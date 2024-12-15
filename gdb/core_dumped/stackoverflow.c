#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(char *argv[]){
    float k;
    printf("this is consumer\n");
    k=(float)sqrt(atoi(argv[1]));
    printf("%s\n",k);
    return 0;
}

// https://stackoverflow.com/questions/19641597/what-is-segmentation-fault-core-dumped
