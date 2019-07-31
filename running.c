#include <stdio.h>
#define theta0 0
#define n 0.0000000001

double f_x(double theta1, double x1, double theta2, double x2);

double f_theta1(double* age, double* wgt, double* ay, double theta1, double theta2);
double f_theta2(double* age, double* wgt, double* ay, double theta1, double theta2);


int main()
{
	double age[23] = { 44,40,44,42,38,47,40,43,44,38,44,45,45,47,54,49,51,51,48,49,57,54,52 };
	double wgt[23] = { 89.47,75.07,85.84,68.15,89.02,77.45,75.98,81.19,81.42,81.87,73.03,87.66,66.45,79.15,83.12,81.42,69.63,77.91,91.63,73.37,73.37,79.38,76.32 };
	double ay[23] = { 182,185,168,172,180,176,180,170,176,186,168,192,176,164,170,185,172,168,164,168,176,165,166 };
	double theta1 = 0.01;
	double theta2 = 0.01;
	double temp = 0;
	int i = 0;
	
	for (i = 0; i < 1000; i++)
	{
		temp = theta1 - n * f_theta1(age, wgt ,ay, theta1, theta2);
		theta1 = temp;
		printf(" theta1 = %lf\n", theta1);
	}

	for (i = 0; i < 1000; i++)
	{
		temp = theta2 - n * f_theta2(age, wgt, ay, theta1, theta2);
		theta2 = temp;
		printf("theta2 = %lf\n", theta2);
	}

	return 0;

}

double f_x(double x1, double theta1, double theta2, double x2)
{
	return theta0 + theta1 * x1 + theta2 * x2;
}

double f_theta1(double* age, double* wgt, double* ay, double theta1, double theta2) 
{
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(age[i], theta1, theta2, wgt[i]) - ay[i]) * age[i];
	}
	return sum;
}

double f_theta2(double* age, double* wgt, double* ay, double theta1, double theta2)
{
	double sum = 0;
	int i = 0;

	for (i = 0; i < 23; i++) {
		sum += (f_x(age[i], theta1, theta2, wgt[i]) - ay[i]) * wgt[i];
	}
	return sum;
}

