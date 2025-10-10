#include <iostream>
#include <vector>

using namespace std;

void gerarSomas(const vector<int>& numeros, int idx, int somaAlvo, int somaAtual, 
                vector<int>& combinacaoAtual, vector<vector<int>>& resultado)
{
    int n = numeros.size();

    if (somaAtual == somaAlvo) {
        resultado.push_back(combinacaoAtual); // Achou
        return;
    }

    if (somaAtual > somaAlvo || idx >= n) {
        return; // Soma invalida
    }

    for (int i = idx; i < n; i++) { // Continua buscando
        combinacaoAtual.push_back(numeros[i]); // Adiciona o número atual
        gerarSomas(numeros, i + 1, somaAlvo, somaAtual + numeros[i], combinacaoAtual, resultado);
        combinacaoAtual.pop_back(); // Remove o número atual (backtrack)
    }
}


int main()
{
    int n, s;

    cin >> n >> s;

    vector<int> numeros(n);

    for (int i = 0; i < n; ++i) {
        cin >> numeros[i];
    }

    vector<vector<int>> resultado;
    vector<int> combinacaoAtual;
    gerarSomas(numeros, 0, s, 0, combinacaoAtual, resultado);

    int numResultados = resultado.size();
    if (numResultados == 0)
        numResultados = -1;

    cout << numResultados << endl;

    return 0;
}