#include <bits/stdc++.h>

using namespace std;

void max_sliding_window_naive(vector<int> const &A, int w)
{
    for (size_t i = 0; i < A.size() - w + 1; ++i)
    {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));

        cout << window_max << " ";
    }
    return;
}

void max_sliding_window_fast(vector<int> const &A, int w)
{

    deque<int> q(w);
    int i;
    for (i = 0; i < w; i++)
    {
        while (!(q.empty()) and A[i] >= A[q.back()])
            q.pop_back();
        q.push_back(i);
    }

    for (; i < A.size(); i++)
    {
        cout << A[q.front()] << " ";

        while (!(q.empty()) and q.front() <= i - w)
            q.pop_front();

        while (!(q.empty()) and A[i] >= A[q.back()])
            q.pop_back();
        q.push_back(i);
    }
    cout << A[q.front()] << endl;
    return;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_fast(A, w);

    return 0;
}