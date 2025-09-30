#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//
//  Class :         QueueX
//  Description :   Generic implementation of queue
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template <class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T);
        T Dequeue();
        void Display();
        int Count();
};

template <class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

template <class T>
void QueueX<T> :: Enqueue(T no) // InsertLast
{
    struct Queuenode<T> *temp = NULL;
    struct Queuenode<T> * newn = NULL;

    newn = new Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }

        temp->next = newn;
    }

    iCount++;
}

template <class T>
T QueueX<T> :: Dequeue()         // DeleteFirst
{
    struct Queuenode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to remove as queue is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template <class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int QueueX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         StackX
//  Description :   Generic implementation of stack
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;
};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;

    public:
        StackX();
        void Push(T);
        T Pop();
        void Display();
        int Count();
};

template<class T>
StackX<T> :: StackX()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void StackX<T> :: Push(T no) // InsertFirst
{
    struct Stacknode<T> * newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
T StackX<T> :: Pop()         // DeleteFirst
{
    struct Stacknode<T> *temp = NULL;
    T value;

    if(first == NULL)
    {
        cout<<"Unable to pop as stack is empty\n";
        return NULL;
    }
    else
    {
        temp = first;
        value = temp->data;

        first = first -> next;
        delete temp;

        iCount--;

        return value;
    }
}

template<class T>
void StackX<T> :: Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int StackX<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyCLL
//  Description :   Generic implementation of singly circular linked list
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }

    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)   // if(iCount == 0)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;

        last->next = first;
    }

    iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last->next;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = first;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != last ->next);
    
    cout<<"\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        iCount++;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyCLL
//  Description :   Generic implementation of doubly cirular Linked List
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

template <class T>
DoublyCLL<T> :: DoublyCLL()
{
    cout<<"Inside Constructor\n";
    
    first = NULL;
    last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    } 

    last->next = first;
    first->prev = last;

    iCount++;
}

template <class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;
    
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)   // LL is empty
    {
        first = newn;
        last = newn;
    }   
    else    // LL contains atleast one node
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    } 

    last->next = first;
    first->prev = last;
    
    iCount++;
}

template <class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Elements of the LinkedList are : \n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"LinkedList is empty\n";
        return;
    }

    do
    {
        cout<<"| "<< temp->data <<" | <=> ";
        temp = temp->next;   
    } while (temp != first);
    cout<<"\n";
}

template <class T>
int DoublyCLL<T> :: Count()
{
    return iCount;  
}

template <class T>
void DoublyCLL<T> :: DeleteFirst()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete first;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        first = first -> next;
        delete first->prev;     // delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T> :: DeleteLast()
{
    if(first == NULL && last == NULL)   // LL is empty
    {
        return;
    }
    else if(first == last)  // LL contains 1 node
    {
        delete last;
    
        first = NULL;
        last = NULL;
    }
    else    // LL contains more than 1 nodes
    {
        last = last -> prev;
        delete last->next;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template <class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//
//  Class :         SinglyLL 
//  Description :   Generic implementation of singly linear Linked List
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct Node
{
    T data;
    struct Node<T>* next;
};

template<class T>
class SinglyLL
{
private:
    struct Node<T>* first;
    int iCount;

public:
    SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct Node<T>* newn = new Node<T>;

    newn->data = no;
    newn->next = first;
    first = newn;

    iCount++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct Node<T>* newn = new Node<T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        struct Node<T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount+1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct Node<T>* newn = new Node<T>;
        newn->data = no;
        newn->next = NULL;

        struct Node<T>* temp = first;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }

    struct Node<T>* temp = first;
    first = first->next;
    delete temp;

    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct Node<T>* temp = first;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct Node<T>* temp = first;
        for(int i=1; i<pos-1; i++)
        {
            temp = temp->next;
        }

        struct Node<T>* target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

template<class T>
void SinglyLL<T>::Display()
{
    struct Node<T>* temp = first;
    while(temp != NULL)
    {
        cout << "| " << temp->data << " |-";
        temp = temp->next;
    }
    cout << "\n";
}

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         DoublyLL 
//  Description :   Generic implementation of doubly linear Linked List
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct DNode
{
    T data;
    struct DNode<T>* next;
    struct DNode<T>* prev;
};

template<class T>
class DoublyLL
{
private:
    struct DNode<T>* first;
    int iCount;

public:
    DoublyLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    iCount = 0;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    DNode<T>* newn = new DNode<T>;
    newn->data = no;
    newn->next = first;
    newn->prev = NULL;

    if(first != NULL)
        first->prev = newn;

    first = newn;
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    DNode<T>* newn = new DNode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        DNode<T>* temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount+1)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        DNode<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;

        DNode<T>* newn = new DNode<T>;
        newn->data = no;
        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
        return;

    DNode<T>* temp = first;
    first = first->next;

    if(first != NULL)
        first->prev = NULL;

    delete temp;
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
        return;

    if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        DNode<T>* temp = first;
        while(temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
    }

    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        DNode<T>* temp = first;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;

        DNode<T>* target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        iCount--;
    }
}

template<class T>
void DoublyLL<T>::Display()
{
    DNode<T>* temp = first;
    cout << "NULL <=> ";
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         BST 
//  Description :   Generic implementation of Binary Search Tree
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template<class T>
struct BSTNode
{
    T data;
    struct BSTNode<T>* lchild;
    struct BSTNode<T>* rchild;
};

template<class T>
class BST
{
private:
    struct BSTNode<T>* root;

public:
    BST();
    
    void Insert(T);
    void Inorder();
    void Preorder();
    void Postorder();
    bool Search(T);
    int Count();
    int CountLeafNodes();
    int CountParentNodes();

private:
    void InsertNode(struct BSTNode<T>**, T);
    void InorderTraversal(struct BSTNode<T>*);
    void PreorderTraversal(struct BSTNode<T>*);
    void PostorderTraversal(struct BSTNode<T>*);
    bool SearchNode(struct BSTNode<T>*, T, int&);
    int CountNodes(struct BSTNode<T>*);
    int CountLeaf(struct BSTNode<T>*);
    int CountParent(struct BSTNode<T>*);
};

template<class T>
BST<T>::BST()
{
    root = NULL;
}

template<class T>
void BST<T>::Insert(T no)
{
    InsertNode(&root, no);
}

template<class T>
void BST<T>::InsertNode(struct BSTNode<T>** node, T no)
{
    if(*node == NULL)
    {
        *node = new BSTNode<T>;
        (*node)->data = no;
        (*node)->lchild = NULL;
        (*node)->rchild = NULL;
        return;
    }

    if(no == (*node)->data)
    {
        cout << "Duplicate element : Unable to insert node\n";
        return;
    }
    else if(no < (*node)->data)
    {
        InsertNode(&((*node)->lchild), no);
    }
    else
    {
        InsertNode(&((*node)->rchild), no);
    }
}

template<class T>
void BST<T>::Inorder()
{
    InorderTraversal(root);
    cout << "\n";
}

template<class T>
void BST<T>::InorderTraversal(struct BSTNode<T>* node)
{
    if(node != NULL)
    {
        InorderTraversal(node->lchild);
        cout << node->data << "\t";
        InorderTraversal(node->rchild);
    }
}

template<class T>
void BST<T>::Preorder()
{
    PreorderTraversal(root);
    cout << "\n";
}

template<class T>
void BST<T>::PreorderTraversal(struct BSTNode<T>* node)
{
    if(node != NULL)
    {
        cout << node->data << "\t";
        PreorderTraversal(node->lchild);
        PreorderTraversal(node->rchild);
    }
}

template<class T>
void BST<T>::Postorder()
{
    PostorderTraversal(root);
    cout << "\n";
}

template<class T>
void BST<T>::PostorderTraversal(struct BSTNode<T>* node)
{
    if(node != NULL)
    {
        PostorderTraversal(node->lchild);
        PostorderTraversal(node->rchild);
        cout << node->data << "\t";
    }
}

template<class T>
bool BST<T>::Search(T no)
{
    int timeComplexity = 0;
    return SearchNode(root, no, timeComplexity);
}

template<class T>
bool BST<T>::SearchNode(struct BSTNode<T>* node, T no, int &timeComplexity)
{
    while(node != NULL)
    {
        if(no == node->data)
        {
            cout << "Time complexity of search is : " << timeComplexity << "\n";
            return true;
        }
        else if(no < node->data)
            node = node->lchild;
        else
            node = node->rchild;

        timeComplexity++;
    }

    cout << "Time complexity of search is : " << timeComplexity << "\n";
    return false;
}

template<class T>
int BST<T>::Count()
{
    return CountNodes(root);
}

template<class T>
int BST<T>::CountNodes(struct BSTNode<T>* node)
{
    if(node == NULL)
        return 0;
    return 1 + CountNodes(node->lchild) + CountNodes(node->rchild);
}

template<class T>
int BST<T>::CountLeafNodes()
{
    return CountLeaf(root);
}

template<class T>
int BST<T>::CountLeaf(struct BSTNode<T>* node)
{
    if(node == NULL)
        return 0;
    if(node->lchild == NULL && node->rchild == NULL)
        return 1;
    return CountLeaf(node->lchild) + CountLeaf(node->rchild);
}

template<class T>
int BST<T>::CountParentNodes()
{
    return CountParent(root);
}

template<class T>
int BST<T>::CountParent(struct BSTNode<T>* node)
{
    if(node == NULL)
        return 0;
    if(node->lchild != NULL || node->rchild != NULL)
        return 1 + CountParent(node->lchild) + CountParent(node->rchild);
    return 0;
}


///////////////////////////////////////////////////////////////////////
//
//  Class :         Sorting 
//  Description :   Generic implementation of sorting algorithms
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////


template<class T>
class ArrayX
{
public:
    T* Arr;
    int iSize;
    bool Sorted;

    ArrayX(int no)
    {
        iSize = no;
        Arr = new T[iSize];
        Sorted = true;
    }

    ~ArrayX()
    {
        delete[] Arr;
    }

    void Accept()
    {
        cout << "Enter " << iSize << " elements : \n";
        for(int i = 0; i < iSize; i++)
        {
            cout << "Enter element " << i+1 << " : ";
            cin >> Arr[i];

            if((i > 0) && Sorted)
            {
                if(Arr[i] < Arr[i-1])
                    Sorted = false;
            }
        }
    }

    void Display()
    {
        cout << "Elements of the array are : \n";
        for(int i = 0; i < iSize; i++)
        {
            cout << Arr[i] << "\t";
        }
        cout << "\n";
    }

    void BubbleSort()
    {
        if(Sorted) return;

        for(int i = 0; i < iSize; i++)
        {
            for(int j = 0; j < iSize - 1; j++)
            {
                if(Arr[j] > Arr[j+1])
                    swap(Arr[j], Arr[j+1]);
            }

            cout << "Data after Pass : " << i+1 << "\n";
            Display();
        }
    }

    void BubbleSortEfficient()
    {
        if(Sorted) return;

        bool bFlag = true;

        for(int i = 0; (i < iSize && bFlag); i++)
        {
            bFlag = false;
            for(int j = 0; j < iSize - 1 - i; j++)
            {
                if(Arr[j] > Arr[j+1])
                {
                    swap(Arr[j], Arr[j+1]);
                    bFlag = true;
                }
            }
            cout << "Data after Pass : " << i+1 << "\n";
            Display();
        }
    }

    void SelectionSort()
    {
        for(int i = 0; i < iSize - 1; i++)
        {
            int min_index = i;
            for(int j = i+1; j < iSize; j++)
            {
                if(Arr[j] < Arr[min_index])
                    min_index = j;
            }
            if(i != min_index)
                swap(Arr[i], Arr[min_index]);
        }
    }

    void InsertionSort()
    {
        for(int i = 1; i < iSize; i++)
        {
            T selected = Arr[i];
            int j = i - 1;
            while(j >= 0 && Arr[j] > selected)
            {
                Arr[j+1] = Arr[j];
                j--;
            }
            Arr[j+1] = selected;
        }
    }
};


///////////////////////////////////////////////////////////////////////
//
//  Class :         Searching 
//  Description :   Generic implementation of searching algorithms
//  Author :        Akshaykumar Patil
//
///////////////////////////////////////////////////////////////////////

template<class T>
class ArrayX
{
public:
    T* Arr;
    int iSize;
    bool Sorted;

    ArrayX(int no)
    {
        iSize = no;
        Arr = new T[iSize];
        Sorted = true;
    }

    ~ArrayX()
    {
        delete[] Arr;
    }

    void Accept()
    {
        cout << "Enter " << iSize << " elements : \n";
        for(int i = 0; i < iSize; i++)
        {
            cout << "Enter element " << i+1 << " : ";
            cin >> Arr[i];

            if((i > 0) && Sorted)
            {
                if(Arr[i] < Arr[i-1])
                    Sorted = false;
            }
        }
    }

    void Display()
    {
        cout << "Elements of the array are : \n";
        for(int i = 0; i < iSize; i++)
        {
            cout << Arr[i] << "\t";
        }
        cout << "\n";
    }

    bool LinearSearch(T no)
    {
        if(Sorted)
        {
            cout << "Data is sorted\n";
            return BinarySearchEfficientInc(no);
        }

        for(int i = 0; i < iSize; i++)
        {
            if(Arr[i] == no)
                return true;
        }

        return false;
    }

    bool BiDirectionalSearch(T no)
    {
        int iStart = 0, iEnd = iSize - 1;

        while(iStart <= iEnd)
        {
            if(Arr[iStart] == no || Arr[iEnd] == no)
                return true;
            iStart++;
            iEnd--;
        }

        return false;
    }

    bool BinarySearchInc(T no)
    {
        int iStart = 0, iEnd = iSize - 1, iMid;
        while(iStart <= iEnd)
        {
            iMid = iStart + (iEnd - iStart) / 2;

            if(Arr[iMid] == no) return true;
            else if(no < Arr[iMid]) iEnd = iMid - 1;
            else iStart = iMid + 1;
        }
        return false;
    }

    bool BinarySearchDec(T no)
    {
        int iStart = 0, iEnd = iSize - 1, iMid;
        while(iStart <= iEnd)
        {
            iMid = iStart + (iEnd - iStart) / 2;

            if(Arr[iMid] == no) return true;
            else if(no > Arr[iMid]) iEnd = iMid - 1;
            else iStart = iMid + 1;
        }
        return false;
    }

    bool BinarySearchEfficientInc(T no)
    {
        if(!Sorted)
        {
            cout << "Data is not sorted\n";
            return LinearSearch(no);
        }

        int iStart = 0, iEnd = iSize - 1, iMid;
        while(iStart <= iEnd)
        {
            iMid = iStart + (iEnd - iStart) / 2;

            if(Arr[iMid] == no || Arr[iStart] == no || Arr[iEnd] == no)
                return true;
            else if(no < Arr[iMid]) iEnd = iMid - 1;
            else iStart = iMid + 1;
        }
        return false;
    }

    bool CheckSortedInc()
    {
        for(int i = 0; i < iSize - 1; i++)
        {
            if(Arr[i] > Arr[i+1])
                return false;
        }
        return true;
    }

    bool CheckSortedDec()
    {
        for(int i = 0; i < iSize - 1; i++)
        {
            if(Arr[i] < Arr[i+1])
                return false;
        }
        return true;
    }
};


int main()
{
    
    return 0;
}