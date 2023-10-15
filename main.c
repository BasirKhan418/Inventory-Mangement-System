#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure  a product
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to add a product to the inventory
void addProduct(struct Product inventory[], int *count) {
    struct Product newProduct;
    
    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);
    
    printf("Enter product price: ");
    scanf("%f", &newProduct.price);
    
    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);
    
    newProduct.id = (*count) + 1;
    inventory[*count] = newProduct;
    
    (*count)++;
    printf("Product added successfully!\n");
}

// Function to display the inventory
void displayInventory(struct Product inventory[], int count) {
    printf("Inventory:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", inventory[i].id);
        printf("Name: %s\n", inventory[i].name);
        printf("Price: $%.2f\n", inventory[i].price);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("\n");
    }
}

// Function to search for a product by name
void searchProduct(struct Product inventory[], int count) {
    char searchName[50];
    
    printf("Enter product name to search for: ");
    scanf(" %[^\n]", searchName);
    
    printf("Search results:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(inventory[i].name, searchName) != NULL) {
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Price: $%.2f\n", inventory[i].price);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("\n");
        }
    }
}

// Function to save inventory data to a file
void saveInventory(struct Product inventory[], int count) {
    FILE *file = fopen("inventory.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f,%d\n", inventory[i].id, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }

    fclose(file);
    printf("Inventory data saved to inventory.txt\n");
}

int main() {
    struct Product inventory[100]; // Assume a maximum of 100 products
    int count = 0;

    int choice;

    while (1) {
        printf("Inventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Search for Product\n");
        printf("4. Save Inventory Data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &count);
                break;
            case 2:
                displayInventory(inventory, count);
                break;
            case 3:
                searchProduct(inventory, count);
                break;
            case 4:
                saveInventory(inventory, count);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

