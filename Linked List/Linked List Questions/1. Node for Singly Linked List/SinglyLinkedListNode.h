
template <typename T>
class ListNode
{
private:
public:
    T data;
    ListNode<T> *next;

    // Constructor's.

    // Default Constructor.
    ListNode()
    {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterized Constructor.
    ListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Parameterized Constructor.
    ListNode(T data, ListNode<T> *next)
    {
        this->data = data;
        this->next = next;
    }
};