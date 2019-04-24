#pragma once
#ifndef DARK_GLSL
#define DARK_GLSL
#endif
#include "basic.hpp"
#include "vec3.hpp"
#include <ostream>
/*----------1x4 vector */
namespace u
{
	struct vec4
	{
		union
		{
			struct { GLfloat x, y, z, w; };
			struct { GLfloat r, g, b, a; };
			struct { GLfloat s, t, p, q; };

			vec2_swizzle<vec2, 0, 1> xy, rg, st;
			vec2_swizzle<vec2, 2, 3> zw, ba, pg;
			vec3_swizzle<vec3, 0, 1, 2> xyz, rgb, stp;
			GLfloat d[4] = { 0.f, 0.f, 0.f, 0.f };
		};

		/* Constructors */

		vec4() {}
		vec4(GLfloat* vec) : x(vec[0]), y(vec[1]), z(vec[2]), w(vec[3]) {}
		explicit vec4(GLfloat all) : x(all), y(all), z(all), w(all)
		{

		}
		vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w) : x(x), y(y), z(z), w(w) {}
		// Swizzling
		vec4(vec3 v, GLfloat last) : x(v.x), y(v.y), z(v.z), w(last) {}
		vec4(vec2 &v1, vec2 &v2) : x(v1.x), y(v1.y), z(v2.x), w(v2.y) {}

		/* Positivating / Negating */
		vec4 operator+() const
		{
			return vec4(+x, +y, +z, +w);
		}
		vec4 operator-() const
		{
			return vec4(-x, -y, -z, -w);
		}


		/**********************Addition**********************/
		GENERATE_OPRETORS_VEC4(+, +=);
		/**********************Subtraction*******************/
		GENERATE_OPRETORS_VEC4(-, -=);
		/**********************Multiplication****************/
		GENERATE_OPRETORS_VEC4(*, *=);
		/**********************Division**********************/
		GENERATE_OPRETORS_VEC4(/ , /=);

		/* Incrementing and Decrementing Operators */

		vec4 operator++(int)
		{
			return vec4(x++, y++, z++, w++);
		}
		vec4 operator--(int)
		{
			return vec4(x--, y--, z--, w++);
		}
		vec4 operator++()
		{
			return vec4(++x, ++y, ++z, ++w);
		}
		vec4 operator--()
		{
			return vec4(--x, --y, --z, ++w);
		}
		// Indexing
		GLfloat &operator[](const int &i) const
		{
			return (GLfloat&)(d[i > 3 ? -1 : i]);
		}
		// Is equal too?
		const bool operator==(const vec4 &vec) const
		{
			return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
		}
		vec3 get_vec3()
		{
			return vec3(x, y, z);
		}
		/* Member Functions */

		// Retrives the length of a vector.
		GLfloat length()
		{
			return GLfloat(u::sqrt(pow2(x) + pow2(y) + pow2(z) + pow2(w)));
		}
	};
	inline std::ostream &operator <<(std::ostream& os, const u::vec4 &vec)
	{
		os << '(' << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ')';
		return os;
	}
	/* Basic Math Operations with Scalars */

	inline vec4 operator*(const GLfloat& value, vec4 &vec)
	{
		return vec4(vec.x * value, vec.y * value, vec.z * value, vec.w * value);
	}
}