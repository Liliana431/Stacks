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

// ���������� ��������� ����� ��������� �������� �����
int max(struct s* stack);

//������������ ��������������� ������
// 1 - ���� ��� ������ �������
// 0 - ���
int delete_simbol(int simbol, struct s* stack);

//������ ������ � ����
void add_simbol(int simbol, int count, struct s* stack);

// ������������ ������ � �������� ����������� ������
int read_symbols(struct s* stack);

#endif
