#include<iostream>
using namespace std;


bool binary_search(int arr,int start,int end,int element)
{
    int mid = (start+end)/2 ;
    if( start>end){
        return false;
    }
    if(arr[mid]==element)
    {
        return true;
    }
    else if(arr[mid]<element)
    {
        return binary_search(arr,mid+1,end,element);
    }
    else{
        return binary_search(arr,start,mid-1,element)
    }
}
int main()
{
    int arr[5] = {3,2,5,1,6};
    int size = 5;
    int element = 4;
    int start = 0;
    int end=size-1;
    int ans = binary_search(arr,start,end,element);
    if(ans){
        cout<<"Element found."<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    
    return 0;
}