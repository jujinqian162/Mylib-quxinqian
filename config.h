#pragma once
#include <iostream>
#if _HAS_CXX23
	#include <print>
	#define PRINT(...) std::print(__VA_ARGS__)
	#define PRINTLN(...) std::println(__VA_ARGS__)
	#define BY_VALUE this auto self,
#else 
	#include <stdio.h>
	#define PRINT(...) printf(__VA_ARGS__)
	#define PRINTLN(...) PRINT(__VA_ARGS__)
	#define BY_VALUE 
#endif // _HAS_CXX23



#if _HAS_CXX20
	#include <ranges>
	#define CONST20 constexpr
	#define RANGES_ std::ranges::

	template<typename F, typename ...Args>
	concept is_funcable = requires/*(F fun, Args... args)*/ {
		requires (requires(F fun, Args... args) { fun.operator()(args...); } ||
			requires(Args... args) { F::operator()(args...); }
		);
	};

#else
	#define CONST20 
	#define RANGES_ std::
#endif

#if _HAS_CXX17
	#define IF_CONST if constexpr
#else 
	#define IF_CONST if
#endif // _HAS_CXX17




#ifdef DEBUG_LEVEL_NONE
	#define log(...)
	#define loge(...)
#endif // DEBUG_LEVEL == NONE

#ifdef DEBUG_LEVEL_INFO
	#define log(...) PRINTLN(__VA_ARGS__)
	#define loge(...) PRINTLN(__VA_ARGS__)
#endif // DEBUG_LEVEL == INFO

#ifdef DEBUG_LEVEL_ERROR
	#define log(...) 
	#define loge(...) PIRNTLN(__VA_ARGS__)
#endif // DEBUG_LEVEL == ERROR


