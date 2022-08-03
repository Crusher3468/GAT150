#include "InputSystem.h"
#include<SDL.h>
#include<iostream>

namespace neu
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_W;
	const uint32_t key_down = SDL_SCANCODE_S;
	const uint32_t key_left = SDL_SCANCODE_A;
	const uint32_t key_right = SDL_SCANCODE_D;
	const uint32_t key_restart= SDL_SCANCODE_R;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;
	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	void neu::InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);

		m_keyboardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevKeyboardState = m_keyboardState;
	}

	void neu::InputSystem::Shutdown()
	{
	}

	void neu::InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		m_prevKeyboardState = m_keyboardState;

		m_prevMouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = neu::Vector2{ x , y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK;
		m_mouseButtonState[1] = buttons & SDL_BUTTON_LMASK;
		m_mouseButtonState[2] = buttons & SDL_BUTTON_LMASK;

		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());
	}

	inline InputSystem::State InputSystem::GetKeyState(uint32_t key)
	{
		State keyState = State::Idle;

		bool keyDown = GetKeyDown(key);
		bool prevKeydown = GetPreviousKeyDown(key);

		if (!keyDown && !prevKeydown) { keyState = Idle; }
		if (keyDown && !prevKeydown) { keyState = Pressed; }
		if (keyDown && prevKeydown) { keyState = Held; }
		if (!keyDown && prevKeydown) { keyState = Released; }

		return keyState;
	}

	inline InputSystem::State InputSystem::GetButtonState(uint32_t button)
	{
		State buttonState = State::Idle;

		bool buttonDown = getButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		if (!buttonDown && !prevButtonDown) { buttonState = Idle; }
		if (buttonDown && !prevButtonDown) { buttonState = Pressed; }
		if (buttonDown && prevButtonDown) { buttonState = Held; }
		if (!buttonDown && prevButtonDown) { buttonState = Released; }

		return buttonState;
	}

}