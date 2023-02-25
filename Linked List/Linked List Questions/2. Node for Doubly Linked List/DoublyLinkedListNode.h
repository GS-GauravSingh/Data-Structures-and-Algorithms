
template <typename T>
class ListNode
{
private:
public:
    T data;
    ListNode<T> *next;
    ListNode<T> *previous;

    // Constructor's.

    // Default Constructor.
    ListNode()
    {
        this->data = 0;
        this->next = NULL;
        this->previous = NULL;
    }

    // Parameterized Constructor.
    ListNode(T data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }

    // // Parameterized Constructor.
    // ListNode(T data, ListNode<T>* previous)
    // {
    //     this->data = data;
    //     this->next = NULL;
    //     this->previous = previous;
    // }

    // // Parameterized Constructor.
    // ListNode(T data, ListNode<T> *next, ListNode<T> *previous)
    // {
    //     this->data = data;
    //     this->next = next;
    //     this->previous = previous;
    // }
};