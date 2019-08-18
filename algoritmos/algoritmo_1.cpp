#include <bits/stdc++.h>
using namespace std;

int main(){
	int melhor = 0;
	for(int a = 0; a < n; a++){
		for(int b = a; b < n; b++){
			int soma = 0;
			for(int k = a; k <= b; k++){
					soma += vetor[k];
			}
			melhor = max(melhor, soma);
		}
	}
	cout << melhor << endl;
	return 0;
}

