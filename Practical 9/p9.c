#include <stdio.h>

#define MAX 10
#define INF 999

int main()
{
    int cost[MAX][MAX], visited[MAX] = {0};
    int n, i, j, min, a, b, total = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nMinimum Spanning Tree:\n");

    while (edges < n - 1)
    {
        min = INF;

        for (i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (min == INF)
        {
            printf("MST not possible. Graph is disconnected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", a + 1, b + 1, min);

        total += min;
        visited[b] = 1;
        edges++;
    }

    printf("Total cost = %d\n", total);

    return 0;
}
