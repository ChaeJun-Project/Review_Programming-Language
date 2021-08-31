#pragma once

#include <cassert>

unsigned int GetTextLength(const wchar_t* text)
{
	unsigned int length = 0;
	while (*(text + length) != NULL)
	{
		++length;
	}

	return length;
}

void StrCat(wchar_t* pDest, unsigned int& iBufferSize, const wchar_t* pSrc)
{
	assert(pSrc);

	unsigned int dest_length = GetTextLength(pDest);
	unsigned int src_length = GetTextLength(pSrc);

	if (iBufferSize < dest_length + src_length + 1)
		return;

	for (int i = 0; i < src_length; ++i)
	{
		pDest[dest_length + i] = pSrc[i];
	}
}

//일치 0 반환
//왼쪽 값이 더 순위가 높으면 -1 반환
//오른쪽 값이 더 순위가 높으면 1 반환
//같은 알파벳이어도 대문자가 소문자보다 순위가 더 높음
unsigned int StrCmp(const wchar_t* pSrc1, const wchar_t* pSrc2)
{
	unsigned int min_length = 0;
	unsigned int pSrc1_length = GetTextLength(pSrc1);
	unsigned int pSrc2_length = GetTextLength(pSrc2);

	pSrc1_length >= pSrc2_length ? min_length = pSrc2_length : min_length = pSrc1_length;

	//문자열 비교
	//같은 알파벳이어도 대문자가 소문자보다 순위가 더 높음
	//아스키 코드 값으로 접근
	//두 문자열 중 가장 길이가 작은 문자열을 기준으로 while문 검사

	int result = 0;

	unsigned int index = 0;
	while (index <= min_length)
	{
		if (pSrc1[index] > pSrc2[index]) //pSrc2의 문자열 순위가 더 높음
		{
			result = 1;
			return result;
		}

		else if (pSrc1[index] < pSrc2[index]) //pSrc1의 문자열 순위가 더 높음
		{
			result = -1;
			return result;
		}

		++index;
	}

	//가장 짧은 문자열의 길이를 기준으로 비교했을 때 같은 경우
	if (pSrc1_length == pSrc2_length) //비교하는 두 문자열의 길이가 같은 경우
	{
		return result; //pSrc1과 pSrc2의 문자열은 서로 일치함
	}

	else //비교하는 두 문자열의 길이가 다른 경우
	{
		//뒤에 문자가 더 있는 경우 순위가 더 낮음 = 문자열의 길이가 더 긴 것이 순위가 낮음
		pSrc1_length > pSrc2_length ? result = 1 : result = -1;
		return result;
	}
}
