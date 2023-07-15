
/*Write a program to read series of names, one per line, from standard input and write
these names spelled in reverse order to the standard output using I/O redirection and
pipes. Repeat the exercise using an input file specified by the user instead of the
standard input and using an output file specified by the user instead of the standard
output.*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

char *strrev(char *name){
    int i=0,temp;
    int l=strlen(name);
    while(i<l){
        temp=name[i];
        name[i]=name[l-1];
        name[l-1]=temp;
        i++;
        l--;
    }
    return name;
}

int main(){
    fstream file1,file2;
    int i=0,n;
    char ofile[10],ifile[10],temp[25];
    cout<<"Enter the first file name :"<<endl;//Read the name of the input file
    cin>>ofile;
    cout<<"Enter the number of names to be entered : "<<endl;
    cin>>n;
    cout<<"Enter the names :"<<endl;
    file1.open(ofile,ios :: out);
    while(i<n){
        cin>>temp;
        file1<<temp<<endl;
        i++;

    }
    file1.close();
    file1.open(ofile,ios::in);//reopen input file in read mode
    cout<<"Enter the second file name :"<<endl;
    cin>>ifile;
    file2.open(ifile,ios::out);//Open output file in write mode
    i=0;
    while(i<n){
        file1>>temp;
        file2<<strrev(temp)<<endl;
        cout<<temp<<endl;
        i++;
    }
    cout<<"Names are reversed and written successfully";

}
