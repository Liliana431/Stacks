#ifndef parenthesis_check
#define parenthesis_check
#include "stacks.h"

// нахождения максимума среди последний значений стека
int max(struct stack* stack);

//вычеркивание соответствующей скобки
// 1 - если все прошло успешно
// 0 - нет
int delete_simbol(int simbol, struct stack* stack);

//запись скобки в стек
void add_simbol(int simbol, int count, struct stack* stack);

// посимвольное чтение и проверка расстановки скобок
int read_symbols(struct stack* stack);

#endif
