
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

long long fibRecursive(int n) {
    if (n <= 1) return n;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}
long long fibIterative(int n) {
    long long a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        long long next = a + b;
        a = b;
        b = next;
    }

    return a;
}

int main() {
    int sizes[] = {20, 25, 30, 35, 1000};

    for (int n : sizes) {
        cout << "n = " << n << endl;


        if (n <= 35) {
            auto start = high_resolution_clock::now();

            long long result = fibRecursive(n);

            auto stop = high_resolution_clock::now();

            auto duration =
                duration_cast<microseconds>(stop - start);

            cout << "Recursive: "<< duration.count() << " ms" << endl;
        } else {
            cout << "Recursive: skipped" << endl;
        }


        auto start = high_resolution_clock::now();

        long long result = fibIterative(n);

        auto stop = high_resolution_clock::now();

        auto duration =
            duration_cast<microseconds>(stop - start);

        cout << "Iterative: "
             << duration.count() << " us" << endl;



    }

    return 0;
}
