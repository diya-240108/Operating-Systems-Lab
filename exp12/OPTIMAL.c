#include <stdio.h>

int main() {
    int n, frames;
    int pages[100], memory[100];
    int faults = 0;

    printf("Enter number of page references: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (int i = 0; i < frames; i++)
        memory[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replace = -1;

            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    replace = j;
                    break;
                }
            }

            if (replace == -1) {
                int farthest = -1;

                for (int j = 0; j < frames; j++) {
                    int next = n;

                    for (int k = i + 1; k < n; k++) {
                        if (memory[j] == pages[k]) {
                            next = k;
                            break;
                        }
                    }

                    if (next > farthest) {
                        farthest = next;
                        replace = j;
                    }
                }
            }

            memory[replace] = pages[i];
            faults++;
        }

        printf("Page %d: ", pages[i]);

        for (int j = 0; j < frames; j++)
            printf("%d ", memory[j]);

        printf("\n");
    }

    printf("Total Page Faults: %d\n", faults);

    return 0;
}
