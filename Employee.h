#define Employee_header
#include"person.h"
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Employee:public person{
    
  std::string position;
  std::string address;
  int salary;
  int phoneNumber;

  public: 
  Employee(std::string nameX,int IDX,std::string dateX,std::string positionX,int salaryX,int phoneX,std::string AddressX):person(name,ID,d){
   position=positionX;
   salary=salaryX;
   phoneNumber=phoneX;
   address=AddressX;

}

  Employee(){
   ID=0;
   name="";
   d="";
   position="";
   salary=0;
   phoneNumber=0;
   address="";
}
  Employee(const Employee& E){
    ID=E.ID;
    name=E.name;
    position=E.position;
    salary=E.salary;
    phoneNumber=E.phoneNumber;
    d=E.d;
    address=E.address;

}
  ~Employee(){}
  


friend Employee* ExtractEmployees(Employee* Employees);
friend void UpdateEmployeesFile(Employee* Employees, int& Total);
friend void PrintArrayContent(Employee*Employees,int Total);


//ADD employees 
 Employee* AddEmployee(Employee* Employees,int& Total){
   bool flag=SearchEmployeeID(Employees,Total);
   if(flag==false){
   Employee* newEmployees= new Employee[Total+1];
   for(int i=0;i<Total;i++){
     newEmployees[i]=Employees[i];
   }
   newEmployees[Total].ID=ID;
   newEmployees[Total].name=name;
   newEmployees[Total].d=d;
   newEmployees[Total].position=position;
   newEmployees[Total].salary=salary;
   newEmployees[Total].phoneNumber=salary;
   newEmployees[Total].address=address;
   delete[] Employees;
   Employees=newEmployees;
   Total++;
   std::cout<<"Employee is successfully added to Database"<<endl;
}
else{
   std::cout<<"ERROR ! An employee is already registrated! with this ID"<<endl;
}
  return Employees ;
}


//Modify employee data
 bool SearchEmployeeID(Employee* employees,int Total){
   int i;
   bool flag=false;
   for (i=0;i<=Total;i++){
    if(employees[i].ID == ID){
         flag=true;
         break;
    }
 }
    return flag;
}

//Data management 
 void UpdatePosition(Employee* Employees,int Total, std::string newPosition){
int i;
for(i=0;i<Total;i++){
if (SearchEmployeeID(Employees,Total)){
  if(Employees[i].ID=ID){
     Employees[i].position=newPosition;
     std::cout<<"Congratulations on the new position ! Database updated"<<endl;
     break;
  }

 }
}
if(!SearchEmployeeID(Employees,Total)){
     std::cout<<"Employee Identification not found in the system"<<endl;
     
}
}

 void UpdateSalary(Employee* Employees, int Total, int newSalary){
int i;
bool flag=SearchEmployeeID(Employees,Total);
for(i=0;i<Total;i++){
if (flag){
  if(Employees[i].ID=ID){
     Employees[i].salary=newSalary;
     std::cout<<"Salary updated in the system"<<endl;
     break;
   }
  }
 }
 if(!flag){
    std::cout<<"Employee Identification not found in the system"<<endl;
 }
}

void UpdatePhone(Employee* Employees,int Total,int newPhone){
bool flag=SearchEmployeeID(Employees,Total);
int i;
for(i=0;i<Total;i++){
if (flag){
  if(Employees[i].ID=ID){
     Employees[i].salary=newPhone;
     std::cout<<"Phone number of employee "<<Employees[i].ID<<"has been updated"<<endl;
     break;
   }
  }
 }
 if(!flag){
    std::cout<<"Employee Identification not found in the system"<<endl;
 }
}

void UpdateAddress(Employee* Employees,int Total,std::string newAddress){
bool flag=SearchEmployeeID(Employees,Total);
int i;
for(i=0;i<Total;i++){
if (flag){
  if(Employees[i].ID=ID){
     Employees[i].address=newAddress;
     std::cout<<"Employee's address "<<Employees[i].ID<<"has been updated"<<endl;
     break;
   }
  }
 }
 if(!flag){
    std::cout<<"Employee Identification not found in the system"<<endl;
 }
}

void DeleteEmployee(Employee* Employees,int &Total){
bool flag=SearchEmployeeID(Employees,Total);
int i;
int j=0;
for(int i=0;i<=Total;i++){
   if(flag){
     Employee* newEmployees=new Employee[Total-1];
     for(i=0,j=0;i<Total;i++){
     if(Employees[i].ID!=ID){
         newEmployees[j]=Employees[i];
        j++;
      }
     delete[] Employees;
     Employees=newEmployees;
     Total--; 
   }
  }
 }
 std::cout<<"Employee has been deleted from the system"<<endl;
}

//overloading of >> and << operators to read/write the employees data 

friend ostream& operator << (ostream& os, const Employee & Employees ) {
		os <<"The Employee Details "<<endl << "Employee ID :" <<  Employees.ID<< endl << "name :" <<  Employees.name << endl << "position :" <<  Employees.position << endl;
		os << "Date of brith :" <<  Employees.d << endl;
        os << "Address :" <<  Employees.address << endl << "Salary " <<  Employees.salary<< endl;
		os << "phone Number :" <<  Employees.phoneNumber << endl;
        
		
        return os;

	}
friend istream& operator >> (istream& is, Employee & Employees ) {

		
		cout << endl;
		
		cout << "Employee ID :";
		is >> Employees.ID;
		cout << "Employee name :";
		is >> Employees.name;
		cout << "Employee birthdate:";
		is >> Employees.d;
     cout << "Employee position :";
		is >> Employees.position;
		cout << "Employee salary :";
		is >> Employees.salary;
		cout<< "Employee address:";
		is >> Employees.address;
		cout << "phone number:";
		is >> Employees.phoneNumber;
		
		return is;

	}

  //setter
  void SetID(int IDx){ID=IDx;}                       



};

