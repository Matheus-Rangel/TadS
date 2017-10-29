#include "listaord.h"
#include <iostream>
using namespace std;
int main(){//aplicativo para testar a lista ordenada
	listaord<int> l;
	int i = 1;
	std::cout<<"Digite os numeros,  0 para terminar :"<<endl;
	while(i){//armazena valores de forma ordenada na lista ate que seja digitado o valor 0
		cin>>i;
		l.insertord(i);
	}

	while(!(l.endoflist())){//imprime os valores da lista
		cout<<l.value()<<" ";
		l.advance();
	}
	l.remove(2);//remove o valor na posicao 2
	cout<<endl;
	while(!(l.endoflist())){//imprime a lista novamente
		cout<<l.value()<<" ";
		l.advance();
	}
	cout<<endl;
}
