#pragma once
#include<string>
#include<iostream>
#define person_header


using namespace std;

class person
{protected:
    int ID;
	std::string name;
    std::string d;	
public:

    person(std::string Namex,int IDx,std::string Dx ):name(Namex),ID(IDx),d(Dx){}
    person(){
  
    name="";
    ID=0;
	d="00/00/00000";
 
   
   }
   person(const person& p){
      ID=p.ID;
	  name=p.name;
	  d=p.d; 
   }
 ~person(){}
};
