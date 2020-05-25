#ifndef parenthesis_check
#define parenthesis_check
#include "stacks.h"

// ���������� ��������� ����� ��������� �������� �����
int max(struct stack* stack);

//������������ ��������������� ������
// 1 - ���� ��� ������ �������
// 0 - ���
int delete_simbol(int simbol, struct stack* stack);

//������ ������ � ����
void add_simbol(int simbol, int count, struct stack* stack);

// ������������ ������ � �������� ����������� ������
int read_symbols(struct stack* stack);

#endif
