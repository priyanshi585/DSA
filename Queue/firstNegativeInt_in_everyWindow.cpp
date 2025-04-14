#include <iostream>
#include <queue>
using namespace std;

vector<long long> printFirstNegativeInt(long long int A[], long long int N, long long int K)
{
    deque<long long int> dq;
    vector<long long> ans;

    // process 1st window of k size:
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // store ans of 1st K-sized window:
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process for remaining windows:

    for (int i = K; i < N; i++)
    {
        // removal:
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }

        // addition:
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // store ans:
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
    long long int A[] = {-8 , 2 , 3, -6 , 10} ;
    long long int N = sizeof(A) / sizeof(A[0]); 
    long long int K = 2; 

    vector<long long> result = printFirstNegativeInt(A, N, K);

    // Print result
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;

}
