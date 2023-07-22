/*Write a program to write student objects with Variable - Length records using any
suitable record structure and to read from this file a student record using RRN. */
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
class student
{
	public:char name[20],usn[10],age[5],sem[5],branch[5];
};

student s[100],t;
char buffer[45],temp1[20],temp2[20];
int count=0,i;
fstream fp;
void pack(student p)
{
	fp.open("hello.txt",ios::out|ios::app);
	strcpy(buffer,p.name);
	strcat(buffer,"|");
	strcat(buffer,p.usn);
	strcat(buffer,"|");
	strcat(buffer,p.age);
	strcat(buffer,"|");
	strcat(buffer,p.sem);
	strcat(buffer,"|");
	strcat(buffer,p.branch);
	strcat(buffer,"|");
	fp<<count<<"|"<<buffer<<endl;
	fp.close();

}

void write()
{
	cout<<"Enter the name\n";
	cin>>t.name;
	cout<<"Enter the usn\n";
	cin>>t.usn;
	cout<<"Enter the age\n";
	cin>>t.age;
	cout<<"Enter the sem\n";
	cin>>t.sem;
	cout<<"Enter the branch\n";
	cin>>t.branch;
	pack(t);
}

void search()
{
	cout<<"Enter the rrn\n";
	cin>>temp1;
	fp.open("hello.txt",ios::in);
	for(i=0;i<count;i++)
	{
		fp.getline(buffer,100);
		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",temp2,s[i].name,s[i].usn,s[i].age,s[i].sem,s[i].branch);
		if(strcmp(temp1,temp2)==0)
		{
			cout<<"Record found\n"<<s[i].name<<"\t"<<s[i].usn<<"\t"<<s[i].age<<"\t"<<s[i].sem<<"\t"<<s[i].branch<<endl;
			break;
		}
	}
	if(i==count)
	cout<<"Record not found";
	fp.close();
}
int  main()
{
	int c;

	fp.open("hello.txt",ios::out);
	fp.close();
	while(1)
	{
		cout<<"\n1.Write\n 2.Search\n 3.Exit\n Enter your choice\n";
		cin>>c;
		switch(c)
		{
			case 1:count++;write();break;
			case 2:search();break;
			default:exit(0);
		}
	}
}

