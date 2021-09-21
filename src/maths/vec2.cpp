#include"vec2.h"
namespace rabona {namespace maths {

	vec2::vec2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;

	}

	vec2& vec2::add(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	vec2& vec2::subtract(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}
	vec2& vec2::multiply(const vec2& other)
	{
		x *= other.x;
		y *= other.y;

		return *this;
	}
	vec2& vec2::devide(const vec2& other)
	{
		x /= other.x;
		y /= other.y;

		return *this;
	}
	vec2& vec2::operator+=(const vec2& other)
	{
		return add(other);
	}

	vec2& vec2::operator-=(const vec2& other)
	{
		return subtract(other);
	}
	vec2& vec2::operator*=(const vec2& other)
	{
		return multiply(other);
	}
	vec2& vec2::operator/=(const vec2& other)
	{
		return devide(other);
	}
	bool vec2::operator==(const vec2& other)
	{
		return x == other.x && y == other.y;
	}
	bool vec2::operator!=(const vec2& other)
	{
		return !(*this == other);
	}
	vec2& operator+(vec2 left,const vec2& other)
	{
		return left.add(other);
	}
	vec2& operator-(vec2 left,const vec2& other)
	{
		return left.subtract(other);
	}
	vec2& operator*(vec2 left, const vec2& other)
	{
		return left.multiply(other);
	}
	vec2& operator/(vec2 left,const vec2& other)
	{
		return left.devide(other);
	}
	std::ostream& operator<<(std::ostream& stream, const vec2& other)
	{
		stream << "vec2 : (" << other.x << "," << other.y << ")";
		return stream;
	}
} }