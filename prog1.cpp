#include <iostream>
#include <cmath>

using namespace std;


double f(double x)
{
        if (fabs(x) < 0.00000000001) return 9;
        else
            return (x + 1/x)*pow(sin(3*x),2)*exp(-pow(x,2))/log(1 + x);
}

double Integrate(double a, double b, int N)
{
	double len = (b - a) / N;
	double S = 0;

	for(int i = 1; i <= N; ++i)
	{
		S += len * f(a + len * (i - 1/2));
	}
	return S;
}

double Runge(double a, double b, int &N, double eps)
{
	N = 1; 
        double S_N = pow(20, 10);
	double S_2N = (b - a) * f(b);
        //cout << S_2N   << " S2_N"<< endl;
	double len = (b - a);

        while (fabs(S_2N - S_N) / 3 >= eps || N <= 2)
        {
                cout << fabs(S_2N - S_N) / 3  << " S2_N"<< endl;
		N *= 2;
		S_N = S_2N;
		S_2N /= 2;
		len /= 2;

		for(int i = 1; i <= N; i += 2)
		{
			S_2N += len * f(a + len * i);
		}
        }

	return S_2N;
}


int main()
{
        double eps = 0.01;
        double delta_1 = 0.0001;
        double C = 2.123;
	double a_c = 0;
	double b_c = 0;

        int N_1 = 29748846;
	int N_1R = 0;
	int N_c = 0;
	
        double S_1 = Integrate(delta_1, C, N_1);
        double S_1R = Runge(delta_1, 2, N_1R, eps);

	cout << fixed;
	cout.precision(5);

	cout << "Results for usual calculation:" << endl;
        cout << "Integral of f(x) in [0.0001, 2.123]: " << S_1 << endl;
	cout << endl;
	cout << "Results fot Runge calculation:" << endl;
        cout << "Integral of f(x) in [0.0001, 2.123]: " << S_1R << " N_1 = " << N_1R << endl;

	cout << endl;

	cout << "Custom request" << endl;
	cout << "Input a: ";
	cin >> a_c;
	cout << endl;
	cout << "Input b: ";
	cin >> b_c;
	cout << endl;
	cin >> N_c;
	cout << endl;
	cout << "Integral f(x) from " << a_c << " to " << b_c << " is: " << Integrate(a_c, b_c, N_c) << endl;;

	

}
