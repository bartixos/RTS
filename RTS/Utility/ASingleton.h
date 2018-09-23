#pragma once
#include "stdafx.h"

template <typename T>
class ASingleton
{
protected:
	ASingleton()
	{
	}
	static inline SharedPtr<T> instance = nullptr;

public:
	static SharedPtr<T> GetInstance()
	{
		if (!instance)
		{
			instance = std::make_shared<T>();
		}
		return instance;
	}
};
