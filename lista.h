#ifndef LISTA_H
#define LISTA_H
#include "node.h"
#include <memory>
using namespace std;
template <typename T>
class lista{
protected:
	shared_ptr<Node<T>> cabeca;
	shared_ptr<Node<T>> cauda;
	int tamanho;
	int pos;
	shared_ptr<Node<T>> atual;
public:
	lista();
	T begin();
	T back();
	T next();
	T end();
	void insert(int i, T novo);//insere um novo elemento após itn
	void push_back(T novo);
	void push_front(T novo);
	void pop_back();
	void pop_front();
	void remove(int i);
	void clr();
};
template <typename T>
lista<T>::lista(){
	cabeca =  make_shared<Node<T>>;
	cauda = make_shared<Node<T>>;
	cabeca->set_next(make_shared<Node<T>> (cauda));
	cauda->set_prev(make_shared<Node<T>> (cabeca));
	tamanho = 0;
	pos = 0;
}
template <typename T>
T lista<T>::begin(){
	atual = cabeca->get_next;
	pos = 0;
	return atual->get_value;
}
template <typename T>
T lista<T>::back(){
	if(atual->get_prev == cabeca){
		return atual->get_value;
		pos = 0;
	}
	atual = atual->get_prev;
	pos--;
	return atual->get_value;
}
template <typename T>
T lista<T>::next(){
	if(atual->get_next == cauda){
		return atual->get_value;
		pos =  tamanho - 1;
	}
	atual = atual->get_next;
	pos++;
	return atual->get_value;
}
template <typename T>
T lista<T>::end(){
	atual = cauda->get_prev;
	pos = tamanho - 1;
	return atual->get_value;
}
template <typename T>
void lista<T>::push_back(T novo){
	shared_ptr<Node<T>> n = make_shared<Node<T>> (novo);
	n->set_prev(cauda->get_prev());
	n->set_next(cauda);
	(cauda->get_prev())->set_next(n);
	cauda->set_prev(n);
	tamanho++;
}
template <typename T>
void lista<T>::push_front(T novo){
	shared_ptr<Node<T>> n = make_shared<Node<T>> (novo);
	n->set_prev(cabeca);
	n->set_next(cabeca->get_next());
	(cabeca->get_next())->set_prev(n);
	cabeca->set_next(n);
	tamanho++;
}
template <typename T>
void lista<T>::insert(int i, T novo){
	if(i >= tamanho)
		push_back(novo);
	if(i <= 0)
		push_front(novo);
	int it = 0;
	shared_ptr<Node<T>> n = make_shared<Node<T>> (novo);
	shared_ptr<Node<T>> temp = cabeca;
	while(it < i){
		temp = temp->get_next();
		it++;
	}
	n->set_next(temp->get_next);
	n->set_prev(temp);
	(temp->get_next)->set_prev(n);
	temp->set_next(n);
}
template <typename T>
void lista<T>::pop_back(){
	cauda->set_prev((cauda->get_prev)->get_prev);
	(cauda->get_prev)->set_next(cauda);
	tamanho--;

}
template <typename T>
void lista<T>::pop_front(){
	cabeca->set_next((cabeca->get_next)->get_next);
	(cabeca->get_next)->set_prev(cabeca);
	tamanho--;
}
template <typename T>
void lista<T>::remove(int i){
	int it = 0;
	shared_ptr<Node<T>> temp = cabeca;
	while(it <= i){
		temp = temp->get_next();
		it++;
	}
	(temp->get_prev)->set_next(temp->get_next);
	(temp->get_next)->set_prev(temp->get_prev);
}
template <typename T>
void lista<T>::clr(){
	cabeca->set_next(cauda);
	cauda->set_prev(cabeca);
}
#endif

