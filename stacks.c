

#include <stdio.h>
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


// �������� ������������� �����
// 0 - ���� 
// 1 - �������� �� 1/4 ��� ������
// 2 - �����
// 3 - ������
int how_full(struct s* stack, int stack_number)
{
	//���� ����
	if (stack->last[stack_number] == -1)
		return 0;
	//������ ���� �������� �� 1/4 ��� ������
	if (stack_number == 0 && stack->last[0] <= stack->count[0]/4)
		return 1;
	//������� ���� �������� �� 1/4 ��� ������
	if (stack_number == 1 && stack->last[1] - stack->count[0] + 1 <= stack->count[1] / 4)
		return 1;
	//��������� ���� �������� �� 1/4 ��� ������
	if (stack_number == 2 && stack->count_arr - stack->last[2] - 1 >= stack->count[2] * 3 / 4)
		return 1;
	//��������� ���� ��������
	if (stack_number == 2 && stack->last[2] + 1 == stack->count_arr)
		return 2;
	//������ ��� ������� ���� ��������
	if (stack_number < 2 && stack->last[stack_number] + 1 == stack->first[stack_number + 1])
		return 2;
	return 3;
}

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
	stack->last[0] = -1;
	stack->first[1] = 2;
	stack->last[1] = -1;
	stack->first[2] = 4;
	stack->last[2] = -1;
	//������������ ���������� ����� ������� �����
	stack->count[0] = 2;
	stack->count[1] = 2;
	stack->count[2] = 2;
	//����������� ����� �������
	stack->count_arr = 6;
	return stack;
}

// ���������� ����� � ����
void add_place(struct s* stack, int stack_number)
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
		return;
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
	return;
}

// �������� ������ ����� �� �����
void clear_place(struct s* stack, int stack_number)
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
		return;
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
	// ��� �������� ����� 
	// ��������� ������ � ������ ���������� �����
	if (stack_number == 1)
	{
		stack->first[2] -= stack->count[stack_number];
		stack->last[2] -= stack->count[stack_number];
	}
	// ��� ������� �����
	// ��������� ������ � ������ ���������� � �������� �����
	else
	{
		stack->first[2] -= stack->count[stack_number];
		stack->first[1] -= stack->count[stack_number];
		stack->last[1] -= stack->count[stack_number];
		stack->last[2] -= stack->count[stack_number];
	}
	return;
}

// �������� ���������� �������� �����
int top(struct s* stack, int stack_number)
{
	return stack->arr[stack->last[stack_number]];
}

// ������� ������� �� �����
int pop(struct s* stack, int stack_number)
{
	//�������� ���������� ��������
	int value;
	value = stack->arr[stack->last[stack_number]];
	//������ ���� ������������ NULL
	stack->arr[stack->last[stack_number]] = NULL;
	//���������� ����� ���������� ��������
	if (stack->last[stack_number] == stack->first[stack_number])
		stack->last[stack_number] = -1;
	else
		stack->last[stack_number] --;
	// ���� ���� �������� ������, ��� �� 1/4
	if (how_full(stack, stack_number) == 1)
		// �������� ������ ����� �� �����
		clear_place(stack, stack_number);
	return value;
}

// �������� ������� � ����
void push(struct s* stack, int stack_number, int value)
{
	// ���� ���� �����
	if (how_full(stack, stack_number) == 2)
		//�������� �����
		add_place(stack, stack_number);
	// ��������� ������ ���������� �������� �����
	if (stack_number > 0 && stack->last[stack_number] == -1)
		stack->last[stack_number] = stack->first[stack_number];
	else
		stack->last[stack_number] ++;
	// ����������� ���� ��������
	stack->arr[stack->last[stack_number]] = value;
	return;
}

