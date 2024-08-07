#include <iostream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PantryItem {
public:
    PantryItem(const string& name, int quantity) : name(name), quantity(quantity) {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }

private:
    string name;
    int quantity;
};

class Pantry {
public:
    void addFruit(const string& name, int quantity) {
        addItem(fruits, name, quantity);
    }

    void addMeat(const string& name, int quantity) {
        addItem(meats, name, quantity);
    }

    void viewItems() const {
        cout << "Fruits:\n";
        viewCategory(fruits);
        cout << "\nMeats:\n";
        viewCategory(meats);
    }

private:
    vector<PantryItem> fruits;
    vector<PantryItem> meats;

    void addItem(vector<PantryItem>& category, const string& name, int quantity) {
        for (auto& item : category) {
            if (item.getName() == name) {
                item.setQuantity(item.getQuantity() + quantity);
                return;
            }
        }
        category.emplace_back(name, quantity);
    }

    void viewCategory(const vector<PantryItem>& category) const {
        if (category.empty()) {
            cout << "None\n";
            return;
        }
        for (const auto& item : category) {
            cout << "Item: " << item.getName() << ", Quantity: " << item.getQuantity() << "\n";
        }
    }
};

int main() {
    Pantry pantry;
    int choice;
    string name;
    int quantity;

    do {
        cout << "1. Add fruit\n2. Add meat\n3. View items\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter fruit name: ";
                cin >> name;
                cout << "Enter the amount: ";
                cin >> quantity;
                pantry.addFruit(name, quantity);
                break;

            case 2:
                cout << "Enter meat name: ";
                cin >> name;
                cout << "Enter the amount: ";
                cin >> quantity;
                pantry.addMeat(name, quantity);
                break;

            case 3:
                pantry.viewItems();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

