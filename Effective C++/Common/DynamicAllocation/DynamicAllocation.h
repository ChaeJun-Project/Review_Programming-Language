#pragma once

#include <stdlib.h>
#include <cassert>

typedef struct MyArray
{
	int *p_arr;
	unsigned int i_count;
	unsigned int i_max_count;
}Array;

//�迭 �ʱ�ȭ
void InitArray(MyArray& array, const int& arr_size);

//�迭 Ȯ��
void ReallocArray(MyArray& array);

//�迭 ������ �߰�
void PushBack(MyArray& array, const int& data);

//�迭 �޸� ����
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