#ifndef LISTA_H
#define LISTA_H
#include "node.h"
using namespace std;
template <typename T>
class lista{
protected:
	Node<T> *cabeca;
	Node<T> *cauda;
	int tamanho;
	Node<T> *atual;
public:
	lista();
	~lista();
	T begin();//retorna o valor do primeiro elemento, e volta o atual para inicio
	T end();//retorna o valor do ultimo elemento, e coloca o atual no final 
	T value();//retorna o valor do elemento atual.
	bool advance();//avanca o ponteiro atual. retorna false quando chega no fim da lista
	void regress();//volta o ponteiro atual.
	void insert(int i, T novo);//insere um novo elemente apos a posicao i
	void push_back(T novo);//insere um novo elemento no final
	void push_front(T novo);//insere um novo elemento no inicio
	void pop_back();//remove o ultimo elemento
	void pop_front();//remove o primeiro elemento
	void remove(int i);//remove o elemento na posicao i
	void clr();//limpa a lista
	int size();//retorna o tamnho da lista
	bool endoflist();//retornar se o ponteiro atual ja chegou ao final
};
template <typename T>
lista<T>::lista(){
	cabeca =  new Node<T>;
	cauda = new Node<T>;
	cabeca->set_next(cauda);
	cauda->set_prev(cabeca);
	atual = cabeca;
	tamanho = 0;
}
template <typename T>
lista<T>::~lista(){
	atual = cabeca->get_next();
	while(atual != cauda){
		delete atual->get_prev();
		atual = atual->get_next();
	}
	delete cauda->get_prev();
	delete cauda;
}
template <typename T>
bool lista<T>::endoflist(){
	return atual == cauda;
}
template <typename T>
bool lista<T>::advance(){
	if(atual != cauda)
		atual = atual->get_next();
	return atual != cauda;
}
template <typename T>
void lista<T>::regress(){
	atual = atual->get_prev();
}
template <typename T>
T lista<T>::begin(){
	atual = cabeca->get_next();
	return *(atual->get_value());
}
template <typename T>
T lista<T>::value(){
	return *(atual->get_value());
}
template <typename T>
T lista<T>::end(){
	atual = cauda->get_prev();
	return *(atual->get_value());
}
template <typename T>
void lista<T>::push_back(T novo){
	Node<T> *n = new Node<T>(novo);
	n->set_prev(cauda->get_prev());
	n->set_next(cauda);
	(cauda->get_prev())->set_next(n);
	cauda->set_prev(n);
	tamanho++;
	this->begin();
}
template <typename T>
void lista<T>::push_front(T novo){
	Node<T> *n = new Node<T>(novo);
	n->set_prev(cabeca);
	n->set_next(cabeca->get_next());
	(cabeca->get_next())->set_prev(n);
	cabeca->set_next(n);
	tamanho++;
	this->begin();
}
template <typename T>
void lista<T>::insert(int i, T novo){
	if(i >= tamanho)
		push_back(novo);
	if(i <= 0)
		push_front(novo);
	int it = 0;
	Node<T> *n = new Node<T> (novo);
	Node<T> *temp = cabeca;
	while(it < i){
		temp = temp->get_next();
		it++;
	}
	n->set_next(temp->get_next());
	n->set_prev(temp);
	(temp->get_next())->set_prev(n);
	temp->set_next(n);
	tamanho ++;
	this->begin();
}
template <typename T>
void lista<T>::pop_back(){
	if(tamanho > 0){
		Node<T> *temp = cauda->get_prev();
		cauda->set_prev(temp->get_prev());
		delete temp;
		(cauda->get_prev)->set_next(cauda);
		tamanho--;
		this->begin();
	}
}
template <typename T>
void lista<T>::pop_front(){
	if(tamanho > 0){
		Node<T> *temp = cabeca->get_next();
		cabeca->set_next(temp->get_next());
		delete temp;
		(cabeca->get_next)->set_prev(cabeca);
		tamanho--;
		this->begin();
	}
}
template <typename T>
void lista<T>::remove(int i){
	if(tamanho >0){
		int it = 0;
		Node<T> *temp = cabeca;
		while(it <= i){
			temp = temp->get_next();
			it++;
		}
		(temp->get_prev())->set_next(temp->get_next());
		(temp->get_next())->set_prev(temp->get_prev());
		delete temp;
		tamanho--;
		this->begin();
	}
}
template <typename T>
void lista<T>::clr(){
	while(tamanho > 0){
		this->pop_back();
	}
}
template <typename T>
int lista<T>::size(){
	return tamanho; 
}
#endif



