#pragma once
#include "Vector2.h"

namespace neu
{
	struct Transform
	{
		Vector2 position;
		float rotation = 0.0f;
		float scale = 0.0f;
	};
}