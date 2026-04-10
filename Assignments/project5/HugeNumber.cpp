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
    : m_digits{0}
    , m_isNegative{false}
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
                m_isNegative = true;
            }
            continue;
        }

        m_digits.push_back(str[i] - '0');
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
                m_isNegative = true;
            }
            continue;
        }

        m_digits.push_back(arr[i] - '0');
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
        m_isNegative = isNegative;

    for (const auto& digit : digits)
    {
        m_digits.push_back(digit);
    }
}

HugeNumber HugeNumber::operator+(const HugeNumber &other) const
{
    HugeNumber result {};       // empty
    result.m_digits.clear();

    HugeNumber v1 {*this};
    HugeNumber v2 {other};
    int sum {};
    int carry {};
    int digit {};

    std::reverse(v1.m_digits.begin(), v1.m_digits.end());
    std::reverse(v2.m_digits.begin(), v2.m_digits.end());

    int smallerSize = std::min(v1.m_digits.size(), v2.m_digits.size());

    if (this->m_isNegative == other.m_isNegative)         // if same sign
    {
        for (int i = 0; i < smallerSize; ++i)
        {
            sum = v1.m_digits[i] + v2.m_digits[i] + carry;
            carry = sum / 10;
            digit = sum % 10;
            result.m_digits.push_back(digit);
        }

        const auto& larger = (v1.m_digits.size() > v2.m_digits.size()) ? v1 : v2;

        for (int i = smallerSize; i < larger.m_digits.size(); ++i)
        {
            sum = larger.m_digits[i] + carry;
            carry = sum / 10;
            digit = sum % 10;
            result.m_digits.push_back(digit);
        }

        if (carry != 0)
        {
            result.m_digits.push_back(carry);
        }

        // set sign for result
        result.m_isNegative = this->m_isNegative;
    }
    else
    {

    }

    for (auto d : result.m_digits)
        std::cout << d << " ";
    std::cout << "\n";

    std::reverse(result.m_digits.begin(), result.m_digits.end());
    return result;
}

bool HugeNumber::isZero() const
{
    return (numDigits() == 1) && (!m_isNegative) && (m_digits[0] == 0);
}

int HugeNumber::numDigits() const
{
    return m_digits.size();
}

HugeNumber HugeNumber::abs() const
{
    HugeNumber absResult = *this;
    absResult.m_isNegative = false;

    return absResult;
}

std::ostream & operator<<(std::ostream &out, const HugeNumber &hugeNumber)
{
    if (hugeNumber.m_isNegative)
    {
        out << "-";
    }

    for (const auto& digit : hugeNumber.m_digits)
    {
        out << digit;
    }

    return out;
}
