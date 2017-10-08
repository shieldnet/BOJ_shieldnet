/*
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*int FigSizeOfWord(char *Word)
{
char *EndPoint = strchr(Word, 'Null');
int NumOfAlpabet = Word - (int*)EndPoint;

return NumOfAlpabet;
} // 해당 배열에서 특정 문자가 입력될때까지의 배열원소 수. 즉 배열에서 특정문자의 번째수.
*/
void Initialization_arr(int *MostFreAlpa, int NumOfAlpabet)
{
	int i;
	for (i = 0; i < NumOfAlpabet; i++)
	{
		*(MostFreAlpa + i) = 1;
	}
}

void FigMostFreAlpa(char *Word, int *MostFreAlpa, int NumOfAlpabet)
{
	int i, j;
	for (i = 0; i < NumOfAlpabet; i++)
	{
		for (j = i + 1; j < NumOfAlpabet; j++)
		{
			if (i != 0)
			{

				if (MostFreAlpa[i - 1] >(NumOfAlpabet - i))
					break;
			}
			if (Word[i] == Word[j] || Word[i] == Word[j] - 32 || Word[i] - 32 == Word[j])
				MostFreAlpa[i]++;
		}
	}
} // 실제로 가장 많이 쓰인 알파벳 알아내는 함수가 아님. 그러나 배열 MostFreAlpa의 원소 중 가장 큰 수를 i, j번째 원소라 하면 
  // 입력받은 단어 즉 배열 Word의 원소 중 i, j번째 원소에 가장 많이 쓰인 알파벳이 저장되어 있음을 이용함. 
  // 아래의 함수(outputOfMostFreAlpa)가 Word의 원소 중 i, j번째 원소 즉 가장 많이 쓰인 알파벳을 출력하는 함수.
  // 단 가장 많이 쓰인 함수가 여러개 있으면 '?'를 출력하기 위한 여러 다른 문장들이 있음.
void OutputOfMostFreAlpa(char *Word, int *MostFreAlpa, int NumOfAlpabet)
{
	int i, Maximum_point, exist_SameValue, Maximum = MostFreAlpa[0];
	for (i = 1; i < NumOfAlpabet; i++)
	{
		if (Maximum < MostFreAlpa[i])
		{
			Maximum = MostFreAlpa[i];
			Maximum_point = i;
			exist_SameValue = 0;
		}
		else if (Maximum == MostFreAlpa[i])
		{
			exist_SameValue = 1;
		}
	}
	// Output of the most frequent Alpabet or '?'
	if (exist_SameValue == 1)
		putchar('?');
	else
	{
		printf("%c", Word[Maximum_point]);
	}
}

int main(void)
{
	int i = 0;
	char Word[1000000];
	//scanf("%s", Word);
	while (*(Word + i))
	{
		scanf("%d", Word + i++);
	}
	int NumOfAlpabet = i;
	int *MostFreAlpa = (int *)malloc(NumOfAlpabet * sizeof(int));

	Initialization_arr(MostFreAlpa, NumOfAlpabet);
	//ChangeElements(MostFreAlpa, NumOfAlpabet);
	FigMostFreAlpa(Word, MostFreAlpa, NumOfAlpabet);
	OutputOfMostFreAlpa(Word, MostFreAlpa, NumOfAlpabet);

	free(MostFreAlpa);
	return 0;
}