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

	//1. ���ϴ� ũ�⸸ŭ ���ο� �޸� ���� �Ҵ�
	int* new_pt = Malloc_c<int>(array.i_max_count);

	//2. ���� �迭�� �����͸� ���ο� �迭 �����Ϳ� ����
	for (int i = 0; i < array.i_count; ++i)
		new_pt[i] = array.p_arr[i];

	//3. ���� �迭�� �޸� ���� ����
	Free_c<int>(array.p_arr);

	//4. ���� �迭�� ����Ű�� �����Ϳ� ���ο� �迭�� ù ��° �ּ� �� ����
	array.p_arr = new_pt;
}

void ReleaseArray(MyArray& array)
{
	Free_c<int>(array.p_arr);
	array.i_count = 0;
	array.i_max_count = 0;
}