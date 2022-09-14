
#include <cstdlib>
#include <iostream>
#include <type_traits>
using namespace std;

struct Node {
	int valor;
	Node* prox;
};

Node* firstElement = NULL;
Node* lastElement = NULL;

// headers
void menu();
void initialize();
void showListLength();
void showElements();
void insertElement();
void removeElement();
void searchElement();
Node* elementPosition(int numero);
//--------------------------

int main(){
	menu();
}

void menu() {
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		// system("clear"); // somente Node linux e no powershell

		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: initialize();
			break;
		case 2: showListLength();
			break;
		case 3: showElements();
			break;
		case 4: searchElement();
			break;
		case 5: insertElement();
			break;
		case 6: removeElement();
			break;

		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
		// system("read -p 'Press [Enter] key to start ...'"); // somente no linux
	}
}

void initialize() {
	// se a lista j� possuir elementos
	// libera a memoria ocupada
	Node* aux = firstElement;
	while (aux != NULL) {
		Node* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	firstElement = NULL;
	cout << "Lista inicializada \n";
}

void showListLength() {
	int nElementos = 0;
	Node* aux = firstElement;

	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;
}

void showElements() {
	if (firstElement == NULL) {
		cout << "Lista vazia \n";
		return;
	} else {
		cout << "Elementos: \n";
		Node* aux = firstElement;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void insertElement() {
	// aloca memoria dinamicamente para o novo elemento
	Node* newItem = (Node*)malloc(sizeof(Node));
	if (newItem == NULL) {
		return;
	}

	cout << "Digite o elemento: ";
	cin >> newItem->valor;
	newItem->prox = NULL;

	Node* alreadyExists = elementPosition(newItem->valor);

	if(alreadyExists) {
		cout << "Elemento já existe na lista, tente outro.";
		return;
	}

	if (firstElement == NULL) {
		firstElement = newItem;
		lastElement = newItem;
	} else {
		lastElement->prox = newItem;
		lastElement = newItem;

		// Bubble Sort
		bool isSwapped = true;

		while(isSwapped) {
			Node* current = firstElement;

			isSwapped = false;

			while(current->prox != NULL) {
				Node* nextElement = current->prox;

				if(current->valor > nextElement->valor) {
					int swap = current->valor;

					current->valor = nextElement->valor;
					nextElement->valor = swap;

					isSwapped = true;
					continue;
				}
				current = current->prox;
			}
		}
	}
}

void removeElement() {
	int inputValue;
	cout << "Digite o valor que quer excluir: ";
	cin >> inputValue;

	Node* aux = firstElement;
	while (aux->prox != NULL) {
		Node* nextElement = aux->prox;

		if (firstElement->valor == inputValue) {
			free(firstElement);
			firstElement = nextElement;
			break;
		}

		if(nextElement->valor == inputValue) {
			aux->prox = nextElement->prox;

			free(nextElement);
			break;
		}
		aux = aux->prox;
	}
}

void searchElement() {
	int inputValue;
	cout << "Digite o valor que quer excluir: ";
	cin >> inputValue;

	Node* element = elementPosition(inputValue);

	if(element == NULL) {
		cout << "Nenhum elemento foi encontrado com esse valor.";
		return;
	}

	cout << element->valor;
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
Node* elementPosition(int value) {
	Node* current = firstElement;

	while (current != NULL) {
		if (current->valor == value) {
			break;
		}
		current = current->prox;
	}
	
	return current;
}