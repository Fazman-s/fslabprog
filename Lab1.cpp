
/************* FS Program 1 , written by: Prasad B S  *************/

/*Write a program to read series of names, one per line, from standard input and write
these names spelled in reverse order to the standard output using I/O redirection and
pipes. Repeat the exercise using an input file specified by the user instead of the
standard input and using an output file specified by the user instead of the standard
output.*/

#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

//Function to reverse the string
char* strrev(char *str)
{
    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int main()
{
	fstream file1,file2;
	char ifile[10],ofile[10],temp[25];
	int n,i=0;
	
	cout<<"Enter the first filename"<<endl;//Read the name of the input file
	cin>>ofile;
	cout<<"Enter the number of names to be entered"<<endl;//Read number of names to be inserted
	cin>>n;
	cout<<"Enter the names:"<<endl;
	file1.open(ofile,ios::out);
	while(i<n)//Read n names and write to input file
	{
		cin>>temp;
		file1<<temp<<endl;
		i++;
	}
	file1.close();
	file1.open(ofile,ios::in);//reopen input file in read mode
	cout<<"Enter the second filename"<<endl;
	cin>>ifile;
	file2.open(ifile,ios::out);//Open output file in write mode
	i=0;
	while(i<n)//read and reverse the names and write to output file
	{
		file1>>temp;
		file2<<strrev(temp)<<endl;
		cout<<temp<<endl;
		i++;
	}
	cout<<"Names are reversed and written successfully  :) ";

}
