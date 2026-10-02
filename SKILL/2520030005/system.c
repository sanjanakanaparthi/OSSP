#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd;

    // Open the file in read-only mode
    fd = open("input.txt", O_RDONLY);

    // Check whether the file was opened successfully
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }

    printf("File opened successfully.\n");
    printf("File descriptor: %d\n", fd);

    // Close the file
    close(fd);

    return 0;
}

