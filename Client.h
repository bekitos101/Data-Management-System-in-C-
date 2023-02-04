#pragma once
#define Client_header
#include<iostream>
#include<string>
#include"person.h"


using namespace std;

class Client:public person{
int  SignDate;
bool subscribtion;
public:
Client(){
    name="";
    ID=0;
    d="";
    SignDate=0;
    subscribtion=false;
}

Client(const Client& C){
   ID=C.ID;
   name=C.name;
   d=C.d;
   SignDate=C.SignDate;
   subscribtion=C.subscribtion;
}

Client(std::string nameX,int IDx,string BirthX,int SignDateX,bool subscriptionX ):person(name,ID,d){
    SignDate=SignDateX;
    subscribtion=subscriptionX;

}
 ~Client(){/*default destructor*/}



friend Client* ExtractClients(Client* Clients);
friend void UpdateClientFile(Client* Clients, int& Total);


bool SearchID(Client* Clients,int Total){
int i;
bool flag=0;
for (i=0;i<=Total;i++){
    if(Clients[i].ID == ID){
         flag=1;
         break;
    }
 }
    return flag;
}

void setID(int IDx){
   ID=IDx;
}
//data editing mehods 
Client* AddClient(Client* Clients, int& Total)
{
    bool flag = SearchID(Clients, Total);
    if (flag == false)
    {
        Client* newClients = new Client[Total + 1];
        for (int i = 0; i < Total; i++)
            newClients[i] = Clients[i];
        newClients[Total].ID = ID;
        newClients[Total].name = name;
        newClients[Total].d = d;
        newClients[Total].SignDate = SignDate;
        newClients[Total].subscribtion = subscribtion;
        delete[] Clients;
        Clients = newClients;
        Total++;
        std::cout << "Client is successfully added to  the Database" << endl;
    }
    else
        std::cout << "ERROR ! This client is already registrated! with this ID" << endl;
  return Clients;
}


void CalculateDiscountPoints(Client* Clients,int Total){
bool flag=SearchID(Clients,Total);
for(int i=0;i<Total;i++){
int Discount=10; 
if(flag){
    
   // std::cout<<"client's identification "<<Clients[i].ID;
    std::cout<<"Client"<<Clients[i].name<<"has"<<Clients[i].SignDate<<"loyalty points"<<endl;
    if(Clients[i].SignDate>=1){
        std::cout<<"Congratulations on your first year with us !"<<"\n"<<endl;
        std::cout<<" you get"<<Discount<<"%"<<"Discount on your next purchase"<<"\n"<<endl;
    }
    else if(Clients[i].SignDate>=3){
        std::cout<<"We can't thank you enough for your loyalty!"<<endl;
        Discount=(Discount+SignDate)*5/2;
        std::cout<<" you get a "<<Discount<<"%"<<"Gift card on your next purchase";
    }
    
  }
  else{
       std::cout<<"ERROR! This client is not registrated in the system"<<"\n";
  }
  }

  }

// Overloading of << and >> to read/write clients data    
   friend ostream& operator << (ostream& os, const Client & Clients ) {
		os <<"The Clients Details "<<endl << "Client ID :" <<  Clients.ID<< endl << "name :" << Clients.name << endl << "subscribtion :" <<  Clients.subscribtion << endl;
		os << "Birthdate :" <<  Clients.d << endl << "signDate " <<  Clients.SignDate<< endl;
		
		
        return os;

	}
    friend istream& operator >> (istream& is, Client &Clients ) {

		
		cout << endl;
		cout << "Client ID :"<<endl;
		is >> Clients.ID;
		cout << "Client name :"<<endl;
		is >> Clients.name;
		cout << "Client subscribtion :"<<endl;
		is >> Clients.subscribtion;
		cout << "Client Birthdate :"<<endl;
		is >> Clients.d;
		cout<< "Sign Date:"<<endl;
		is >> Clients.SignDate;
		return is;

	}

 
   
};
