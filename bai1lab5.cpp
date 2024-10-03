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

int RemoveHead(List &l)
{
    if (l.pHead == nullptr) 
    {
        return 0;
    }

    Node* temp = l.pHead;
    int removedValue = temp->data;

    l.pHead = l.pHead->pNext;

    if (l.pHead == nullptr)
    {
        l.pTail = nullptr;
    }

    delete temp; 

    return removedValue;
}
