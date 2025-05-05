#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int getkthLargest(vector<int> &arr , int k)
{
    priority_queue<int , vector<int> , greater<int> > mini;
    int n = arr.size();
    for(int i = 0;i<n ; i++){
        int sum = 0;
        for(int j = i; j <n ; j++){
           sum = sum + arr[j];

           if(mini.size()<k){
            mini.push(sum);
           }
           else{
            if(sum>mini.top()){
                mini.pop();
                mini.push(sum);
            }
           }
        }
    }
 return mini.top();
}

int main()
{
    vector<int> arr = {1 , 2 , 6, 4, 3};
    int k = 4;
    int ans = getkthLargest(arr , k);
    cout<<"Kth Largest Sum Subaaray is: "<<ans<<endl;
    return 0;
}
