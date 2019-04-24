#pragma once
#ifndef DARK_GLSL
#define DARK_GLSL
#endif
#include "basic.hpp"
#include "vec2.hpp"
#include <ostream>
/*----------1x3 vector */
namespace u
{
	struct vec3
	{
		union
		{
			struct { GLfloat x, y, z; };
			struct { GLfloat r, g, b; };
			struct { GLfloat s, t, p; };

			vec2_swizzle<vec2, 0, 1> xy;
			vec3_swizzle<vec3, 0, 1, 2> xyz;
			//struct { vec2 rg; };
			//struct { vec2 st; };
			//
			//struct { float x; vec2 yz; };
			//struct { float r; vec2 gb; };
			//struct { float s; vec2 tp; };
			GLfloat d[3] = { 0.f, 0.f, 0.f };
		};

		/* Constructors */

		vec3() {}
		explicit vec3(GLfloat all) : x(all), y(all), z(all)
		{

		}
		vec3(GLfloat a, GLfloat b, GLfloat c)
		{
			x = a;
			y = b;
			z = c;
		}
		//----Positivating-----/
		vec3 operator+() const
		{
			return vec3(+x, +y, +z);
		}
		//----Negating---------/
		vec3 operator-() const
		{
			return vec3(-x, -y, -z);
		}

		/**********************Addition**********************/
		GENERATE_OPRETORS_VEC3(+, +=);
		/**********************Subtraction*******************/
		GENERATE_OPRETORS_VEC3(-, -=);
		/**********************Multiplication****************/
		GENERATE_OPRETORS_VEC3(*, *=);
		/**********************Division**********************/
		GENERATE_OPRETORS_VEC3(/ , /=);
		
		/* Incrementing and Decrementing Operators */

		vec3 operator++(int)
		{
			return vec3(x++, y++, z++);
		}
		vec3 operator--(int)
		{
			return vec3(x--, y--, z--);
		}
		vec3 operator++()
		{
			return vec3(++x, ++y, ++z);
		}
		vec3 operator--()
		{
			return vec3(--x, --y, --z);
		}
		// Indexing
		GLfloat &operator[](const int i) const
		{
			return (GLfloat&)(d[i > 2 ? -1 : i]);
		}
		// Is equal too?
		const bool operator==(const vec3 &vec) const
		{
			return x == vec.x && y == vec.y && z == vec.z;
		}

		/* Member Functions */

		// Retrives the length of a vector.
		GLfloat length() const
		{
			return GLfloat(u::sqrt(pow2(x) + pow2(y) + pow2(z)));
		}
	};
	inline std::ostream &operator <<(std::ostream& os, const u::vec3 &vec)
	{
		os << '(' << vec.x << ", " << vec.y << ", " << vec.z << ')';
		return os;
	}
	/* Basic Math Operations with Scalars */
	inline vec3 operator*(const GLfloat& value, vec3 vec)
	{
		return vec3(vec.x * value, vec.y * value, vec.z * value);
	}
}