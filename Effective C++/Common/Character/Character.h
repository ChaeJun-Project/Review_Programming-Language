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

//��ġ 0 ��ȯ
//���� ���� �� ������ ������ -1 ��ȯ
//������ ���� �� ������ ������ 1 ��ȯ
//���� ���ĺ��̾ �빮�ڰ� �ҹ��ں��� ������ �� ����
unsigned int StrCmp(const wchar_t* pSrc1, const wchar_t* pSrc2)
{
	unsigned int min_length = 0;
	unsigned int pSrc1_length = GetTextLength(pSrc1);
	unsigned int pSrc2_length = GetTextLength(pSrc2);

	pSrc1_length >= pSrc2_length ? min_length = pSrc2_length : min_length = pSrc1_length;

	//���ڿ� ��
	//���� ���ĺ��̾ �빮�ڰ� �ҹ��ں��� ������ �� ����
	//�ƽ�Ű �ڵ� ������ ����
	//�� ���ڿ� �� ���� ���̰� ���� ���ڿ��� �������� while�� �˻�

	int result = 0;

	unsigned int index = 0;
	while (index <= min_length)
	{
		if (pSrc1[index] > pSrc2[index]) //pSrc2�� ���ڿ� ������ �� ����
		{
			result = 1;
			return result;
		}

		else if (pSrc1[index] < pSrc2[index]) //pSrc1�� ���ڿ� ������ �� ����
		{
			result = -1;
			return result;
		}

		++index;
	}

	//���� ª�� ���ڿ��� ���̸� �������� ������ �� ���� ���
	if (pSrc1_length == pSrc2_length) //���ϴ� �� ���ڿ��� ���̰� ���� ���
	{
		return result; //pSrc1�� pSrc2�� ���ڿ��� ���� ��ġ��
	}

	else //���ϴ� �� ���ڿ��� ���̰� �ٸ� ���
	{
		//�ڿ� ���ڰ� �� �ִ� ��� ������ �� ���� = ���ڿ��� ���̰� �� �� ���� ������ ����
		pSrc1_length > pSrc2_length ? result = 1 : result = -1;
		return result;
	}
}
