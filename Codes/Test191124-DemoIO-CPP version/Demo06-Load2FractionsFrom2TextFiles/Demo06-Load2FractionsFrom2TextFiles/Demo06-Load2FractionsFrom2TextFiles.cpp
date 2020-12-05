//
//  Demo06-Load2FractionsFrom2TextFiles.cpp
//  Demo06-Load2FractionsFrom2TextFiles
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
    ifstream f1, f2;
    
    f1.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo06-Load2FractionsFrom2TextFiles/Demo06-Load2FractionsFrom2TextFiles/fraction1-input.txt");
    f2.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo06-Load2FractionsFrom2TextFiles/Demo06-Load2FractionsFrom2TextFiles/fraction2-input.txt");
    
    if(!f1.is_open() || !f2.is_open()){
        cout << "Can not open 2 files" << endl;
    }
    else{
        loadFraction(f1, a);
        loadFraction(f2, b);
        
        cout << "Fraction a: ";
        printFraction(a);
        cout << "Fraction b: ";
        printFraction(b);
        
        f1.close();
        f2.close();
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

