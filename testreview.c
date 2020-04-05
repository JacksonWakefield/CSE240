#include<stdio.h>

int main(){

    int ma[2][4], *p;

    p = &ma[0][0];

    *p = 5;
    *(p+2) = 10;

    printf("%s", p);
}