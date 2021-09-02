#pragma once

#include <stdlib.h>
#include <cassert>

typedef struct MyArray
{
	int *p_arr;
	unsigned int i_count;
	unsigned int i_max_count;
}Array;

//배열 초기화
void InitArray(MyArray& array, const int& arr_size);

//배열 확장
void ReallocArray(MyArray& array);

//배열 데이터 추가
void PushBack(MyArray& array, const int& data);

//배열 메모리 해제
void ReleaseArray(MyArray& array);

//C Style
template<typename T>
T* Malloc_c(const unsigned int& size)
{
	T* pt = (T*)malloc(sizeof(T) * size);
	return pt;
}

template<typename T>
void Free_c(T* pt)
{
	free(pt);
	pt = NULL;
}

//C++ Style
template<typename T>
T* New_cplusplus(const unsigned int& size)
{
	T* pt = new T[size];
	return pt;
}

template<typename T>
void Delete_cplusplus(T* pt)
{
	delete[] pt;
	pt = nullptr;
	assert(pt);
}

template<typename T>
void DeleteArray_cplusplus(T* pt)
{
	delete[] pt;
	pt = nullptr;
	assert(pt);
}