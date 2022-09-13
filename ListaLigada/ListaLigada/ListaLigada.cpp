
#include <cstdlib>
#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* firstElement = NULL;
NO* lastElement = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu() {
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		// system("clear"); // somente no linux e no powershell

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
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;

		case 7:
			return;
		default:
			break;
		}

		// system("pause"); // somente no windows
		system("read -p 'Press [Enter] key to start ...'"); // somente no linux
	}
}

void inicializar() {
	// se a lista j� possuir elementos
	// libera a memoria ocupada
	NO* aux = firstElement;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	firstElement = NULL;
	cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = firstElement;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos() {
	if (firstElement == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = firstElement;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento() {
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* alreadyExists = posicaoElemento(novo->valor);

	if(alreadyExists) {
		cout << "Elemento já existe na lista, tente outro.";
		return;
	}

	if (firstElement == NULL)
	{
		firstElement = novo;
		lastElement = novo;
	}
	else
	{
		// Insere no final da lista
		lastElement->prox = novo;
		lastElement = novo;
	}
}

void excluirElemento() {
	int inputValue;
	cout << "Digite o valor que quer excluir: ";
	cin >> inputValue;

	NO* aux = firstElement;
	while (aux->prox != NULL) {
		NO* nextElement = aux->prox;

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

void buscarElemento() {
	int inputValue;
	cout << "Digite o valor que quer excluir: ";
	cin >> inputValue;

	NO* element = posicaoElemento(inputValue);

	if(element == NULL) {
		cout << "Nenhum elemento foi encontrado com esse valor.";
		return;
	}

	cout << element->valor;
}

// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento n�o estiver na lista
NO* posicaoElemento(int numero) {
	NO* aux = firstElement;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}