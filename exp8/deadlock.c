#include <stdio.h>

int main()
{
    int n, m;
    int alloc[10][10], request[10][10];
    int avail[10];
    int finish[10];
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

    printf("Enter Request Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    printf("Enter Available Resources:\n");

    for (j = 0; j < m; j++)
    {
        scanf("%d", &avail[j]);
    }

    /* Initialize finish array */
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    /* Deadlock Detection Algorithm */
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
                    if (request[i][j] > avail[j])
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

                    finish[i] = 1;
                    safe[count] = i;
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

    /* Check for deadlock */
    if (count == n)
    {
        printf("\nNo Deadlock Detected.\n");
    }
    else
    {
        printf("\nDeadlock Detected.\n");
        printf("Deadlocked Processes: ");

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                printf("P%d ", i);
            }
        }

        printf("\n");
    }

    return 0;
}
