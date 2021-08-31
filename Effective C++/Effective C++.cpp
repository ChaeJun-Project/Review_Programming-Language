#include <iostream>
#include "Common/DynamicAllocation/DynamicAllocation.h"

int main()
{
    int* pt = DynamicAllocate_cplusplus<int>(100);
	pt[50] = 100;

	std::cout<< pt[50]<<std::endl;

	DeleteDynamicAllocate_cplusplus<int>(pt);

	std::cout << pt[50];

	return 0;
}
