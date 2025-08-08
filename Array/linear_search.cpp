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


int linear_search(int arr[] , int size , int key )
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
           
            return i;
        }      
    }
     return -1;
}


int main()
{
    int size;
    cout<<"Enter the size of array: "<<endl;
    cin>>size;
    int arr[100];
    inputArray(arr,size) ;
    printArray(arr,size);
    int key;
    cout<<"\nEnter the element to be searched: "<<endl;
    cin>>key;

    int index = linear_search(arr,size,key);
    if(index == -1){
        cout<<"Element not found in the array."<<endl;
    }
    else{
        cout<<"Element is found at "<<index<<endl;
    }
    return 0;



}
