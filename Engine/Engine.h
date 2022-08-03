#pragma once

#include"Core/Memory.h"
#include"Core/File.h"
#include"Core/Time.h"

#include"Math/MathUtils.h"
#include"Math/Random.h"

#include"Framework/Scene.h"
#include "Framework//Game.h"

#include"Input/InputSystem.h"

#include"Audio/AudioSystem.h"

#include"Renderer/Renderer.h"
#include"Renderer/Text.h"
#include"Renderer/Font.h"

#include<memory>

namespace neu
{
	extern neu::Renderer g_renderer;
	extern neu::InputSystem g_inputSystem;
	extern neu::Time g_time;
	extern neu::AudioSystem g_audioSystem;
}