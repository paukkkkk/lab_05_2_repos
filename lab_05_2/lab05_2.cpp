//lab05-2
//РІ-11 
#include<iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void S(const double x, const double eps, int& n, double& s);
void A(const double x, const double n, const double& a);

int main()
{ 
	double xp, xk, x, dx, eps,  s = 0;
	int n = 0;

	cout << "xp="; cin >> xp;
	cout << "xk="; cin >> xk;
	cout << "dx="; cin >> dx;
	cout << "eps="; cin >> eps;

	cout  << fixed;

	cout << "-------------------------------------------------------------------------" << endl;

	cout << "|" << setw(8) << "x" << "       |"
		<< setw(14) << "acos(x)" << "   |"
		<< setw(10) << "s" << "        |"
		<< setw(11) << "n" << "       |"
		<< endl;
	cout << "-------------------------------------------------------------------------" << endl;

	x = xp;

	while (x <= xk)
	{
		S(x, eps, n, s);

		cout << "|" << setw(8) << setprecision(2) << x << "       |"
			<< setw(14) << setprecision(5) << acos(x) << "   |"
			<< setw(10) << setprecision(5) << s << "        |"
			<< setw(11) << n <<  "       |"
			<< endl;
		
		x += dx;
	}
	
	cout << "-------------------------------------------------------------------------" << endl;


	return 0;
}

void A(const double x, const int n, double& a)
{
	double R = ((x * x) * ((2 * n - 1) * (2 * n - 1)) / ((2 * n) * (2 * n + 1)));
	a *= R;
}

void S(const double x, const double eps, int& n, double& s)
{
	n = 0;
	double a = x;
	s = x;

	do
	{
		n++;
		A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
	double Pi = acos(-1.0);
	s = (Pi / 2.0) - s;
}