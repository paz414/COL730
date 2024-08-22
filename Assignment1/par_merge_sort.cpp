#include <omp.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>
#include "functions.h"
using namespace std;
using namespace std::chrono;

void p_merge(vector<Record> &arr, int l, int mid, int r) {
    int p = mid - l + 1;
    int q = r - mid;
    vector<Record> L(p), R(q);
    for (int i = 0; i < p; i++) L[i] = arr[l + i];
    for (int i = 0; i < q; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < L.size() && j < R.size()) {
        if (L[i].key <= R[j].key) {
            arr[k] = L[i];
            i++;        
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < L.size()) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < R.size()) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void p_sort(vector<Record> &arr, int l, int r, int depth) {
    if (l >= r) return;

    int m = l + (r - l) / 2;

    if (depth > 0) {
        #pragma omp task shared(arr)
        p_sort(arr, l, m, depth - 1);

        #pragma omp task shared(arr)
        p_sort(arr, m + 1, r, depth - 1);

        #pragma omp taskwait
    } else {
        p_sort(arr, l, m, 0);
        p_sort(arr, m + 1, r, 0);
    }

    p_merge(arr, l, m, r);
}

void parallel_merge_sort(vector<Record> &arr) {
    int n = arr.size();
    int num_threads = omp_get_max_threads();
    int max_depth = log2(num_threads); // Determine the depth of parallelism

    #pragma omp parallel
    {
        #pragma omp single
        {
            p_sort(arr, 0, n - 1, max_depth);
        }
    }
}

// int main() {
//     vector<Record> arr = {
//         {689199, {544687}},
//         {154777, {522225}},
//         {317163, {178550}},
//         {162933, {976547}},
//         {991956, {590311}},
//         {655508, {184317}},
//         {538394, {354815}},
//         {334007, {454298}},
//         {554981, {518771}},
//         {129588, {222662}} 
//     };
//     auto start = high_resolution_clock::now();
//     parallel_merge_sort(arr);
//     auto stop = high_resolution_clock::now();
//     auto duration = duration_cast<milliseconds>(stop - start);

//     for (const auto& record : arr) {
//         cout << record.key << " " << record.int_data[0] << endl;
//     }
//     cout << "Time taken: " << duration.count() << " milliseconds" << endl << endl;
//     return 0;
// }
