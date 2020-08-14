#ifndef vector3d_H
#define vector3d_H
#ifdef _WIN32
#pragma once
#endif

class vector3d
{
public:

	float x, y, z;

	vector3d(void)
	{
		invalidate();
	}

	vector3d(float x, float y, float z)
	{
		this->x = x; this->y = y; this->z = z;
	}

	vector3d(float* clr)
	{
		x = clr[0]; y = clr[1]; z = clr[2];
	}

	float& operator[](int i)
	{
		return ((float*)this)[i];
	}

	float operator[](int i) const
	{
		return ((float*)this)[i];
	}

	bool operator==(const vector3d& src) const
	{
		return (src.x == x) && (src.y == y) && (src.z == z);
	}

	bool operator!=(const vector3d& src) const
	{
		return (src.x != x) || (src.y != y) || (src.z != z);
	}

	vector3d& operator+=(const vector3d& v)
	{
		x += v.x; y += v.y; z += v.z;
		return *this;
	}

	vector3d& operator-=(const vector3d& v)
	{
		x -= v.x; y -= v.y; z -= v.z;
		return *this;
	}

	vector3d& operator*=(float fl)
	{
		x *= fl; y *= fl; z *= fl;
		return *this;
	}

	vector3d& operator*=(const vector3d& v)
	{
		x *= v.x; y *= v.y; z *= v.z;
		return *this;
	}

	vector3d& operator/=(const vector3d& v)
	{
		x /= v.x; y /= v.y; z /= v.z;
		return *this;
	}

	vector3d&	operator+=(float fl)
	{
		x += fl; y += fl; z += fl;
		return *this;
	}

	vector3d&	operator/=(float fl)
	{
		x /= fl; y /= fl; z /= fl;
		return *this;
	}

	vector3d&	operator-=(float fl)
	{
		x -= fl; y -= fl; z -= fl;
		return *this;
	}

	vector3d operator-(void) const
	{
		return vector3d(-x, -y, -z);
	}

	vector3d operator+(const vector3d& v) const
	{
		return vector3d(x + v.x, y + v.y, z + v.z);
	}

	vector3d operator-(const vector3d& v) const
	{
		return vector3d(x - v.x, y - v.y, z - v.z);
	}

	vector3d operator*(float fl) const
	{
		return vector3d(x * fl, y * fl, z * fl);
	}

	vector3d operator*(const vector3d& v) const
	{
		return vector3d(x * v.x, y * v.y, z * v.z);
	}

	vector3d operator/(float fl) const
	{
		return vector3d(x / fl, y / fl, z / fl);
	}

	vector3d operator/(const vector3d& v) const
	{
		return vector3d(x / v.x, y / v.y, z / v.z);
	}

	float length(void) const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	float length2d(void) const
	{
		return sqrtf(x * x + y * y);
	}

	float dot(const vector3d& b) const
	{
		return (x * b.x + y * b.y + z * b.z);
	}

	void invalidate()
	{
		x = y = z = std::numeric_limits<float>::infinity();
	}

	void init(float x = 0.0f, float y = 0.0f, float z = 0.0f)
	{
		this->x = x; this->y = y; this->z = z;
	}

	float length_sqr(void) const
	{
		return (x * x + y * y + z * z);
	}

	bool is_null()
	{
		return (!x && !y && !z);
	}
};

inline float vector3d_distance(const vector3d src, const vector3d dest)
{
	vector3d sub = dest - src;

	return sub.length();
}

inline void vector3d_subtract(const vector3d& a, const vector3d& b, vector3d& result)
{
	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
}

inline void vector3d_clear(vector3d& a)
{
	a.x = a.y = a.z = 0.0f;
}

inline void vector3d_copy(const vector3d& src, vector3d& dst)
{
	dst.x = src.x;
	dst.y = src.y;
	dst.z = src.z;
}

inline void vector3d_add(const vector3d& a, const vector3d& b, vector3d& c)
{
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
}

inline void vector3d_angles(const vector3d& forward, vector3d& angles)
{

	float tmp, yaw, pitch;

	if (forward.y == 0 && forward.x == 0) {

		yaw = 0;

		if (forward.z > 0) {
			pitch = 270;
		} else {
			pitch = 90;
		}

	} else {

		yaw = RAD2DEG(atan2f(forward.y, forward.x));

		if (yaw < 0)
			yaw += 360;

		tmp = forward.length2d();
		pitch = RAD2DEG(atan2f(-forward.z, tmp));

		if (pitch < 0)
			pitch += 360;

	}

	angles[0] = pitch;
	angles[1] = yaw;
	angles[2] = 0;

}

class __declspec(align(16))vector3d_aligned : public vector3d
{
public:

	inline vector3d_aligned(void) {};

	inline vector3d_aligned(float x, float y, float z)
	{
		init(x, y, z);
	}

	explicit vector3d_aligned(const vector3d& v)
	{
		init(v.x, v.y, v.z);
	}

	vector3d_aligned& operator=(const vector3d& v)
	{
		init(v.x, v.y, v.z);
		return *this;
	}

	float w;

};

#endif // !vector3d_H