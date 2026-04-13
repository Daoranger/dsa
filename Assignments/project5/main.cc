/**
* main.cpp
 *
 * Author: Hoang Nguyen
 * Date created: 3/28/2026
 * Last modified: 4/12/2026
 *
 * Where we run and test the program with HugeNumber
 */

#include "HugeNumber.h"
#include <iostream>
#include <vector>

int main()
{
    // ------ Constructors Tests ------
    HugeNumber zero;
    std::cout << "zero: " << zero << "\n";

    HugeNumber hnStr1(std::string("12345678901234567890"));
    HugeNumber hnStr2(std::string("-45009"));
    std::cout << "hnStr1: " << hnStr1 << "\n";
    std::cout << "hnStr2: " << hnStr2 << "\n";

    char arr[] = "12345678901234567890";
    HugeNumber hnCharArr(arr, sizeof(arr) - 1); // char is 1 byte
    std::cout << "hnCharArr: " << hnCharArr << "\n";

    std::vector<int> d = {1,2,3,4,5};
    HugeNumber hnVecPos(d, false);
    HugeNumber hnVecNeg(d, true);
    std::cout << "hnVecPos: " << hnVecPos << "\n";
    std::cout << "hnVecNeg: " << hnVecNeg << "\n";

    // ------ Addition Tests ------

    // Two positives
    HugeNumber atPos1(std::string("999999999999"));
    HugeNumber atPos2(std::string("1"));
    std::cout << "at1 + at2 = " << atPos1 + atPos2 << "\n";

    // Two negatives
    HugeNumber atNeg1(std::string("-999999999999"));
    HugeNumber atNeg2(std::string("-1"));
    std::cout << "atNeg1 + atNeg2 = " << atNeg1 + atNeg2 << "\n";

    // Different signs
    HugeNumber atDS1(std::string("-999999999999"));
    HugeNumber atDS2(std::string("999999999999"));
    std::cout << "atDS1 + atDS2 = " << atDS1 + atDS2 << "\n";

    HugeNumber atDS3(std::string("999999999999"));
    HugeNumber atDS4(std::string("-99999999999"));
    std::cout << "atDS3 + atDS4 = " << atDS3 + atDS4 << "\n";

    HugeNumber atDS5(std::string("-2500"));
    HugeNumber atDS6(std::string("300"));
    std::cout << "atDS5 + atDS6 = " << atDS5 + atDS6 << "\n";

    // ------ Subtraction Tests ------

    // Two positives
    HugeNumber stPos1(std::string("1000000000000"));
    HugeNumber stPos2(std::string("1"));
    std::cout << "stPos1 - stPos2 = " << stPos1 - stPos2 << "\n";

    // Two negatives
    HugeNumber stNeg1(std::string("-99999999"));
    HugeNumber stNeg2(std::string("-1"));
    std::cout << "stNeg1 - stNeg2 = " << stNeg1 - stNeg2 << "\n";

    // Diff signs
    HugeNumber stDiff1(std::string("99999999"));
    HugeNumber stDiff2(std::string("-1"));
    std::cout << "stDiff1 - stDiff2 = " << stDiff1 - stDiff2 << "\n";

    // ------ Product Tests ------

    // Both positive
    HugeNumber ptPos1(std::string("13"));
    HugeNumber ptPos2(std::string("11"));
    std::cout << "ptPos1 * ptPos2 = " << ptPos1 * ptPos2 << "\n";

    // Both negative
    HugeNumber ptNeg1(std::string("-25"));
    HugeNumber ptNeg2(std::string("-4"));
    std::cout << "ptNeg1 * ptNeg2 = " << ptNeg1 * ptNeg2 << "\n";

    // Diff signs
    HugeNumber ptPos(std::string("-25"));
    HugeNumber ptNeg(std::string("4"));
    std::cout << "ptPos * ptNeg = " << ptPos * ptNeg << "\n";

    // ------ Comparison Tests ------

    // Equal
    HugeNumber ctE1(std::string("25"));
    HugeNumber ctE2(std::string("25"));
    std::cout << "ctE1 == ctE2: " << ((ctE1 == ctE2) ? "true" : "false") << '\n';
    HugeNumber ctE3(std::string("-100"));
    HugeNumber ctE4(std::string("-100"));
    std::cout << "-100 == -100: " << ((ctE3 == ctE4) ? "true" : "false") << '\n';
    HugeNumber ctE5(std::string("-19"));
    HugeNumber ctE6(std::string("19"));
    std::cout << "ctE5 == ctE6: " << ((ctE5 == ctE6) ? "true" : "false") << '\n';

    // Not Equals
    HugeNumber ctNE1(std::string("25"));
    HugeNumber ctNE2(std::string("244"));
    std::cout << "ctNE1 != ctNE2: " << ((ctNE1 != ctNE2) ? "true" : "false") << '\n';
    HugeNumber ctNE3(std::string("-99"));
    HugeNumber ctNE4(std::string("99"));
    std::cout << "ctNE3 != ctNE4: " << ((ctNE3 != ctNE4) ? "true" : "false") << '\n';
    HugeNumber ctNE5(std::string("19"));
    HugeNumber ctNE6(std::string("19"));
    std::cout << "ctNE5 != ctNE6: " << ((ctNE5 != ctNE6) ? "true" : "false") << '\n';

    // Less than
    HugeNumber ctLTPos1(std::string("25"));
    HugeNumber ctLTPos2(std::string("244"));
    std::cout << "25 < 244: " << ((ctLTPos1 < ctLTPos2) ? "true" : "false") << '\n';

    HugeNumber ctLTPos3(std::string("25"));
    HugeNumber ctLTPos4(std::string("-244"));
    std::cout << "25 < -244: " << ((ctLTPos3 < ctLTPos4) ? "true" : "false") << '\n';

    HugeNumber ctLTPos5(std::string("-999"));
    HugeNumber ctLTPos6(std::string("5"));
    std::cout << "-999 < 5: " << ((ctLTPos5 < ctLTPos6) ? "true" : "false") << '\n';

    HugeNumber ctLTPos7(std::string("255555"));
    HugeNumber ctLTPos8(std::string("-99"));
    std::cout << "255555 < -99: " << ((ctLTPos7 < ctLTPos8) ? "true" : "false") << '\n';

    HugeNumber ctLTPos9(std::string("-9999"));
    HugeNumber ctLTPos10(std::string("-9998"));
    std::cout << "-9999 < -9998: " << ((ctLTPos9 < ctLTPos10) ? "true" : "false") << '\n';


    // Greater Than
    HugeNumber gt1(std::string("12345"));
    HugeNumber gt2(std::string("12344"));
    std::cout << "12345 > 12344: " << ((gt1 > gt2) ? "true" : "false") << '\n';

    // Less Than Equal
    HugeNumber lte1(std::string("123"));
    HugeNumber lte2(std::string("124"));
    std::cout << "123 <= 124: " << ((lte1 <= lte2) ? "true" : "false") << '\n';
    HugeNumber lte3(std::string("123"));
    HugeNumber lte4(std::string("-124"));
    std::cout << "123 <= -124: " << ((lte3 <= lte4) ? "true" : "false") << '\n';
    HugeNumber lte5(std::string("123"));
    HugeNumber lte6(std::string("123"));
    std::cout << "123 <= 123: " << ((lte5 <= lte6) ? "true" : "false") << '\n';

    // Greater Than Equal
    HugeNumber gte1(std::string("124"));
    HugeNumber gte2(std::string("123"));
    std::cout << "124 >= 123: " << ((gte1 >= gte2) ? "true" : "false") << '\n';
    HugeNumber gte3(std::string("-124"));
    HugeNumber gte4(std::string("123"));
    std::cout << "-124 >= 123: " << ((gte3 >= gte4) ? "true" : "false") << '\n';
    HugeNumber gte5(std::string("123"));
    HugeNumber gte6(std::string("123"));
    std::cout << "123 >= 123: " << ((gte5 >= gte6) ? "true" : "false") << '\n';

    // Prefix increment
    HugeNumber x(std::string("999"));
    std::cout << "++x: " << ++x << "\n";        // print: 1000
    std::cout << "x++: " << x++ << "\n";        // print: 1000, x = 1001;
    std::cout << "x: " << x << "\n";
    std::cout << "--x: " << --x << "\n";        // print: 1000
    std::cout << "x--: " << x-- << "\n";        // print: 1000, x = 999;
    std::cout << "x: " << x << "\n";

    // operator~
    HugeNumber reverseTest(std::string("123400"));
    std::cout << "reverse test: " << ~reverseTest << "\n";          // print: 4321

    // opreator>>
    std::cout << "Enter some huge number: ";
    HugeNumber someHugeNumber;
    std::cin >> someHugeNumber;
    std::cout << "someHugeNumber: " << someHugeNumber << "\n";

}