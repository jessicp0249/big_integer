/*

*/

#include<cmath>
#include<iostream>
#include<vector>

#ifndef BIGINT_H
#define BIGINT_H
class BigInt
{
private:
    std::vector<int> m_digits;
    bool m_negative;

public:
    BigInt();
    void add_digit(int value);
    int carry(int& value);
    int get_digit(int index);
    std::vector<int>* get_digits();
    int max_placeval();

    void set_negative(bool tf);
    bool is_negative();

};
#endif
