//
//  Demo05-Save2FractionsTo2TextFiles.cpp
//  Demo05-Save2FractionsTo2TextFiles
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

void inputFraction(Fraction &p);
void saveFraction(ofstream &f, Fraction p);

int main(int argc, const char * argv[]) {
    Fraction a, b;
    ofstream f1, f2;
    
    cout << "Fraction 1: " << endl;
    inputFraction(a);
    cout << "Fraction 2: " << endl;
    inputFraction(b);
    
    f1.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo05-Save2FractionsTo2TextFiles/Demo05-Save2FractionsTo2TextFiles/fraction1-output.txt");
    f2.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo05-Save2FractionsTo2TextFiles/Demo05-Save2FractionsTo2TextFiles/fraction2-output.txt");
    
    if(!f1.is_open() || !f2.is_open()){
        cout << "Can not create 2 files" << endl;
    }
    else{
        saveFraction(f1, a);
        saveFraction(f2, b);
        f1.close();
        f2.close();
    }
    return 0;
}

void inputFraction(Fraction &p){
    cout << "Numerator: ";
    cin >> p.num;
    cout << "Denominator: ";
    cin >> p.denom;
}
void saveFraction(ofstream &f, Fraction p){
    f << p.num << " " << p.denom << endl;
}
