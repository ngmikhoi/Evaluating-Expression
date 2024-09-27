#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int prior(char c);
string Infix2Postfix(string infix);
string Infix2Prefix(string infix);
string PostfixPrefixCalculator(string input);
int logicPost(string str);
string LogicInfix2Postfix(string infix);
int logicPre(string str);
string LogicInfix2Prefix(string infix);
struct variable {
	char name;
	bool value;
};
string LogicPostfixPrefixCalculator(string input, string varlue);