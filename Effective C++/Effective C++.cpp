// Effective C++.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int Fibo_Re(int num)
{
	if (num == 1 || num == 2)
		return 1;

	return Fibo_Re(num - 1) + Fibo_Re(num - 2);
}

int Fibo(int num)
{
	if (num == 1 || num == 2)
		return 1;

    int result = 0;
	int temp1 = 1;
	int temp2 = 1;

	for (int i = 0; i < num - 2; i++)
	{
		result = temp1 + temp2;

		temp1 = temp2;
		temp2 = result;
	}

	return result;
}

struct d
{
  int q;
  double r;
};

struct qwerqwe
{
   d wer;
   int dsadasd;
   char dadasd;
};

int main()
{
	return 0;
}
