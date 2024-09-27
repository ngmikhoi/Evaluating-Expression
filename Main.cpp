#include "declaration.h"
int main() {
	string infixArithmetic = "(987+(654*(321/123)))^2-(456+789)";
	cout << "Infix: " << infixArithmetic << endl;
	cout << "Postfix: " << Infix2Postfix(infixArithmetic) << endl;
	cout << "Prefix: " << Infix2Prefix(infixArithmetic) << endl;
	cout << "Value of Postfix: " << PostfixPrefixCalculator(Infix2Postfix(infixArithmetic)) << endl;
	cout << "Value of Prefix: " << PostfixPrefixCalculator(Infix2Prefix(infixArithmetic)) << endl<<endl;
	string infixLogic = "~t->t&~w|(z&(p&(w&(p|p&q)|y&z&z)<->x&(~p|z)&~y))";
	string varlue = "t w z p q y x 1 1 1 1 1 1 1";
	cout << "Infix: " << infixLogic << endl;
	cout << "Postfix: " << LogicInfix2Postfix(infixLogic) << endl;
	cout << "Prefix: " << LogicInfix2Prefix(infixLogic) << endl;
	cout << "Variable value: " << varlue << endl;
	cout << "Value of Postfix: " << LogicPostfixPrefixCalculator(LogicInfix2Postfix(infixLogic), varlue) << endl;
	cout << "Value of Prefix: " << LogicPostfixPrefixCalculator(LogicInfix2Prefix(infixLogic), varlue) << endl;
	return 0;
}