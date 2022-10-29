#include <bits/stdc++.h>

using namespace std;

class StackWithMax
{
    vector<int> stack;
    int maximum;

public:
    StackWithMax()
    {
        this->maximum = INT8_MIN;
    }

    void Push(int value)
    {
        stack.push_back(value);
        if (value > maximum)
            maximum = value;
    }

    void Pop()
    {
        assert(stack.size());
        int temp = stack[stack.size() - 1];
        stack.pop_back();
        if (temp == maximum)
            maximum = *max_element(stack.begin(), stack.end());
    }

    int Max() const
    {
        assert(stack.size());
        return maximum;
    }
};

int main()
{
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i)
    {
        cin >> query;
        if (query == "push")
        {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop")
        {
            stack.Pop();
        }
        else if (query == "max")
        {
            cout << stack.Max() << "\n";
        }
        else
        {
            assert(0);
        }
    }
    return 0;
}