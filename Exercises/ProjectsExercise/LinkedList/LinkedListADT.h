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
    linkedListIterator();

    linkedListIterator(nodeType<T>* ptr);

    T& operator*();
    // function to overload the dereferencing operator*

    linkedListIterator<T>& operator++();
    // overload the preincrement operator

    bool operator==(const linkedListIterator<T>& rhs) const;
    // return true if two iterators is equals

    bool operator!=(const linkedListIterator<T>& rhs) const;
    // return true if two iterators is not equals

private:
    nodeType<T>* current;
};

template <typename T>
class linkedListType
{

protected:
    int count;                  // store number of elements in linked list
    nodeType<T>* first;         // pointer to first node
    nodeType<T>* last;          // pointer to last node
};

#include "LinkedListADT.tpp"
