#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>  // For benchmarking
using namespace std;

vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int target = 8;

void binary_search(vector<int> array, int target) {
    int left = 0;
    int right = array.size() - 1; 

    while (left <= right) {
        int mid = (left + right) / 2;

        if (array[mid] == target) {
            cout << "Found the value at index " << mid << endl;
            return;  
        }
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

int main() {
    // Benchmarking: measuring the execution time of 1000 runs
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < 1000; ++i) {
        binary_search(arr, target);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Execution time for 1000 runs: " << duration.count() << " seconds" << endl;

    return 0;
}
