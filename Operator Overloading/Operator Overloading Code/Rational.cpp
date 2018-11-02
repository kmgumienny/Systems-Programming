//Rational.cpp -- kmgumienny

#include "Rational.h"
#include <algorithm>


/*
 * Default constructor for a Rational.
 */
Rational::Rational() {
	numerator = 0;
	denominator = 1;
}
/*
 * Copy constructor for a rational.
 */
Rational::Rational(const Rational &aRat) {
	numerator = aRat.numerator;
	denominator = aRat.denominator;
}
/*
 * Constructor for Rational that is a whole number.
 */
Rational::Rational(const int wholeNum) {
	numerator = wholeNum;
	denominator = 1;
}
/*
 * Constructor for Rational. Takes in a numerator
 * and denominator and sets the rational's numerator
 * and denominator to the two parameters. If the
 * provided den is 0, the program exits.
 */
Rational::Rational(const int num, const int den){
	numerator = num;
	if (den == 0) {
		cout << "Denominator cannot be 0." << endl;
		exit(0);
	}
	else {
		denominator = den;
	}
	this->normalize(num, den);
}

/*
 * normalize finds the greatest common denominator by calling
 * the gcd function from the algorithm library. Once
 * the gcd is found, it divides the numerator and denominator
 * by the gcd. It checks to see if the denominator is negative.
 * If it is, it multiplies the numirator and denominator by -1.
 */
Rational &Rational::normalize(long long int num, long long int denom) {
	long long int gcd = __gcd(num, denom);
	numerator = num / gcd;
	denominator = denom / gcd;
	if (denom < 0) {
		numerator *= -1;
		denom *= -1;
	}
	return *this;
}

/*
 * Takes a rational and pulls its numerator and
 * denominator out. It then divides the two and
 * returns the value.
 */
double Rational::toDouble() const {
	double num = numerator;
	double den = denominator;
	double doubleRat = num / den;
	return doubleRat;
}


/*
 * ostream function is used to print a rational in readable
 * form. print the numerator, then a slash, and then the
 * denominator. Returns the output.
 */
ostream &operator <<(ostream &output, const Rational &aRat) {
	output << aRat.numerator << "/" << aRat.denominator;
	return output;
}

/*
 * istream function takes in the input and the location
 * of a rational and goes through the input, character by
 * character until it reaches a number. It then pulls the
 * whole number from the input and stores it as num and
 * assigns num to the rational's numerator. It then grabs
 * the next character, which is a / and store the number
 * following it in den and sets den as the rational's
 * denominator
 * loop invariant: Loop continues until no more spaces
 * int den stores the denominator for a Rational
 * int num stores the numerator for a rational
 * char c is used to check what is in the file.
 *
 */
istream &operator >>(istream &input, Rational &aRat) {;
	int num = 0, den = 0;
	char c;
	while(((c = input.peek()) == ' ') || c == '\t' ){
		//loop invariant: Loop continues until no more spaces
		input.get();
	}
	c = input.peek();
	if((c <= '9' && c >= '0') || c == '-'){
		input >> num;
		aRat.setNumerator(num);
		if (input.peek() == '/') {
			input >> c;
			input >> den;
			if(den == 0){
				cout<<"A denominator was set to 0. Exiting.";
				exit(0);
			}
			aRat.setDenominator(den);
		}
	}
	return input;
}

/*
 * Getter for a Rational's denominator.
 */
int Rational::getDenominator() const {
	return denominator;
}

/*
 * Getter for a Rational's numerator.
 */
int Rational::getNumerator() const {
	return numerator;
}

/*
 * Setter for a Rational's denominator
 */
void Rational::setDenominator(int den) {
	denominator = den;
}

/*
 * Setter for a Rational's Numerator
 */
void Rational::setNumerator(int num) {
	numerator = num;
}
/*
 * Destructor for a Rational.
 */
Rational::~Rational() {}

/*
 * Overloaded  +. Cross multiplies and adds the product.
 * Sets the product equal to num. multiplies the two
 * denominators and sets them equal to int den.
 * num and den are normalized and the resulting rational is
 * returned.
 */
Rational Rational::operator +(const Rational &aRat) {
	int num = aRat.denominator*numerator + denominator*aRat.numerator;
	int den = denominator*aRat.denominator;
	return normalize(num, den);
}

/*
 * Overloaded -. Creates a new rational that is normalized
 * with the same numerator and denominator as aRat but the
 * numerator is negative. this and newRat are then added
 * and the result is returned.
 */
Rational Rational::operator -(const Rational &aRat) {
	Rational newRat(aRat.numerator * -1, aRat.denominator);
	return *this+newRat;
}
/*
 * Overloaded *. Multiplies both numerators and denominators
 * of the 2 rationals and then returns the normalized result.
 */
Rational Rational::operator *(const Rational &aRat) {
	long long int num = numerator * aRat.numerator;
	long long int den = denominator * aRat.denominator;
	return normalize(num, den);
}

/*
 * Overloaded /. Cross multiplies the 2 rationals
 * and returns the normalized result.
 */
Rational Rational::operator /(const Rational &aRat) {
	long long int num = this->numerator * aRat.denominator;
	long long int denom = this->denominator * aRat.numerator;
	return normalize(num, denom);
}

/*
 * Overloaded ==. Cross multiplies the denominator
 * and numerator of two rationals and sees if the
 * products are equal to each other. Returns boolean.
 */
bool Rational::operator ==(const Rational &aRat) const {
	return ((numerator*aRat.denominator) == (aRat.numerator*denominator));
}

/*
 * Overloaded != cross multiplies the two rationals
 * and sees if the products are not equal to each other.
 * Returns boolean.
 */
bool Rational::operator !=(const Rational &aRat) const {
	return ((numerator*aRat.denominator) != (aRat.numerator*denominator));
}

/*
 * Overloaded <. Cross multiplies 2 rationals and sees if the
 * first product is less than the second. Returns boolean.
 */
bool Rational::operator <(const Rational &aRat) const {
	return ((numerator*aRat.denominator) < (aRat.numerator*denominator));
}

/*
 * Overloaded <=. Cross multiplies 2 rationals and checks
 * if the first product is less than or equal to
 * the second product. Returns boolean.
 */
bool Rational::operator <=(const Rational &aRat) const {
	return ((numerator*aRat.denominator) <= (aRat.numerator*denominator));
}
/*
 * Overloaded >. Cross multiplies two rationals and
 * sees if the first product is greater than the
 * second. Returns boolean.
 */
bool Rational::operator >(const Rational &aRat) const {
	return ((numerator*aRat.denominator) > (aRat.numerator*denominator));
}

/*
 * Overloaded >=.Cross multiples 2 rationals and sees if the
 * first product is greater than or equal to the second.
 * returns a boolean.
 */
bool Rational::operator >=(const Rational &aRat) const {
	return ((numerator*aRat.denominator) >= (aRat.numerator*denominator));
}


/*
 * Overloaded =. Sets this rational's numerator
 * and denominator equal to the called rational's
 * numerator and denominator.
 */
Rational &Rational::operator =(const Rational &aRat) {
	this->numerator = aRat.numerator;
	this->denominator = aRat.denominator;
	return *this;

}
/*
 * Overloaded +=. Creates a new rational and
 * calls the + operator with the two rationals
 * called with the function. Sets called Rational's
 * numerator and denominator equal to newRat's numerator
 * and denominator.
 */
Rational &Rational::operator +=(const Rational &aRat) {
	Rational newRat = *this + aRat;
	this->numerator = newRat.numerator;
	this->denominator = newRat.denominator;
	return *this;
}
/*
 * Overloaded -=. Creates a new rational and
 * calls the - operator with the two rationals
 * called with the function. Sets called Rational's
 * numerator and denominator equal to newRat's numerator
 * and denominator.
 */
Rational &Rational::operator -=(const Rational &aRat) {
	Rational newRat = *this - aRat;
	this->numerator = newRat.numerator;
	this->denominator = newRat.denominator;
	return *this;
}
/*
 * Overloaded *=. Creates a new rational and
 * calls the * operator with the two rationals
 * called with the function. Sets called Rational's
 * numerator and denominator equal to newRat's numerator
 * and denominator.
 */
Rational &Rational::operator *=(const Rational &aRat) {
	Rational r = *this * aRat;
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	return *this;
}
/*
 * Overloaded /=. Creates a new rational and
 * calls the / operator with the two rationals
 * called with the function. Sets called Rational's
 * numerator and denominator equal to newRat's numerator
 * and denominator.
 */
Rational &Rational::operator /=(const Rational &aRat) {
	Rational r = *this / aRat;
	this->numerator = r.numerator;
	this->denominator = r.denominator;
	return *this;
}



