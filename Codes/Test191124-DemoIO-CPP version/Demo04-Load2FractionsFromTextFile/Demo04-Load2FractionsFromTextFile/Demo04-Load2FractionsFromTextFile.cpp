//
//  Demo04-Load2FractionsFromTextFile.cpp
//  Demo04-Load2FractionsFromTextFile
//
//  Created by HTThanh on 11/24/19.
//  Copyright © 2019 HTThanh. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Fraction{
    int num, denom;
};

void loadFraction(ifstream &f, Fraction &p);
void printFraction(Fraction p);
int main(int argc, const char * argv[]) {
    Fraction a, b;
    ifstream f;
    
    f.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo04-Load2FractionsFromTextFile/Demo04-Load2FractionsFromTextFile/2fractions-input.txt");
    if(!f.is_open()){
        cout << "Can not open file" << endl;
    }
    else{
        loadFraction(f, a);
        loadFraction(f, b);
        
        cout << "Fraction a: ";
        printFraction(a);
        cout << "Fraction b: ";
        printFraction(b);
        
        f.close();
    }
    return 0;
}

void loadFraction(ifstream &f, Fraction &p){
    f >> p.num;
    f >> p.denom;
}
void printFraction(Fraction p){
    cout << p.num << "/" << p.denom << endl;
}
