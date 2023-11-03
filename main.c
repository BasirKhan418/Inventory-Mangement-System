#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

// Structure for a product
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

// Function to display a product
void displayProduct(const struct Product* product) {
    printf("ID: %d\n", product->id);
    printf("Name: %s\n", product->name);
    printf("Price: $%.2f\n", product->price);
    printf("Quantity: %d\n\n");
}

// Function to add a product to the inventory (array)
void addProductToArray(struct Product inventory[], int *count) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    struct Product newProduct;
    newProduct.id = (*count) + 1;

    printf("Enter product name: ");
    scanf(" %[^\n]", newProduct.name);

    printf("Enter product price: ");
    scanf("%f", &newProduct.price);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.quantity);

    inventory[*count] = newProduct;
    (*count)++;
    printf("Product added to the array successfully!\n");
}

// Function to display the inventory (array)
void displayInventoryArray(const struct Product inventory[], int count) {
    printf("Inventory (Array):\n");
    for (int i = 0; i < count; i++) {
        displayProduct(&inventory[i]);
    }
}

// Function to delete a product from the inventory (array)
void deleteProductFromArray(struct Product inventory[], int *count, int id) {
    int index = -1;
    for (int i = 0; i < *count; i++) {
        if (inventory[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Product with ID %d not found.\n", id);
    } else {
        for (int i = index; i < *count - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        (*count)--;
        printf("Product with ID %d deleted from the array successfully!\n", id);
    }
}

// Function to insert a product into the inventory (array) at a specific position
void insertProductInArray(struct Product inventory[], int *count, int position) {
    if (*count >= MAX_PRODUCTS) {
        printf("Inventory is full. Cannot add more products.\n");
        return;
    }

    if (position < 0 || position >= *count) {
        printf("Invalid position for insertion.\n");
    } else {
        struct Product newProduct;
        newProduct.id = (*count) + 1;

        printf("Enter product name: ");
        scanf(" %[^\n]", newProduct.name);

        printf("Enter product price: ");
        scanf("%f", &newProduct.price);

        printf("Enter product quantity: ");
        scanf("%d", &newProduct.quantity);

        for (int i = *count; i > position; i--) {
            inventory[i] = inventory[i - 1];
        }

        inventory[position] = newProduct;
        (*count)++;
        printf("Product inserted into the array at position %d successfully!\n", position);
    }
}

// Function to search for a product by ID (array)
int searchProductByIdInArray(const struct Product inventory[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            return i; // Product found at index i
        }
    }
    return -1; // Product not found
}

// Function to sort the inventory by product name (array)
void sortInventoryArrayByName(struct Product inventory[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(inventory[i].name, inventory[j].name) > 0) {
                struct Product temp = inventory[i];
                inventory[i] = inventory[j];
                inventory[j] = temp;
            }
        }
    }
    printf("Inventory sorted by name successfully!\n");
}

// Structure for a stack
struct Stack {
    struct Product products[MAX_PRODUCTS];
    int top;
};

// Function to initialize a stack
void initStack(struct Stack* stack) {
    stack->top = 0;
}

// Function to push a product onto the stack
void pushToStack(struct Stack* stack, const struct Product* product) {
    if (stack->top < MAX_PRODUCTS) {
        stack->products[stack->top] = *product;
        stack->top++;
        printf("Product pushed to the stack successfully!\n");
    } else {
        printf("Stack is full. Cannot push more products.\n");
    }
}

// Function to pop a product from the stack
void popFromStack(struct Stack* stack) {
    if (stack->top > 0) {
        stack->top--;
        printf("Product popped from the stack successfully!\n");
    } else {
        printf("Stack is empty. Cannot pop.\n");
    }
}

// Function to display the stack
void displayStack(const struct Stack* stack) {
    printf("Stack (Last In, First Out):\n");
    for (int i = stack->top - 1; i >= 0; i--) {
        displayProduct(&stack->products[i]);
    }
}

int main() {
    struct Product inventoryArray[MAX_PRODUCTS];
    int countArray = 0;

    struct Stack productStack;
    initStack(&productStack);

    int choice;

    while (1) {
        printf("Inventory Management System\n");
        printf("1. Add Product \n");
        printf("2. Display Inventory \n");
        printf("3. Delete Product \n");
        printf("4. Insert Product \n");
        printf("5. Search Product by ID \n");
        printf("6. Sort Inventory by Name (Array)\n");
        printf("7. Push Product to Stack\n");
        printf("8. Pop Product from Stack\n");
        printf("9. Display Stack\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProductToArray(inventoryArray, &countArray);
                break;
            case 2:
                displayInventoryArray(inventoryArray, countArray);
                break;
            case 3:
                {
                    int idToDelete;
                    printf("Enter the ID of the product to delete: ");
                    scanf("%d", &idToDelete);
                    deleteProductFromArray(inventoryArray, &countArray, idToDelete);
                }
                break;
            case 4:
                {
                    int positionToInsert;
                    printf("Enter the position for insertion: ");
                    scanf("%d", &positionToInsert);
                    insertProductInArray(inventoryArray, &countArray, positionToInsert);
                }
                break;
            case 5:
                {
                    int idToSearch;
                    printf("Enter the ID of the product to search: ");
                    scanf("%d", &idToSearch);
                    int foundIndex = searchProductByIdInArray(inventoryArray, countArray, idToSearch);
                    if (foundIndex != -1) {
                        printf("Product found at index %d:\n", foundIndex);
                        displayProduct(&inventoryArray[foundIndex]);
                    } else {
                        printf("Product not found.\n");
                    }
                }
                break;
            case 6:
                sortInventoryArrayByName(inventoryArray, countArray);
                break;
            case 7:
                if (countArray > 0) {
                    pushToStack(&productStack, &inventoryArray[countArray - 1]);
                    countArray--;
                } else {
                    printf("Array is empty. Cannot push to the stack.\n");
                }
                break;
            case 8:
                popFromStack(&productStack);
                break;
            case 9:
                displayStack(&productStack);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

