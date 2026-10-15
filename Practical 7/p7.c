#include <stdio.h>
#include <ctype.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int evaluate(char exp[], int n)
{
    int i, v1, v2, result;
    char ch;

    for(i = 0; i < n; i++)
    {
        ch = exp[i];

        if(isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            v2 = pop();
            v1 = pop();

            switch(ch)
            {
                case '+':
                    result = v1 + v2;
                    break;

                case '-':
                    result = v1 - v2;
                    break;

                case '*':
                    result = v1 * v2;
                    break;

                case '/':
                    result = v1 / v2;
                    break;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char exp[MAX];
    int n = 0, result;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    while(exp[n] != '\0')
    {
        n++;
    }

    result = evaluate(exp, n);

    printf("Result = %d\n", result);

    return 0;
}
