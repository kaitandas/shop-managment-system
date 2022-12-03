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
class customer{
	private:
		string email;
		string password;
	public:	
		customer(){
			email="user@gmail";
			password="123";
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
class shop{
	
	public:
		admin a;
		customer c;
	    employees e[20];
	    int noOfEmployee=20;
		
		shop(){
			
		
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
		cout<<"c";
		char input1,input_ep;
		do{
			
			cout<<"Enter your choice\nA)Employee\nB)Product\n\n";
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
			
	   		cout<<"If you want to exit the press 'Esc' key,'FROM EMPLOYEE AND PRODUCT' and if continue press any key.\n";
			input1=getch();
			
		}while(input1!=27);
		
	}
	else if(c.getEmail()==email && c.getPassword()==password){
		
		cout<<"Enter your products in cart\n";
	}
	
	cout<<"If you want to exit the press 'Esc' key, 'FROM LOGIN'and if continue press any key.\n";
	input=getch();
		
	}while(input!=27);
	}
	
	
	void employee(){
		
		char input;
		int a;
		do{
		
		cout<<"Enter series number if you want to.\n1)Add employees\n2)Delete employees\n3)Search employees\n 4) View All\n";
		cin>>a;
		
		employees e[0];
		
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
				viewAll();
				break;				
		}		
		
	
		cout<<"If you want to exit the press 'Esc' key, 'FROM EMPLOYEE' and if continue press any key from.\n";
		input=getch();
	}while(input!=27);
		
	}
	void viewAll(){
		for(int i=0; i<noOfEmployee ;i++){
			cout<< e[i].employee_name;
		}
		
	}
	void add_employees(){
		int n;
		cout<<"Enter the number of employees you want to add\n";
		cin>>n;
		
		cout<<"\nEnter information of employees\n\n";
		for(int i=0;i<n;i++){
			
//			employees p;
//			e[i]=&p;
			
			cout<<"Employee "<<i+1<<"\n";
			cout<<"Enter name\n";
			cin>>e[i].employee_name;
			cout<<"Enter id\n";
			string a;
			cin>>a;
			e[i].set_id(a);
			
		}
		
		e[0].no_of_employees=n;
		noOfEmployee = n;
	}
	void delete_employees(){
		char input;
//		cout<<"\nEnter the number of employees you want to delete.\n";
		
//		cout<<"\nEnter information of employees\n\n";
//		for(int i=0;i<n;i++){
		do{
			
			cout<<"Enter id you want to delete.\n";
            string a;
            cin>>a;
            
            for(int i=0;i<e[0].no_of_employees;i++){
            	
            	if(a==e[i].get_id()){
//            		for(int j=0;j<e[0].no_of_employees;j++){
					
            		e[i].employee_name=e[i+1].employee_name;
            		e[i].set_id(e[i+1].get_id());
            		
//            	}
				}
				if(i+1==e[0].no_of_employees){
					e[i].employee_name="null";
					e[i].set_id("null");
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
			cout<<"Enter the employee id you want to know\n";
			cin>>id;
		
		for(i=0;i<e[0].no_of_employees;i++){
	
			if(id==e[i].get_id()){
				cout<<"Name of Employee : "<<e[i].employee_name<<"\n";
			}
	    }
		cout<<"If you want to exit the press 'Esc' key, 'SEARCH EMPLOYEE' and if continue press any key from.\n";
			
			input=getch();
			
			
		}while(input!= 27);
	}
	void product(){
		
	}
};


class stock{
	public:
		string product_no;
		string product_name;
		int product_quantity;
		int total_products;
		
		stock(){
			
			total_products=100;
		}
	
	virtual void addProduct()=0;
	virtual void deleteProduct()=0;
	virtual void updateProduct()=0;
	virtual void searchProduct()=0;
};
class products:public stock{
	
	public:
		void addProduct(){
			
		}
		void deleteProduct(){
			
		}
		void updateProduct(){
			
		}
		void searchProduct(){
			
		}
};

class cart{
	
	public:
		products p;
		int cart[9];
};
main(){
	

	shop s;
	s.input();	

}
