/* This is only a example program to demonstrate the different memory segment of a prcess
this program should not be considerd as any use case */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function declaration */
int add_num(int num1, int num2);

int g_var = 20; // initialised data segemnt
int g_flag; // un-initialised data segment

// This code will be stored in Text segment as read only memory
void main(void){

    int num1, num2, sum; // stack frame of 'main' function - stack segment
    char *pstr; // pstr is part of stack frame of main()
    char *buf = "welcome"; // "welcome" string is stored in text segment, where as variable pointer buf is stored in stack frame of main
    char stack_buf[20] = {"stackData"}; // stack_buf is stored on stack frame and it contains value "stackData"

    // buf[0] = 'n'; // This will cause segmentation fault, as buf[0] tries to write to text segment, which is read only
    strcpy(stack_buf, "newString"); // possible as it is stored on stack

    num1 = 10; // 10 is stored on stack 
    num2 = 20; // 20 is stored on stack
    sum = add_num(num1, num2); // value of sum is stored on stack
    printf("\n the result of add is (%d) \n", sum);

    num1 = 100;
    num2 = 200;
    sum = add_num(num1, num2);
    printf("\n the result of add is (%d) \n", sum);

    pstr = malloc(20); // Heap segment, pstr points to 20 bytes on Heap, but location of pstr itsefl is part of stack frame of 'main()'
    strcpy(pstr, "Hello");
    printf("\n string stored is (%s) \n", pstr);


}