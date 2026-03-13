#include <iostream>

// Employee is "abstract base class", cannot be instantiate
class Employee
{
public:
    Employee(int id)
        : m_id(id)
    {
    }
    virtual void doSomething1() const = 0;      // pure virutal function
    void doSomething2() const;                  // non virtual function

private:
    int m_id;   // private data member
};

class Boss : public Employee
{
public:
    Boss(int id)
        : Employee(id)                          // constructor chaining/delegate constructors
    {
    }
    
    virtual void doSomething1() const             // make sure this have it own implementaiton or Boss will be consider as abstract base class
    {
        std::cout << "Boss::doSomething1()\n";
    }
};

int main()
{
    Boss boss(1);
    boss.doSomething1();
}

