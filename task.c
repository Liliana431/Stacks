
#include <stdio.h>
#include "stacks.h"

// ���������� ��������� ����� ��������� �������� �����
int max(struct s* stack)
{
	int m1 = 0, m2 = 0, m3 = 0, m;
	// ����� �� ��� �����
	if (how_full(stack, 0) != 0)
		m1 = top(stack, 0);
	if (how_full(stack, 1) != 0)
		m2 = top(stack, 1);
	if (how_full(stack, 2) != 0)
		m3 = top(stack, 2);
	//��������� ��������
	if (m1 >= m2)
		if (m1 >= m3)
			m = m1;
		else
			m = m3;
	else
		if (m2 >= m3)
			m = m2;
		else
			m = m3;
	return m;
}

//������������ ��������������� ������
// 1 - ���� ��� ������ �������, 0 - ���
int delete_simbol(int simbol, struct s* stack)
{
	int stack_number;
	// ���� ������ �������
	if (simbol == ')')
		//���������� ������ ����
		stack_number = 0;
	//���� ������ ����������
	if (simbol == ']')
		//���������� ������� ����
		stack_number = 1;
	// ���� ������ ��������
	if (simbol == '}')
		//���������� ���������� ����
		stack_number = 2;
	// ���� ���� ���� ������
	if (how_full(stack, stack_number) == 0)
		return 0;
	// ���� ������ ���������
	if (max(stack) == pop(stack, stack_number))
		return 1;
	return 0;
}

//������ ������ � ����
void add_simbol(int simbol, int count, struct s* stack)
{
	// ���� ������ �������
	if (simbol == '(')
		// �������� �� ����� � ������ ����
		push(stack, 0, count);
	//���� ������ ����������
	if (simbol == '[')
		//�������� �� ����� � ������� ����
		push(stack, 1, count);
	// ���� ������ ��������
	if (simbol == '{')
		// �������� �� ����� � ��������� ����
		push(stack, 2, count);
	return;
}

// ������������ ������ � �������� �����������
int read_symbols(struct s* stack)
{
	// p - ��������, ������� ���������� ������� ������������ ������
	// 1 - ���� ��� ������ �������, 0 - ���� ������ �� ����
	// ������� ���������� ���������� ����������� ������������� ������
	int p = 0, count = 0;
	char simbol;
	// ���� ���� ������� ��� ������
	while (scanf_s("%c", &simbol))
	{
		// ���� ������ �����������
		if (simbol == '\n')
			//����� �� �����
			break;
		// ���� ��� ������������� ������
		if (simbol == '(' || simbol == '[' || simbol == '{')
		{
			// �������� �� � ����
			count++;
			add_simbol(simbol, count, stack);
		}
		// ���� ������ �������������
		if (simbol == ')' || simbol == ']' || simbol == '}')
		{
			// ���������� ��������������� ������������� ������
			p = delete_simbol(simbol, stack);
			// ���� ������ �� ����
			if (p == 0)
				// ������ ����������� �����������
				return 0;
		}
	}
	// ���� � ������ ���-�� �����
	if (how_full(stack, 0) != 0 || how_full(stack, 1) != 0 || how_full(stack, 2) != 0)
		// ������ ����������� �����������
		return 0;
	// � ������ ������� ���������
	return 1;
}
