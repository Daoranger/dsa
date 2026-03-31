template <typename T>
linkedListIterator<T>::linkedListIterator()
{
    current = nullptr;
}

template <typename T>
linkedListIterator<T>::linkedListIterator(nodeType<T>* ptr)
{
    current = ptr;
}

template <typename T>
T& linkedListIterator<T>::operator*()
{
    return current->info;
}

template <typename T>
linkedListIterator<T>& linkedListIterator<T>::operator++()
{
    current = current->info;
    return *this;
}

template <typename T>
bool linkedListIterator<T>::operator==(const linkedListIterator<T>& rhs) const
{
    return (current == rhs.current);
}

template <typename T>
bool linkedListIterator<T>::operator!=(const linkedListIterator<T>& rhs) const
{
    return (current != rhs.current);
}