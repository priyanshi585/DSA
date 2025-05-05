#include<iostream>
#include<queue>
using namespace std;

int kthSmallest(int arr[] , int l , int r  , int k){
    priority_queue<int> pq;

    for(int i = 0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i = k ; i<=r ; i++){
        if(arr[i]<pq.top()){
            pq.pop() ;
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[5] = {7 , 10 ,4 , 20 , 15} ;
    int l =0 ;
    int r = 4;
    int k = 4;
    int ans = kthSmallest(arr , l , r, k);
    cout<<"Kth Smallest Element: "<<ans<<endl;
    return 0;
}
