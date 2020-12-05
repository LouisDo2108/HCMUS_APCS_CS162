//
//  main.cpp
//  Demo07-SaveFractionArrayToTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <stdio.h>

struct Fraction{
    int num, denom;
};

void inputFraction(Fraction &p);
void saveFraction(FILE *f, Fraction p);

void inputFractionArray(Fraction a[], int &n);
void saveFractionArray(FILE *f, Fraction a[], int n);

int main(int argc, const char * argv[]) {
    Fraction a[100];
    int n = 0;
    FILE *f;
    
    inputFractionArray(a, n);
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo07-SaveFractionArrayToTextFile/Demo07-SaveFractionArrayToTextFile/fractionarray-output.txt", "wt");
    if(f == NULL){
        printf("Can not create file\n");
    }
    else{
        saveFractionArray(f, a, n);
        fclose(f);
    }
    return 0;
}

void inputFraction(Fraction &p){
    printf("Numerator: ");
    scanf("%d", &p.num);
    printf("Denominator: ");
    scanf("%d", &p.denom);
}
void saveFraction(FILE *f, Fraction p){
    fprintf(f, "%d %d\n", p.num, p.denom);
}
void inputFractionArray(Fraction a[], int &n){
    printf("Number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("a[%d]: \n");
        inputFraction(a[i]);
    }
}
void saveFractionArray(FILE *f, Fraction a[], int n){
    fprintf(f,"%d\n", n);
    for(int i = 0; i < n; i++){
        saveFraction(f, a[i]);
    }
}
