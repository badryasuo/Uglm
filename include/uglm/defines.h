#pragma once
#pragma warning( disable : 4098 )
#pragma warning( disable : 4201 )
#if defined(_MSC_VER)
    //  Microsoft 
    #define declspec_naked __declspec(naked)
    #define fastcall __fastcall
#elif defined(__GNUC__)
    //  GCC
    #define declspec_naked __attribute__ ((naked))
    #define fastcall __attribute__((fastcall))
#else
    
#endif


#ifndef __gl_h_
    typedef float GLfloat;
#endif
#define pow2(x)(x*x)
#define glPI 3.1415	
namespace u
{
	enum GL_FLAG
	{
		zero,
		reverse
	};
}