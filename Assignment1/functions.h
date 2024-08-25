#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <random>

using namespace std;
using namespace std::chrono;

struct Record {
    int key;
    vector<int> int_data;
};

void merge_sort(vector<Record> &arr);
void parallel_merge_sort(vector<Record> &arr);
vector<Record> binary_search(vector<Record> &arr, int key);
vector<Record> parallel_binary_search(vector<Record> &arr, int key);
