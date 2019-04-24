#pragma once
#include "basic.hpp"
#include "swizzle.hpp"
#include <ostream>
/*----------1x2 vector */
namespace u
{
	struct vec2
	{
		union
		{
			struct { GLfloat x, y; };
			struct { GLfloat r, g; };
			struct { GLfloat s, t; };
			vec2_swizzle<vec2, 0, 0> xx;
			vec2_swizzle<vec2, 1, 1> yy;

			GLfloat d[2] = { 0.f, 0.f };
		};

		/* Constructors */

		vec2() {}
		explicit vec2(GLfloat all) : x(all), y(all)
		{

		}
		vec2(GLfloat a, GLfloat b)
		{
			x = a;
			y = b;
		}
		//----Positivating-----/
		vec2 operator+() const
		{
			return vec2(+x, +y);
		}
		//----Negating---------/
		vec2 operator-() const
		{
			return vec2(-x, -y);
		}
		/**********************Addition**********************/
		GENERATE_OPRETORS_VEC2(+, +=);
		/**********************Subtraction*******************/
		GENERATE_OPRETORS_VEC2(-, -=);
		/**********************Multiplication****************/
		GENERATE_OPRETORS_VEC2(*, *=);
		/**********************Division**********************/
		GENERATE_OPRETORS_VEC2(/, /=);

		/* Incrementing and Decrementing Operators */

		vec2 operator++(int)
		{
			return vec2(x++, y++);
		}
		vec2 operator--(int)
		{
			return vec2(x--, y--);
		}
		vec2 operator++()
		{
			return vec2(++x, ++y);
		}
		vec2 operator--()
		{
			return vec2(--x, --y);
		}

		vec2 &operator=(const float &XY)
		{
			this->x = XY;
			this->y = XY;
			return *this;
		}
		// Indexing
		GLfloat &operator[](const int i) const
		{
			return (GLfloat&)(d[i > 1 ? -1 : i]);
		}
		// Is equal too?
		const bool operator==(const vec2 &vec) const
		{
			return x == vec.x && y == vec.y;
		}

		/* Member Functions */

		// Retrives the length of a vector.
		GLfloat length() const
		{
			return GLfloat(u::sqrt(pow2(x) + pow2(y)));
		}

	};
	/* Basic Math Operations with Scalars */

	inline vec2 operator+(const GLfloat& value, vec2 &vec)
	{
		return vec2(vec.x + value, vec.y + value);
	}
	inline vec2 operator-(const GLfloat& value, vec2 &vec)
	{
		return vec2(vec.x - value, vec.y - value);
	}
	inline vec2 operator*(const GLfloat& value, vec2 &vec)
	{
		return vec2(vec.x * value, vec.y * value);
	}
	inline vec2 operator/(const GLfloat& value, vec2 &vec)
	{
		return vec2(vec.x / value, vec.y / value);
	}

	struct ivec2 : public vec2
	{
		union
		{
			struct { int x, y; };
			struct { int r, g; };
			struct { int s, t; };
			vec2_swizzle<vec2, 0, 0> xx;
			vec2_swizzle<vec2, 1, 1> yy;

			int d[2] = { 0, 0 };
		};

		/* Constructors */

		ivec2() {}
		explicit ivec2(int all) : x(all), y(all) {}
		ivec2(int a, int b)
		{
			x = a;
			y = b;
		}
		int &operator[](const int i) const
		{
			return (int&)(d[i > 1 ? -1 : i]);
		}
	};
	inline std::ostream &operator <<(std::ostream& os, const u::vec2 &vec)
	{
		os << '(' << vec.x << ", " << vec.y << ')';
		return os;
	}
	/* Basic Math Operations with Scalars */

	inline ivec2 operator*(const GLfloat& value, ivec2 &vec)
	{
		return ivec2(static_cast<int>(vec.x * value), static_cast<int>(vec.y * value));
	}
}