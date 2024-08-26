#include "functions.h"
#include <omp.h>

void show(const vector<int> &arr){
    cout<<"[ Array of size "<<arr.size()<<" ] ";
}
int main() {
    //create a random large vector of records using loops
    vector<Record> arr;
    for (int i = 0; i < 10000000; i++) {
        Record record;
        record.key = i;
        // Generate random integer data
        for (int j = 0; j < 10; j++) {
            record.int_data.push_back(rand() % 100);
        }
        arr.push_back(record);
    }
    vector<Record> arr1=arr;
    cout<<"Parallel Merge Sort"<<endl;
    auto start = high_resolution_clock::now();
    parallel_merge_sort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;

    cout<<"Sequential Merge Sort"<<endl;
    start = high_resolution_clock::now();
    merge_sort(arr1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;
    return 0;
}
