#include <stdio.h>
#include <string.h>

void towerOfHanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        printf("Move disc %d from %c to %c.\n",n,A,C);
        return;
    }
    towerOfHanoi(n-1,A,C,B);
    printf("Move disc %d from %c to %c.\n",n,A,C);
    towerOfHanoi(n-1,B,A,C);
}


int main()
{
    printf("Enter the number of disc: ");
    int n;
    scanf("%d",&n);

    towerOfHanoi(n,'A','B','C');

    return 0;
}