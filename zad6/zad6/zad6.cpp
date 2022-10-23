#include <iostream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;


vector<float> roundVec(vector<float> a, int r = 1)
{
    vector<float> summ;

    for (float x : a)
    {
        summ.push_back(round(x * (10 ^ r)) / (10 ^ r));
    }

    return summ;
}

vector<float> makeVar(vector<float> arr, float a)
{
    vector<float> arr2;

    for(float x : arr)
    {
        arr2.push_back(x + a);
    }

    return arr2;
}

int ShowArray(string name = "", float data = 0, vector<float> arr = {})
{
    cout << "****" << endl << endl;
    if (arr.size() == 0)
    {
        cout << name << " == " << data << endl;
        return 0;
    }

    cout << name << endl << endl;
    int i = 0;

    for(float x : arr)
    {
        
        cout << i << ". " << x << endl;
        ++i;
        
    }
    cout << endl;
    cout << "****" << endl << endl;
}

vector<float> summVec(vector<float> a, vector<float> b = {}, float delitel = 1)
{
    vector<float> summ;

    if (b.size() <= 0)
    {
        float one_summ = 0;
        for (float x : a)
        {
            if (x >= 0)
            {
                one_summ += x;
            }
            else
            {
                one_summ += (x * delitel);
            }
        }


        summ = { one_summ };
        return summ;
    }

    if (a.size() != b.size())
        return { 9999999 };


    

    for(int i = 0; i < a.size(); ++i)
    {
        float x = (a[i] + b[i]) / delitel;

        summ.push_back( x );
    }

    if (delitel != 1)
        summ = roundVec(summ, 0);
    

    return summ;
}

vector<float> resVec(vector<float> a, vector<float> b)
{
    vector<float> summ;

    if (a.size() != b.size())
        return { 9999999 };

    for (int i = 0; i < a.size(); ++i)
    {
        summ.push_back(a[i] - b[i]);
    }

    return summ;
}

vector<float> umnVec(vector<float> a, vector<float> b = {}, int x = 0)
{
    vector<float> finish;

    if( x != 0)
    {
       for (int i = 0; i < a.size(); ++i)
        {
           finish.push_back(a[i] * a[i]);
        }

       return finish;
    }

    for (int i = 0; i < a.size(); ++i)
    {
        finish.push_back(a[i] * b[i]);
    }

    return finish;

}



int main()
{

    //vector<float> xi = {54.0, 21.6, 33.4, 41.3, 24.0, 18.8, 53.2, 20.9, 3.7, 49.5};
    //vector<float> x = {54.7, 22.7, 32.3, 39.8, 25.8, 18.4, 51.6, 22.2, 5.6, 50.2};

    vector<float> xi_const = {23.4, 14.6, 49.5, 3.7, 20.9, 53.2, 18.8, 24.0, 41.3, 33.4};
    vector<float> v_xi = { 21.5, 13.2, 50.5, 5.7, 21.6, 51.8, 18.5, 25.9, 40.1, 32.4};

    float var = 0.7;
    //float var = 0;


    vector<float> xi = makeVar(xi_const, var);

    ShowArray("Xi", 0, xi);
    ShowArray("X'i", 0, v_xi);

    vector<float> Di = summVec(xi, v_xi, 2);
    ShowArray("Di", 0, Di);

    vector<float> di = resVec(xi, v_xi);
    ShowArray("di", 0, di);
    float summ_d = summVec(di, {}, -1)[0];
    ShowArray("[|d|]", summ_d);

    float summ_di = summVec(di)[0];
    ShowArray("di_summ", summ_di);


    float krug = summ_di / 10;

    vector<float> v_di = makeVar(di, ((-1)*krug));
    v_di = roundVec(v_di, 0);
    ShowArray("di'", 0, v_di);

    float summ_v_di = summVec(v_di)[0];
    ShowArray("[di']", roundVec({ summ_v_di }, 0)[0]);

    vector<float> di2 = umnVec(di, {}, 1);
    ShowArray("di2", 0, di2);
    float summ_di2 = summVec(di2, {})[0];
    ShowArray("[di2]", summ_di2);


    vector<float> v_di2 = umnVec(v_di, {}, 1);
    ShowArray("di'2", 0, v_di2);
    float summ_v_di2 = summVec(v_di2, {})[0];
    ShowArray("[di'2]", summ_v_di2);

    cout << summ_di << "<=" << "2.5*" << summ_d << " / " << "sqrt(10)" << " == " << 2.5 * summ_d << " / " << sqrt(10) << "===" << (2.5 * summ_d) / (sqrt(10)) << endl << endl;
    float md = sqrt(summ_di2 / 10);

    cout << "md ==== _/[di2/n] ==" << summ_di2 << '/' << "10" << " == " << sqrt(summ_di2 / 10) << endl << endl;


    float mxi = md / sqrt(2);

    cout << "mxi ==== md/sqrt(2) == " << md << "/" << sqrt(2) << " === " << mxi << endl << endl;

    float mxif = mxi / sqrt(2);

    cout << "mxi/sqrt(2) ==== " << mxi << " / " << sqrt(2) << " === " << mxif << endl << endl;


    cout << "krug == [di]/n == " << summ_di << "/" << 10 << " ==== " << krug << endl << endl;

    float o_krug = roundVec({ krug }, 0)[0];
    ShowArray("Krug_0", o_krug);
    float beta_o = o_krug - krug;
    ShowArray("beta_0", beta_o);


    float v_md = sqrt(summ_v_di2 / 9);
    cout << "md' === " << "_/" << summ_v_di2 << "/" << 9 << " === " << v_md << endl << endl;

    float v_mxi = v_md / sqrt(2);   
    cout << "mxi' === " << v_mxi << endl << endl;

    float v_mxi_o = v_mxi / sqrt(2); 
    cout << "mxi_o === " << v_mxi_o << endl << endl;

    cout << "[di'] == -n*beta == " << -10 * beta_o << endl << endl;
    cout << summ_v_di << " == -n*beta == " << -10 * beta_o << endl << endl;

    cout << "[ (di') ^ 2] == [di^2] - [di^2]/n == " << summ_di2 - ((summ_di*summ_di) / 10) << endl << endl;
    cout << summ_v_di2 << " == [di'^2] - [di^2]/n == " << summ_di2 - ((summ_di * summ_di) / 10) << endl << endl;

    int abc; 

    cin >> abc;



}

