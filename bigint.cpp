
/*

*/

#include<cmath>
#include<iostream>
#include<vector>
#include "bigint.h"

BigInt::BigInt()
{}

void BigInt::add_digit(int value)
{
    const int FACTOR=10;

    if(value<0)
        m_negative=true;

    value=fabs(value);
    if(value<FACTOR)
        m_digits.push_back(value);
    else
    {
        int single = 0;
        while(value>0)
        {
            single=carry(value);    // Separate single digit from value
            m_digits.push_back(single);
        }
    }
}

int BigInt::carry(int& value)
{
    const int FACTOR=10;
    int single=value%FACTOR;
    value/=FACTOR;

    return single;
}

int BigInt::get_digit(int index)
{
    if(index>=max_placeval())
        return 0;
    else
        return m_digits[index];
}

int BigInt::max_placeval()
{
    return m_digits.size();
}

std::vector<int>* BigInt::get_digits()
{
    std::vector<int>* v=&m_digits;
    return v;
}


void BigInt::set_negative(bool tf)
{
    m_negative=tf;
}
    
bool BigInt::is_negative()
{
    return m_negative;
}

