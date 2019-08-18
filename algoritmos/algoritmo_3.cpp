#include <bits/stdc++.h>
using namespace std;

int main(){
	int melhor = 0, soma = 0;
	for(int k = 0; k < n; k++){
		soma = max(vetor[k], soma + vetor[k]);
		melhor = max(melhor, soma);
	}
	cout << melhor << "\n";
	return 0;
}

