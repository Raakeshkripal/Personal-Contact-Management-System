//**** 21BEC0967 RAAKESH KRIPAL.VUK ****
// Include necessary header files
#include <stdio.h>   // Standard input/output functions
#include <stdlib.h>  // Standard library functions, including memory allocation
#include <string.h>  // String manipulation functions

// Define structure for contact information
typedef struct Contact {     // Define a structure named "Contact"
    char name[50];           // Name of the contact, up to 50 characters
    char phoneNumber[20];    // Phone number of the contact, up to 20 characters
    char emailAddress[50];   // Email address of the contact, up to 50 characters
    union {                  // Union for either home or work address
        char homeAddress[100];  // Home address, up to 100 characters
        char workAddress[100];  // Work address, up to 100 characters
    } address;
    struct Contact* next;    // Pointer to the next contact in the linked list
} Contact;

// Function prototypes
void addContact(Contact** head);            // Function to add a new contact
void modifyContact(Contact* head);          // Function to modify an existing contact
void deleteContact(Contact** head);         // Function to delete a contact
void searchContact(Contact* head);          // Function to search for a contact
void displayContacts(Contact* head);        // Function to display all contacts
void saveContactsToFile(Contact* head);     // Function to save contacts to a file
Contact* loadContactsFromFile();            // Function to load contacts from a file

int main() {
    Contact* head = NULL;  // Initialize the head of the linked list of contacts
    int choice;            // Variable to store user's menu choice

    // Menu-driven loop
    do {
        // Display menu options
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Modify Contact\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Display Contacts\n");
        printf("6. Save Contacts to File\n");
        printf("7. Load Contacts from File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Read user's choice

        // Switch based on user's choice
        switch (choice) {
            case 1:
                addContact(&head);     // Add a new contact
                break;
            case 2:
                modifyContact(head);   // Modify an existing contact
                break;
            case 3:
                deleteContact(&head);  // Delete a contact
                break;
            case 4:
                searchContact(head);   // Search for a contact
                break;
            case 5:
                displayContacts(head); // Display all contacts
                break;
            case 6:
                saveContactsToFile(head);  // Save contacts to a file
                break;
            case 7:
                head = loadContactsFromFile();  // Load contacts from a file
                break;
            case 8:
                printf("Exiting the program...\n");  // Exit the program
                break;
            default:
                printf("Invalid choice. Please try again.\n");  // Invalid choice message
        }
    } while (choice != 8);  // Continue loop until user chooses to exit

    return 0;  // Return from main function
}

// Function to add a new contact
void addContact(Contact** head) {
    Contact* newContact = (Contact*)malloc(sizeof(Contact));  // Allocate memory for new contact
    printf("Enter name: ");
    scanf("%s", newContact->name);                           // Read name from user
    printf("Enter phone number: ");
    scanf("%s", newContact->phoneNumber);                    // Read phone number from user
    printf("Enter email address: ");
    scanf("%s", newContact->emailAddress);                   // Read email address from user
    printf("Enter address type (1. Home, 2. Work): ");
    int addressType;
    scanf("%d", &addressType);                               // Read address type from user
    if (addressType == 1) {
        printf("Enter home address: ");
        scanf("%s", newContact->address.homeAddress);         // Read home address from user
    } else {
        printf("Enter work address: ");
        scanf("%s", newContact->address.workAddress);         // Read work address from user
    }
    newContact->next = *head;                                 // Set next pointer of new contact
    *head = newContact;                                       // Update head to point to new contact
    printf("Contact added successfully!\n");                  // Print success message
}
// Function to modify an existing contact
void modifyContact(Contact* head) {
    // Code for modifying contact
    char name[50];  // Variable to store the name of the contact to be modified
    printf("Enter the name of the contact you want to modify: ");
    scanf("%s", name);  // Read the name of the contact from the user

    Contact* current = head;  // Initialize a pointer to traverse the linked list
    while (current != NULL) {  // Loop through the linked list
        if (strcmp(current->name, name) == 0) {  // Check if the current contact's name matches the input name
            printf("Enter new phone number: ");
            scanf("%s", current->phoneNumber);  // Read and update the phone number of the contact
            printf("Enter new email address: ");
            scanf("%s", current->emailAddress);  // Read and update the email address of the contact
            printf("Enter new address type (1. Home, 2. Work): ");
            int addressType;
            scanf("%d", &addressType);  // Read the new address type from the user
            if (addressType == 1) {
                printf("Enter new home address: ");
                scanf("%s", current->address.homeAddress);  // Read and update the home address if selected
            } else {
                printf("Enter new work address: ");
                scanf("%s", current->address.workAddress);  // Read and update the work address if selected
            }
            printf("Contact modified successfully!\n");  // Print success message
            return;  // Exit the function after modifying the contact
        }
        current = current->next;  // Move to the next contact in the linked list
    }
    printf("Contact not found!\n");  // Print message if the contact is not found
}

// Function to delete a contact
void deleteContact(Contact** head) {
    // Code for deleting contact
    char name[50];  // Variable to store the name of the contact to be deleted
    printf("Enter the name of the contact you want to delete: ");
    scanf("%s", name);  // Read the name of the contact from the user

    Contact* current = *head;  // Initialize a pointer to traverse the linked list, starting from the head
    Contact* prev = NULL;  // Pointer to keep track of the previous contact

    while (current != NULL) {  // Loop through the linked list
        if (strcmp(current->name, name) == 0) {  // Check if the current contact's name matches the input name
            if (prev == NULL) {  // If the contact to be deleted is the head
                *head = current->next;  // Update the head to point to the next contact
            } else {
                prev->next = current->next;  // Update the previous contact's next pointer to skip the current contact
            }
            free(current);  // Free the memory allocated for the current contact
            printf("Contact deleted successfully!\n");  // Print success message
            return;  // Exit the function after deleting the contact
        }
        prev = current;  // Update the previous pointer
        current = current->next;  // Move to the next contact in the linked list
    }
    printf("Contact not found!\n");  // Print message if the contact is not found
}

// Function to search for a contact
void searchContact(Contact* head) {
    // Code for searching contact
    char name[50];  // Variable to store the name of the contact to be searched
    printf("Enter the name of the contact you want to search: ");
    scanf("%s", name);  // Read the name of the contact from the user

    Contact* current = head;  // Initialize a pointer to traverse the linked list
    while (current != NULL) {  // Loop through the linked list
        if (strcmp(current->name, name) == 0) {  // Check if the current contact's name matches the input name
            printf("Contact found!\n");  // Print success message
            printf("Name: %s\n", current->name);  // Print the name of the contact
            printf("Phone Number: %s\n", current->phoneNumber);  // Print the phone number of the contact
            printf("Email Address: %s\n", current->emailAddress);  // Print the email address of the contact
            if (strlen(current->address.homeAddress) > 0) {
                printf("Home Address: %s\n", current->address.homeAddress);  // Print the home address if available
            } else {
                printf("Work Address: %s\n", current->address.workAddress);  // Print the work address if available
            }
            return;  // Exit the function after finding the contact
        }
        current = current->next;  // Move to the next contact in the linked list
    }
    printf("Contact not found!\n");  // Print message if the contact is not found
}
// Function to display all contacts
void displayContacts(Contact* head) {
    // Check if the linked list is empty
    if (head == NULL) {
        printf("No contacts to display.\n");
        return;
    }

    // Initialize a temporary pointer to traverse the linked list
    Contact* current = head;
    printf("Contacts:\n");

    // Traverse the linked list and print contact details
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone Number: %s\n", current->phoneNumber);
        printf("Email Address: %s\n", current->emailAddress);

        // Check if the homeAddress string has content
        if (strlen(current->address.homeAddress) > 0) {
            printf("Home Address: %s\n", current->address.homeAddress);
        } else {
            printf("Work Address: %s\n", current->address.workAddress);
        }

        printf("\n");
        current = current->next; // Move to the next node
    }
}

// Function to save contacts to a file
void saveContactsToFile(Contact* head) {
    // Open a file for writing in text mode
    FILE *fp = fopen("contacts.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Initialize a temporary pointer to traverse the linked list
    Contact* current = head;

    // Traverse the linked list and write contact details to the file
    while (current != NULL) {
        // Write name, phone number, and email address to the file
        fprintf(fp, "%s,%s,%s,", current->name, current->phoneNumber, current->emailAddress);

        // Check if the homeAddress string has content
        if (strlen(current->address.homeAddress) > 0) {
            // Write "Home" and the home address to the file
            fprintf(fp, "Home,%s\n", current->address.homeAddress);
        } else {
            // Write "Work" and the work address to the file
            fprintf(fp, "Work,%s\n", current->address.workAddress);
        }

        current = current->next; // Move to the next node
    }

    fclose(fp); // Close the file
    printf("Contacts saved to file successfully!\n");
}

// Function to load contacts from a file
Contact* loadContactsFromFile() {
    // Open a file for reading in text mode
    FILE *fp = fopen("contacts.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }

    Contact* head = NULL; // Initialize the head of the linked list to NULL
    char line[300]; // Buffer to store each line from the file

    // Read each line from the file and create a new node in the linked list
    while (fgets(line, sizeof(line), fp)) {
        Contact* newContact = (Contact*)malloc(sizeof(Contact));

        // Read name, phone number, email address, and home address from the line
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],", newContact->name, newContact->phoneNumber, newContact->emailAddress, newContact->address.homeAddress);

        // Add the new node to the beginning of the linked list
        newContact->next = head;
        head = newContact;
    }

    fclose(fp); // Close the file
    printf("Contacts loaded from file successfully!\n");
    return head; // Return the head of the linked list
}
