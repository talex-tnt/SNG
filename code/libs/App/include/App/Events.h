#pragma once
#include <memory>
#include <string>

namespace
{
	//move this to utils
	template<class T> 
	constexpr typename std::underlying_type<T>::type GetEnumValue(T i_enum) noexcept
	{
		return static_cast<typename std::underlying_type<T>::type >( i_enum );
	}
}

namespace app
{
namespace events
{

enum class EventType
{
	k_quit
};

class KeyDownEvent
{
public:
	enum class KeycodeType
	{
		k_up, k_down, k_left, k_right,
	};
	KeyDownEvent(KeycodeType i_keycode) :
		m_keycode(i_keycode) { }
	KeycodeType GetKeycode() const { return m_keycode; }
private:
	KeycodeType m_keycode;
};

inline std::ostream& operator<<(std::ostream& o_stream, const KeyDownEvent& i_keyDownEvent)
{
	o_stream << std::string("KeyDownEvent: ") << GetEnumValue(i_keyDownEvent.GetKeycode());
	return o_stream;
}
}
}