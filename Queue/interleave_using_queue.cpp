#include<iostream>
#include<queue>
using namespace std;

queue<int> interleaveTwoHalves(queue<int> q, int n) {
    queue<int> firstHalf;
    int half = n / 2;

    // Step 1: Move first half elements into another queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave first half and second half
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();
        q.push(q.front());
        q.pop();
    }

    return q;
}

void print(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    cout << "Original Queue: ";
    print(q);

    queue<int> ans = interleaveTwoHalves(q, 8);

    cout << "Queue after interleaving two halves: ";
    print(ans);

    return 0;
}
