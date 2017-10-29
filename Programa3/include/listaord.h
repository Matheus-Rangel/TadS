#ifndef LISTAORD_H
#define LISTAORD_H
#include "lista.h"
#include "node.h"
#include <iostream>
using namespace std;
template<typename T>
class listaord : public lista<T>{
public:
	void insertord(T i);
};
template<typename T>
void listaord<T>::insertord(T i){
	if(lista<T>::tamanho == 0){
		this->push_front(i);
	}
	else if( this->begin() >= i){
		this->push_front(i);
	}
	else if(this->end() <= i){
		this->push_back(i);
	}
	else{
		Node<T> *temp = lista<T>::cabeca;
		Node<T> *novo = new Node<T>(i);
		while((temp->get_next())->get_next()){
			temp = temp->get_next();
			if(i <= *(temp->get_value())){
				novo->set_next(temp);
				novo->set_prev(temp->get_prev());
				(temp->get_prev())->set_next(novo);
				temp->set_prev(novo);
				break;
			}
		}
		lista<T>::tamanho++;
	}
	this->begin();//retorna o atual para o comeco apos inserir
}

#endif