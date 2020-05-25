#ifndef stacks
#define stacks

//3 �����
struct stack
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
int how_full(struct stack* stack, int stack_number);

// �������� �����
struct stack* create();

// ���������� ����� � ����
void add_place(struct stack* stack, int stack_number);

// �������� ������ ����� �� �����
void clear_place(struct stack* stack, int stack_number);

// �������� ���������� �������� �����
int top(struct stack* stack, int stack_number);

// ������� ������� �� �����
int pop(struct stack* stack, int stack_number);

// �������� ������� � ����
void push(struct stack* stack, int stack_number, int value);

#endif
