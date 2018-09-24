#pragma once
#include <iostream>
#include <memory>

#define FORCEINLINE __forceinline

#ifdef _DEBUG

template<typename T>
FORCEINLINE void Log(const T& t)
{
	std::cout << t << "\n";
}
#else
template<typename T>
FORCEINLINE void Log(const T& t) {}

#endif // _DEBUG

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;
