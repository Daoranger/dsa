#include <iostream>

class Node
{
public:
    Node(int value) : data(value) {}
    int data;
    Node* next;
};

void printLL(Node* head)
{
    Node* current = head;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << "\n";
}

Node* reverseIterative(Node* head)
{
    if (!head) return nullptr;

    Node* dummy = nullptr;

    while (head)
    {
        Node* next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }

    return dummy;
}

Node* reverseRecursive(Node* head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

int main()
{
    Node* head = nullptr;
    Node* node1 = new Node(11);
    Node* node2 = new Node(12);
    Node* node3 = new Node(13);
    Node* node4 = new Node(14);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;

    printLL(head);

    head = reverseIterative(head);

    printLL(head);

    head = reverseRecursive(head);

    printLL(head);

    return 0;
}