#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cap_c 5
int size = 0, front = 0;
char arr[cap_c];

int isFull()
{
    return (size == cap_c);
}

int isEmpty()
{
    return (size == 0);
}

void deque()
{
    if(isEmpty()) {printf("QUEUE IS EMPTY!\n"); return;}

    front = (front + 1)%cap_c;
    --size;
}

void insert()
{
    if(isFull()) {printf("QUEUE IS FULL!\n"); return;}

    char elem;
    printf("Enter character or value to be inserted: ");
    scanf("%c",&elem);

    int rear = (front + size -1)%cap_c;
    rear = (rear + 1) % cap_c;

    arr[rear] = elem;
    ++size;  
}

void display()
{
    if(isEmpty()) {printf("QUEUE IS EMPTY!\n"); return;}

    int count = 0;
    printf("Contents of Queue is:\n");
    for(int i = front; count < size; ++i)
    {
        printf("%c ",arr[i]);

        if(i == (cap_c-1))
            i = 0;
        ++count;
    }
}


int main()
{
    int exit_ = 0;
    do
    {
        printf("\n1.Insert ");
        printf("2.Delete ");
        printf("3.Display ");
        printf("4.exit \n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);

        while((getchar()) != '\n');

        switch (choice)
        {
        case 1:  insert();  break;
        case 2:  deque();  break;
        case 3:  display(); break;
        case 4:  exit_ = 1; break;
        default: printf("Enter correct choice!\n"); break;
        }

    } while (!exit_);
}