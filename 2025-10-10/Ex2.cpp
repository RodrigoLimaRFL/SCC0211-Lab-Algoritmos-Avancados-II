#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bitset<1000000> primos;

void calcularCrivo()
{
    primos.set();

    primos[0] = 0;
    primos[1] = 0;

    for(long long int i = 2; i * i <= 1000000; i++)
    {
        for(long long int j = i * i; j <= 1000000; j += i)
        {
            primos[j] = 0;
        }
    }
}

vector<pair<long long int, int>> fatorar(long long int numero)
{
    vector<pair<long long int, int>> fatoresEMultiplicidades;

    while(numero % 2 == 0)
    {
        if(fatoresEMultiplicidades.empty() || fatoresEMultiplicidades.back().first != 2)
        {
            fatoresEMultiplicidades.push_back({2, 1});
        }
        else
        {
            fatoresEMultiplicidades.back().second++;
        }

        numero /= 2;
    }

    for(long long int i = 3; i * i <= numero; i += 2)
    {
        while(numero % i == 0)
        {
            if(fatoresEMultiplicidades.empty() || fatoresEMultiplicidades.back().first != i)
            {
                fatoresEMultiplicidades.push_back({i, 1});
            }
            else
            {
                fatoresEMultiplicidades.back().second++;
            }

            numero /= i;
        }
    }

    if(numero > 2)
    {
        fatoresEMultiplicidades.push_back({numero, 1});
    }

    return fatoresEMultiplicidades;
}

int main()
{
    int n = 0;

    cin >> n;

    vector<long long int> numeros(n);

    for(int i = 0; i < n; i++)
    {
        cin >> numeros[i];
    }

    calcularCrivo();

    for(int i = 0; i < n; i++)
    {
        long long int numero = numeros[i];

        vector<pair<long long int, int>> fatoresEMultiplicidades = fatorar(numero);

        for(const auto& fatorEMultiplicidade : fatoresEMultiplicidades)
        {
            cout << "(" <<fatorEMultiplicidade.first << "," << fatorEMultiplicidade.second << ")";

            if (&fatorEMultiplicidade != &fatoresEMultiplicidades.back())
            {
                cout << ",";
            }
        }

        cout << endl;
    }

    return 0;
}