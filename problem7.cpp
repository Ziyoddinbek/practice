
#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int main() {
    int sizes[] = {50, 100, 200, 400, 800};

    for (int n : sizes) {


        vector<vector<int>> A(n, vector<int>(n));
        vector<vector<int>> B(n, vector<int>(n));
        vector<vector<int>> C(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }
        }


        auto start = high_resolution_clock::now();


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }


        auto stop = high_resolution_clock::now();

        double duration =
            duration_cast<nanoseconds>(stop - start).count() / 1000000.0;

        cout << "n = " << n << endl;
        cout << "Multiply time: " << duration << " ms" << endl;
        cout << "Approx. bytes: "
             << 3LL * n * n * sizeof(int) << endl;

    }

    return 0;
}
