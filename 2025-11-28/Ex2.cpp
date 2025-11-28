#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> tamanhoBordas(const string& frase)
{
    int n = (int)frase.size();
    vector<int> resultados;

    if (n == 0) return resultados;

    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i-1];
        while (j > 0 && frase[i] != frase[j])
            j = pi[j-1];
        if (frase[i] == frase[j]) ++j;
        pi[i] = j;
    }

    int k = pi[n-1];
    while (k > 0)
    {
        resultados.push_back(k);
        k = pi[k-1];
    }

    reverse(resultados.begin(), resultados.end());
    return resultados;
}

int main()
{
    string frase;
    getline(cin, frase);

    vector<int> resultados = tamanhoBordas(frase);
    for (int tamanho : resultados)
    {
        cout << tamanho << " ";
    }

    return 0;
}
