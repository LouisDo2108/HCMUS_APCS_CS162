//
//  Demo02-LoadIntArrayFromTextFile.cpp
//  Demo02-LoadIntArrayFromTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include<stdio.h>

void loadIntArray(FILE *f, int a[], int &n);
void printIntArray(int a[], int n);

int main(int argc, const char * argv[]) {
    FILE * f;
    int a[100];
    int n = 0;
    
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo02-LoadIntArrayFromTextFile/Demo02-LoadIntArrayFromTextFile/intarray-input.txt", "rt");
    if(f == NULL){
        printf("File does not exist\n");
    }
    else{
        loadIntArray(f, a, n);
        printIntArray(a, n);
        fclose(f);
    }
    return 0;
}

void loadIntArray(FILE *f, int a[], int &n){
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
    }
}

void printIntArray(int a[], int n){
    if(n == 0){
        printf("Empty array\n");
    }
    else{
        for(int i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
