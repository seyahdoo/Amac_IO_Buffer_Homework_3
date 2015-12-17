///reference http://en.cppreference.com/w/c/io/setbuf
///thanks to KLee1 on http://stackoverflow.com/questions/3557221/how-do-i-measure-time-in-c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //for INT_MAX
#include <time.h> //for timer

#define BUFFERSIZE 1024

void testPutcBuffered(int);
void testPutcUnBuffered(int);
void testFputcBuffered(int);
void testFputcUnBuffered(int);

void testGetcBuffered(int);
void testGetcUnBuffered(int);

int main()
{
    testPutcBuffered(1000000);
    testPutcUnBuffered(1000000);

    testGetcBuffered(1000000);
    testGetcUnBuffered(1000000);

    testFputcBuffered(1000000);
    testFputcUnBuffered(1000000);

    return 0;
}


void testPutcBuffered(int times)
{
    //get start clock
    clock_t start = clock();

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

    //if there is a buffered output on stream flush it!
    fflush(fp);

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //print the result!?
    printf ("Putc() Test Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

void testPutcUnBuffered(int times)
{
    //get start clock
    clock_t start = clock();

    //open the test file.
    FILE *fp;
    fp = fopen("Test.txt","w");
    if(fp == NULL)
    {
        printf("Test.txt couldnt open \non testPutcBuffered()");
        exit(1);
    }

    //Set Null Buffer. (No Buffering on c runtime side)
    if(setvbuf(fp,NULL,_IONBF,0) != 0)
    {
        printf("setbuf() error");
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

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //print the result!?
    printf ("Putc() Test Un Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

void testFputcBuffered(int times)
{
    //get start clock
    clock_t start = clock();

    //open the test file.
    FILE *fp;
    fp = fopen("Test.txt","w");
    if(fp == NULL)
    {
        printf("Test.txt couldnt open \non testFputcBuffered()");
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
        fputc(c,fp);
    }

    //if there is a buffered output on stream flush it!
    fflush(fp);

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //print the result!?
    printf ("Fputc() Test Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

void testFputcUnBuffered(int times)
{
    //get start clock
    clock_t start = clock();

    //open the test file.
    FILE *fp;
    fp = fopen("Test.txt","w");
    if(fp == NULL)
    {
        printf("Test.txt couldnt open \non testFputcUnBuffered()");
        exit(1);
    }

    //allocate for buffer and assign it
    if(setvbuf(fp, NULL, _IONBF, 0) != 0)
    {
        printf("setvbuf() error");
        exit(2);
    }

    //plainly put "times" times random character
    int c,i;
    for(i = 0;i<times;i++)
    {
        c = (rand()%26)+'A';
        fputc(c,fp);
    }

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //print the result!?
    printf ("Fputc() Test Un Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

void testGetcBuffered(int times)
{
    //get start clock
    clock_t start = clock();

    //open the test file.
    FILE *fp;
    fp = fopen("Test.txt","r");
    if(fp == NULL)
    {
        printf("Test.txt couldnt open \non testGetcBuffered()");
        exit(1);
    }

    //allocate for buffer and assign it
    char buffer[BUFFERSIZE];
    if(setvbuf(fp, buffer, _IOFBF, BUFFERSIZE) != 0)
    {
        printf("setvbuf() error");
        exit(2);
    }

    //allocate memory to store from file
    char *RamStorage;
    RamStorage = malloc(times*sizeof(char));
    if(RamStorage == NULL)
    {
        printf("We dont have enough memory for RamStorage on testGetcBuffered()\n exiting!");
        printf("%d",times);
        exit(3);
    }

    //get the RamStorage data from drive
    int i;
    for(i = 0;i<times;i++)
    {
        RamStorage[i] = getc(fp);
    }

    //if there is a buffered output on stream flush it!
    fflush(fp);

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //print the result!?
    printf ("Getc() Test Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

void testGetcUnBuffered(int times)
{
    //get start clock
    clock_t start = clock();

    //open the test file.
    FILE *fp;
    fp = fopen("Test.txt","r");
    if(fp == NULL)
    {
        printf("Test.txt couldnt open \non testGetcUnBuffered()");
        exit(1);
    }

    //set buffer null
    if(setvbuf(fp, NULL, _IONBF, 0) != 0)
    {
        printf("setvbuf() error");
        exit(2);
    }

    //allocate memory to store from file
    char *RamStorage;
    RamStorage = malloc(times*sizeof(char));
    if(RamStorage == NULL)
    {
        printf("We dont have enough memory for RamStorage on testGetcBuffered()\n exiting!");
        printf("%d",times);
        exit(3);
    }

    //get the RamStorage data from drive
    int i;
    for(i = 0;i<times;i++)
    {
        RamStorage[i] = getc(fp);
    }

    //if there is a buffered output on stream flush it!
    fflush(fp);

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //print the result!?
    printf ("Getc() Test Un Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}
