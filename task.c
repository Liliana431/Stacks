
#include <stdio.h>
#include "stacks.h"

// нахождени€ максимума среди последний значений стека
int max(struct s* stack)
{
	int m1 = 0, m2 = 0, m3 = 0, m;
	// пусты ли эти стеки
	if (how_full(stack, 0) != 0)
		m1 = top(stack, 0);
	if (how_full(stack, 1) != 0)
		m2 = top(stack, 1);
	if (how_full(stack, 2) != 0)
		m3 = top(stack, 2);
	//сравнение значений
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

//вычеркивание соответствующей скобки
// 1 - если все прошло успешно, 0 - нет
int delete_simbol(int simbol, struct s* stack)
{
	int stack_number;
	// если скобка кругла€
	if (simbol == ')')
		//выбираетс€ первый стек
		stack_number = 0;
	//если скобки квадратна€
	if (simbol == ']')
		//выбираетс€ средний стек
		stack_number = 1;
	// если скобка фигурна€
	if (simbol == '}')
		//выбираетс€ пеоследний стек
		stack_number = 2;
	// если этот стек пустой
	if (how_full(stack, stack_number) == 0)
		return 0;
	// если скобки совпадают
	if (max(stack) == pop(stack, stack_number))
		return 1;
	return 0;
}

//запись скобки в стек
void add_simbol(int simbol, int count, struct s* stack)
{
	// если скобка кругла€
	if (simbol == '(')
		// записать ее номер в первый стек
		push(stack, 0, count);
	//если скобки квадратна€
	if (simbol == '[')
		//записать ее номер в средний стек
		push(stack, 1, count);
	// если скобка фигурна€
	if (simbol == '{')
		// записать ее номер в последний стек
		push(stack, 2, count);
	return;
}

// посимвольное чтение и проверка расстановки
int read_symbols(struct s* stack)
{
	// p - значение, которое возвращает функци€ вычеркивани€ скобок
	// 1 - если все прошло успешно, 0 - если скобки не было
	// счетчик показывает количество прочитанных открывающихс€ скобок
	int p = 0, count = 0;
	char simbol;
	// пока есть символы дл€ чтени€
	while (scanf_s("%c", &simbol))
	{
		// если строка закончилась
		if (simbol == '\n')
			//выход из цикла
			break;
		// если это открывающа€с€ скобка
		if (simbol == '(' || simbol == '[' || simbol == '{')
		{
			// записать ее в стек
			count++;
			add_simbol(simbol, count, stack);
		}
		// если скобка закрывающа€с€
		if (simbol == ')' || simbol == ']' || simbol == '}')
		{
			// вычеркнуть соответствующую закрывающуюс€ скобку
			p = delete_simbol(simbol, stack);
			// если скобок не было
			if (p == 0)
				// скобки расставлены неправильно
				return 0;
		}
	}
	// если в стеках что-то лежит
	if (how_full(stack, 0) != 0 || how_full(stack, 1) != 0 || how_full(stack, 2) != 0)
		// скобки расставлены неправильно
		return 0;
	// в других случа€х правильно
	return 1;
}
