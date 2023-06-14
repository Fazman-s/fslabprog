/************* FS Program 5 , written by: Prasad B S  *************/

/*Write a program to implement simple index on primary key for a file of student
objects. Implement add ( ), search ( ), delete ( ) using the index. */
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
char buffer[50],buffer1[50];
char tempusn[15],temprrn[10],keyusn[15];
int count=0,i;
fstream fp1,fp2;
void pack(student p)
{
	fp1.open("std.txt",ios::out|ios::app);
	fp2.open("ind.txt",ios::out|ios::app);
	strcpy(buffer,p.name);
	strcat(buffer,"|");
	strcat(buffer,p.usn);
	strcat(buffer,"|");
	strcat(buffer,p.age);
	strcat(buffer,"|");
	strcat(buffer,p.sem);
	strcat(buffer,"|");
	strcat(buffer,p.branch);
	int x=strlen(buffer);
	for(int j=0;j<45-x;j++)
	strcat(buffer,"!");
	fp1<<count<<"|"<<buffer<<endl;
	fp2<<p.usn<<"|"<<count<<"|"<<endl;
	fp1.close();
	fp2.close();
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
	student x;
	fp1.open("std.txt",ios::in);
	fp2.open("ind.txt",ios::in);
	cout<<" Enter the USN to search for:";
	cin>>keyusn;
	for(i=0;i<count;i++)
	{

			fp2.getline(buffer,100);
			sscanf(buffer,"%[^|]|%[^|]|",tempusn,temprrn);
			if(strcmp(tempusn,keyusn)==0)
			{
				cout<<" Record found"<<endl;
				int rrn=atoi(temprrn);
				cout<<" RRN value of record:"<<rrn<<endl;
				fp1.seekg((rrn-1)*49,ios::beg);
				fp1.getline(buffer1,100);
				//cout<<"buffer content"<<buffer1<<endl;
				sscanf(buffer1,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^!]!",temprrn,x.name,x.usn,x.age,x.sem,x.branch);
				cout<<"\nUSN:"<<x.usn<<"\nNAME:"<<x.name<<"\nAGE:"<<x.age<<"\nSEM:"<<x.sem<<"\nBRANCH:"<<x.branch<<endl;
		       		break;
			}
}
	if(i==count)
	cout<<"record not found";
	fp1.close();
	fp2.close();
}


void delet()
{
	int j;
	char temp[5];
	if(i==count)
	return;
	fp1.open("std.txt",ios::in);
	for( j=0;j<count;j++)
	{
		fp1.getline(buffer,100);
		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^!]!",temp,s[j].name,s[j].usn,s[j].age,s[j].sem,s[j].branch);
	}
	fp1.close();
	//fp2.close();
		cout<<" deleting record no:"<<i+1<<endl;

	remove("std.txt");
	remove("ind.txt");
	fp1.open("std.txt",ios::out);
	fp2.open("ind.txt",ios::out);
	fp1.close();
	fp2.close();
	int cntold=count;
	count=0;
	for(j=0;j<cntold;j++)
	if(j!=i)
	{
	count++;
	pack(s[j]);
	}

}
int main()
{
	int c;

	fp1.open("std.txt",ios::out);
	fp2.open("ind.txt",ios::out);
	fp1.close();
	fp2.close();
	while(1)
	{
		cout<<"\n1.Write\n 2.Search\n 3.Delete\n 4.Exit\n Enter your choice\n";
		cin>>c;
		switch(c)
		{
			case 1:count++;write();break;
			case 2:search();break;
			case 3:search();delet();break;
			default:exit(0);
		}
	}
}

