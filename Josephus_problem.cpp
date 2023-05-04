/*
Student Name: Mazin Mohammad Mostafa
ID: 200011389
*/

//Josephus Problem
#include <iostream>
using namespace std;

// Node structure for circular linked list
struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

// Function to create a circular linked list of n nodes
Node* createCircularLinkedList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 1; i <= n; i++) {
        
        Node* curr = new Node(i);           // curr stands for current node
        
        if (head == nullptr) {
            head = tail = curr;
            head->next = tail;
        }
        else {
            tail->next = curr;
            curr->next = head;
            tail = curr;
        }
    
    }
    return head;
}

// Function to solve the Josephus problem using a circular linked list
int josephusProblem(Node* head, int k) {
    
    if (head == nullptr || k == 0) {
        return -1;
    }
    
    Node* curr = head;
    
    while (curr->next != curr) {
        
        // Find the k-th node
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        
        // Delete the k-th node
        Node* temp = curr->next;
        curr->next = curr->next->next;
        cout << "Position " << temp->value << " has been eliminated." << endl;
        delete temp;
        curr = curr->next;
    }
    
    return curr->value;
}

int main() {
    
    int n ; // Number of nodes
    cout << "Enter number of persons: "; cin >> n;

    int k ; // number of moves/steps
    cout << "Enter number of moves/steps: "; cin >> k;
    
    Node* head = createCircularLinkedList(n);
    
    int winner = josephusProblem(head, k);  // find the winner's position
    
    cout << "The winner is at position: " << winner << endl;
    
    return 0;
}