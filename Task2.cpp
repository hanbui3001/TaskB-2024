#include "ArrayStack.h"
#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	cin >> s;
	ArrayStack<int> st;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			st.push(i + 1);
		}
		else if(s[i] == ')'){
			int u = st.top();
			st.pop();
			cout << u << " " << i + 1 << endl;
		}
	}
}