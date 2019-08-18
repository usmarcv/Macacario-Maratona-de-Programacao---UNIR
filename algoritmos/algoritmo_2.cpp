#include <bits/stdc++.h>
using namespace std;

int main(){
	int melhor = 0;
	for(int a = 0; a < n; a++){
		int soma = 0;
		for(int b = a; b < n; b++){
			soma += vetor[b];
			melhor = max(melhor, soma);
		}
	}
	cout << melhor << "\n";
	return 0;
}

