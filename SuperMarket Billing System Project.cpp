#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class shopping
{
	private:
		int pcode;//product code
		float price;//price of the product
		float dis;//discount of the product
		string pname;//name of the product
		
	public:
		void menu(); //Interface Shown To Every User...  (Main Menu)
		void administrator(); //Interface shown if user is administrator...
		void buyer();  //Interface shown if user is buyer...
		void add();  //function to add the product...
		void edit();  //function to modify the product...
		void rem();   //function to remove/delete the product...
		void list();  //function to show the list of products to the buyer...
		void receipt();	
};

//Menu Function...
void shopping::menu()
{
	m: //m is a label...
	int choice;
	
	//Email and Password For Login...
	string email;
	string password;
	
	cout<<"\t\t\t\t_____________________________\n";
	cout<<"\t\t\t\t                             \n";
	cout<<"\t\t\t\t          Supermarket Main Menu            \n";
	cout<<"\t\t\t\t                             \n";
	cout<<"\t\t\t\t_____________________________\n";
	cout<<"\t\t\t\t                             \n";
	
	//Creating an interface where 
    //user have to select whether he is an administrator or buyer....
	cout<<"\t\t\t\t|  1) Administrator   |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  2) Buyer           |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\t\t\t\t|  3) Exit            |\n";
	cout<<"\t\t\t\t|                     |\n";
	cout<<"\n\t\t\t Please select:";
	cin>>choice;//choice from user...
	
	switch(choice){
		
		
		case 1:  //if user is logging in as administrator...
			cout<<"\t\t\t Please Login  \n";
			cout<<"\t\t\t Enter Email: ";
			cin>>email;
			cout<<"\t\t\t Password: ";
			cin>>password;
			
			if(email=="niket@email.com" && password=="niket@123"){
				administrator();
			}
			else{
				cout<<"Invalid Email Or Password";
			}
			break;
	
	case 2: //if user if logging in as buyer...
		{
			buyer();
		}
	case 3:  //for exit(successful termination of the program)
		{
			exit(0);
		}
	default:  //this case will execute if user select any other option rather tham 1,2 or 3...
		{
			cout<<"Please select from the given options..."<<endl;
		}
	}

goto m; // this goto will help us to go again at main menu and using this m as a label
        //present at starting of this function...
}

void shopping::administrator(){
	m:
	int choice;
	cout<<"\n\n\t\t\t  Administrator Menu";
	cout<<"\n\t\t\t|___1) Add the product_____|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|___2) Modify the product__|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|___3) Delete the product__|";
	cout<<"\n\t\t\t|                          |";
	cout<<"\n\t\t\t|___4)Back to main menu____|";
	
	cout<<"\n\n\t Please enter your choice: ";
	cin>>choice;
	
	switch(choice){
		case 1:
			add();
			break;
	    
	    case 2:
	    	edit();
	    	break;
	    
	    case 3:
	    	rem();
	    	break;
	    	
	    case 4:
	    	menu();
	    	break;
	    	
	    default:  //if user makes an invalid choice...
	    	cout<<"Invalid Choice!!"<<endl;
	}
	goto m;
}

void shopping::buyer()
{
	m:
	int choice;
	cout<<"\n\t\t\t  Buyer Menu \n";
	cout<<"\t\t\t________________\n";
	cout<<"                      \n";
	cout<<"\t\t\t 1)Buy Product \n";
	cout<<"                      \n";
	cout<<"\t\t\t 2)Go Back      \n";
	cout<<"                      \n";
	
	cout<<"Enter Your Choice: ";
	cin>>choice;
	
	switch(choice){
		case 1:  //if user buys the product...
			receipt();
			break;
			
		case 2:
			menu();
			break;
		
		default:
			cout<<"Invalid Choice"<<endl;
	}
	
	goto m;
}

void shopping::add()  // this menu is controlled by administrator...
{
	m:
	fstream data; // data is an object created of fstream class...
	int c;  //product code
	int token=0; 
	float p;  //price of the product
	float d;  //discount on product
	string n;  //product name
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product: ";
	cin>>pcode;
	
	cout<<"\n\n\t Name of the product: ";
	cin>>pname;
	cout<<"\n\n\t Price of the product: ";
	cin>>price;
	cout<<"\n\n\t Discount on the product: ";
	cin>>dis;
	
	data.open("database.txt",ios::in);  // here we open a file database.txt using ios-in in read-only-mode...
	
	if(!data)  //if this file with product info doesn't exist...
	{
		data.open("database.txt",ios::app|ios::out);  //ios-app activates append mode and ios-out is for writing mode...
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";  //writing the info inside file...
		data.close(); //After that close the file...
	}
	
	else  //if file with product info already exist...
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())  //eof is end of file.. so this loop will iterate till end of file...
		{
			
			//this condition means product code entered by administrator already exists...
			if(c==pcode){  //if code matches... (there is redundancy)
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
	
	    if(token==1){
		   goto m;
	    }
	    else  //if pcode is unique...
	    {
		   //then administrator can add other values too...
		   data.open("database.txt",ios::app|ios::out);
		   data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		   data.close();
	    }
    }
	cout<<"\n\n\t Record Inserted!!";
}

void shopping::edit()
{
	fstream data,data1;  //created two objects of fstream class...
	int pkey;
	int token=0;
	int c; //updated product code
	float p;  //updated price of the product
	float d;  //updated discount on product
	string n;  //updated name of the product
	
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code: ";
	cin>>pkey;
	
	//Now we will open the file to check if file exist or not...
	data.open("database.txt",ios::in);
	
	if(!data)   //file doesn't exist...
	{
		cout<<"\n\nFile doesn't exist! ";
	}
	else  //file exists...
	{
	    data1.open("database1.txt",ios::app|ios::out);  // So now we will open another file using data1 object and save our edited data in it...
	    
	    data>>pcode>>pname>>price>>dis;  //read the data from previous file...
	    while(!data.eof())  //iterate through previous file
	    {
	    	if(pkey==pcode)   //if code provided by administrator now matched...
			{
	    		//We will allow him to modify the product...
	    		cout<<"\n\t\t Enter the new product code: ";
	    		cin>>c;
	    		
	    		cout<<"\n\t\t Enter the new name of the product: ";
	    		cin>>n;
	    		
	    		cout<<"\n\t\t Enter the new price of the product: ";
	    		cin>>p;
	    		
	    		cout<<"\n\t\t Enter the new discount on the product: ";
	    		cin>>d;
	    		
	    		//Now updating all the things using data1 object...
	    		data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
	    		cout<<"\n\nRecord Edited!!\n";
	    		token++;
			}
			else  //pkey entered by administrator doesn't matches...
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";	
			}
			data>>pcode>>pname>>price>>dis;  //keep reading for next iterations
		}
	    //After updating close both the objects...
	    data.close();
	    data1.close();
	    
	    remove("database.txt"); //remove the old database.txt file...
	    rename("database1.txt","database.txt"); //rename database1 to database.txt...
	    
	    if(token==0){
	    	cout<<"\n\nRecord Not Found Sorry!! ";
		}
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t-----------Delete Product----------\n";
	cout<<"\n\n\t Enter the product code: ";
	cin>>pkey;
	data.open("database.txt",ios::in);  //opened the file...
	if(!data)   //file doesn't exist...
	{
		cout<<"File Doesn't Exist!!";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof()){
			if(pcode==pkey)  //if pkey entered by admninistrator matches pcode then delete the product...
			{  
				cout<<"\n\n\t Product Deleted Successfully!!";
				token++;
			}
			else  //if pkey doesn't matches then push data as it is... thru data1 into database1.txt
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		//Close both the objects... after deletion...
		data.close();
		data1.close();
		
		remove("database.txt");  //remove old database.txt file...
		rename("database1.txt","database.txt"); //rename database1 to database.txt...
		
		if(token==0){
			cout<<"\n\n Record Not Found!!";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|_______________________________________________|\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|_______________________________________________|\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof()){
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();  //closing the object after lisiting to user...
}

void shopping::receipt()
{
	fstream data;
	int arrc[100]; //Array of product codes...
	int arrq[100]; //Array of Quantities...
	
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t    RECEIPT ";
	data.open("database.txt",ios::in);
	
	if(!data) //No data inside the file...
	{
		cout<<"\n\n Empty Database";
	}
	else   //data is present...
	{
		data.close(); //close the file we opened to check whether data is present or not...
		list();
		cout<<"\n|__________________________________|\n";
		cout<<"\n|                                  |\n";
	    cout<<"\n|                                  |\n";
		cout<<"\n|        Please Place The Order    |\n";
		cout<<"\n|                                  |\n";
	    cout<<"\n|__________________________________|\n";
	    cout<<"\n|                                  |\n";
	    
	    do
	    {
	    	m:
	    	cout<<"\n\n Enter product code: ";
	    	cin>>arrc[c];
	    	cout<<"\n\n Enter product quantity: ";
	    	cin>>arrq[c];
	    	
	    	//if code entered by the user matches with code entered already then there is duplicacy...
	    	for(int i=0;i<c;i++){
	    		if(arrc[c]==arrc[i]){
	    			cout<<"\n\n Duplicate Product Code.Please try again!!";
	    			goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product?? if yes,then press y,else press n... ";
			cin>>choice;
		}
		while(choice=='y');
		
		cout<<"\n\n\t\t\t_______________________RECEIPT____________________\n";
		cout<<"\n"<<"ProductNo"<<"  "<<"ProductName"<<"  " <<"ProductQuantity"<<"  "<<"price"<<"  "<<"Amount"<<"  "<<"AmountWithDiscount"<<"\n";
		
		for(int i=0;i<c;i++){
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				//if code entered by buyer matches.. then we add the product in user's basket...
				if(pcode==arrc[i])  //arrc[i] is the value of the code filled by buyer...
				{
					amount=price*arrq[i];   //total amount is price into quantity of the product which is stored in arrq...
					dis=amount-(amount*dis/100);  //discount is calculated as amount minus percentage of discount on that amount...
					total=total+dis;  //after that discount is added to total variable...
					cout<<"\n"<<pcode<<"     "<<pname<<"    "<<arrq[i]<<"    "<<price<<"    "<<amount<<"    "<<dis<<"\n";
				}
				data>>pcode>>pname>>price>>dis;  //continuing the iteration of reading file...
			}
		}
		data.close(); //at the end close the file...
	}
	
	cout<<"\n\n_________________________________________";
	cout<<"\n Total Amount: "<<total;
} 

int main()
{
	shopping s;
	s.menu();
}
