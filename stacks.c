
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
	int count_arr;
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
struct s* create()
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
	//����������� ����� �������
	stack->count_arr = 6;
	return stack;
}

// ���������� ������ � ����
struct s* add_place(struct s* stack, int stack_number)
{
	// ���������� ����� � ����� �������
	stack->arr = realloc(stack->arr, (stack->count_arr + stack->count[stack_number]) * sizeof(int));
	// ���� ��� ����, ������� � ����� �������
	if (stack_number == 2)
	{
		//����������� � ������ ������ �������� NULL
		for (int i = stack->last[2] + 1; i < stack->count_arr + stack->count[2]; i++)
			stack->arr[i] = NULL;
		//��������� ������� �������
		stack->count_arr += stack->count[2];
		//��������� ������� �����
		stack->count[2] *= 2;
		return stack;
	}
	//��� ��������� �������
	// ����������� �������� ���� ������, ����������� ����� ��������������, � �����
	for (int i = stack->count_arr + stack->count[stack_number] - 1; i >= stack->first[stack_number + 1]; i--)
		stack->arr[i] = stack->arr[i - stack->count[stack_number]];
	// ���������� ������������� ����� �������������� �����
	for (int i = stack->last[stack_number] + 1; i < stack->first[stack_number + 1] + stack->count[stack_number]; i++)
		stack->arr[i] = NULL;
	// ��� �������� ����� 
	// ��������� ������ � ������ ���������� �����
	if (stack_number == 1)
	{
		stack->first[2] += stack->count[stack_number];
		stack->last[2] += stack->count[stack_number];
	}
	// ��� ������� �����
	// ��������� ������ � ������ ���������� � �������� �����
	else
	{
		stack->first[2] += stack->count[stack_number];
		stack->first[1] += stack->count[stack_number];
		stack->last[1] += stack->count[stack_number];
		stack->last[2] += stack->count[stack_number];
	}
	//��������� ������� �������
	stack->count_arr += stack->count[stack_number];
	//��������� ������� �����
	stack->count[stack_number] *= 2;
	return stack;
}

// �������� ������ ������ �� �����
struct s* clear_place(struct s* stack, int stack_number)
{
	// ��� ���������� �����
	if (stack_number == 2)
	{
		//������ ������ ������ �� ����� �������
		stack->arr = realloc(stack->arr, (stack->count_arr - (stack->count[2] / 2)) * sizeof(int));
		//��������� ������� �����
		stack->count[2] /= 2;
		//��������� ������� �������
		stack->count_arr = stack->count[0] + stack->count[1] + stack->count[2];
		return stack;
	}
	//��� ��������� �������
	// ����������� �������� ���� ������, ����������� ����� ������������, �� �� ������� �����
	for (int i = stack->first[stack_number] + stack->count[stack_number] / 2; i < stack->count_arr - (stack->count[stack_number] / 2); i++)
		stack->arr[i] = stack->arr[i + (stack->count[stack_number] / 2)];
	//��������� ������� �����
	stack->count[stack_number] /= 2;
	//��������� ������� �������
	stack->count_arr -= stack->count[stack_number];
	//������ ������ ������ �� ����� �������
	stack->arr = realloc(stack->arr, (stack->count_arr) * sizeof(int));
	return stack;
}

