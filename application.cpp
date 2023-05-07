#include "stack.h"

bool is_match(char open, char close);
bool line_correct(string line);

int main()
{
	string line;
	cout << "Enter line: ";
	getline(cin, line, ';');

	if (line_correct(line))
		cout << "Line is correct" << endl;
	else
	{
		cout << "Line is not correct. Error found as position : " << endl;
		stack<int> error_pos;
		stack<char> s;
		for (size_t i = 0; i < line.length(); i++)
		{
			if (line[i] == '(' || line[i] == '[' || line[i] == '{')
			{
				s.push(line[i]);
				error_pos.push(i);
			}
			else if (line[i] == ')' || line[i] == ']' || line[i] == '}')
			{
				if (s.isEmpty() || !is_match(s.top(), line[i]))
				{
					cout << i << endl;
					break;
				}
				else
				{
					s.pop();
					error_pos.push(i);
				}
			}
		}
	}
	return 0;
}

bool is_match(char open, char close)
{
	return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}
bool line_correct(string line)
{
	stack<char> st;
	for (size_t i = 0; i < line.length(); i++)
	{
		if (line[i] == '(' || line[i] == '[' || line[i] == '{')
			st.push(line[i]);
		else if (line[i] == ')' || line[i] == ']' || line[i] == '}')
		{
			if (!is_match(st.top(), line[i]))
				return false;
			else
				st.pop();
		}
	}
	return st.isEmpty();
}