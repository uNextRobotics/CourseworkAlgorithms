метод перебора

#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
	return sin(x) - 1 / x;
}

double const h = 0.0001;
int main()
{
	double f, a, b, x, m, xm;
	cin >> a >> b;
	xm = a;
	m = func(xm);
	for (int i = 1;h * i + a < b;i++) {
		x = h * i + a;
		f = func(x);
		if (f < m) {
			m = f;
			xm = x;
		}
	}
	cout << "minimum point: " << xm <<'\n' ;
	cout<<"minimum value: " << m<<'\n';
}

метод хорд

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

double func(double x)
{
	return pow(M_E, x) - 2 * x*x;
}

double dfunc(double x)
{
	return pow(M_E, x) - 4 * x;
}

double find(double a, double b, double eps)
{
	while (fabs(b - a) > eps)
	{
		a = b - (b - a) * dfunc(b) / (dfunc(b) - dfunc(a));
		b = a - (a - b) * dfunc(a) / (dfunc(a) - dfunc(b));
	}
	return b;
}

int main()
{
	double a, b, eps = 0.0001, xm, m;
	cin >> a >> b;
	xm=find(a, b, eps);
	m = func(xm);
	cout << "minimum point: " << xm << '\n';
	cout << "minimum value: " << m << '\n';
	return 0;
}