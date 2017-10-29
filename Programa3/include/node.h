#ifndef NODE_H
#define NODE_H
#include <memory>
using namespace std;
template <typename T>
class Node{
private:
	Node<T> *next;
	T *value;
	Node<T> *prev;
public:
	Node();
	Node(T novo);
	~Node();
	void set_next(Node<T> *n);
	void set_prev(Node<T> *p);
	void set_value(T v);
	Node<T>* get_next();
	Node<T>* get_prev();
	T* get_value();
};
template <typename T>
Node<T>::Node(){
	next = nullptr;
	prev = nullptr;
	value = NULL;
}
template <typename T>
Node<T>::Node(T novo){
	next = nullptr;
	prev = nullptr;
	value = new T (novo);
}
template <typename T>
Node<T>::~Node(){
	delete value;
}
template <typename T>
void Node<T>::set_next(Node<T> *n){	
	next = n;
}
template <typename T>
void Node<T>::set_prev(Node<T> *p){	
	prev = p;
}
template <typename T>
void Node<T>::set_value(T v){	
	value = new T(v);
}
template <typename T>
Node<T>* Node<T>::get_next(){
	return next;
}
template <typename T>
Node<T>* Node<T>::get_prev(){
	return prev;
}
template <typename T>
T* Node<T>::get_value(){
	return value;
}
#endif