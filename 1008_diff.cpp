/*
����
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

�Է�
ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.

���
ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�.
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
} // �ش� �迭���� Ư�� ���ڰ� �Էµɶ������� �迭���� ��. �� �迭���� Ư�������� ��°��.
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
} // ������ ���� ���� ���� ���ĺ� �˾Ƴ��� �Լ��� �ƴ�. �׷��� �迭 MostFreAlpa�� ���� �� ���� ū ���� i, j��° ���Ҷ� �ϸ� 
  // �Է¹��� �ܾ� �� �迭 Word�� ���� �� i, j��° ���ҿ� ���� ���� ���� ���ĺ��� ����Ǿ� ������ �̿���. 
  // �Ʒ��� �Լ�(outputOfMostFreAlpa)�� Word�� ���� �� i, j��° ���� �� ���� ���� ���� ���ĺ��� ����ϴ� �Լ�.
  // �� ���� ���� ���� �Լ��� ������ ������ '?'�� ����ϱ� ���� ���� �ٸ� ������� ����.
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