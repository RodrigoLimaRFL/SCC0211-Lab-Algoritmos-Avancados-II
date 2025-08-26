#include <iostream>
#include <vector>

using namespace std;


int postoInicial(vector<pair<int, int>>& combustivelECusto) {
    int n = combustivelECusto.size();
    int total = 0; 
    int saldo = 0;  
    int inicio = 0;  

    for (int i = 0; i < n; i++) {
        int ganho = combustivelECusto[i].first - combustivelECusto[i].second;
        total += ganho;
        saldo += ganho;

        if (saldo < 0) {
            inicio = i + 1;
            saldo = 0;
        }
    }

    return (total >= 0 ? inicio : -1);
}

int main() {
    int n;

    cin >> n;

    vector<pair<int, int>> combustivelECusto(n);

    for(int i = 0; i < n; i++) {
        cin >> combustivelECusto[i].first >> combustivelECusto[i].second;
    }

    cout << postoInicial(combustivelECusto) << endl;

    return 0;
}