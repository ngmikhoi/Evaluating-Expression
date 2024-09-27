#include "declaration.h"
int prior(char c) {
	if (c == '^') {
		return 3;
	}
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}
string Infix2Postfix(string infix) {
	string postfix;
	stack<char> st;
	int inLen = infix.length();
	for (int i = 0; i < inLen; i++) {
		char c = infix[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			postfix += c;
			char n = infix[i + 1];
			if (!(n >= 'a' && n <= 'z') && !(n >= 'A' && n <= 'Z') && !(n >= '0' && n <= '9')) {
				postfix += " ";
			}
		}
		else if (c == '(')
			st.push('(');

		else if (c == ')') {
			while (st.top() != '(') {
				postfix += st.top();
				postfix += " ";
				st.pop();
			}
			st.pop();
		}

		else {
			while (!st.empty() && prior(infix[i]) <= prior(st.top())) {
				postfix += st.top();
				postfix += " ";
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		postfix += st.top();
		postfix += " ";
		st.pop();
	}
	return postfix;
}
string Infix2Prefix(string infix) {
	reverse(infix.begin(), infix.end());
	string prefix;
	stack<char> st;
	int inLen = infix.length();
	for (int i = 0; i < inLen; i++) {
		char c = infix[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
			char n = infix[i - 1];
			if (!(n >= 'a' && n <= 'z') && !(n >= 'A' && n <= 'Z') && !(n >= '0' && n <= '9')) {
				prefix += " ";
			}
			prefix += c;
		}
		else if (c == ')')
			st.push(')');

		else if (c == '(') {
			while (!st.empty() && st.top() != ')') {
				prefix += " ";
				prefix += st.top();
				st.pop();
			}
			if (!st.empty())
				st.pop();
		}

		else {
			while (!st.empty() && prior(infix[i]) < prior(st.top())) {
				prefix += " ";
				prefix += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		prefix += " ";
		prefix += st.top();
		st.pop();
	}
	reverse(prefix.begin(), prefix.end());
	return prefix;
}
string PostfixPrefixCalculator(string input) {
	stack<double> st;
	int len = input.length();
	if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/' || input[0] == '^') {
		for (int j = len - 1; j >= 0; j--) {
			if (input[j] == ' ')
				continue;

			if (isdigit(input[j])) {
				double num = 0;
				int i = j;
				while (j < len && isdigit(input[j]))
					j--;
				j++;
				for (int k = j; k <= i; k++)
					num = double(num * 10 + double(input[k] - '0'));

				st.push(num);
			}
			else {

				double o1 = st.top();
				st.pop();
				double o2 = st.top();
				st.pop();
				switch (input[j]) {
				case '+':
					st.push(double(o1 + o2));
					break;
				case '-':
					st.push(double(o1 - o2));
					break;
				case '*':
					st.push(double(o1 * o2));
					break;
				case '/':
					st.push(double(o1 / o2));
					break;
				case '^':
					st.push(double(pow(o1, o2)));
					break;
				}
			}
		}
	}
	else {
		for (int j = 0; j < len; j++) {
			if (input[j] == ' ')
				continue;

			if (isdigit(input[j])) {
				double num = 0;
				int i = j;
				while (j >= 0 && isdigit(input[j]))
					j++;
				j--;
				for (int k = i; k <= j; k++)
					num = double(num * 10 + double(input[k] - '0'));

				st.push(num);
			}
			else {
				double o2 = st.top();
				st.pop();
				double o1 = st.top();
				st.pop();
				switch (input[j]) {
				case '+':
					st.push(double(o1 + o2));
					break;
				case '-':
					st.push(double(o1 - o2));
					break;
				case '*':
					st.push(double(o1 * o2));
					break;
				case '/':
					st.push(double(o1 / o2));
					break;
				case '^':
					st.push(double(pow(o1, o2)));
					break;
				}
			}
		}
	}
	double m = st.top();
	while (!st.empty()) {
		st.pop();
	}
	stringstream ss;
	ss << fixed << setprecision(4) << m;
	string res = ss.str();
	int resLen = res.length();
	for (int i = resLen - 1; i > resLen - 5; i--) {
		if (res[i] == '0')
			res.pop_back();
		else break;
	}
	if (res[resLen - 4] == '\0')
		res.pop_back();
	return res;
}
int logicPost(string str) {
	if (str == "~")
		return 4;
	else if (str == "|" || str == "&")
		return 3;
	else if (str == "->")
		return 2;
	else if (str == "<->")
		return 1;
	else
		return -1;
}
string LogicInfix2Postfix(string infix) {
	string postfix;
	stack<string> st;
	int inLen = infix.length();
	for (int i = 0; i < inLen; i++) {
		char c = infix[i];
		if (c == ' ')
			continue;
		string str;
		str += c;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			postfix += c;
		}
		else if (c == '(')
			st.push("(");

		else if (c == ')') {
			while (st.top() != "(") {
				postfix += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (c == '<') {
			str += "->";
			while (!st.empty() && logicPost(str) <= logicPost(st.top())) {
				postfix += st.top();
				st.pop();
			}
			st.push("<->");
			i += 2;
		}
		else if (c == '-') {
			str += ">";
			while (!st.empty() && logicPost(str) <= logicPost(st.top())) {
				postfix += st.top();
				st.pop();
			}
			st.push("->");
			i++;
		}
		else {
			while (!st.empty() && logicPost(str) <= logicPost(st.top())) {
				postfix += st.top();
				st.pop();
			}
			st.push(str);
		}
	}
	while (!st.empty()) {
		postfix += st.top();
		st.pop();
	}
	return postfix;
}
int logicPre(string str) {
	if (str == "~")
		return 4;
	else if (str == "|" || str == "&")
		return 3;
	else if (str == ">-")
		return 2;
	else if (str == ">-<")
		return 1;
	else
		return -1;
}
string LogicInfix2Prefix(string infix) {
	reverse(infix.begin(), infix.end());
	string prefix;
	stack<string> st;
	int inLen = infix.length();
	for (int i = 0; i < inLen; i++) {
		char c = infix[i];
		string str;
		str += c;
		if (c == ' ')
			continue;
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			prefix += c;
		}
		else if (c == ')')
			st.push(")");

		else if (c == '(') {
			while (!st.empty() && st.top() != ")") {
				prefix += st.top();
				st.pop();
			}
			if (!st.empty())
				st.pop();
		}
		else if (c == '>' && infix[i + 2] == '<') {
			str += "-<";
			while (!st.empty() && logicPre(str) < logicPre(st.top())) {
				prefix += st.top();
				st.pop();
			}
			st.push(">-<");
			i += 2;
		}
		else if (c == '>') {
			str += "-";
			while (!st.empty() && logicPre(str) < logicPre(st.top())) {
				prefix += st.top();
				st.pop();
			}
			st.push(">-");
			i++;
		}
		else {
			while (!st.empty() && logicPre(str) < logicPre(st.top())) {
				prefix += st.top();
				st.pop();
			}
			st.push(str);
		}
	}
	while (!st.empty()) {
		prefix += st.top();
		st.pop();
	}
	reverse(prefix.begin(), prefix.end());
	return prefix;
}
string LogicPostfixPrefixCalculator(string input, string varlue) {
	stack<bool> st;
	variable var[100];
	int numVar = 0;
	int h = 0;
	int len = input.length();
	int varlen = varlue.length();
	for (int i = 0; i < varlen; i++) {
		char ch = varlue[i];
		if (ch == ' ')
			continue;
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
			var[h].name = ch;
			h++;
		}
		else if (ch == '1') {
			var[numVar].value = 1;
			numVar++;
		}
		else if (ch == '0') {
			var[numVar].value = 0;
			numVar++;
		}
	}
	if (input[0] == '~' || input[0] == '|' || input[0] == '&' || input[0] == '-' || input[0] == '<') {
		for (int j = len - 1; j >= 0; j--) {
			char c = input[j];
			if (c == ' ')
				continue;
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				for (int i = 0; i < numVar; i++) {
					if (c == var[i].name) {
						bool temp = var[i].value;
						st.push(temp);
					}
				}
			}
			else if(!st.empty()) {
				if (c == '~') {
					bool o = st.top();
					st.pop();
					st.push(!o);
				}
				else if (c == '>' && j>=2 && input[j - 2] == '<') {
					j -= 2;
					bool o1 = st.top();
					st.pop();
					bool o2 = st.top();
					st.pop();
					if (o1 == o2)
						st.push(1);
					else st.push(0);
				}
				else if (c == '>') {
					j--;
					bool o1 = st.top();
					st.pop();
					bool o2 = st.top();
					st.pop();
					if (o1 == 1 && o2 == 0)
						st.push(0);
					else st.push(1);
				}
				else if (c == '|' || c == '&') {
					bool o1 = st.top();
					st.pop();
					bool o2 = st.top();
					st.pop();
					switch (c) {
					case '|':
						st.push(o1 || o2);
						break;
					case '&':
						st.push(o1 && o2);
						break;
					}
				}
			}
		}
	}
	else {
		for (int j = 0; j < len; j++) {
			char c = input[j];
			if (c == ' ')
				continue;
			if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
				for (int i = 0; i < numVar; i++) {
					if (c == var[i].name) {
						st.push(var[i].value);
					}
				}
			}
			else if(!st.empty()) {
				if (c == '~') {
					bool o = st.top();
					st.pop();
					st.push(!o);
				}
				else if (c == '<') {
					j += 2;
					bool o2 = st.top();
					st.pop();
					bool o1 = st.top();
					st.pop();
					if (o1 == o2)
						st.push(1);
					else st.push(0);
				}
				else if (c == '-') {
					j++;
					bool o2 = st.top();
					st.pop();
					bool o1 = st.top();
					st.pop();
					if (o1 == 1 && o2 == 0)
						st.push(0);
					else st.push(1);
				}
				else if (c == '|' || c == '&'){
					bool o2 = st.top();
					st.pop();
					bool o1 = st.top();
					st.pop();
					switch (c) {
					case '|':
						st.push(o1 || o2);
						break;
					case '&':
						st.push(o1 && o2);
						break;
					}
				}
			}
		}
	}
	string res;	
	if (!st.empty()) {
		if (st.top())
			res = "TRUE";
		else
			res = "FALSE";
	}
	while (!st.empty()) {
		st.pop();
	}
	return res;
}