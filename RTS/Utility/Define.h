#pragma once
#include <iostream>
#include <memory>

#define FORCEINLINE __forceinline

template<typename T>
FORCEINLINE void Log(const T& t)
{
	std::cout << t << "\n";
}

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;
