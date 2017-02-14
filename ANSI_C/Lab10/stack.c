#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 15  //Начальный размер стека
#define STACK_OVERFLOW -100  //Код ошибки переполнения стека
#define STACK_UNDERFLOW -101  //Код ошибки недозаполнения стека
#define OUT_OF_MEMORY -102  //Код ошибки выхода за пределы памяти
#define MULTIPLER 3  //Множитель размера стека

struct stack  //Инициализация структуры стека
{
    int *data;
    size_t size;
    size_t top;
};
typedef struct stack Stack;

Stack* createStack();  //Функция создания стека

void deleteStack(Stack **stack);  //Функция удаления стека

void resizeStack(Stack *stack);  //Функция изменения размера стека

void pushData(Stack *stack, int value);  //Функция добавления данных в стек

int popData(Stack *stack);  //Функция, берущая вершину стека и уменьшающая его размер

int peek(Stack *stack);  //Функция вывода текущей вершины стека

void implodeStack(Stack *stack);  //Функция, уменьшающая стек до размера, равного числу элементов

int main()
{
    Stack *stack;

    stack = createStack();

    for(int i = 0; i < 50; i++)
    {
        pushData(stack,i);
    }
    implodeStack(stack);
    for(int i = 0; i < 50; i++)
    {
        printf("Взятый элемент с вершины: %d\n",popData(stack));
        printf("Текущий элемент вершины: %d\n", peek(stack));
        if (popData(stack) == 0)
            break;
    }
    deleteStack(&stack);
    return 0;
}

Stack* createStack()
{
    Stack *out = NULL;
    out = malloc(sizeof(Stack));
    if (out == NULL)
    {
        exit(OUT_OF_MEMORY);
    }
    out->size = INIT_SIZE;
    out->data = malloc(out->size * sizeof(int));
    if (out->data == NULL)
    {
        free(out);
        exit(OUT_OF_MEMORY);
    }
    out->top = 0;
    return out;
}

void deleteStack(Stack **stack)
{
    free((*stack)->data);
    free(*stack);
    *stack = NULL;
}

void resizeStack(Stack *stack)
{
    stack->size *= MULTIPLER;
    stack->data = realloc(stack->data, stack->size * sizeof(int));
    if (stack->data == NULL)
    {
        exit(STACK_OVERFLOW);
    }
}

void pushData(Stack *stack, int value)
{
    if (stack->top >= stack->size)
    {
        resizeStack(stack);
    }
    stack->data[stack->top] = value;
    stack->top++;
}

int popData(Stack *stack)
{
    if (stack->top ==0)
    {
        exit(STACK_UNDERFLOW);
    }
    stack->top--;
    return stack->data[stack->top];
}

int peek(Stack *stack)
{
    if (stack->top ==0)
    {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->top-1];
}

void implodeStack(Stack *stack)
{
    stack->size = stack->top;
    stack->data = realloc(stack->data, stack->size * sizeof(Stack));
}