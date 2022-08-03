#include <iostream>
#include <string.h>
#include <stdbool.h>
using namespace std;

// Structure used for Linked-List,Stack and Queue.
template <class T>
struct node
{
    T data;
    struct node *prev;
    struct node *next;
};

// Structure used for Binary Search Tree.
template <class T>
struct nodet
{
    T data;
    struct nodet *lchild;
    struct nodet *rchild;
};

void Authentication() // Function to Entering correct Password for verification
{
    static int iCnt = 0;
    char arr[20];

    if (iCnt == 3)
    {
        cout << "You Entered Wrong Password 3 times..Sorry!\n";
        exit(0);
    }

    cout << "Enter Correct Password:";
    cin >> arr;

    if (stricmp(arr, "omkar") == 0)
    {
        cout << "Welcome to STL Application..!\n\n";
    }
    else
    {
        iCnt++;
        cout << "Sorry..Wrong Password!\n";
        Authentication();
    }
}
///////////////////////////////////////////////SINGLY LINEAR LINKEDLIST////////////////////////////////////////////////////

// Declarations
template <class T>
class SinglyLL
{
private:
    int iSize;
    struct node<T> *Head;

public:
    SinglyLL();
    ~SinglyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int Count();
    void Display();
    int FirstOcc(T);
    int LastOcc(T);
    int NumberofOcc(T);
    int Reverse();
};

template <class T>
SinglyLL<T>::SinglyLL() // Constructor of SinglyLL
{
    iSize = 0;
    Head = NULL;
}

template <class T>
SinglyLL<T>::~SinglyLL() // Destructor of SinglyLL
{
    cout << "Destructor Calls";
    struct node<T> *temp = Head;

    for (int i = 0; i < iSize; i++)
    {
        delete temp;
        temp = temp->next;
    }
}

template <class T>
void SinglyLL<T>::InsertFirst(T iNo) // InsertNode atFirst of SinglyLL
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
    }

    else // if LL contains atleast one node
    {
        newn->next = Head;
        Head = newn;
    }
    iSize++;
}

template <class T>
void SinglyLL<T>::InsertLast(T iNo) // insertNode atEnd of SinglyLL
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (Head == NULL) // if LL is empty
    {
        Head = newn;
    }

    else // if LL contains atleast one node
    {
        while (temp->next != NULL) // Travels till last of LL
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T iNo, int iPos) // Insert Node at any random position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if ((iPos < 0) || (iPos > iSize + 1)) // if position is Invalid
    {
        cout << "Sorry..Position is Invalid..!";
        return;
    }

    else if (iPos == 1) // If position is First
    {
        InsertFirst(iNo);
    }

    else if (iPos == iSize + 1) // If position is Last
    {
        InsertLast(iNo);
    }

    else // if random position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is Empty
    {
        cout << "Linked-List is Already Empty..!";
        return;
    }

    else if (Head->next == NULL) // if LL conatins Single Node
    {
        delete Head;
        Head = NULL;
        iSize = 0;
    }

    else // if LL conatins more than one node
    {
        Head = Head->next;
        delete temp;
        iSize--;
    }
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is Empty
    {
        cout << "Linked List is Already Empty..!";
        return;
    }

    else if (Head->next == NULL) // if LL contains only one node
    {
        delete Head;
        Head = NULL;
        iSize = 0;
    }

    else // if LL conatins more than one node
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        iSize--;
    }
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos) // Delete node at perticular position
{
    struct node<T> *temp = Head;
    struct node<T> *target = NULL;

    if ((iPos < 1) || (iPos > iSize)) // if Position is Invalid
    {
        cout << "Sorry..Invalid Position..!";
        return;
    }

    else if (iPos == 1) // if position is first
    {
        DeleteFirst();
    }

    else if (iPos == iSize) // if position is Last
    {
        DeleteLast();
    }

    else // if position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        iSize--;
    }
}

template <class T>
int SinglyLL<T>::Count() // Count Total Numbers of Node
{
    return iSize;
}

template <class T>
void SinglyLL<T>::Display() // Display All Nodes
{
    struct node<T> *temp = Head;

    if (temp == NULL)
    {
        cout << "Linked-List is Empty..!";
        return;
    }

    for (int i = 0; i < iSize; i++)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "NULL";
}

template <class T>
int SinglyLL<T>::FirstOcc(T iNo) // Count First Occarance of Node
{
    int iCnt1 = 0, iCnt2 = 0;
    struct node<T> *temp = Head;

    if (temp == NULL) // if LL is Empty
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
                break;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int SinglyLL<T>::LastOcc(T iNo) // Count Last Occarance of Node
{
    struct node<T> *temp = Head;
    int iCnt1 = 0, iCnt2 = 0;

    if (temp == NULL)
    {
        return -1;
    }
    else
    {

        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int SinglyLL<T>::NumberofOcc(T iNo) // Count the element number of times occurs
{
    int iCnt = 0;
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < iSize; i++)
        {
            if (temp->data == iNo)
            {
                iCnt++;
            }
            temp = temp->next;
        }
    }
    return iCnt;
}

template <class T>
int SinglyLL<T>::Reverse() // reverse the LL
{
    struct node<T> *prev = NULL;
    struct node<T> *curr = Head;
    struct node<T> *nextX = NULL;

    if (curr == NULL)
    {
        return -1;
    }
    else
    {
        while (curr != NULL)
        {
            nextX = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextX;
        }
        Head = prev;
        return 0;
    }
}

//////////////////////////////////////////SINGLY CIRCULAR LINKED-LIST///////////////////////////////////
// Declarations
template <class T>
class SinglyCL
{
private:
    int iSize;
    struct node<T> *Head;
    struct node<T> *Tail;

public:
    SinglyCL();
    ~SinglyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int Count();
    void Display();
    int FirstOcc(T);
    int LastOcc(T);
    int NumberofOcc(T);
    int Reverse();
};

template <class T>
SinglyCL<T>::SinglyCL() // constructor
{
    iSize = 0;
    Head = NULL;
    Tail = NULL;
}

template <class T>
SinglyCL<T>::~SinglyCL() // destructor
{
    struct node<T> *temp = Head;

    for (int i = 0; i < iSize; i++)
    {
        delete temp;
        temp = temp->next;
    }
}

template <class T>
void SinglyCL<T>::InsertFirst(T iNo) // Insert Node at first position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
        Tail = newn;
    }

    else // if LL contains one or more node
    {
        newn->next = Head;
        Head = newn;
    }
    iSize++;
    Tail->next = Head;
}

template <class T>
void SinglyCL<T>::InsertLast(T iNo) // Insert Node at Last Position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
        Tail = newn;
    }

    else // if LL contains more than 1 node
    {
        Tail->next = newn;
        Tail = newn;
    }
    iSize++;
    Tail->next = Head;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T iNo, int iPos) // Insert node at any position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if ((iPos < 1) || (iPos > iSize + 1)) // if Invalid position
    {
        cout << "Sorry..Position is Invalid..!";
    }

    else if (iPos == 1) // if Position is first
    {
        InsertFirst(iNo);
    }

    else if (iPos == iSize + 1) // if Position is last
    {
        InsertLast(iNo);
    }

    else // if position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iSize++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst() // Delete First node of LL
{
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        cout << "Linked-List is Already Empty..!";
        return;
    }

    else if (Head == Tail) // if LL contains only one LL
    {
        delete temp;
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }

    else // if LL contains more than one node
    {
        Head = Head->next;
        delete temp;
        iSize--;
        Tail->next = Head;
    }
}

template <class T>
void SinglyCL<T>::DeleteLast() // Delete Last node of LL
{
    struct node<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) // if LL is Empty
    {
        cout << "Linked-List is Already Empty..!";
        return;
    }

    else if (Head == Tail) // if LL contains only one LL
    {
        delete temp;
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }

    else // if LL contains more than one node
    {
        for (int i = 1; i < iSize - 1; i++)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        iSize--;
        Tail->next = Head;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos) // Delete node at any position
{
    struct node<T> *temp = Head;
    struct node<T> *target = NULL;

    if ((iPos < 1) || (iPos > iSize)) // if Invalid position
    {
        cout << "Sorry..Position is Invalid..!";
        return;
    }

    else if (iPos == 1) // if Position is first
    {
        DeleteFirst();
    }

    else if (iPos == iSize) // if Position is last
    {
        DeleteLast();
    }

    else // if position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
        iSize--;
    }
}

template <class T>
int SinglyCL<T>::Count() // Count Total Numbers of Node
{
    return iSize;
}

template <class T>
void SinglyCL<T>::Display() // Display All Nodes
{
    struct node<T> *temp = Head;

    if (temp == NULL)
    {
        cout << "Linked-List is Empty..!";
        return;
    }

    for (int i = 0; i < iSize; i++)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

template <class T>
int SinglyCL<T>::FirstOcc(T iNo) // Count First Occarance of Node
{
    int iCnt1 = 0, iCnt2 = 0;
    struct node<T> *temp = Head;

    if (temp == NULL) // if LL is Empty
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
                break;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int SinglyCL<T>::LastOcc(T iNo) // Count Last Occarance of Node
{
    struct node<T> *temp = Head;
    int iCnt1 = 0, iCnt2 = 0;

    if (temp == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int SinglyCL<T>::NumberofOcc(T iNo) // Count the element number of times occurs
{
    int iCnt = 0;
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < iSize; i++)
        {
            if (temp->data == iNo)
            {
                iCnt++;
            }
            temp = temp->next;
        }
    }
    return iCnt;
}

template <class T>
int SinglyCL<T>::Reverse() // reverse the LL
{
    struct node<T> *prev = NULL;
    struct node<T> *curr = Head;
    struct node<T> *nextX = NULL;

    if (curr == NULL)
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < iSize; i++)
        {
            nextX = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextX;
        }
        Head = prev;
        return 0;
    }
}

//////////////////////////////////////DOUBLY LINEAR LINKED-LIST////////////////////////////////////////

// Declarations
template <class T>
class DoublyLL
{
private:
    int iSize;
    struct node<T> *Head;

public:
    DoublyLL();
    ~DoublyLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int Count();
    void Display();
    int FirstOcc(T);
    int LastOcc(T);
    int NumberofOcc(T);
    int Reverse();
};

template <class T>
DoublyLL<T>::DoublyLL() // constructor
{
    Head = NULL;
    iSize = 0;
}

template <class T>
DoublyLL<T>::~DoublyLL() // Destructor
{
    struct node<T> *temp = Head;
    for (int i = 0; i < iSize; i++)
    {
        delete temp;
        temp = temp->next;
    }
}

template <class T>
void DoublyLL<T>::InsertFirst(T iNo) // Insert Node at first position
{
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
    }

    else // if LL contains nodes
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    iSize++;
}

template <class T>
void DoublyLL<T>::InsertLast(T iNo) // Insert Node at Last Position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
    }

    else // if LL contains  node
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iSize++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos) // Insert node at any position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((iPos < 1) || (iPos > iSize + 1)) // if Invalid position
    {
        cout << "Sorry..Position is Invalid..!";
    }

    else if (iPos == 1) // if Position is first
    {
        InsertFirst(iNo);
    }

    else if (iPos == iSize + 1) // if Position is last
    {
        InsertLast(iNo);
    }

    else // if position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        iSize++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst() // Delete Node at first position
{
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        cout << "Linked-List is Empty..!";
        return;
    }

    else if (Head->next == NULL) // if LL conatains only one node
    {
        delete temp;
        Head = NULL;
        iSize = 0;
    }

    else // if LL is contains more than one node
    {
        Head = Head->next;
        delete Head->prev;
        Head->prev = NULL;
        iSize--;
    }
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        cout << "Linked-List is Empty..!";
        return;
    }

    else if (Head->next == NULL) // if LL conatains only one node
    {
        delete temp;
        Head = NULL;
        iSize = 0;
    }

    else // if LL is contains more than one node
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        iSize--;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct node<T> *temp = Head;

    if ((iPos < 1) || (iPos > iSize)) // if Invalid position
    {
        cout << "Sorry..Position is Invalid..!";
        return;
    }

    else if (iPos == 1) // if Position is first
    {
        DeleteFirst();
    }

    else if (iPos == iSize) // if Position is last
    {
        DeleteLast();
    }

    else // if position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iSize--;
    }
}

template <class T>
int DoublyLL<T>::Count() // Count total number of nodes
{
    return iSize;
}

template <class T>
void DoublyLL<T>::Display() // Display all nodes of LL
{
    struct node<T> *temp = Head;

    for (int i = 0; i < iSize; i++)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int DoublyLL<T>::FirstOcc(T iNo) // Count  First Occarnce  of node
{
    int iCnt1 = 0, iCnt2 = 0;

    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else // if LL conatins node
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
                break;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int DoublyLL<T>::LastOcc(T iNo) // Count Last Occarance  of node
{
    int iCnt1 = 0, iCnt2 = 0;

    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else // if LL contains node
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int DoublyLL<T>::NumberofOcc(T iNo) // Count the number of times node present
{
    int iCnt = 0;
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        return -1;
    }

    else // if LL contains node
    {
        for (int i = 0; i < iSize; i++)
        {
            if (temp->data == iNo)
            {
                iCnt++;
            }
            temp = temp->next;
        }
    }
    return iCnt;
}

template <class T>
int DoublyLL<T>::Reverse() // Reverse the given LL
{
    struct node<T> *curr = Head;
    struct node<T> *prev = NULL;
    struct node<T> *nextX = NULL;

    if (Head == NULL) // if LL is empty
    {
        return -1;
    }

    else // if LL contains more than one node
    {
        for (int i = 0; i < iSize; i++)
        {
            nextX = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextX;
        }
        Head = prev;
        return 0;
    }
}

//////////////////////////////////DOUBLY-CIRCULAR LINKED-LIST////////////////////////////////////////

// Declarations
template <class T>
class DoublyCL
{
private:
    int iSize;
    struct node<T> *Head;
    struct node<T> *Tail;

public:
    DoublyCL();
    ~DoublyCL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    int Count();
    void Display();
    int FirstOcc(T);
    int LastOcc(T);
    int NumberofOcc(T);
    int Reverse();
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    Head = NULL;
    Tail = NULL;
    iSize = 0;
}

template <class T>
DoublyCL<T>::~DoublyCL()
{
    struct node<T> *temp = Head;
    for (int i = 0; i < iSize; i++)
    {
        delete temp;
        temp = temp->next;
    }
}

template <class T>
void DoublyCL<T>::InsertFirst(T iNo) // Insert Node at first position
{
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL)) // if LL is Empty
    {
        Head = newn;
        Tail = newn;
    }

    else // if LL contains nodes
    {
        Head->prev = newn;
        newn->next = Head;
        Head = newn;
    }
    iSize++;
    Head->prev = Tail;
    Tail->next = Head;
}

template <class T>
void DoublyCL<T>::InsertLast(T iNo) // Insert Node at Last Position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
    }

    else // if LL contains  node
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    iSize++;
    Head->prev = Tail;
    Tail->next = Head;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T iNo, int iPos) // Insert node at any position
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if ((iPos < 1) || (iPos > iSize + 1)) // if Invalid position
    {
        cout << "Sorry..Position is Invalid..!";
    }

    else if (iPos == 1) // if Position is first
    {
        InsertFirst(iNo);
    }

    else if (iPos == iSize + 1) // if Position is last
    {
        InsertLast(iNo);
    }

    else // if position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        iSize++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst() // Delete Node at first position
{
    struct node<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) // if LL is empty
    {
        cout << "Linked-List is Empty..!";
        return;
    }

    else if (Head == Tail) // if LL conatains only one node
    {
        delete temp;
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }

    else // if LL is contains more than one node
    {
        Head = Head->next;
        delete Head->prev;
    }
    iSize--;
    Head->prev = Tail;
    Tail->next = Head;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    struct node<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL)) // if LL is empty
    {
        cout << "Linked-List is Empty..!";
        return;
    }

    else if (Head == Tail) // if LL conatains only one node
    {
        delete temp;
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }

    else // if LL is contains more than one node
    {
        Tail = Tail->prev;
        delete Tail->next;
    }
    iSize--;
    Tail->next = Head;
    Head->prev = Tail;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct node<T> *temp = Head;

    if ((iPos < 1) || (iPos > iSize)) // if Invalid position
    {
        cout << "Sorry..Position is Invalid..!";
        return;
    }

    else if (iPos == 1) // if Position is first
    {
        DeleteFirst();
    }

    else if (iPos == iSize) // if Position is last
    {
        DeleteLast();
    }

    else // if position is in between
    {
        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iSize--;
    }
}

template <class T>
int DoublyCL<T>::Count() // Count total number of nodes
{
    return iSize;
}

template <class T>
void DoublyCL<T>::Display() // Count total nodes
{
    struct node<T> *temp = Head;

    if ((Head == NULL) && (Tail == NULL))
    {
        cout << "Linked-List is Already Empty..!";
        return;
    }

    else
    {
        for (int i = 0; i < iSize; i++)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }
}

template <class T>
int DoublyCL<T>::FirstOcc(T iNo) // Count  First Occarnce  of node
{
    int iCnt1 = 0, iCnt2 = 0;

    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else // if LL conatins node
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
                break;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int DoublyCL<T>::LastOcc(T iNo) // Count Last Occarance  of node
{
    int iCnt1 = 0, iCnt2 = 0;

    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else // if LL contains node
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
            }
            temp = temp->next;
        }
    }
    return iCnt2;
}

template <class T>
int DoublyCL<T>::NumberofOcc(T iNo) // Count the number of times node present
{
    int iCnt = 0;
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        return -1;
    }

    else // if LL contains node
    {
        for (int i = 0; i < iSize; i++)
        {
            if (temp->data == iNo)
            {
                iCnt++;
            }
            temp = temp->next;
        }
    }
    return iCnt;
}

template <class T>
int DoublyCL<T>::Reverse() // Reverse the given LL
{
    struct node<T> *curr = Head;
    struct node<T> *prev = NULL;
    struct node<T> *nextX = NULL;

    if ((Head == NULL) && (Tail == NULL)) // if LL is empty
    {
        return -1;
    }

    else // if LL contains more than one node
    {
        for (int i = 0; i < iSize; i++)
        {
            nextX = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextX;
        }
        Head = prev;
        return 0;
    }
}

//////////////////////////////////////STACK USING LINKED-LIST////////////////////////

// Decalarations
template <class T>
class StackLL
{
private:
    struct node<T> *Head;
    int iSize;

public:
    StackLL();
    ~StackLL();
    void Push(T);
    int Pop();
    int Peek();
    int Count();
    void Display();
    int FirstOcc(T);
    int LastOcc(T);
    int NumberofOcc(T);
    int Reverse();
};

template <class T>
StackLL<T>::StackLL() // Constructor
{
    Head = NULL;
    iSize = 0;
}

template <class T>
StackLL<T>::~StackLL() // Destructor
{
    struct node<T> *temp = Head;

    for (int i = 0; i < iSize; i++)
    {
        delete temp;
        temp = temp->next;
    }
}

template <class T>
void StackLL<T>::Push(T iNo) // Insert Element at LAst
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
    }

    else // if LL contains more than one node
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iSize++;
}

template <class T>
int StackLL<T>::Pop() // Delete node at First
{
    struct node<T> *temp = Head;
    int iRet = -1;

    if (Head == NULL) // if LL is empty
    {
        cout << "Stack is  Empty..!";
        return iRet;
    }

    else if (Head->next == NULL) // if LL contains only one node
    {
        Head = Head->next;
        iRet = temp->data;
        delete temp;
        iSize--;
        return iRet;
    }

    else // if LL contains one or more node
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        iRet = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        iSize--;
        return iRet;
    }
}

template <class T>
int StackLL<T>::Peek() // Element at top
{
    if (Head == NULL)
    {
        cout << "Stack is Empty..!";
        return -1;
    }
    else
    {
        return Head->data;
    }
}

template <class T>
int StackLL<T>::Count() // Count total Nodes
{
    return iSize;
}

template <class T>
void StackLL<T>::Display() // Display the node elements
{
    struct node<T> *temp = Head;

    for (int i = 0; i < iSize; i++)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int StackLL<T>::FirstOcc(T iNo) // Count First occuarnce of node
{
    struct node<T> *temp = Head;
    int iCnt1 = 0, iCnt2 = 0;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
                break;
            }
            temp = temp->next;
        }
        return iCnt2;
    }
}

template <class T>
int StackLL<T>::LastOcc(T iNo) // Count Last occuarnce of node
{
    struct node<T> *temp = Head;
    int iCnt1 = 0, iCnt2 = 0;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
            }
            temp = temp->next;
        }
        return iCnt2;
    }
}

template <class T>
int StackLL<T>::NumberofOcc(T iNo) // Count number of times node is occures
{
    struct node<T> *temp = Head;
    int iCnt = 0;

    if (Head == NULL)
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < iSize; i++)
        {
            if (temp->data == iNo)
            {
                iCnt++;
            }
            temp = temp->next;
        }
    }
    return iCnt;
}

template <class T>
int StackLL<T>::Reverse() // Reverse the LL
{
    struct node<T> *curr = Head;
    struct node<T> *prev = NULL;
    struct node<T> *nextX = NULL;

    if (Head == NULL) // if LL is empty
    {
        cout << "Stack is already Empty..!";
        return -1;
    }

    else // if LL conatins node
    {
        for (int i = 0; i < iSize; i++)
        {
            nextX = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextX;
        }
    }
    Head = prev;
    return 0;
}
/////////////////////////////////////STACK WITH ARRAY//////////////////////////////////////

// Declarations
template <class T>
class StackA
{
private:
    T *arr;
    int iTop;
    int iSize;

public:
    StackA();
    ~StackA();
    void ArraySize(int);
    void Push(T);
    int Pop();
    int Peek();
    int Count();
    void Display();
    int FirstOcc(T);
    int LastOcc(T);
    int NumberofOcc(T);
    void Reverse();
};

template <class T>
void StackA<T>::ArraySize(int iNo) // to create memory for all elements
{
    cout << "Enter Elements:";
    arr = new int[iNo];
    iSize = iNo;
}

template <class T>
StackA<T>::StackA() // Construuctor
{
    iTop = -1;
}

template <class T>
StackA<T>::~StackA() // Destructor
{
    for (int i = 0; i < iSize; i++)
    {
        delete[] arr;
    }
}

template <class T>
void StackA<T>::Push(T iNo) // push element is in stack
{
    if (iTop == iSize - 1) // if Stack is full
    {
        cout << "Stack is Overflow..!";
        return;
    }

    else // is Stack has space
    {
        iTop++;
        arr[iTop] = iNo;
    }
}

template <class T>
int StackA<T>::Pop() // pop element in stack
{
    if (iTop == -1) // if Stack is empty
    {
        cout << "Stack is Underflow..!";
        return -1;
    }

    else // if stack has space
    {
        int iNo = arr[iTop];
        iTop--;
        return iNo;
    }
}

template <class T>
int StackA<T>::Peek() // Element at top
{
    int iNo = 0;
    if (iTop == -1) // if Stack is empty
    {
        cout << "Stack is Empty..!";
        return 0;
    }
    else // if stack contains element
    {
        iNo = arr[iTop];
    }
    return iNo;
}

template <class T>
int StackA<T>::Count() // total number of element in stack
{
    int iCnt = 0;
    for (int i = 0; i <= iTop; i++)
    {
        iCnt++;
    }
    return iCnt;
}

template <class T>
void StackA<T>::Display() // Display elements
{
    if (iTop == -1) // if stack is empty
    {
        cout << "Stack is Empty..!"
             << "\n";
        return;
    }

    else
    {
        for (int i = 0; i <= iTop; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << "\n";
    }
}

template <class T>
int StackA<T>::FirstOcc(T iNo) // Count First occ of number
{
    int iCnt = 0, iCnt2 = 0;

    if (iTop == -1) // if stack is empty
    {
        cout << "Stack is Underflow..!"
             << "\n";
        return -1;
    }

    else
    {
        iCnt++;
        for (int i = 0; i <= iTop; i++)
        {
            if (arr[i] == iNo)
            {
                iCnt2 = iCnt;
                break;
            }
        }
    }
    return iCnt2;
}

template <class T>
int StackA<T>::LastOcc(T iNo) // Count Last occ of number
{
    int iCnt = 0, iCnt2 = 0;

    if (iTop == -1) // if stack is empty
    {
        cout << "Stack is Underflow..!"
             << "\n";
        return -1;
    }

    else
    {

        for (int i = 0; i <= iTop; i++)
        {
            iCnt++;
            if (arr[i] == iNo)
            {
                iCnt2 = iCnt;
            }
        }
    }
    return iCnt2;
}

template <class T>
int StackA<T>::NumberofOcc(T iNo) // Count perticular element count
{
    int iCnt = 0;

    if (iTop == -1) // if stack is empty
    {
        cout << "Stack is Underflow..!"
             << "\n";
        return -1;
    }

    else
    {
        for (int i = 0; i <= iTop; i++)
        {
            if (arr[i] == iNo)
            {
                iCnt++;
            }
        }
    }

    return iCnt;
}

template <class T>
void StackA<T>::Reverse()
{

    if ((arr) == NULL)
    {
        cout << "Stack is Empty..!";
        return;
    }

    else
    {
        cout << "Stack Reverse Successfully..!";

        for (int i = iTop; i >= 0; i--)
        {
            cout << arr[i] << "\t";
        }
    }
}

/////////////////////////////////////QUEUE WITH LINKED-LIST///////////////////////////////

// Declarations
template <class T>
class QueueLL
{
private:
    struct node<T> *Head;
    int iSize;

public:
    QueueLL();
    ~QueueLL();
    void Enqueue(T);
    int Dequeue();
    int Count();
    void Display();
    int FirstOcc(T);
    int LastOcc(T);
    int NumberofOcc(T);
    int Reverse();
};

template <class T>
QueueLL<T>::QueueLL() // Constructor
{
    Head = NULL;
    iSize = 0;
}

template <class T>
QueueLL<T>::~QueueLL() // Destructor
{
    struct node<T> *temp = Head;
    for (int i = 0; i < iSize; i++)
    {
        delete temp;
        temp = temp->next;
    }
}

template <class T>
void QueueLL<T>::Enqueue(T iNo) // Insert node at First
{
    struct node<T> *temp = Head;
    struct node<T> *newn = new struct node<T>;
    newn->data = iNo;
    newn->next = NULL;

    if (Head == NULL) // if LL is Empty
    {
        Head = newn;
    }

    else // if LL contains nodes
    {
        newn->next = Head;
        Head = newn;
    }
    iSize++;
}

template <class T>
int QueueLL<T>::Dequeue() // Delete node at First
{
    struct node<T> *temp = Head;

    if (Head == NULL) // if LL is empty
    {
        cout << "Queue is Empty..!";
        return -1;
    }

    else if (Head->next == NULL) // if LL conatins only one node
    {
        int iRet = temp->data;
        temp = temp->next;
        delete temp;
        iSize = 0;
        return iRet;
    }

    else // if LL conatains node
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        int iRet = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        iSize--;
        return iRet;
    }
}

template <class T>
int QueueLL<T>::Count() // Count total Numbers of nodes
{
    return iSize;
}

template <class T>
void QueueLL<T>::Display() // Display all nodes of queue
{
    struct node<T> *temp = Head;

    for (int i = 0; i < iSize; i++)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int QueueLL<T>::FirstOcc(T iNo) // Count First occuarnce of node
{
    struct node<T> *temp = Head;
    int iCnt1 = 0, iCnt2 = 0;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
                break;
            }
            temp = temp->next;
        }
        return iCnt2;
    }
}

template <class T>
int QueueLL<T>::LastOcc(T iNo) // Count Last occuarnce of node
{
    struct node<T> *temp = Head;
    int iCnt1 = 0, iCnt2 = 0;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < iSize; i++)
        {
            iCnt1++;
            if (temp->data == iNo)
            {
                iCnt2 = iCnt1;
            }
            temp = temp->next;
        }
        return iCnt2;
    }
}

template <class T>
int QueueLL<T>::NumberofOcc(T iNo) // Count number of times node is occures
{
    struct node<T> *temp = Head;
    int iCnt = 0;

    if (Head == NULL) // if LL is Empty
    {
        return -1;
    }

    else
    {
        for (int i = 0; i < iSize; i++)
        {
            if (temp->data == iNo)
            {
                iCnt++;
            }
            temp = temp->next;
        }
    }
    return iCnt;
}

template <class T>
int QueueLL<T>::Reverse() // Reverse the Queue
{
    struct node<T> *curr = Head;
    struct node<T> *prev = NULL;
    struct node<T> *nextX = NULL;

    if (curr == NULL) // if Queue is empty
    {
        cout << "Queue is already Empty..!";
        return -1;
    }

    else // if queue conatins node
    {
        for (int i = 0; i < iSize; i++)
        {
            nextX = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextX;
        }
    }
    Head = prev;
    return 0;
}

////////////////////////////////////////BINARY SEARCH TREE////////////////////////////////////////////

template <class T>
class BST
{
private:
    struct nodet<T> *Head;
    int iSize;

public:
    BST();
    //~BST(struct node <T> *);
    void InsertNode(struct nodet<T> **, T);
    void InOrder(struct nodet<T> *);
    void PreOrder(struct nodet<T> *);
    void PostOrder(struct nodet<T> *);
    int Count();
    void CountParent(struct nodet<T> *, int *);
    void CountLeaf(struct nodet<T> *, int *);
    bool SearchNode(struct nodet<T> *, T);
};

template <class T>
BST<T>::BST() // Constructor
{
    Head = NULL;
    iSize = 0;
}

/*template<class T>
BST<T>::~BST(struct node <T> *temp)//Destructor
{
    for(i=0;i<iSize;i++)
    {
        delete temp;
        ~BST(temp->data);
    }

}*/

template <class T>
void BST<T>::InsertNode(struct nodet<T> **root, T iNo) // Insert node at BST
{
    struct nodet<T> *temp = Head;
    struct nodet<T> *newn = NULL;
    newn = new struct nodet<T>;
    newn->data = iNo;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if (Head == NULL) // if BST is empty
    {
        Head = newn;
        *root = Head;
        iSize++;
    }

    else // if BST conatins node
    {
        while (1)
        {
            if (iNo > temp->data) // if entered number is greater than root element
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    iSize++;
                    break;
                }
                temp = temp->rchild;
            }

            else if (iNo < temp->data) // if entered element is less than root element
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    iSize++;
                    break;
                }
                temp = temp->lchild;
            }

            else if (iNo == temp->data) // if data is duplicate
            {

                cout << "Duplicate Element Found..!";
                delete newn;
                break;
            }
        }
    }
}

template <class T>
void BST<T>::PreOrder(struct nodet<T> *temp) // Display BST in DLR
{

    if (temp != NULL) // if BST is not empty
    {
        cout << temp->data << "\t"; // D
        PreOrder(temp->lchild);     // L
        PreOrder(temp->rchild);     // R
    }
}

template <class T>
void BST<T>::InOrder(struct nodet<T> *temp) // Display BST in LDR
{

    if (temp != NULL) // if BST is not empty
    {
        InOrder(temp->lchild);      // L
        cout << temp->data << "\t"; // D
        InOrder(temp->rchild);      // R
    }
}

template <class T>
void BST<T>::PostOrder(struct nodet<T> *temp) // Display BST in LRD
{

    if (temp != NULL) // if BST is not empty
    {
        PostOrder(temp->lchild);    // L
        PostOrder(temp->rchild);    // R
        cout << temp->data << "\t"; // D
    }
}

template <class T>
int BST<T>::Count() // Count Total nodes in BST
{
    return iSize;
}

template <class T>
void BST<T>::CountParent(struct nodet<T> *temp, int *iCnt) // Count total Parent nodes
{
    if (temp != NULL)
    {
        if ((temp->lchild != NULL) || (temp->rchild != NULL))
        {
            (*iCnt)++;
        }
        CountParent(temp->lchild, iCnt);
        CountParent(temp->rchild, iCnt);
    }
}

template <class T>
void BST<T>::CountLeaf(struct nodet<T> *temp, int *iCnt) // Count total Leaf nodes
{
    if (temp != NULL)
    {
        if ((temp->lchild == NULL) && (temp->rchild == NULL))
        {
            (*iCnt)++;
        }
        CountLeaf(temp->lchild, iCnt);
        CountLeaf(temp->rchild, iCnt);
    }
}

template <class T>
bool BST<T>::SearchNode(struct nodet<T> *temp, T iNo) // Search node in BST
{
    if (temp != NULL)
    {
        if (iNo > temp->data)
        {
            return SearchNode(temp->rchild, iNo);
        }

        else if (iNo < temp->data)
        {
            return SearchNode(temp->lchild, iNo);
        }

        else if (iNo == temp->data) // if Number found
        {
            return true;
        }

        else // if Number not found
        {
            return false;
        }
    }
}

////////////////////////////MAIN FUNCTION/////////////////////////////////////////////////////

int main() // Main Entry Point Function of STL
{
    int iNo = 0, iChoice = 1, iRet = 0, iPos = 0, iSelect = 1, i = 0;
    bool bRet;
    struct nodet<int> *root = NULL;

    SinglyLL<int> slobj;
    SinglyCL<int> scobj;
    DoublyLL<int> dlobj;
    DoublyCL<int> dcobj;
    StackLL<int> stlobj;
    QueueLL<int> qobj;
    StackA<int> saobj;
    BST<int> bobj;

    Authentication();
    while (iChoice != 0)
    {
        cout << "\n__________________________________________";
        cout << "\n\n*******************************************\n\n";
        cout << "*** MAIN MENU of STANDERD TEMPLATE LIBERARY  ***";
        cout << "\n\n*******************************************\n\n";
        cout << "Enter Your Choice:"
             << "\n";
        cout << "1:Singly Linear Linked-List"
             << "\n";
        cout << "2:Singly Circular Linked-List"
             << "\n";
        cout << "3:Doubly Linear Linked-List"
             << "\n";
        cout << "4:Doubly Circular Linked-List"
             << "\n";
        cout << "5:Stack using Linked-List"
             << "\n";
        cout << "6:Stack using Array"
             << "\n";
        cout << "7:Queue using Linked-List"
             << "\n";
        cout << "8:Binary Search Tree(BST)"
             << "\n";
        cout << "0.Exit the Application"
             << "\n";
        cin >> iChoice;
        cout << "\n___________________________________________";

        switch (iChoice)
        {
        case 1:
            cout << "\nSINGLY LINEAR LINKED LIST\n";

            while (iSelect != 0)
            {
                cout << "\n_________________________\n";
                cout << "Enter your choice :"
                     << "\n";
                cout << "1  : Insert at first position "
                     << "\n";
                cout << "2  : Insert at last position "
                     << "\n";
                cout << "3  : Insert at given position "
                     << "\n";
                cout << "4  : Delete first node "
                     << "\n";
                cout << "5  : Delete last node "
                     << "\n";
                cout << "6  : Delete node at give position "
                     << "\n";
                cout << "7  : Display the contents "
                     << "\n";
                cout << "8  : Count number of nodes "
                     << "\n";
                cout << "9  : Count First Occarance of Node\n";
                cout << "10 : Count Last Occarance of Node\n";
                cout << "11 : Count Number of Times Node Occuares\n";
                cout << "12 : Reverse the Nodes\n";
                cout << "0  : Back to main Menu  "
                     << "\n";
                cout << "\n_________________________\n";
                cin >> iSelect;

                switch (iSelect)
                {
                case 1:
                    cout << "Enter number\n";
                    cin >> iNo;
                    slobj.InsertFirst(iNo);
                    break;

                case 2:
                    cout << "Enter number\n";
                    cin >> iNo;
                    slobj.InsertLast(iNo);
                    break;

                case 3:
                    cout << "Enter a Number\n";
                    cin >> iNo;
                    cout << "Enter a position\n";
                    cin >> iPos;
                    slobj.InsertAtPos(iNo, iPos);
                    break;

                case 4:
                    slobj.DeleteFirst();
                    break;

                case 5:
                    slobj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter a position\n";
                    cin >> iPos;
                    slobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    slobj.Display();
                    break;

                case 8:
                    iNo = slobj.Count();
                    cout << "Number of Nodes are : " << iNo << "\n";
                    break;

                case 9:
                    cout << "Enter Number Whose First Occurance You Want:";
                    cin >> iNo;
                    iRet = slobj.FirstOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "First Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 10:
                    cout << "Enter Number Whose Last Occurance You Want:";
                    cin >> iNo;
                    iRet = slobj.LastOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "Last Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 11:
                    cout << "Enter Number you want Count:";
                    cin >> iNo;
                    iRet = slobj.NumberofOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << iNo << " is Present at " << iRet << " of times ";
                    }
                    break;

                case 12:
                    iRet = slobj.Reverse();
                    if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "Linklist Reverse Successfully..!"
                             << "\n";
                        slobj.Display();
                    }
                    break;

                case 0:
                    cout << "Thank you for using Singly Linear Linklist application\n";
                    break;

                default:
                    cout << "Please enter proper option\n";
                    break;
                } // End of Switch(iSelect)
            }     // End of Case-1
            iSelect = 1;
            break;

        case 2:
            cout << "\nSINGLY CIRCULAR LINKED LIST\n";

            while (iSelect != 0)
            {
                cout << "\n_________________________\n";
                cout << "Enter your choice :"
                     << "\n";
                cout << "1  : Insert at first position "
                     << "\n";
                cout << "2  : Insert at last position "
                     << "\n";
                cout << "3  : Insert at given position "
                     << "\n";
                cout << "4  : Delete first node "
                     << "\n";
                cout << "5  : Delete last node "
                     << "\n";
                cout << "6  : Delete node at give position "
                     << "\n";
                cout << "7  : Display the contents "
                     << "\n";
                cout << "8  : Count number of nodes "
                     << "\n";
                cout << "9  : Count First Occarance of Node\n";
                cout << "10 : Count Last Occarance of Node\n";
                cout << "11 : Count Number of Times Node Occuares\n";
                cout << "12 : Reverse the Nodes\n";
                cout << "0  : Back to main Menu  "
                     << "\n";
                cout << "\n_________________________\n";
                cin >> iSelect;

                switch (iSelect)
                {
                case 1:
                    cout << "Enter number\n";
                    cin >> iNo;
                    scobj.InsertFirst(iNo);
                    break;

                case 2:
                    cout << "Enter number\n";
                    cin >> iNo;
                    scobj.InsertLast(iNo);
                    break;

                case 3:
                    cout << "Enter a Number\n";
                    cin >> iNo;
                    cout << "Enter a position\n";
                    cin >> iPos;
                    scobj.InsertAtPos(iNo, iPos);
                    break;

                case 4:
                    scobj.DeleteFirst();
                    cout << "Data Removed Succesfully..!";
                    break;

                case 5:
                    scobj.DeleteLast();
                    cout << "Data Removed Succesfully..!";
                    break;

                case 6:
                    cout << "Enter a position\n";
                    cin >> iPos;
                    scobj.DeleteAtPos(iPos);
                    cout << "Data Removed Succesfully..!";
                    break;

                case 7:
                    scobj.Display();
                    break;

                case 8:
                    iNo = scobj.Count();
                    cout << "Number of Nodes are : " << iNo << "\n";
                    break;

                case 9:
                    cout << "Enter Number Whose First Occurance You Want:";
                    cin >> iNo;
                    iRet = scobj.FirstOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "First Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 10:
                    cout << "Enter Number Whose Last Occurance You Want:";
                    cin >> iNo;
                    iRet = scobj.LastOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "Last Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 11:
                    cout << "Enter Number you want Count:";
                    cin >> iNo;
                    iRet = scobj.NumberofOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << iNo << " is Present at " << iRet << " of times ";
                    }
                    break;

                case 12:
                    iRet = scobj.Reverse();
                    if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "Linklist Reverse Successfully..!"
                             << "\n";
                        scobj.Display();
                    }
                    break;

                case 0:
                    cout << "Thank you for using Singly Circular Linklist application\n";
                    break;

                default:
                    cout << "Please enter proper option\n";
                    break;
                } // End of Switch(iSelect)
            }     // End of case-2
            iSelect = 1;
            break;

        case 3:
            cout << "\n DOUBLY LINEAR LINKED LIST\n";

            while (iSelect != 0)
            {
                cout << "\n_________________________\n";
                cout << "Enter your choice :"
                     << "\n";
                cout << "1  : Insert at first position "
                     << "\n";
                cout << "2  : Insert at last position "
                     << "\n";
                cout << "3  : Insert at given position "
                     << "\n";
                cout << "4  : Delete first node "
                     << "\n";
                cout << "5  : Delete last node "
                     << "\n";
                cout << "6  : Delete node at give position "
                     << "\n";
                cout << "7  : Display the contents "
                     << "\n";
                cout << "8  : Count number of nodes "
                     << "\n";
                cout << "9  : Count First Occarance of Node\n";
                cout << "10 : Count Last Occarance of Node\n";
                cout << "11 : Count Number of Times Node Occuares\n";
                cout << "12 : Reverse the Nodes\n";
                cout << "0  : Back to main Menu  "
                     << "\n";
                cout << "\n_________________________\n";
                cin >> iSelect;

                switch (iSelect)
                {
                case 1:
                    cout << "Enter number\n";
                    cin >> iNo;
                    dlobj.InsertFirst(iNo);
                    break;

                case 2:
                    cout << "Enter number\n";
                    cin >> iNo;
                    dlobj.InsertLast(iNo);
                    break;

                case 3:
                    cout << "Enter a Number\n";
                    cin >> iNo;
                    cout << "Enter a position\n";
                    cin >> iPos;
                    dlobj.InsertAtPos(iNo, iPos);
                    break;

                case 4:
                    dlobj.DeleteFirst();
                    break;

                case 5:
                    dlobj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter a position\n";
                    cin >> iPos;
                    dlobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    dlobj.Display();
                    break;

                case 8:
                    iNo = dlobj.Count();
                    cout << "Number of Nodes are : " << iNo << "\n";
                    break;

                case 9:
                    cout << "Enter Number Whose First Occurance You Want:";
                    cin >> iNo;
                    iRet = dlobj.FirstOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "First Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 10:
                    cout << "Enter Number Whose Last Occurance You Want:";
                    cin >> iNo;
                    iRet = dlobj.LastOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "Last Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 11:
                    cout << "Enter Number you want Count:";
                    cin >> iNo;
                    iRet = dlobj.NumberofOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << iNo << " is Present at " << iRet << " of times ";
                    }
                    break;

                case 12:
                    iRet = dlobj.Reverse();
                    if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "Linklist Reverse Successfully..!";
                        dlobj.Display();
                    }
                    break;

                case 0:
                    cout << "Thank you for using Doubly Linear Linklist application\n";
                    break;

                default:
                    cout << "Please enter proper option\n";
                    break;
                } // End of Switch(iSelect)
            }     // End of case-3

            iSelect = 1;
            break;

        case 4:
            cout << "\n DOUBLY CIRCULAR LINKED LIST\n";

            while (iSelect != 0)
            {
                cout << "\n_________________________\n";
                cout << "Enter your choice :"
                     << "\n";
                cout << "1  : Insert at first position "
                     << "\n";
                cout << "2  : Insert at last position "
                     << "\n";
                cout << "3  : Insert at given position "
                     << "\n";
                cout << "4  : Delete first node "
                     << "\n";
                cout << "5  : Delete last node "
                     << "\n";
                cout << "6  : Delete node at give position "
                     << "\n";
                cout << "7  : Display the contents "
                     << "\n";
                cout << "8  : Count number of nodes "
                     << "\n";
                cout << "9  : Count First Occarance of Node\n";
                cout << "10 : Count Last Occarance of Node\n";
                cout << "11 : Count Number of Times Node Occuares\n";
                cout << "12 : Reverse the Nodes\n";
                cout << "0  : Back to main Menu "
                     << "\n";
                cout << "\n_________________________\n";
                cin >> iSelect;

                switch (iSelect)
                {
                case 1:
                    cout << "Enter number\n";
                    cin >> iNo;
                    dcobj.InsertFirst(iNo);
                    break;

                case 2:
                    cout << "Enter number\n";
                    cin >> iNo;
                    dcobj.InsertLast(iNo);
                    break;

                case 3:
                    cout << "Enter a Number\n";
                    cin >> iNo;
                    cout << "Enter a position\n";
                    cin >> iPos;
                    dcobj.InsertAtPos(iNo, iPos);
                    break;

                case 4:
                    dcobj.DeleteFirst();
                    break;

                case 5:
                    dcobj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter a position\n";
                    cin >> iPos;
                    dcobj.DeleteAtPos(iPos);
                    break;

                case 7:
                    dcobj.Display();
                    break;

                case 8:
                    iNo = dcobj.Count();
                    cout << "Number of Nodes are : " << iNo << "\n";
                    break;

                case 9:
                    cout << "Enter Number Whose First Occurance You Want:";
                    cin >> iNo;
                    iRet = dcobj.FirstOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "First Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 10:
                    cout << "Enter Number Whose Last Occurance You Want:";
                    cin >> iNo;
                    iRet = dcobj.LastOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << "Last Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 11:
                    cout << "Enter Number you want Count:";
                    cin >> iNo;
                    iRet = dcobj.NumberofOcc(iNo);

                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }
                    else
                    {
                        cout << iNo << " is Present at:" << iRet << " of times ";
                    }
                    break;

                case 12:
                    iRet = dcobj.Reverse();
                    if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }

                    else
                    {
                        cout << "Linklist Reverse Successfully..!"
                             << " ";
                        dcobj.Display();
                    }

                    break;

                case 0:
                    cout << "Thank you for using Doubly Circular Linklist application\n";
                    break;

                default:
                    cout << "Please enter proper option\n";
                    break;
                } // End of Switch(iSelect)
            }     // End of case-4

            iSelect = 1;
            break;

        case 5:
            cout << "\n STACK USING LINKED-LIST\n";

            while (iSelect != 0)
            {
                printf("\n_________________________\n");
                cout << "Enter Your Choice:"
                     << "\n";
                cout << "1:Push the Element"
                     << "\n";
                cout << "2:Pop the Element"
                     << "\n";
                cout << "3:Peek the Element"
                     << "\n";
                cout << "4.Count the Number of Elements"
                     << "\n";
                cout << "5.Display the Elements"
                     << "\n";
                cout << "6:First Occarance of Element"
                     << "\n";
                cout << "7:Last Occarance of Element"
                     << "\n";
                cout << "8:Count Occarance of Perticular Element\n";
                cout << "9.Reverse the Linked List\n";
                cout << "0: Back to main Menu "
                     << "\n";
                cin >> iSelect;
                printf("\n____________________________\n");

                switch (iSelect)
                {
                case 1:
                    cout << "Enter Element You Want Push:";
                    cin >> iNo;
                    stlobj.Push(iNo);
                    cout << "Stack Updated Successfully..!";
                    break;

                case 2:
                    iRet = stlobj.Pop();
                    if (iRet == -1)
                        cout << "Stack is Empty";
                    else
                        cout << "Pop Element is:" << iRet << "\n";
                    break;

                case 3:
                    iRet = stlobj.Peek();
                    cout << "Peek Element is:" << iRet << "\n";
                    break;

                case 4:
                    iRet = stlobj.Count();
                    cout << "Total Number of nodes are:" << iRet;
                    break;

                case 5:
                    cout << "Nodes are:\n";
                    stlobj.Display();
                    break;

                case 6:
                    cout << "Enter Number Whose First Occurance You Want:";
                    cin >> iNo;
                    iRet = stlobj.FirstOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }

                    else if (iRet == -1)
                    {
                        cout << "Stack is Empty..!";
                    }

                    else
                    {
                        cout << "First Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 7:
                    cout << "Enter Number Whose Last Occurance You Want:";
                    cin >> iNo;
                    iRet = stlobj.LastOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }

                    else if (iRet == -1)
                    {
                        cout << "Stack is Empty..!";
                    }

                    else
                    {
                        cout << "Last Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 8:
                    cout << "Enter Number you want Count:";
                    cin >> iNo;
                    iRet = stlobj.NumberofOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }

                    else if (iRet == -1)
                    {
                        cout << "Stack is Empty..!";
                    }

                    else
                    {
                        cout << iNo << " is Present at " << iRet << " of times ";
                    }
                    break;

                case 9:
                    iRet = stlobj.Reverse();
                    if (iRet == -1)
                    {
                        cout << "Linked-List is Empty..!";
                    }

                    else
                    {
                        cout << "Linklist Reverse Successfully..!";
                        stlobj.Display();
                    }
                    break;

                case 0:
                    cout << "Thank you for using Stack(LL) application\n";
                    break;

                default:
                    cout << "Please enter proper option\n";
                    break;

                } // End of Switch(iSelect)
            }     // End of case-5

            iSelect = 1;
            break;

        case 6:
            cout << "\nSTACK USING ARRAY\n";
            cout << "Enter Size of Array:";
            cin >> iNo;
            saobj.ArraySize(iNo);
            while (iSelect != 0)
            {
                printf("\n_________________________\n");
                cout << "Enter Your Choice:"
                     << "\n";
                cout << "1:Push the Element"
                     << "\n";
                cout << "2:Pop the Element"
                     << "\n";
                cout << "3:Peek the Element"
                     << "\n";
                cout << "4:Count Total Number of elements"
                     << "\n";
                cout << "5.Display the Elements"
                     << "\n";
                cout << "6:First Occarance of Element"
                     << "\n";
                cout << "7:Last Occarance of Element"
                     << "\n";
                cout << "8:Count Occarance of Perticular Element\n";
                cout << "9:Display Stack in Reverse"
                     << "\n";
                cout << "0:Back to main Menu"
                     << "\n";
                cin >> iSelect;
                printf("\n____________________________\n");

                switch (iSelect)
                {
                case 1:
                    cout << "Enter Element You Want Push:";
                    cin >> iNo;
                    saobj.Push(iNo);
                    break;

                case 2:
                    iRet = saobj.Pop();
                    if (iRet == -1)
                        cout << "Stack is Empty";
                    else
                        cout << "Pop Element is:" << iRet << "\n";
                    break;

                case 3:
                    iRet = saobj.Peek();
                    cout << "Peek Element is:" << iRet << "\n";
                    break;

                case 4:
                    iRet = saobj.Count();
                    cout << "Total Number of Elements are:" << iRet;
                    break;

                case 5:
                    cout << "Nodes are:\n";
                    saobj.Display();
                    break;

                case 6:
                    cout << "Enter Number Whose First Occurance You Want:";
                    cin >> iNo;
                    iRet = saobj.FirstOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!"
                             << "\n";
                    }

                    else if (iRet == -1)
                    {
                        cout << "Stack is Empty..!";
                    }

                    else
                    {
                        cout << "First Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 7:
                    cout << "Enter Number Whose Last Occurance You Want:";
                    cin >> iNo;
                    iRet = saobj.LastOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }

                    else if (iRet == -1)
                    {
                        cout << "Stack is Empty..!";
                    }

                    else
                    {
                        cout << "Last Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 8:
                    cout << "Enter Number you want Count:";
                    cin >> iNo;
                    iRet = saobj.NumberofOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }

                    else if (iRet == -1)
                    {
                        cout << "Stack is Empty..!";
                    }

                    else
                    {
                        cout << iNo << " is Present at " << iRet << " of times ";
                    }
                    break;

                case 9:
                    saobj.Reverse();
                    break;

                case 0:
                    cout << "Thank you for using Stack(Array) Application\n";
                    break;

                default:
                    cout << "Please enter proper option\n";
                    break;

                } // End of Switch(iSelect)
            }     // End of case-6
            iSelect = 1;
            break;

        case 7:
            cout << "\nQUEUE USING LINKED-LIST\n";
            while (iSelect != 0)
            {
                printf("\n____________________________\n");
                cout << "Enter the Choice:"
                     << "\n";
                cout << "1:EnQueue the Element"
                     << "\n";
                cout << "2:DeQueue the Element"
                     << "\n";
                cout << "3:Count the Elements"
                     << "\n";
                cout << "4:Display the Elements"
                     << "\n";
                cout << "5:First Occarance of Element"
                     << "\n";
                cout << "6:Last Occarance of Element"
                     << "\n";
                cout << "7:Count Occrance of Perticlar Element"
                     << "\n";
                cout << "8:Reverse the Elements"
                     << "\n";
                cout << "0.Back to main Menu"
                     << "\n";
                cin >> iSelect;
                printf("\n_____________________________\n");

                switch (iSelect)
                {
                case 1:
                    cout << "Enter Element You Want Enqueue:";
                    cin >> iNo;
                    qobj.Enqueue(iNo);
                    cout << "Queue Updated Successfully..!";
                    break;

                case 2:
                    iRet = qobj.Dequeue();
                    if (iRet == -1)
                        cout << "Queue is Empty";
                    else
                        cout << "DeQueue Element is:" << iRet << "\n";
                    break;

                case 3:
                    iRet = qobj.Count();
                    cout << "Total Number of Elements are:" << iRet;
                    break;

                case 4:
                    cout << "Nodes are:";
                    qobj.Display();
                    break;

                case 5:
                    cout << "Enter Number Whose First Occurance You Want:";
                    cin >> iNo;
                    iRet = qobj.FirstOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Queue is Empty..!";
                    }
                    else
                    {
                        cout << "First Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 6:
                    cout << "Enter Number Whose Last Occurance You Want:";
                    cin >> iNo;
                    iRet = qobj.LastOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Queue is Empty..!";
                    }
                    else
                    {
                        cout << "Last Occurance of " << iNo << " is at " << iRet << " Position "
                             << "\n";
                    }
                    break;

                case 7:
                    cout << "Enter Number you want Count:";
                    cin >> iNo;
                    iRet = qobj.NumberofOcc(iNo);
                    if (iRet == 0)
                    {
                        cout << "Element Not Found..!";
                    }
                    else if (iRet == -1)
                    {
                        cout << "Queue is Empty..!";
                    }
                    else
                    {
                        cout << iNo << " is Present at " << iRet << " of times ";
                    }
                    break;

                case 8:
                    iRet = qobj.Reverse();
                    if (iRet == -1)
                    {
                        cout << "Queue is Empty..!";
                    }

                    else
                    {
                        cout << "Linklist Reverse Successfully..!"
                             << "\n";
                        qobj.Display();
                    }
                    break;

                case 0:
                    cout << "Thank you for using Queue(LL) application\n";
                    break;

                default:
                    cout << "Please enter proper option\n";
                    break;
                } // End of Switch(iSelect)
            }     // End of case-7

            iSelect = 1;
            break;

        case 8:
            cout << "\n BINARY SEARCH TREE(BST)\n";
            while (iSelect != 0)
            {
                printf("\n_______________________________\n");
                cout << "Enter Your Choice:"
                     << "\n";
                cout << "1.Insert Node"
                     << "\n";
                cout << "2.Display Inorder"
                     << "\n";
                cout << "3.Display Preorder"
                     << "\n";
                cout << "4.Display Postorder"
                     << "\n";
                cout << "5.Count Total Nodes"
                     << "\n";
                cout << "6.Count Parent Nodes"
                     << "\n";
                cout << "7.Count Leaf Nodes"
                     << "\n";
                cout << "8.Search Node"
                     << "\n";
                cout << "0.Exit the Application"
                     << "\n";
                cin >> iSelect;
                printf("\n____________________________________\n");

                switch (iSelect)
                {
                case 1:
                    cout << "Enter Node You Want Add:"
                         << "\n";
                    cin >> iNo;
                    bobj.InsertNode(&root, iNo);
                    break;

                case 2:
                    cout << "Nodes in Inorder sequence are:"
                         << "\n";
                    bobj.InOrder(root);
                    break;

                case 3:
                    cout << "Nodes in Preorder Sequence are:"
                         << "\n";
                    bobj.PreOrder(root);
                    break;

                case 4:
                    cout << "Nodes in Postorder Sequence are:"
                         << "\n";
                    bobj.PostOrder(root);
                    break;

                case 5:
                    iRet = bobj.Count();
                    cout << "Total Number of Nodes are:" << iRet;
                    break;

                case 6:
                    i = 0;
                    bobj.CountParent(root, &i);
                    cout << "Total Number of Parent Nodes are:" << i;
                    break;

                case 7:
                    i = 0;
                    bobj.CountLeaf(root, &i);
                    cout << "Total Number of Leaf Nodes are:" << i;
                    break;

                case 8:
                    cout << "Enter Node You Want Search:";
                    cin >> iNo;
                    bRet = bobj.SearchNode(root, iNo);
                    if (bRet == true)
                    {
                        cout << iNo << "Node is Present";
                    }
                    else
                    {
                        cout << iNo << "Node is not Present";
                    }
                    break;

                case 0:
                    cout << "Thanks for using Binary Search Tree(BST) Application"
                         << "\n";
                    break;

                default:
                    cout << "Please Select Correct option..!";
                    break;
                } // End of Switch(iSelect)
            }     // End of case-8

            iSelect = 1;
            break; // This is break for Case 8*/

        case 0:
            cout << "\n\n";
            cout << "\t\t\t**************************************************************\n";
            cout << "\t\t\t**************************************************************\n";
            cout << "\t\t\t**                                                          **\n";
            cout << "\t\t\t** THANK-YOU FOR USING CUSTOMIZED STANDARD TEMPLATE LIBAERY **\n";
            cout << "\t\t\t**                                                          **\n";
            cout << "\t\t\t**************************************************************\n";
            cout << "\t\t\t**************************************************************\n";
            exit(0);
            break;

        default:
            cout << "Please Select Proper Option..!\n";
            break;
        }
    }
    return 0;
}