#include "SDL/Graphics/OpenGL/ShaderSupport.h"

#include <GL/glew.h>
#include <GL/glu.h>

#if defined(__clang__)
#	pragma clang diagnostic push
#	pragma clang diagnostic ignored "-Wpragma-pack"
#endif

#include <SDL.h>
#include <SDL_opengl.h>

#if defined(__clang__)
#	pragma clang diagnostic pop
#endif

#include <stdio.h>
#include <string>
#include <streambuf>
#include <iostream>
#include <fstream>

namespace shader_support
{

RenderDataContext s_renderContext;


enum class ShaderType {
	k_fragment = GL_FRAGMENT_SHADER, k_vertex = GL_VERTEX_SHADER
};

bool InitGLExtensions()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);


	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	GLenum glewError = glewInit();
	if ( glewError != GLEW_OK )
	{
		std::cerr << "Error initializing GLEW " << glewGetErrorString(glewError) << std::endl;
		return false;
	}

	//Use Vsync
	if ( SDL_GL_SetSwapInterval(1) < 0 )
	{
		std::cerr << "Warning: Unable to set VSync! SDL Error: " << SDL_GetError() << std::endl;
	}
	return true;
}

std::string ReadFile(const std::string& i_file)
{
	std::ifstream f(i_file.c_str());
	std::string source(( std::istreambuf_iterator<char>(f) ),
					   std::istreambuf_iterator<char>());
	return source;
}

void PrintShaderLog(GLuint shader)
{
	if ( glIsShader(shader) )
	{
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

		char* infoLog = new char[ maxLength ];

		glGetShaderInfoLog(shader, maxLength, &infoLogLength, infoLog);
		if ( infoLogLength > 0 )
		{
			std::cout << infoLog << std::endl;
		}
		delete[] infoLog;
	}
	else
	{
		std::cerr << "Name " << shader << " is not a shader\n" << std::endl;
	}
}

void PrintProgramLog(GLuint program)
{
	if ( glIsProgram(program) )
	{
		int infoLogLength = 0;
		int maxLength = infoLogLength;

		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

		char* infoLog = new char[ maxLength ];

		glGetProgramInfoLog(program, maxLength, &infoLogLength, infoLog);
		if ( infoLogLength > 0 )
		{
			std::cout << infoLog << std::endl;
		}
		delete[] infoLog;
	}
	else
	{
		std::cerr << "Name " << program << " is not a program\n" << std::endl;
	}
}

std::pair<bool, GLint> PrepareShader(ShaderType i_type, const std::string& i_path)
{
	bool success = true;;
	const GLuint shaderId = glCreateShader(static_cast< int >(i_type));
	const std::string src = ReadFile(i_path);
	const char* shaderSrc = src.c_str();
	glShaderSource(shaderId, 1, &shaderSrc, nullptr);
	glCompileShader(shaderId);

	GLint fShaderCompiled = GL_FALSE;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &fShaderCompiled);
	if ( fShaderCompiled != GL_TRUE )
	{
		std::cerr << "Unable to compile shader " << i_path << "! " << std::endl;
		PrintShaderLog(shaderId);
		success = false;
	}
	return std::make_pair(success, shaderId);
}

std::pair<bool, GLuint> PrepareShaderProgram(const std::string& i_vertexShaderPath, const std::string& i_fragmentShaderPath)
{
	bool success = false;
	const GLuint programID = glCreateProgram();
	const auto vertexShader = PrepareShader(ShaderType::k_vertex, i_vertexShaderPath);
	const auto fragmentShader = PrepareShader(ShaderType::k_fragment, i_fragmentShaderPath);

	if ( vertexShader.first && fragmentShader.first )
	{
		glAttachShader(programID, vertexShader.second);
		glAttachShader(programID, fragmentShader.second);
		glLinkProgram(programID);

		GLint programSuccess = GL_TRUE;
		glGetProgramiv(programID, GL_LINK_STATUS, &programSuccess);
		success = true;
		if ( programSuccess != GL_TRUE )
		{
			std::cerr << "Error linking program " << programID << "!!" << std::endl;
			PrintProgramLog(programID);
			success = false;
		}
	}
	return std::make_pair(success, programID);
}

RenderBuffers PrepareRenderBuffers()
{
	RenderBuffers buffers;
	//Create VBO
	GLfloat vertexData[] =
	{
		-1.f, -1.f,
		1.f, -1.f,
		1.f,  1.f,
		-1.f,  1.f
	};
	glGenBuffers(1, &buffers.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, buffers.VBO);
	glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);

	//Create IBO
	GLuint indexData[] = { 0, 1, 2, 3 };
	glGenBuffers(1, &buffers.IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW);
	return buffers;
}



RenderDataContext PrepareRenderContext(GLuint i_programId)
{
	RenderDataContext renderContext;
	renderContext.shaderProgramId = i_programId;
	glBindAttribLocation(i_programId, renderContext.vertexPosAttrLoc, "LVertexPos2D");

	renderContext.buffers = PrepareRenderBuffers();
	return renderContext;
}

void DeleteShaderProgram(GLuint i_shaderProgramId)
{
	glDeleteProgram(i_shaderProgramId);
}

void Render(const RenderDataContext& i_ctx)
{
	glUseProgram(i_ctx.shaderProgramId);

	glEnableVertexAttribArray(i_ctx.vertexPosAttrLoc);

	GLint resLoc = glGetUniformLocation(i_ctx.shaderProgramId, "u_resolution");
	glProgramUniform2f(i_ctx.shaderProgramId, resLoc, i_ctx.resolution[0], i_ctx.resolution[1]);

	glBindBuffer(GL_ARRAY_BUFFER, i_ctx.buffers.VBO);
	glVertexAttribPointer(i_ctx.vertexPosAttrLoc, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_ctx.buffers.IBO);
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL);

	glDisableVertexAttribArray(i_ctx.vertexPosAttrLoc);

	glUseProgram(0u);
}

}


//////////////////////////////////////////////////////////////////////////
// Debug stuff follows
//////////////////////////////////////////////////////////////////////////

namespace shader_support
{
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL, creates window, and initializes OpenGL
bool init();

//Initializes rendering program and clear color
bool initGL();

//Input handler
void handleKeys(unsigned char key, int x, int y);

//Per frame update
void update();

//Renders quad to the screen
void render();

//Frees media and shuts down SDL
void close();

//Shader loading utility programs
void PrintProgramLog(GLuint program);
void PrintShaderLog(GLuint shader);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//OpenGL context
SDL_GLContext gContext;

//Render flag
bool gRenderQuad = true;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Use OpenGL 3.1 core
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if ( gWindow == NULL )
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create context
			gContext = SDL_GL_CreateContext(gWindow);
			if ( gContext == NULL )
			{
				printf("OpenGL context could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize GLEW
				glewExperimental = GL_TRUE;
				GLenum glewError = glewInit();
				if ( glewError != GLEW_OK )
				{
					printf("Error initializing GLEW! %s\n", glewGetErrorString(glewError));
				}

				//Use Vsync
				if ( SDL_GL_SetSwapInterval(1) < 0 )
				{
					printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
				}

				//Initialize OpenGL
				if ( !initGL() )
				{
					printf("Unable to initialize OpenGL!\n");
					success = false;
				}
			}
		}
	}

	return success;
}



bool initGL()
{
	auto program = PrepareShaderProgram("std.vertex", "std.fragment");
	if ( program.first )
	{
		s_renderContext = PrepareRenderContext(program.second);
	}
	return program.first;
}

void handleKeys(unsigned char key, int x, int y)
{
	//Toggle quad
	if ( key == 'q' )
	{
		gRenderQuad = !gRenderQuad;
	}
}

void update()
{
	//No per frame update needed
}

void render()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	if ( gRenderQuad )
	{
		Render(s_renderContext);
	}
}

void close()
{
	//Deallocate program
	glDeleteProgram(s_renderContext.shaderProgramId);

	//Destroy window	
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


void RunTest()
{
	//Start up SDL and create window
	if ( !init() )
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		//Enable text input
		SDL_StartTextInput();

		//While application is running
		while ( !quit )
		{
			//Handle events on queue
			while ( SDL_PollEvent(&e) != 0 )
			{
				//User requests quit
				if ( e.type == SDL_QUIT )
				{
					quit = true;
				}
				//Handle keypress with current mouse position
				else if ( e.type == SDL_TEXTINPUT )
				{
					int x = 0, y = 0;
					SDL_GetMouseState(&x, &y);
					handleKeys(e.text.text[ 0 ], x, y);
				}
			}

			//Render quad
			render();

			//Update screen
			SDL_GL_SwapWindow(gWindow);
		}

		//Disable text input
		SDL_StopTextInput();
	}

	//Free resources and close SDL
	close();
}

}