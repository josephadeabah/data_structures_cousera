#include <bits/stdc++.h>

using namespace std;

struct Bracket
{
    Bracket(char type, int position) : type(type),   position(position){
    }

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{
    std::string text;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position)
    {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here
            Bracket *b = new Bracket(next, position);
            opening_brackets_stack.push(*b);
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty())
            {
                std::cout << position + 1 << std::endl;
                return 0;
            }
            Bracket b = opening_brackets_stack.top();
            if (b.Matchc(next))
                opening_brackets_stack.pop();
            else
            {
                std::cout << position + 1 << std::endl;
                return 0;
            }
        }
    }

    // Printing answer, write your code here
    if (opening_brackets_stack.empty())
        std::cout << "Success" << std::endl;
    else
    {
        while (opening_brackets_stack.size() != 1)
            opening_brackets_stack.pop();

        Bracket temp = opening_brackets_stack.top();
        std::cout << temp.position + 1 << std::endl;
    }
    return 0;
}