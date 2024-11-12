#ifndef SINGLELISTSTACK_H
#define SINGLELISTSTACK_H

#include<iostream>
using namespace std;

#include<iostream>
using namespace std;
template<typename T>
class Node{
	private:
		Node<T> *next;
		T elem;
	public:
		Node(T x, Node<T> *p = nullptr){
			elem = x;
			next = p;
		}
		Node<T>* getNext(){
			return next;
		}
		T& getElem(){
			return elem;
		}
		void setNext(Node<T>& p){
			next = p;
		}
		void setElem(T n){
			elem = n;
		}	
};
template<typename T>
class ListStack{
	private:
		int Size;
		Node<T> *head;
	public:
		ListStack(){
			Size = 0;
			head = nullptr;
		}
		int size(){
			return Size;
		}
		bool empty(){
			return Size == 0;
		}
		T& top(){
			return head->getElem();
		}
		void pop(){
			if(Size <= 1){
				Size = 0;
				head = nullptr;
				return;
			}
			else{
				head = head->getNext();
				Size--;
			}
		}
		void push(T x){
			Node<T>* res = new Node<T>(x, head);
			head = res;
			Size++;
		}
		class iterator{
			private:
				Node<T>* it;
			public:
				iterator(Node<T>* p = nullptr) : it(p){
				}
				iterator begin(){
					return iterator(it);
				}
				iterator end(){
					return iterator(nullptr);
				}
				bool operator!=(iterator& other){
					return it != other->it;
				}
				iterator& operator=(iterator& other){
					it = other->it;
					return *this;
				}
				iterator& operator++(){
					if(it != nullptr){
						it = it->getNext();
					}
					return *this;
				}
				T& operator*(){
					return it->getElem();
				}
		};
};
#endif