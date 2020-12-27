
#include <stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push();
void pop();
void palindrome();
void display();

void main()
{
    int key;
    while(1)
    
    {
        
    printf("------------STACK OPERATION----------\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\n");
    printf("\nEnter your choice\n");
    scanf("%d",&key);
    switch(key)
    {
        case 1:push();
        break;
         case 2:pop();
        break;
         case 3:display();
        break;
         case 4:palindrome();
        break;
         case 5:return;
        default:printf("Invalid choice\n");
        
    }
    
}
    
}

void push(){
    int item;
    if(top==(MAX-1)){
        printf("Stack Overlow\n");
    }
    else{
        printf("Enter the element to be pushed\n");
        scanf("%d",&item);
               ++top;
        stack[top] = item;
        
    }
}

void display(){
    int i ;
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        printf("The element in stack is\n ");
        for(i=top;i>=0;i--)printf("stack[%d]:%d\n",i,stack[i]);
       }
}

void pop(){
    int item ;
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
         int item = stack[top];
        --top;
        printf("The element that is being poped %d\n",item);
        
        
    }
}

void palindrome(){
  
  int i,count=0;
  for(i=0;i<=top/2;i++){
      if(stack[i]=stack[top-i])
          {
          count++;
          }
      };
      if((top/2+1)==count){
          printf("Stack content is palindrome\n");
          
      }
          
          else{
              printf("stack content is not palindrome\n");
          };
          
      };

