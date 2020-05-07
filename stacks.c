
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

			//?
// �������� ������������� �����
// 0 - ���� 
// 1 - ����� ������ 1 �������
// 2 - �������� �� 1/4 ��� ������
// 3 - �����
// 4 - ������
int how_full(struct s* stack, int stack_number)
{
	if (stack->last[stack_number] == NULL)
		return 0;
	if (stack->last[stack_number] == stack->first[stack_number])
		return 1;
	if (stack->last[stack_number] <= stack->count[stack_number]/4)
		return 2;
	if (stack->last[stack_number] == stack->count[stack_number])
		return 3;
	return 4;
}
			//?

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



