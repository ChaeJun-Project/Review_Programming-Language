#pragma once

#include <stdlib.h>
#include <cassert>

//C Style
template<typename T>
T* DynamicAllocate_c(const int& size)
{
	T* pt = (T*)malloc(sizeof(T) * size);
	return pt;
}

template<typename T>
void FreeDynamicAllocate_c(T* pt)
{
	free(pt);
	pt = NULL;
	assert(pt);
}

//C++ Style
template<typename T>
T* DynamicAllocate_cplusplus(const int& size)
{
	T* pt = new T[size];
	return pt;
}

template<typename T>
void DeleteDynamicAllocate_cplusplus(T* pt)
{
	delete[] pt;
	pt = nullptr;
	assert(pt);
}