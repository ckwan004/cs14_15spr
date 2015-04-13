#include "MyList.h"

MyList::MyList()
{
    
}

MyList::MyList(const MyList& str)
{
    Node * tempNode = str.head;
    for(int i=0;i < str.size(); ++i)
    {
        push_back(tempNode->data);
        tempNode = tempNode->next;
    }
}

MyList::MyList(const string& str)
{
    const char * thing = str.c_str();
    for(int i=0;i < str.size(); ++i)
    {
        push_back(thing[i]);
    }
}

MyList::MyList(const char* str)
{
    string x = str;
    for(int i=0; i < x.size(); ++i)
    {
        push_back(*(str+i));
    }
}

MyList::~MyList()
{
    if(head->next == head)
    {
        delete head;
    }
    else
    {
        Node * tempNode = head->next;
        for(int i=0;i < size();++i)
        {
            delete head;
            head = tempNode;
            tempNode = tempNode->next;
        }
    }
}

void MyList::push_front(char value)
{
    if(head == NULL)
    {
        head = new Node(value);
        head->pred = head;
        head->next = head;
    }
    else
    {
        Node * tempNode = new Node(value);
        tempNode->pred = head->pred;
        tempNode->next = head;
        head = tempNode;
    }
    ++num;
}

void MyList::push_back(char value)
{
    if(head == NULL)
    {
        head = new Node(value);
        head->pred = head;
        head->next = head;
    }
    else if(head->next == head)
    {
        Node * tempNode = new Node(value);
        
        head->pred = tempNode;
        head->next = tempNode;
        tempNode->pred = head;
        tempNode->next = head;
    }
    else
    {
        Node * tempNode = new Node(value);
        Node * tail = head->pred;
        
        tail->next = tempNode;
        tempNode->pred = tail;
        
        head->pred = tempNode;
        tempNode->next = head;
    }
    ++num;
}

void MyList::pop_front()
{
    if(head == NULL)
    {
        
    }
    else if(head->pred == head)
    {
        delete head;
        head = NULL;
        --num;
    }
    else
    {
        Node * tempNode = head->pred;
        Node * tempNode2 = head->next;
        delete head;
        
        tempNode->next = tempNode2;
        tempNode2->pred = tempNode;
        head = tempNode2;
        --num;
    }
}

void MyList::pop_back()
{
    if(head == NULL)
    {
        
    }
    else if(head->pred == head)
    {
        delete head;
        head = NULL;
        --num;
    }
    else
    {
        Node * tempNode2 = head->pred->pred;
        Node * getRid = head->pred;
        
        head->pred = tempNode2;
        tempNode2->next = head;
        
        delete getRid;
        --num;
    }
}

void MyList::swap(int i, int j)
{
    int bigPos;
    int smallPos;
    if(size() <= i || size() <= j)
    {
        cout << "Error too big.\n";
    }
    else if(i < 0 || j < 0)
    {
        cout << "Cannot use negative position.\n";
    }
    else
    {
        if(i > j)
        {
            bigPos = i;
            smallPos = j;
        }
        else
        {
            bigPos = j;
            smallPos = i;
        }
        
        Node * tempNode1 = head;
        Node * tempNode2 = head;
        for(int b = 0; b != bigPos; ++b)
        {
            tempNode1 = tempNode1->next;
        }
        
        for(int s = 0; s != smallPos; ++s)
        {
            tempNode2 = tempNode2->next;
        }
        
        char valueHolder = tempNode2->data;
        tempNode2->data = tempNode1->data;
        tempNode1->data = valueHolder;
    }
}

void MyList::insert_at_pos(int i, char value)
{
    if(i >= size())
    {
        cout << "Error too big.\n";
    }
    else if(i < 0)
    {
        cout << "Cannot use negative position.\n";
    }
    else if(i == 0)
    {
        push_front(value);
    }
    else if(i == (num-1))
    {
        push_back(value);
    }
    else
    {
        Node * thing = head;
        for(int x=0;x != i; x++)
        {
            thing = thing->next;
        }
        
        Node * tempNode = new Node(value);
        Node * tempNode2 = thing->next;
        thing->next = tempNode;
        tempNode->pred = thing;
        tempNode2->pred = tempNode;
        tempNode->next = tempNode2;
        
        ++num;
    }
}

void MyList::reverse()
{
    MyList thing = MyList();
    Node * tempNode = head->pred;
    for(int i = size(); i > 0; --i)
    {
        thing.push_back(tempNode->data);
        tempNode = tempNode->pred;
    }
    
    while(size() != 0)
    {
        pop_back();
    }
    
    for(int i=0; i < thing.size();++i)
        push_back(thing[i]);
}

void MyList::print() const
{
    Node * tempNode = head;
    for(int i=0; i < size(); ++i)
    {
        cout << tempNode->data << " ";
        tempNode = tempNode->next;
    }
}

int MyList::find(char value) const
{
    int pos = -1;
    Node * tempNode = head;
    for(int i=0; i < size(); ++i)
    {
        if(tempNode->data == value)
        {
            pos = i;
            break;
        }
        tempNode = tempNode->next;
        pos = -1;
    }
    return pos;
}

int MyList::find(MyList& query_str) const
{
    int pos = -1;
    int checker = 0;
    MyList thing = MyList(*this);
    if(size() - query_str.size() < 0)
        return pos;
    
    for(int i=0;i < size(); ++i)
    {
        for(int x=0;x < query_str.size();++x)
        {
            if(i+x >= size())
                break;
            if(thing[i+x] == query_str[x])
                ++checker;
        }
        if(checker == query_str.size())
            return i;
        checker = 0;
    }
    return pos;
}

MyList& MyList::operator=(const MyList& str)
{
    MyList thing = MyList();
    Node * tempNode = str.head;
    
    for(int i=0; i< str.size(); ++i)
    {
        thing.push_back(tempNode->data);
        tempNode = tempNode->next;
    }
    return thing;
}

char& MyList::operator[](const int i)
{
    Node * tempNode = head;
    char thing = NULL;
    if(i >= size())
    {
        cout << "Error position is too big.\n";
        return thing;
    }
    else if(i < 0)
    {
        cout << "Error position is negative.\n";
        return thing;
    }
    else
    {
        for(int x=0;x < i; ++x)
        {
            tempNode = tempNode->next;
        }
        thing = tempNode->data;
        return thing;
    }
}

MyList& MyList::operator+(const MyList& str)
{
    MyList * tempList = new MyList();
    Node * tempHead2 = head;
    
    for(int i=0;i<size();++i)
    {
        tempList->push_back(tempHead2->data);
        tempHead2 = tempHead2->next;
    }
    
    Node * tempHead = str.head;
    Node * tail = str.head->pred;
    for(;tempHead != tail; tempHead = tempHead->next)
    {
        tempList->push_back(tempHead->data);
    }
    tempList->push_back(tempHead->data);
    
    return *tempList;
}