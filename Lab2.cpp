

/*Write a program to read and write student objects with fixed-length records and the
fields delimited by “|”. Implement pack ( ), unpack ( ), modify ( ) and search ( )
methods.*/
#include<iostream>
#include<stdlib.h>
//#include<process.h>
#include<string.h>
#include<fstream>
using namespace std;
class student
{
	public:char name[20],usn[10],age[5],sem[5],branch[5];
};
student s[100],t;
char buffer[45],temp[20];
int count=0,i;
fstream fp1;
void pack(student p)
{
	fp1.open("hello1.txt",ios::out|ios::app);
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
	int x=strlen(buffer);
	for(int j=0;j<45-x;j++)
	strcat(buffer,"!");
	cout<<buffer;
	fp1<<buffer<<endl;
	fp1.close();

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
void unpack()
{
	fp1.open("hello1.txt",ios::in);
	for(i=0;i<count;i++)
	{
		fp1.getline(buffer,100);
		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",s[i].name,s[i].usn,s[i].age,s[i].sem,s[i].branch);
	}
	fp1.close();
}
void display()
{
	if(count==0)
	{
		cout<<"\nNo records\n";
		return;
	}
	cout<<"\n name\t usn\t age\t sem\t branch\n";
	for(i=0;i<count;i++)
	cout<<s[i].name<<"\t"<<s[i].usn<<"\t"<<s[i].age<<"\t"<<s[i].sem<<"\t"<<s[i].branch<<endl;
}
void search()
{
	cout<<"Enter the usn\n";
	cin>>temp;
	for(i=0;i<count;i++)
	if(!strcmp(s[i].usn,temp))
	{
		cout<<"Record found\n"<<s[i].name<<"\t"<<s[i].usn<<"\t"<<s[i].age<<"\t"<<s[i].sem<<"\t"<<s[i].branch<<endl;
		break;
	}
	if(i==count)
	cout<<"Record not found";
}
void modify()
{
	if(i==count)
	return;
	cout<<"Enter new values\n Enter name :";
	cin>>s[i].name;
	cout<<"Enter usn :";
	cin>>s[i].usn;
	cout<<"Enter age :";
	cin>>s[i].age;
	cout<<"Enter sem :";
	cin>>s[i].sem;
	cout<<"Enter branch :";
	cin>>s[i].branch;
	fp1.close();
	remove("hello1.txt");
	fp1.open("hello1.txt",ios::out);
	fp1.close();
	for(int j=0;j<count;j++)
	pack(s[j]);
}
int main()
{
	int c;
	//clrscr();
	fp1.open("hello1.txt",ios::out);
	fp1.close();
	while(1)
	{
		cout<<"\n1.Write\n 2.Display\n 3.Search\n 4.Modify\n 5.Exit\n Enter your choice\n";
		cin>>c;
		switch(c)
		{
			case 1:count++;write();break;
			case 2:unpack();display();break;
			case 3:unpack();search();break;
			case 4:unpack();search();modify();break;
			default:exit(0);
		}
	}
}

