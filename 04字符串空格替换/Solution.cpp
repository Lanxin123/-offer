#include "stdafx.h"
#include <iostream>
using namespace std;

void ReplaceBlank(char string[], int length)
{
	if (length<=0||string==NULL)
	{
		return;
	}
	
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (string[i]!='\0')
	{
		++originalLength;
		
		if (string[i]==' ')
		 ++numberOfBlank;
		
		++i;
	}
	
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		return;

	int indexOfOriginal = originalLength;
	int indexOfnew = newLength;
	while (indexOfOriginal >= 0 && indexOfnew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfnew--] = '0';
			string[indexOfnew--] = '2';
			string[indexOfnew--] = '%';
		}
		else
		{
			string[indexOfnew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

int main()
{
	char string[10] = "1 2";
	ReplaceBlank(string, 10);
	for (int i = 0;i<4;i++)
	{
		cout << string[i];
	}
}