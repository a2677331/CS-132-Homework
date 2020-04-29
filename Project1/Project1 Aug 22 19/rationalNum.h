// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 00/00/2019
// rationalNum.h


#ifndef rationalNum_h
#define rationalNum_h

#include <iostream>

using namespace std;

class rationalNum
{
    friend ostream& operator << (ostream&, const rationalNum&); // overload << operator
    friend void foo();
public:
    rationalNum(int = 0, int = 0); // Constructor
    
    int getNum() const; // Fetch numerator
    int getDen() const; // Fetch denominator
    void setNum(int);   // Set numerator
    void setDen(int);   // Set denominator
    void invert(rationalNum&); // Invert fractioin
    void mixed();  // Find Mixed fraction
    void reduce(); // Reduce fraction
    bool exception1() const;   // Exception Case1: if denominator and numberator are the same, just display 1.
    bool exception2() const;   // Exception Case2: if denominator is 1, just display numerator.
    
    rationalNum operator + (const rationalNum&); // overload addition operator
    rationalNum operator - (const rationalNum&); // overload subtraction operator
    rationalNum operator * (const rationalNum&); // overload multipliacation operator
    rationalNum operator / (const rationalNum&); // overload division operator
    bool operator < (const rationalNum&) const;  // overload less than operator
    bool operator <= (const rationalNum&) const; // overload less than or equal to operator
    bool operator > (const rationalNum&) const;  // overload greater than operator
    bool operator >= (const rationalNum&) const; // overload greater than or equal to operator
    bool operator == (const rationalNum&) const; // overload greater equal operator
    
private:
    int numerator ;  // numerator
    int denominator; // denominator
    int lPart = 0;   // left part of the mixed function
};

#endif /* rationalNum_h */
