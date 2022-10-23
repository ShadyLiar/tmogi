// zad5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <iterator>
#include <algorithm>
#include "Windows.h"

using namespace std;

class Degree 
{
public:
    double t_grad = 0;
    double t_min = 0;
    double t_sec = 0;

public:
    Degree(double grad, double min, double sec) : t_grad(grad), t_min(min), t_sec(sec) {}
    Degree(double dec)
    {
        double d_min = std::modf(dec, &t_grad) * 60;
        t_sec = std::modf(d_min, &t_min) * 60;
    }

    vector<double> Show()
    {
        vector<double> num;
        num.push_back(t_grad);
        num.push_back(t_min);
        num.push_back(t_sec);
        cout << t_grad << "° " << t_min << " " << t_sec << "" << endl;
        return num;

    }

    

};

template<typename T>
void Show(vector<T> array)
{
    for (int i = 0; i < array.size(); ++i)
        cout << i + 1 << ". " << array[i] << endl;
}


template<typename T>
vector<T> getEi(Degree beta)
{
}

vector<double> correctDegree()
{
    return vector<double>();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Degree* beta = new Degree(36, 47, 58.5);
    beta->Show();
    cout << endl << endl;

    vector<double> variant = { +0.7, -1.0, +0.2, +1.6, -1.2, +0.4, +0.2, -1.5, +0.2, -0.4, +1.4, +0.5 };
    vector<double> betas;
    Show(variant);
    cout << endl << endl;

    for (int i = 0; i < variant.size(); ++i)
        betas.push_back(beta->t_sec + variant[i]);

    Show(betas);

    auto min_value = *std::min_element(betas.begin(), betas.end());

    cout << endl;
    cout << "Xmin = " << min_value << endl;

    vector<double> Ei;
    double summEi = 0;

    for (int i = 0; i < betas.size(); ++i)
    {
        Ei.push_back(betas[i] - min_value);
        summEi += Ei[i];
    }
        
    


    cout << endl;
    Show(Ei);
    cout << endl;
    cout << "SUMM EI = " << summEi << endl;
    cout << endl;

    vector<double> Ei2;
    double summEi2 = 0;

    for (int i = 0; i < betas.size(); ++i)
    {
        Ei2.push_back(Ei[i]*Ei[i]);
        summEi2 += Ei2[i];
    }
    cout << endl;
    Show(Ei2);
    cout << endl;
    cout << "SUMM EI2 = " << summEi2 << endl;
    cout << endl;
    
    Degree* X = beta;
    X->t_sec = min_value;
    X->t_sec = X->t_sec + (summEi / 12);

    X->Show();
    

    double betaOrk = 0;
    double XOKR = 0;
    cout << "IN BETA ORK: " << endl; 
    cin >> betaOrk;
    cout << "IN X OKR " << endl;
    cin >> XOKR;

    vector<double> Vi;
    double summVi = 0;

    for (int i = 0; i < variant.size(); ++i)
    {
        Vi.push_back(betas[i] - XOKR);
        summVi += Vi[i];
    }
        
        


    
    cout << endl;
    Show(Vi);
    cout << endl;


    cout << "KONTROL" << betaOrk << "*" << 12 << " = -" << betaOrk * 12 << "==" << summVi << endl;

    vector<double> Vi2;
    double summVi2 = 0;

    for (int i = 0; i < variant.size(); ++i)
    {
        Vi2.push_back(Vi[i]*Vi[i]);
        summVi2 += Vi2[i];
    }

    cout << endl;
    Show(Vi2);
    cout << endl;
    cout << "SUM Vi2 = " << summVi2 << endl;
    cout << endl;

    double m_summv2 = summVi2 - (summVi * summVi) / 12;
    double r = summVi2 - m_summv2;
    cout << "VI2 = " << m_summv2 << " (" << summVi2 << " - " << m_summv2 << " = " << r << ") " << endl;
    cout << endl;

    double mx = sqrt(summVi2 / 11);
    cout << "mx = " << mx << endl << endl;

    double Mmx = mx / (sqrt(2 * 11));
    cout << "Mmx = " << Mmx << endl << "mx = +-" << mx << "+=" << Mmx << endl;

    double MmxXmx = Mmx / mx;
    cout << "Mmx/mx = " << MmxXmx << endl << endl;

    double M = mx / sqrt(12);
    double mM = M / sqrt(2 * 12);

    cout << "M = " << M << endl << "mM = " << mM << endl << "M = +-" << M << " +-" << mM << endl << "mM/M = " << mM / M << endl << endl;

    double lZ = X->t_sec - (1.8 * M);
    double rZ = X->t_sec + (1.8 * M);

    cout << lZ << " < " << "X" << " < " << rZ << endl;

    cout << sqrt(11 / 19.7) * mx << " < Gx < " << sqrt(11 / 4.6) * mx << endl;

    double endPoint;
    cin >> endPoint;
}

