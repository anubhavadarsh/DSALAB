#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* insert(struct node* root)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("-> ");
    scanf("%d",&temp->data);

    temp->left = temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        struct node* curr = root;
        struct node* prev;
        while(curr != NULL)
        {
            prev = curr;
            if(temp->data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(temp->data < prev->data)
            prev->left = temp;
        else
            prev->right = temp;
    }

    return root;
}

struct node* create(struct node* root)
{
    printf("Enter the number of nodes: ");
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
    {
        root = insert(root);
    }

    return root;
}

void search(struct node* root)
{
    printf("Enter a value to search: ");
    int item;
    scanf("%d",&item);

    struct node* curr = root;
    while(curr != NULL)
    {
        if(item == curr->data)
        {
            printf("item found!\n");
            return;
        }
        else
        {
            if(item < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    printf("item not found!\n");
}

void inorder(struct node* node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

void preorder(struct node* node)
{
    if(node != NULL)
    {
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(struct node* node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
    }
}


int main()
{
    struct node *root = NULL;  
    int exit_ = 0;
    do
    {
        printf("\n\n1. Create   2. Search   3. Preorder   4. Inorder  5. Postorder  6. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: root = create(root);   break;
            case 2: search(root);   break;
            case 3: preorder(root); break;
            case 4: inorder(root);  break;
            case 5: postorder(root);break;
            case 6: exit_ = 1;      break;
            default:
                printf("enter correct choice!");
        }
    } while (!exit_);

    return 0;
}