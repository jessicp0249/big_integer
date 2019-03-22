/*

*/

#include<cmath>
#include<iostream>
#include<fstream>
#include<vector>
#include "bigint.h"

BigInt operator+(BigInt num1, BigInt num2);
BigInt operator-(BigInt num1, BigInt num2);
BigInt operator*(BigInt num1, BigInt num2);
BigInt operator<<(std::fstream f, BigInt num);

bool operator<(BigInt num1, BigInt num2);
bool operator>(BigInt num1, BigInt num2);
bool operator==(BigInt num1, BigInt num2);


BigInt operator+(BigInt num1, BigInt num2)
{
    BigInt result;
    int digit1,digit2,max;

    if(num1>num2)
        max=num1.max_placeval();
    else
        max=num2.max_placeval();

    // if num1 and num2 are both negative/positive, give result the same positive/negative bool value as num1
    if(num1.is_negative()==num2.is_negative())
    {
        for(int i=0; i<max; i++)
        {
            digit1=num1.get_digit(i);
            digit2=num2.get_digit(i);
            result.add_digit(digit1+digit2);
        }       
        result.set_negative(num1.is_negative());
    }
    else
    {
         if(num2.is_negative()==true)
            result = num1-num2;
         else if(num1.is_negative()==true)
            result = num2-num1;
    }    

    return result;
}

BigInt operator-(BigInt num1, BigInt num2)
{
    BigInt result;
    int digit1,digit2,max;

    if(num1.is_negative()==num2.is_negative()) 
    {
        if(num2>num1)
        {
            result=num2-num1;
            result.set_negative(true);
        }
        else
        {
            for(int i=0; i<max; i++)
            {
                digit1=num1.get_digit(i);
                digit2=num2.get_digit(i);
                result.add_digit(digit1-digit2);
            }            
        }

    }
    else
    {
        if(num1.is_negative()==true)
        {
            num2.set_negative(true);
            result = num1+num2;
        }
        else
        {
            num2.set_negative(false);
            result = num1+num2;
        }
    }

    return result;
}

BigInt operator*(BigInt num1, BigInt num2)
{
    BigInt result;
    int digit1,digit2;
    int single=0;
    const int INCREM=10;    // Increment through place values
    
    for(int i=0; i<num1.max_placeval(); i++)
    {
        digit1=num1.get_digit(i)*(INCREM*i);
        
        for(int j=0; j<num2.max_placeval(); j++)
        {
            digit2=num2.get_digit(j);
            single+=digit1*digit2*(INCREM*j);
        }
    }            
    result.add_digit(single);
    // Two positive nums or two negative nums = positive
    if(num1.is_negative()==num2.is_negative())
        result.set_negative(false);
    // One positive num and one negative num = negative
    else result.set_negative(true);

    return result;
}

bool operator<(BigInt num1, BigInt num2)
{
    bool result;
    if(num1==num2)
        result=false;
    // if one num is negative and one is positive...
    else if(num1.is_negative()!=num2.is_negative())
    {
        // and if num1 is negative...
        if(num1.is_negative()==true)
            result=true;
        // but if num2 is negative...
        else
            result=false;
    }
    
    return result;

}

bool operator>(BigInt num1, BigInt num2)
{
    return(!(num1<num2));
}


bool operator==(BigInt num1, BigInt num2)
{
    bool result;
    if(num1.is_negative()==num2.is_negative() && *(num1.get_digits())==*(num2.get_digits()))
        result=true;
    else result=false;

    return result;
}
