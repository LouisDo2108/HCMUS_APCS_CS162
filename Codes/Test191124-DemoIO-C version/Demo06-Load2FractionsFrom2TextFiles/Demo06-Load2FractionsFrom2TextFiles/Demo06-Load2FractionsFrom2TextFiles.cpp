//
//  Demo06-Load2FractionsFrom2TextFiles.cpp
//  Demo06-Load2FractionsFrom2TextFiles
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
int main(int argc, const char * argv[]) {
    Fraction a, b;
    FILE *f1, *f2;
    
    f1 = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo06-Load2FractionsFrom2TextFiles/Demo06-Load2FractionsFrom2TextFiles/fraction1-input.txt", "rt");
    f2 = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo06-Load2FractionsFrom2TextFiles/Demo06-Load2FractionsFrom2TextFiles/fraction2-input.txt", "rt");
    
    if(f1 == NULL || f2 == NULL){
        printf("Can not open 2 files\n");
    }
    else{
        loadFraction(f1, a);
        loadFraction(f2, b);
        
        printf("Fraction a: ");
        printFraction(a);
        printf("Fraction b: ");
        printFraction(b);
        
        fclose(f1);
        fclose(f2);
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

