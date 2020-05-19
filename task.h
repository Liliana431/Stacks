#ifndef stacks
#define stacks

//3 стека
struct s
{
	int first[3];
	int last[3];
	int count[3];
	int* arr;// массив под 3 стека
	int count_arr;
};

// нахождения максимума среди последний значений стека
int max(struct s* stack);

//вычеркивание соответствующей скобки
// 1 - если все прошло успешно
// 0 - нет
int delete_simbol(int simbol, struct s* stack);

//запись скобки в стек
void add_simbol(int simbol, int count, struct s* stack);

// посимвольное чтение и проверка расстановки скобок
int read_symbols(struct s* stack);

#endif
