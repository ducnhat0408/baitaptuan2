#include <iostream>
#include <string>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    string s;
    stack <int> a;
    fstream input;
    input.open("BRACKET.INP");
    input >> s;
    input.close();
    ofstream output("BRACKET.OUT");

    // xử lý xâu ngoặc
    for (int i=0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            a.push(i);  // nếu là ngoặc mở thì push i vào stack
        }
        if (s[i] == ')')
        {
            if ((!a.empty())     && (s[a.top()] == '('))
            {
                a.pop(); // stack ko rỗng và phân tử trên cùng stack ko là ngoặc ')' thì lấy ra khỏi stack
            }
            else
            {
                a.push(i); // ngược lại thì tiếp tục push i
            }

        }
    }

    //  thêm ngoặc
    if (a.empty())
    {
        cout << "0" ;
        output << "0";
    }
    else
    {
        cout <<  a.size() << "\n" ;
        output << a.size() << "\n";
        while (!a.empty())
        {
            if (s[a.top()] == ')')
            {
                cout << "(" << a.top() << "\n";
                output << "(" << a.top() << "\n";
                a.pop();
            }
            else
            {
                cout << ")" << (a.top() + 1) << "\n";
                output << ")" << (a.top() + 1) << "\n";
                a.pop();
            }
        }
    }
    output.close();
    return 0;
}



