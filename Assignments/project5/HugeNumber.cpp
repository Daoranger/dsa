/**
 * HugeNumber.cpp
 *
 * Author: Hoang Nguyen
 * Date Created: 3/28/2026
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
        throw std::invalid_argument("HugeNumber: empty input");

    if (str.size() == 1 && str[0] == '-')
        throw std::invalid_argument("HugeNumber: only negative sign");

    if (str[0] != '-' && !isdigit(str[0]))
        throw std::invalid_argument("HugeNumber: first char is not negative sign or digit");

    for (int i = 1; i < str.size(); ++i)
    {
        if (!isdigit(str[i]))
            throw std::invalid_argument("HugeNumber: invalid input");
    }

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '-')
        {
            if (str[i + 1] != '0')
            {
                isNegative_ = true;
            }
            continue;
        }

        digits_.push_back(str[i] - '0');
    }
}

HugeNumber::HugeNumber(const char arr[], int size)
{
    if (size == 0)
        throw std::invalid_argument("HugeNumber: empty input");

    if (size == 2 && arr[0] == '-')
        throw std::invalid_argument("HugeNumber: only negative sign");

    if (arr[0] != '-' && !isdigit(arr[0]))
        throw std::invalid_argument("HugeNumber: first char is not negative sign or digit");

    // minus one becuase we didn't want to include the null character
    for (int i = 1; i < size - 1; ++i)
    {
        if (!isdigit(arr[i]))
            throw std::invalid_argument("HugeNumber: invalid input");
    }

    // minus one becuase we didn't want to include the null character
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] == '-')
        {
            if (arr[i + 1] != '0')
            {
                isNegative_ = true;
            }
            continue;
        }

        digits_.push_back(arr[i] - '0');
    }
}

HugeNumber::HugeNumber(const std::vector<int>& digits, bool isNegative)
{
    if (digits.empty())
        throw std::invalid_argument("HugeNumber: empty input");

    for (const auto& digit : digits)
    {
        if (digit < 0 || digit > 9)
            throw std::invalid_argument("HugeNumber: invalid input");
    }

    if (digits[0] != 0)
        isNegative_ = isNegative;

    for (const auto& digit : digits)
    {
        digits_.push_back(digit);
    }
}

HugeNumber HugeNumber::operator+(const HugeNumber &other) const
{
    HugeNumber result {};       // empty

    HugeNumber v1 {*this};
    HugeNumber v2 {other};
    int sum {};
    int carry {};
    int digit {};

    std::reverse(v1.digits_.begin(), v1.digits_.end());
    std::reverse(v2.digits_.begin(), v2.digits_.end());

    int smallerSize = std::min(v1.digits_.size(), v2.digits_.size());

    if (this->isNegative_ == other.isNegative_)         // if same sign
    {
        for (int i = 0; i < smallerSize; ++i)
        {
            sum = v1.digits_[i] + v2.digits_[i] + carry;
            carry = sum / 10;
            digit = sum % 10;
            result.digits_.push_back(digit);
        }

        const auto& larger = (v1.digits_.size() > v2.digits_.size()) ? v1 : v2;

        for (int i = smallerSize; i < larger.digits_.size(); ++i)
        {
            sum = larger.digits_[i] + carry;
            carry = sum / 10;
            digit = sum % 10;
            result.digits_.push_back(digit);
        }

        if (carry != 0)
        {
            result.digits_.push_back(carry);
        }

        // set sign for result
        result.isNegative_ = this->isNegative_;
    }
    else
    {
        if (*this < other)
        {
            return other - *this;
        }
        else
        {
            return *this - other;
        }
    }

    std::reverse(result.digits_.begin(), result.digits_.end());
    return result;
}

bool HugeNumber::operator==(const HugeNumber &other) const
{
    if (numDigits() != other.numDigits() || isNegative_ != other.isNegative_)
    {
        return false;
    }

    for (int i = 0; i < numDigits(); ++i)
    {
        if (digits_[i] != other.digits_[i])
        {
            return false;
        }
    }

    return true;
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

    int comp = compareMagnitudes(*this, other);

    // same sign
    if (!isNegative_) // if both positive, only true if a < b
    {
        return comp < 0;
    }
    else // if bot negative, only true if a > b
    {
        return comp > 0;
    }
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

void HugeNumber::normalize()
{
    // case 1: delete all leading zeroes
    while (digits_.size() > 1 && digits_.front() == 0)
    {
        digits_.erase(digits_.begin());
    }

    // case 2: if last element is zero, ensure it is positive
    if (digits_[0] == 0)
    {
        isNegative_ = false;
    }
}

// Return -1 if a < b, return 1 if a > b, return 0 if a == b
int HugeNumber::compareMagnitudes(const HugeNumber& a, const HugeNumber& b) const
{
    // if diff number of digits
    if (a.digits_.size() != b.digits_.size())
    {
        return (a.digits_.size() < b.digits_.size()) ? -1 : 1;
    }

    // if same number of digits, compare by each digits
    for (int i = 0; i < a.digits_.size(); ++i)
    {
        if (a.digits_[i] != b.digits_[i])
        {
            return (a.digits_[i] < b.digits_[i]) ? -1 : 1;
        }
    }

    // a = b
    return 0;
}

HugeNumber HugeNumber::addMagnitudes(const HugeNumber &a, const HugeNumber &b) const
{
    HugeNumber result {};       // empty

    HugeNumber v1 {a};
    HugeNumber v2 {b};
    int sum {};
    int carry {};
    int digit {};

    std::reverse(v1.digits_.begin(), v1.digits_.end());
    std::reverse(v2.digits_.begin(), v2.digits_.end());

    int smallerSize = std::min(v1.digits_.size(), v2.digits_.size());

    for (int i = 0; i < smallerSize; ++i)
    {
        sum = v1.digits_[i] + v2.digits_[i] + carry;
        carry = sum / 10;
        digit = sum % 10;
        result.digits_.push_back(digit);
    }

    const auto& larger = (v1.digits_.size() > v2.digits_.size()) ? v1 : v2;

    for (int i = smallerSize; i < larger.digits_.size(); ++i)
    {
        sum = larger.digits_[i] + carry;
        carry = sum / 10;
        digit = sum % 10;
        result.digits_.push_back(digit);
    }

    if (carry != 0)
    {
        result.digits_.push_back(carry);
    }

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

std::istream & operator>>(std::istream &in, HugeNumber& hugeNumber)
{
    hugeNumber.digits_.clear();
    hugeNumber.isNegative_ = false;

    std::string s;
    in >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (!isdigit(s[i]))
        {
            if (i == 0 && s[i] == '-')
            {
                continue;
            }
            throw std::invalid_argument("HugeNumber: empty input");
        }
    }

    if (s[0] == '-')
    {
        hugeNumber.isNegative_ = true;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '-')
        {
            continue;
        }
        hugeNumber.digits_.push_back(s[i] - '0');
    }
    hugeNumber.normalize();

    return in;
}