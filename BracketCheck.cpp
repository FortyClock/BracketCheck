#include <iostream>
#include <stack>
using namespace std;

void main()
{
	// ( { [ <

	string line = ")({}(<>)[[]]";
	stack <char> container;

	container.push(line[0]);

	for (int i = 1; i < line.length(); i++)
	{
		if (line[i] == '(' || line[i] == '[' || line[i] == '{' || line[i] == '<')
			container.push(line[i]);

		else if (line[i] == ')' ||
				 line[i] == ']' ||
				 line[i] == '}' ||
				 line[i] == '>')
		{
			if (container.top() == '(' ||
				container.top() == '{' ||
				container.top() == '<' ||
				container.top() == '[')
				container.pop();
			else
				break;
		}		
	}


	if (container.empty())
		cout << true;       // expression is correct
	else
		cout << false;		// expression is uncorrect

}