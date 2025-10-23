#include<iostream>
using namespace std;

void inputArray(int arr[], int size)
{
    cout<<"Enter te array elements: "<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<endl;
}
  
void printArray(int arr[] , int size)
{
    cout<<"Array elements: "<<endl;
    for(int i=0;i<size;i++)
    {
       cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printReverse(int arr[] , int size)
{
    cout<<"Reversed Array: "<<endl;
    for(int i=size-1;i>=0;i--)
    {
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
}



int main()
{
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[100];
    inputArray(arr,size) ;
    printArray(arr,size);
    printReverse(arr,size) ;
    return 0;



}
