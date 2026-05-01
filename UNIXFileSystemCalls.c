#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd;
    char data[]="Hello OS Lab";

    fd = open("file.txt", O_CREAT|O_WRONLY, 0644);
    write(fd, data, sizeof(data));

    close(fd);

    fd = open("file.txt", O_RDONLY);
    char buffer[50];
    read(fd, buffer, sizeof(buffer));

    printf("File content: %s\n", buffer);

    close(fd);
    return 0;
}
