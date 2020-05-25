#ifndef stacks
#define stacks

//3 стека
struct stack
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
int how_full(struct stack* stack, int stack_number);

// создание стека
struct stack* create();

// добавление ячеек в стек
void add_place(struct stack* stack, int stack_number);

// удаление лишних ячеек из стека
void clear_place(struct stack* stack, int stack_number);

// значение последнего элемента стека
int top(struct stack* stack, int stack_number);

// достать элемент из стека
int pop(struct stack* stack, int stack_number);

// положить элемент в стек
void push(struct stack* stack, int stack_number, int value);

#endif
