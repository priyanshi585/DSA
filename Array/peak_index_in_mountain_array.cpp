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

int peakIndex(int arr[] , int size)
{
    int start = 0;
    int end = size - 1 ;
    
    while(start<end){
        int mid = start+(end-start)/2;
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else{
            end =mid ;
        }
        return start ;
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[100];
    inputArray(arr,size) ;
    printArray(arr,size);
    cout<<endl;
    int index = peakIndex(arr,size);
    cout<<"The peak in mountain array is :"<<index<<endl;
    return 0;


}