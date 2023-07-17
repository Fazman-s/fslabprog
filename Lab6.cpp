/*Write a program to implement index on secondary key, the name, for a file of
student objects. Implement add ( ), search ( ), delete ( ) using the secondary index. */
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
char buffer[50],buffer1[50],buffer2[50];
char tempname[15],temprrn[10],keyname[15],tempusn[10],tempusn1[10];
int count=0,i,j;
fstream fp1,fp2,fp3;

void pack(student p)
{
	fp1.open("std.txt",ios::out|ios::app);
	fp2.open("ind.txt",ios::out|ios::app);
	fp3.open("sec.txt",ios::out|ios::app);

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
	fp3<<p.name<<"|"<<p.usn<<"|"<<endl;

	fp1.close();
	fp2.close();
	fp3.close();
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
{  int fg=0,flag1;
	student x;
	fp1.open("std.txt",ios::in);
	fp2.open("ind.txt",ios::in);
	fp3.open("sec.txt",ios::in);
	cout<<" Enter the Name to search for:";
	cin>>keyname;
	for(i=0;i<count;i++)
	{

		fp3.getline(buffer,100);
		sscanf(buffer,"%[^|]|%[^|]|",tempname,tempusn);
		if(strcmp(tempname,keyname)==0)
		{
			fg=1;
			for(j=0;j<count;j++)
			{
				flag1=0;
				fp2.getline(buffer2,100);
				sscanf(buffer2,"%[^|]|%[^|]|",tempusn1,temprrn);
				if(strcmp(tempusn1,tempusn)==0)
				{
					flag1=1;
					cout<<" Record found"<<endl;
					int rrn=atoi(temprrn);
					cout<<" RRN value of record:"<<rrn;
					fp1.seekg((rrn-1)*49,ios::beg);
					fp1.getline(buffer1,100);
					sscanf(buffer1,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^!]!",temprrn,x.name,x.usn,x.age,x.sem,x.branch);
					cout<<"\nUSN:"<<x.usn<<"\nNAME:"<<x.name<<"\nage:"<<x.age<<"\nsem:"<<x.sem<<"\nbranch:"<<x.branch;
					break;
				}
			}
				
		}
		if (flag1==1)
			break;
	}
	if(fg==0||flag1==0)
	cout<<"record not found";
	fp1.close();
	fp2.close();
	fp3.close();
}


void delet()
{
	int j;
	char temp[10];
	if(i==count)
	return;
	fp1.open("std.txt",ios::in);
	for( j=0;j<count;j++)
	{
		fp1.getline(buffer,100);
		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^!]!",temp,s[j].name,s[j].usn,s[j].age,s[j].sem,s[j].branch);
	}
	fp1.close();
	remove("std.txt");
	remove("ind.txt");
	remove("sec.txt");
	fp1.open("std.txt",ios::out);
	fp2.open("ind.txt",ios::out);
	fp3.open("sec.txt",ios::out);
	fp1.close();
	fp2.close();
	fp3.close();
	int cntold=count;
	count=0;
	for(j=0;j<cntold;j++)
	if(j!=i)
	{
		count++;
		pack(s[j]);
	}
	cout<<" record deleted";
}

int main()
{
	int c;
	fp1.open("std.txt",ios::out);
	fp2.open("ind.txt",ios::out);
	fp3.open("sec.txt",ios::out);

	fp1.close();
	fp2.close();
	fp3.close();
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

