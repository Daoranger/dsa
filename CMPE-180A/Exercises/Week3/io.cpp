#include <fstream>
#include <iostream>

int main()
{
    using namespace std;

    // Example 1: simple ifstream and ofstream
    /*
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("in.txt");
    out_stream.open("out.txt");

    int first, second, third;
    in_stream >> first >> second >> third;
    out_stream << "Hello my name is Hoang Nguyen\n";

    std::cout << "first=" << first << " second=" << second << " third=" << third << "\n";
    */

    ifstream in_stream;

    in_stream.open("story.txt");

    if (in_stream.fail())
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }
}

