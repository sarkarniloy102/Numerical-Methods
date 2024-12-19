#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
#define error 0.005

double DegToRad(double x){
   return (x * PI) / 180.0;
}

double f(double x){
    return (x * x - 1) * sin(DegToRad(x)) - 2 * x * cos(DegToRad(x));
}

double ff(double x){
    return (4 * x * sin(DegToRad(x)) + cos(DegToRad(x * x - 3)));
}

double Bisection(){
    cout << "By using Bisection Method," << endl << endl;

    double x0, x1, x2, fx0, fx1, fx2;
    int idx = 1;

    x1 = 1;
    x2 = 15;

    fx1 = f(x1);
    fx2 = f(x2);

    while(fabs(x2 - x1) > error)
    {
        x0 = (x1 + x2) / 2;
        fx0 = f(x0);

        if(fx0 * fx1 < 0)
        {
            x2 = x0;
            fx2 = f(x2);
        }
        else
        {
            x1 = x0;
            fx1 = f(x1);
        }

        cout << "Iteration " << idx++ << " = " << fixed << setprecision(4) << x0 << endl;
    }

    x0 = (x1 + x2) / 2;

    cout << "Iteration " << idx << " = " << fixed << setprecision(4) << x0 << endl;
    cout << endl << "The root of the equation is = " << x0 << endl;

    return x0;
}

double Newton_Raphson(){
    cout << endl << endl << "By using Newton-Raphson Method," << endl << endl;

    double x0, x1, fx0, ffx0;
    int idx = 1;

    x1 = 20;

    do{
        x0 = x1;

        cout << "Iteration " << idx++ << " = " << fixed << setprecision(4) << x1 << endl;

        x1 = x0 - (f(x0) / ff(x0));

    }while(fabs(x1 - x0) > error);

    cout << "Iteration " << idx << " = " << fixed << setprecision(4) << x1 << endl;
    cout << endl << "The root of the equation is = " << x1 << endl;

    return x1;
}

double False_Position(){
    cout << endl << endl << "By using False Position Method," << endl << endl;

    double x0, xx0, x1, x2, fx0, fx1, fx2;
    int idx = 1;

    x2 = 1;
    x1 = 15;

    x0 = (double) INT_MAX;
    fx1 = f(x1);
    fx2 = f(x2);

    do{
        xx0 = x0;
        x0 = x1 - ((fx1 * (x2 - x1)) / (fx2 - fx1));
        fx0 = f(x0);

        if(fx0 * fx1 < 0){
            x2 = x0;
            fx2 = f(x2);
        }
        else{
            x1 = x0;
            fx1 = f(x1);
        }

        cout << "Iteration " << idx++ << " = " << fixed << setprecision(4) << x0 << endl;

    }while(fabs(x0-xx0) > error);

    cout << endl << "The root of the equation is = " << x0 << endl;

    return x0;
}

double Secant(){
    cout << endl << endl << "By using Secant Method," << endl << endl;

    double x1, x2, x3, fx1, fx2, fx3;
    int idx = 1;

    x2 = 10;
    x1 = -100;

    fx1 = f(x1);
    fx2 = f(x2);

    do{
        x3 =  ((fx2 * x1) - (fx1 * x2)) / (fx2 - fx1);

        cout << "Iteration " << idx++ << " = " << fixed << setprecision(4) << x3 << endl;

        x1 = x2;
        x2 = x3;
        fx1 = fx2;
        fx2 = f(x3);

    }while(fabs(x1-x2) > error);

    cout << endl << "The root of the equation is = " << x3 << endl;

    return x3;
}

int main()
{  
    double bisection, newton_raphson, false_position, secant;

    bisection = Bisection();
    newton_raphson = Newton_Raphson();
    false_position = False_Position();
    secant = Secant();

    cout << endl << endl << endl;

    cout << "By plotting the root which we got from the Bisection Method to the function we get, f("
         << bisection << ") = " << fabs(f(bisection)) << endl;

    cout << "By plotting the root which we got from the Newton-Raphson Method to the function we get, f("
         << newton_raphson << ") = " << fabs(f(newton_raphson)) << endl;

    cout << "By plotting the root which we got from the False Position Method to the function we get, f("
         << false_position << ") = " << fabs(f(false_position)) << endl;

    cout << "By plotting the root which we got from the Secant Method to the function we get, f("
         << secant << ") = " << fabs(f(secant)) << endl;

    cout << endl << endl;

    return 0;
}