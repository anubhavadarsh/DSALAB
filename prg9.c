#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int co, ex, ey, ez;
    int flag;
    struct node *next;
};

struct node* createNode()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter the coefficient: ");
    scanf("%d",&temp->co);

    printf("Enter the exponent for x: ");
    scanf("%d",&temp->ex);

    printf("Enter the exponent for y: ");
    scanf("%d",&temp->ey);

    printf("Enter the exponent for z: ");
    scanf("%d",&temp->ez);

    temp->flag = 0;
    temp->next = temp;

    return temp;
}

struct node* insertBack(struct node* poly)
{
    struct node* temp = createNode();

    if(poly == NULL)
    {
        poly = temp;
        return poly;
    }

    struct node* curr = poly;
    while(curr->next != poly)
    {
        curr = curr->next;
    }
    
    temp->next = curr->next;
    curr->next = temp;

    return poly;
}

struct node* createPoly(struct node* poly)
{
    printf("Enter the number of terms for polynomial: ");
    int terms;
    scanf("%d",&terms);

    for(int i = 0; i < terms; ++i)
    {
        poly = insertBack(poly);
        printf("\n");
    }

    return poly;
}

void evaluatePoly(struct node* poly)
{
    if(poly == NULL) { printf("polynomial doesn't exists!"); return;}

    printf("x: ");
    int x;
    scanf("%d",&x);

    printf("y: ");
    int y;
    scanf("%d",&y);

    printf("z: ");
    int z;
    scanf("%d",&z);

    struct node* curr = poly->next;
    int val = (poly->co)*(pow(x,poly->ex)*pow(y,poly->ey)*pow(z,poly->ez));

    while(curr != poly)
    {
        val += (curr->co)*(pow(x,curr->ex)*pow(y,curr->ey)*pow(z,curr->ez));
        curr = curr->next;
    }

    printf("A(%d,%d,%d) = %d\n",x,y,z,val);
}

void evaluate(struct node* poly1, struct node* poly2)
{
    printf("1. f(x,y,z)     2. g(x,y,z)\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);

    choice == 1?evaluatePoly(poly1):evaluatePoly(poly2);
}

struct node* createForAddPoly(struct node* poly,int co, int ex, int ey, int ez)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->co = co;
    temp->ex = ex;
    temp->ey = ey;
    temp->ez = ez;
    temp->flag = 0;
    temp->next = temp;

    if(poly == NULL)
    {
        poly = temp;
        return poly;
    }
    else
    {
        struct node* curr = poly;
        while(curr->next != poly)
            curr = curr->next;
        
        temp->next = curr->next;
        curr->next = temp;

        return poly;
    }
}

void addPoly(struct node *poly1, struct node *poly2)
{
    struct node *finalpoly = NULL;

    struct node *curr  = poly1;
    struct node *curr2 = poly2;

    int flag = 0;
    do
    {
        curr2 = poly2;
        flag = 0;
        do
        {
            if(curr->ex == curr2->ex && curr->ey == curr2->ey && curr->ez == curr2->ez)
            {
                int co = curr->co + curr2->co;
                finalpoly = createForAddPoly(finalpoly, co, curr->ex, curr->ey, curr->ez);
                curr2->flag = 1;
                flag = 1;
                break;
            }
            curr2 = curr2->next;
        } while (curr2 != poly2);
        if(flag == 0)
        {
            finalpoly = createForAddPoly(finalpoly, curr->co,curr->ex, curr->ey, curr->ez);
        }
        curr = curr->next;
    }while(curr != poly1);

    do
    {
        if(curr2->flag == 0)
        {
            finalpoly = createForAddPoly(finalpoly, curr2->co, curr2->ex, curr2->ey, curr2->ez);
        }
        curr2 = curr2->next;
    } while (curr2 != poly2);
    
    struct node *trav = finalpoly;
    do
    {
        printf("%dx^%dy^%dz^%d ",trav->co, trav->ex, trav->ey, trav->ez);
        trav = trav->next;
    }while(trav != finalpoly);
    printf("\n");
}

void displayPoly(struct node *poly)
{
    printf("polynomial: ");
    struct node *curr = poly;
    do
    {
        printf("%dx^%dy^%dz^%d ",curr->co, curr->ex, curr->ey, curr->ez);
        curr = curr->next;
    } while (curr != poly);
    printf("\n");
}

void display(struct node* poly1, struct node* poly2)
{
    printf("1. f(x,y,z)     2. g(x,y,z)\n");
    int choice;
    printf("Enter choice: ");
    scanf("%d",&choice);

    choice == 1?displayPoly(poly1):displayPoly(poly2);
}

int main()
{
    struct node *poly1 = NULL, *poly2 = NULL;
    printf("create polynomials: \n");

    printf("f(x,y,z) : \n");
    poly1 = createPoly(poly1);

    printf("g(x,y,z) : \n");
    poly2 = createPoly(poly2);

    int exit_ = 0;
    do
    {
        printf("\n\n1. Evaluate     2. Add two polynomials      3. display polynomial       4. exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: evaluate(poly1, poly2);     break;
            case 2: addPoly(poly1, poly2);      break;
            case 3: display(poly1, poly2);      break;
            case 4: exit_ = 1;                  break;
            default:
                printf("Enter correct choice!\n");
        }
    } while (!exit_);
    
    return 0;
}