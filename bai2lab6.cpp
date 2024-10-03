struct Node
{
    int data;
    Node* pNext;
};

struct List
{
    Node* pHead;
    Node* pTail;
};

void Init(List &l)
{
    l.pHead = nullptr;
    l.pTail = nullptr;
}

void AppendList(List &l, int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        Node* newNode = new Node;
        newNode->data = arr[i];
        newNode->pNext = nullptr;

        if (l.pHead == nullptr)
        {
            l.pHead = newNode;
            l.pTail = newNode;
        }
        else
        {
            l.pTail->pNext = newNode;
            l.pTail = newNode;
        }
    }
}

int RemoveNodesK(List &l, int k)
{
    Node* current = l.pHead;
    Node* previous = nullptr;
    int count = 0;

    while (current != nullptr)
    {
        if (current->data == k)
        {
            Node* temp = current;
            if (previous == nullptr) 
            {
                l.pHead = current->pNext;
                if (l.pHead == nullptr) 
                {
                    l.pTail = nullptr;
                }
            }
            else 
            {
                previous->pNext = current->pNext;
                if (current->pNext == nullptr) 
                {
                    l.pTail = previous;
                }
            }

            current = current->pNext;
            delete temp;
            count++;
        }
        else
        {
            previous = current;
            current = current->pNext;
        }
    }
    return count; 
}
