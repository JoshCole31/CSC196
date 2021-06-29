#pragma once

#ifdef DYNAMIC_EXPORTS
#define DYMNAMIC_API _declapec(dllexport)
#else
#define DYMNAMIC_API _declapec(dllexport)
#endif

namespace nc
{
	struct DYMNAMIC_API
	{
		float x;
		float y;

		point(float x, float y) :x{ x }, y{ y } {}
		point operator + (point p) { return point { p.x + x, p.y + y }; }
	};

}