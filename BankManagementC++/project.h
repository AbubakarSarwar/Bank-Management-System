//Base class
//Concrete class
void display_sp(int); 
class account
{
    	//Account number = Password of user
	    int accountnum;
	    //Name of user
        char name_of_user[50];
        int deposit;
        //Type of Account
        char type;
	    int loan;
public:
	account(){
		loan=0;
	}
	//To modify an account
	void modifyaccount();
	//Deleting an account
	void deleteaccount();
	//Display all accounts
	void displayall();
	//Display a single account
	void displayaccount();
	//Deposit balance
    void deposit_funds(int);
    //Withdraw balance
    void draw_funds(int);  
    //Creating a new account
	void create_account(); 
    //Display account
	void show_account();   
	//To modify an account
    void modify_account();
    //Get report of account
	void get_report();
    //Getter of account number
	int get_accountnum();  
	//Getter for funds     
    int get_funds();  
	//Getter for account type     
    char get_accounttype();
    //Getter for deposit
    int get_deposit();
	void setloan(int i);
	int getloan();

};

class customer
{
       private:
		int customer_id;
		account ac;
      public:
      void setdetails();
      void nth_customer();
};

class transaction
{
      private:
		  account ac;
       public:
      void withdraw();
      	void deposit();
};

class atm
{
      private:
       int number;
       transaction trans;
       account ac;
       
       public:
      int get_pin();
      void with_draw();
       void balance_inquiry();
};


class loan
 {
       private:
              account ac;
       public:
       void loaning();
 };
 
 class transferance
{
         private:
              account ac;
        public:
       void transfer(void);
};
