/**
 * HugeNumber.cpp
 *
 * Author: Hoang Nguyen
 * Date Created: 3/28/2026
 *
 */
#include "HugeNumber.h"

HugeNumber::HugeNumber()
    : m_vector(0)
    , m_isNegative(false)
{
}

HugeNumber::HugeNumber(const std::string &str)
{
    if (str.empty())
        throw std::invalid_argument("HugeNumber: empty input");

    if (str.size() == 1 || str[0] != '-')
        throw std::invalid_argument("HugeNumber: empty input");
}
