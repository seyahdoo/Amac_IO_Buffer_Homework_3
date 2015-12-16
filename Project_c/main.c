///reference http://en.cppreference.com/w/c/io/setbuf

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //for INT_MAX

#define BUFFERSIZE 3

int main()
{

    char buffer[BUFFERSIZE];
    int c;
    //c = setvbuf(stdin, buffer, _IOFBF, BUFFERSIZE);
    for (c = 0;c<30000;c++)
    {
        putchar('0');
    }




    printf("Hello world!\n");
    return 0;
}
