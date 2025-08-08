#include <iostream>

using namespace std;

long long int numNaoAtaques(long long int k)
{
    long long int numPosicoes = (k * k) * (k * k - 1) / 2;
    long long int numAtaques;

    if(k <= 2)
    {
        numAtaques = 0;
    }
    else
    {
        numAtaques = 4 * (k-1) *  (k-2);
    }

    return numPosicoes - numAtaques;
}

int main()
{
    int n;

    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << numNaoAtaques(i) << endl;
    }

    return 0;
}