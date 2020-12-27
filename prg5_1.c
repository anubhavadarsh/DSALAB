#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

double calculate(char symbol,double op1, double op2)
{
    switch (symbol)
    {
    case '+': return op1 + op2;
    case '-': return op1 - op2;
    case '*': return op1 * op2;
    case '/': return op1 / op2;
    default:  return 0;
    }
}

void evaluate(char exp[])
{
    double stack[50];
    int top = -1;

    for(int i = 0; i < strlen(exp)-1; ++i)
    {
        char symbol = exp[i];
        if(isdigit(symbol))
        {
            stack[++top] = exp[i] - '0';
        }
        else
        {
            double op2 = stack[top--];
            double op1 = stack[top--];

            double res = calculate(symbol, op1, op2);

            stack[++top] = res;
        }
    }
    double result = stack[top--];
    printf("\nThe result is: %f\n",result);
}

int main()
{
    char exp[50];
    printf("\nEnter a valid postfix expression: ");
    fgets(exp,sizeof(exp),stdin);

    evaluate(exp);
    return 0;
}