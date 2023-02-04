
#define product_header
#include"Client.h"
#include<string.h>
#include<iostream>
#include<fstream>


using namespace std;

class  product{

int productNum;
std::string prodName;
std::string DateofShipping;
int NumItems;
int Price;

public:
product(std::string nameX,int NumX,string ShipX, int ItemsX,int PriceX){
    productNum=NumX;
    prodName=nameX;
    DateofShipping=ShipX;
    NumItems=ItemsX;
    Price=PriceX;
}
product(const product& p){
    *this=p;
}
product(){
    productNum=0;
    prodName=' ';
    DateofShipping="";
    NumItems=0;
    Price=0;
}

friend product* ExtractProducts(product* products);
friend void UpdateProductsFile(product* products, int& Total);

//setter
void setProductID(int x){
    productNum=x;
}
//SearchProducts
bool SearchName(product* Products,int Total){
bool flag=false;
for(int i=0;i<Total;i++){
   if(Products[i].prodName==prodName){
       flag=true;
       break;
   } 
   return flag;
  }
}
bool SearchID(product* Products,int Total){
bool flag=false;
for(int i=0;i<Total;i++){
   if(Products[i].productNum==productNum){
       flag=true;
       break;
   } 
  }
  return flag;
      
}
// Updating product Data
product* AddProduct(product* Products,int& Total){
bool flag=SearchID(Products,Total);
if(flag==false){
   product* newProducts= new product[Total+1];
   for(int i=0;i<Total;i++){
     newProducts[i]=Products[i];
   }
   newProducts[Total].prodName=prodName;
   newProducts[Total].productNum=productNum;
   newProducts[Total].DateofShipping=DateofShipping;
   newProducts[Total].Price=Price;
   newProducts[Total].NumItems=NumItems;
   delete[] Products;
   Products=newProducts;
   Total++;
   std::cout<<"Product is successfully added to Database";
}
else{
   std::cout<<"ERROR ! A Product is already registrated with this ID! Try another option"<<endl;
}  
  return Products ;
}

void UpdatePrice(product* Products,int Total,int newPrice){
int i;

for(i=0;i<Total;i++){
if (SearchID(Products,Total)){
  if(Products[i].productNum==productNum){
     Products[i].Price=newPrice;
     break;
  }
 }
}

std::cout<<"Product has been successfully updated"<<endl;

if(!SearchID(Products,Total)){
  std::cout<<"Error ! Product ID is not in the system !"<<endl;
}
}   

void UpdateStock(product* Products,int Total,int newSTock){
int i;
for(i=0;i<Total;i++){
if (SearchID(Products,Total)){
  if(Products[i].productNum==productNum){
     Products[i].NumItems=Products[i].NumItems+newSTock;
     break;
  }
 }
}
 std::cout<<"Number of available items for product number "<<Products[i].productNum<<" has been updated to "<<Products[i].NumItems<<endl;
    
 if(!SearchID(Products,Total)){
  std::cout<<"Error ! Product ID is not in the system !"<<endl;
}

 
}
friend ostream& operator << (ostream& os, const product & products ) {
		os <<"The Product Details "<<endl << "Product ID :" <<  products.productNum<< endl << "name :" << products.prodName  << endl << "Price :" <<  products.Price<< endl;
		os << "Date of shipping :" <<  products.DateofShipping << endl << "Number of items in stock " <<  products.NumItems<< endl;
        return os;

	}

friend istream& operator >> (istream& is, product & products) {

		
		cout << endl;	
		cout << "Product ID :";
		is >> products.productNum;
		cout << "Product name :";
		is >> products.prodName;
		cout << "Shipping date :";
		is >>  products.DateofShipping ;
		cout << "Number of Items:";
		is >>  products.NumItems;
		cout << "Product price :";
		is >>  products.Price;
		cout<<endl;
		return is;

	}



};
