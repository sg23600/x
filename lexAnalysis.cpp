// input.txt, int a = b + 12 + 1c ;

#include <bits/stdc++.h> 
using namespace std; 
string keywords[] = {"void", "using", "namespace", "int", "include", "iostream", "cin", "cout", "return", "float", "double", "string"}; 

bool isKeyword(string str){ 
	for(string c: keywords) 
		if(c.compare(str)==0) return true;
	return false; 
}

bool isOperator(string str){ 
	// + - * / & | && || = == += -= *= /=
	if (str == "+" || str == "-" || str == "" || str == "/" || str == "^" || str == "&&" || str == "||" || str == "=" || str == "==" || str == "&" || str == "|" || str == "%" || str == "++" || str == "--" || str == "+=" || str == "-=" || str == "/=" || str == "=" || str == "%=") 
		return true;
	return false; 
}

bool isPunctuator(string str){
	// ( ) { } [ ] < > ; , # << >> ()
	if (str == "(" || str == "{" || str == "[" || str == ")" || str == "}" || str == "]" || str == "<" || str == ">" || str == "()" || str == ";" || str == "<<" || str == ">>" || str == "," || str == "#") 
		return true; 
	return false; 
} 

int main(){ 
	fstream file;
	string s, filename; 
	filename = "./input.txt";
	file.open(filename.c_str());
	int k=0, i=0, l=0, p=0, op=0, c=0; 
	while(file>>s){
		if(s=="#include<iostream>") 
			cout<<s<<" is a header"<<endl; 
		else if(isOperator(s)){ 
			cout<<s<<" is an operator"<<endl; 
			op++;
		}
		else if(isKeyword(s)){ 
			cout<<s<<" is a keyword\n";
			k++; 
		}
		else if(isPunctuator(s)){ 
			cout<<s<<" is a punctuator"<<endl; 
			p++;
		} 
		else if(isdigit(s[0])){ // To check for constant 
			int x=0; 
			if(!isdigit(s[x++])) continue;
			else {
				cout<<s<<" is a constant"<<endl; 
				c++;
			}
		}
		else{ 
				cout<<s<<" is an identifier"<<endl; 
				i++; 
			}
	} 
	cout<<"\n"<<k<<" keywords\n"<<c<<" constants\n"<<i<<" identifiers\n"<<p<<" punctuators\n"<<op<<" operators\n"; 
}

