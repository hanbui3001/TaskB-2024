#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include<iostream>
using namespace std;

template<typename T>
class ArrayStack{
	private:
		int Size;
		int Space;
		T* elem;
	public:
		ArrayStack(){
			Size = 0;
			Space = 0;
			elem = nullptr;
		}
		~ArrayStack(){
			if(elem != nullptr){
				delete[] elem;
			}
		}
		int size(){
			return Size;
		}
		bool empty(){
			return Size == 0;
		}
		T& top(){
			return elem[Size - 1];
		}
		void pop(){
			if(empty()) return;
			Size--;
		}
		void push(T val){
			if(Size == Space){
				Space = Size == 0 ? 1 : Space * 2;
				T* tmp = new T[Space];
				for(int i = 0; i < Size; i++){
					tmp[i] = elem[i];
				}
				if(elem != NULL){
					delete[] elem;
				}
				elem = tmp;
			}
			elem[Size] = val;
			Size++;
		}
		void clear(){
			Size = 0;
		}
		class iterator{
			private:
				T* ptr;
			public:
				iterator(T* p):ptr(p){
				}
				bool operator!=(const iterator& other){
					return ptr != other.ptr;
				}
				iterator& operator=(iterator& other){
					ptr = other.ptr;
					return *this;
				}
				iterator& operator++(){
					ptr++;
					return *this;
				}
				T& operator*(){
					return *ptr;
				}
		};
		iterator begin() { 
			return iterator(elem); 
		}
    	iterator end() {
			return iterator(elem + Size);
		}
};

#endif
