#include <stdio.h>

int main() {
    int n, m;
    int block[100], process[100];

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);

    printf("Enter block sizes:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &m);

    printf("Enter process sizes:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &process[i]);

    for (int i = 0; i < m; i++) {
        int worst = -1;

        for (int j = 0; j < n; j++) {
            if (block[j] >= process[i]) {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            printf("Process %d allocated to Block %d\n",
                   i + 1, worst + 1);

            block[worst] -= process[i];
        } else {
            printf("Process %d cannot be allocated\n", i + 1);
        }
    }

    return 0;
}
