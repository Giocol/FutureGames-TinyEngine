#pragma once
#include "Vector.h"

struct AABB {
public:
	AABB() = default;
	AABB(Vector min, Vector max) : min(min), max(max) {};
	static AABB fromPositionSize(Vector position, Vector size);

	Vector min;
	Vector max;
};

bool aabbOverlap(AABB a, AABB b);