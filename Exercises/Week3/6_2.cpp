#include <iostream>
#include <fstream>

int main()
{
    // 1) format output to screen
    // std::cout.setf(std::ios::fixed);
    // std::cout.setf(std::ios::showpoint);
    // std::cout.precision(2);
    //
    // std::cout << 3.14124124124 << "\n";

    // 2) format output to a file with out-file stream
    // std::ofstream outStream;
    // outStream.setf(std::ios::fixed);
    // //outStream.setf(std::ios::showpoint);
    // //outStream.precision(2);
    //
    // outStream.open("test.txt");
    // outStream << 3.1490000 << "\n";

    // 3) set flags
    // setf(std::ios::fixed);
    // setf(std::ios:showpoint);
    // precision(int);

    // 4) unsettting flags
    // cout.unsetf(ios::showpos)

    std::ifstream ifStream;
    ifStream.open("infile.dat");

    double sum {};
    double next {};
    int count {};

    while (ifStream >> next)
    {
        sum += next;
        ++count;
    }

    double average { sum / count };

    std::cout << "avg=" << average << "\n";

}