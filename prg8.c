#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insertRear();
void createNode();
void display();

struct node
{
    char name[300], dept[20], desig[15], phno[10];
    int ssn, sal;

    struct node *next;
    struct node *prev;
};

struct node *front = NULL, *temp = NULL;

void removeTrailingNewLine(char *str)
{
    if(str == NULL)
        return;

    int length = strlen(str);
    if(str[length-1] == '\n')
    {
        str[length-1] = '\0';
    }
}

void createNode()
{
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter name: ");
    fgets(temp->name, sizeof(temp->name), stdin);           removeTrailingNewLine(temp->name);

    printf("Enter department: ");
    fgets(temp->dept, sizeof(temp->dept), stdin);           removeTrailingNewLine(temp->dept);

    printf("Enter designation: ");
    fgets(temp->desig, sizeof(temp->desig), stdin);         removeTrailingNewLine(temp->desig);

    printf("Enter phone number: ");
    fgets(temp->phno, sizeof(temp->phno), stdin);           while(getchar() != '\n');

    printf("Enter ssn: ");
    scanf("%d",&temp->ssn);

    printf("Enter salary: ");
    scanf("%d",&temp->sal);                                 while(getchar() != '\n');

    temp->next = temp->prev = NULL;
}

void create()
{
    printf("Enter the number of employees: ");
    int n;
    scanf("%d",&n);     while(getchar() != '\n');

    for(int i = 0; i < n; ++i)
    {
        insertRear();
        printf("\n");
    }
}

void insertFront()
{
    createNode();
    if(front == NULL) { front = temp; return;}

    temp->next = front;
    front->prev = temp;
    front = temp;
}

void insertRear()
{
    createNode();
    if(front == NULL) { front = temp; return;}

    struct node *curr = front;
    while(curr->next != NULL)
        curr = curr->next;
    
    curr->next = temp;
    temp->prev = curr;
}

void insert()
{
    printf("\n1. InsertRear     2. InsertFront\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d",&choice);    while(getchar() != '\n');

    choice == 1?insertRear():insertFront();
}

void deleteFront()
{
    if(front == NULL)  { printf("List empty!"); return;}

    else if(front->next == NULL)
    {
        free(front);
        front = NULL;
    }

    else
    {
        struct node *curr = front;
        front = front->next;
        front->prev = NULL;
        free(curr);

        display();
    }
}

void deleteRear()
{
    if(front == NULL)  { printf("List empty!"); return;}

    else if(front->next == NULL)
    {
        free(front);
        front = NULL;
    }

    else
    {
        struct node *curr = front;
        while((curr->next)->next != NULL)
            curr = curr->next;
        
        struct node *last = curr->next;
        curr->next = NULL;
        free(last);

        display();
    } 
}

void delete()
{
    printf("\n1. DeleteRear     2. DeleteFront\n");
    printf("Enter choice: ");
    int choice;
    scanf("%d",&choice);    while(getchar() != '\n');

    choice == 1?deleteRear():deleteFront();
}

void display()
{
    if(front == NULL)   { printf("list empty!");    return;}

    struct node *curr = front;
    int count  = 1;
    while(curr != NULL)
    {
        printf("%d. %d  %s  %s  %s  %s  %d\n",count++,curr->ssn,curr->name,curr->dept,curr->desig,curr->phno,curr->sal);
        curr = curr->next;
    }
}

int main()
{
    int exit_ = 0;
    do
    {
        printf("\n\n1. Create   2. Insert   3. Delete   4. Display  5. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d",&choice);    while(getchar() != '\n');

        switch(choice)
        {
            case 1: create();   break;
            case 2: insert();   break;
            case 3: delete();   break;
            case 4: display();  break;
            case 5: exit_ = 0;  break;
            default:
                printf("Enter correct choice!");
        }
    } while (!exit_);
    
    return 0;
}