#ifndef TELBOOK_H
#define TELBOOK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phone;
};

int loadContacts(Contact tb[]);
void displayContacts(Contact tb[], int count);
void addContact(Contact tb[], int &count);
void editContact(Contact tb[], int count);
void searchContact(Contact tb[], int count);

int loadContacts(Contact tb[]) {
    ifstream file("contact.txt");
    int count = 0;
    if (file) {
        while (file >> tb[count].name >> tb[count].phone) {
            count++;
        }
    }
    file.close();
    return count;
}

void displayContacts(Contact tb[], int count) {
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << tb[i].name << " - " << tb[i].phone << "\n";
    }
}

void addContact(Contact tb[], int &count) {
    if (count >= 100) {
        cout << "Phonebook is full!\n";
        return;
    }

    cout << "Enter name: ";
    cin >> tb[count].name;
    cout << "Enter phone number: ";
    cin >> tb[count].phone;
    count++;

    ofstream file("contact.txt", ios::app);
    if (file) {
        file << tb[count - 1].name << " " << tb[count - 1].phone << "\n";
        file.close();
    } else {
        cout << "Error saving contact to file.\n";
    }
}

void editContact(Contact tb[], int count) {
    string name;
    cout << "Enter the name of the contact you want to edit: ";
    cin >> name;

    for (int i = 0; i < count; i++) {
        if (tb[i].name == name) {
            cout << "Enter new name: ";
            cin >> tb[i].name;
            cout << "Enter new phone number: ";
            cin >> tb[i].phone;

            ofstream file("contact.txt");
            if (file) {
                for (int j = 0; j < count; j++) {
                    file << tb[j].name << " " << tb[j].phone << "\n";
                }
                file.close();
            } else {
                cout << "Error saving changes to file.\n";
            }
            return;
        }
    }
    cout << "Contact not found.\n";
}

void searchContact(Contact tb[], int count) {
    string query;
    cout << "Enter name or phone number to search: ";
    cin >> query;

    for (int i = 0; i < count; i++) {
        if (tb[i].name == query || tb[i].phone == query) {
            cout << "Contact found: " << tb[i].name << " - " << tb[i].phone << "\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

#endif
