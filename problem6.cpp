
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    int sizes[] = {1000, 5000, 10000, 50000, 100000};



    for (int n : sizes) {
        int* A = new int[n];
        int* copy1 = new int[n];
        int* copy2 = new int[n];

        // Generate random numbers
        for (int i = 0; i < n; i++) {
            A[i] = rand();
            copy1[i] = A[i];
            copy2[i] = A[i];
        }

        // Bubble sort
        auto start = high_resolution_clock::now();

        bubbleSort(copy1, n);

        auto stop = high_resolution_clock::now();

        double bubbleTime =
            duration<double, milli>(stop - start).count();

        // std::sort
        start = high_resolution_clock::now();

        sort(copy2, copy2 + n);

        stop = high_resolution_clock::now();

        double stdTime =
            duration<double, milli>(stop - start).count();
        cout<<"bubble time: "<<bubbleTime<<endl;
        cout<<"std time: "<<stdTime<<endl;
        cout<<"ratio: "<<bubbleTime/stdTime<<endl;


        delete[] A;
        delete[] copy1;
        delete[] copy2;
    }

    return 0;
}
