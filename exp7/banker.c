#include <stdio.h>

int main()
{
    int n, m;
    int alloc[10][10], max[10][10];
    int avail[10], need[10][10];
    int finish[10] = {0};
    int safe[10];
    int i, j, k;
    int count = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    /* Calculate Need Matrix */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    /* Banker's Algorithm */
    while (count < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int possible = 1;

                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if (possible)
                {
                    for (j = 0; j < m; j++)
                    {
                        avail[j] += alloc[i][j];
                    }

                    safe[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            break;
        }
    }

    if (count == n)
    {
        printf("\nSystem is in SAFE state.\n");

        printf("Safe Sequence: ");

        for (i = 0; i < n; i++)
        {
            printf("P%d", safe[i]);

            if (i != n - 1)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is NOT in a safe state.\n");
    }

    return 0;
}
