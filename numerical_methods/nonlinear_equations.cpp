// Nonlinear equations.
// External iterations according to Seidel's method, 
// internal ones according to Newton's method.

/*
 Nonlinear equations:
 f1(x1..xn) = 0,
 f2(x1..xn) = 0,
 ...
 fn(x1..xn) = 0
 dimension n*n (here dimension 2*2).
*/


#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>
using namespace std;

const double EPSILON = 1E-5;
const int n = 2;    //dimension

// Nonlinear equations
double FUNC(double x, double y, int i)  
{
    switch (i)
    {
    case 1:
        return 10 * x * x * y * y + 3 * x * x - 20 * x * y - 3;
    case 2:
        return 3 * x * x * y * y + x * x - 3 * x * y - 7;
    default:
        cout << "Error in dimension!" << endl;
        return -1;
    }
}

// Jacobi matrix
double Jacobi_Matrix(double x, double y, int i, int j)  
{
    switch (i)
    {
    case 1:
        switch (j)
        {
        case 1:
            return 20 * x * y * y + 6 * x - 20 * y;
        case 2:
            return 20 * x * x * y - 20 * x;
        default:
            return -1;
        }
    case 2:
        switch (j)
        {
        case 1:
            return 6 * x * y * y + 2 * x - 3 * y;
        case 2:
            return 6 * x * x * y - 3 * x;
        default:
            return -1;
        }
    default:
        return -1;
    }
}

// Print answer
void Answer(double x, double y)
{
    cout << "Answer:" << endl;
    cout << "x =  " << x << ",  y =  " << y << endl;
}

// Inverse matrix
void Inverse_Matrix(double** A) 
{
    double det;  //matrix determinant
    double tmp;
    det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    tmp = A[0][0];
    if (abs(det) > EPSILON)
    {
        A[0][0] = A[1][1] / det;
        A[1][1] = tmp / det;
        A[0][1] = -A[0][1] / det;
        A[1][0] = -A[1][0] / det;
    }
}

// Seidel-Newton method
void Seidel_Newton(double x, double y, double& x_new, double& y_new) 
{
    double D11, D22;

    D11 = Jacobi_Matrix(x, y, 1, 1);
    if (abs(D11) > EPSILON)
        x_new = (-1 * FUNC(x, y, 1) / D11) + x;
    else
        x_new = x;

    D22 = Jacobi_Matrix(x_new, y, 2, 2);
    if (abs(D22) > EPSILON)
        y_new = (-1 * FUNC(x_new, y, 2) / D22) + y;
    else
        y_new = y;
}

int main()
{
    setlocale(LC_ALL, "rus");

    double initial[2];   //initial approximation
    initial[0] = -1.2;
    initial[1] = -1.8;

    double new_answ[2];
    double max, norma;
    int i = 0;

    do
    {
        Seidel_Newton(initial[0], initial[1], new_answ[0], new_answ[1]);

        max = abs(initial[0] - new_answ[0]);
        if (abs(initial[1] - new_answ[1]) > max)
            max = abs(initial[1] - new_answ[1]);
        initial[0] = new_answ[0];
        initial[1] = new_answ[1];

        norma = abs(FUNC(new_answ[0], new_answ[1], 1));
        if (abs(FUNC(new_answ[0], new_answ[1], 2)) > norma)
            norma = abs(FUNC(new_answ[0], new_answ[1], 2));

        i++;
        cout << "Iteration ¹" << i << endl << new_answ[0] << "\t" << new_answ[1] << endl << endl;

    } while ((max > EPSILON || norma > EPSILON) && i < 1000);

    cout << endl << endl;
    Answer(new_answ[0], new_answ[1]);

    system("pause");
    return 1;
}
