#pragma once
#include <Windows.h>
#include <cmath>

class Math {
public:
	//
};

struct Vec2 {
	union {
		struct {
			float x, y;
		};
		float arr[2];
	};

	//Vec2() { x = y = 0; };
	
	Vec2(float x = 0, float y = 0) {
		this->x = x; this->y = y;
	};

	bool operator == (Vec2 v) { return v.x == x && v.y == y; };
	bool operator != (Vec2 v) { return v.x != x || v.y != y; };
};

struct Vec3 {
	union {
		struct {
			float x, y, z;
		};
		float arr[3];
	};

	//Vec3() { x = y = z = 0; };

	Vec3(float x = 0, float y = 0, float z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	Vec3(float f) {
		this->x = x; this->y = f; this->z = f;
	}

	bool operator == (Vec3 v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vec3 v) { return v.x != x || v.y != y || v.z != z; };

	Vec3 add(Vec3 v) {
		return Vec3(x + v.x, y + v.y, z + v.z);
	}

	Vec3 add(float f) {
		return Vec3(x + f, y + f, z + f);
	}

	Vec3 sub(Vec3 v) {
		return Vec3(x - v.x, y - v.y, z - v.z);
	}

	Vec3 sub(float f) {
		return Vec3(x - f, y - f, z - f);
	}

	Vec3 mult(Vec3 v) {
		return Vec3(x * v.x, y * v.y, z * v.z);
	}

	Vec3 mult(float f) {
		return Vec3(x * f, y * f, z * f);
	}

	Vec3 div(Vec3 v) {
		return Vec3(x / v.x, y / v.y, z / v.z);
	}

	Vec3 div(float f) {
		return Vec3(x / f, y / f, z / f);
	}

	float distance(Vec3 v) {
		float dX = x - v.x;
		float dY = y - v.y;
		float dZ = z - v.z;
		return std::sqrt(dX * dX + dY * dY + dZ * dZ);
	}

	float magnitude() {
		return sqrtf(x * x + y * y + z * z);
	}

	float magnitudexy() {
		return sqrtf(x * x + y * y);
	}

	float magnitudexz() {
		return sqrtf(x * x + z * z);
	}

	Vec3 normalize() {
		return div(magnitude());
	}

	Vec3 floor() {
		return Vec3(floorf(x), floorf(y), floorf(z));
	}
};

struct Vec3i {
	union {
		struct {
			int x, y, z;
		};
		int arr[3];
	};

	//Vec3i() { x = y = z = 0; };

	Vec3i(int x = 0, int y = 0, int z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	bool operator == (Vec3i v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vec3i v) { return v.x != x || v.y != y || v.z != z; };

	Vec3i sub(const Vec3i& o) {
		return Vec3i(x - o.x, y - o.y, z - o.z);
	}
};

struct Vec4 {
	union {
		struct {
			float x, y, z, w;
		};
		float arr[4];
	};
	Vec4(float x = 0, float y = 0, float z = 0, float w = 0) {
		this->x = x; this->y = y; this->z = z; this->w = w;
	};
	Vec4(Vec2 start, Vec2 end) {
		this->x = start.x, this->y = start.y;
		this->z = end.x, this->w = end.y;
	};
	Vec2 start() {
		return Vec2(this->x, this->y);
	};
	Vec2 end() {
		return Vec2(this->z, this->w);
	}
};

struct AABB {
	Vec3 lower;
	Vec3 upper;
};

class _RGBA {
public:
	float r;
	float g;
	float b;
	float a;
	_RGBA(float r, float g, float b, float a = 1) {
		this->r = (r / 255.f); this->g = (g / 255.f); this->b = (b / 255.f);
		this->a = a;
	}
};