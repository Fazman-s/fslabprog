/************* FS Program 7 , written by: Prasad B S  *************/

/*Write a program to read two lists of names and then match the names in the two lists
using Consequential Match based on a single loop. Output the names common to both the lists. */
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;


fstream out1,out2,out3;

void writelists()
{
	
	int i,m,n;
	char name[20];
	out1.open("file1.txt",ios::out);
	out2.open("file2.txt",ios::out);
	if((!out1)||(!out2))
	{
		cout<<"Unable to open one of the list files";
		exit(0);
	}
	cout<<"Enter the number of names you want to enter in file1:";
	cin>>m;
	cout<<"Enter the names in ascending order\n";
	for(i=0;i<m;i++)
	{
		cin>>name;
		out1<<name;
		out1<<"\n";
	}
	cout<<"Enter the number of names you want to enter in file2 :";
	cin>>n;
	cout<<"Enter the names in ascending order :\n";
	for(i=0;i<n;i++)
	{
		cin>>name;
		out2<<name;
		out2<<"\n";
	}
	out1.close();
	out2.close();
}


void match()
{
	char list1[100][20],list2[100][20];
	int i,j,m,n,k=0;
	out1.open("file1.txt",ios::in);
	out2.open("file2.txt",ios::in);
	out3.open("file3.txt",ios::out);
	if((!out1)||(!out2)||(!out3))
	{
		cout<<"Unable to open one of the file";
		exit(0);
	}
	m=n=0;
	cout<<"LIST1 \n";
	while(!out1.eof())
	{
		out1.getline(list1[m],20,'\n');
		cout<<list1[m]<<"\n";
		m++;
	}
	cout<<"LIST2 \n";
	while(!out2.eof())
	{
		out2.getline(list2[n],20,'\n');
		cout<<list2[n]<<"\n";
		n++;
	}
	i=j=0;
	cout<<"\n Elements common to both files are :"<<endl;
	while(i<m-1&&j<n-1)
	{
		if(strcmp(list1[i],list2[j])==0) //if match is found
		{
			out3<<list1[i]<<"\n";
			cout<<list1[i]<<"\n";
			i++;
			j++;
			k++;
		}
		else if(strcmp(list1[i],list2[j])<0)// if first list element is smaller
			i++;
		else
			j++;
		
	}
	if(!k)
	{
		cout<<"No common names";
	}
}


int main()
{
	
	writelists();
	match();
	
}

