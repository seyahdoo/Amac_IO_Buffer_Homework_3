///reference http://en.cppreference.com/w/c/io/setbuf

#include <stdio.h>
#include <stdlib.h>

#define BUFFERSIZE 3

int main()
{

    char buffer[BUFFERSIZE];
    int c;
    //c = setvbuf(stdin, buffer, _IOFBF, BUFFERSIZE);

    printf("%d",c);
    putchar('b');
    putchar('c');
    putchar('d');
    putchar('e');
    putchar('f');
    putchar('g');
    for (c = 0;c<2000;c++)
    {
        putchar(' ');
    }




    printf("Hello world!\n");
    return 0;
}
