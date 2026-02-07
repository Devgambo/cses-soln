#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define the maximum size of the priority queue

// Function declarations
void insert_by_priority(int data);
void delete_by_priority(int data);
void create_queue();
void check_priority(int data);
void display_queue();

// Priority queue array and front/rear pointers
int pri_queue[MAX];
int front, rear;

// Main function
int main() {
    int choice, value;

    // Menu for user interaction
    printf("Priority Queue Implementation\n");
    printf("1 - Insert an element into the queue\n");
    printf("2 - Delete an element from the queue\n");
    printf("3 - Display queue elements\n");
    printf("4 - Exit\n");

    // Initialize the priority queue
    create_queue();

    // Infinite loop to handle menu-based operations
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to be inserted: ");
                scanf("%d", &value);
                insert_by_priority(value);
                break;
            case 2:
                printf("\nEnter value to delete: ");
                scanf("%d", &value);
                delete_by_priority(value);
                break;
            case 3:
                display_queue();
                break;
            case 4:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }

    return 0;
}

// Function to initialize the queue
void create_queue() {
    front = rear = -1; // Set both pointers to -1 indicating an empty queue
}

// Function to insert an element into the priority queue
void insert_by_priority(int data) {
    if (rear >= MAX - 1) {
        printf("\nQueue overflow! No more elements can be inserted.");
        return;
    }

    if (front == -1 && rear == -1) { // If the queue is empty
        front = rear = 0;
        pri_queue[rear] = data;
    } else {
        check_priority(data);
        rear++;
    }
}

// Function to check priority and place the element in the correct position
void check_priority(int data) {
    int i, j;

    for (i = 0; i <= rear; i++) {
        if (data >= pri_queue[i]) { // Find the correct position based on priority
            // Shift elements to make space for the new element
            for (j = rear + 1; j > i; j--) {
                pri_queue[j] = pri_queue[j - 1];
            }
            pri_queue[i] = data; // Insert the element at the correct position
            return;
        }
    }
    pri_queue[i] = data; // Insert at the end if no higher priority found
}

// Function to delete an element from the priority queue
void delete_by_priority(int data) {
    int i;

    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("\nQueue is empty! No elements to delete.");
        return;
    }

    // Search for the element to delete
    for (i = 0; i <= rear; i++) {
        if (pri_queue[i] == data) {
            // Shift elements to fill the gap
            for (; i < rear; i++) {
                pri_queue[i] = pri_queue[i + 1];
            }
            rear--;

            // Reset front and rear if the queue becomes empty
            if (rear == -1) {
                front = -1;
            }
            printf("\n%d deleted from the queue.", data);
            return;
        }
    }

    printf("\n%d not found in the queue.", data);
}

// Function to display all elements in the priority queue
void display_queue() {
    if (front == -1 && rear == -1) { // Check if the queue is empty
        printf("\nQueue is empty.");
        return;
    }

    printf("\nPriority Queue Elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", pri_queue[i]);
    }
}
