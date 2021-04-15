#include <stdio.h>
#include <stdlib.h>

int a[10][10], visited[10], vis[10];
int n, count;

void create()
{
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            scanf("%d",&a[i][j]);
            visited[i] = 0;
            vis[i] = 0;
        }
    } 
}

void bfs()
{
    int queue[10], front = 0, rear = -1;

    printf("Enter a source vertix: ");
    int source;
    scanf("%d",&source);

    queue[++rear] = source;
    visited[source] = 1;

    printf("The adjacent vertices are: ");
    while(front <= rear)
    {
        int u = queue[front++];
        for(int i = 0; i < n; ++i)
        {
            if(a[u][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
                printf("%d ",i);
            }
        }
    }
    printf("\n");
}

void dfs(int source)
{
    vis[source] = 1;
    for(int i = 0; i < n; ++i)
    {
        if(a[source][i] == 1 && vis[i] == 0)
        {
            ++count;
            dfs(i);
        }
    }
}

int main()
{
    int exit_ = 0;
    do
    {
        printf("\n\n1. Create   2. BFS   3. DFS   4. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: bfs();    break;
            case 3: count = 1;
                    for(int i = 0; i < n; ++i)
                    {
                        if(vis[i] == 0)
                            dfs(i);
                    }
                    if(count == n)
                    {
                        printf("graph is connected!");
                    }
                    else
                    {
                        printf("graph is not connected!");
                    }
                    break;
            case 4: exit_ = 1; break;
            default:
                printf("Enter correct choice!");
        }
    } while (!exit_);
    
    return 0;
}