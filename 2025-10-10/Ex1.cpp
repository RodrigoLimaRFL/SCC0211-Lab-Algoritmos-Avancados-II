#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<long long int> numeros(n);

    for(int i = 0; i < n; i++)
    {
        cin >> numeros[i];
    }

    bitset<1000000> primos;
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

    vector<pair<long long int, long long int>> somas;

    for(int i = 0; i < n; i++)
    {
        long long int numero = numeros[i];

        if(numero == 4)
        {
            somas.push_back({2, 2});
            continue;
        }

        if(numero == 5)
        {
            somas.push_back({2, 3});
            continue;
        }

        for(long long int j = 3; j <= numero / 2; j += 2)
        {
            if(primos[j] && primos[numero - j])
            {
                somas.push_back({j, numero - j});
                break;
            }
        }
    }

    for(const auto& soma : somas)
    {
        cout << soma.first << " " << soma.second << endl;
    }

    return 0;
}