#include <iostream>
#include "Common/DynamicAllocation/DynamicAllocation.h"

class UserObject
{
private:
	int (UserObject::*mp_func_list[4])(const int&, const int&);


public:
	UserObject()
	{
		mp_func_list[0] = &UserObject::Add;
		mp_func_list[1] = &UserObject::Sub;
		mp_func_list[2] = &UserObject::Mul;
		mp_func_list[3] = &UserObject::Div;
	}

	int Add(const int& a, const int& b)
	{
		return a + b;
	}

	int Sub(const int& a, const int& b)
	{
		return a - b;
	}

	int Mul(const int& a, const int& b)
	{
		return a * b;
	}

	int Div(const int& a, const int& b)
	{
		return b ? a/b : 0;
	}

	int (UserObject::**GetFuncList()) (const int&, const int&)
	{
	   return mp_func_list;
	}

};



int main()
{
	
	UserObject data;

	int (UserObject::**p)(const int&, const int&) = data.GetFuncList();

	for (int i = 0; i < 4; ++i)
	{
		std::cout<< (data.*(p[i]))(5, 4) <<std::endl;
		
	}

	return 0;
}
