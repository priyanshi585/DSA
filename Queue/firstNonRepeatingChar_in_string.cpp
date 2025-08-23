#include <iostream>
#include <queue>
#include <map>
using namespace std;

string firstNonRepeating(string A)
{  
    map<char, int> count;
    string ans = "";
    queue<int> q;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        count[ch]++;
 
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string A = "aabc";
    string ans = firstNonRepeating(A);
    cout << "First Non Repeating Character in string: " << ans << endl;
    return 0;
}
