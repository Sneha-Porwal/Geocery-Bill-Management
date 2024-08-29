#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Item {
public:
    int id;
    char name[50];
    int quantity;
    int price;
    char unit[5];
};

class Shop {
public:
    char name[50];
    char address[100];
    char contactNumber[15];
};

void selectionSort(Item items[], int totalItems) {
    for (int i = 0; i < totalItems - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < totalItems; j++) {
            if (strcmp(items[j].name ,items[minIndex].name) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(items[i].name, items[minIndex].name);
        }
    }
}

void displayReceipt(Item items[], int totalItems, Shop shop, char customerName[50], char customerAddress[100], double discount, double tax) {
    int total = 0;
    int maxQuantity = 0;
    
    // Sort items alphabetically using selection sort
    selectionSort(items, totalItems);

    cout << "\n\n\n";
    cout << "\t\t Sanjay Kirana Store \n" << "\t\t-----------------------------\n ";
    cout << "\t\t 38, Bada Bazar Dewas (M.P) \n" << "\t\t Contact: 9407110071 \n";
    cout << "\t\t-----------------------------------\n";
    cout << "\n";
    cout << "Customer: " << customerName << "\t Address: " << customerAddress << "\n";
    cout << "\n";

    for (int i = 0; i < totalItems; i++) {
        cout << "Id: " << items[i].id << "\t";
        cout << "Item Name: " << items[i].name << "\t\t\t";
        cout << "Quantity: " << items[i].quantity << "\t";
        cout << "Unit: " << items[i].unit << "\t";
        cout << "Price: " << items[i].price << "\t";
        cout << "Total Price: " << items[i].price * items[i].quantity << "\n";
        cout << "---------------------------------------------------------------------------------------------------------------\n";

        total += items[i].price * items[i].quantity;

        if (items[i].quantity > maxQuantity) {
            maxQuantity = items[i].quantity;
        }
    }

    double discountAmount = total * (discount / 100);
    double taxAmount = total * (tax / 100);
    double grandTotal = total - discountAmount + taxAmount;

    cout << "\t Total: " << total << "\n";
    cout << "\t Discount (" << discount << "%): " << discountAmount << "\n";
    cout << "\t Tax (" << tax << "%): " << taxAmount << "\n";
    cout << "\t Grand Total: " << grandTotal << "\n";

    cout << "\n\n";
    cout << "Most Purchased Item: " << items[0].name << " (Quantity: " << maxQuantity << ")\n";

    // Payment Mode Selection
    int paymentMode;
    cout << "Select Payment Mode:\n";
    cout << "1. Cash\n";
    cout << "2. Online Payment\n";
    cout << "Enter your choice: ";
    cin >> paymentMode;

    // Process payment based on the selected mode
    if (paymentMode == 1) {
        double cash;
        cout << "Enter Cash Amount: ";
        cin >> cash;

        if (cash >= grandTotal) {
            cout << "Payment successful! Change: " << cash - grandTotal << endl;
        } else {
            cout << "Insufficient payment. Please try again.\n";
          
        }
    } else if (paymentMode == 2) {
        cout << "Online Payment successfully processed.\n";
    } else {
        cout << "Invalid payment mode.\n";
    }

    cout << "Thanks for visiting Sanjay Kirana \n";
    cout << "\n\n";
}

int main() {
    cout << "Hello..............\n";
    Shop shop;
    char customerName[50];
    char customerAddress[100];
    int totalItems;
    double discount, tax;
    const int maxItems = 30;  // Maximum number of items

    Item items[maxItems];

    cout << "Enter your name: \t";
    cin.ignore();  // Ignore the newline character left in the buffer
    cin.getline(customerName, 50);
    cout << "Enter your address: \t";
    cin.getline(customerAddress, 100);
    int choice;
    do {
        cout << "\n1. Add Item\n";
        cout << "2. Display Receipt\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (totalItems < maxItems) {
                    items[totalItems].id = totalItems + 1;
                    cout << "Enter item name for item " << items[totalItems].id << ": \t";
                    cin.ignore();  // Ignore the newline character left in the buffer
                    cin.getline(items[totalItems].name, 50);
                    cout << "Enter quantity: \t";
                    cin >> items[totalItems].quantity;
                    cout << "Enter unit (KG/g/PCS/Lit): \t";
                    cin >> items[totalItems].unit;
                    cout << "Enter price: \t";
                    cin >> items[totalItems].price;
                    totalItems++;

                } else {
                    cout << "Maximum items reached!\n";
                }
                break;
            case 2:
                cout << "\n";
                cout << "Enter discount percentage: \t";
                cin >> discount;
                cout << "Enter tax percentage: \t";
                cin >> tax;
                displayReceipt(items, totalItems, shop, customerName, customerAddress, discount, tax);
                break;
            case 3:
                cout << "Thank You For Shopping!!!";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
        }
    } while (choice != 3);

    return 0;
}
