#include "vec4.h"
#include<iostream>
namespace rabona {namespace maths{


	vec4::vec4(const float& x, const float& y, const float& z, const float& w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;

	}

	vec4& vec4::add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;

		return *this;
	}

	vec4& vec4::subtract(const vec4& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;

		return *this;
	}
	vec4& vec4::multiply(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;

		return *this;
	}
	vec4& vec4::devide(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}
	vec4& vec4::operator+=(const vec4& other)
	{
		return add(other);
	}

	vec4& vec4::operator-=(const vec4& other)
	{
		return subtract(other);
	}
	vec4& vec4::operator*=(const vec4& other)
	{
		return multiply(other);
	}
	vec4& vec4::operator/=(const vec4& other)
	{
		return devide(other);
	}
	bool vec4::operator==(const vec4& other)
	{
		return x == other.x && y == other.y && z == other.z;
	}
	bool vec4::operator!=(const vec4& other)
	{
		return !(*this == other);
	}
	vec4& operator+(vec4 left, const vec4& other)
	{
		return left.add(other);
	}
	vec4& operator-(vec4 left, const vec4& other)
	{
		return left.subtract(other);
	}
	vec4& operator*(vec4 left, const vec4& other)
	{
		return left.multiply(other);
	}
	vec4& operator/(vec4 left, const vec4& other)
	{
		return left.devide(other);
	}
	std::ostream& operator<<(std::ostream& stream, const vec4& other)
	{
		stream << "vec4 : (" << other.x << "," << other.y << "," << other.z << "," << other.w << ")";
		return stream;
	}
}}
