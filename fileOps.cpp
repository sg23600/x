#include<bits/stdc++.h>
using namespace std;

void createFile(string fileName){
	fstream file;
	file.open(fileName, ios::out);
	if(!file){
	   cout<<"Error in creating file!!\n";
	   return;
   }
   cout<<"File created successfully!!\n";
   file.close();
   cout<<"\n";
}

void readFile(string fileName){
	ifstream file;
	file.open(fileName);
	char ch;
	if(!file){
      cout<<"Error: File could not be opened!!\n";
      return;
   	}
	cout<<"Contents of file are as follows: "<<"\n";
	file>>ch;
	while(!file.eof()){
		cout<<ch;
		file>>ch;
	}
	file.close();
	cout<<"\n\n";
}

void writeToFile(string fileName, string contents){
	ofstream file;
	file.open(fileName);
	file<<contents;
	file.close();
}

void deleteFile(char str[]){
	int status=remove(str);
    if(status==0)
        cout<<"File Deleted Successfully!!\n";
    else
        cout<<"Error Occurred! File could not be deleted!!\n";
}

int main(){
	createFile("test1.txt");
	writeToFile("test1.txt", "Sandipan Das");
	readFile("test1.txt");
	deleteFile("test1.txt");
}
