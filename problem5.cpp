
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int main() {
    int sizes[] = {100000};

    for (int n : sizes) {

        // (a) Without reserve
        vector<int> v;
        int jumps = 0;
        size_t oldCapacity = v.capacity();

        auto start = high_resolution_clock::now();

        for (int i = 0; i < n; i++) {
            v.push_back(rand());

            if (v.capacity() != oldCapacity) {
                jumps++;
                oldCapacity = v.capacity();
            }
        }

        auto stop = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop - start);

        // (b) With reserve
        vector<int> w;
        w.reserve(n);

        start = high_resolution_clock::now();

        for (int i = 0; i < n; i++) {
            w.push_back(rand());
        }

        stop = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop - start);

        cout << "Push_back only: " << duration1.count() << " microseconds" << endl;
        cout << "Reserve + push_back: " << duration2.count() << " microseconds" << endl;
        cout << "Capacity jumps: " << jumps << endl;

    }

    return 0;
}
