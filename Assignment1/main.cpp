#include "functions.h"
#include <omp.h>

int main() {
    vector<Record> arr = {
        {689199, {544687}},
        {154777, {522225}},
        {317163, {178550}},
        {162933, {976547}},
        {991956, {590311}},
        {655508, {184317}},
        {538394, {354815}},
        {334007, {454298}},
        {554981, {518771}},
        {129588, {222662}} 
    };
    vector<Record> arr1=arr;
    cout<<"Parallel Merge Sort"<<endl;
    auto start = high_resolution_clock::now();
    parallel_merge_sort(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    for (const auto& record : arr) {
        cout << record.key << " " << record.int_data[0] << endl;
    }
    cout << "Time taken: " << duration.count() << " milliseconds" << endl << endl;

    cout<<"Sequential Merge Sort"<<endl;
    start = high_resolution_clock::now();
    merge_sort(arr1);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    
    for (const auto& record : arr1) {
        cout << record.key << " " << record.int_data[0] << endl;
    }
    cout << "Time taken: " << duration.count() << " milliseconds" << endl << endl;
    return 0;
}