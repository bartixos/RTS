#pragma once
#include "stdafx.h"
#include <unordered_map>
template <typename T>
class AResourceManager
{
protected:
	using ResourceMap = std::unordered_map<std::string, SharedPtr<T>>;
	AResourceManager()
	{
		resourceMap.clear();
	}

	ResourceMap resourceMap;

public:
	bool Exist(const std::string& name) noexcept;
	SharedPtr<T> GetResource(const std::string& name) noexcept;
	//Path is from Assets dir
	SharedPtr<T> LoadResouce(const std::string& name, const std::string& path) noexcept;

	//todo: Add Remove resources
	void Remove() noexcept;
};

template<typename T>
inline bool AResourceManager<T>::Exist(const std::string & name) noexcept
{
	if (resourceMap[name])
		return true;
	else
		return false;
}

template<typename T>
inline SharedPtr<T> AResourceManager<T>::GetResource(const std::string & name)noexcept
{
	if (Exist(name))
	{
		return resourceMap[name];
	}
	return nullptr;
}

template<typename T>
inline SharedPtr<T> AResourceManager<T>::LoadResouce(const std::string & name, const std::string & path)noexcept
{
	if (Exist(name))
	{
		return GetResource(name);
	}
	else
	{
		std::string _path = "Assets/" + path;
		resourceMap.insert_or_assign(name, std::make_shared<T>());
		if (!resourceMap[name]->loadFromFile(_path))
		{
			Log("Cannot Load Texture with name " + name);
		}
		return resourceMap[name];
	}
}

template<typename T>
inline void AResourceManager<T>::Remove()noexcept
{
}
