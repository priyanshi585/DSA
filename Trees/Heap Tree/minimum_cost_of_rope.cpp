#include<iostream>
#include<queue>
using namespace std;

long long minimumCost(long long arr[] , long long n ){
    priority_queue<long long , vector<long long>  , greater<long long> > pq;
    
    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }

    long long cost = 0;

    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();

        long long sum= a+b;
        cost = cost+sum;
        pq.push(sum);
    }
    return cost;
}

int main()
{
    long long arr[4] = {4 , 3 , 2  , 6};
    long long n = 4;

    long long cost = minimumCost(arr , n);
    cout<<"Minimum Cost of ropes is: "<<cost<<endl;
    return 0;
}
