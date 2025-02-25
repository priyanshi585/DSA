#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v, int position){
    int s = position+1 ;
    int e = v.size()-1;
    while(s<=e)
    {
        swap(v[s],v[e]);
        s++;
        e--;
    }
    return v;
}

vector<int> printArray(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main()
{
    vector<int> v;
    v.push_back(11);
    v.push_back(14);
    v.push_back(21);
    v.push_back(8);
    v.push_back(61);
    int m;
    cout<<"Enter the position from where you want to reverse: "<<endl;
    cin>>m;
    vector<int> ans = reverse(v,m);
    printArray(ans);
    return 0;
}