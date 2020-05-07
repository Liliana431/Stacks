
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

