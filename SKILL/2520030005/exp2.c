#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int source, destination;
    char buffer[1024];
    ssize_t bytesRead;

    // Open source file for reading
    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file for writing
    destination = open("destination.txt",
                       O_WRONLY | O_CREAT | O_TRUNC,
                       0644);

    if (destination < 0)
    {
        perror("Error opening destination file");
        close(source);
        return 1;
    }

    // Read from source and write to destination
    while ((bytesRead = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytesRead);
    }

    // Close both files
    close(source);
    close(destination);

    printf("File copied successfully.\n");

    return 0;
}
