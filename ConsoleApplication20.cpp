#include <iostream>

#include <math.h>

using namespace std;

class Complex
{

public:

	int Real, Imag;

	Complex();

	Complex(Complex &obj);

	Complex(int, int);

	~Complex();
	Complex& operator=(const Complex& right) {

		if (this == &right)

			return *this;

		Real = right.Real;

		Imag = right.Imag;

		return *this;

	}

	friend const Complex& operator++(Complex& i) {

		i.Real++;

		i.Imag++;

		return i;
		//Префиксн
	}

	friend const Complex operator++(Complex& i, int) {

		Complex old(i);

		i.Real++;

		i.Imag++;

		return old;
		//Постфикс
	}

	friend const Complex& operator--(Complex& i) {

		i.Real--;

		i.Imag--;

		return i;

	}
	friend const Complex operator--(Complex& i, int) {

		Complex old(i);

		i.Real--;

		i.Imag--;

		return old;

	}
	friend bool operator==(const Complex& left, const Complex& right) {

		return ((left.Real == right.Real) && (left.Imag == right.Imag));

	}
	friend ostream& operator<< (ostream &out, const Complex &Z) {

		if (Z.Real)

			if (Z.Imag)

				if (Z.Imag > 0)

					out << Z.Real << "+" << Z.Imag << "i";

				else
					out << Z.Real << Z.Imag << "i";

			else

				out << Z.Real;

		else

			if (Z.Imag)

				out << Z.Imag << "i";

			else
				out << 0;
		return out;

	}

	friend istream& operator>> (istream &in, Complex &Z) {

		in >> Z.Real;

		in >> Z.Imag;
		return in;

	}

	void getData();

};

Complex::Complex()

{
	Real = 0;
	Imag = 0;

}

Complex::Complex(Complex &obj) {

	Real = obj.Real;

	Imag = obj.Imag;

}

Complex::Complex(int R, int I)

{

	Real = R;

	Imag = I;

}

Complex::~Complex()

{
}

void Complex::getData() {

	cout << "Находим модуль: " << sqrt(Real*Real + Imag * Imag) << endl;

	cout << "Выводим действительную и мнимую часть: " << Imag << "i" << endl;

}

int main()
{

	Complex a(10, 5);

	a.getData();

	cout << a;

	return 0;

}