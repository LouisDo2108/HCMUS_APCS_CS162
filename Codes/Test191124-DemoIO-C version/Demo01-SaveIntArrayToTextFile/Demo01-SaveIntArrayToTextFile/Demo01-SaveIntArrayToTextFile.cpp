//
//  Demo01-SaveIntArrayToTextFile.cpp
//  Demo01-SaveIntArrayToTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include<stdio.h>

void inputIntArray(int a[], int &n);
void saveIntArray(FILE *f, int a[], int n);

int main(int argc, const char * argv[]) {
    int a[100];
    int n = 0;
    
    inputIntArray(a, n);
    
    FILE *f;
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo01-SaveIntArrayToTextFile/Demo01-SaveIntArrayToTextFile/intarray-output.txt", "wt");
    if(f == NULL){
        printf("Can not create file intarray-output.txt\n");
    }
    else{
        saveIntArray(f, a, n);
        fclose(f);
    }
    
    return 0;
}

void inputIntArray(int a[], int &n){
    printf("Number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("a[%d]: ");
        scanf("%d", &a[i]);
    }
}

void saveIntArray(FILE *f, int a[], int n){
    fprintf(f, "%d\n", n);
    for(int i = 0; i < n; i++){
        fprintf(f, "%d ", a[i]);
    }
}
