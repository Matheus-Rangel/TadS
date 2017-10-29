#include "lista.h"
#include <iostream>
using namespace std;
int main(){
	lista<char> l;
	int i = 0;
	int j = 0;
	char exp[20];
	char op;
	cout<<"Digite a expressao: ";
	cin.getline(exp, 20, '\n');
	//armaze a entrada na lista
	while(isprint(exp[i])){
		l.push_back(exp[i]);
		i++;
	}
	i = 0;
	op = l.value();
	l.advance();
	do{
		i = i *10;
		i = i + (op - '0');		
		op = l.value();
	}while (op != ' ');//converte o primeiro numero da lista e armazena no int i
	cout<<i<<endl;
	while(l.advance()){//pula os whitespace 
		j = 0;
		op = l.value();
		l.advance();
		do{
			j = j *10;
			j = j + (op - '0');
			op = l.value();
			l.advance();
		}while (op != ' ');//armazena o proximo numero da lista.
		op = l.value();//armazena a operacao e faz o calculo
		l.advance();
		cout<<"exp = "<<i<<" "<<op<<" "<<j<<endl;
		switch(op){
			case '+': i = i + j; break;
			case '-': i = i - j; break;
			case '*': i = i * j; break;
			case '/': i = i / j; break;
			default : 
				cout<<"Expressao Invalida"<<endl;
				return 1;
				break;
		}
	}
	std::cout<<"Resultado = "<< i << std::endl;
}