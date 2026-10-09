
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};

int main() {
    const int n = 100000;
    const int key = n - 1;
    vector<int> v;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }

    auto stop = high_resolution_clock::now();
    auto vectorInsert = duration_cast<microseconds>(stop - start).count();

    start = high_resolution_clock::now();

    int vectorIndex = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == key) {
            vectorIndex = i;
            break;
        }
    }

    stop = high_resolution_clock::now();
    auto vectorSearch = duration_cast<microseconds>(stop - start).count();

    int* A = new int[n];

    start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        A[i] = i;
    }

    stop = high_resolution_clock::now();
    auto arrayInsert = duration_cast<microseconds>(stop - start).count();

    start = high_resolution_clock::now();

    int arrayIndex = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] == key) {
            arrayIndex = i;
            break;
        }
    }

    stop = high_resolution_clock::now();
    auto arraySearch = duration_cast<microseconds>(stop - start).count();

    Node* head = nullptr;
    Node* tail = nullptr;

    start = high_resolution_clock::now();

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node{i, nullptr};

        if (head == nullptr) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;
    }

    stop = high_resolution_clock::now();
    auto listInsert = duration_cast<microseconds>(stop - start).count();

    start = high_resolution_clock::now();

    Node* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data == key) {
            found = true;
            break;
        }
        current = current->next;
    }

    stop = high_resolution_clock::now();
    auto listSearch = duration_cast<microseconds>(stop - start).count();

    cout << "Structure | Insert(us) | Search(us) | Total bytes\n";

    cout << "Vector: "
         << vectorInsert << " | "
         << vectorSearch << " | "
         << v.capacity() * sizeof(int) << endl;

    cout << "Array: "
         << arrayInsert << " | "
         << arraySearch << " | "
         << n * sizeof(int) << endl;

    cout << "Linked list: "
         << listInsert << " | "
         << listSearch << " | "
         << n * sizeof(Node) << endl;

    cout << "Bytes per int: " << sizeof(int) << endl;
    cout << "Bytes per node: " << sizeof(Node) << endl;

    // Prevent unused search results
    cout << "Found positions: "
         << vectorIndex << ", " << arrayIndex
         << " | List found: " << found << endl;

    // Free memory
    delete[] A;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
