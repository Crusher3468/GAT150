#pragma once
#include <random>

namespace neu
{
	inline void SeedRandom(int seed) { srand(seed); }

	inline int random() { return rand(); }
	inline int random(int max) { return random() % max; }
	inline int random(int min, int max) { return min + random() % (max -min ) + 1; }

	inline float randomf() { return rand() / (float)RAND_MAX; }
	inline float randomf(float max) { return randomf() * max; }
	inline float randomf(float min, float max) { return min + randomf(max - min); }
}