//main.cpp -- kmgumienny

#include <iostream>
#include "Rational.h"
#include "string.h"
using namespace std;

/**
 * rationalMath has an outer loop that makes checks for a
 * new line or end of file. The loop sets booleanOperator
 * and booleanResult to false for every line in the
 * text file. In the first loop, a Rational object is created,
 * read in and printed out. Then the inner loop is created that
 * creates a second rational that is read in and printed and
 * a string op checks stores the operator. The second rational
 * and the operator are printed out. The operator is then
 * searched for through a series of elifs and the operation
 * is performed. The result of the operation is stored as the
 * first rational created and the second loop continues to loop
 * for as many other rationals are there are on that line of text.
 * an if statement checks if it's EOF. If not, it removes /n from txt.
 * Finally, the result of the math is printed out, a result and a double
 * variant of the rational if the operator is arithmetic. If the operator
 * wasn't arithmetic, it prints out the boolean result of the operation
 *
 * First loop invariant: loop continues until whole line of text
 * is read in from file.
 *
 * Second loop invariant: Loop continues until the last operator on the line
 * is read in and /n is reached.
 *
 * bool booleanOpertor checks the operator and sees it it is arithmetic operator.
 * bool booleanResult is the result of a boolean operator.
 */
void rationalMath(ifstream &input) {
	while (input.peek() != '\n' && input.peek() != EOF) {
		// loop invariant: loop continues until whole line of text
		// is read in from file.
		Rational rat1;
		bool booleanOperator = false;
		bool booleanResult = false;
		input >> rat1;
		cout << rat1 << " ";
		while (input.peek() != '\n' && input.peek() != EOF) {
			// Second loop invariant: Loop continues until the last
			// operator on the line is read in and /n is reached.
			Rational rat2;
			string op;
			input >> rat2;
			input >> op;
			cout << rat2 << " " << op << " ";
			if (op == "+") {
				rat1 = rat1+rat2;
				booleanOperator = false;
			} else if (op == "-") {
				rat1 = rat1-rat2;
				booleanOperator = false;
			} else if (op == "*") {
				rat1 = rat1*rat2;
				booleanOperator = false;
			} else if (op == "/") {
				rat1 = rat1/rat2;
				booleanOperator = false;
			} else if (op == "+=") {
				rat1 += rat2;
				booleanOperator = false;
			} else if (op == "-=") {
				rat1-=rat2;
				booleanOperator = false;
			} else if (op == "*=") {
				rat1*=rat2;
				booleanOperator = false;
			} else if (op == "/=") {
				rat1/=rat2;
				booleanOperator = false;
			} else if (op == "==") {
				booleanResult = rat1 == rat2;
				booleanOperator = true;
			} else if (op == "!=") {
				booleanResult = rat1 != rat2;
				booleanOperator = true;
			} else if (op == "<") {
				booleanResult = rat1 < rat2;
				booleanOperator = true;
			} else if (op == "<=") {
				booleanResult = rat1 <= rat2;
				booleanOperator = true;
			} else if (op == ">") {
				booleanResult = rat1 > rat2;
				booleanOperator = true;
			} else if (op == ">=") {
				booleanResult = rat1 >= rat2;
				booleanOperator = true;
			}
		}
		if (input.peek() != EOF) {
			input.get();
		}
		if (booleanOperator) {
			cout << "\t= " << boolalpha << booleanResult << noboolalpha << endl;
		} else {
			cout << "\t= " << rat1 << " (double " << rat1.toDouble() << ")" << endl;
		}
	}
}

/*
 * main first checks to see that at least 2 arguments were
 * given in terminal. Then a for loop is created that goes through
 * all the input text files and calls rationalMath function to
 * perform math on the rationals in the text file. Once it finishes,
 * the file is closed and the loop continues until there are no
 * more files.
 * loop invariant: i < text files provided & i > 1
 */
int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Not enough argument. Exiting.");
		exit(0);
	}
	else {
		for (int i = 1; i < argc; i++) {
			//loop invariant: i < text files provided & i > 1
			ifstream input(argv[i]);
			if (!input) {
				printf("Error: Unable To Open File\n");
				exit(0);
			}
			cout << "File: " << i << endl;
			rationalMath(input);
			input.close();
		}
	}
	return 0;
}

