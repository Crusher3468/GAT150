#pragma once
#include<cstdint>
#include<vector>
#include<array>
#include "Math/Vector2.h"

namespace neu
{
	class InputSystem
	{
	public:
		enum class State
		{
			Idle,
			Pressed,
			Held,
			Released
		};


		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void Shutdown();
		
		void Update();

		State GetKeyState(uint32_t key);
		bool GetKeyDown(uint32_t key) { return m_keyboardState[key]; }
		bool GetPreviousKeyDown(uint32_t key) { return m_prevKeyboardState[key];  }

		State GetButtonState(uint32_t button);
		bool getButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool GetPreviousButtonDown(uint32_t button) { return m_prevMouseButtonState[button]; }


		const neu::Vector2& GetMousePosition() const { return m_mousePosition;  }
	private:
		int m_numKeys;
		Vector2 m_mousePosition;

		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;
		std::array<uint8_t, 3> m_mouseButtonState;
		std::array<uint8_t, 3> m_prevMouseButtonState;
	};

	extern const uint32_t key_space;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
	extern const uint32_t key_escape;
	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;
	extern const uint32_t key_restart;
	extern const uint32_t key_enter;

}
