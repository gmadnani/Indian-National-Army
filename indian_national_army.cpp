#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
char Entr;
struct date
{
float d,m,y;
};
class soldier
{
private:
char name[50];
date dateob;
long int telno;
long int mobno;
char add[100];
char currad[100];
char marrstatus[30];
long int salary;
char designation[50];
date last_leave;
int nooffamilymembers;
int soldiercode;
int allowances;
int pobox;
int workexp;
public:
void create();
void search();
void password();
void display();
void insert();
void del();
void modify();
void olddisplay();
int getmembercode()
{
return soldiercode;
}
void input()
{
cout<<"Enter the soldier's name: ";
cin>>name;
cout<<"Enter the soldier's code: ";
cin>>soldiercode;
cout<<"Enter the date of birth(Day): ";
cin>>dateob.d;
cout<<"Enter (Month): ";
cin>>dateob.m;
cout<<"Enter (Year): ";
cin>>dateob.y;
cout<<"Enter the residence number: ";
cin>>telno;
cout<<"Enter the mobile number: ";
cin>>mobno;
cout<<"Enter the residence address: ";
cin>>add;
cout<<"Enter the current working address: ";
cin>>currad;
cout<<"Enter the martial status:(Yes or No) ";
cin>>marrstatus;
cout<<"Enter the salary: ";
cin>>salary;
cout<<"Enter the allowances: ";
cin>>allowances;
cout<<"Enter the designation: ";
cin>>designation;
cout<<"Enter the date of last leave(day): ";
cin>>last_leave.d;
cout<<"Enter (month): ";
cin>>last_leave.m;
cout<<"Enter (year): ";
cin>>last_leave.y;
cout<<"Enter the number of family members: ";
cin>>nooffamilymembers;
cout<<"Enter the post box number: ";
cin>>pobox;
cout<<"Enter the duration of work experience(in years): ";
cin>>workexp;
}
void show()
{
cout<<"\nSoldier's name:"<<name;
cout<<"\nSoldier's code:"<<soldiercode;
cout<<"\nDate of birth:"<<dateob.d<<"/"<<dateob.m<<"/"<<dateob.y;
cout<<"\nResidence number:"<<telno;
cout<<"\nMobile number:"<<mobno;
cout<<"\nResidence address:"<<add;
cout<<"\nCurrent working address:"<<currad;
cout<<"\nMartial status:"<<marrstatus;
cout<<"\nSalary:"<<salary;
cout<<"\nAllowances:"<<allowances;
cout<<"\nDesignation:"<<designation;
cout<<"\nDate of last leave:"<<last_leave.d<<"/"<<last_leave.m<<"/"<<last_leave.y;
cout<<"\nNumber of family members:"<<nooffamilymembers;
cout<<"\nPost box number:"<<pobox;
cout<<"\nDuration of work experience(in years):"<<workexp<<"\n\n";
}
};
soldier s;
void soldier::password()
{
char p1,p2,p3,p4;
cout<<"Enter the password:";
p1=getch();
cout<<"*";
p2=getch();
cout<<"*";
p3=getch();
cout<<"*";
p4=getch();
cout<<"*";
if(p1=='a'&&p2=='d'&&p3=='i'&&p4=='s')
{
return;
}
else
{
cout<<"\nYou have entered the password wrong";
cout<<"\nPROGRAM TERMINATED!!!!!";
exit(0);
}
}
void soldier::create()
{
fstream f;
soldier s;
int i,n;
f.open("soldier.dat",ios::out|ios::binary);
cout<<"Enter the number of soldiers:";
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"\nEnter soldier"<<i<<"\n";
s.input();
f.write((char*)&s,sizeof(s));
}
f.close();
}
void soldier::search()
{
int found=0;
ifstream f;
soldier s;
f.open("soldier.dat",ios::in|ios::binary);
f.seekg(0);
int scode;
cout<<"Enter the soldier code to be searched for:";
cin>>scode;
while(f.read((char*)&s,sizeof(s)))
{
if (scode==s.getmembercode())
{
found=1;
s.show();
}
}
if(found==0)
cout<<"Record not found"<<endl;
f.close();
}
void soldier::display()
{
fstream f;
f.open("soldier.dat",ios::in|ios::binary);
f.read((char*)&s,sizeof(s));
while(!f.eof())
{
s.show();
f.read((char*)&s,sizeof(s));
}
f.close();
}
void soldier::insert()
{
fstream f,t;
int scode;
f.open("soldier.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
cout<<"Enter the code after the record has been inserted:";
cin>>scode;
f.read((char*)&s,sizeof(s));
while(!f.eof())
{
t.write((char*)&s,sizeof(s));
if (scode==s.getmembercode())
{
s.input();
t.write((char*)&s,sizeof(s));
}
f.read((char*)&s,sizeof(s));
}
f.close();
t.close();
remove("soldier.dat");
rename("temp.dat","soldier.dat");
}
void soldier::del()
{
fstream f,t,d;
int scode;
char ch;
f.open("soldier.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
d.open("deleted.dat",ios::out|ios::binary);
cout<<"Are you sure you want to continue?:";
cin>>ch;
if(ch=='Y'|ch=='y')
{
cout<<"Enter the code of the soldier to be deleted:";
cin>>scode;
while(f.read((char*)&s,sizeof(s)))
{
if (scode!=s.getmembercode())
{
t.write((char*)&s,sizeof(s));
}
else
{
d.write((char*)&s,sizeof(s));
}
}
f.close();
t.close();
remove("soldier.dat");
rename("temp.dat","soldier.dat");
}
}
void soldier::olddisplay()
{
fstream d;
soldier s;
d.open("deleted.dat",ios::in|ios::binary);
d.read((char*)&s,sizeof(s));
while(!d.eof())
{
s.show();
d.read((char*)&s,sizeof(s));
}
d.close();
}
void soldier::modify()
{
fstream f,t;
int scode;
f.open("soldier.dat",ios::in|ios::binary);
t.open("temp.dat",ios::out|ios::binary);
cout<<"Enter the record to be modified:";
cin>>scode;
f.read((char*)&s,sizeof(s));
while(!f.eof())
{
if(scode==s.getmembercode())
{
s.input();
}
t.write((char*)&s,sizeof(s));
f.read((char*)&s,sizeof(s));
}
f.close();
t.close();
remove("soldier.dat");
rename("temp.dat","soldier.dat");
}
void main()
{
clrscr();
int ch;
char a;
cout<<"__________________________________________";
cout<<"\nINDIAN NATIONAL ARMY (INA) DATABASE ";
cout<<"\n__________________________________________";
cout<<"\nPress c to continue or e to exit:";
cin>>Entr;
if(Entr=='e'|Entr=='E')
exit(0);
else if(Entr=='c'|Entr=='C')
{
s.password();
cout<<"\nYou have successfully been Granted Access";
}
do{
cout<<"\nPlease enter your choice";
cout<<"\n1.Create";
cout<<"\n2.Search";
cout<<"\n3.Display";
cout<<"\n4.Insert";
cout<<"\n5.Delete";
cout<<"\n6.Modify";
cout<<"\n7.Display deleted records";
cout<<"\nYour choice:";
cin>>ch;
switch(ch)
{
case 1:s.create();
break;
case 2:s.search();
break;
case 3:s.display();
break;
case 4:s.insert();
break;
case 5:s.del();
break;
case 6:s.modify();
break;
case 7:s.olddisplay();
break;
default:cout<<"The option selected is WRONG!";
}
cout<<"\nDo you want to continue";
cin>>a;
}while(a=='y'|a=='Y');
getch();
}
