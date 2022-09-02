#pragma once
#include <cmath>
namespace neu
{
	constexpr float HalfPi = 1.57079632679f;
	constexpr float Pi = 3.14159265359f;
	constexpr float TwoPi = 6.28318530718f;

	constexpr float DegToRad(float degrees)
	{
		return degrees * (Pi / 180);
	}

	constexpr float RadToDeg(float radians)
	{
		return radians * (180 / Pi);
	}

	template <typename T>
	T Clamp(T value, T min, T max)
	{
		if (value < min) return min;
		if (value > max) return max;

		return value;
	}

	template <typename T>
	T Lerp(T min, T max, float t)
	{
		t = Clamp (t, 0.0f, 1.0f);

		return min + ((max - min) * t);
	}

	template <typename T>
	T Normalize(T value, T min, T max)
	{
		return (value - min) / (max - min);
	}

	template <typename T>
	T Remap(T value, T inMin, T inMax, T outMin, T outMax)
	{
		return Lerp(outMin, outMax, Normalize(value, inMin, inMax));
	}

	template <typename T>
	T mod(T num, T den)
	{
		return std::fmod(num, den);
	}

	template <typename T>
	inline int mod(int num, int den)
	{
		return num % den; 
	}

	template <typename T>
	T Wrap(T value, T min, T max)
	{
		if (value < min) return max - mod((min - value), (max - min));
		if (value > max) return min + mod ((value - min), (max - min));

		return value;
	}

	int sqr(int v);
	inline int half(int v) { return v / 2; }
}
