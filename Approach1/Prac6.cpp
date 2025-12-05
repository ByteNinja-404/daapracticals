#include <iostream>

using namespace std;

struct Node {
    float data;
    Node* next;
};

// Insert into sorted linked list
void sortedInsert(Node*& head, float val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;

    // Special case for the head end
    if (!head || head->data >= val) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Locate the node before the point of insertion
    Node* current = head;
    while (current->next && current->next->data < val) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float* arr, int n) {
    // 1. Create n empty buckets (Arrays of pointers to Node)
    Node** buckets = new Node*[n];
    for(int i=0; i<n; i++) buckets[i] = NULL;

    //2. Add elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i]; // Index in bucket
        if (bi >= n) bi = n - 1; // Edge case for value 1.0
        sortedInsert(buckets[bi], arr[i]);
    }

    // 3. Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            Node* temp = curr;
            curr = curr->next;
            delete temp; // Free memory
        }
    }
    delete[] buckets; // Free bucket array
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    float* arr = new float[n];
    cout << "Enter " << n << " float elements (between 0 and 1): ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    bucketSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr; // Free array memory
    return 0;
}