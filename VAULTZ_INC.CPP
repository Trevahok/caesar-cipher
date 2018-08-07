#include<iostream.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<math.h>

//Data members
char org[300];
char opt='0';
int opt1=0;
int key[300];
time_t t=time(0);
long int k=t;
int arsz=0;  //Array size
int cnt=0;

//Prototypes
void encrypt();
void decrypt();
void keygen(long int t);


void main()
{
clrscr();
//Intro
for( cnt=0;cnt<80;cnt++)cout<<"_-";
cout<<"\n\t\t\t\tWelcome to Vaultz Inc.\n";
for( cnt=0;cnt<80;cnt++)cout<<"_-";

//Menu

cout<<"\n\t We are here for all your data security solutions!\n\n\t";
menu:
cout<<" How may we serve you today?:\n\t\t1.Encrypt your data?\n\t\t2.Decrypt your data?\n\t\t3.Exit?";
cin>>opt1;

switch(opt1)
{case 1:encrypt();clrscr();for( cnt=0;cnt<80;cnt++)cout<<"_-";cout<<"\n\t\t\t\tWelcome to Vaultz Inc.\n";for( cnt=0;cnt<80;cnt++)cout<<"_-";goto menu;
 case 2:decrypt();clrscr();for( cnt=0;cnt<80;cnt++)cout<<"_-";cout<<"\n\t\t\t\tWelcome to Vaultz Inc.\n";for( cnt=0;cnt<80;cnt++)cout<<"_-";goto menu;
 case 3:
  {
  cout<<"Are you sure you want to exit?";
  cin>>opt;
  if(opt=='y'||opt=='Y')
  {clrscr();
  for( cnt=0;cnt<80;cnt++)cout<<"_-";
  cout<<"\n\n\t\t\tThank you!Visit again!\n";
  for( cnt=0;cnt<80;cnt++)cout<<"_-";
  cout<<"\n\n\n\t\tIf you have any suggestions or feedback,\n\t\tFeel free to contact \n\n\t\t\t   Mr.Vignesh S.  XII 'A' Alwin School\n\t\tThe CEO and lead programmer of Vaultz Inc.\n\n\n\n\n\n\n\t\t\t\t\t\tWe dont have any other branches!";
  }
  else {clrscr();for( cnt=0;cnt<80;cnt++)cout<<"_-";cout<<"\n\t\t\t\tWelcome to Vaultz Inc.\n";for( cnt=0;cnt<80;cnt++)cout<<"_-";goto menu;}
 } break;
 default: {cout<<"\nPlease choose any of the above options using their respective Code Nos.";getch();cin.ignore(1);goto menu;}
}
getch();
}


void encrypt()
{ 
    clrscr(); 
    for( cnt=0;cnt<80;cnt++)cout<<"_-";
    cout<<"\n\t\t\t\t Vaultz Inc.\n";
    for( cnt=0;cnt<80;cnt++)cout<<"_-";
    t=time(0);
//Data entry
cout<<"\n\t So you want to encrypt data?\n\n Please enter you original data: ";
renter:
cin.ignore(1,'n');
cin.getline(org,300);

cout<<"\nIs this correct?(y/n): "<<org<<" : ";
cin>>opt;
if(opt=='n'||opt=='N'){cout<<"\nPlease re-enter data: ";goto renter;}

arsz=strlen(org);
cout<<"\n\tSafeguard this key for future decryption: "<<t ;     //Key collection
keygen(k);

for(cnt=0;cnt<arsz;cnt++)
org[cnt]-=key[cnt];                  //Ahem...ahem... Trade secrets!

cout<<"\n\nPlease collect your encrypted data: "<<org;
getch();
}

void keygen(long int t)          //Generates key...   (Shhh.. this is where the magic happens! dont u dare tell anyone abt wat u saw here )
{
for(int cnt=1;cnt<7;cnt++)
{long int temp=pow(10,cnt);key[cnt]=(t%temp)/pow(10,cnt-1);}
for(cnt=0;cnt<arsz;cnt++)
{key[cnt+8]=key[cnt];}
}

void decrypt()
{
clrscr();
for( cnt=0;cnt<80;cnt++)cout<<"_-";cout<<"\n\t\t\t\t Vaultz Inc.\n";for( cnt=0;cnt<80;cnt++)cout<<"_-";
//Data entry
cout<<"\n\n\t So you want to decrypt data?\n\n\t\t Please enter you encrypted data:";
renter:
cin.ignore(1,'n');
cin.getline(org,300,'\n');
cout<<"Is this correct?(y/n)"<<org<<" :";
arsz=strlen(org);
cin>>opt;
if(opt=='n'||opt=='N'){cout<<"Please re-enter data:";goto renter;}

cout<<"\n\tPlease enter your Key: ";     //Key
cin>>k;
keygen(k);

for(cnt=0;cnt<arsz;cnt++)
org[cnt]+=key[cnt];

cout<<"Please collect your Decrypted data: "<<org;
getch();
}
