class Node
{
public:
    Node(int value) : data(value), next(nullptr) {} 
    int data;
    Node* next;
};

class Queue
{
public:
    
    //enqueue
    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    //dequeue
    void deque
    {
        if (head == nullptr) return;

        if (head == tail) 
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    //front()
    int front() const
    {
        if (isEmpty()) throw std::runtime_error("Queue is empty");
        return head->data;
    }

    //isEmpty
    bool isEmpty() const
    {
        return head == nullptr;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

};