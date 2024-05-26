#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
};

void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin >> newContact.name;
    cout << "Enter phone number: ";
    cin >> newContact.phoneNumber;
    contacts.push_back(newContact);
}

void searchByName(const vector<Contact>& contacts, const string& name) {
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Found contact: " << contact.name << " (" << contact.phoneNumber << ")\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

void displayContacts(const vector<Contact>& contacts) {
    cout << "Contacts:\n";
    for (const auto& contact : contacts) {
        cout << contact.name << " (" << contact.phoneNumber << ")\n";
    }
}

int main() {
    vector<Contact> contacts; // Store contacts
    int choice;

    do {
        cout << "\nPhone Directory Application\n";
        cout << "1. Add Contact\n";
        cout << "2. Search by Name\n";
        cout << "3. Display All Contacts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                cout << "Enter name to search: ";
                string searchName;
                cin >> searchName;
                searchByName(contacts, searchName);
                break;
            case 3:
                displayContacts(contacts);
                break;
            case 4:
                cout << "Exiting. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}