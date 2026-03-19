#include <iostream>

class A 
{

public:
    
    A(int v) : value(v) {}
    A& operator+=(int n)
    {
        value += n;
        return *this;
    }

    A operator+=(int n)
    {
        value += n;
        return *this;
    }

private:
    int value;
};

int main()
{
    
}

