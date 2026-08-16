#include <stdio.h>

int main() {
    int n, frames;
    int pages[100], memory[100], recent[100];
    int faults = 0;

    printf("Enter number of page references: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (int i = 0; i < frames; i++) {
        memory[i] = -1;
        recent[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int found = -1;

        for (int j = 0; j < frames; j++) {
            if (memory[j] == pages[i]) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            recent[found] = i;
        } else {
            int replace = -1;

            for (int j = 0; j < frames; j++) {
                if (memory[j] == -1) {
                    replace = j;
                    break;
                }
            }

            if (replace == -1) {
                replace = 0;

                for (int j = 1; j < frames; j++) {
                    if (recent[j] < recent[replace])
                        replace = j;
                }
            }

            memory[replace] = pages[i];
            recent[replace] = i;
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
