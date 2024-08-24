#include "functions.h"

void merge(vector<Record> &arr, int l, int m,int r){

    int p=m-l+1;
    int q=r-m;
    vector<Record> L(p),R(q);

    for(int i=0;i<p;i++) L[i]=arr[l+i];
    for(int i=0;i<q;i++) R[i]=arr[m+1+i];

    int i=0,j=0,k=l;

    while(i<L.size() && j<R.size()){
        if(L[i].key<=R[j].key){
            arr[k]=L[i];
            i++;        
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<L.size()){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<R.size()){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void sort(vector<Record> &arr,int l, int r){
    if(l>=r) return;

    int m= l+(r-l)/2;
    sort(arr,l,m);
    sort(arr,m+1,r);
    merge(arr,l,m,r);
}
void merge_sort(vector<Record> &arr){
    sort(arr,0,arr.size()-1);
}