#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

// Retorna as medianas "lower" (mesma semântica do seu código original)
vector<int> medianas(vector<int>& nums, int k)
{
    vector<int> resultados;
    if (k == 0 || nums.size() < (size_t)k) return resultados;

    multiset<int> janela_lo;
    multiset<int> janela_hi;

    auto tamanho_desejado_lo = [&](int k) {
        return (k + 1) / 2; 
    };

    auto rebalancear = [&](int k) {
        size_t want = tamanho_desejado_lo(k);
        while (janela_lo.size() > want) {
            auto it = prev(janela_lo.end());
            janela_hi.insert(*it);
            janela_lo.erase(it);
        }
        while (janela_lo.size() < want && !janela_hi.empty()) {
            auto it = janela_hi.begin();
            janela_lo.insert(*it);
            janela_hi.erase(it);
        }
    };

    auto inserir = [&](int val, int k) {
        if (janela_lo.empty() || val <= *prev(janela_lo.end()))
            janela_lo.insert(val);
        else
            janela_hi.insert(val);
        rebalancear(k);
    };

    auto remover = [&](int val, int k) {
        auto it = janela_lo.find(val);
        if (it != janela_lo.end()) {
            janela_lo.erase(it);
        } else {
            it = janela_hi.find(val);
            if (it != janela_hi.end())
                janela_hi.erase(it);
        }
        rebalancear(k);
    };

    for (int i = 0; i < k; ++i)
        inserir(nums[i], k);

    resultados.push_back(*prev(janela_lo.end()));

    for (size_t i = k; i < nums.size(); ++i)
    {
        inserir(nums[i], k);
        remover(nums[i - k], k);
        resultados.push_back(*prev(janela_lo.end()));
    }

    return resultados;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> resultados = medianas(nums, k);
    for (size_t i = 0; i < resultados.size(); ++i) {
        cout << resultados[i] << " ";
    }
    cout << "\n";

    return 0;
}
