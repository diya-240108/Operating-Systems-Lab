#include <stdio.h>

int main() {
    int pageSize, numPages;
    int pageTable[100];
    int logicalAddress;
    int pageNumber, offset;
    int frameNumber, physicalAddress;

    printf("Enter Page Size: ");
    scanf("%d", &pageSize);

    printf("Enter Number of Pages: ");
    scanf("%d", &numPages);

    for (int i = 0; i < numPages; i++) {
        printf("Enter Frame Number for Page %d: ", i);
        scanf("%d", &pageTable[i]);
    }

    printf("Enter Logical Address: ");
    scanf("%d", &logicalAddress);

    pageNumber = logicalAddress / pageSize;
    offset = logicalAddress % pageSize;

    if (pageNumber >= numPages) {
        printf("Invalid Logical Address\n");
        return 0;
    }

    frameNumber = pageTable[pageNumber];

    physicalAddress = frameNumber * pageSize + offset;

    printf("Page Number      : %d\n", pageNumber);
    printf("Offset           : %d\n", offset);
    printf("Frame Number     : %d\n", frameNumber);
    printf("Physical Address : %d\n", physicalAddress);

    return 0;
}
