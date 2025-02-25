#include<iostream>
using namespace std;

void inputArray(int arr[], int size)
{
    cout<<"Enter te array elements: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}

void printArray(int arr[] , int size)
{
    cout<<"Array elements: "<<endl;
    for(int i=0;i<size;i++)
    {
       cout<<arr[i]<<" ";
    }
}


int firstOccurance(int arr[], int size, int k)
{
    int start = 0;
    int last = size - 1 ;
    int ans = -1 ;

    while(start<=last)
    {
        int mid = start + (last-start)/2 ;
        if(arr[mid]==k){
            ans = mid;
            last = mid - 1;
        }
        else if(arr[mid]<k){
            start = mid +1 ;
        }
        else{
            last = mid - 1 ;
        }
        
    }
    return ans;
}

int lastOccurance(int arr[], int size, int k)
{
    int start = 0;
    int last = size - 1 ;
    int ans = -1 ;

    while(start<=last)
    {
        int mid = start + (last-start)/2 ;
        if(arr[mid]==k){
            ans = mid;
            start = mid + 1;
        }
        else if(arr[mid]<k){
            start = mid +1 ;
        }
        else{
            last = mid - 1 ;
        }
    }
    return ans;
}






int main()
{
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[100];
    inputArray(arr,size) ;
    printArray(arr,size);
    int k;
    cout<<"Enter the key to find occurance: "<<endl;
    cin>>k ;
    int first = firstOccurance(arr, size,  k);
    int second = lastOccurance( arr, size, k);
    return 0;


}