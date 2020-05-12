

#include <stdio.h>
#include <stdlib.h>
//3 стека
struct s
{
	int first[3];
	int last[3];
	int count[3];
	int* arr;// массив под 3 стека
	int count_arr;
};


// проверка заполненности стека
// 0 - пуст 
// 1 - заполнен на 1/4 или меньше
// 2 - полон
// 3 - другое
int how_full(struct s* stack, int stack_number)
{
	//стек пуст
	if (stack->last[stack_number] == -1)
		return 0;
	//первый стек заполнен на 1/4 или меньше
	if (stack_number == 0 && stack->last[0] <= stack->count[0]/4)
		return 1;
	//средний стек заполнен на 1/4 или меньше
	if (stack_number == 1 && stack->last[1] - stack->count[0] + 1 <= stack->count[1] / 4)
		return 1;
	//последний стек заполнен на 1/4 или меньше
	if (stack_number == 2 && stack->count_arr - stack->last[2] - 1 >= stack->count[2] * 3 / 4)
		return 1;
	//последний стек заполнен
	if (stack_number == 2 && stack->last[2] + 1 == stack->count_arr)
		return 2;
	//первый или средний стек заполнен
	if (stack_number < 2 && stack->last[stack_number] + 1 == stack->first[stack_number + 1])
		return 2;
	return 3;
}

// создание стека
struct s* create()
{
	struct s* stack;
	stack = malloc(sizeof(struct s));
	stack->arr = malloc(6 * sizeof(int*));
	//заполнение массива значением NULL
	for (int i = 0; i < 6; i++)
		stack->arr[i] = NULL;
	// записывание номера первого и последнего элемента каждого стека
	stack->first[0] = 0;
	stack->last[0] = -1;
	stack->first[1] = 2;
	stack->last[1] = -1;
	stack->first[2] = 4;
	stack->last[2] = -1;
	//записыввание количества ячеек каждого стека
	stack->count[0] = 2;
	stack->count[1] = 2;
	stack->count[2] = 2;
	//записывание длины массива
	stack->count_arr = 6;
	return stack;
}

// добавление ячеек в стек
void add_place(struct s* stack, int stack_number)
{
	// добавление памти в конец массива
	stack->arr = realloc(stack->arr, (stack->count_arr + stack->count[stack_number]) * sizeof(int));
	// если это стек, стоящий в конце массива
	if (stack_number == 2)
	{
		//записывание в пустые ячейки значение NULL
		for (int i = stack->last[2] + 1; i < stack->count_arr + stack->count[2]; i++)
			stack->arr[i] = NULL;
		//изменение размера массива
		stack->count_arr += stack->count[2];
		//изменение размера стека
		stack->count[2] *= 2;
		return;
	}
	//для остальных случаев
	// перемещение значений всех стеков, находящихся после увеличиваемого, в конец
	for (int i = stack->count_arr + stack->count[stack_number] - 1; i >= stack->first[stack_number + 1]; i--)
		stack->arr[i] = stack->arr[i - stack->count[stack_number]];
	// заполнение незаполненных ячеек увеличиваемого стека
	for (int i = stack->last[stack_number] + 1; i < stack->first[stack_number + 1] + stack->count[stack_number]; i++)
		stack->arr[i] = NULL;
	// для среднего стека 
	// изменение начала и концаа последнего стека
	if (stack_number == 1)
	{
		stack->first[2] += stack->count[stack_number];
		stack->last[2] += stack->count[stack_number];
	}
	// для первого стека
	// изменение начала и концаа последнего и среднего стека
	else
	{
		stack->first[2] += stack->count[stack_number];
		stack->first[1] += stack->count[stack_number];
		stack->last[1] += stack->count[stack_number];
		stack->last[2] += stack->count[stack_number];
	}
	//изменение размера массива
	stack->count_arr += stack->count[stack_number];
	//изменение размера стека
	stack->count[stack_number] *= 2;
	return;
}

// удаление лишних ячеек из стека
void clear_place(struct s* stack, int stack_number)
{
	// для последнего стека
	if (stack_number == 2)
	{
		//убрать лишние ячейки из конца массива
		stack->arr = realloc(stack->arr, (stack->count_arr - (stack->count[2] / 2)) * sizeof(int));
		//изменение размера стека
		stack->count[2] /= 2;
		//изменение размера массива
		stack->count_arr = stack->count[0] + stack->count[1] + stack->count[2];
		return;
	}
	//для остальных случаев
	// перемещение значений всех стеков, находящихся после уменьшаемого, на их будущее место
	for (int i = stack->first[stack_number] + stack->count[stack_number] / 2; i < stack->count_arr - (stack->count[stack_number] / 2); i++)
		stack->arr[i] = stack->arr[i + (stack->count[stack_number] / 2)];
	//изменение размера стека
	stack->count[stack_number] /= 2;
	//изменение размера массива
	stack->count_arr -= stack->count[stack_number];
	//убрать лишние ячейки из конца массива
	stack->arr = realloc(stack->arr, (stack->count_arr) * sizeof(int));
	// для среднего стека 
	// изменение начала и концаа последнего стека
	if (stack_number == 1)
	{
		stack->first[2] -= stack->count[stack_number];
		stack->last[2] -= stack->count[stack_number];
	}
	// для первого стека
	// изменение начала и концаа последнего и среднего стека
	else
	{
		stack->first[2] -= stack->count[stack_number];
		stack->first[1] -= stack->count[stack_number];
		stack->last[1] -= stack->count[stack_number];
		stack->last[2] -= stack->count[stack_number];
	}
	return;
}

// значение последнего элемента стека
int top(struct s* stack, int stack_number)
{
	return stack->arr[stack->last[stack_number]];
}

// достать элемент из стека
int pop(struct s* stack, int stack_number)
{
	//значение последнего элемента
	int value;
	value = stack->arr[stack->last[stack_number]];
	//вместо него записывается NULL
	stack->arr[stack->last[stack_number]] = NULL;
	//изменяется номер последнего элемента
	if (stack->last[stack_number] == stack->first[stack_number])
		stack->last[stack_number] = -1;
	else
		stack->last[stack_number] --;
	// если стек заполнен меньше, чем на 1/4
	if (how_full(stack, stack_number) == 1)
		// удаление лишних ячеек из стека
		clear_place(stack, stack_number);
	return value;
}

// положить элемент в стек
void push(struct s* stack, int stack_number, int value)
{
	// если стек полон
	if (how_full(stack, stack_number) == 2)
		//добавить место
		add_place(stack, stack_number);
	// изменение номера последнего элемента стека
	if (stack_number > 0 && stack->last[stack_number] == -1)
		stack->last[stack_number] = stack->first[stack_number];
	else
		stack->last[stack_number] ++;
	// записывание туда значения
	stack->arr[stack->last[stack_number]] = value;
	return;
}

