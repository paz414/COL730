#include <omp.h>
#include "functions.h"

// Sequential binary search
int binary_search(const vector<Record>& arr, int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid].key == key)
            return mid;
        
        if (arr[mid].key < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1; // Key not found
}

// Parallel binary search
vector<Record> parallel_binary_search(vector<Record>& arr, int key) {
    vector<Record> results;
    int n = arr.size();
    omp_set_num_threads(4);
    int num_threads = omp_get_max_threads();
    int chunk_size = n / num_threads;
    
    #pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();
        int start = thread_id * chunk_size;
        int end = (thread_id == num_threads - 1) ? n - 1 : start + chunk_size - 1;
        
        if (arr[start].key <= key && arr[end].key >= key) {
            int result = binary_search(arr, start, end, key);
            
            if (result != -1) {
                #pragma omp critical
                {
                    results.push_back(arr[result]);
                }
            }
        }
    }
    
    return results;
}
