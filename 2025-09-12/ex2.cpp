#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int soma_cortes(const vector<long long int> &alturas, long long int altura_corte)
{
    long long int soma = 0;
    for (long long int altura : alturas)
    {
        if (altura > altura_corte)
            soma += altura - altura_corte;
    }
    return soma;
}

long long int min_altura(const vector<long long int> &alturas, long long int madeira_desejada)
{
    long long int melhor_altura = -1;
    long long int esq = 0;
    long long int dir = alturas.back(); // maior altura

    while (esq <= dir)
    {
        long long int meio = (esq + dir) / 2;
        long long int madeira_cortada = soma_cortes(alturas, meio);

        if (madeira_cortada >= madeira_desejada)
        {
            melhor_altura = meio; // possível solução
            esq = meio + 1;       // tenta cortar mais alto
        }
        else
        {
            dir = meio - 1;       // corta mais baixo
        }
    }

    return melhor_altura;
}


int main()
{
    int num_arvores;

    long long int madeira_desejada;

    cin >> num_arvores >> madeira_desejada;

    vector<long long int> alturas(num_arvores);

    for (int i = 0; i < num_arvores; i++)
    {
        cin >> alturas[i];
    }

    sort(alturas.begin(), alturas.end());

    cout << min_altura(alturas, madeira_desejada) << endl;

    return 0;
}