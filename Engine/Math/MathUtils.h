//#pragma once

#ifndef __MATH_UTILS_H__

namespace neu
{
	const float HalfPi = 1.57079632679f;
	const float Pi = 3.14159265359f;
	const float TwoPi = 6.28318530718f;

	inline float DegToRad(float degrees)
	{
		return degrees * (Pi / 180);
	}

	inline float RadToDeg(float radians)
	{
		return radians * (180 / Pi);
	}

	int sqr(int v);
	inline int half(int v) { return v / 2; }
}

#endif //