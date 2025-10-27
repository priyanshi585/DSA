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

int binary_search(int arr[] , int size , int key)
{
    int low = 0;
    int high = size-1;
    while(low<=high)
    {
        if(size == 0){
            return -1;
        }
        else{
            int mid = (low+high)/2  ;
            if(arr[mid]==key){
                return mid ;
            }
            else if(arr[mid]>key){
                high = mid-1 ;
            }
            else{
                low = mid+1 ;
            }
        }
    }
    return -1 ;
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
    cout<<"Enter the element to be searched: "<<endl;
    cin>>key;

    int index = binary_search(arr,size,key);
    if(index == -1)
    {
        cout<<"Element Not found in array."<<endl;
    }
    else{
        cout<<"Element is found at index "<<index<<endl;
    }
   
    return 0;


}


