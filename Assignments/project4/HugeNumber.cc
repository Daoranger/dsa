/**
* HugeNumber.cpp
 *
 * Author: Hoang Nguyen
 * Date created: 3/28/2026
 * Last modified: 4/12/2026
 *
 */

#include "HugeNumber.h"
#include <algorithm>

HugeNumber::HugeNumber()
    : digits_{0}
    , isNegative_{false}
{
}

HugeNumber::HugeNumber(const std::string &str)
{
    if (str.empty())
        throw std::invalid_argument("Empty input");

    if (str.size() == 1 && str[0] == '-')
        throw std::invalid_argument("Invalid input");

    int startIndex = 0;

    if (str[0] == '-')
    {
        isNegative_ = true;
        startIndex = 1;
    }

    for (int i = startIndex; i < str.size(); ++i)
    {
        if (!isdigit(str[i]))
        {
            throw std::invalid_argument("Invalid input");
        }
    }

    for (int i = startIndex; i < str.size(); ++i)
    {
        digits_.push_back(str[i] - '0');
    }

    normalize();
}

HugeNumber::HugeNumber(const char arr[], int size)
{
    if (size == 0)
        throw std::invalid_argument("Empty input");

    if (size == 1 && arr[0] == '-')
        throw std::invalid_argument("Invalid input");

    int startIndex = 0;

    if (arr[0] == '-')
    {
        isNegative_ = true;
        startIndex = 1;
    }

    for (int i = startIndex; i < size; ++i)
    {
        if (!isdigit(arr[i]))
        {
            throw std::invalid_argument("Invalid input");
        }
    }

    for (int i = startIndex; i < size; ++i)
    {
        digits_.push_back(arr[i] - '0');
    }

    normalize();
}

HugeNumber::HugeNumber(const std::vector<int>& digits, bool isNegative)
{
    if (digits.empty())
        throw std::invalid_argument("Empty input");

    isNegative_ = isNegative;

    for (const auto& digit : digits)
    {
        if (digit < 0 || digit > 9)
            throw std::invalid_argument("HugeNumber: invalid input");
        digits_.push_back(digit);
    }

    normalize();
}

HugeNumber HugeNumber::operator+(const HugeNumber& other) const
{
    HugeNumber result;

    // if same signs
    if (isNegative_ == other.isNegative_)
    {
        result = addMagnitude(other);
        result.isNegative_ = isNegative_;
    }
    else // if different signs
    {
        int compare = compareMagnitude(other);

        if (compare < 0)
        {
            result = other.subtractMagnitude(*this);
            result.isNegative_ = other.isNegative_;
        }
        else
        {
            result = this->subtractMagnitude(other);
            result.isNegative_ = isNegative_;
        }
    }

    result.normalize();
    return result;
}

HugeNumber HugeNumber::operator-(const HugeNumber &other) const
{
    HugeNumber negativeOther = other;
    negativeOther.isNegative_ = !negativeOther.isNegative_;

    return *this + negativeOther;
}

HugeNumber HugeNumber::operator*(const HugeNumber &other) const
{
    HugeNumber total;
    int botIndex = other.digits_.size() - 1;
    int shift = 0;

    while (botIndex >= 0)
    {
        HugeNumber partial;
        partial.digits_.clear();
        int topIndex = digits_.size() - 1;
        int carry = 0;

        while (topIndex >= 0)
        {
            int product  = other.digits_[botIndex] * digits_[topIndex] + carry;
            int digit = product % 10;
            carry = product / 10;
            partial.digits_.push_back(digit);
            --topIndex;
        }

        if (carry != 0)
        {
            partial.digits_.push_back(carry);
        }

        std::reverse(partial.digits_.begin(), partial.digits_.end());
        for (int i = 0; i < shift; ++i)
        {
            partial.digits_.push_back(0);
        }
        total = total + partial;
        --botIndex;
        ++shift;
    }

    total.isNegative_ = isNegative_ ^ other.isNegative_;
    total.normalize();
    return total;
}

bool HugeNumber::operator==(const HugeNumber &other) const
{
    return (this->compareMagnitude(other) == 0 && isNegative_ == other.isNegative_);
}

bool HugeNumber::operator!=(const HugeNumber &other) const
{
    return !(*this == other);
}

bool HugeNumber::operator<(const HugeNumber &other) const
{
    // different sign: if current is negative true, if not false
    if (isNegative_ != other.isNegative_)
    {
        return isNegative_;
    }

    int comp = compareMagnitude(other);
    return  (!isNegative_) ? comp < 0 : comp > 0;
}

bool HugeNumber::operator<=(const HugeNumber &other) const
{
    return !(other < *this);
}

bool HugeNumber::operator>(const HugeNumber &other) const
{
    return other < *this;
}

bool HugeNumber::operator>=(const HugeNumber &other) const
{
    return !(*this < other);
}

HugeNumber& HugeNumber::operator++()
{
    *this = *this + HugeNumber("1");
    return *this;
}

HugeNumber HugeNumber::operator++(int)
{
    HugeNumber temp = *this;
    *this = *this + HugeNumber("1");
    return temp;
}

HugeNumber& HugeNumber::operator--()
{
    *this = *this - HugeNumber("1");
    return *this;
}

HugeNumber HugeNumber::operator--(int)
{
    HugeNumber temp = *this;
    *this = *this - HugeNumber("1");
    return temp;
}

HugeNumber HugeNumber::operator~() const
{
    HugeNumber temp = *this;
    std::reverse(temp.digits_.begin(), temp.digits_.end());
    temp.normalize();
    return temp;
}

bool HugeNumber::isZero() const
{
    return (numDigits() == 1) && (!isNegative_) && (digits_[0] == 0);
}

int HugeNumber::numDigits() const
{
    return digits_.size();
}

HugeNumber HugeNumber::abs() const
{
    HugeNumber absResult = *this;
    absResult.isNegative_ = false;

    return absResult;
}

// a good cases of normalize is when compare 0 and -0,
// then they are different cuz of sign so normalize is important
void HugeNumber::normalize()
{
    // case 1: delete all leading zeroes
    while (digits_.size() > 1 && digits_[0] == 0)
    {
        digits_.erase(digits_.begin());
    }

    // case 2: if last element is zero, ensure it is positive
    if (digits_[0] == 0)
    {
        isNegative_ = false;
    }
}

int HugeNumber::compareMagnitude(const HugeNumber& other) const
{
    // if theirs sizes are different we can know which one is smaller/larger
    if (digits_.size() != other.digits_.size())
    {
        return (digits_.size() < other.digits_.size()) ? -1 : 1;
    }

    // if theirs size are the same, we have to compare each element
    // because we store the most significant digits at index 0, we start
    // at zero and traverse from left to right
    for (int i = 0; i < digits_.size(); ++i)
    {
        if (digits_[i] != other.digits_[i])
        {
            return (digits_[i] < other.digits_[i]) ? -1 : 1;
        }
    }

    // equals
    return 0;
}

HugeNumber HugeNumber::addMagnitude(const HugeNumber& other) const
{
    HugeNumber result;
    result.digits_.clear();
    int aIndex = digits_.size() - 1;
    int bIndex = other.digits_.size() - 1;
    int carry = 0;

    while (aIndex >= 0 || bIndex >= 0)
    {
        int aDigit = (aIndex >= 0) ? digits_[aIndex] : 0;
        int bDigit = (bIndex >= 0) ? other.digits_[bIndex] : 0;
        int sum = aDigit + bDigit + carry;
        int digit = sum % 10;
        carry = sum / 10;
        result.digits_.push_back(digit);

        --aIndex;
        --bIndex;
    }

    if (carry != 0) result.digits_.push_back(carry);

    std::reverse(result.digits_.begin(), result.digits_.end());
    return result;
}

HugeNumber HugeNumber::subtractMagnitude(const HugeNumber& other) const
{
    HugeNumber result;
    result.digits_.clear();
    int aIndex = digits_.size() - 1;
    int bIndex = other.digits_.size() - 1;
    int borrow = 0;

    while (aIndex >= 0)
    {
        int aDigit = digits_[aIndex];
        int bDigit = (bIndex >= 0) ? other.digits_[bIndex] : 0;
        int diff = aDigit - bDigit - borrow;
        int digit;

        if (diff < 0)
        {
            digit = diff + 10;
            borrow = 1;
        }
        else
        {
            digit = diff;
            borrow = 0;
        }
        result.digits_.push_back(digit);

        --aIndex;
        --bIndex;
    }

    std::reverse(result.digits_.begin(), result.digits_.end());
    result.normalize();
    return result;
}


std::ostream & operator<<(std::ostream &out, const HugeNumber &hugeNumber)
{
    if (hugeNumber.isNegative_)
    {
        out << "-";
    }

    for (const auto& digit : hugeNumber.digits_)
    {
        out << digit;
    }

    return out;
}

std::istream & operator>>(std::istream& in, HugeNumber& hugeNumber)
{
    hugeNumber.digits_.clear();
    hugeNumber.isNegative_ = false;

    std::string s;
    in >> s;

    if (s.empty())
    {
        throw std::invalid_argument("Empty input");
    }

    if (s.size() == 1 && s[0] == '-')
    {
        throw std::invalid_argument("Invalid input");
    }

    int startIndex = 0;
    if (s[0] == '-')
    {
        hugeNumber.isNegative_ = true;
        startIndex = 1;
    }

    // check if
    for (int i = startIndex; i < s.size(); ++i)
    {
        if (!isdigit(s[i]))
        {
            throw std::invalid_argument("Invalid input");
        }
    }

    for (int i = startIndex; i < s.size(); ++i)
    {
        hugeNumber.digits_.push_back(s[i] - '0');
    }
    hugeNumber.normalize();
    return in;
}