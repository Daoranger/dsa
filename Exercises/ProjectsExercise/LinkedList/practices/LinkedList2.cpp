#include <iostream>

struct nodeType
{
    int info;
    nodeType* link;
};

void traverseList(nodeType* head)
{
    nodeType* current = head;

    while (current)
    {
        std::cout << current->info << "->";

        if (!current->link)
        {
            std::cout << "nullptr\n";
        }

        current = current->link;
    }
}

nodeType* buildListBackward()
{
    nodeType* first = nullptr;
    nodeType* newNode;
    int num;

    while (true)
    {
        std::cout << "Enter a value: ";
        std::cin >> num;
        if (num == -999)
            break;
        
        newNode = new nodeType;
        newNode->info = num;
        newNode->link = nullptr;

        if (first == nullptr)
        {
            first = newNode;
        }
        else
        {
            newNode->link = first;
            first = newNode;
        }
    }

    return first;
}

nodeType* buildListForward()
{
    nodeType* first = nullptr;
    nodeType* last = nullptr;
    nodeType* newNode;
    int num;
    
    while (true)
    {
        std::cout << "Enter a number or (-999 to stop): ";
        std::cin >> num;

        if (num == -999)
            break;

        newNode = new nodeType;
        newNode->info = num;
        newNode->link = nullptr;

        if (first == nullptr)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->link = newNode;
            last = newNode;
        }
    }

    return first;
        
}

int main()
{
    nodeType* firstBackward = buildListBackward();
    traverseList(firstBackward);

    nodeType* firstForward = buildListForward();
    traverseList(firstForward);
}