#include <fcntl.h>
#include "tlpi_hdr.h"

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int fd, outputFd, openFlags;
    ssize_t numRead;
    off_t pos;
    char buf[BUF_SIZE];

    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s old-file new-file\n", argv[0]);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        errExit("opening file %s", argv[1]);

    read(fd, buf, 20);

    pos = lseek(fd, 0, SEEK_CUR);
    printf("Current offset of lseek: %ld\n", pos);

    printf("try invalid offset and check error code: \n");
    lseek(fd, 0, SEEK_SET);

    if (lseek(fd, -5, SEEK_CUR) == -1)
        errExit("seeking to before the beginning of file %s\n", argv[1]);
}