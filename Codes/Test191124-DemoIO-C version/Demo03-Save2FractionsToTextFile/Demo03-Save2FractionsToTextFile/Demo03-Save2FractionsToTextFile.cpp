//
//  Demo03-Save2FractionsToTextFile.cpp
//  Demo03-Save2FractionsToTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include<stdio.h>

struct Fraction{
    int num, denom;
};

void inputFraction(Fraction &p);
void saveFraction(FILE *f, Fraction p);

int main(int argc, const char * argv[]) {
    Fraction a, b;
    FILE *f;
    
    printf("Fraction 1: \n");
    inputFraction(a);
    printf("Fraction 2: \n");
    inputFraction(b);
    
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo03-Save2FractionsToTextFile/Demo03-Save2FractionsToTextFile/2fractions-output.txt", "wt");
    if(f == NULL){
        printf("Can not create file\n");
    }
    else{
        saveFraction(f, a);
        saveFraction(f, b);
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
