#include <iostream>
#include <fstream>
#include <string>
#include "telbook.h" // File with structure and functions for phonebook
#include "quiz.h"    // File with functions for quiz

using namespace std;

void showMenu();

int main() {
    int choice;
    Contact telbook[100];
    int count = loadContacts(telbook); // Load existing contacts from file

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            startQuiz();
        } else if (choice == 2) {
            int subChoice;
            cout << "1 - Show all contacts\n2 - Add contact\n3 - Edit contact\n4 - Search contact\n";
            cout << "Your choice: ";
            cin >> subChoice;

            switch (subChoice) {
                case 1:
                    displayContacts(telbook, count);
                    break;
                case 2:
                    addContact(telbook, count);
                    break;
                case 3:
                    editContact(telbook, count);
                    break;
                case 4:
                    searchContact(telbook, count);
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

void showMenu() {
    cout << "\nMenu:\n";
    cout << "1 - Quiz\n";
    cout << "2 - Phonebook\n";
    cout << "Your choice: ";
}
