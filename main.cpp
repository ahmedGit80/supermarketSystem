#include <iostream>
#include <string>
#include "SupermarketSystem.h" 

using namespace std;

int main() {
    SupplierLinkedList ledger;
    ledger.insertFirst(101, 1500.50);
    ledger.insertFirst(102, 3200.75);
    ledger.insertFirst(103, 450.00);
    ledger.insertFirst(104, 10000.00);
    ledger.insertFirst(105, 275.25);
    ledger.insertFirst(106, 500.00);
    ledger.traverse();
    cout << endl;

    DamagedBoxStack damaged(5);
    damaged.push("choclate");
    damaged.push("Banana");
    damaged.push("Apple");
    damaged.push("Orange");
    damaged.push("Mango");
    string item;
    damaged.pop(item);
    cout << "remove item " << item << endl;
    damaged.pop(item);
    cout << "remove item " << item << endl;
    damaged.pop(item);
    cout << "remove item " << item << endl;
    cout << endl;

    CashierQueue checkoutLine(5);
    checkoutLine.enqueue("Ahmed Mamdouh");
    checkoutLine.enqueue("Sara Aly");
    cout << endl;

    string currentCustomer;
    checkoutLine.dequeue(currentCustomer);
    cout << "Active customer: [" << currentCustomer << "]" << endl;

    ShoppingCartStack customerCart(5);
    customerCart.push("Fresh Milk");
    customerCart.push("Whole Wheat Pasta");
    customerCart.push("Soda Can");
    string discardedProduct;
    customerCart.pop(discardedProduct);
    cout << "Undo product: " << discardedProduct << endl << endl;

    InvoiceLinkedList billingSystem;
    billingSystem.insertFirst("INV-2026-001", 350.50);
    billingSystem.insertFirst("INV-2026-002", 1250.00);
    billingSystem.traverse();

    return 0;
}
