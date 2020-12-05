//
//  Demo08-LoadFractionArrayFromTextFile.cpp
//  Demo08-LoadFractionArrayFromTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <stdio.h>

struct Fraction{
    int num, denom;
};

void loadFraction(FILE *f, Fraction &p);
void printFraction(Fraction p);
void loadFractionArray(FILE *f, Fraction a[], int &n);
void printFractionArray(Fraction a[], int n);

int main(int argc, const char * argv[]) {
    Fraction a[100];
    int n = 0;
    FILE *f;
    
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO/Demo08-LoadFractionArrayFromTextFile/Demo08-LoadFractionArrayFromTextFile/fractionarray-input.txt", "rt");
    
    if(f == NULL){
        printf("Can not open file\n");
    }
    else{
        loadFractionArray(f, a, n);
        printFractionArray(a, n);
        fclose(f);
    }
    return 0;
}

void loadFraction(FILE *f, Fraction &p){
    fscanf(f, "%d", &p.num);
    fscanf(f, "%d", &p.denom);
}
void printFraction(Fraction p){
    printf("%d/%d\n", p.num, p.denom);
}
void loadFractionArray(FILE *f, Fraction a[], int &n){
    fscanf(f, "%d", &n);
    for(int i = 0; i < n; i++){
        loadFraction(f, a[i]);
    }
}
void printFractionArray(Fraction a[], int n){
    printf("Number of elements: %d\n", n);
    for(int i = 0; i < n; i++){
        printf("a[%d]: ", i);
        printFraction(a[i]);
    }
}
