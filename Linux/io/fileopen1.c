#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


int main()
{   
    int fd;
    fd = open("test.txt",O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr,"open errorwith errno =%d\n",errno);
        exit(EXIT_FAILURE);
    }
    printf("OPEN SUCC \n");
    return 0;
}

