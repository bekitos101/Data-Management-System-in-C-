
#include<conio.h>
#include <iostream>
#include<fstream>
#include<string>
#include"product.h"
#include"Employee.h"
#include"Client.h" 
#include<conio.h>

using namespace std;

//the exceptions will be commented because for some reason they mess up with the file while reading/writing it 

//throws an error in case of unopened file 
class FileException : public exception  
{
    virtual const char* what() const throw()
    {
        return "WARNING! Error occured when opening File !";
    }
}FileEX;




int PasswordChecker(){
char UserPass[20],TruePass[20]={"user2021"},ch;
int i=0;
int n;
printf(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
printf("Enter the password. After entering password press either space bar,tab or enter key\n");
while(1)
{
ch=getch();
if((ch==' ')||(ch=='\t')||(ch=='\r'))
{
break;
}
else
{
UserPass[i]=ch;
ch='*';
std::cout<<ch;
i++;
}
}
printf("\n");
UserPass[i]='\0';
n=strcmp(UserPass,TruePass);
if(n==0){
    return 1;
  	}
else {
    return 0;
}
 }

int ProductsTotal()
{
    int Total = 0;
    std::string s;
    std::fstream fproducts;
    fproducts.open("Products.txt");
    while (!fproducts.eof())
    {
        std::getline(fproducts, s);
        Total++;
    }
    fproducts.close();
    return Total/5;
}

int ClientsTotal(){
int Total = 0;
    std::string s;
    std::fstream fclients;
    fclients.open("Clients.txt");
    while (!fclients.eof())
    {
        std::getline(fclients, s);
        Total++;
    }
    fclients.close();
    return Total/5;

}

int EmployeesTotal(){
int Total = 0;
    std::string s;
    std::fstream femployees;
    femployees.open("Employees.txt");
    while (!femployees.eof())
    {
        std::getline(femployees,s);
        Total++;
    }
    femployees.close();
    return Total/7;

}
 


 Client* ExtractClients(Client* Clients){
    fstream Client_file;
    Client_file.open("Clients.txt", ios::in);//do i need to open it here ?
    int Total=ClientsTotal();
    int i = 0;
    /*try {
           Client_file.open("Employees.txt", ios::app);
            if (!Client_file.is_open())
                throw(FileEX);
        }
    catch (exception& ex){
            cout << ex.what() << endl;
    
    }*/
   while (i < Total)
    {
        Client_file >> Clients[i].ID;
        Client_file >> Clients[i].name;       
        Client_file>>Clients[i].d;
        Client_file >> Clients[i].SignDate;
        Client_file>>Clients[i].subscribtion;
        i++;
    }
    Client_file.close();
    return Clients;
 

}
void UpdateClientFile(Client* Clients, int& Total){
fstream Client_file;
    int i = 0;
   /* try {
        Client_file.open("Clients.txt", ios::in);
        if (! Client_file.is_open())
            throw(FileEX);
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    }*/  
    Client_file.open("Clients.txt", ios::out);         
    for(int i=0;i<Total;i++){
      Client_file<< Clients[i].ID<< endl;
      Client_file<< Clients[i].name<< endl;
      Client_file<< Clients[i].d<< endl;
      Client_file<< Clients[i].SignDate<< endl;
      Client_file<< Clients[i].subscribtion<< endl;

       }
    
}

 Employee* ExtractEmployees(Employee* Employees) {
    fstream employee_file;
    fstream test;
    employee_file.open("Employees.txt", ios::in);
    int Total = EmployeesTotal();
    int i = 0;
   /* try {
        employee_file.open("Employees.txt", ios::app);
        if (!employee_file.is_open())
            throw(FileEX);
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }*/ 
    while (i < Total)
    {
        employee_file >> Employees[i].ID;
        employee_file >> Employees[i].name;
        employee_file >> Employees[i].position;
        employee_file >> Employees[i].salary;
        employee_file >> Employees[i].d;
        employee_file >> Employees[i].phoneNumber;
        employee_file >> Employees[i].address;
     
        i++;
    }
    employee_file.close();
    return Employees;




}
void UpdateEmployeesFile(Employee* Employees, int& Total){
fstream Employee_file;
    int i = 0;
   /* try {
        Employee_file.open("Employees.txt", ios::in);
        if (! Employee_file.is_open())
            throw(FileEX);
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    } */
    Employee_file.open("Employees.txt", ios::out);         
    for(int i=0;i<Total;i++){
      Employee_file<< Employees[i].ID<< endl;
      Employee_file<< Employees[i].name<< endl;
      Employee_file<< Employees[i].position<< endl;
      Employee_file<< Employees[i].salary<< endl;
      Employee_file<< Employees[i].d<< endl;
      Employee_file<< Employees[i].phoneNumber<< endl;
      Employee_file<< Employees[i].address<< endl;
      
       }
     Employee_file.close();
    
}
product* ExtractProducts(product* products){
fstream Product_file;
    Product_file.open("Products.txt", ios::in);//do i need to open it here ?
    int Total=ProductsTotal();
    int i = 0;
   /* try {
           Product_file.open("Products.txt", ios::app);
            if (!Product_file.is_open())
                throw(FileEX);
        }
    catch (exception& ex){
            cout << ex.what() << endl;
    }*/

   while (i < Total)
    {
        Product_file >> products[i].productNum;
        Product_file >> products[i].prodName;
        Product_file>>products[i].DateofShipping;
        Product_file>> products[i].Price;
        Product_file>> products[i].NumItems;
        i++;
    }
    Product_file.close();
    return products;
 
}
void UpdateProductsFile(product* products, int& Total){
fstream Product_file;
    int i = 0;
   /* try {
        Product_file.open("Employees.txt", ios::in);
        if (!Product_file.is_open())
            throw(FileEX);
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
    } */
    Product_file.open("Products.txt", ios::out);         
    for(int i=0;i<Total;i++){
      Product_file<< products[i].productNum<< endl;
      Product_file<< products[i].prodName<< endl;
      Product_file<< products[i].DateofShipping<< endl;
      Product_file<< products[i].Price<< endl;
      Product_file<< products[i].NumItems<< endl;
         
      }
    Product_file.close();
    
}

//Main function of the program 
int main(){
int choice;
int pass=0;
pass=PasswordChecker();
if(pass==1){
    std::cout<<"Access granted to the system"<<endl; 
 
    //allocating memeory for the products container & extracting it from products file 
    int TotProd=ProductsTotal();
    product* Products=new product[TotProd];
    Products=ExtractProducts(Products);
    //allocating memory for the clients container & extracting it from the clients file 
    int TotClient=ClientsTotal();
    Client* Clients=new Client[TotClient];
    Clients=ExtractClients(Clients);
    //allocating memory for the employees container & extracting it from the employees file 
    int TotEmployee=EmployeesTotal();
    Employee* Employees=new Employee[TotEmployee];
    Employees=ExtractEmployees(Employees); 
    std::cout<<"Correct Password.Press any key to proceed\n"<<endl;     
    system("cls");
    std::cout <<"\t\t\t\t"<< "      *************************************************" << endl;
    std::cout << "\t\t\t\t"<<"      * Welcome To Our warehouse Data management System *" << endl;
    std::cout << "\t\t\t\t"<<"      *************************************************" <<endl;
    std::cout << "1. Login to the Products Database \n" << endl;  
    std::cout << "2. Login to the Clients  Database \n" << endl;
    std::cout << "3. Login to the Employees Database \n" << endl;
    std::cout <<"\t\t\t\t"<< "      ***************************************************"<<endl;
    std::cout << "Choose One: "<<endl;
    std::cin >> choice;
    switch(choice){
        int ChoProd;
        case 1 : 
        {
          std::cout<<"Select an option from 1 to 3"<<endl; 
          std::cout<<"1-Add a product "<<endl;
          std::cout<<"2-Update Price"<<endl; 
          std::cout<<"3-Update Stock options"<<endl;
          std::cout<<"your choice"<<endl;
          std::cin>>ChoProd;
            if(ChoProd==1){
                product* pro= new product();
                cin>>* pro;
                Products=pro->AddProduct(Products,TotProd);
                delete pro;
                
            }
            else if(ChoProd==2){
               int prodID=0;
               int newP=0;
               std::cout<<"enter ID of the product that you want to update"<<endl;
               std::cin>>prodID;
               product pro;
               pro.setProductID(prodID); 
               std::cout<<"Enter the new Price"<<endl;
               std::cin>>newP;
               pro.UpdatePrice(Products,TotProd,newP);
               std::cout<<"price has been updated"<<endl;
            }
            else if (ChoProd==3){
               int prodID=0;
               int newStock=0;
               int thirdchoice=0;
               std::cout<<"enter ID of the product that you want to update"<<endl;
               std::cin>>prodID;
               product pro;
               pro.setProductID(prodID); 
               std::cout<<"1-New arrival"<<endl;
               std::cout<<"2-Sold items "<<endl;
               cin>>thirdchoice;
               int newitems=0;    
               switch(thirdchoice){
                 case 1: 
                {   std::cout<<"enter the number of the new items"<<endl;
                    std::cin>>newitems;
                    pro.UpdateStock(Products,TotProd,newitems);
                 break;}

                 case 2:
                 {  std::cout<<"enter the number of the sold items"<<endl;
                    std::cin>>newitems;
                    pro.UpdateStock(Products,TotProd,(-1*newitems));
                 break;}  
                     
               } 
               
              }
            else{
               system("cls");
               int s;
               std::cout<<"Error! Wrong choice, press any key to go back to menu or any key to exit!"<<endl;
            
            }
        }
        break; 
        case 2:
        {
          int ChoCli=0;
          std::cout<<"Select an option from 1 to 2"<<endl; 
          std::cout<<"1-Add a new client "<<endl;
          std::cout<<"2-Calculate Loyalty and Discout points"<<endl; 
          std::cout<<"your choice"<<endl;
          std::cin>>ChoCli;
           if(ChoCli==1){
            Client Cli;
            cin>>Cli;
            Clients=Cli.AddClient(Clients,TotClient);         
           }
           else if(ChoCli==2){
            int CliID=0;
            std::cout<<"Enter the client's identification number"<<endl;  
            std::cin>>CliID;
            Client* Cli= new Client();
            Cli->setID(CliID);
            Cli->CalculateDiscountPoints(Clients,TotClient);
           }
           else{
            system("cls");
            int s;
            std::cout<<"Error! Wrong choice, press any key to exit!"<<endl;
           
           }
         break;
        }       
        case 3:
        {
          int EmplChoice=0;
          std::cout<<"Select an option from 1 to 6"<<endl; 
          std::cout<<"1-Add a new Employee "<<endl;
          std::cout<<"2-Update Position"<<endl; 
          std::cout<<"3-Update Salary"<<endl;
          std::cout<<"4-Update Phone Number"<<endl;
          std::cout<<"5-Update Address"<<endl;
          std::cout<<"6-Delete Employee"<<endl;
          std::cout<<"your choice"<<endl;
          std::cin>>EmplChoice;
          if(EmplChoice==1){
            Employee Emp;
            cin>> Emp;
            Employees=Emp.AddEmployee(Employees,TotEmployee);
                           
          }
          else if(EmplChoice==2){
           int EmpID=0;   
           std::string newpos;
           std::cout<<"enter ID of the employee that you are searching "<<endl;
           std::cin>>EmpID;
           Employee Emp;
           Emp.SetID(EmpID); 
           std::cout<<"enter the title of the new positon that they are filling "<<endl;
           std::cin>>newpos;
           //std::getline(cin, newpos)which one works ? 
           Emp.UpdatePosition(Employees,TotEmployee,newpos);                   
                             
          
          }
          else if(EmplChoice==3){
           int EmpID=0;   
           int newsalary=0;
           std::cout<<"enter ID of the employee that you are searching "<<endl;
           std::cin>>EmpID;
           Employee Emp;
           Emp.SetID(EmpID); 
           std::cout<<"enter the new salary that they are getting "<<endl;
           std::cin>>newsalary;
           Emp.UpdateSalary(Employees,TotEmployee,newsalary);                   
                            
          
          }
          else if(EmplChoice==4){
           int EmpID=0;   
           int PhoneNum=0;
           std::cout<<"enter ID of the employee that you are searching "<<endl;
           std::cin>>EmpID;
           Employee Emp;
           Emp.SetID(EmpID); 
           std::cout<<"enter the new phone number "<<endl;
           std::cin>>PhoneNum;
           Emp.UpdatePhone(Employees,TotEmployee,PhoneNum);                    
                            
          
          }
          else if(EmplChoice==5){
           int EmpID=0;   
           std::string newAddress=" ";
           std::cout<<"enter ID of the employee that you are searching "<<endl;
           std::cin>>EmpID;
           Employee Emp;
           Emp.SetID(EmpID); 
           std::cout<<"enter their new address "<<endl;
           std::cin>>newAddress;
           Emp.UpdateAddress(Employees,TotEmployee,newAddress);                   
                           
          
          }
          else if(EmplChoice==6){
           char Remove;
           int EmpID=0;   
           std::cout<<"enter ID of the employee that you removing "<<endl;
           std::cin>>EmpID;
           Employee* Emp= new Employee();
           Emp->SetID(EmpID); 
           std::cout<<"Are you sure you want to remove this employee(Y/N) ?"<<endl;
           Remove=getch();
           if(Remove=='Y'){
               Emp->DeleteEmployee(Employees,TotEmployee);
               delete Emp;
            }
           else{
               main();
            }
          }
        break;
        }       
    
    
    }   

    UpdateClientFile(Clients,TotClient);
    UpdateEmployeesFile(Employees,TotEmployee);
    UpdateProductsFile(Products,TotProd);
        
   }
    getch();
    return 0;
}

