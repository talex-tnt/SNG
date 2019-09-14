@echo off

set prj_type=%1
set sln_proj=%cd%/builds/%prj_type%/sng.sln
if not exist %sln_proj% (
	call gen_proj-%prj_type%.bat
	:loop
	if not exist %sln_proj% (
		echo "Waiting for the project.."
		timeout 1
		goto loop
	)
) 
echo Starting project %sln_proj%
start %sln_proj%
rem pause