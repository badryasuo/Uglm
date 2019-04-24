#pragma once
namespace u
{
	template<typename vec_type, unsigned int A, unsigned int B>
	struct vec2_swizzle
	{
		float d[2];
		vec_type operator=(const vec_type& vec)
		{
			d[A] = vec.x;
			d[B] = vec.y;
			// Cast this vec2_swizzle* to vec2* and return the *pointed* (i.e *this) object as a reference.
			//return vec_type(d[A], d[B]);
			return *static_cast<vec_type*>(this);
		}
		operator vec_type()
		{
			return vec_type(d[A], d[B]);
		}
	};
#define GENERATE_OPRETORS_VEC2(OP, OPTHIS)\
	/* vector OP scalar*/\
	vec2 operator OP(const GLfloat& value) const\
	{\
		return vec2(this->x OP value, this->y OP value);\
	}\
	/* this = vector OP scalar*/\
	vec2 &operator OPTHIS(const GLfloat &value)\
	{\
		return *this = vec2(this->x OP value, this->y OP value);\
	}\
	/* vector OP vector*/\
	vec2 operator OP(const vec2 &vec) const\
	{\
		return vec2(this->x OP vec.x, this->y OP vec.y);\
	}\
	/* this = vector OP vector*/\
	vec2 &operator OPTHIS(const vec2 &vec)\
	{\
		return *this = vec2(this->x OP vec.x, this->y OP vec.y);\
	}
	template<typename vec_type, unsigned int A, unsigned int B, unsigned int C>
	struct vec3_swizzle
	{
		float d[3];
		vec_type& operator=(const vec_type& vec)
		{
			d[A] = vec.x;
			d[B] = vec.y;
			d[C] = vec.z;
			return *(vec_type*)this;
		}
		operator vec_type()
		{
			return vec_type(d[A], d[B], d[C]);
		}
	};
#define GENERATE_OPRETORS_VEC3(OP, OPTHIS)\
	/* vector OP scalar*/\
	vec3 operator OP(const GLfloat& value) const\
	{\
		return vec3(this->x OP value, this->y OP value, this->z OP value);\
	}\
	/* this = vector OP scalar*/\
	vec3 &operator OPTHIS(const GLfloat &value)\
	{\
		return *this = vec3(this->x OP value, this->y OP value, this->z OP value);\
	}\
	/* vector OP vector*/\
	vec3 operator OP(const vec3 &vec) const\
	{\
		return vec3(this->x OP vec.x, this->y OP vec.y, this->z OP vec.z);\
	}\
	/* this = vector OP vector*/\
	vec3 &operator OPTHIS(const vec3 &vec)\
	{\
		return *this = vec3(this->x OP vec.x, this->y OP vec.y, this->z OP vec.z);\
	}
	template<typename vec_type, unsigned int A, unsigned int B, unsigned int C, unsigned int D>
	struct vec4_swizzle
	{
		float d[4];
		vec_type& operator=(const vec_type& vec)
		{
			d[A] = vec.x;
			d[B] = vec.y;
			d[C] = vec.z;
			d[D] = vec.w;
			return *(vec_type*)this;
		}
		operator vec_type()
		{
			return vec_type(d[A], d[B], d[C], d[D]);
		}
	};
#define GENERATE_OPRETORS_VEC4(OP, OPTHIS)\
	/* vector OP scalar*/\
	vec4 operator OP(const GLfloat& value) const\
	{\
		return vec4(this->x OP value, this->y OP value, this->z OP value, this->w OP value);\
	}\
	/* this = vector OP scalar*/\
	vec4 &operator OPTHIS(const GLfloat &value)\
	{\
		return *this = vec4(this->x OP value, this->y OP value, this->z OP value, this->w OP value);\
	}\
	/* vector OP vector*/\
	vec4 operator OP(const vec4 &vec) const\
	{\
		return vec4(this->x OP vec.x, this->y OP vec.y, this->z OP vec.z, this->w OP vec.w);\
	}\
	/* this = vector OP vector*/\
	vec4 &operator OPTHIS(const vec4 &vec)\
	{\
		return *this = vec4(this->x OP vec.x, this->y OP vec.y, this->z OP vec.z, this->w OP vec.w);\
	}
}