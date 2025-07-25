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

int printMax(int arr[],int size)
{

    int max = arr[0] ;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max = arr[i] ;
        }
    }
    return max;
}

int printMin(int arr[],int size)
{

    int min = arr[0] ;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min = arr[i] ;
        }
    }
    return min;
}



int main()
{
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[100];
    inputArray(arr,size) ;
    printArray(arr,size);

    cout<<"\nMaximum Element in given array is: "<<printMax(arr,size)<<endl;
    cout<<"Minimum Element in given array is: "<<printMin(arr,size)<<endl;
    return 0;


}
