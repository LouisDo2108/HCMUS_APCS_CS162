//
//  Demo04-Load2FractionsFromTextFile.cpp
//  Demo04-Load2FractionsFromTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include<stdio.h>

struct Fraction{
    int num, denom;
};

void loadFraction(FILE *f, Fraction &p);
void printFraction(Fraction p);
int main(int argc, const char * argv[]) {
    Fraction a, b;
    FILE *f;
    
    f = fopen("/Users/apple/Documents/SC/c/Test191124-DemoIO-C version/Demo04-Load2FractionsFromTextFile/Demo04-Load2FractionsFromTextFile/2fractions-input.txt", "rt");
    if(f == NULL){
        printf("Can not open file\n");
    }
    else{
        loadFraction(f, a);
        loadFraction(f, b);
        
        printf("Fraction a: ");
        printFraction(a);
        printf("Fraction b: ");
        printFraction(b);
        
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
