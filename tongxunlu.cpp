#include <iostream>
#include <string>
#include<cctype>
#include <stdlib.h>
#include<string.h>
#include<ctime>
#define MAX 1000
using namespace std;

void showmenu()
{

	cout<<"1. + "<<endl;
	cout<<"2. show "<<endl;
	cout<<"3. - "<<endl;
	cout<<"4. search "<<endl;
	cout<<"5. modify "<<endl;
	cout<<"6. clean "<<endl;
	cout<<"0. exit "<<endl;

}

struct person
{
	string name;
	int age;
	int sex;
	string phone;
	string address;
};

struct addressbook
{
	person personarry[MAX];
	int total;
}; 

void add(addressbook * ads)
{
if(ads->total>=1000)
{
cout<<"max"<<endl;
}
else{
cout<<"name"<<endl;
cin>>ads->personarry[ads->total].name;
cout<<"sex :1. boy  2. girl"<<endl;
cin>>ads->personarry[ads->total].sex;
cout<<"age"<<endl;
cin>>ads->personarry[ads->total].age;
cout<<"phone"<<endl;
cin>>ads->personarry[ads->total].phone;
cout<<"address"<<endl;
cin>>ads->personarry[ads->total].address;
ads->total++;
system("reset");
}
}

void play(const addressbook * ads ){
if(ads->total==0){
cout<<"no recording"<<endl;}
int i=0;
for(i=0;i<ads->total;i++)
{
cout<<"name: "<<ads->personarry[i].name<<"\t";
cout<<"sex: "<<(ads->personarry[i].sex==1?"boy":"girl")<<"\t";
cout<<"age: "<<ads->personarry[i].age<<"\t\t";
cout<<"phone: "<<ads->personarry[i].phone<<"\t\t";
cout<<"address: "<<ads->personarry[i].address<<endl;
}
}


int isexist(addressbook * ads,string name1)
{
for(int i=0;i<ads->total;i++)
{
if(ads->personarry[i].name==name1)
return i;
}
return -1;
}


void delete2(addressbook *ads){
cout<<"who need to be deleted?"<<endl;
string name1;
cin>>name1;
int tmp=isexist(ads,name1);
if(tmp==-1) 
	cout<<"no recording"<<endl;
else
	for(int i=tmp;i<ads->total;i++)
		{ 
		ads->personarry[i]=ads->personarry[i+1];
}
ads->total--;
}


void find(addressbook ads){
string name1;
cout<<"who need to be finded"<<endl;
cin>>name1;
int tmp=isexist(&ads,name1);
if(tmp==-1) 
	cout<<"no recording"<<endl;
else
	cout<<"name:"<<ads.personarry[tmp].name<<"\t"<<"age:"<<ads.personarry[tmp].age<<"\t"
	<<"sex:"<<(ads.personarry[tmp].sex==1?"boy":"girl")<<"\t"
	<<"phone"<<ads.personarry[tmp].phone<<"\t"<<"address:"<<ads.personarry[tmp].address<<endl;
}


void modify(addressbook * ads){
cout<<"who need to be modified?"<<endl;
string name1;
cin>>name1;
int tmp=isexist(ads,name1);
if(tmp==-1)
	cout<<"no raecoding "<<endl;
else{
cout<<"name?"<<endl;
cin>>ads->personarry[tmp].name;
cout<<"age?"<<endl;
cin>>ads->personarry[tmp].age;
cout<<"sex?"<<endl;
cin>>ads->personarry[tmp].sex;
cout<<"phone?"<<endl;
cin>>ads->personarry[tmp].phone;
cout<<"address?"<<endl;
cin>>ads->personarry[tmp].address;
}
}


void clean(addressbook *ads){
ads->total =0;
cout<<"addressbook has been emptied"<<endl;
}



int main()
{
addressbook ads;
ads.total=0;
int select =0;
string name1;
while(true)
{
  showmenu();
  cin>>select;
  switch(select)
  {
	case 1:
		add(&ads);
		break;
	case 2:
		play(&ads);
		break;

	case 3:
		delete2(&ads);		
		break;

	case 4:	
		find(ads);
		break;
	case 5:
		modify(&ads);
		break;
	case 6:
		clean(&ads);
		break;
	case 0:
		cout<<"bye!"<<endl;
		return 0;
		break;
	default :
		break;

  }
}





























return 0;
}
