#include <bits/stdc++.h>

using namespace std; 

#define MAXN 10000 
#define SQRSIZE 100 

int arr[MAXN];			 // vetor original 
int block[SQRSIZE];		 // vetor decomposto 
int blk_sz;					 // tamanho do bloco

// Complexidade : O(1) 
void update(int idx, int val){ 
	int blockNumber = idx / blk_sz; 
	block[blockNumber] += val - arr[idx]; 
	arr[idx] = val; 
} 

// Complexidade : O(sqrt(n)) 
int query(int l, int r){ 
	int sum = 0; 
	while (l<r and l%blk_sz!=0 and l!=0){ 
		// Caminhando pelo limite esquerdo 
		sum += arr[l]; 
		l++; 
	} 
	while (l+blk_sz <= r){ 
		// Caminhando pelos blocos menores do que o limite direito 
		sum += block[l/blk_sz]; 
		l += blk_sz; 
	} 
	while (l<=r){ 
		// Caminhando pelo bloco do limite direito
		sum += arr[l]; 
		l++; 
	} 
	return sum; 
} 

// Preenche os valores na variavel input 
void preprocess(int input[], int n){ 
	// Iniciando o index do bloco
	int blk_idx = -1; 

	// Calculo do tamanho do bloco 
	blk_sz = sqrt(n); 

	// Criando o vetor decomposto 
	for (int i=0; i<n; i++){ 
		arr[i] = input[i]; 
		if (i%blk_sz == 0){ 
			// Entrando no proximo bloco 
			// Incrementando o valor do indice 
			blk_idx++; 
		} 
		block[blk_idx] += arr[i]; 
	} 
} 


int main(){ 
	
	int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10}; 
	int n = sizeof(input)/sizeof(input[0]); 

	preprocess(input, n); 

	cout << "query(3,8) : " << query(3, 8) << endl; 
	cout << "query(1,6) : " << query(1, 6) << endl; 
	update(8, 0); 
	cout << "query(8,8) : " << query(8, 8) << endl; 
	return 0; 
} 

