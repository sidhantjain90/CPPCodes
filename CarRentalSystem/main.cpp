#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <iomanip>



using namespace std;

// Base Class for Customers
class Customer{

	public:
		string customerName;
		string carModel;
		string carNumber;
		char data;

};

// Class for Welcome screen
class Welcome{

	public:
		void welcomeScreen(){
			ifstream read("welcome.txt");

			if(!read){
				std::cout << "Cannot open welcome file!" << '\n';
			}
			string str;
			while(read){
				getline(read,str);
				if(read){
					cout<<str<<endl;
				}
			}
			read.close();
			sleep(2);
			cout<<"\n \t \t Starting Program, Please wait..."<<endl;
			sleep(3);
			system("clear");
		}
};

// Class for Renting car
class Rent : public Customer{

	public:
		int days=0;
		int rentalFee=0;

		void data(){
			cout<<"\n \t \t Please enter your name: ";cin>>customerName;
			cout<<endl;

			system("clear");

			cout <<"\n \t \t Hi, "<<customerName<<"."<<endl;

			do {
				cout<<"\n \t \t Please select a Car"<<endl;
				cout<<"\n \t \t Enter A for Tesla 2011"<<endl;
				cout<<"\n \t \t Enter B for Hyundai 2015"<<endl;
				cout<<"\n \t \t Enter C for Ford 2017"<<endl;
				cout<<endl;

				cout<<"\n \t \t Choose a car from the above options: ";cin>>carModel;
				cout<<endl;

				if(carModel=="A"){
					system("clear");

					cout<<"You have chosen Tesla Model 2011"<<endl;
					ifstream readA("A.txt");
					string str;
					while(readA){
						getline(readA,str);
						if(readA){
							cout<<str<<endl;
						}
					}
					sleep(2);
					readA.close();
				}

				if(carModel=="B"){
					system("clear");

					cout<<"You have chosen Hyundai model 2015"<<endl;
					ifstream readB("B.txt");
					string str;
					while(readB){
						getline(readB,str);
						if(readB){
							cout<<str<<endl;
						}
					}
					sleep(2);
					readB.close();
				}

				if(carModel=="C"){
					system("clear");

					cout<<"You have chosen Ford model 2017"<<endl;
					ifstream readC("C.txt");
					string str;
					while(readC){
						getline(readC,str);
						if(readC){
							cout<<str<<endl;
						}
					}
					sleep(2);
					readC.close();
				}

			} while(carModel!="A" && carModel!="B" && carModel!="C");

			cout<<"-------------------------------"<<endl;
			cout<<"Please provide the following information: ";
			cout<<"Please select a car No.: ";cin>>carNumber;
			cout<<"Number of days you wish to rent the car: ";cin>>days;
			cout<<endl;

		}

		void calculate(){
			sleep(1);
			system("clear");
			cout<<"Calculating rent. Please wait... "<<endl;
			sleep(2);
			if(carModel=="A"||carModel=="a"){
				rentalFee=days*56;
			}
			if(carModel=="B"||carModel=="b"){
				rentalFee=days*60;
			}
			if(carModel=="C"||carModel=="c"){
				rentalFee=days*75;
			}
		}

		void showRent(){
			cout<<"\n\t\t               Car Rental - Customer Invoice    "<<endl;
			cout<<"\t\t    /////////////////////////////////////////////////////"<<endl;
			cout<<"\t\t    | Invoice No.: "<<"---------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
			cout<<"\t\t    | Customer Name: "<<"-------------------|"<<setw(10)<<customerName<<" |"<<endl;
			cout<<"\t\t    | Car Model: "<<"-----------------------|"<<setw(10)<<carModel<<" |"<<endl;
			cout<<"\t\t    | Car No.: "<<"-------------------------|"<<setw(10)<<carNumber<<" |"<<endl;
			cout<<"\t\t    | Number of days: "<<"------------------|"<<setw(10)<<days<<" |"<<endl;
			cout<<"\t\t    | Your Rental Amount: "<<"--------------|"<<setw(10)<<rentalFee<<" |"<<endl;
			cout<<"\t\t    | Caution Money: "<<"-------------------|"<<setw(10)<<"0"<<" |"<<endl;
			cout<<"\t\t    | Advanced: "<<"------------------------|"<<setw(10)<<"0"<<" |"<<endl;
			cout<<"\t\t    ______________________________________________________________"<<endl;
			cout<<"\n";
			cout<<"\t\t    | Total Rental Amount is: "<<"----------|"<<setw(10)<<rentalFee<<" |"<<endl;
			cout<<"\t\t    ______________________________________________________________"<<endl;
			cout<<"\t\t    # This is a computer generated invoice and does not"<<endl;
			cout<<"\t\t    require an authorized signature #"<<endl;
		}

};

// Login function
bool login(){

	string pass="";
	bool success;

	cout<<"\n \t \t Login with your password"<<endl;

	cout<<"\n \t \t Enter your password: ";cin>>pass;

	if(pass == "pass"){
		system("clear");
		cout<<"Acess Granted!"<<endl;
		success = true;
	}else{
		cout<<"OOPS!!!"<<endl;
		sleep(2);
		system("clear");
		cout << "Try Again!" << endl;

		success = false;

		login();
	}
	return success;

}


int main(){

	Welcome wc;
	wc.welcomeScreen();

	bool success = login();

	if(success){
		Rent rentable;
		rentable.data();
		rentable.calculate();
		rentable.showRent();
	}

  return 0;
}
