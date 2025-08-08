#include<iostream>
using namespace std;

int getPivot(int arr[],int n){
    int s = 0;
    int e = n-1;

    while(s<e)
    {
        int mid = s + (e-s)/2 ;
        if(arr[mid]>=arr[0]){
            s = mid +1 ;
        }
        else{
            e = mid;
        }
    }
    return s;
}


int main()
{
   int arr[5] = {3 ,5, 6 ,9 ,10} ;
   cout<<"Index of pivot: "<<getPivot(arr,5);
   return 0;
 

}
