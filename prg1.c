#include <stdio.h>
#include <stdlib.h>

//global variables;
int arr[100], size_arr;


void create()
{
    printf("\nEnter the size of array: ");
    scanf("%d",&size_arr);

    printf("\nEnter the elements:\n");

    for(int i = 0; i < size_arr; ++i)
    {
        int elem;
        scanf("%d",&elem);
        arr[i] = elem;
    }
}

void display()
{
    printf("\nElements in the array are: \n");

    for(int i = 0; i < size_arr; ++i)
    {
        printf("%d ",arr[i]);
    }
}

void insert()
{  
    printf("\nEnter a element to be inserted: ");
    int elem;
    scanf("%d",&elem);

    printf("\nEnter position: ");
    int pos;
    scanf("%d",&pos);

    if(pos == size_arr)
    {
        arr[pos] = elem;
        ++size_arr;
    }
    else
    {
        for(int i = size_arr-1; i >= pos; --i)
        {
            arr[i+1] = arr[i];
        }
        arr[pos] = elem;
        ++size_arr;
    }
}

void delete()
{
    printf("\nEnter the position of element to be deleted: ");
    int pos;
    scanf("%d",&pos);

    for(int i = pos; i < size_arr; ++i)
    {
        arr[pos] = arr[pos+1];
    }
    --size_arr;
}

int main()
{
    int exit_ = 0;
    do
    {
        printf("\n\n------MENU------\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");

        printf("Enter your choice: ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            create(); break;
        case 2:
            display();break;
        case 3:
            insert(); break;
        case 4:
            delete(); break;
        case 5:
            exit_ = 1;break;
        default:
            printf("\nEnter correct choice!\n");break;
        }
    } while (!exit_);
    
    return 0;
}