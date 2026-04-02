#include <iostream>
#include <stdexcept>

template <typename T>
struct nodeType
{
    T info;
    nodeType<T>* link;
};

template <typename T>
class linkedListIterator
{
public:
    linkedListIterator()
    {
        current = nullptr;
    }

    linkedListIterator(nodeType<T>* ptr)
    {
        current = ptr;
    }

    T& operator*()
    {
        return current->info;
    }

    linkedListIterator<T>& operator++()
    {
        current = current->info;
        return *this;
    }

    bool operator==(const linkedListIterator<T>& rhs) const
    {
        return (current == rhs.current);
    }

    bool operator!=(const linkedListIterator<T>& rhs) const
    {
        return (current != rhs.current);
    }

private:
    nodeType<T>* current;
};

template <typename T>
class linkedListType
{
public:
    // assignment operator=
    linkedListType<T>& operator=(const linkedListType<T>& rhs)
    {
        if (this != rhs)
        {
            copyList(rhs);
        }

        return *this;
    }

    // intilizeList
    void intializeList()
    {
        destroyList();
    }

    // isEmpty
    bool isEmpty() const
    {
        return (first == nullptr);
    }

    // print
    void print() const
    {
        nodeType<T>* curr = first;

        while (curr)
        {
            std::cout << curr->info << " ";
            curr = curr->link;
        }
    }

    // length
    int length() const
    {
        return count;
    }

    // destroyList
    void destroyList()
    {
        nodeType<T>* temp = nullptr;

        while (first)
        {
            temp = first;
            first = first->link;
            delete temp;
        }

        count = 0;
        first = nullptr;
        last = nullptr;
    }

    T front() const
    {
        if (isEmpty)
            throw std::out_of_range("List is empty, no front element");
        return first->info;
    }
    // back()

    T back() const
    {
        if (isEmpty)
            throw std::out_of_range("List is empty, no front element");
        return last->info;
    }

    //////////////////////pure virtual functions/////////////////////
    // search(NsearchItem)
    virtual bool search(const T& searchItem) const = 0;

    // insertFirst
    virtual void insertFirst(const T& newItem) = 0;

    // insert Last
    virtual void insertLast(const T& newItem) = 0;

    // delete node
    virtual void deleteNode(const T& newItem) = 0;
    //////////////////////////////////////////////////////////////////

    // begin() return iterator where current = front
    linkedListIterator<T> begin() const
    {
        return linkedListIterator<T>(first);
    }
    // end() return iterator where current = one element pass back
    linkedListIterator<T> end() const
    {
        return linkedListIterator<T>(last->next);
    }

    // default constructor
    linkedListType<T>()
    {
        count = 0;
        first = nullptr;
        last = nullptr;
    }

    // copy constructor
    linkedListType<T>(const linkedListType<T>& rhs)
    {
        first = nullptr;
        copyList(rhs);
    }

    // destructor  
    ~linkedListType<T>()
    {
        destroyList();
    }

protected:
    int count;                  // store number of elements in linked list
    nodeType<T>* first;         // pointer to first node
    nodeType<T>* last;          // pointer to last node

private:
    void copyList (const linkedListType<T>& rhs)
    {
        nodeType<T>* newNode;
        nodeType<T>* curr;
        if (first != nullptr)   // if list is not empty
        {
            destroyList();
        }
        
        if (rhs.first == nullptr)   // if rhs ll empty
        {
            count = 0;
            first = 0;
            last = 0;
        }
        else
        {
            curr = rhs.first;

            // copy first node
            newNode = new nodeType<T>();
            newNode->info = curr->info;
            newNode->link = nullptr;

            first = newNode;
            last = newNode;
            curr = curr->link;

            // copy the rest of the nodes
            while (curr)
            {
                newNode = new nodeType<T>();
                newNode->info = curr->info;
                newNode->link = nullptr;

                last->link = newNode;
                last = newNode;
                curr = curr->link;
            }
        }
    }
};

template <typename T>
class unorderedLinkedList : public linkedListType<T>
{
public:
    bool search(const T& searchItem) const override
    {
        nodeType<T>* curr = this->first;

        while (curr)
        {
            if (curr->info = searchItem)
            {
                return true;
            }

            curr = curr->link;
        }

        return false;
    }
};
