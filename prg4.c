#include <stdio.h>
#include <stdlib.h>


int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;
        
        case '*':
        case '/':
        case '%':
            return 2;
        
        case '^':
            return 3;
        
        default:
            return 0;
    }
}

void infixPostfix(char infix[])
{
    char postfix[100];
    int top = -1;
    for(int i = 0; infix[i] != '\0'; i++)
    {
        if(precedence(infix[i]) == 0)
        {
            if(infix[i] == '(')
            {
                postfix[++top] = '(';
            }
            else if(infix[i] == ')')
            {
                while(postfix[top] != '(')
                {   
                    printf("%c",postfix[top--]);
                }
                --top;
            }
            else
            {
                printf("%c",infix[i]);
            }
        }
        else
        {
            if(top == -1)
            {
                postfix[++top] = infix[i];
            }
            else
            {
                if(precedence(infix[i]) > precedence(postfix[top]))
                {
                    postfix[++top] = infix[i];
                }
                else if(precedence(infix[i]) < precedence(postfix[top]))
                {
                    while(precedence(infix[i]) < precedence(postfix[top]))
                    {
                        printf("%c",postfix[top--]);
                    }
                    postfix[++top] = infix[i];
                }
                else
                {
                    if(precedence(infix[i]) != 3)
                    {
                        while(precedence(infix[i]) == precedence(postfix[top]))
                        {
                            printf("%c",postfix[top--]);
                        }
                        postfix[++top] = infix[i];
                    }
                    else
                    {
                        postfix[++top] = infix[i];
                    }
                }
                
            }
            
        }
        
    }
    while(top != -1)
    {
        printf("%c",postfix[top--]);
    }
}

int main()
{
    char infix[100];

    printf("\nEnter a valid infix expression: ");
    fgets(infix,sizeof(infix), stdin);

    infixPostfix(infix);

    return 0;
}