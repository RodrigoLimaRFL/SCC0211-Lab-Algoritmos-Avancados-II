#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<string> palavras;
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        string palavra;
        cin >> palavra;
        palavras.push_back(palavra);
    }

    int numPalavras = palavras.size();

    map<string, bool> anagramas;

    for(int i = 0; i < numPalavras; i++)
    {
        sort(palavras[i].begin(), palavras[i].end());
        anagramas[palavras[i]] = true;
    }

    cout << anagramas.size() << endl;
}