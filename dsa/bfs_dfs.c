#include <stdio.h>

int que[20], top = -1, front = -1, rear = -1;
int a[20][20], visit[20], stack[20];

int dequeue()
{
    int k;
    if ((front>rear)||(front == -1))
        return (0);
    else
    {
        k=que[front++];
        return (k);
    }
}
void enqueue(int item)
{
    if (rear==19)
        printf("OVERFLOW");
    else
    {
        if (rear==-1)
        {
            que[++rear]=item;
            front++;
        }
        else
            que[++rear]=item;
    }
}
void push(int item)
{
    stack[++top]=item;
}
int pop()
{
    int k;
    if (top==-1)
        return (-1);
    else
    {
        k=stack[top--];
        return (k);
    }
}
void bfs(int s, int n)
{
    int p, i;
    enqueue(s);
    visit[s]=1;
    p=dequeue();
    if (p!= 0)
        printf(" %d", p);
    while(p!=0)
    {
        for (i=1;i<=n;i++)
            if ((a[p][i]!=0)&&(visit[i]==0))
            {
                enqueue(i);
                visit[i]=1;
            }
        p=dequeue();
        if(p!=0)
            printf(" %d ", p);
    }
    for (i=1;i<=n;i++)
        if(visit[i]==0)
            bfs(i, n);
}
void dfs(int s,int n)
{
    int i, k;
    push(s);
    visit[s] = 1;
    k=pop();
    if (k!=-1)
        printf(" %d ", k);
    while (k!=-1)
    {
        for (i = 1;i<= n;i++)
            if ((a[k][i]!=0)&&(visit[i]==0))
            {
                push(i);
                visit[i]=1;
            }
        k=pop();
        if (k!=-1)
            printf(" %d ",k);
    }
    for (i=1;i<=n;i++)
        if (visit[i]==0)
            dfs(i, n);
}

int main()
{
    int n, i, s, ch=0, j;
    printf("Enter the no of vertices ");
    scanf("%d", &n);
    
    for (i=1;i<=n; i++)
    {
        for (j=1;j<=n;j++)
        {
            printf("Enter 1 if %d has a edge with %d else 0 ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("The adjacency matrix is\n");
    for (i=1;i<=n;i++)
    {
        for (j= 1;j<= n;j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    while (ch!=3)
    {
        for (i=1;i<=n;i++) 
        {
            visit[i] = 0;
        }
        printf("\nSELECT FROM THE FOLLOWING MENU");
        printf("\nPRESS 1 FOR BFS");
        printf("\nPRESS 2 FOR DFS");
        printf("\nPRESS 3 TO EXIT");
        scanf("%d", &ch);
        if (ch==1)
        {
            printf("ENTER THE STARTING VERTEX :");
            scanf("%d", &s);
            bfs(s, n);
        }
        else if(ch==2)
        {
            printf("ENTER THE STARTING VERTEX :");
            scanf("%d", &s);
            dfs(s, n);
        }
        else
            break;
    }
} 
