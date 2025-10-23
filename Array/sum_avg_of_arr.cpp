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

int printSum(int arr[] , int size)
{
    int sum = 0;
    for(int i=0;i<size;i++){
        sum = sum + arr[i] ;
    }
    return sum ;
}

int printAvg(int arr[] , int size)
{
    int avg = 0;
    for(int i=0;i<size;i++)
    {
        int sum = printSum(arr,size);
        avg = sum/size;
    }
    return avg ;
}



int main()
{
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[100];
    inputArray(arr,size) ;
    printArray(arr,size);
    cout<<"/nSum of array elements is: "<<printSum(arr,size)<<endl;
    cout<<"/nAverage of array elements is: "<<printAvg(arr,size)<<endl;
    return 0;



}
