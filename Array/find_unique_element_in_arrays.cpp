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
    cout<<endl;
}


int findUnique(int arr[] , int size)
{
    int ans = 0;
    for(int i=0;i<size;i++)
    {
        ans = ans ^ arr[i] ;
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
    int uniqueElement = findUnique(arr,size) ;
    cout<<"Unique Element is: "<<uniqueElement<<endl;
    return 0;


}