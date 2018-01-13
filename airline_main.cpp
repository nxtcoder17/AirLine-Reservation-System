#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cerrno>
using namespace std;

class AIRLINE
{
/****************************************
	Ticket Booking Requirements
******************************************/
	char name[20],email[30],address[20],departure[15],arrival[15],sex,phone[11];
	int age,bookingId;
	char passport[15];

	int userFlightNo;

	char date[15];     // Date Variable
	char *locations[6];
/*****************************************
 	Flight Management Requirements
*******************************************/
	char flightName[30] , seatNo[5] , flightDate[10] , travelClass[10];
	int seatEconomy , seatBusiness , seatPremium;
	float fareEconomy , fareBusiness , farePremium;
	int flightNo;
	char flightOrigin[15] , flightDestination[15];

public :
	int id; 		// A General Variable
	//Settings the Parameters as per the User's INPUT
	AIRLINE () {
		id = 0;
		locations [0] = (char *)"PATNA" ;
		locations [1] = (char *)"AMRITSAR" ; 
		locations [2] = (char *)"BENGALURU" ;
	   	locations [3] = (char *)"NEW DELHI" ;
	   	locations [4] = (char *)"MUMBAI" ;
		locations [5] = (char *)"CHANDIGARH" ;
	}

                
    void printTicket();
	int locationsMenu();
	void makeQueryString(int);
	int fareCalculator(int , char);
	void setDate(int);
    int checkAvailablity();

	void setName();
	void setEmail();
	void setAddress();
	void setPhone();
	void setDeparture();
	void setArrival();
	void setAge();
	void setSex();
	void setPassport();
	void setBookingId();
	void setUserFlightNo();

	//Getters
	char * getName();
	char * getEmail();
	char * getAddress();
	char * getDate();
	char * getDeparture();
	char * getArrival();
	char getSex();
	int getAge();
	char * getPhone();
	int getBookingId();
	char * getPassport();
	int getUserFlightNo();

	void disAll();

	// Flight Management
	
	void setFlightName();
	void setFlightNo();
	void setSeatNo();

    void setSeatEconomy(int);
    void setSeatBusiness(int);
    void setSeatPremium(int);

	void setFlightOrigin();
	void setFlightDestination();
	void setFare();
	char setTravelClass();

	void decSeatNum(char , int);
    void incSeatNum(char , int);

	void disFlightAll();

	char * getFlightName();
	int getFlightNo();
	char * getSeatNo();
	int getSeatClass(char);
	char * getFlightDate();
	char * getFlightOrigin();
	char * getFlightDestination();
	int getFare(char);
	char * getTravelClass();
    char getTravelClassChar();
    int getSeatEconomy();
    int getSeatBusiness();
    int getSeatPremium();

    // General Functions Required for Seat
    //void setId();
    int getId(){ return id;}
};

int AIRLINE :: locationsMenu()
{
loc:
	cout << "\t1. Patna\n";
	cout << "\t2. Amritsar\n";
	cout << "\t3. Bengaluru\n";
	cout << "\t4. New Delhi\n";
	cout << "\t5. Mumbai\n";
	cout << "\t6. Chandigarh\n";

	cout << "Please Input Your Choice Number :-  ";
	int n;
    cin >> n;

	if (n < 1 || n > 6) {
		cout << "You entered an invalid choice , Please input a valid choice\n";
		goto loc;
	}

	return n - 1;
}

void AIRLINE :: setName()
{
enter:
	cout << "Enter Your Name :- ";
	cin.get();
	cin.getline(name,20);

	int i = 0;
    int count = 0;
	while (name[i] != '\0')
	{
		if ((name[i] >= 65 && name[i] <=90) || (name[i] >= 97 && name[i] <= 122))
		{}
		else if (name[i] >=48 && name[i] <= 57)
		{
			cout << "\t\t/////////////////////////////////////////////////////////////////////\n";
			cout << "\t\t///You entered an invalid character in name                       ///\n";
			cout << "\t\t///Note :- Use Only [Alphabets] and [Space] are allowed in name   ///\n";
			cout << "\t\t/////////////////////////////////////////////////////////////////////\n";
			goto enter;
		}
        count++;
		i++;
	}

    if (count < 5) { 
        cout << "Name could not be less than 5 Characters . Please Try Again\n";
        goto enter;
    }
}

void AIRLINE :: setEmail()
{
email :
	cout << "Enter Your Email Address :- ";
	cin.getline(email,30);

	int i = 0;
	int counter = 0;
    int counter_2 = 0;
	while (email[i] != '\0')
	{
        // Adding Checking for @ 
		if ((int)email[i] == 64)
			counter++;
		i++;
	}
    i = 0;
    while (email[i] != '\0') {
        // Checking for . (period) in Email Address
        if((int)email[i] == 46)
            counter_2++;
        i++;
    }
	if(counter =! 1 || counter_2 != 1)
	{
		cout << "\t\tPlease enter a Valid Email Address\n";
		goto email;
	}

}

void AIRLINE :: setAddress()
{
	cout << "Enter Your Permanent Address :- ";
	cin.get();
	cin.getline(address,20);
}

void AIRLINE :: setDate(int parameter)

{
	int dd , mm , yy;
	cout << "Enter the Date of Journey :\n";
dd_re:
	cout << "   Day [DD] : ";
	cin >> dd;

	if (dd < 0 || dd > 31) {
		cout << "You Entered an invalid date . Please Try Again\n";
		goto dd_re;
	}
mm_re:
	cout << " Month [MM] : ";
	cin >> mm;
	if (mm == 2 && dd > 28) {
		cout << "February , 2017 has only 28 Days . Please enter the date again\n";
		goto dd_re;
	}
	if (mm < 0 ||  mm > 12) {
		cout << "Months are in range [1 - 12] only , Please make a correct choice \n";
		goto mm_re;
	}
yy_re:
	cout << "Year [YYYY] : ";
	cin >> yy;

	if (yy != 2017) {
		cout << "You can only book tickets for current year . Please make Correct Choice \n";
		goto yy_re;
	}

	char separator[2];
	separator[0] = (char) 47; // ASCII Code for '/' -> 47
	separator[1] = '\0';

	char DD[3];
	int dd_u = dd % 10;
	int dd_t = dd / 10;
	DD[0] = (char)dd_t + '0';
	DD[1] = (char)dd_u + '0';
	DD[2] = '\0';

    if (parameter == 0) {
	    strcpy(date , DD);
	    strcat(date , separator);
    }
    else {
	    strcpy(flightDate , DD);
	    strcat(flightDate , separator);
    }


	char MM[3];
	int mm_u = mm % 10;
	int mm_t = mm / 10;
	MM[0] = (char) mm_t + '0';
	MM[1] = (char) mm_u + '0';
	MM[2] = '\0';

    if (parameter == 0) {
	    strcat(date , MM);
	    strcat(date , separator);
    }
    else {
	    strcat(flightDate , MM);
	    strcat(flightDate , separator);
    }

	int yy_u = yy % 10;
	yy = yy / 10;
	int yy_t = yy % 10;
	yy = yy / 10;
	int yy_h = yy  % 10;
	yy = yy / 10;
	int yy_th = yy;

	char YY[5];
	YY[0] = (char) yy_th + '0';
	YY[1] = (char) yy_h + '0';
	YY[2] = (char) yy_t + '0';
	YY[3] = (char) yy_u + '0';
	YY[4] = '\0';

    if (parameter == 0) 
	    strcat(date , YY);
    else
        strcat(flightDate , YY);
}

void AIRLINE :: setPhone()
{
phone:
	cout << "Enter your Phone Number :- ";
	cin >> phone;

    if (strlen(phone) != 10 ) {
        cout << "You entered an invalid phone number . Please Try Again \n";
        goto phone;
    }
    if (phone[0] == '9' || phone[0] == '8' || phone[0] == '7') { }
    else {
        cout << "You entered an invalid phone number . Please Try Again \n";
        goto phone;
    }
	int i = 0;
	int count = 0;
	while (phone[i] >= 48 && phone[i] <= 57 && phone[i] != '\0') {
		count++;
		i++;
	}
	if (count != strlen(phone)) 
		goto phone;
}

void AIRLINE :: makeQueryString(int p)
{
	int index = locationsMenu();
	char * ptr = locations[index];
	int len = strlen(locations[index]);
	char place[len + 1];
	for(int i = 0 ;  i <= len ; i++) {
		if (i == len)
			place[i] = '\0';
		else
			place[i] = (char)*(ptr + i);
	}
	
	switch (p) {
		case 1:
			strcpy(departure , place);
			break;
		case 2:
			strcpy(arrival , place);
			break;
		case 3:
			strcpy(flightOrigin , place);
			break;
		case 4:
			strcpy(flightDestination , place);
	}

}
void AIRLINE :: setDeparture()
{
	cout << "Please select  your City of Departure : \n";
	makeQueryString(1); // 1 to set Departure
}

void AIRLINE :: setArrival()
{
	cout << "Please select your City of Arrival :\n";
	makeQueryString(2); // 2 to set Arrival
}

void AIRLINE :: setAge()
{
age_re:
	cout << "Enter your Age :- ";
	cin >> age;

    if (age < 0 || age > 100) {
        cout << "Your age doesn't match as per the Flight Standards [01 - 99]. Please enter your valid age\n";
        goto age_re;
    } 
}

void AIRLINE :: setSex()
{
sex_re:
	cout << "Enter Your Sex (M/F):- ";
    char tmp;
	cin >> tmp;
    
    if( (tmp == 'M' || tmp == 'm') || (tmp == 'f' ||tmp == 'F')) { }
    else {
        cout << "\t\t\tYou are entering an invalid choice . Please make a correct choice\n";
        goto sex_re;
    }
    sex = tmp;
}

void AIRLINE :: setBookingId()
{
	fstream f("booking.dat");
	if (errno != 0) 
		bookingId = 1231100;
	else {
		AIRLINE x;
		f.read((char *) &x , sizeof(x));
		while (f.eof() != 1) {
			f.read((char *) &x , sizeof(x));
		}
		bookingId = x.getBookingId() + 1;
	}
	f.close();

	cout << "Booking Id : - " << bookingId << endl;
}

void AIRLINE :: setPassport()
{
password_re:
	cout << "Enter your Passport Number :- ";
	char tmp[15];
    cin >> tmp;

    int i = 0;
    int count = 0;
    while (tmp[i] != '\0') {
        count++;
        i++;
    }

    if (count < 10) {
        cout << "\t\t\tPassport Number can't be less than 10 characters . Please enter correct info\n";
        goto password_re;
    }
    strcpy(passport , tmp);
}

void AIRLINE :: setUserFlightNo() {
userFlight_re:
	cout << "Enter the Flight Number for which you want to book : ";
	cin >> userFlightNo;

	AIRLINE check;
	fstream fun("flights.dat");
	fun.read((char *)&check , sizeof(check));
	int flag = 0;
	while(fun.eof() != 1) {
		if (userFlightNo == check.getFlightNo()) {
			flag = 1;
			break;
		}
		else
			flag = 0;
		fun.read((char *)&check , sizeof(check));
	}
	fun.close();
	if (flag == 0) {
		cout << "You entered an invalid Flight Number , Please try again\n";
		goto userFlight_re;
	}
}

/********************************************************************
	//Accessing the Parameters for different operations
************************************************************************/
char * AIRLINE ::  getName()
{
	return name;
}

char * AIRLINE :: getEmail()
{
	return email;
}

char * AIRLINE :: getAddress()
{
	return address;
}

char * AIRLINE :: getDate()
{
	return date;
}

char AIRLINE :: getSex()
{
	return sex;
}

char * AIRLINE :: getPhone()
{
	return phone;
}

char * AIRLINE :: getDeparture()
{
	return departure;
}

char * AIRLINE :: getArrival()
{
	return arrival;
}

int AIRLINE :: getBookingId()
{
	return bookingId;
}

char * AIRLINE :: getPassport() 
{
	return passport;
}

int AIRLINE :: getUserFlightNo() {
	return userFlightNo;
}

// ################         Display all Function for displaying all the SET parameters   #######################################
void AIRLINE :: disAll()
{
	cout.setf(ios::left);
	cout <<setw(10)<<getBookingId()<<setw(15)<<getName()<<setw(12)<<getDate()<<setw(15)<<getUserFlightNo()<<setw(15)<<getPhone()<<setw(20)<<getEmail()<<setw(12)<<getTravelClass()<<setw(12)<<getPassport()<<setw(8)<<getSeatNo()<<endl;
}

//
// Method definitions for Flight Part
// ------------------------------------
void AIRLINE :: setFlightName()
{
    int flag ;
name_re:
	cout << "Enter the Flight Name : ";
	cin.get();
    char tmp[30];
	cin.getline(tmp , 30);

    AIRLINE a;
    flag = 0;
    fstream f("flights.dat");
    if (errno != 0) {
        strcpy(flightName , tmp);
    }
    else {
        f.seekg(0 , ios::beg);
        f.read((char *) &a , sizeof (a));
        while (f.eof() != 1) {
            if (strcmp(tmp , a.getFlightName()) == 0) {
                cout << "Flight Name Already exists\n";
                flag = 1;
                goto name_re;
            }
            f.read((char *) &a , sizeof (a));
        }
        if (flag == 0) {
            strcpy(flightName , tmp);
        }
        f.close();
    }
    return;
}

void AIRLINE :: setFlightNo()
{
re_enter:
	cout << "Enter the Flight Number : ";
	int temp;
	cin >> temp;

    AIRLINE tmp;
	fstream fl_id;
	fl_id.open("flights.dat" ,ios::in|ios::out|ios::binary|ios::app);
	fl_id.seekg(0,ios::beg);
    fl_id.read((char *)&tmp , sizeof(tmp));
	while (fl_id.eof() != 1) {
		if (temp == tmp.getFlightNo()) {
			cout << "Flight No. already exists in the database . Please Try Again\n";
			goto re_enter;
		}
        fl_id.read((char *)&tmp , sizeof(tmp));
	}
	fl_id.close();
	flightNo = temp;
}

void AIRLINE :: setSeatEconomy(int p) {
    if (p == 0) {
        cout << "No. of Seats for Economy : ";
        cin >> seatEconomy;
    }
    else
        seatEconomy = p;
}

void AIRLINE :: setSeatBusiness(int p) {
    if (p == 0) {
        cout << "No. of Seats for Business : ";
        cin >> seatBusiness;
    }
    else 
        seatBusiness = p;
}

void AIRLINE :: setSeatPremium(int p) {
    if (p == 0) {
        cout <<"No. of Seats for Premium : ";
        cin >> seatPremium;
    }
    else
        seatPremium = p;
}

void AIRLINE :: setSeatNo()
{
    AIRLINE tmp;
	fstream f_id("booking.dat");
    if (errno != 0)
        id = 1;
    else {
        f_id.read((char *)&tmp , sizeof(tmp));
        while (f_id.eof() != 1) {
            f_id.read((char *)&tmp , sizeof(tmp));
        }
        id = tmp.getId() + 1;
    }
    f_id.close();

    int id_u = id % 10;
    int id_t = id / 10;
   

    char id_str[5];
    id_str[0] = (char)id_t + '0';
    id_str[1] = (char)id_u + '0';
    id_str[2] = '\0';

	if (id <= 20)
		strcat(id_str , "A");	
	else if (id <= 40)
		strcat(id_str , "B");
	else if (id <= 60)
		strcat(id_str , "C");
	else if (id <= 80)
		strcat(id_str , "D");
	else if (id <= 100)
		strcat(id_str , "E");
	else if (id <= 120)
		strcat(id_str , "F");

	strcpy(seatNo , id_str);
    return;
}

void AIRLINE :: setFlightOrigin()
{
	cout << "Choose the Origin Place for Flight :\n";
	cout << "------------------------------------\n";
	makeQueryString(3); // 3 to set Flight Origin
}

void AIRLINE :: setFlightDestination()
{
	cout << "Select the Destination for Flight\n";
	cout << "---------------------------------\n";
	makeQueryString(4); // 4 to set Flight Destination
}

void AIRLINE :: setFare()
{
	cout << "Fare for Economy Class : ";
	cin >> fareEconomy;
	cout << "Fare for Business Class : ";
	cin >> fareBusiness;
	cout << "Fare for Premium Class : ";
	cin >> farePremium;
	cout << "\nThank You , Fare List has been successfully updated\n";
}

char AIRLINE :: setTravelClass()
{
stc:
	cout << "Choose your Travelling Class\n";
	cout << "1. Economy Class\n";
	cout << "2. Business Class\n";
	cout << "3. Premium Class\n";

	cout << "Enter your choice : ";
	int book;
	cin >> book;

	switch(book) {
		case 1:
			strcpy(travelClass , "Economy");
			break;
		case 2:
			strcpy(travelClass , "Business");
			break;
		case 3:
			strcpy(travelClass , "Premium");
			break;
		default:
			cout << "You entered an invalid choice . Try Again \n";
			goto stc;
	}
	if (book == 1) 
		return 'E';
	if (book == 2)
		return 'B';
	if (book == 3)
		return 'P';
}
void AIRLINE :: decSeatNum(char ch , int flNo) {
    fstream file;
    fstream file_tmp;
    file.open("flights.dat",ios::in|ios::out|ios::app|ios::binary);
    file_tmp.open("temp.dat",ios::in|ios::out|ios::app|ios::binary);

    AIRLINE tmp;
    file.seekg(0,ios::beg);
    file.read((char *) &tmp , sizeof(tmp));
    while(file.eof() != 1) {
        if (flNo == tmp.getFlightNo()) {
            if (ch == 'E') {
                tmp.setSeatEconomy(tmp.getSeatEconomy() - 1);
            }
            else if (ch == 'B') {
                tmp.setSeatBusiness(tmp.getSeatBusiness() - 1);
            }
            else if (ch == 'P') {
                tmp.setSeatPremium(tmp.getSeatPremium() - 1);
            }
            file_tmp.write((char *)&tmp , sizeof(tmp));
            file.read((char *) &tmp , sizeof(tmp));
        }
        else {
            file_tmp.write((char *) & tmp , sizeof (tmp));
            file.read((char *) &tmp , sizeof(tmp));
        }
    }
    file.close();
    system("rm flights.dat");
    system("mv temp.dat flights.dat");
}

void AIRLINE :: incSeatNum(char ch , int flNo) {
    fstream file;
    fstream file_tmp;
    file.open("flights.dat",ios::in|ios::out|ios::app|ios::binary);
    file_tmp.open("temp.dat",ios::in|ios::out|ios::app|ios::binary);

    AIRLINE tmp;
    file.seekg(0,ios::beg);
    file.read((char *) &tmp , sizeof(tmp));
    while(file.eof() != 1) {
        if (flNo == tmp.getFlightNo()) {
            if (ch == 'E') {
                tmp.setSeatEconomy(tmp.getSeatEconomy() + 1);
            }
            else if (ch == 'B') {
                tmp.setSeatBusiness(tmp.getSeatBusiness() + 1);
            }
            else if (ch == 'P') {
                tmp.setSeatPremium(tmp.getSeatPremium() + 1);
            }
            file_tmp.write((char *)&tmp , sizeof(tmp));
            file.read((char *) &tmp , sizeof(tmp));
        }
        else {
            file_tmp.write((char *) & tmp , sizeof (tmp));
            file.read((char *) &tmp , sizeof(tmp));
        }
    }
    file.close();
    system("rm flights.dat");
    system("mv temp.dat flights.dat");
}
//################################################################################
char * AIRLINE :: getFlightName()
{
	return flightName;
}
int AIRLINE :: getFlightNo()
{
	return flightNo;
}

char * AIRLINE :: getSeatNo()
{
	return seatNo;
}

/*int AIRLINE :: getSeatClass(char x) 
{
	if (x == 'E')
		return seatEconomy;
	else if (x == 'B')
		return seatBusiness;
	else if (x == 'P')
		return seatPremium;
}

*/

int AIRLINE :: getSeatEconomy() { return seatEconomy;}
int AIRLINE :: getSeatBusiness() { return seatBusiness;}
int AIRLINE :: getSeatPremium() {return seatPremium;}

char * AIRLINE :: getFlightDate()
{
	return flightDate;
}

char * AIRLINE :: getFlightOrigin()
{
	return flightOrigin;
}

char * AIRLINE :: getFlightDestination()
{
	return flightDestination;
}

int AIRLINE :: fareCalculator(int flNo , char trClass) {
	int fare = 0;
	AIRLINE temp;
	fstream fareCal("flights.dat");
	fareCal.read((char *)&temp , sizeof(temp));
	while (fareCal.eof() != 1) {
		if (flNo == temp.getFlightNo()) {
			fare = temp.getFare(trClass);
		}
		fareCal.read((char *)&temp , sizeof(temp));
	}
	fareCal.close();
	return fare;
}
int AIRLINE :: getFare(char x)
{
	if (x == 'E')
		return fareEconomy;
	else if (x == 'B')
		return fareBusiness;
	else if (x == 'P')
		return farePremium;
}

char * AIRLINE :: getTravelClass()
{
        return travelClass;
}

char AIRLINE :: getTravelClassChar() {
    if (strcmp(travelClass , "Economy") == 0)
        return 'E';
    else if (strcmp(travelClass , "Business") == 0)
        return 'B';
    else if (strcmp(travelClass , "Premium") == 0)
        return 'P';
}
//disFlightAll
void AIRLINE :: disFlightAll()
{
	cout.setf(ios::left);
    cout<<setw(15)<<flightNo<<setw(25)<<flightName<<setw(12)<<flightDate<<setw(15)<<flightOrigin<<setw(15);
	cout<<flightDestination<<setw(5)<<getSeatEconomy()<<setw(5)<<getSeatBusiness()<<setw(5)<<getSeatPremium()<<endl;
}

//################################################################################################################
//
//################################################################################################################
// Various Fuctions which are called in the main() function below
int MENU()
{
    system("clear");
    cout <<"\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t**********************************************************************\n";
	cout << "\t\t\t               Welcome to PHENOMENAL AIRLINE SERVICES   \n";
	cout << "\t\t\t**********************************************************************\n";

    cout <<endl;
	cout << "\t\t\t\t\tPlease Choose from the following MENU\n";
	cout << "\t\t\t\t\t-------------------------------------\n";
	cout << "\t\t\t\t\t1. BOOKING\t\t2. FLIGHT_DETAILS\n";
	cout << "\t\t\t\t\t3. SEARCH\t\t4. MODIFY\n";
	cout << "\t\t\t\t\t5. CANCELLATION\t\t6. PASSENGER'S LIST\n";
    cout << "\t\t\t\t\t7. PRINT TICKET\t\t8. EXIT\n";

	int choice;
	cout << "\n\t\t\t\t\t\tEnter Your Choice :- ";
	cin >> choice;

	if(choice < 1 || choice > 8)
	{
        system("clear");
		cout << "\t\tYou entered an invalid choice . Please choose Again \n\n";
		return 0;
	}
	else
		return choice;
}

void disFormat()
{
	cout <<endl;
	cout.setf(ios::left);
	cout<<setw(10)<<"Book. ID"<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(15)<<"Flight Id"<<setw(15)<<"Phone"<<setw(20)<<"Email"<<setw(12)<<"Class"<<setw(12)<<"Passport"<<setw(8)<<" Seat "<<endl;
	cout<<setw(10)<<"--------"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(15)<<"---------"<<setw(15)<<"-----"<<setw(20)<<"-----"<<setw(12)<<"-----"<<setw(12)<<"--------"<<setw(8)<<"------"<<endl;
}

void disFlightFormat()
{
    cout <<endl;
    cout.setf(ios::left);
    cout<<setw(15)<<"Flight No."<<setw(25)<<"Flight Name"<<setw(12)<<"Date"<<setw(15)<<"Origin"<<setw(15)<<"Destination"<<setw(5)<<" E "<<setw(5) << " B " <<setw(5) << " P " << endl;
    cout<<setw(15)<<"----------"<<setw(25)<<"-----------"<<setw(12)<<"----"<<setw(15)<<"-------"<<setw(15)<<"----------"<<setw(5)<<"---"<<setw(5) << "---" <<setw(5) << "---" << endl;
}

char exitFlightFormat() 
{
	char ch;
	cout << "Press 'r' to return to the Flights Portal Menu or 'q' to quit\n";
	cout << "\tPress any other key to go to Home Page\n";
	cin >> ch;

	return ch;
}

int exitFormat()
{
	char ch;
	cout << "\tPress 'q'/'Q' to quit or any other key to got back to Home Screen\n";
	cin >> ch;

	if(ch == 'Q' || ch == 'q')
		exit(EXIT_FAILURE);
	else
		return 1;
}

void password() {
    cout << "You need to enter your Password to continue from here onwards\n";
    cout << "Please enter Carefully , you will only get 3 chances\n";
    int chances = 3;

    //char default_Password[15] = "phenomenal";
pass_re:
    cout << "Enter your Password : ";
    char id[15];
    cin >> id;

    if (strcmp(id , "phenomenal") == 0) {
        cout << "Login Successful\n";
        return;
    }
    else {
        --chances;
        if (chances == 0){
            cout << "You entered Wrong Password 3 times.\n";
            cout << "Terminating the program\n";
            exit(EXIT_FAILURE);
        }
        cout << "\t\t\t! Wrong Password . Please Try Again\n";
        goto pass_re;
    }
}

void AIRLINE :: printTicket() {
    cout << "\t\t\t###################################################################################\n";
    cout << "\t\t\t                           PHENOMENAL AIRLINE SERVICES                            \n";
    cout << "\t\t\t---------------------------------------------------------------------------------  \n";
    cout << "\t\t\t"<<getTravelClass()<<" Class                                             \n";
    cout << "\t\t\t           Name                                               BookingID           \n";
    cout << "\t\t\t      --------------                                        ----------------       \n";
    cout << "\t\t\t        "<<getName()<<"                                   \t\t"<<getBookingId()<<" \n";
    cout << "\t\t\t-----------------------------------------------------------------------------------\n";
    cout << "\t\t\tFlight No : "<<getUserFlightNo()<<"\t\t\t\t\t    Date : "<<getDate()<<"             \n";
    cout << "\t\t\t-----------------------------------------------------------------------------------\n";
    cout << "\t\t\tOrigin : "<<getDeparture()<<"\t\t  Destination : "<<getArrival()<<"\t\t    Seat : "<<getSeatNo()<<"\n";
    cout << "\t\t\t###################################################################################\n";
}
void acetLogo() {
    system("clear");
	cout <<"\n\n\n\n\n\n\n\n";
    cout <<"\t\t\t      //////////////     //////////////     //////////////     ////////////// \n";
    cout <<"\t\t\t      //          //     //                 //                       //       \n";
    cout <<"\t\t\t      //          //     //                 //                       //       \n";
    cout <<"\t\t\t      //          //     //                 //                       //       \n";
    cout <<"\t\t\t      //         //     //                 //////////               //       \n";
    cout <<"\t\t\t      //////////////     //                 //                       //       \n";
    cout <<"\t\t\t      //          //     //                 //                       //       \n";
    cout <<"\t\t\t      //          //     //                 //                       //       \n";
    cout <<"\t\t\t      //          //     //                 //                       //       \n";
    cout <<"\t\t\t      //          //     //////////////     //////////////           //       \n";
    cout <<"\n";
    cout <<"\n";
    cout <<"\t\t\t                              /////////////////////\n";
    cout <<"\t\t\t                             //  SEMESTER - III //\n";
    cout <<"\t\t\t                            /////////////////////\n";
    cout <<"\n\n";
    cout <<"\t\t\t                 //////////////////////////////////////\n";
    cout <<"\t\t\t                //   AIRLINE RESERVATION SYSTEM     //\n";
    cout <<"\t\t\t               //////////////////////////////////////\n";
    cout <<"\n";
    cout <<"\t\t\t                     Press Enter to Continue .....\n";
	cin.get();
}

int main()
{
	acetLogo();
    password();
start :
	int choice = MENU();
	if (choice == 0)
		goto start;
	switch(choice)
	{
		case 1:
			{
				//system("setterm -background 1 -foreground white");
                system("clear");
                cout <<"\n\n\n\n\n\n";
				cout << "\t\t\tWelcome to the Ticket Booking Services\n";
				AIRLINE b;
				b.setBookingId();
				fstream tb;
				tb.open("booking.dat",ios::in|ios::out|ios::binary|ios::app);

				cout << "Enter the following details to book your ticket :\n";
				b.setDeparture();
				b.setArrival();
				int fare;

				cout << "Your Arrival and Departure places : \n";
				cout << b.getDeparture() << " and " << b.getArrival() << endl;
				
				AIRLINE tmp;
				fstream fl;
				fl.open("flights.dat",ios::in|ios::out|ios::binary|ios::app);
				fl.seekg(0,ios::beg);
				//tb.write((char *)&b , sizeof(b));

				cout << "Following are the Flights that suit your needs :\n\n";
				disFlightFormat();
				fl.seekg(0,ios::beg);
				fl.read((char *)&tmp, sizeof(tmp));
                int *p = new int(0);
				while (fl.eof() != 1)
				{
					if (strcmp(b.getDeparture() , tmp.getFlightOrigin()) == 0) {
                        *p += 1;
						tmp.disFlightAll();
					}
					fl.read((char *)&tmp, sizeof(tmp));
				}
                if (*p == 0) {
                    cout << "\t\t\tNo Flight satisfies your demands , We are very sorry \n";
                    cout << "Press Any Key to go to main menu : ";
                    cin.get();
                    goto start;
                }
                delete p;
				b.setUserFlightNo();
				b.setName();
				b.setAge();
				b.setPassport();
				b.setAddress();
				b.setEmail();
				b.setPhone();
				b.setSex();
				b.setDate(0); 
				char ch = b.setTravelClass();

                // Auto Decrementing the seat from respective class
                b.decSeatNum(ch , b.getUserFlightNo());
                b.setSeatNo();

				fare = b.fareCalculator(b.getUserFlightNo() , ch);
				cout << "After ch : " << ch << endl;
				cout <<"Total Fare for Journey : " << fare << endl;

				cout << "\nAll Details successfully accepted\n";
				cout << "\t\tTicket Booking Done!!!\n";
				tb.write((char *)&b , sizeof(b));

				cout << "Ticket Details are :- \n";
				disFormat();
				b.disAll();

			    int q = exitFormat();
				if (q == 1)
					goto start;
			}
			break;
		case 2:
			{
			flight_menu:
				AIRLINE flight;
                system("clear");
                cout <<"\n\n\n\n\n\n\n\n";
				cout << "\t\t\t\tWelcome to the Flights Portal\n";
				cout << "\n\t\t\tHere You can manage all the Flights going in/out of your Airlines\n";
				cout << "\t\t\t\t\tHere is Your Menu :- \n\n";
				cout << "\t\t\t\t1. Add Flights\t\t2. Remove Flights\n";
				cout << "\t\t\t\t3. Edit Fare\t\t4. Manage Seats\n";
				cout << "\t\t\t\t5. Flights Search\t6. Total Flights\n";

				cout << "\n\t\t\t\tEnter your preferred choice :- ";
				int fl_choice;
				cin >> fl_choice;
				switch(fl_choice)
				{
					case 1:
						{
							cout << "\t\t\tWelcome to the Add Flights Section\n";
							cout << "\tFollowing Details are required for adding a flight , Enter them carefullly\n";

							flight.setFlightName();
							flight.setFlightNo();
							flight.setFlightOrigin();
							flight.setFlightDestination();
							flight.setDate(1);
							
							// Setting the seats per class
							cout << "Enter the Seat Details\n";
							//flight.setSeatClass();	
                            flight.setSeatEconomy(0);
                            flight.setSeatBusiness(0);
                            flight.setSeatPremium(0);

                            cout << "Economy : " << flight.getSeatEconomy() <<endl;
							//Setting the fare Details
							cout << "\tEnter the Fare Details for the Flight\n";
							flight.setFare();

							fstream flight_add;
							flight_add.open("flights.dat",ios::in|ios::out|ios::binary|ios::app);
							flight_add.write((char *)&flight, sizeof(flight));
							flight_add.close();
							cout << "\t\tFlight has been successfully added\n";

							cout << "Following are the Flight details that you added ;- \n";
							disFlightFormat();
							flight.disFlightAll();

							char ch = exitFlightFormat();
							if (ch == 'q' || ch == 'Q')
								exit(EXIT_FAILURE);
							else if (ch == 'r' || ch == 'R')
								goto flight_menu;
							else
								goto start;
						}
						break;
					case 2:
						{
							cout << "Welcome to the 'Remove Flight' Menu\n";
							cout << "Enter the Flight No. for flight that you want to be removed : \n";
							int tmp;
							cin >> tmp;
							fstream flight_remove , flight_tmp;
							flight_remove.open("flights.dat",ios::in|ios::out|ios::binary|ios::app);
							flight_remove.seekg(0,ios::beg);

							flight_tmp.open("tmp.dat",ios::in|ios::out|ios::binary|ios::app);

							int flag = 0;
							while (flight_remove.eof() != 1)
							{
								if (tmp == flight.getFlightNo())
								{
									flag = 1;
									cout << "\tYou are going to delete the Following Flight\n";
									disFlightFormat();
									flight.disFlightAll();

									cout << "Press 'y' to confirm removing the flights from Operations\n";
									char ch;
									cin >> ch;

									if (ch == 'Y' || ch == 'y')
										flight_remove.read((char *) &flight , sizeof(flight));
								}
								else
								{
									flight_remove.read((char *)&flight , sizeof(flight));
									flight_tmp.write((char *)&flight , sizeof(flight));
								}
							}
							if (flag == 0)
							{
								cout << "\nYou eneterd an invalid Flight Number\n";
								goto end;
							}
							remove("flights.dat");
							rename("tmp.dat" , "flights.dat");
							cout << "Flight Successfully Removed from Operations :- \n";

						end:
							char ch = exitFlightFormat();
							if (ch == 'q' || ch == 'Q')
								exit(EXIT_FAILURE);
							else if (ch == 'r' || ch == 'R')
								goto flight_menu;
							else
								goto start;
						}
						break;
					case 3:
						{
							cout << "Welcome to the Fare Management Portal\n:- ";
							cout << "Enter the Flight No. for Flight you want to manage Fare :- ";
							int tmp;
							cin >> tmp;

							fstream flight_fare;
							flight_fare.open("flights.dat",ios::in|ios::out|ios::binary|ios::app);
							flight_fare.seekg(0,ios::beg);
							flight_fare.read((char *)&flight , sizeof(flight));
							int flag = 0;
							while (flight_fare.eof() != 1)
							{
								if (tmp == flight.getFlightNo())
								{
									flag = 1;
									cout << "Current Fare Details are :- \n";
									cout << "Economy : " << flight.getFare('E')<<endl;
									cout << "Business : " << flight.getFare('B')<<endl;
									cout << "Premim : " << flight.getFare('P')<<endl;

									cout << "Enter the new Fare Details :- \n";
									flight.setFare();

									flight_fare.write((char *) &flight , sizeof(flight));
									cout << "\t\tFlight Fare Succssfully modified\n";
								}

								flight_fare.read((char *)&flight , sizeof(flight));
							}

							if (flag == 0)
								cout << "\nYou eneterd an invalid Flight Number\n";
							char ch = exitFlightFormat();
							if (ch == 'q' || ch == 'Q')
							exit(EXIT_FAILURE);
							else if (ch == 'r' || ch == 'R')
								goto flight_menu;
							else
								goto start;
						}
						break;
					case 4:
						{
							cout << "\tWelcome to the Seat Management Portal\n";
							cout << "Here You can manage Seats Per Category of Passengers\n";
							cout << "Please enter the following details : \n";
							cout << "Enter the Flight No. whose Seats you want to manage :- ";
							int tmp;
							cin >> tmp;
							
							fstream flight_seat;
							flight_seat.open("flights.dat",ios::in|ios::out|ios::binary|ios::app);
                            fstream flight_rewrite;
                            flight_rewrite.open("flights_copy.dat" , ios::in|ios::out|ios::binary|ios::app);

							int flag = 0;
							flight_seat.read((char *)&flight , sizeof(flight));
							while (flight_seat.eof() != 1)
							{
								if ( tmp == flight.getFlightNo())	
								{
									flag = 1;
									cout << "Flight No. matched as per records\n";
									cout << "Following are the current seats in Flight :- \n";
									disFlightFormat();
									flight.disFlightAll();

									cout << "Enter the following details to modify the seats :- \n";
									flight.setSeatEconomy(0);
                                    flight.setSeatBusiness(0);
                                    flight.setSeatPremium(0);

									flight_rewrite.write((char *) &flight , sizeof(flight));
								    flight_seat.read((char *)& flight , sizeof(flight));
									cout << "Seats Successfully Modified \n";
								}
                                else {
									flight_rewrite.write((char *) &flight , sizeof(flight));
								    flight_seat.read((char *)& flight , sizeof(flight));
                                }
							}
							if (flag == 0)
								cout << "\tNo Flight exists with the given Flight Id\n";

                            system("rm flights.dat");
                            system("mv flights_copy.dat flights.dat");

							char ch = exitFlightFormat();
							if (ch == 'q' || ch == 'Q')
							exit(EXIT_SUCCESS);
							else if (ch == 'r' || ch == 'R')
								goto flight_menu;
							else
								goto start;
						}
						break;
					case 5:
						{
							cout << "Welcome to the Flights Search Menu\n";
							cout << "Enter the Flight Number you want to search : ";
							int tmp;
							cin >> tmp;

							int flag = 0;
							fstream fl_search("flights.dat");
							fl_search.seekg(0,ios::beg);
							fl_search.read((char *)&flight , sizeof(flight));
							while (fl_search.eof() != 1) {
								if (tmp == flight.getFlightNo()) {
									flag = 1;
									cout << "Here is the Flight You are looking for : \n";
									disFlightFormat();
									flight.disFlightAll();
									fl_search.read((char *)&flight , sizeof(flight));
								}
							}
							if (flag == 0) 
								cout << "!!! You entered an invalid Flight Number !!!\n";
							char ch = exitFlightFormat();
							if (ch == 'Q' || ch == 'q')
								exit(EXIT_SUCCESS);
							else if (ch == 'r' || ch == 'R')
								goto flight_menu;
							else
								goto start;
						}
						break;
					case 6:
						{
							cout << "Welcome to the Total Flights Section\n";
							cout << "\tFollowing are the flights that are managed by our Airline \n";

							fstream fl_dis("flights.dat");
                            if (errno != 0) {
                                cout << "\t\t\tNo Flights are currently under Administration\n";
                            }
							fl_dis.seekg(0,ios::beg);
							fl_dis.read((char *)&flight , sizeof(flight));

							int count = 0;
							disFlightFormat();
							while (fl_dis.eof() != 1) {
								count++;
								flight.disFlightAll();
								fl_dis.read((char *) & flight , sizeof(flight));
							}
							cout << "\n\t\t\tTotal Number of Flights Managed : " << count << endl;
							char ch = exitFlightFormat();
							if (ch == 'Q' || ch == 'q')
								exit(EXIT_SUCCESS);
							else if (ch == 'r' || ch == 'R')
								goto flight_menu;
							else
								goto start;
						}
						break;
				}
			}
			break;

		case 3:
			{
				system("clear");
				AIRLINE s;
				fstream f3;
				f3.open("booking.dat",ios::in|ios::binary|ios::app);
				f3.seekg(0,ios::beg);
				int k = 0;
				do
				{
                    cout <<"\n\n\n\n\n\n\n";
                    cout << "\t\t\t\tWeclome to the Search Page\n";
					cout << "\t\t\tChoose from the following search criterias\n";
					cout << "\t\t\t------------------------------------------\n";
					cout << "\t\t\t1. AIRLINE ID (Highly Recommended)\n";
					cout << "\t\t\t2. NAME\n";
					cout << "\t\t\t3. EMAIL\n";
					cout << "\t\t\t4. PHONE\n";

					cin >> choice;
					if(choice < 1|| choice >4)
						k++;
					else
						break;
				}while(k != 0);

				int flag = 0;
				char query[30];
				switch (choice)
				{
					case 1:
						{
							int query;
							cout << "Enter the AIRLINE ID :- ";
							cin >>query;

							f3.read((char *)&s,sizeof(s));
							while(f3.eof() != 1)
							{
								if(query == s.getBookingId())
								{
									flag = 1;
									disFormat();
									s.disAll();
								}
								f3.read((char *)&s,sizeof(s));
							}

							if (flag == 0)
							{
								cout << "\tSearch query not found!\n";
							       	exit(EXIT_FAILURE);
							}

							int q = exitFormat();
							if (q == 1)
								goto start;
							f3.close();
						}
						break;

					case 2:
						{
							cout << "Enter the Name which you want to search :- ";
							cin.get();
							cin.getline(query,30);

							f3.read((char *)&s,sizeof(s));
							while(f3.eof() != 1)
							{
								if(strcmp(query,s.getName()) == 0)
								{
									flag = 1;
									disFormat();
									s.disAll();
								}
								f3.read((char *)&s,sizeof(s));
							}

							if(flag == 0)
							{
								cout << "Search Query not found!!!!";
								exit(EXIT_FAILURE);
							}
							int q = exitFormat();
							if(q == 1)
								goto start;
							f3.close();
						}
						break;

					case 3:
						{
							cout << "Enter the Email which you want to search :- ";
							cin >> query;

							f3.read((char *)&s,sizeof(s));
							while(f3.eof() != 1)
							{
								if(strcmp(query,s.getEmail()) == 0)
								{
									flag = 1;
									disFormat();
									s.disAll();
								}
								f3.read((char *)&s,sizeof(s));
							}

							if(flag == 0)
								cout << "\tSearch Query not Found!!!\n";

							int q = exitFormat();
							if (q == 1)
								goto start;

							f3.close();
						}
						break;

					case 4:
						{
							cout << "Enter the phone number which you want to search :- ";
							char query[15];
							cin >> query;

							f3.read((char *)&s,sizeof(s));
							while(f3.eof() != 1)
							{
								if(strcmp(query , s.getPhone())== 0)
								{
									flag = 1;
									disFormat();
									s.disAll();
								}
								f3.read((char *)&s,sizeof(s));
							}

							if (flag==0)
								cout << "\tSearch Query not found !!!!\n";
							int q = exitFormat();
							if (flag == 1)
								goto start;
							f3.close();
						}
						break;
				}
			}
			break;
		case 4:              // Ticket Modifications
			{
				system("clear");
                cout << "\n\n\n\n\n\n\n\n";
				cout << "\t\t\t****************************************************\n";
				cout << "\t\t\t\tWelcome to the Modifications Portal\n";
				cout << "\t\t\t****************************************************\n";
				AIRLINE mod;

				cout << "\n\t\t\tTo edit/update your INFO , please enter your unique booking ID :- ";
				int query;
				cin >> query;

				fstream fr,fw;
				fr.open("booking.dat",ios::in|ios::binary|ios::app);
				fw.open("mod.dat",ios::in|ios::binary|ios::app);
				fr.read((char *)&mod,sizeof(mod));
				fr.seekg(0,ios::beg);

				int flag = 0;
				while (fr.eof() != 1)
				{
					if(query == mod.getBookingId())
					{
						flag = 1;
						cout << "\n\tyou want to modify the following record\n";
						disFormat();
						mod.disAll();
						break;
					}
					fr.read((char *)&mod,sizeof(mod));
				}

				if(flag == 0)
				{
					cout << "\t\t!!! search query not found !!!";
					cout << "\t\twe are sending you back to home screen\n";
					goto start;
				}
				else
				{
					char ch;
					cout << "\t\tbooking id matched as in the records\n";
					cout << "\tto proceed press 'y'/'y' ,or to abort press 'q'/'q'\n";
					cin >> ch;
					if (ch != 'y' && ch != 'y')
						goto start;
				}

				// modifications menu
				cout << "\n\tplease choose among the following modifications criteria \n";
				cout << "\t\t1. name\t\t\t2. email\n";
				cout << "\t\t3. address\t\t4. phone no.\n";
				cout << "Enter your Choice :- ";
				int choice;
				cin >> choice;

				fr.seekg(0,ios::beg);
				fr.read((char *)&mod,sizeof(mod));
				switch (choice)
				{
					case 1:   // Editing the Passenger's Name
						{
							while(fr.eof() != 1)
							{
								if(query == mod.getBookingId())
								{
									mod.setName();
									cout << "\t\tName Successfully Modified\n";
									fw.write((char *)&mod,sizeof(mod));
									cout << "\tNew Record is :-\n";
									disFormat();
									mod.disAll();
									fr.read((char *)&mod,sizeof(mod));
								}
								else
								{
									fw.write((char *)&mod,sizeof(mod));
									fr.read((char *)&mod,sizeof(mod));
								}
							}

							remove ("booking.dat");
							rename("mod.dat","booking.dat");
							fr.close();
							fw.close();

							int q = exitFormat();
							if (q == 1)
								goto start;
						}
						break;

					case 2:
						{
							while(fr.eof() != 1)
							{
								if(query == mod.getBookingId())
								{
									cin.get();
									mod.setEmail();
									cout << "\t\tEmail Successfully Modified\n";
									fw.write((char *)&mod,sizeof(mod));
									cout << "New Record is :- \n";
									disFormat();
									mod.disAll();
									fr.read((char *)&mod,sizeof(mod));
								}
								else
								{
									fw.write((char *)&mod,sizeof(mod));
									fr.read((char *)&mod,sizeof(mod));
								}
							}

							remove("booking.dat");
							rename("mod.dat","booking.dat");
							fr.close();
							fw.close();

							int q = exitFormat();
							if (q == 1)
								goto start;
						}
						break;
					case 3:
						{
							while(fr.eof() != 1)
							{
								if(query == mod.getBookingId())
								{
									mod.setAddress();
									cout << "\t\tAddress Successfully Modified\n";
									fw.write((char *)&mod,sizeof(mod));
									cout << "\tNew Record is :-\n";
									disFormat();
									mod.disAll();
									fr.read((char *)&mod,sizeof(mod));
								}
								else
								{
									fw.write((char *)&mod,sizeof(mod));
									fr.read((char *)&mod,sizeof(mod));
								}
							}

							remove ("booking.dat");
							rename("mod.dat","booking.dat");
							fr.close();
							fw.close();

							int q = exitFormat();
							if (q == 1)
								goto start;

						}
						break;

					case 4:
						{
							while(fr.eof() != 1)
							{
								if(query == mod.getBookingId())
								{
									mod.setPhone();
									cout << "\t\tPhone Number Successfully Modified\n";
									fw.write((char *)&mod,sizeof(mod));
									cout << "\tNew Record is :-\n";
									disFormat();
									mod.disAll();
									fr.read((char *)&mod,sizeof(mod));
								}
								else
								{
									fw.write((char *)&mod,sizeof(mod));
									fr.read((char *)&mod,sizeof(mod));
								}
							}

							remove ("booking.dat");
							rename("mod.dat","booking.dat");
							fr.close();
							fw.close();

							int q = exitFormat();
							if (q == 1)
								goto start;
						}
						break;
				}
			}
			break;

		case 5:           //   TICKET Cancellation
			{
				system("clear");
                cout <<"\n\n\n\n\n\n\n";
				cout << "\t\t\t********************************************************\n";
				cout << "\t\t\t\tWelcome to the Ticket Cancellation System\n";
				cout << "\t\t\t*********************************************************\n";

				AIRLINE c;
				int query;
				int flag;
				cout << "\n\t\tEnter the Booking ID of the ticket which you want to cancel :- ";
				cin >> query;

				fstream fr,fw;
				fr.open("booking.dat",ios::in|ios::app|ios::binary);
				fw.open("temp.dat",ios::in|ios::binary|ios::app);

				fr.seekg(0,ios::beg);
				fr.read((char *)&c,sizeof(c));
				while (fr.eof() != 1)
				{
					if (query == c.getBookingId())
					{
						flag = 1;
						disFormat();
						c.disAll();
						cout << "\tThis Ticket is going to be cancelled\n";
						cout << "\t\t To Proceed , press 'y'/'Y' or To Abort press 'q'/'Q' \n";
						char ch;
						cin >> ch;
						if (ch == 'q' || ch == 'Q')
							goto start;
						else {
                            c.incSeatNum(c.getTravelClassChar() , c.getUserFlightNo());
							goto del;
                        }
					}
					fr.read((char *)&c,sizeof(c));
				}
            del:
				fr.seekg(0,ios::beg);
				fr.read((char *)&c,sizeof(c));
				while(fr.eof() != 1)
				{
					if(query != c.getBookingId())
					{
						fw.write((char*)&c,sizeof(c));
					}
					fr.read((char *)&c,sizeof(c));
				}

				if (flag == 0)
				{
					cout << "\t!!!! Search query not found !!! You are being sent to Home Screen >>>> \n";
					goto start;
				}

				remove("booking.dat");
				rename("temp.dat","booking.dat");
				fr.close();
				fw.close();

				cout << "\t\t!!! Ticket Successfully Cancelled !!! \n";
				int q = exitFormat();
				if (q == 1)
					goto start;
			}
			break;

		case 6: // Passenger's List
			{
				system("clear");
				AIRLINE p;
				int count = 0;
				fstream f6;
				f6.open("booking.dat",ios::in|ios::out|ios::binary|ios::app);
				f6.seekg(0,ios::beg);
				f6.read((char *)&p,sizeof(p));
                cout << "\t\t\tPASSENGER'S DETAIL\n";
				disFormat();
				while(f6.eof() != 1)
				{
					p.disAll();
					count++;
					f6.read((char *)&p,sizeof(p));
				}
				f6.close();
				cout << "\t\t\tTotal Number of Passengers is "<<count<<endl;

				int q = exitFormat();
				if (q == 1)
					goto start;
			}
            break;
        case 7:
            {
                system("clear");
                cout <<"\n\n\n\n\n\n\n";
                cout << "\t\t\t\tWelcome to The Ticket Printing Facility\n\n\n";
                cout << "\t\t\tEnter the Booking Id for which TICKET is to be printed : ";
                int ticket_id;
                cin >> ticket_id;

                AIRLINE ticket;
                fstream search_id("booking.dat");
                search_id.seekg(0,ios::beg);
                search_id.read((char *) &ticket , sizeof(ticket));
                int flag = 0;
                while (search_id.eof() != 1) {
                    if (ticket_id == ticket.getBookingId()) {
                        flag = 1;
                        cout << "\n\t\t\tHere comes your Ticket :\n";
                        ticket.printTicket();
                    }
                    search_id.read((char *) &ticket , sizeof(ticket));
                }
                if (flag == 0)
                    cout << "\t\t\t\tThe Booking ID you entered doesn't exist in our Database\n";

                cout << endl;
				int q = exitFormat();
				if (q == 1)
					goto start;
            }
            break;
        case 8:
            {
                cout << "\t\tGood Bye !!!! , We hope you enjoyed our Services \n";
                exit(EXIT_SUCCESS);
            }
	}
}
