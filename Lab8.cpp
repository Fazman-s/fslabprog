/*Write a program to read k Lists of names and merge them using k-way merge
algorithm with k = 8.  */
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
class record
{
	public:char usn[20],name[20];
};

int no;
fstream file[8];
char fname[8][8]={"1.txt","2.txt","3.txt","4.txt","5.txt","6.txt","7.txt","8.txt"};

void merge_file(const char *file1,const char *file2,const char *file3)
{
	record recrd[20];
	int k=0;
	fstream f1,f2;
	f1.open(file1,ios::in);
	f2.open(file2,ios::in);
	while(!f1.eof())
	{
		f1.getline(recrd[k].name,20,'|');
		f1.getline(recrd[k++].usn,20,'\n');
	}
	while(!f2.eof())
	{
		f2.getline(recrd[k].name,20,'|');
		f2.getline(recrd[k++].usn,20,'\n');
	}
	record temp;
	int x,y;
	for(x=0;x<k-2;x++)
		for(y=0;y<k-x-2;y++)
			if(strcmp(recrd[y].name,recrd[y+1].name)>0)
			{
				temp=recrd[y];
				recrd[y]=recrd[y+1];
				recrd[y+1]=temp;
			}
	fstream temp1;
	temp1.open(file3,ios::out);
	for(x=1;x<k-1;x++)
		temp1<<recrd[x].name<<"|"<<recrd[x].usn<<"\n";
	f1.close();
	f2.close();
	temp1.close();
}



void kwaymerge()
{
	merge_file("1.txt","2.txt","11.txt");
	merge_file("3.txt","4.txt","22.txt");
	merge_file("5.txt","6.txt","33.txt");
	merge_file("7.txt","8.txt","44.txt");
	merge_file("11.txt","22.txt","111.txt");
	merge_file("33.txt","44.txt","222.txt");
	merge_file("111.txt","222.txt","1111.txt");
	return;
}

int main()
{
	int i,no;
	char name[20],usn[20];
	fstream result;
	record rec[20];
	cout<<"Enter the no. of records:";
	cin>>no;
	cout<<"Enter the details:";
	for(i=0;i<8;i++)
		file[i].open(fname[i],ios::out);
	for(i=0;i<no;i++)
	{
		cout<<"NAME:";
		cin>>rec[i].name;
		cout<<"USN:";
		cin>>rec[i].usn;
		file[i%8]<<rec[i].name<<"|"<<rec[i].usn<<"\n";
	}
	for(i=0;i<8;i++)
		file[i].close();
	kwaymerge();
	result.open("1111.txt",ios::in);
	cout<<"Sorted Records:";

	for(i=0;i<no;i++)
	{
	result.getline(name,20,'|');
	result.getline(usn,20,'\n');
	cout<<"\nNAME:"<<name<<"\nUSN:"<<usn<<"\n";
	}
}
