#pragma once

namespace jc
{
	void SeedRandom(unsigned int seed);

	float Random();//0-1
	float RandomRange(float min, float max);

	int Randomint();
	int RandomRangeInt(int min, int max);


}