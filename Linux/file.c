#include "stdio.h"
#include <stdio.h>


int main()

{   
    int num = 42;
    int *p;        // 声明一个指向整型的指针
    p = &num;
    
    printf("The new value of num is: %d\n", num);

    printf("The new value of num through pointer p is: %d\n", *p);

    FILE *file = fopen("example.txt", "w");
    if(file != NULL)
    {   

        fprintf(file,"Hello World");
        
        fclose(file);
    }


}