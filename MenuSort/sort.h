#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;

void showVet(int* v, int MAX){
	cout << "\n[ ";
	for(int i = 0; i < MAX; i++){
		if(i < MAX - 1){
			cout << v[i] << ", ";
		}else{
			cout << v[i];
		}
	}
	cout << " ]" <<endl;
}

void load(string load){
	for(int i = 0; i < 3; i++){
		load += " .";
		cout << load;
		Sleep(500);
		if(i < 2) system("cls");
	}
}

void gerarVetor(int * v){
	srand(time(NULL));	
	load("Gerando");
	for(int i = 0; i < 10; i++){	
		v[i] = rand() % 100;
		Sleep(150);
		system("cls");	
		int count = 0;
		cout << "vetor => [ ";
		while(count <= i ){
			if(count < 9){
				cout << v[count] << ", ";	
			}else{
				cout << v[count];
			}
			count++;		
		}
	}
	cout <<" ]\n\n";
}

/* BubbleSort*/
void BubbleSort(int * v){	
	int troca = 1;
	int max = 10;
	cout << "Vetor Original: ";
	showVet(v, max);
	cout << "\nOrdenação: BubbleSort..." << endl;
	while(troca != 0){
			troca = 0;
		for(int i = 0; i < max - 1; i++){
			if(v[i] > v[i + 1]){
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				troca = 1;
			}
		}
		max--;
	}
	showVet(v, 10);
}

/* InsertionSort */
void InsertionSort(int *v){
	cout << "Vetor Original: " << endl;
	showVet(v, 10);
	cout << "\nOrdenação: InsertionSort..." << endl;
	for(int i = 1; i < 10; i++){
		int j = i;
		while(v[j] < v[j - 1] && j > 0){
			int aux = v[j];
			v[j] = v[j - 1];
			v[j - 1] = aux;
			j--;
		}
	}
	showVet(v, 10);
}

/* SelectionSort*/
void SelectionSort(int *v){
	cout << "\nVetor Original: " << endl;
	showVet(v, 10);
	cout << "\nOrdenação: SelectionSort..." << endl;
	for(int i = 0; i < 10; i++){
		int menor = i;
		for(int j = i + 1; j < 10; j++){
			if(v[menor] > v[j]){
				menor = j;
			}
		}
		int aux = v[i];
		v[i] = v[menor];
		v[menor] = aux;
	}
	showVet(v, 10);
}

/* CountingSort*/
void CountingSort(int * v){
	cout << "\nVetor Original: " << endl;
	showVet(v, 10);
	
	int count[10];
	for(int i = 0; i < 10; i++){
		count[i] = 0;
	}
	
	int saida[10];
	cout << "\nOrdenação: CountingSort..." << endl;
	for(int i = 0; i < 10-1; i++){
		for(int j = i + 1; j < 10; j++){
			if(v[i] > v[j]){
				count[i]++;
			}else{
				count[j]++;
			}
		}
	}
	
	for(int i = 0; i < 10; i++){
		saida[count[i]] = v[i];
	}	
	showVet(saida, 10);	
}

/* ShellSort */
void ShellSort(int *v){
	cout << "\nVetor Original: " << endl;
	showVet(v, 10);
	int inc[3] = {5, 3, 1};
	int x = 0;
	cout << "\nOrdenação: ShellSort..." << endl;
	while(inc[x] > 1){
		int i = 0;
		int j = inc[x];
		while(j < 10){
			if(v[i] > v[j]){
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
			i++;
			j++;
		}
		x++;
	}
	showVet(v, 10);
	cout << "\nChamando InsertionSort...\n" << endl;
	InsertionSort(v);
}


/* Ordenação por Contagem Distribuida */
void CountingDistributionSort(int *v){
	
	cout << "\nVetor Original: " << endl;
	showVet(v, 10);
	
	int saida[10];
	int menor, maior;
 	menor = v[0];
 	maior = menor;
 	
 	cout << "\nOrdenação: CountingDistributionSort..." << endl;
 	for(int i = 1; i < 10; i++){
 		if(v[i] < menor){
 			menor = v[i];
		 }
		 else if(v[i] > maior){
		 	maior = v[i];
		 }
	 }
	 
	 int cont[maior + 1];
	 for(int i = 0; i <= maior; i++){
	 	cont[i] = 0;
	 }
	 
	 for(int i = 0; i < 10; i++){
	 	cont[v[i]]++;
	 }
	 
	 for(int i = menor + 1; i <= maior; i++){
	 	cont[i] += cont[i - 1];
	 }
	 
	 for(int j = 0; j < 10; j++){
	 	int i = cont[v[j]];
	 	saida[i - 1] = v[j];
	 	cont[v[j]]--;
	 }	 
	 showVet(saida, 10);
}

 /* ordenação simples */
void sort(int *v, int max){
	for(int i = 0; i < max - 1; i++){
		for(int j = i + 1; j < max; j++){
			if(v[i] > v[j]){
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

/* MergeSort */
void MergeSort(int *v){
	cout << "Vetor Original: ";
	showVet(v, 10);
	
	int v1[5], v2[5];
	for(int i = 0; i < 5; i++){
		v1[i] = v[i];
	}
	
	int j = 0;
	for(int i = 5; i < 10; i++){
		v2[j] = v[i];
		j++;
	}
	
	sort(v1, 5);
	sort(v2, 5);
	//showVet(v1, 5);
	//showVet(v2, 5);
	
	cout << "\nOrdenação: MergeSort..." << endl;
	int i = 0, k = 0;
	j = 0;
	
	while(i < 5 and j < 5){
		if(v1[i] < v2[j]){
			v[k] = v1[i];
			i++;
		}else{
			v[k] = v2[j];
			j++;	
		}
		k++;
	}
	
	while(i < 5){
		v[k] = v1[i];
		i++;
		k++;
	}
	
	while(j < 5){
		v[k] = v2[j];
		j++;
		k++;	
	}
	
	showVet(v, 10);	
}


