///reference http://en.cppreference.com/w/c/io/setbuf
///thanks to guesst on http://cboard.cprogramming.com/csharp-programming/101684-calculate-elapsed-seconds.html

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //for INT_MAX
#include <time.h> //for timer

#define BUFFERSIZE 3

void testPutcBuffered();


int main()
{

//    char buffer[BUFFERSIZE];
//    int c;
//    c = setvbuf(stdin, buffer, _IOFBF, BUFFERSIZE);
//    for (c = 0;c<100000;c++)
//    {
//        putchar('0');
//    }


    testPutcBuffered(10000000);




    return 0;
}


void testPutcBuffered(int times)
{
    time_t start, end;
    double dif;

    //get start time
    time (&start);

    //open the test file.
    FILE *fp;
    fp = fopen("Test.txt","w");
    if(fp == NULL)
    {
        printf("Test.txt couldnt open \non testPutcBuffered()");
        exit(1);
    }

    //allocate for buffer and assign it
    char buffer[BUFFERSIZE];
    if(setvbuf(fp, buffer, _IOFBF, BUFFERSIZE) != 0)
    {
        printf("setvbuf() error");
        exit(2);
    }

    //plainly put "times" times random character
    int c,i;
    for(i = 0;i<times;i++)
    {
        c = (rand()%26)+'A';
        putc(c,fp);
    }

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get stop time
    time (&end);

    //calculate the seconds between start and end times.
    dif = difftime (end,start);

    //print the result!?
    printf ("Putc() Test Buffered took %.2lf seconds to run for %d times.\n", dif,times);

}
