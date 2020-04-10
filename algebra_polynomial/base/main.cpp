#include <iostream>
#include <string>
#include "Polynomial.h"
#include <math.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");
    string s = "2x^3y^4z^5+3x^3y^4z^5-4x^3y^4z^5+6x^3y^4z^5";
    Polynomial p(s);
    cout << p << endl;
    p.CastSimilar();
    cout << p << endl;
}

