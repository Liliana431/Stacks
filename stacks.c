
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
//3 �����
struct s
{
	int first[3];
	int last[3];
	int count[3];
	int* arr;// ������ ��� 3 �����
};




// �������� �����
int* create()
{
	struct s* stack;
	stack = malloc(sizeof(struct s));
	stack->arr = malloc(6 * sizeof(int*));
	//���������� ������� ��������� NULL
	for (int i = 0; i < 6; i++)
		stack->arr[i] = NULL;
	// ����������� ������ ������� � ���������� �������� ������� �����
	stack->first[0] = 0;
	stack->last[0] = NULL;
	stack->first[1] = 2;
	stack->last[1] = NULL;
	stack->first[2] = 4;
	stack->last[2] = NULL;
	//������������ ���������� ������ ������� �����
	stack->count[0] = 2;
	stack->count[1] = 2;
	stack->count[2] = 2;
	return stack;
}

