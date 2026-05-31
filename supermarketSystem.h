#ifndef SUPERMARKET_SYSTEM_H
#define SUPERMARKET_SYSTEM_H

#include <iostream>
#include <string>
using namespace std;

const int MAX_CAPACITY = 5;

class SupplierLinkedList {
private:
    class node {
    public:
        int key;
        double data;
        node *next;
    };
    
    typedef node* NodePointer;
    NodePointer head, cursor, prev;
    int size;

public:
    SupplierLinkedList();
    bool listIsEmpty() const;
    void insertFirst(const int &k, const double &d);
    void traverse() const;
};

class DamagedBoxStack {
private:
    string *stack;
    int top;
    int MaxSize;

public:
    DamagedBoxStack(int nelements = MAX_CAPACITY);
    ~DamagedBoxStack();
    const bool stackIsEmpty();
    const bool stackIsFull();
    void push(string item);
    void pop(string &item);
};

class CashierQueue {
private:
    string *queue;
    int front, rear, count, MaxSize;

public:
    CashierQueue(int nelements = MAX_CAPACITY);
    ~CashierQueue();
    bool queueIsEmpty() const;
    bool queueIsFull() const;
    void enqueue(string el);
    void dequeue(string &el);
};

class ShoppingCartStack {
private:
    string *stack;
    int top;
    int MaxSize;

public:
    ShoppingCartStack(int nelements = MAX_CAPACITY);
    ShoppingCartStack(const ShoppingCartStack &original);
    ~ShoppingCartStack();
    bool stackIsEmpty() const;
    bool stackIsFull() const;
    void push(string el);
    void pop(string &el);
};

class InvoiceLinkedList {
public:
    InvoiceLinkedList();
    bool listIsEmpty() const;
    void insertFirst(const string &k, const double &d);
    void traverse();

private:
    class node {
    public:
        string key;
        double data;
        node *next;
    };

    typedef node * NodePointer;
    NodePointer head, cursor, prev;
};

#endif
