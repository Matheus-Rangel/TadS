#ifndef NODE_H
#define NODE_H
#include <memory>
using namespace std;
template <typename T>
class Node{
private:
	shared_ptr<Node<T>> next;
	T value;
	shared_ptr<Node<T>> prev;
public:
	Node();
	Node(T novo);
	Node(const Node<T> &novo);
	void set_next(shared_ptr<Node> n);
	void set_prev(shared_ptr<Node> p);
	void set_value(T v);
	shared_ptr<Node<T>> get_next();
	shared_ptr<Node<T>> get_prev();
	T get_value();
};
template <typename T>
Node<T>::Node(){
	next = nullptr;
	prev = nullptr;
	value = make_shared<T> (NULL);
}
template <typename T>
Node<T>::Node(T novo){
	next = nullptr;
	prev = nullptr;
	value = make_shared<T> (novo);
}
template <typename T>
Node<T>::Node(const Node<T> &novo){
	next = novo.get_next;
	value = novo.get_value;
	prev =  novo.get_prev;
}
template <typename T>
void Node<T>::set_next(shared_ptr<Node<T>> n){	
	next = n;
}
template <typename T>
void Node<T>::set_prev(shared_ptr<Node<T>> p){	
	prev = p;
}
template <typename T>
void Node<T>::set_value(T v){	
	value = v;
}
template <typename T>
shared_ptr<Node<T>> Node<T>::get_next(){
	return next;
}
template <typename T>
shared_ptr<Node<T>> Node<T>::get_prev(){
	return prev;
}
template <typename T>
T Node<T>::get_value(){
	return value;
}
#endif