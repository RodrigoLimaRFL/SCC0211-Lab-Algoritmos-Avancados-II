#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minAbastecimentos(int distanciaDestino, int capacidadeTanque, vector<pair<int, int>>& distanciaEDisponibilidade) {
    int abastecimentos = 0;
    int posicaoAtual = 0;
    int tanqueAtual = capacidadeTanque;
    int numPostos = distanciaEDisponibilidade.size();

    if(tanqueAtual >= distanciaDestino)
    {
        return 0; // Já chegou ao destino
    }

    if(tanqueAtual < distanciaEDisponibilidade[0].first) {
        return -1; // Não é possível chegar ao primeiro posto
    }

    int i = 0;

    while(i < numPostos)
    {
        if(posicaoAtual + tanqueAtual >= distanciaDestino) {
            return abastecimentos;
        }

        int j = i + 1;

        vector<int> postosAtingiveis;

        while(j < numPostos && tanqueAtual >= distanciaEDisponibilidade[j].first - distanciaEDisponibilidade[i].first)
        {
            postosAtingiveis.push_back(j);
            j++;
        }

        if(postosAtingiveis.empty())
        {
            return -1; // Não é possível chegar a nenhum posto
        }

        // Escolher o posto com maior disponibilidade
        int postoEscolhido = postosAtingiveis[0];
        for(int k : postosAtingiveis)
        {
            if(distanciaEDisponibilidade[k].second > distanciaEDisponibilidade[postoEscolhido].second)
            {
                postoEscolhido = k;
            }
        }
        tanqueAtual -= (distanciaEDisponibilidade[postoEscolhido].first - distanciaEDisponibilidade[i].first);

        tanqueAtual = min(tanqueAtual + distanciaEDisponibilidade[postoEscolhido].second, capacidadeTanque);

        i = postoEscolhido;
        posicaoAtual = distanciaEDisponibilidade[postoEscolhido].first;
        abastecimentos++;
    }

    return -1; 
}

int main()
{
    int distanciaDestino, capacidadeTanque;

    cin >> distanciaDestino >> capacidadeTanque;

    int numPostos;

    cin >> numPostos;

    vector<pair<int, int>> distanciaEDisponibilidade(numPostos);

    for (int i = 0; i < numPostos; ++i) {
        cin >> distanciaEDisponibilidade[i].first >> distanciaEDisponibilidade[i].second;
    }

    sort(distanciaEDisponibilidade.begin(), distanciaEDisponibilidade.end());

    int resultado = minAbastecimentos(distanciaDestino, capacidadeTanque, distanciaEDisponibilidade);
    cout << resultado << endl;

    return 0;
}