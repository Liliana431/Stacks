
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
//3 стека
struct s
{
	int first[3];
	int last[3];
	int count[3];
	int* arr;// массив под 3 стека
};

			//?
// проверка заполненности стека
// 0 - пуст 
// 1 - имеет только 1 элемент
// 2 - заполнен на 1/4 или меньше
// 3 - полон
// 4 - другое
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

// создание стека
int* create()
{
	struct s* stack;
	stack = malloc(sizeof(struct s));
	stack->arr = malloc(6 * sizeof(int*));
	//заполнение массива значением NULL
	for (int i = 0; i < 6; i++)
		stack->arr[i] = NULL;
	// записывание номера первого и последнего элемента каждого стека
	stack->first[0] = 0;
	stack->last[0] = NULL;
	stack->first[1] = 2;
	stack->last[1] = NULL;
	stack->first[2] = 4;
	stack->last[2] = NULL;
	//записыввание количества яйчеек каждого стека
	stack->count[0] = 2;
	stack->count[1] = 2;
	stack->count[2] = 2;
	return stack;
}



