#include <iostream>
#include <string>
#include "Stack.h"
#include "StackArray.h"
#include "Queue.h"
#include "QueueArray.h"

bool checkBalanceBrackets(const std::string& text, int maxDeep = 50);
bool testCheckBalanceBrackets();

using namespace std;

int main()
{
	try
	{
		StackArray<int> stk(5);
        stk.push(4);
        stk.push(5);
        stk.push(6);
        stk.push(7);
        stk.push(8);



		stk.print();
        cout << endl;
		stk.pop();

		stk.print();
        cout << endl;
		stk.pop();

		stk.print();
	}
	catch (Stack<int>::StackException& error)
	{
		cerr << error.getMessage();
		exit(-1);
	}	

    system("pause");
    system("cls");

	try
	{
		QueueArray<int> que(5);
		que.enQueue(2);
		que.enQueue(3);
		que.enQueue(4);
		que.enQueue(5);
		que.enQueue(6);

		que.print();
		cout << endl;
		que.deQueue();
		que.print();
		cout << endl;
		que.deQueue();
		que.print();
		cout << endl;
		que.enQueue(7);
		que.print();

	}
	catch (Queue<int>::QueueException& error)
	{
		cerr << error.getMessage();
		exit(-1);
	}

    system("pause");
    system("cls");

    testCheckBalanceBrackets();

	return 0;
}


bool checkBalanceBrackets(const std::string& text, int maxDeep)
{
    StackArray<char> stack(maxDeep);
    try
    {
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == '(' || text[i] == '[' || text[i] == '{')
            {
                stack.push(text[i]);
                continue;
            }
            if (text[i] == ')')
            {
                if (stack.top() != '(')
                {
                    return false;
                }
                stack.pop();
                continue;
            }
            if (text[i] == '}')
            {
                if (stack.top() != '{')
                {
                    return false;
                }
                stack.pop();
                continue;
            }
            if (text[i] == ']')
            {
                if (stack.top() != '[')
                {
                    return false;
                }
                stack.pop();
            }
        }
    }
    catch (Stack<char>::StackException& error)
    {
        return false;
    }
    return stack.isEmpty();
}

bool testCheckBalanceBrackets()
{
    const char* t0 = "{}))";
    std::cout << t0 << " -> " << (checkBalanceBrackets(t0) ? "Right" : "False") << "\n";


    const char* t1 = "()";
    std::cout << t1 << " -> " << (checkBalanceBrackets(t1) ? "Right" : "False") << "\n";


    const char* t2 = "{(([]))}";
    std::cout << t2 << " -> " << (checkBalanceBrackets(t2) ? "Right" : "False") << "\n";


    return true;
}