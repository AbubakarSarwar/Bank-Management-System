#include "project.h"
//#include "customer.h"
//#include "transaction.h"
//#include "atm.h"
//#include "loan.h"
//#include "transferance.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<conio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include<windows.h>
#include<string.h>
using namespace std;

void setcolor(unsigned short color)
{	
HANDLE hcon=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}



int main()
{
int pas;
int opt;
int num;
int a;
	setcolor(15);cout<<"\t***********************************************************************\n";
	setcolor(9);cout<<"\t-+/::+/-///////////////////////:.     `.://///////////////////////////`\n"; 
   cout<<"\t:ss+/ss:ooooooooooooooooooooosssso- `/osssssssssssssssssssssssssssssss`\n"; 
   cout<<"\t:ss+/ss:++++++++++++++++++++++//sss-+sso////++++++++++++++++++++++++++`\n"; 
   cout<<"\t:ss+/ss:sssssssssssssssssssssss+/ss+sss:+sssssssssssssssssssssssssssss`\n"; 
   cout<<"\t:ss+/ss:````````````````````.oso/ssosss:+sss-`````````-++//++:````````\n";  
   cout<<"\t:ss+/ss:           /ooo:/ooo:oso/ss+:sso:/sss:        -sso+ss:\n";          
   cout<<"\t:ss+/ss:+oooo+   `+sso/osso:.oso/ss+ :sss/:sss/`      -sso+ss:\n";          
   cout<<"\t:ss+/ss:+oooo+  .oss+/osso. .oso/ss+  .oss+-+sso.     -sso+ss:\n";          
   cout<<"\t:ss+/ss:ooooo+`/sss/+sss/`  .oso/ss+   `/sso:/sss:    -sso+ss:\n";          
   cout<<"\t:ss+/ss:+++++++sso:osss:    .oso/ss+     :sss/-oss:   -sso+ss:\n";          
   cout<<"\t:ss+/ss:    .oss+:osso.     .oso/ss+      .osso-+ss/  -sso+ss:\n";          
   cout<<"\t:ss+/ss:    /sso:sss+`      .oso/ss+       `+sss-oss: -sso+ss:\n";          
   cout<<"\t:ss+/ss:    /sso:ssssoooooooosss:ossoooooooossss-oss: -sso+ss:\n";          
   cout<<"\t:ss+/ss:    -sss+/+ooooooooo+/sso/+ooooooooooo+/osso` -sso+ss:\n";          
   cout<<"\t:ss+/ss:     .+ssssssssssssso.:ossssssssssssssssss+`  -sso+ss:\n";          
   cout<<"\t.//:-//.       .:////////////`  .:://///////////-`    .///://-\n\n";  

setcolor(15);cout<<"\t***********************************************************************";

setcolor(15);cout<<"\n\tPROJECT BY THE 'FIA'\n\n\tFahad Tanveer\n\n\tAbubakar Sarwar\n\n\tIlsa Zehra Zaidi\n\n \n";
setcolor(9);cout<<"\t---------------------------------------------------------";
setcolor(15);cout<<"\n\tFAST ISLAMIC BANK LIMITED\n";
setcolor(9);cout<<"\t---------------------------------------------------------\n\n";            
setcolor(9);cout<<"\t*********************************************************";
setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 1 ";setcolor(95);cout<<" To Login                                      "<<endl;
setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 2 ";setcolor(95);cout<<" To Create A New Account                       "<<endl;
setcolor(9);cout<<"\n\t*********************************************************\n";
setcolor(15);cout<<"\nInput Option number: ";
//Exceptional handling
try{
cin>>a;
bool count=false;
if(a>2 || a<1)
{
	throw 1;
}
if(isalpha(a)){
	throw 1;
}
if(a==1)
{                
setcolor(15);cout<<"\nEnter your pasword"<<endl;

cin>>pas;
	system("cls");
bool found=false;
account ac;

	fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);



while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(account));
                if(ac.get_accountnum()==pas)
                {
                                            count=true;
                                            found=true;
                                            
                }
                
}
}
else if(a==2)
{            
    count==true;
     customer c;
     c.setdetails();
     c.nth_customer();

}      
}
catch(int i){
	cout<<"You have entered a wrong option number\n (Try again)";
	cout<<"\nInput Option number: ";
	cin>>a;
}

       for(;;)
        {
        system("cls");	                                               
             cout<<"-------------------------------------------------------------------------------\n";                                                                                                                                      
   
		setcolor(9);cout<<" @@@@@@  ";setcolor(15);cout<<"`@@@` ";setcolor(9);cout<<"  @@@@@@ ";setcolor(15);cout<<" `@@@@@@@#  ";setcolor(9);cout<<"   #@@@@@@+   ";setcolor(15);cout<<"@@@#   ";setcolor(9);cout<<".@@#  :@@ ";setcolor(15);cout<<"@@#  @@@.\n";      
        setcolor(9);cout<<" @@@@@@  ";setcolor(15);cout<<"#@@@#  ";setcolor(9);cout<<" @@@@@@@.";setcolor(15);cout<<"`@@@@@@@@    ";setcolor(9);cout<<" #@@@@@@@  ";setcolor(15);cout<<"`@@@@   ";setcolor(9);cout<<"`@@@. :@@ ";setcolor(15);cout<<"@@# @@@,\n";      
        setcolor(9);cout<<" @@      ";setcolor(15);cout<<"@@`@@   ";setcolor(9);cout<<"@@#        ";setcolor(15);cout<<";@@       ";setcolor(9);cout<<" #@@  '@@  ";setcolor(15);cout<<"#@+@@, ";setcolor(9);cout<<" `@@@@ :@@ ";setcolor(15);cout<<"@@#@@@:\n";     
        setcolor(9);cout<<" @@@@@: ";setcolor(15);cout<<".@@ @@,  ";setcolor(9);cout<<".@@@@@     ";setcolor(15);cout<<";@@      ";setcolor(9);cout<<"  #@@@@@@   ";setcolor(15);cout<<"@@`#@#  ";setcolor(9);cout<<"`@@@@#:@@ ";setcolor(15);cout<<"@@@@@@\n";     
        setcolor(9);cout<<" @@@@@: ";setcolor(15);cout<<"@@# #@@    ";setcolor(9);cout<<"@@@@@:   ";setcolor(15);cout<<";@@      ";setcolor(9);cout<<"  #@@@@@@@ ";setcolor(15);cout<<":@@ .@@  ";setcolor(9);cout<<"`@@`@@;@@ ";setcolor(15);cout<<"@@@@@@#\n";     
        setcolor(9);cout<<" @@    ";setcolor(15);cout<<"`@@@@@@@ ";setcolor(9);cout<<" @@,  @@@   ";setcolor(15);cout<<";@@       ";setcolor(9);cout<<" #@@  `@@,";setcolor(15);cout<<"@@@@@@@: ";setcolor(9);cout<<"`@@ '@@@@ ";setcolor(15);cout<<"@@@'#@@.\n";     
        setcolor(9);cout<<" @@    ";setcolor(15);cout<<";@@@@@@@' ";setcolor(9);cout<<"@@@  @@@   ";setcolor(15);cout<<";@@      ";setcolor(9);cout<<"  #@@  #@@,";setcolor(15);cout<<"@@@@@@@@ ";setcolor(9);cout<<"`@@  @@@@ ";setcolor(15);cout<<"@@#  @@@\n";     
        setcolor(9);cout<<" @@    ";setcolor(15);cout<<"@@@   @@@ ";setcolor(9);cout<<".@@@@@@    ";setcolor(15);cout<<";@@     ";setcolor(9);cout<<"   @@@@@@@@";setcolor(15);cout<<";@@   '@@ ";setcolor(9);cout<<".@@   @@@ ";setcolor(15);cout<<"@@#  #@@+\n";      
        setcolor(9);cout<<" @@    ";setcolor(15);cout<<"@@:   ;@@   ";setcolor(9);cout<<"@@@:     ";setcolor(15);cout<<";@@      ";setcolor(9);cout<<"  #@@@@@: ";setcolor(15);cout<<"@@@    @@+";setcolor(9);cout<<"`@@   '@@ ";setcolor(15);cout<<"@@#   @@@\n";        
        cout<<"-------------------------------------------------------------------------------\n";                                                                                                                                      
   cout<<"\t\t\t\t";setcolor(10);cout<<"*\t*";
  cout<<"\t\t\t\t";setcolor(10);cout<<"**\t**";
   cout<<"\t\t\t\t";setcolor(9);cout<<"***\t***";
   cout<<"\t\t\t\t";setcolor(9);cout<<"****\t****";
   cout<<"\t\t\t\t";setcolor(11);cout<<"*****\t*****";
    cout<<"\t\t\t\t";setcolor(11);cout<<"******\t******";
   cout<<"\t\t\t\t";setcolor(12);cout<<"*******\t*******";
   cout<<"\t\t\t\t";setcolor(12);cout<<"*******\t*******";
   cout<<"\t\t\t\t";setcolor(13);cout<<"******\t******";
   cout<<"\t\t\t\t";setcolor(13);cout<<"*****\t*****";
   cout<<"\t\t\t\t";setcolor(14);cout<<"****\t****";
   cout<<"\t\t\t\t";setcolor(14);cout<<"***\t***";
   cout<<"\t\t\t\t";setcolor(15);cout<<"**\t**";
   cout<<"\t\t\t\t";setcolor(15);cout<<"*\t*";
   setcolor(15);cout<<"\t***************************************************************";
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 1 ";setcolor(224);cout<<" to Deposit Funds                                      "<<endl;
   setcolor(15);cout<<"\t***************************************************************";
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 2 ";setcolor(48);cout<<" to Withdraw Funds                                     "<<endl;
   setcolor(15);cout<<"\t***************************************************************";             
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 3 ";setcolor(208);cout<<" to Check Balance                                      "<<endl;
   setcolor(15);cout<<"\t***************************************************************";               
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 4 ";setcolor(192);cout<<" to View All Account Holder  	                       "<<endl;
   setcolor(15);cout<<"\t***************************************************************";
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 5 ";setcolor(176);cout<<" to Close an Account             		       "<<endl;
   setcolor(15);cout<<"\t***************************************************************";
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 6 ";setcolor(160);cout<<" to Modify an Account             		       "<<endl;
   setcolor(15);cout<<"\t***************************************************************";
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 7 ";setcolor(112);cout<<" to transfer the money from one account to another     "<<endl;
   setcolor(15);cout<<"\t***************************************************************";
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 8 ";setcolor(32);cout<<" to Access ATM 	                        	       "<<endl;
   setcolor(15);cout<<"\t***************************************************************";
    setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 9 ";setcolor(64);cout<<" to Get Loan	                    	               "<<endl;
   setcolor(15);cout<<"\t***************************************************************";
   setcolor(15);cout<<"\n\t";setcolor(240);cout<<"Press 10 ";setcolor(80);cout<<" to Exit the Program		            	       "<<endl;
   setcolor(15);cout<<"\t***************************************************************\n";
   cout<<"\t\t\t\t";setcolor(9);cout<<"*\t*";
   cout<<"\t\t\t\t";setcolor(9);cout<<"**\t**";
   cout<<"\t\t\t\t";setcolor(10);cout<<"***\t***";
   cout<<"\t\t\t\t";setcolor(10);cout<<"****\t****";
   cout<<"\t\t\t\t";setcolor(11);cout<<"*****\t*****";
   cout<<"\t\t\t\t";setcolor(11);cout<<"******\t******";
   cout<<"\t\t\t\t";setcolor(12);cout<<"*******\t*******";
   cout<<"\t\t\t\t";setcolor(12);cout<<"*******\t*******";
   cout<<"\t\t\t\t";setcolor(13);cout<<"******\t******";
   cout<<"\t\t\t\t";setcolor(13);cout<<"*****\t*****";
   cout<<"\t\t\t\t";setcolor(14);cout<<"****\t****";
   cout<<"\t\t\t\t";setcolor(14);cout<<"***\t***";
   cout<<"\t\t\t\t";setcolor(15);cout<<"**\t**";
   cout<<"\t\t\t\t";setcolor(15);cout<<"*\t*";
	cout<<"\n\tInput Option number: ";
    cin>>opt;
                system("cls");
                if(opt==2){
                setcolor(9);
                transaction tra;
                tra.withdraw();
                }
                else if(opt==7)
                {
                    
                    setcolor(10);
                	transferance trans;
                	trans.transfer();
                }
                 else if(opt==6)
                 {
                 	
                    setcolor(11);
                 	account ac;
                 	ac.modifyaccount();
                 	
                 }
                else if(opt==5)
                {
                	
                    setcolor(12);
                	account ac;
                	ac.deleteaccount();
                	
                }
                else if(opt==4)
                {
                	
                    setcolor(13);
                	account ac;
                	ac.displayall();
                }
                else if(opt==3)
                {
                	
                    setcolor(14);
                	account ac;
                	ac.displayaccount();
                }
                else if(opt==1)
                {
                	
                    setcolor(13);
                	transaction traj;
                	traj.deposit();
                }
                else if(opt==8)
                {
                	
                    setcolor(12);
                	       atm aa;
                     aa.with_draw();
                     aa.balance_inquiry();
              
                }
                   else if(opt==9)
                {
                	                    setcolor(11);

                	loan lo;
                	lo.loaning();
                }
                else if(opt==10)
                {
              		break;  	
                }
             
                else
                {
                	cout<<"You entered a wrong option number"<<endl;
                }
        
    }
        system("pause");
        return 0;
}

void display_sp(int n)
{
        account ac;
        bool flag=false;
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        if(!inFile)
        {
                cout<<"File could not be open !! Press any key";
                return;
        }
 
        while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
        {
                if(ac.get_accountnum()==n)
                {
                	cout<<"BALANCE DETAILS"<<endl;
                        ac.show_account();
                        flag=true;
                }
        }
        inFile.close();
        if(flag==false)
                cout<<"\n\nAccount number does not exist.";
}
 
