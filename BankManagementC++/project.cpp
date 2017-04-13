#include "project.h"
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
      
void account::setloan(int i)
{
	loan=i;
}
int account::getloan()
{
	return loan;
}
//Account Modification Function
void account::modifyaccount()
{
	int n;
	cout<<"Enter the pasword for modifying the account"<<endl;
	cin>>n;
	bool found=false;
        fstream File;
        File.open("account.dat",ios::binary|ios::in|ios::out);
        //Verification of wether the file is opened successfully or not
		if(!File)
        {
                cout<<"File could not be open !! you messed it..";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (this), sizeof(account));
                //Verification of wether the password belongs to any account or not
				if(get_accountnum()==n)
                {
                        show_account();
                        cout<<"\n\nEnter The New Details of account: "<<endl;
                        //Invoking modification function to make changes on the desired account
						modify_account();
                        int pos=(-1)*static_cast<int>(sizeof(account));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (this), sizeof(account));
                        cout<<"\n\n\t Record has been updated. ";
                        found=true;
                  }
        }
        File.close();
        if(found==false)
                cout<<"\n\n Record Not Found ";
                getch();
	
}       


//Deleting an Account
 void account::deleteaccount()
 {
 	int n;
 	cout<<"Enter pasword for the account that you would like to delete"<<endl;
 	cin>>n;

        ifstream inFile;
        ofstream outFile;
        inFile.open("account.dat",ios::binary);
        //Verification of wether the file is opened successfully or not
		if(!inFile)
        {
                cout<<"File could not open !! Press any Key...";
                return;
        }
        outFile.open("Temp.dat",ios::binary);
        inFile.seekg(0,ios::beg);
        while(inFile.read(reinterpret_cast<char *> (this), sizeof(account)))
        {
                //Invoking modification function to make changes on the desired account
				if(get_accountnum()!=n)
                {
                        outFile.write(reinterpret_cast<char *> (this), sizeof(account));
                }
        }
        inFile.close();
        outFile.close();
        remove("account.dat");
        rename("Temp.dat","account.dat");
        cout<<"\n\n\tRecord has been deleted...";
 	
 	getch();
 	
 }
 
 //Displaying all accounts
 void account::displayall()
 {
        ifstream inFile;
        inFile.open("account.dat",ios::binary);
        //Verification of wether the file is opened successfully or not
        if(!inFile)
        {
                cout<<"File could not open !! Press any Key...";
                return;
        }
        cout<<"====================================================\n";
        cout<<"\n\t\tACCOUNT HOLDER LIST\n";
		cout<<"====================================================\n";
     	   cout<<"====================================================\n";
        cout<<"\nAcc No.    Name     Type Balance\n";
		cout<<"====================================================\n";
     
	    while(inFile.read(reinterpret_cast<char *> (this), sizeof(account)))
        {
        	//invoking get_report function to display the accounts
                get_report();
        }
        inFile.close();
        getch();
}
 
 //Display single account	
 void account::displayaccount()
 {
 	cout<<"Enter your password to view current details of your account:"<<endl;
 	int num;
 	cin>>num;
 	display_sp(num);
 	getch();
 	
 }
 
 //Getter for deposit
int account::get_deposit()
{
	return deposit;
}

 //Creating a new account
void account::create_account()
{
     account ac;
        cout<<"\nEnter The account Number: ";
        cin>>accountnum;
        
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        
while(!File.eof())
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(account));
              //Checking if the password is already taken
			    if(ac.get_accountnum()==accountnum)
                {
                    cout<<"The password you entetred is already in existence"<<endl;
                    cin>>accountnum;
                                            
       }
                
                                            
}
        cout<<"\nEnter your name(Account Holder's name) : ";
        cin.ignore();
        cin.getline(name_of_user,50);
        //Exceptional handling for minimum initial balance
		try{
		cout<<"\nPress 's' for Saving Account\nPress 'c' for Current Account\nEnter account type: ";
        cin>>type;
        type=toupper(type);
        cout<<type;
		cout<<"\n\n(Minimum 500 for Saving Account/ Minimum 1000 for Current Account)\nEnter The Initial balance: ";
        cin>>deposit;
        if(deposit<500 && type=='S'){
        	throw 'c';
        }
        
        if(deposit<1000 && type=='C'){
        	throw 1;
        }
		cout<<"\n\nYour Account has been successfully created\nThank you for choosing our Bank.\n ";
}
//catch statement for current account
catch(int i){
	while(deposit<1000){
	cout<<"Sorry but the amount is less than the minimum initial amount for current account\n";
	cout<<"Try again\n";
	cout<<"Input amount(Minimum 1000):\n";
	cin>>deposit;
}
}

//catch statement for saving account
catch(char j){
	
	while(deposit<500){
	cout<<"Sorry but the amount is less than the minimum initial amount for saving account\n";
	cout<<"Try again\n";
	cout<<"Input amount(Minimum 500):\n";
	cin>>deposit;
}
}
}
//Displays an account
void account::show_account()
{
        cout<<"\nAccount Number: "<<accountnum;
        cout<<"\nAccount Holder name: "<<name_of_user;
        cout<<"\nType of Account is: "<<type;
        cout<<"\nBalance amount is: "<<deposit;
}
 
 //Modification in an account
void account::modify_account()
{
        cout<<"\nAccount Number: "<<accountnum;
        cout<<"\nModify Account Holder Name: ";
        cin.ignore();
        cin.getline(name_of_user,50);
        cout<<"\nModify Type of Account: ";
        cin>>type;
        type=toupper(type);
        cout<<"\nModify Balance amount: ";
        cin>>deposit;
}
 
 //Setter for deposit
void account::deposit_funds(int x)
{
        deposit+=x;
}
       
 //Setter for withdraw
void account::draw_funds(int x)
{
        deposit-=x;
}
 //Displays report
void account::get_report()
{
        cout<<accountnum<<setw(10)<<" "<<name_of_user<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}
 
 //Getter for account number
int account::get_accountnum()
{
        return accountnum;
}
 
 //getter for funds(withdraw and deposit both depending on the situation)
int account::get_funds()
{
        return deposit;
}
 
 //getter for type of account
char account::get_accounttype()
{
        return type;
}




      void customer::setdetails()
		{
        account ac;
        ofstream outFile;
        outFile.open("account.dat",ios::binary|ios::app);
        ac.create_account();
        outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
        outFile.close();
			
		}

		
		void customer:: nth_customer()
		{
			ifstream infile;
			infile.open("account.dat",ios::in|ios::binary);
			if(!infile)
			{
				cout<<"Error"<<endl;
				exit(0);
			}
			infile.seekg(0,ios::end);
			int endposition=infile.tellg();
			int n=endposition/sizeof(customer);
			
			customer_id=n+1;
			cout<<"\nYou are our customer No."<<customer_id<<".\n Your Zip code is '"<<customer_id<<"'"<<endl;
		}
		
		
		
		
		
		
	
		void transaction::withdraw()
		{
			unsigned long withdraw;
			int n;
			cout<<"Enter your password"<<endl;
			cin>>n;
			        int amt;
        bool found=false;
      
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press Any Key. . .";
                return;
        }
        while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(account));
                if(ac.get_accountnum()==n)
                {
                ac.show_account();
                cout<<"\n\n\tTO WITHDRAW AMOUNT ";
                                cout<<"\n\nEnter The amount to be withdrawn : ";
                                cin>>amt;
                                int bal=ac.get_funds()-amt;
                                if((bal<500 && ac.get_accounttype()=='S') || (bal<1000 && ac.get_accounttype()=='C'))
                                        cout<<"You have Insufficienct balance";
                                else
                                        ac.draw_funds(amt);

                                        int pos=(-1)*static_cast<int>(sizeof(ac));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(account));
                        cout<<"\n\n\t Record has been updated.";
                        found=true;
}
}

File.close();
        if(found==false)
                cout<<"\n\n Sorry, Record Not Found. ";
				
getch();		
				}
						
		void transaction:: deposit()
		{
			int n;
			cout<<"Enter the password"<<endl;
			cin>>n;
			int amt;
            bool found=false;
        account ac;
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press Any Key. . .";
                return;
        }
while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(account));
                if(ac.get_accountnum()==n)
                {
ac.show_account();
cout<<"\n\n\tTO DEPOSIT AMOUNT ";
                                cout<<"\n\nEnter The amount to be deposited: ";
                                cin>>amt;
                                
                                if(amt<0)
                                        cout<<"You have insufficient balance";
                                else
                                        ac.deposit_funds(amt);

int pos=(-1)*static_cast<int>(sizeof(ac));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(account));
                        cout<<"\n\n\t The Record has been updated";
                        found=true;
                        ac.show_account();
                        
}
}

File.close();
        if(found==false)
                cout<<"\n\n Sorry, Record Not Found. ";
				
getch();
	
		}
		
		
		
		
		
		
	
		
		
		
		
		
		
		
		
		

      		int atm:: get_pin()
      {
          cout<<"Show your pin card number in front of the sensor machine "<<endl;
          
          cout<<"your pin is correct! you may proceed !"<<endl;
      }
      
      void atm:: with_draw()
      {
           trans.withdraw();
      cout<<"withdrawing!"<<endl;
      }
      
      void atm:: balance_inquiry()
      {
           cout<<"Your updated balance is :"<<endl;
           ac.show_account();
      
      }









void loan:: loaning()
              {
          	int n;
			cout<<"Enter the pasword"<<endl;
			
			cin>>n;
			bool found=false;
			
			
        fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press any key !..";
                return;
        }
while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(account));
                if(ac.get_accountnum()==n)
                {
                	found=true;
                	break;
                }
        }
        int count=ac.getloan();
        if(count==0)
        {
			
			cout<<"How much money do you want to take as loan"<<endl;
			int loa;
			cin>>loa;
			loa=loa/3;
			
	       found=false;
        
while(!File.eof() && found==false)
        {
                File.read(reinterpret_cast<char *> (&ac), sizeof(account));
                if(ac.get_accountnum()==n)
                {
ac.show_account();
getch();
int des;
des=ac.get_deposit();
                     if(des>=loa)
{
                                
                                loa=loa*3;
                                        ac.deposit_funds(loa);
                                        ac.setloan(loa);

int pos=(-1)*static_cast<int>(sizeof(ac));
                        File.seekp(pos,ios::cur);
                        File.write(reinterpret_cast<char *> (&ac), sizeof(account));
                        cout<<"\n\n\t Record Updated";
                        found=true;
                        ac.show_account();
                        getch();
}
else
{
    cout<<"The amount you asked for cannot be given as a loan"<<endl;
    
}

                       
}
                                            
}

}

else if(count>0)
{
	cout<<"You have not returned the previous loan"<<endl;
	getch();
}
}






void transferance:: transfer(void)
             {
             cout<<"Enter the account number?"<<endl;
             int x;
             cin>>x;
		     display_sp(x);

int option;
ifstream infile("account.dat",ios::binary);
infile.read(reinterpret_cast<char*>(&ac),sizeof(account));

cout<<endl<<"\nYour current amount is : "<<ac.get_deposit()<<endl;
x=ac.get_deposit();
int amt;
cout<<"How much amount do you want to transfer?"<<endl;
cin>>amt;

if(amt<=0 || amt> x)
{
	cout<<"An error has been occured , Please try later"<<endl;
}

else
{
	cout<<"Enter the account Number in which you want to transfer the money"<<endl;
	int num;
	cin>>num;
	
	display_sp(num);
	bool found=false;
	infile.close();
	fstream File;
        File.open("account.dat", ios::binary|ios::in|ios::out);
        if(!File)
        {
                cout<<"File could not be open !! Press Any Key. . .";
                return;
        }
        while(!File.eof() && found==false)
        {
        	 File.read(reinterpret_cast<char *> (&ac), sizeof(account));
                if(ac.get_accountnum()==num)
                {
                	ac.deposit_funds(amt);
                	found=true;
                }
        }
        if(found==true)
        {
        
        int pos=(-1)*static_cast<int>(sizeof(ac));
        File.seekp(pos,ios::cur);
        File.write(reinterpret_cast<char *> (&ac), sizeof(account));
        cout<<"\n\n the amount is successfully transfered to its required destination";
        found=true;
    }
    
    else if(found=false)
    {
    	cout<<"An Error Has occured"<<endl;
    }	
}
}
              

