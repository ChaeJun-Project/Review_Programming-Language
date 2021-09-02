#include "DynamicAllocation.h"

void InitArray(MyArray & array, const int & arr_size)
{
	array.p_arr = Malloc_c<int>(arr_size);
	array.i_count = 0;
	array.i_max_count = arr_size;
}

void PushBack(MyArray& array, const int & data)
{
	if (array.i_count < array.i_max_count)
	{
		array.p_arr[array.i_count] = data;

		++array.i_count;
	}

	else
	{
		ReallocArray(array);

		array.p_arr[array.i_count] = data;

		++array.i_count;
	}
}

void ReallocArray(MyArray & array)
{
	array.i_max_count *= 2;

	//1. 원하는 크기만큼 새로운 메모리 영역 할당
	int* new_pt = Malloc_c<int>(array.i_max_count);

	//2. 기존 배열의 데이터를 새로운 배열 데이터에 복사
	for (int i = 0; i < array.i_count; ++i)
		new_pt[i] = array.p_arr[i];

	//3. 기존 배열의 메모리 영역 해제
	Free_c<int>(array.p_arr);

	//4. 기존 배열을 가리키는 포인터에 새로운 배열의 첫 번째 주소 값 저장
	array.p_arr = new_pt;
}

void ReleaseArray(MyArray& array)
{
	Free_c<int>(array.p_arr);
	array.i_count = 0;
	array.i_max_count = 0;
}