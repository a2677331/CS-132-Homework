// Jian Zhong
// Prof. Mackay
// CS132 Project 1
// 00/00/2019
// rationalNum.cpp


#include "rationalNum.h"

// Definition of Constructor
rationalNum::rationalNum(int n, int d)
{
    setNum(n);
    setDen(d);
}

// Definition of exception1()
bool rationalNum::exception1() const
{
    return (numerator  == denominator);
}

// Definition of exception2()
bool rationalNum::exception2() const
{
    return(denominator == 1);
}

// Definition of getNum()
int rationalNum::getNum() const
{
    return (numerator );
}

// Definition of getDen()
int rationalNum::getDen() const
{
    return (denominator);
}

// Definition of setNum()
void rationalNum::setNum(int n)
{
    numerator  = n;
}

// Definition of setDen()
void rationalNum::setDen(int d)
{
    denominator = d;
}

// Definition of Invert()
void rationalNum::invert(rationalNum& obj)
{
    cout << "\nInverting...\n";
    int tempNum;
    
    // Swap numerator and denominator
    tempNum = obj.numerator ;
    obj.numerator  = obj.denominator;
    obj.denominator = tempNum;
}

// Definition of Mixed()
void rationalNum::mixed()
{
    if(abs(numerator)  > abs(denominator))
    {
        cout << "\nMixed fractioning...\n";
        lPart = numerator  / denominator; // get left part of the Mixed fraction
        numerator  = abs(numerator)  % abs(denominator);
        denominator = abs(denominator);
    }
    else
        cout << "It is not a improper function.\n";
}

// Definition of Reduce()
void rationalNum::reduce()
{
    int temp1 = abs(numerator);
    int temp2 = abs(denominator);
    
    while(temp1 != temp2)
        if(temp1 == 0 || temp2 == 0) // When either Numerator or Denominator is 0,
            break;                   // the fraction cannot be reduced.
        else if(temp1 > temp2)
            temp1 = (temp1) - (temp2);
        else if(temp1 < temp2)
            temp2 = (temp2) - (temp1);
    
    int GCD = temp1; // Greatest Common Divisor
    
    //Reduce the fraction
    if (GCD == 0)
        cout << "Numerator is 0, cannot be reduced.\n";
    else
    {
        numerator = numerator / GCD;
        denominator = denominator /GCD;
    }
}

// Definition of Ostream Operator
ostream& operator << (ostream& out, const rationalNum& otherObj)
{
    if (otherObj.denominator == 0)    // if denominator is zero, display #div0.
        out << "#div0\n";
    else if ( otherObj.exception1() ) // if denominator and numberator are the same, display 1.
        out << "The result is: " << 1 << endl;
    else if ( otherObj.exception2() ) // if denominator is one, then display only the numerator.
        out << "The result is: " << otherObj.numerator  << endl;
    else if (otherObj.lPart != 0)     // If it is Mixed Function
        out << "The result is: "  << otherObj.lPart << " and "<< otherObj.numerator  << '/' << otherObj.denominator << endl;
    else                              // other than that, output normal rational form number.
        out << "The result is: " << otherObj.numerator  << '/' << otherObj.denominator << endl;
    
    return out;
}

// Definition of addition operator
rationalNum rationalNum::operator + (const rationalNum& rightObj)
{
    rationalNum temp;
    
    cout << "Adding...\n";
    if (denominator != rightObj.denominator) // if both rational numbers have different denominators.
    {
        temp.numerator  = numerator  * rightObj.denominator + rightObj.numerator  * denominator;
        temp.denominator = denominator * rightObj.denominator;
    }
    else // if share same denominators.
    {
        temp.numerator  = numerator  + rightObj.numerator ;
        temp.denominator = denominator;
    }

    temp.reduce(); // reduce the fraction
    
    return temp;
}

 // Definition of subtraction operator
rationalNum rationalNum::operator - (const rationalNum& rightObj)
{
    rationalNum temp;
    
    cout << "Subtracting...\n";
    if (denominator != rightObj.denominator) // if both rational numbers have different denominators.
    {
        temp.numerator  = numerator  * rightObj.denominator - rightObj.numerator  * denominator;
        temp.denominator = denominator * rightObj.denominator;
    }
    else // if share same denominators.
    {
        temp.numerator  = numerator  - rightObj.numerator ;
        temp.denominator = denominator;
    }
    
    temp.reduce(); // reduce the fraction
    
    return temp;
}

// Definition of multipliacation operator
rationalNum rationalNum::operator * (const rationalNum& rightObj)
{
    rationalNum temp;
    
    cout << "Multiplying...\n";
    temp.numerator  = numerator  * rightObj.numerator ;
    temp.denominator = denominator * rightObj.denominator;
    
    temp.reduce(); // reduce the fraction
    
    return temp;
}

// Definition of division operator
rationalNum rationalNum::operator / (const rationalNum& rightObj)
{
    rationalNum temp;
    
    cout << "Dividing...\n";
    temp.numerator  = numerator  * rightObj.denominator;
    temp.denominator = denominator * rightObj.numerator ;
    
    temp.reduce(); // reduce the fraction
    
    return temp;
}

// Definition of less than operator
bool rationalNum::operator < (const rationalNum& rightObj) const
{
    if (denominator != rightObj.denominator) // if both rational numbers have different denominators.
        return ( (numerator  * rightObj.denominator - rightObj.numerator  * denominator) < 0 );
    else
        return (numerator  < rightObj.numerator );
}

// Definition of less than or equal to operator
bool rationalNum::operator <= (const rationalNum& rightObj) const
{
    if (denominator != rightObj.denominator) // if both rational numbers have different denominators.
        return ( (numerator  * rightObj.denominator - rightObj.numerator  * denominator) <= 0 );
    else
        return (numerator  <= rightObj.numerator );
}

// Definition of greater than operator
bool rationalNum::operator > (const rationalNum& rightObj) const
{
    if (denominator != rightObj.denominator) // if both rational numbers have different denominators.
        return ( (numerator  * rightObj.denominator - rightObj.numerator  * denominator) > 0 );
    else
        return (numerator  > rightObj.numerator );
}

// Definition of greater than or equal to operator
bool rationalNum::operator >= (const rationalNum& rightObj) const
{
    if (denominator != rightObj.denominator) // if both rational numbers have different denominators.
        return ( (numerator  * rightObj.denominator - rightObj.numerator  * denominator) >= 0 );
    else
        return (numerator  >= rightObj.numerator );
}

// Definition of greater equal operator
bool rationalNum::operator == (const rationalNum& rightObj) const
{
    if (denominator != rightObj.denominator) // if both rational numbers have different denominators.
        return ( (numerator  * rightObj.denominator - rightObj.numerator  * denominator) == 0 );
    else
        return (numerator  == rightObj.numerator );
}
