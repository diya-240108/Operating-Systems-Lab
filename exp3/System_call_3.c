#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("sample.txt", O_RDONLY);

    if (fd < 0)
    {
        printf("File Opening Failed\n");
        return 1;
    }

    printf("File Opened Successfully\n");

    close(fd);

    printf("File Closed Successfully\n");

    return 0;
}
