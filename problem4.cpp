#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

int main() {
    const int CAP = 100000;
    int A[CAP];

    int sizes[] = {100000};

    for (int n : sizes) {
        int* B = new int[n];

        // Static array
        auto start = high_resolution_clock::now();

        for (int i = 0; i < n; i++) {
            A[i] = i;
        }

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken: " << duration.count() << " microseconds" << endl;

        // Dynamic array
        start = high_resolution_clock::now();

        for (int i = 0; i < n; i++) {
            B[i] = i;
        }

        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        cout<< "Time taken: " << duration.count() << " microseconds" << endl;
        cout << "Dynamic array bytes: " << n * sizeof(int) << endl;
        return 0;
    }
}
