#include <fcntl.h>
#include <sys/stat.h>
#include "tlpi_hdr.h"

#define MAX_BUF 1024

int main(int argc, char *argv[])
{
    int fd, opt;
    ssize_t numRead, numWritten;
    char buf[MAX_BUF];

    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        usageErr("%s file \n", argv[0]);

    opt = getopt(argc, argv, "a");

    if (opt == 'a') /* append */
        fd = open(argv[optind], O_RDWR | O_CREAT | O_APPEND,
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    else /* overwrite */
        fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC,
                  S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    while (numRead != 0)
    {
        /* read from stdin */
        numRead = read(STDIN_FILENO, buf, MAX_BUF);
        if (numRead == -1)
            err_exit("read");

        /* write to stdout */
        numWritten = write(STDOUT_FILENO, buf, numRead);
        if (numWritten == -1)
            err_exit("write to stdout");

        /* write to file */
        numWritten = write(fd, buf, numRead);
        if (numWritten == -1)
            err_exit("write to file");
    }

    exit(EXIT_SUCCESS);
}