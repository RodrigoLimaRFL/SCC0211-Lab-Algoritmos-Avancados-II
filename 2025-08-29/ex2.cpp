#include <iostream>
#include <vector>

using namespace std;

void printTabuleiro(const vector<vector<bool>>& tabuleiro) {
    for (const auto& linha : tabuleiro) {
        for (bool celula : linha) {
            cout << (celula ? 1 : 0) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

pair<int, int> proximaCelulaVazia(const vector<vector<bool>>& tabuleiro) {
    int altura = tabuleiro.size();
    int largura = tabuleiro[0].size();

    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            if (!tabuleiro[i][j]) {
                return {i, j};
            }
        }
    }

    return {-1, -1}; // Nenhuma celula vazia
}

bool preencherTabuleiro(vector<vector<bool>>& tabuleiro, const vector<pair<int, int>>& pecas, int tabuleiroAltura, int tabuleiroLargura) {
    // Se não há célula vazia -> tabuleiro está completo
    if (proximaCelulaVazia(tabuleiro).first == -1) {
        //cout << "Tabuleiro preenchido com sucesso!" << endl;
        return true;
    }

    // Se não há peças sobrando e ainda há célula vazia
    if (pecas.empty()) {
        //cout << "Nenhuma peça disponível para preencher o tabuleiro." << endl;
        return false;
    }

    pair<int, int> celulaVazia = proximaCelulaVazia(tabuleiro);

    // Tenta cada peça disponível
    for (int idx = 0; idx < (int)pecas.size(); idx++) {
        // Testa em duas orientações: normal e rotacionada
        for (int rot = 0; rot < 2; rot++) {
            int alturaPeca = (rot == 0 ? pecas[idx].first : pecas[idx].second);
            int larguraPeca = (rot == 0 ? pecas[idx].second : pecas[idx].first);

            // Verifica se a peça cabe nos limites
            if (celulaVazia.first + alturaPeca <= tabuleiroAltura &&
                celulaVazia.second + larguraPeca <= tabuleiroLargura) {

                // Verifica se o espaço está livre
                bool podeColocar = true;
                for (int i = 0; i < alturaPeca && podeColocar; i++) {
                    for (int j = 0; j < larguraPeca; j++) {
                        if (tabuleiro[celulaVazia.first + i][celulaVazia.second + j]) {
                            podeColocar = false;
                            break;
                        }
                    }
                }

                if (!podeColocar) continue;

                // Coloca a peça
                for (int i = 0; i < alturaPeca; i++) {
                    for (int j = 0; j < larguraPeca; j++) {
                        tabuleiro[celulaVazia.first + i][celulaVazia.second + j] = true;
                    }
                }

                //cout << "Colocando peça " << alturaPeca << "x" << larguraPeca 
                //     << " (id=" << idx << ", rot=" << rot << ")" << endl;
                //printTabuleiro(tabuleiro);

                // Cria nova lista de peças sem a usada
                vector<pair<int, int>> novasPecas = pecas;
                novasPecas.erase(novasPecas.begin() + idx);

                // Recursão
                if (preencherTabuleiro(tabuleiro, novasPecas, tabuleiroAltura, tabuleiroLargura)) {
                    return true;
                }

                // Backtracking: remove a peça
                for (int i = 0; i < alturaPeca; i++) {
                    for (int j = 0; j < larguraPeca; j++) {
                        tabuleiro[celulaVazia.first + i][celulaVazia.second + j] = false;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    int tabuleiroAltura, tabuleiroLargura;
    cin >> tabuleiroAltura >> tabuleiroLargura;

    int n;
    cin >> n;

    vector<pair<int, int>> tamanhoPecas;
    for (int i = 0; i < n; i++) {
        int altura, largura;
        cin >> altura >> largura;
        tamanhoPecas.push_back({altura, largura});
    }

    vector<vector<bool>> tabuleiro(tabuleiroAltura, vector<bool>(tabuleiroLargura, false));

    bool resultado = preencherTabuleiro(tabuleiro, tamanhoPecas, tabuleiroAltura, tabuleiroLargura);

    if (resultado) {
        cout << "yebo" << endl;
    } else {
        cout << "cha" << endl;
    }

    return 0;
}
