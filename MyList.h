#ifndef __MyList_H__
#define __MyList_H__

#include <iostream>

using namespace std;

struct Node
{
public:
    char data = 0;
    Node * next = NULL;
    Node * pred = NULL;
    Node() : data(0) , next(0), pred(0) {}
    Node(char x) : data(x), next(this), pred(this) {}
};

class MyList
{
public:
    char failChar = 0;
    
    MyList();
    MyList(const MyList& str);
    MyList(const string& str);
    MyList(const char* str);
    ~MyList();
    
    void push_front(char value);
    void push_back(char value);
    void pop_front();
    void pop_back();
    void swap(int i, int j);
    void insert_at_pos(int i, char value);
    void reverse();
    
    int size() const {return num;};
    void print() const;
    int find(char value) const;
    int find(MyList& query_str) const;
    void display();
    
    MyList& operator=(const MyList& str);
    char& operator[](const int i);
    MyList& operator+(const MyList& str);
    
    Node * head = NULL;
    int num = 0;
};
#endif