#include "ArrayStack.h"
#include "SingleListStack.h"
#include <iostream>

using namespace std;

int main(){
	int q;
	cin >> q;
	ArrayStack<int> st;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int val;
			cin >> val;
			st.push(val);
		}
		else if(t == 2){
			if(!st.empty()){
				st.pop();
			}
		}
		else if(t == 3){
			if(st.empty()){
				cout << "EMPTY!";
			}
			else{
				cout << st.top();
			}
		}
	}
}
