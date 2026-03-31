/**
 * HugeNumber.h
 *
 * Author: Hoang Nguyen
 * Date Created: 3/28/2026
 *
 */

#ifndef HUGENUMBER_H
#define HUGENUMBER_H

#include <vector>
#include <string>
#include <iostream>


class HugeNumber
{

public:
    HugeNumber();
    explicit HugeNumber(const std::string& str);
    HugeNumber(const char arr[], int size);
    explicit HugeNumber(const std::vector<int>& digits, bool isNegative);

    HugeNumber operator+(const HugeNumber& other) const;
    HugeNumber operator-(const HugeNumber& other) const;
    HugeNumber operator*(const HugeNumber& other) const;
    bool operator==(const HugeNumber& other) const;
    bool operator!=(const HugeNumber& other) const;
    bool operator<(const HugeNumber& other) const;
    bool operator<=(const HugeNumber& other) const;
    bool operator>(const HugeNumber& other) const;
    bool operator>=(const HugeNumber& other) const;
    HugeNumber& operator++();
    HugeNumber operator++(int);
    HugeNumber& operator--();
    HugeNumber operator--(int);
    friend std::ostream& operator<<(std::ostream& out, const HugeNumber& hugeNumber);
    friend std::istream& operator>>(std::istream& in, HugeNumber& hugeNumber);
    HugeNumber operator~() const;

    bool isZero() const;
    int numDigits() const;
    HugeNumber abs() const;

    // remove leading zeros
    // ensures zero is never stored as negative
    void normalize();

private:
    std::vector<int> m_digits;
    bool m_isNegative {};
};


#endif