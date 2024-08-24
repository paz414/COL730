#include "functions.h"

vector<Record> binary_search(vector<Record> &arr,int key){
    int l=0,r=arr.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(arr[m].key==key){
            vector<Record> result;
            result.push_back(arr[m]);
            return result;
        }
        if(arr[m].key<key) l=m+1;
        else r=m-1;
    }
    return vector<Record>();
}