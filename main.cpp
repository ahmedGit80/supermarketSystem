#include <iostream>
#include <string>
#include <limits>
#include "SupermarketSystem.h"

using namespace std;

// ─────────────────────────────────────────────
//  Helper – print a styled header
// ─────────────────────────────────────────────
void printHeader(const string &title) {
    cout << "\n╔══════════════════════════════════════╗" << endl;
    cout << "║  " << title;
    int padding = 36 - (int)title.size();
    for (int i = 0; i < padding; i++) cout << " ";
    cout << "║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
}

// ─────────────────────────────────────────────
//  Module 1 – Supplier Ledger (Linked List)
// ─────────────────────────────────────────────
void supplierMenu() {
    SupplierLinkedList ledger;
    int choice;
    do {
        printHeader("Supplier Ledger");
        cout << "  1. Add Supplier" << endl;
        cout << "  2. View All Suppliers" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "  Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            int key;
            double debt;
            cout << "  Enter Supplier ID  : ";
            cin >> key;
            cout << "  Enter Supplier Debt: ";
            cin >> debt;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            ledger.insertFirst(key, debt);
        } else if (choice == 2) {
            ledger.traverse();
        } else if (choice != 0) {
            cout << "  !! Invalid choice, try again." << endl;
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Module 2 – Damaged Box Storage (Stack)
// ─────────────────────────────────────────────
void damagedBoxMenu() {
    DamagedBoxStack damaged(MAX_CAPACITY);
    int choice;
    do {
        printHeader("Damaged Box Storage");
        cout << "  1. Report Damaged Box (Push)" << endl;
        cout << "  2. Process Damaged Box (Pop)" << endl;
        cout << "  3. Check Stack Status" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "  Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string item;
            cout << "  Enter product name: ";
            getline(cin, item);
            damaged.push(item);
            cout << "  >> [" << item << "] added to damaged stack." << endl;
        } else if (choice == 2) {
            string item;
            damaged.pop(item);
            if (!item.empty())
                cout << "  >> Processed damaged item: [" << item << "]" << endl;
        } else if (choice == 3) {
            cout << "  Stack is " << (damaged.stackIsEmpty() ? "EMPTY" : "NOT empty");
            cout << "  |  " << (damaged.stackIsFull() ? "FULL" : "NOT full") << endl;
        } else if (choice != 0) {
            cout << "  !! Invalid choice, try again." << endl;
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Module 3 – Cashier Queue
// ─────────────────────────────────────────────
void cashierMenu() {
    CashierQueue checkoutLine(MAX_CAPACITY);
    int choice;
    do {
        printHeader("Cashier Queue");
        cout << "  1. Customer Arrives (Enqueue)" << endl;
        cout << "  2. Serve Next Customer (Dequeue)" << endl;
        cout << "  3. Check Queue Status" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "  Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string name;
            cout << "  Enter customer name: ";
            getline(cin, name);
            checkoutLine.enqueue(name);
        } else if (choice == 2) {
            string customer;
            checkoutLine.dequeue(customer);
            if (!customer.empty())
                cout << "  >> Now serving: [" << customer << "]" << endl;
        } else if (choice == 3) {
            cout << "  Queue is " << (checkoutLine.queueIsEmpty() ? "EMPTY" : "NOT empty");
            cout << "  |  " << (checkoutLine.queueIsFull() ? "FULL" : "NOT full") << endl;
        } else if (choice != 0) {
            cout << "  !! Invalid choice, try again." << endl;
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Module 4 – Shopping Cart (Stack)
// ─────────────────────────────────────────────
void shoppingCartMenu() {
    ShoppingCartStack cart(MAX_CAPACITY);
    int choice;
    do {
        printHeader("Shopping Cart");
        cout << "  1. Add Product to Cart (Push)" << endl;
        cout << "  2. Remove Last Product (Pop / Undo)" << endl;
        cout << "  3. Check Cart Status" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "  Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string product;
            cout << "  Enter product name: ";
            getline(cin, product);
            cart.push(product);
        } else if (choice == 2) {
            string product;
            cart.pop(product);
            if (!product.empty())
                cout << "  >> Removed from cart: [" << product << "]" << endl;
        } else if (choice == 3) {
            cout << "  Cart is " << (cart.stackIsEmpty() ? "EMPTY" : "NOT empty");
            cout << "  |  " << (cart.stackIsFull() ? "FULL" : "NOT full") << endl;
        } else if (choice != 0) {
            cout << "  !! Invalid choice, try again." << endl;
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  Module 5 – Invoice System (Linked List)
// ─────────────────────────────────────────────
void invoiceMenu() {
    InvoiceLinkedList billing;
    int choice;
    do {
        printHeader("Invoice System");
        cout << "  1. Add Invoice" << endl;
        cout << "  2. View All Invoices" << endl;
        cout << "  0. Back to Main Menu" << endl;
        cout << "  Your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string invoiceID;
            double total;
            cout << "  Enter Invoice ID : ";
            getline(cin, invoiceID);
            cout << "  Enter Total      : ";
            cin >> total;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            billing.insertFirst(invoiceID, total);
            cout << "  >> Invoice [" << invoiceID << "] added." << endl;
        } else if (choice == 2) {
            if (billing.listIsEmpty())
                cout << "  No invoices recorded yet." << endl;
            else
                billing.traverse();
        } else if (choice != 0) {
            cout << "  !! Invalid choice, try again." << endl;
        }
    } while (choice != 0);
}

// ─────────────────────────────────────────────
//  MAIN MENU
// ─────────────────────────────────────────────
int main() {
    int choice;
    do {
        cout << "\n╔══════════════════════════════════════╗" << endl;
        cout << "║   🛒  SUPERMARKET MANAGEMENT SYSTEM  ║" << endl;
        cout << "╠══════════════════════════════════════╣" << endl;
        cout << "║  1.  Supplier Ledger                 ║" << endl;
        cout << "║  2.  Damaged Box Storage             ║" << endl;
        cout << "║  3.  Cashier Queue                   ║" << endl;
        cout << "║  4.  Shopping Cart                   ║" << endl;
        cout << "║  5.  Invoice System                  ║" << endl;
        cout << "║  0.  Exit                            ║" << endl;
        cout << "╚══════════════════════════════════════╝" << endl;
        cout << "  Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: supplierMenu();    break;
            case 2: damagedBoxMenu();  break;
            case 3: cashierMenu();     break;
            case 4: shoppingCartMenu(); break;
            case 5: invoiceMenu();     break;
            case 0:
                cout << "\n  Goodbye! Thank you for using the Supermarket System.\n" << endl;
                break;
            default:
                cout << "  !! Invalid choice, please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
