#ifndef stacks
#define stacks

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
int how_full(struct s* stack, int stack_number);

// �������� �����
struct s* create();

// ���������� ����� � ����
void add_place(struct s* stack, int stack_number);

// �������� ������ ����� �� �����
void clear_place(struct s* stack, int stack_number);

// �������� ���������� �������� �����
int top(struct s* stack, int stack_number);

// ������� ������� �� �����
int pop(struct s* stack, int stack_number);

// �������� ������� � ����
void push(struct s* stack, int stack_number, int value);

#endif
