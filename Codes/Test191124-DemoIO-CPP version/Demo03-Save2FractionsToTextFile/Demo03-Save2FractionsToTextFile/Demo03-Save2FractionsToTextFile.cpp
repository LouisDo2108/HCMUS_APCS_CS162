//
//  Demo03-Save2FractionsToTextFile.cpp
//  Demo03-Save2FractionsToTextFile
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
    ofstream f;
    
    cout << "Fraction 1: " << endl;
    inputFraction(a);
    cout << "Fraction 2: " << endl;
    inputFraction(b);
    
    f.open("/Users/apple/Documents/SC/c/Test191124-DemoIO-CPP version/Demo03-Save2FractionsToTextFile/Demo03-Save2FractionsToTextFile/2fractions-output.txt");
    if(!f.is_open()){
        cout << "Can not create file" << endl;
    }
    else{
        saveFraction(f, a);
        saveFraction(f, b);
        f.close();
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
