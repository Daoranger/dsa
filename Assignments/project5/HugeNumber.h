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
    bool operator==(const HugeNumber& other) const;     // done
    bool operator!=(const HugeNumber& other) const;
    bool operator<(const HugeNumber& other) const;
    bool operator<=(const HugeNumber& other) const;
    bool operator>(const HugeNumber& other) const;
    bool operator>=(const HugeNumber& other) const;
    HugeNumber& operator++();
    HugeNumber operator++(int);
    HugeNumber& operator--();
    HugeNumber operator--(int);
    friend std::ostream& operator<<(std::ostream& out, const HugeNumber& hugeNumber);   // done
    friend std::istream& operator>>(std::istream& in, HugeNumber& hugeNumber);          // done
    HugeNumber operator~() const;   // done

    bool isZero() const;        // done
    int numDigits() const;      // done
    HugeNumber abs() const;     // done

    // remove leading zeros
    // ensures zero is never stored as negative
    void normalize();           // done

private:
    std::vector<int> digits_;
    bool isNegative_ {};

    // helper functions
    int compareMagnitudes(const HugeNumber& a, const HugeNumber& b) const;
    HugeNumber addMagnitudes(const HugeNumber& a, const HugeNumber& b) const;
    HugeNumber subtractMagnitudes(const HugeNumber& larger, const HugeNumber& smaller) const;
};


#endif