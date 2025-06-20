#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int phone;
    char name[20];
    char address[50];
    char email[30];
} contact_t;

#define MAX_CONTACTS 100

contact_t contacts[MAX_CONTACTS];
int numContacts = 0;

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Clear the input buffer by reading and discarding characters until newline or EOF is encountered
}

void displayMenu() {
    // Display the main menu options
    printf("--------------------------------------------------\n");
    printf("Contact Management System\n");
    printf("--------------------------------------------------\n");
    printf("0. Quit\n");
    printf("1. Add a new contact\n");
    printf("2. List all contacts\n");
    printf("3. Search for contact\n");
    printf("4. Delete a contact\n");
    printf("--------------------------------------------------\n");
    printf("Enter Option [0-4]: ");
}

void addContact() {
    // Add a new contact to the contact list
    if (numContacts >= MAX_CONTACTS) {
        printf("Cannot add more contacts. Contact list is full.\n");
        return;
    }

    contact_t newContact;

    printf("Enter name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin); // Read the contact's name from user input
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove the trailing newline character

    printf("Enter phone number: ");
    scanf("%d", &newContact.phone); // Read the contact's phone number from user input
    clearInputBuffer();

    printf("Enter address: ");
    fgets(newContact.address, sizeof(newContact.address), stdin); // Read the contact's address from user input
    newContact.address[strcspn(newContact.address, "\n")] = '\0'; // Remove the trailing newline character

    printf("Enter email: ");
    fgets(newContact.email, sizeof(newContact.email), stdin); // Read the contact's email from user input
    newContact.email[strcspn(newContact.email, "\n")] = '\0'; // Remove the trailing newline character

    contacts[numContacts] = newContact; // Add the new contact to the contact list
    numContacts++;

    printf("Contact added successfully.\n");
}

void listContacts() {
    // List all contacts in the contact list
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("Contact List:\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < numContacts; i++) {
        printf("Name: %s\n", contacts[i].name); // Print the contact's name
        printf("Phone: %d\n", contacts[i].phone); // Print the contact's phone number
        printf("Address: %s\n", contacts[i].address); // Print the contact's address
        printf("Email: %s\n", contacts[i].email); // Print the contact's email
        printf("--------------------------------------------------\n");
    }
}

void searchContact() {
    // Search for a contact by name or phone number
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    int searchOption;

    printf("Search by:\n");
    printf("1. Name\n");
    printf("2. Phone number\n");
    printf("Enter option [1-2]: ");
    scanf("%d", &searchOption); // Read the user's option for searching by name or phone number
    clearInputBuffer();

    if (searchOption == 1) {
        char searchName[20];
        printf("Enter the name of the contact to search: ");
        fgets(searchName, sizeof(searchName), stdin); // Read the name to search from user input
        searchName[strcspn(searchName, "\n")] = '\0'; // Remove the trailing newline character

        int found = 0;

        for (int i = 0; i < numContacts; i++) {
            if (strcmp(contacts[i].name, searchName) == 0) { // Compare the name with each contact in the list
                printf("Contact Found:\n");
                printf("Name: %s\n", contacts[i].name); // Print the contact's name
                printf("Phone: %d\n", contacts[i].phone); // Print the contact's phone number
                printf("Address: %s\n", contacts[i].address); // Print the contact's address
                printf("Email: %s\n", contacts[i].email); // Print the contact's email
                printf("--------------------------------------------------\n");
                found = 1;
            }
        }

        if (!found) {
            printf("Contact not found.\n");
        }
    } else if (searchOption == 2) {
        int searchPhone;
        printf("Enter the phone number of the contact to search: ");
        scanf("%d", &searchPhone); // Read the phone number to search from user input
        clearInputBuffer();

        int found = 0;

        for (int i = 0; i < numContacts; i++) {
            if (contacts[i].phone == searchPhone) { // Compare the phone number with each contact in the list
                printf("Contact Found:\n");
                printf("Name: %s\n", contacts[i].name); // Print the contact's name
                printf("Phone: %d\n", contacts[i].phone); // Print the contact's phone number
                printf("Address: %s\n", contacts[i].address); // Print the contact's address
                printf("Email: %s\n", contacts[i].email); // Print the contact's email
                printf("--------------------------------------------------\n");
                found = 1;
            }
        }

        if (!found) {
            printf("Contact not found.\n");
        }
    } else {
        printf("Invalid option.\n");
    }
}

void deleteContact() {
    // Delete a contact from the contact list
    if (numContacts == 0) {
        printf("No contacts found.\n");
        return;
    }

    int phone;
    printf("Enter the phone number of the contact to delete: ");
    scanf("%d", &phone); // Read the phone number to delete from user input
    clearInputBuffer();

    int foundIndex = -1;

    for (int i = 0; i < numContacts; i++) {
        if (contacts[i].phone == phone) { // Search for a contact with the entered phone number
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < numContacts - 1; i++) {
            contacts[i] = contacts[i + 1]; // Shift the contacts after the deleted contact by one position to the left
        }
        numContacts--;
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}

int main() {
    int option;

    do {
        displayMenu(); // Display the main menu

        while (scanf("%d", &option) != 1 || option < 0 || option > 4) { // Read and validate the user's option
            clearInputBuffer();
            printf("Invalid option. Please try again: ");
        }
        clearInputBuffer();

        switch (option) {
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;
            case 1:
                addContact(); // Add a new contact
                break;
            case 2:
                listContacts(); // List all contacts
                break;
            case 3:
                searchContact(); // Search for a contact
                break;
            case 4:
                deleteContact(); // Delete a contact
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 0);

    return 0;
}
