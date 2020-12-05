//
//  Demo05-Save2FractionsTo2TextFiles.cpp
//  Demo05-Save2FractionsTo2TextFiles
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

int main(int argc, const char * argv[]) {
    Fraction a, b;
    FILE *f1, *f2;
    
    printf("Fraction 1: \n");
    inputFraction(a);
    printf("Fraction 2: \n");
    inputFraction(b);
    
    f1 = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo05-Save2FractionsTo2TextFiles/Demo05-Save2FractionsTo2TextFiles/fraction1-output.txt", "wt");
    f2 = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo05-Save2FractionsTo2TextFiles/Demo05-Save2FractionsTo2TextFiles/fraction2-output.txt", "wt");
    
    if(f1 == NULL || f2 == NULL){
        printf("Can not create 2 files\n");
    }
    else{
        saveFraction(f1, a);
        saveFraction(f2, b);
        fclose(f1);
        fclose(f2);
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
