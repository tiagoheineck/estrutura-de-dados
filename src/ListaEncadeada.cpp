#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insert(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void display(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    display(head);

    return 0;
}
