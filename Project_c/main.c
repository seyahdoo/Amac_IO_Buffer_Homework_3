/**
@file
Prog_Lang autumn2015 assignment3.
A program that tests buffers. on getc Fgetc Putc and Fputc.
@author
Name: Seyyid Ahmed Doðan
Student no: 14011038
Date: 17/12/2015
E-Mail: seyyidahmed.dogann@gmail.com
Compiler used: GCC
IDE: Code::Blocks 13.12
Operating System Windows 10
*/

///you can find this project on github
///https://github.com/seyahdoo/Amac_IO_Buffer_Homework_3

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
void testFgetcBuffered(int);
void testFgetcUnBuffered(int);

void testBufferThing(int);

void getch(void);

int main()
{
    printf("\nPress Any Key to Initiate Buffer Test");
    getch();

    testBufferThing(100000);
    testBufferThing(1000000);
    testBufferThing(10000000);

    printf("\nTest Ended!");
    printf("\nPress Any Key to Exit");
    getch();
    return 0;
}

void testBufferThing(int Amount)
{
    printf("\n");
    testPutcBuffered(Amount);
    testPutcUnBuffered(Amount);
    printf("\n");

    testGetcBuffered(Amount);
    testGetcUnBuffered(Amount);
    printf("\n");

    testFputcBuffered(Amount);
    testFputcUnBuffered(Amount);
    printf("\n");

    testFgetcBuffered(Amount);
    testFgetcUnBuffered(Amount);
    printf("\n");
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

    //Release the memory so there wont be any Memory Leaks
    free(RamStorage);

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

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //Release the memory so there wont be any Memory Leaks
    free(RamStorage);

    //print the result!?
    printf ("Getc() Test Un Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

void testFgetcBuffered(int times)
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
        RamStorage[i] = fgetc(fp);
    }

    //if there is a buffered input on stream flush it!
    fflush(fp);

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //Release the memory so there wont be any Memory Leaks
    free(RamStorage);

    //print the result!?
    printf ("Fgetc() Test Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

void testFgetcUnBuffered(int times)
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

    //set buffer to NULL
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
        RamStorage[i] = fgetc(fp);
    }

    //dont forget to close the file after you are done with it.
    fclose(fp);

    //get end clock
    clock_t end = clock();

    //calculate the seconds between start and end times.
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;

    //Release the memory so there wont be any Memory Leaks
    free(RamStorage);

    //print the result!?
    printf ("Fgetc() Test Un Buffered took %2.10f seconds to run for %d times.\n", seconds,times);
}

