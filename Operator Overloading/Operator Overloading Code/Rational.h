// Rational.h -- kmgumienny

#ifndef RATIONAL_H_
#define RATIONAL_H_
#include "iostream"
#include "fstream"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Rational {
	friend ostream& operator <<(ostream& outs, const Rational &a);
	friend istream& operator >>(istream& input, Rational &a);
public:
	Rational();
	Rational(const int wholeNum);
	Rational(const int num, const int den);
	Rational(const Rational &aRat);
	double toDouble() const;
	int getDenominator() const;
	int getNumerator() const;
	void setDenominator(int den);
	void setNumerator(int num);
	Rational &normalize(long long int num, long long int den);
	bool operator ==(const Rational &aRat) const;
	bool operator !=(const Rational &aRat) const;
	bool operator <(const Rational &aRat) const;
	bool operator <=(const Rational &aRat) const;
	bool operator >(const Rational &aRat) const;
	bool operator >=(const Rational &aRat) const;
	Rational operator +(const Rational &aRat);
	Rational operator -(const Rational &aRat);
	Rational operator *(const Rational &aRat);
	Rational operator /(const Rational &aRat);
	Rational &operator =(const Rational &aRat);
	Rational &operator +=(const Rational &aRat);
	Rational &operator -=(const Rational &aRat);
	Rational &operator *=(const Rational &aRat);
	Rational &operator /=(const Rational &aRat);
	virtual ~Rational();
private:
	int numerator;
	int denominator;
};
#endif /* RATIONAL_H_ */
