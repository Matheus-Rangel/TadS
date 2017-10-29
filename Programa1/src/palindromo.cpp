#include "pilha.h"
#include <cctype>
#include <iostream>

int main(int argc, char **argv){//recebe como parametro as palavras para checar
	Pilha<char> p; 
	if(argc =! 2)
		return 1;
	int i = 1;
	int j = 0;
	int k = 0;
	char *formatado =  new char(50);//tamanho maximo 50
	while(argv[i]){
		j = 0;
		while(argv[i][j]){
			if(k == 50){
				std::cout<<"Numero maximo de chacteres excedido. 50"<<std::endl;
				return 1;
			}//checa antes de fazer a cesso se o numero de chacteres nao foi excedido.
			formatado[k] = tolower(argv[i][j]);
			j++;
			k++;
		}
		i++;
	}
	i = 0;
	while(i<k){
		p.push(formatado[i]);//armazena a palavra em uma pilha
		i++;
	}
	i = 0;
	while(i<k){
		if(formatado[i] != p.top()){ //pega o proximo elemento da pilha e testa.
			std::cout<<"Nao Palindromo"<<std::endl;
			return 0;
		}
		p.pop();//remove o proximo elemento da lista.
		i++;
	}
	std::cout<<"Palindromo!!!"<<std::endl;
	return 0;
}		
