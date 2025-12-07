#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
    int id;
    string name;
    int quantity;
    Item* next;

    Item(int id, string name, int quantity) 
	{
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->next = NULL;
    }
};

class Inventory 
{
private:
    Item* head;

public:
    Inventory() 
	{
        head = NULL;
    }

    void addItem(int id, string name, int quantity) 
	{
        Item* newItem = new Item(id, name, quantity);

        if (head == NULL) 
		{
            head = newItem;
        }
        else 
		{
            Item* temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newItem;
        }

        cout << "Item added successfully!\n";
    }

    void removeItem(int id) 
	{
        if (head == NULL) 
		{
            cout << "Inventory is empty!\n";
            return;
        }

        Item* temp = head;
        Item* prev = NULL;

        if (temp != NULL && temp->id == id) 
		{
            head = temp->next;
            delete temp;
            cout << "Item removed successfully!\n";
            return;
        }

        while (temp != NULL && temp->id != id) 
		{
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) 
		{
            cout << "Item not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Item removed successfully!\n";
    }

    void searchItem(int id) 
	{
        Item* temp = head;

        while (temp != NULL) 
		{
            if (temp->id == id) 
			{
                cout << "\nItem Found:\n";
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Quantity: " << temp->quantity << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Item not found!\n";
    }

    void displayInventory() 
	{
        if (head == NULL) 
		{
            cout << "Inventory is empty!\n";
            return;
        }

        Item* temp = head;
        cout << "\n--- Game Inventory Items ---\n";

        while (temp != NULL) 
		{
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Quantity: " << temp->quantity << endl;
            temp = temp->next;
        }
    }
};

int main() 
{
    Inventory inv;
    int choice, id, quantity;
    string name;

    do 
	{
        cout << "\n===== GAME INVENTORY MANAGER =====\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Search Item\n";
        cout << "4. Display Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
		{

        case 1:
            cout << "Enter Item ID: ";
            cin >> id;
            cin.ignore();

            cout << "Enter Item Name: ";
            getline(cin, name);

            cout << "Enter Quantity: ";
            cin >> quantity;

            inv.addItem(id, name, quantity);
            break;

        case 2:
            cout << "Enter Item ID to remove: ";
            cin >> id;
            inv.removeItem(id);
            break;

        case 3:
            cout << "Enter Item ID to search: ";
            cin >> id;
            inv.searchItem(id);
            break;

        case 4:
            inv.displayInventory();
            break;

        case 5:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } 
	while (choice != 5);

    return 0;
}