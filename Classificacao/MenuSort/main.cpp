#include <iostream>
#include "sort.h"

using namespace std;

int vetor[10];

void opcoes(char);
void menu();

int main(){
	menu();
	return 0;
}

void menu(){
	setlocale(LC_ALL, "Portuguese");
	gerarVetor(vetor);
	system("cls");
	char r = ' ';
	while(r != 's'){
		cout << "\n\tMétodos de Ordenação\n" << endl;
		cout << "\t1 - Gerar Vetor" << endl;
		cout << "\t2 - BubbleSort" << endl;
		cout << "\t3 - InsertionSort" << endl;
		cout << "\t4 - SelectionSort" << endl;
		cout << "\t5 - CountingSort" << endl;
		cout << "\t6 - CountingDistributedSort" << endl;
		cout << "\t7 - ShellSort" << endl;
		cout << "\t8 - MergeSort" << endl;
		cout << "\n\tS - Sair" << endl;
		
		cout << "\n\tEscolha: ";
		cin >> r;
		if(r == 'S') r = 's';
		system("cls");
		opcoes(r);	
	}	
}

void opcoes(char input){
	switch(input){
		case '1':{
			gerarVetor(vetor);
			break;
		}
		case '2':{
			BubbleSort(vetor);
			break;
		}
		case '3':{
			InsertionSort(vetor);
			break;
		}
		case '4':{
			SelectionSort(vetor);
			break;
		}
		case '5':{
			CountingSort(vetor);
			break;
		}
		case '6':{
			CountingDistributionSort(vetor);
			break;
		}
		case '7':{
			ShellSort(vetor);
			break;
		}
		case '8':{
			MergeSort(vetor);
			break;
		}
		case 's' :{
			cout << "Bye Bye..." << endl;
			break;
		}
		default:{
			cout << "Valor inválido..." << endl;
			break;
		}
	}//fim switch
	cout << "\n";
	system("pause");
	system("cls");
}


