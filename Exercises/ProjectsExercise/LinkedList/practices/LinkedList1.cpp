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

int main()
{
    nodeType* head;

    nodeType* node1 = new nodeType;
    node1->info = 45;

    nodeType* node2 = new nodeType;
    node2->info = 65;

    nodeType* node3 = new nodeType;
    node3->info = 34;

    nodeType* node4 = new nodeType;
    node4->info = 76;

    node1->link = node2;
    node2->link = node3;
    node3->link = node4;
    node4->link = nullptr;

    head = node1;
    traverseList(head);

    nodeType* p = node2;
    nodeType* newNode = new nodeType;
    newNode->info = 50;
    newNode->link = p->link;
    p->link = newNode;

    traverseList(head);

    // p is now at node with value 50;
    p = p->link;

    nodeType* removeNode = p->link;
    p->link = removeNode->link;
    delete removeNode;

    traverseList(head);
}