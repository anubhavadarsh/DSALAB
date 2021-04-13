#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    char usn[11], name[30], branch[5], phno[11];
    int sem;
    struct node *next;
};

struct node *front = NULL, *temp = NULL;

void display();
void insertRear();

void removeStringTrailingNewline(char *str) 
{
    if (str == NULL)
        return;
    int length = strlen(str);
    if (str[length-1] == '\n')
        str[length-1]  = '\0';
}

void createNode()
{
    temp = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter usn:          ");
    fgets(temp->usn, sizeof(temp->usn), stdin);         while(getchar() != '\n');

    printf("Enter name:         ");
    fgets(temp->name, sizeof(temp->name), stdin);       removeStringTrailingNewline(temp->name);

    printf("Enter branch:       ");
    fgets(temp->branch, sizeof(temp->branch), stdin);   removeStringTrailingNewline(temp->branch);

    printf("Enter phone number: ");
    fgets(temp->phno, sizeof(temp->phno), stdin);       while(getchar() != '\n');

    printf("Enter sem:          ");
    scanf("%d",&temp->sem);                             while(getchar() != '\n');
    
    temp->next = NULL;
}

void create()
{
    printf("Enter the size of records: ");
    int n;
    scanf("%d",&n); while(getchar() != '\n');

    for(int i = 0; i < n; ++i)
    {
        insertRear();
        printf("\n");
    }
}

void insertFront()
{
    createNode();
    if(!front)
        front = temp;
    else
    {
        temp->next = front;
        front = temp;
    }
}

void insertRear()
{
    createNode();
    if(!front)
        front = temp;
    else
    {
        struct node *curr = front;
        while(curr->next != NULL)
            curr = curr->next;
        
        curr->next = temp;
    }
}

void deleteFront()
{
    if(!front)
    {
        printf("List empty!"); return;
    }
    else if(front->next == NULL)
    {
        free(front);
        front = NULL;
    }
    else
    {
        struct node* curr = front;
        front = front->next;
        free(curr);

        display();
    }
}

void deleteRear()
{
    if(!front)
    {
        printf("List empty!"); return;
    }
    else if(front->next == NULL)
    {
        free(front);
        front = NULL;
    }
    else
    {
        struct node* curr = front;
        while((curr->next)->next != NULL)
            curr = curr->next;

        struct node* last = curr->next;
        curr->next = NULL;
        free(last);

        display();
    }
}

void display()
{
    if(!front)
    {
        printf("List empty!"); return;
    }

    struct node *curr = front;
    int count = 1;
    printf("slno.       usn            name              branch        phno        sem\n");
    while(curr != NULL)
    {
        printf("%d.      %s     %s          %s      %s      %d\n",count++,curr->usn, curr->name, curr->branch, curr->phno, curr->sem);
        curr = curr->next;
    }
}

int main()
{
    int exit_ = 0;
    do
    {
        printf("\n\n1. Create   2. Insert_front   3. Insert_rear   4. Delete_front   5. Delete_rear   6. Display    7. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d",&choice);

        while(getchar() != '\n');

        switch(choice)
        {
            case 1: create();       break;
            case 2: insertFront();  break;
            case 3: insertRear();   break;
            case 4: deleteFront();  break;
            case 5: deleteRear();   break;
            case 6: display();      break;
            case 7: exit_ = 1;      break;
            default:
                printf("Enter correct choice!");
        }


    } while (!exit_);
    

    return 0;
}