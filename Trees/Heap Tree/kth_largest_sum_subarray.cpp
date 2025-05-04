#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getkthLargest(vector<int> &arr , int k)
{
    vector<int> sumStore ;
    int n = arr.size();

    for(int i =0; i<n ; i++){
        int sum = 0;
        for(int j = i ; j <n ;j++){
            sum = sum+ arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin() , sumStore.end());
    int L = sumStore.size();
    return sumStore[L-k];
}

int main()
{
    vector<int> arr = {1 , 2 , 6, 4, 3};
    int k = 4;
    int ans = getkthLargest(arr , k);
    cout<<"Kth Largest Sum Subaaray is: "<<ans<<endl;
    return 0;
}
