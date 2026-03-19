#include <iostream>
#include <fstream>
#include <cstdlib>

int main()
{

    // 1) cin and cout
    using std::cin;
    using std::cout;

    cout << "Hello world\n";

    int age {};

    cout << "Enter your age: ";
    cin >> age;

    // 2) input file stream variable
    using std::ifstream;
    ifstream in_stream;

    // 3) output file stream variable
    using std::ofstream;
    ofstream out_stream;

    // 4) input to a file
    in_stream.open("infile.dat");
    if (!in_stream)
    {
        std::cerr << "Input file open failed\n";
        //exit(1);
    }
    int a, b, c, d, e;
    in_stream >> a >> b >> c >> d >> e;
    cout << a << " "
            << b << " "
            << c << " "
            << d << " "
            << e << "\n";

    // 5) output to a file
    // out_stream.open("outfile.dat");
    // if (!out_stream)
    // {
    //     std::cerr << "Output file open failed\n";
    //     exit(1);
    // }
    // out_stream << "Hello this is Hoang!\n";

    // 6) Halting execution
    // using std::exit;
    //exit(0);

    // 7) Using fail and exit
    // in_stream.open("stuff.dat");
    // if (in_stream.fail())
    // {
    //     cout << "stuff.dat file open failed\n";
    //     exit(1);
    // }

    // 8) Appending Data
    // use constant ios::app
    // using std::ios;
    // ofstream outStream;
    // outStream.open("important.txt", ios::app);
    // outStream << "\nadded after Hello\n";

    // 9) User input filename
    char file_name[16];
    cout << "Enter the file_name ";
    cin >> file_name;
    ifstream inStream;
    inStream.open(file_name);
    if (inStream.fail())
    {
        cout << "Input file opening failed.\n";
    }


}