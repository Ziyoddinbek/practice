#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int linearSearch(int A[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (A[i] == key) return i;
    }
    return -1;
}


int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i]=rand()%100;
    }
    auto start = high_resolution_clock::now();

    linearSearch(A, n, A[n/2]);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
