#include "functions.h"
#include <omp.h>

void show(const vector<int> &arr){
    cout<<"[ Array of size "<<arr.size()<<" ] ";
}
int main() {
    //create a random large vector of records using loops
    vector<Record> arr;
    int size=1000000;
    int k=10;
    for (int i = 0; i < size; i++) {
        Record record;
        record.key = rand() % size;
        // Generate random integer data
        for (int j = 0; j < k; j++) {
            record.int_data.push_back(rand() % 100);
        }
        arr.push_back(record);
    }
    //test sort
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

    //test search
    int key=rand()%size;
    cout<<"Key Being Searched: "<<key<<endl;
    cout<<"Parallel Binary Search"<<endl;
    start = high_resolution_clock::now();
    vector<Record> result=parallel_binary_search(arr,key);
    // cout<<"Results: ";
    // for(auto &record:result){
    //     cout<<record.key<<" ";
    //     for(auto &data:record.int_data)
    //         cout<<data<<" ";    
    //     cout<<endl;
    // }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;


    cout<<"Sequential Binary Search"<<endl;
    start = high_resolution_clock::now();
    vector<Record> result1=binary_search(arr,key);
    // cout<<"Results: ";
    // for(auto &record:result1){
    //     cout<<record.key<<" ";
    //     for(auto &data:record.int_data)
    //         cout<<data<<" ";    
    //     cout<<endl;
    // }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds" << endl << endl;
    return 0;
}
