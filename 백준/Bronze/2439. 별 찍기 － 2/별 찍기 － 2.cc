#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int t,a,b;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        for (int k = 1; k <= t-i; k++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}