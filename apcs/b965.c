#include <stdio.h>

int arr[100][100];

void print(int r, int c);
void reverse(int r, int c);

int main(void)
{
    int r,c,m, acc[100];
    scanf("%d%d%d", &r, &c, &m);
    int i,j;
    for (i = 0; i<r; ++i)
        for (j = 0; j<c; ++j)
            scanf("%d", &arr[i][j]);
    for (i = 0; i<m; ++i)
        scanf("%d", &acc[m-i-1]);

    reverse(r, c); // reverse
    print(r,c);
    return 0;
}

void reverse(int r, int c)
{
    int i,j;
}

void print(int r, int c)
{
    int i,j;
    for (i = 0; i<r; ++i)
        for (j = 0; j<c; ++j)
        {
            if (j < c-1)printf("%d ", arr[i][j]);
            else printf("%d\n", arr[i][j]);
        }
    return;
}