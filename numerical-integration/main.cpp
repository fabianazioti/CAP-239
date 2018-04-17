#include <iostream>
#include <math.h>
#include <vector>

const double euler = 2.71828182845904523536;

std::vector<double> make_interval(const double &, const double &, const double &);
double function (const double &);
double trapezium_meth(const double &, const double &, const double &);
double rectangle_method(const double &, const double &, const double &);


using namespace std;

int main()
{
    int n;

    double a,b;

    cout << "Enter integration ranges a and b and the Pass size: " << std::endl;

    cin >> a >> b >> n;

    cout << "The result with the method of the rectangles is: " << trapezium_meth(a, b, n) << endl;

    cout << "The result with trapezium method is: " << rectangle_method(a, b, n) << endl;

    return 0;
}

std::vector<double> make_interval(const double &a, const double &b, const double &h)
{
    std::vector<double> interval;

    for(double val = a; val <= b; val += h)
         interval.push_back(val);

    return interval;
}

double function(const double &x)
{
    // return(2*x-2);
    return pow(euler, x) * cos(x);
    // return (pow (euler, -(x*x)));
    //return(cos(x));
   // return((-2*x*x*x) + (12*x*x) - (20*x )+85);
}

double trapezium_meth(const double &a, const double &b, const double &n)
{
    int i;

    double h, resul =  0;

    std::vector<double> interval;

    h = (b-a)/n;

    interval = make_interval(a, b, h);

    resul = function(interval[0]);

    for( i = 1; i < interval.size()-1; i++)
        resul += 2 * function(interval[i]);

    resul += function(interval[i]);

    return (h/2) * resul;
}

double rectangle_method(const double &a, const double &b, const double &n)
{
    double h, intev, result = 0;

    vector<double> interval;

    h = (b-a)/n;

    interval = make_interval(a, b, h);

    for(int i = 0; i < interval.size() - 1; i++)
    {
        intev = interval[i+1] - interval[i];
        result += intev * function( (interval[i] + interval [i+1]) / 2);
    }

   return result;
}
