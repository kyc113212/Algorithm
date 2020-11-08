#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

	string s;
	stack<char> st;
	string post = "";

	cin >> s;

	for (int i = 0; i < s.size(); i++) {

		if (s[i] >= 48 && s[i] <= 57) {
			post += s[i];
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-') {
			if (st.empty()) {
				st.push(s[i]);
			}
			else {
				if (st.top() == '*' || st.top() == '/') {
					while (st.top() != '+' && st.top() != '-' && !st.empty()) {
						post += st.top();
						st.pop();
						if (st.empty())
							break;
					}
					st.push(s[i]);
				}
				else {
					st.push(s[i]);
				}
			}
		}
		else if (s[i] == '*' || s[i] == '/') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			while (st.top() != '(') {
				post += st.top();
				st.pop();
			}
			st.pop();
		}

	}

	while (!st.empty()) {
		post += st.top();
		st.pop();
	}

	cout << post << endl;

	stack<int> op;
	int sum = 0;
	for (int i = 0; i < post.size(); i++) {
		if (post[i] >= 48 && post[i] <= 57) {
			op.push(post[i] - '0');
		}
		else if (post[i] == '+') {
			int a, b;
			a = op.top();
			op.pop();
			b = op.top();
			op.pop();
			op.push(a + b);
		}
		else if (post[i] == '-') {
			int a, b;
			a = op.top();
			op.pop();
			b = op.top();
			op.pop();
			op.push(a - b);
		}
		else if (post[i] == '*') {
			int a, b;
			a = op.top();
			op.pop();
			b = op.top();
			op.pop();
			op.push(a * b);
		}
		else if (post[i] == '/') {
			int a, b;
			a = op.top();
			op.pop();
			b = op.top();
			op.pop();
			op.push(a / b);
		}

	}

	cout << op.top() << endl;

	return 0;
}
