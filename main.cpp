#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int arraySum(int A[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
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

    arraySum(A, n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl;

    return 0;
}
