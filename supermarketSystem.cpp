#include "SupermarketSystem.h"
#include <iostream>
#include <string>
using namespace std;


// Mahmoud Abdellatif Mohamed 202200521 

SupplierLinkedList::SupplierLinkedList() {
    head = nullptr;
    cursor = nullptr;
    prev = nullptr;
    size = 0;
}

bool SupplierLinkedList::listIsEmpty() const {
    return head == nullptr;
}

void SupplierLinkedList::insertFirst(const int &k, const double &d) {
    if (size >= MAX_CAPACITY) {
        cout << "Error: Maximum capacity of " << MAX_CAPACITY << " reached. Cannot insert supplier: " << k << endl;
        return;
    }

    NodePointer newNode = new node;
    newNode->key = k;
    newNode->data = d;

    newNode->next = head;
    head = newNode;

    size++;
    cout << "Inserted: " << k << " with debt " << d << endl;
}

void SupplierLinkedList::traverse() const {
    if (listIsEmpty()) {
        cout << "The suppliers ledger is currently empty." << endl;
        return;
    }

    NodePointer temp = head;
    cout << "\n--- Suppliers Ledger ---" << endl;
    while (temp != nullptr) {
        cout << "[ Key: " << temp->key << " | Debt: " << temp->data << " ]" << endl;
        temp = temp->next;
    }
    cout << "\n--- --- --- --- --- --- --- --- --- " << endl;
}


// Mohamed Mahmoud AbdelGhafar Mohamed 202200491 

DamagedBoxStack::DamagedBoxStack(int nelements)
{
    MaxSize = nelements;
    top = -1;

    stack = new string[MaxSize];
}
DamagedBoxStack::~DamagedBoxStack()
{
    delete[] stack;
}
const bool DamagedBoxStack::stackIsEmpty()
{
    if(top == -1)
    {


    return true;
}
    else
    {
        return false ;

    }
 }
const bool DamagedBoxStack::stackIsFull()
{
    if(top == MaxSize-1)
    {


    return true;
}
    else
    {
        return false ;

    }
 }
void DamagedBoxStack::push(string item)
{
    if(stackIsFull())
    {
        cout << "Damaged Box is Full" << endl;
        return;
    }

    top++;
    stack[top] = item;
}
void DamagedBoxStack::pop(string &item)
{
    if(stackIsEmpty())
    {
        cout << "Damaged Box is Empty" << endl;
        return;
    }

    item = stack[top];
    top--;
}



// Salma Hassan Omar Mohamed 202300559

CashierQueue::CashierQueue(int nelements) {
    MaxSize = nelements;
    queue = new string[MaxSize];
    front = 0;
    rear = 0;
    count = 0;
}

CashierQueue::~CashierQueue() {
    delete[] queue;
}

bool CashierQueue::queueIsEmpty() const {
    return (count == 0);
}

bool CashierQueue::queueIsFull() const {
    return (count == MaxSize);
}

void CashierQueue::enqueue(string el) {
    if (queueIsFull()) {
        cout << "Queue is Full" << endl;
        return;
    }
    queue[rear] = el;
    rear = (rear + 1) % MaxSize;
    count++;
    cout << "?? Entered Queue: [" << el << "]" << endl;
}

void CashierQueue::dequeue(string &el) {
    if (queueIsEmpty()) {
        cout << "Queue is Empty" << endl;
        return;
    }
    el = queue[front];
    front = (front + 1) % MaxSize;
    count--;
}




// Ahmed Maged Abdelaziz 202300462

ShoppingCartStack::ShoppingCartStack(int nelements) {
    MaxSize = nelements;
    stack = new string[MaxSize];
    top = -1;
}

ShoppingCartStack::ShoppingCartStack(const ShoppingCartStack &original) {
    MaxSize = original.MaxSize;
    top = original.top;
    stack = new string[MaxSize];
    for (int i = 0; i <= top; i++) {
        stack[i] = original.stack[i];
    }
}

ShoppingCartStack::~ShoppingCartStack() {
    delete[] stack;
}

bool ShoppingCartStack::stackIsEmpty() const {
    return (top < 0);
}

bool ShoppingCartStack::stackIsFull() const {
    return (top >= MaxSize - 1);
}

void ShoppingCartStack::push(string el) {
    if (stackIsFull()) {
        cout << "Stack is Full" << endl;
        return;
    }
    top++;
    stack[top] = el;
    cout << "?? Added to Cart: [" << el << "]" << endl;
}

void ShoppingCartStack::pop(string &el) {
    if (stackIsEmpty()) {
        cout << "Stack is Empty" << endl;
        return;
    }
    el = stack[top];
    top--;
}



//Eslam Nazeh Hassan  202200202

InvoiceLinkedList::InvoiceLinkedList()
{
    head = NULL;
    cursor = NULL;
    prev = NULL;
}

bool InvoiceLinkedList::listIsEmpty() const
{
    return (head == NULL);
}

void InvoiceLinkedList::insertFirst(const string &k, const double &d)
{
    NodePointer pnew;

    pnew = new node;

    pnew->key = k;
    pnew->data = d;

    pnew->next = head;
    head = pnew;

    cursor = head;
    prev = NULL;
}

void InvoiceLinkedList::traverse()
{
    NodePointer p;

    p = head;

    while (p != NULL)
    {
        cout << "Invoice: " << p->key << endl;
        cout << "Total: " << p->data << endl;

        p = p->next;
    }
}
