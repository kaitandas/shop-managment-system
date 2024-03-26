#include <iostream>
#include <conio.h>
using namespace std;
class admin{
	
	private:
		 string email;
		 string password;
	public:	
		admin(){
			email="kaitandas";
			password="1234";
		}
		string getEmail(){
			return email;
		}
		string getPassword(){
			return password;
		}
};




class employees{
	private:	
		string employee_id;
	public:
		string employee_name;
		int no_of_employees;
		
		employees(){
			
			no_of_employees=0;
			employee_id="";
		}
		void set_id(string a){
			employee_id=a;
		}
		string get_id(){
			return employee_id;
		} 
		
	
};
class products{
	
	public:
		string product_number;
		string product_name;
		float price;
		string type;      
        products(){
            price=0;
		}
		products(string pNumber,string pName,float p){
              
                 product_name=pName;
				 product_number=pNumber;
				 price=p;
		}

	    void ProductInformation(){
			
			cout<<"Product 'TYPE' : "<<get_type()<<"\n";
			cout<<"Product name : "<<get_name()<<"\n";
			cout<<"Product number : "<<get_id()<<"\n";
			cout<<"Product Price : "<<get_price()<<"\n";
		}	   

		void getInput(){
			
			    cout<<"Enter type of product\n";
				cin>>type;
				cout<<"Enter Product ID\n";
				cin>>product_number;
				cout<<"Enter Product name\n";
				cin>>product_name;
				cout<<"Enter Product Price\n";
				cin>>price;
		}
		void deleteInformation(){

		}//Abstraction
		           
		  virtual string get_type(){
                return "";
		 }
		      string get_id(){
			return product_number;
		}
		string get_name(){
			return product_name;
		}
		
		float get_price(){
			return price;
		}    

        
};

class mobile:public products{                    //Inheritance...
	public:
	      mobile():products(){}
		  mobile(string a,string b,float c):products(a,b,c){


		  }
	    string get_type(){
			return "Mobile";
		}
};
class tablet:public products{
	public:
	tablet():products(){

	}
	tablet(string a,string b,float c):products(a,b,c){


		  }
		
		string get_type(){
			return "Tablet";
		}
		
};
class cart{
	
	public:
		// mobile m[10];
		// tablet t;
		products pList[20];
		int CountIndex;
		float totalPrice;
		
		cart(){
			totalPrice=0;
			CountIndex=0;
		}
		void AddToCart(products pp){
			pList[CountIndex] = pp;
             CountIndex++;

			 totalPrice+=pp.get_price();
		}
		void ViewCart(){
             
			 cout<<"\n\t-----------------Cart---------------\n\n";

			for(int i=0;i<CountIndex;i++){

				pList[i].ProductInformation();
				cout<<"\n";

			}
			cout<<"Total Price : "<<totalPrice<<"\n\n";

			
		}
};
class customer{
	public:
		string email;
		string password;


	public:	
	//    cart c;
	  
		customer(){
			email="user@gmail";
			password="123";
			// s.input(email,password);
		}
		string getEmail(){
			return email;
		}
		string getPassword(){
			return password;
		}
	 
};
class shop{
	
	public:
		admin a;
		customer c;
		cart cart1;
	    employees e[20];
		mobile m[10];     //Product...
		tablet t[10];     //Product...
		int mobileCounter,MnoOfProduct;
		int tabletCounter,tnoOfProduct;
	    int noOfEmployee_limit,noOfEmployee;
	    int noOfEmployee_counter;
		
		shop(){
			 
			 noOfEmployee_limit=20;
			 noOfEmployee=0;
		     noOfEmployee_counter=0;
			 mobileCounter=3;
			 tabletCounter=3;
			mobile m1("111","samsung A5",121);

			 mobile m2("112","apple : iPhone 12",500);
			 mobile m3("113","huawei Y3 pro",550);

			 m[0]=m1;
			 m[1]=m2;
			 m[2]=m3;

			tablet t1("121","viper ",300);

			 tablet t2("122","apple : iPad",3000);
			 tablet t3("123","huawei Y3 pro",1200);

			 t[0]=t1;
			 t[1]=t2;
			 t[2]=t3;
		}
	void input(){
			string email,password;
	char input;
	
//		employees p[20];
//			
//			for(int i=0;i<20;i++){
//				e[i]=&p[i];
//			}
	do{
//		this();
	cout<<"Enter email:\n";
	cin>>email;
	cout<<"Enter password:\n";
	cin>>password;
	
	if(email==a.getEmail() && password==a.getPassword()){
		cout<<"\n\n\n\t'WELCOME TO ADMIN PANEL'\n\n\n";
		char input1,input_ep;
		do{
			
			cout<<"Enter your choice\nA)Employee\nB)Product\n\n\n";
			cin>>input_ep;
			
			switch(input_ep){
				
			case 'A':
			case 'a':
				employee();
				break;
			
			case 'B':
			case 'b':
				product();
				break;
				
			default:
			break;
			}
			
	   		cout<<"If you want to exit then press 'Esc' key,'FROM EMPLOYEE AND PRODUCT' and if continue press any key.\n";
			input1=getch();
			
		}while(input1!=27);
		
	}
	else if(c.getEmail()==email && c.getPassword()==password){
		
              showCustomerView();
	}
	
	cout<<"If you want to exit then press 'Esc' key, 'FROM LOGIN'and if continue press any key.\n";
	input=getch();
		
	}while(input!=27);
	}
	
	
	void employee(){
		
		char input;
		int a;
		do{
		cout<<"\n\n\t----------------Employee--------------------\n\n";
		cout<<"Enter series number if you want to.\n1)Add employees\n2)Delete employees\n3)Search employees\n 4) View All\n";
		cin>>a;
		
		
		switch(a){
			
			case 1:
			     add_employees();
			    break;
			case 2:
				delete_employees();
				break;
			case 3:
				search_employees();
				break;
			case 4:
				viewAllEmployee();
				break;				
		}		
		
	
		cout<<"If you want to exit then press 'Esc' key, 'FROM EMPLOYEE' and if continue press any key from.\n";
		input=getch();
	}while(input!=27);
		
	}
	
	void add_employees(){
		

		cout<<"\n\nEnter the number of employees you want to add\n";
		cin>>noOfEmployee;
		
		cout<<"\n\nEnter information of employees\n\n";
		for(int i=0;i<noOfEmployee;i++){
			
//			employees p;
//			e[i]=&p;
			
			cout<<"Employee :"<<i+1<<"\n";
			cout<<"Enter name\n";
			cin>>e[noOfEmployee_counter].employee_name;
			cout<<"Enter id\n";
			string a;
			cin>>a;
			e[noOfEmployee_counter].set_id(a);
			
            noOfEmployee_counter++;

			cout<<"\n";
		}
		
		// e[0].no_of_employees=n;
		// noOfEmployee = n;
		
	}
	void delete_employees(){
		char input;
//		cout<<"\nEnter the number of employees you want to delete.\n";
		
//		cout<<"\nEnter information of employees\n\n";
//		for(int i=0;i<n;i++){
		do{
			
			cout<<"\n\nEnter id you want to delete.\n\n";
            string a;
            cin>>a;
            
            for(int i=0;i<noOfEmployee_counter;i++){
            	
            	if(a==e[i].get_id()){
           		for(int j=i;j<noOfEmployee_counter;j++){
					
            		e[j].employee_name=e[j+1].employee_name;
            		e[j].set_id(e[j+1].get_id());
            		
					if(j==noOfEmployee_counter-1){
						// e[j].employee_name="null";
						// e[j].set_id("null");
                         
						cout<<"'\n\nID deleted successfully'\n\n";
						noOfEmployee_counter--;
				}
					
           	}
				}
				
			}
           
           cout<<"Enter 'ESC' Keyword for exit, or enter any keyword to continue.\n";
		input=getch();
		}while(input!=27);
	}
	void search_employees(){
		char input;
		string id;
		int i;
		               
		do{
			cout<<"\n\nEnter the employee id you want to know\n";
			cin>>id;
		
		for(i=0;i<noOfEmployee_counter;i++){
	
			if(id==e[i].get_id()){
				cout<<"Name of Employee : "<<e[i].employee_name<<"\n\n";
			}
	    }
		cout<<"If you want to exit then press 'Esc' key, 'SEARCH EMPLOYEE' and if continue press any key from.\n";
			
			input=getch();
			
			
		}while(input!= 27);
	}

	void viewAllEmployee(){
		    
          cout<<"\n\t--------------present Employees-----------\n";

		for(int i=0; i<noOfEmployee_counter ;i++){
			cout<<"\nEmployee : "<<i+1<<"\n";
			cout<< e[i].employee_name<<"\n";
			cout<<e[i].get_id()<<"\n";
		}
		
	}
	void product(){
		
		cout<<"\n\n----------------PRODUCTS----------------";
        char input;
		do{
          int a;
              cout<<"\n\nEnter your choices\n\n1)Add Product\n2)DeleteProduct\n3)View Product\n\n";
			  cin>>a;
		  switch (a)
		  {
		  case 1:
			   addProduct();
			break;
		  case 2:
		       deleteProduct();
			   break;
		  case 3:
		  	   viewProduct();	
			break;   
		  
		  }
		cout<<"If you want to exit then press 'Esc' key,from 'Product' and if continue press any key from.\n";
        input=getch();
		}while(input!=27);
	}
	void addProduct(){
        cout<<"Enter Product\n\n1)Mobile\n2)Tablet\n\n";
		int a;
		cin>>a;

		switch (a)
		{
		case 1:
			cout<<"\n\n---------------MOBILE---------------\n\n";

			cout<<"Enter quantity of Products to add\n\n";
			cin>>MnoOfProduct;
			for(int i=0;i<MnoOfProduct;i++){
				
				cout<<"Mobile Product : "<<i+1<<"\n\n";
				
				m[mobileCounter].getInput();        //input...
                   if(m[mobileCounter].product_name==m[mobileCounter-1].product_name || m[mobileCounter].product_number==m[mobileCounter-1].product_number){

                       cout<<"\nInformation you given is same please input again.\n\n";

					   mobileCounter--;
					   i--;

				   }

				mobileCounter++;

				
 
			}
			break;
		
		case 2:
		     cout<<"\n\n---------------TABLET---------------\n\n";

			 
			 cout<<"Enter quantity of Products to add\n\n";
			 cin>>tnoOfProduct;
			 for(int i=0;i<tnoOfProduct;i++){
				
				cout<<"Tablet Product : "<<i+1<<"\n\n";

				t[tabletCounter].getInput();      //input...

                  if(t[tabletCounter].product_name==t[tabletCounter-1].product_name || t[tabletCounter].product_number==t[tabletCounter-1].product_number ){

                    cout<<"\nInformation you given is same please input again.\n\n";

				    tabletCounter--;
					   i--;

				   }
				tabletCounter++;
 
			}
			break;
		}
	}
	void deleteProduct(){

			cout<<"Enter Product\n\n1)Mobile\n2)Tablet\n\n";
		char input;	
       int a;
		cin>>a;

		switch (a)
		{
		case 1:
			cout<<"\n\n---------------MOBILE---------------\n\n";
		do{
			
			
            if(mobileCounter>=1){

			cout<<"\n\nEnter id you want to delete.\n\n";
            string a;
            cin>>a;

            for(int i=0;i<mobileCounter;i++){
            	
            	if(a==m[i].get_id()){
           		for(int j=i;j<mobileCounter;j++){
					
            		m[j].product_name=m[j+1].product_name;
            		m[j].product_number=m[j+1].product_number;
					m[j].price=m[j+1].price;
            		
					if(j==mobileCounter-1){
						// e[j].employee_name="null";
						// e[j].set_id("null");
                         
						cout<<"'\n\nID deleted successfully'\n\n";
						mobileCounter--;
				}
					
           	}
			   break;
				}
				else {
					cout<<"No data found\n\n";
					break;
				}
				
			}
			}
			else{
				cout<<"No data found...\n\n";
			}
           cout<<"Enter 'ESC' Keyword for exit from 'DELETE MOBILE', or enter any keyword to continue.\n";
		input=getch();
		}while(input!=27);
	
			break;
		
		case 2:
		     cout<<"\n\n---------------TABLET---------------\n\n";

			 do{
			
            if(tabletCounter>=1 ){
		
			cout<<"\n\nEnter id you want to delete.\n\n";
            string a;
            cin>>a;

            for(int i=0;i<tabletCounter;i++){
            	
            	if(a==t[i].get_id()){

           		for(int j=i;j<tabletCounter;j++){
					
            		t[j].product_name=t[j+1].product_name;
            		t[j].product_number=t[j+1].product_number;
            		t[j].price=t[j+1].price;
					if(j==tabletCounter-1){
						// e[j].employee_name="null";
						// e[j].set_id("null");
                         
						cout<<"'\n\nID deleted successfully'\n\n";
						tabletCounter--;
						 
				}
					
           	}
			    break; 
				}
				
				else {
					cout<<"No data found\n\n";
					break;
				}

			}

			}
			else{
				cout<<"No data found...\n\n";
			}
			
           cout<<"Enter 'ESC' Keyword for exit from 'DELETE TABLET', or enter any keyword to continue.\n";
		input=getch();
		}while(input!=27);
			break;
		}
	}
	void viewProduct(){
		cout<<"Enter Product\n\n1)Mobile\n2)Tablet\n\n";
		int a;
		cin>>a;

		switch (a)
		{
		case 1:
			cout<<"\n\n---------------MOBILE---------------\n\n";
        if(mobileCounter>=1){
			for(int i=0; i<mobileCounter ;i++){

			cout<<"Product : "<<i+1<<"\n\n";

			m[i].ProductInformation();
			cout<<"\n";

		}
		}
		else{
			cout<<"No data found...\n\n";
		}
			break;
		
		case 2:
		     cout<<"\n\n---------------TABLET---------------\n\n";
             
			 if(tabletCounter>=1){
			 for(int i=0; i<tabletCounter ;i++){

			 cout<<"Product : "<<i+1<<"\n\n";
			
			t[i].ProductInformation();
			cout<<"\n";

		}
			 }
			 else {
				cout<<"No data found...\n\n";
			 }

			break;
		}
	}
	void showCustomerView(){

    	cout<<"\n\t----------------WELCOME TO CUSTOMER----------------\n\n";
		
		cout<<"Enter your products in cart\n";
        char input2;


		do{
			cout<<"1)View Cart\n";
			cout<<"2)Add to cart\n";
            cout<<"ESC to exit\n\n";
           input2=getch();

			
			switch (input2)
			{
			case '1':
			cart1.ViewCart();
				break;
			case '2':
			viewProduct();
            AddToCart();
			break;
			default:
				break;
			}
          
		}while(input2!=27);
	}
	void AddToCart(){

		cout<<"Enter product id to add into cart\n";
		string input;
		cin>>input;

		for(int i=0;i<mobileCounter;i++){
			if(input==m[i].get_id()){
              
              cart1.AddToCart(m[i]);   
			}
			else if(input==t[i].get_id()){
               cart1.AddToCart(t[i]);
			}
		}
	}

};



main(){
	
    //  customer cust;
	shop s;
	s.input();	

}



