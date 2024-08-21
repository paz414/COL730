#include "functions.h"
#include <omp.h>
using namespace std;

void parallel_binary_search(vector<Record> &arr, int key, vector<Record> &result){
    int l=0,r=arr.size()-1;
    #pragma omp parallel
    {
        #pragma omp single
        {
            cout<<"Number of threads: "<<omp_get_num_threads()<<endl;
            //parallel_search(arr,l,r,key,result);
        }
    }
}
int main(){
    cout<<"Enter the number of records: ";
}