#include <stdio.h>
#include <stdlib.h>

//global variables
int arr[5];
int top = -1;

void push()
{
    if(top == 4)
    {
        printf("STACK OVERFLOW!\n");
    }
    else
    {
        printf("Enter the element to be inserted: ");
        int elem;
        scanf("%d",&elem);
        ++top;
        arr[top] = elem;
    }
    
}

int pop()
{
    if(top == -1)
    {
        printf("STACK UNDERFLOW!\n");
    }
    else
    {
        int elem = arr[top];
        --top;
        printf("The popped element is: %d",elem);
        return elem;
    }
    
}

void palindrome()
{
    if(top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        int i = 0, j = top;
        while(i <= j)
        {
            if(arr[i] != arr[j])
            {
                printf("Not palindrome\n");
                return;
            }
            ++i; --j;
        }
        printf("Palindrome\n");
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is empty!\n");
    }
    else
    {
        for(int i = 0; i <= top; ++i)
        {
            printf("%d ",arr[i]);
        }
    }
}

int main()
{   
    int exit_ = 0;
    do
    {
        printf("\n\n--------STACK OPERATIONS--------\n");
        printf("1.PUSH  ");
        printf("2.POP  ");
        printf("3.PALINDROME  ");
        printf("4.DISPLAY  ");
        printf("5.EXIT\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);;

        switch (choice)
        {
        case 1:
            push();break;
        case 2:
            pop(); break;
        case 3:
            palindrome();break;
        case 4:
            display();break;
        case 5:
            exit_ = 1;break;
        default:
            printf("Invalid choice!\n");
            break;
        }

    } while (!exit_);
    
    return 0;
}