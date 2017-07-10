#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;

//Global Variables
int flag = 0;

class BOOKING
{
        char name[20];
        char add[50];
        char email[30];
        long mobile;
        int age;
        char sex;
        char departure[25];
        char arrival[25];
        char date[10];
	int serial = 0;
        long long aadhar;
    public :
        void getName()
        {
            cout << "Enter Passenger's Name :- ";
            cin.get();
            cin.getline(name,20);
        }

        void getEmail()
        {
            cout << "Enter your email address :- ";
            cin.get();
            cin.getline(email,50);
        }

        void getMobile()
        {
            cout << "Enter your Mobile Number :- ";
            cin >> mobile;
        }

        void getGen()
        {
            cout << "Enter the Address Details :- ";
            cin.getline(add,50);

            cout << "Enter your Age :- ";
            cin >> age;

            cout <<"Enter Sex(M/F) :- ";
            cin >> sex;
        }

        void getAadhar()
        {
            cout << "Enter Aadhar Number :- ";
            cin >> aadhar;
        }

        void getTravel()
        {

            int n;
            int k = 0;
            do
            {
                cout << "\n\t\tSelect Your City of Departure\n";
                cout << "\t\t-----------------------------\n";
		cout << "\t1.  Patna\n";
		cout << "\t2.  Amritsar\n";
		cout << "\t3.  Bengaluru\n";
		cout << "\t4.  New Delhi\n";
		cout << "\t5.  Mumbai\n";
		cout << "\t6.  Chandigarh\n";
		cout << "\t7.  Allahabad\n";
		cout << "\t8.  Chennai\n";
		cout << "\t9.  Pune\n";
		cout << "\t10. Varanasi\n";

		cout << "Please Input Your Choice Number :-  ";
                cin >> n;

		switch (n)
                {
                	case 1:
                        	strcpy(departure, "PATNA");
                        	break;
                    	case 2:
                        	strcpy(departure, "AMRITSAR");
                        	break;
                    	case 3:
                        	strcpy(departure, "BENGALURU");
                        	break;
                    	case 4:
                        	strcpy(departure, "NEW DELHI");
                        	break;
                    	case 5:
                        	strcpy(departure, "MUMBAI");
                        	break;
                    	case 6:
                        	strcpy(departure, "CHANDIGARH");
                        	break;
		    	case 7:
				strcpy(departure, "ALLAHABAD");
				break;
		   	case 8:
				strcpy(departure, "CHENNAI");
				break;
		    	case 9:
				strcpy(departure, "PUNE");
				break;
			case 10:
				strcpy(departure, "VARANASI");
				break;
		    
                    	default:
                        	cout << "Invalid Choice . Please Try Again.\n";
                        	k++;
		}
            }while(k != 0);

            int p = 0;
            do
            {
                cout << "\n\t\tSelect Your City of Arrival\n";
                cout << "\t\t---------------------------\n";
                cout << "\t1.  New Delhi\n";
                cout << "\t2.  Patna\n";
                cout << "\t3.  Mumbai\n";
                cout << "\t4.  Bengaluru\n";
                cout << "\t5.  Chennai\n";
                cout << "\t6.  Pondicherry\n";
		cout << "\t7.  Varanasi\n";
		cout << "\t8.  Pune\n";
		cout << "\t9.  Amritsar\n";
		cout << "\t10. Allahabad\n";

                cout << "Please Input Your Choice :- ";
                cin >>n;

                switch(n)
                {
                    	case 1:
                        	strcpy(arrival,"NEW DELHI");
                        	break;
                    	case 2:
                        	strcpy(arrival,"PATNA");
                        	break;
                    	case 3:
                        	strcpy(arrival,"MUMBAI");
                        	break;
                    	case 4:
                        	strcpy(arrival,"BENGALURU");
                        	break;
                    	case 5:
                        	strcpy(arrival,"CHENNAI");
                        	break;
                    	case 6:
                        	strcpy(arrival,"PONDICHERRY");
                        	break;
			case 7:
				strcpy(arrival,"VARANASI");
				break;
			case 8:
				strcpy(arrival,"PUNE");
				break;
			case 9:
				strcpy(arrival,"AMRITSAR");
				break;
			case 10:
				strcpy(arrival,"ALLAHABAD");
				break;
                   	default:
                        	cout << "Invalid choice . Please Try Again.\n";
                        	p++;
                }
            }while(p != 0);

            cout << "Date of Journey ( DD/MM/YYYY ) :- ";
            cin >> date;
        }
	int getSerial()
	{
		serial = serial + 1;
		return serial;
	}

        //Now Functions for Comparison
        void searchName(char query[20])
        {
            if(strcmp(query,name) == 0)
            {
                cout << "\t\t!!! Name found in Records !!!\n";
                flag = 1;
                disInfo();
            }
        }

        void searchEmail(char query[30])
        {
            if(strcmp(query,email) == 0)
            {
                cout << "\t\t!!! Email matched in Records !!!\n";
                flag = 1;
                disInfo();
            }
        }

        void searchAadhar(long long query)
        {
            if(query == aadhar)
            {
                cout << "\t\t!!! Aadhar ID matched in Records !!!\n";
                flag = 1;
                disInfo();
            }
        }

        void searchMobile(long query)
        {
            if(query == mobile)
            {
                cout << "\t\t!!! Mobile Number found in the Records !!!\n";
                flag = 1;
                disInfo();
            }
        }

        //Modifications for the Mofify module
        void modName(char query[20])    // Modifying the Name
        {
            if(strcmp(query,name) == 0)
            {
                cout << "\t\t!!! Entry Found !!!\n";
                flag = 1;
                cout << "Currently list is :- \n";
                disInfo();

                //Modifying
                char moName[20];
                cout << "Enter the correct Name :- ";
                cin.getline(moName,20);

                strcpy(name,moName);
                cout << "\t\t!!! Successfully Modified Name !!!\n";
                cout << "The Modified list is as follows :- \n";
                disInfo();
            }
        }

        void modEmail(char query[30])
        {
            if(strcmp(query,email) == 0)
            {
                cout << "\t\t!!! Email matched in Records !!!\n";
                flag = 1;
                cout << "Current details are :-\n";
                disInfo();

                //Modifying
                char moEmail[30];
                cout << "Enter the Correct Email ID :- ";
                cin.getline(moEmail,30);

                strcpy(email,moEmail);
                cout << "\t\t!!! Email Successfully Modified !!!\n";
                cout << "The Modified Details are :- \n";
                disInfo();
            }
        }

        void modAadhar(long long query)
        {
            if(query == aadhar)
            {
                cout << "\t\t!!! Aadhar ID matched in Records !!!\n";
                flag = 1;
                cout << "Current Details are :- \n";
                disInfo();

                //Modiying
                long long moAadhar;
                cout << "Enter the Correct Aadhar Card Number :- ";
                cin >> moAadhar;

                aadhar = moAadhar;
                cout << "\t\t!!! Aadhar Successfully Modified !!! \n";
                cout << "Modified Details are :- \n";
                disInfo();
            }
        }

        void modMobile(long query)
        {
            if(query == mobile)
            {
                cout << "\t\t!!! Mobile Number found in the Records !!!\n";
                flag = 1;
                cout << "Current Details are :- \n";
                disInfo();

                //Modifying
                long moMobile;
                cout << "Enter the Correct Mobile Number :- ";
                cin >> moMobile;

                mobile = moMobile;
                cout << "\t\t!!! Mobile No. Successfully Modified !!!\n";
                cout << "Modified Details are :- \n";
                disInfo();
            }
        }

        //Displaying whatever we got above
        int disInfo()
        {
            cout.setf(ios::left);
            cout <<setw(2)<<serial<<setw(15)<< name <<setw(12)<< date <<setw(20)<< add <<setw(15)<< mobile <<setw(30)<<email<<setw(20)<<aadhar<<setw(12)<< departure <<setw(12)<< arrival<<endl;
        }

	//########################################################################################################################################################
	//                                                   RESERVATION PART                                                   
	//########################################################################################################################################################
	
	void new_seat()
	{

	}
};

class FLIGHT
{
	int flightNum;
	
};
void adminPass()
{
    char admin;
    char password[] = "phenomenal";
    char pass[15];
    char p;
    cout << "\n\t\tWarning !!!!\n";
    cout << "You can access this feature only if you are the Flight Admininstrator of the Phenomenal Airline Services\n";
    cout << "\n\tIf you are an administrator , press 'A'('a') to continue :- ";
    cin >> admin;

    if(admin == 'A' || admin == 'a')
    {
pass:
        cout << "Enter your Administrative Password :- ";
        cin >> pass;

        if(strcmp(pass,password) == 0)
        {
            cout << "\tCongratulations You are an Adminstrator\n";
            //goto flight;
        }
        else
        {
            cout << "\tYou entered an Incorrect Password\n";
            cout << "Press 'c' to Re-enter your Administrator Password (Pressing Anything else will lead to termiantion of program) :- ";
            cin >> p;

            if(p == 'c'||p == 'C')
               goto pass;
            else
                exit(EXIT_FAILURE);
        }
    }
    else
    {
        cout << "Since You are not the Administrator , we are terminating the program\n";
        exit(EXIT_FAILURE);
    }
}

int main()
{
start:
    cout << endl;
    cout << "*********************************************************************\n";
    cout <<"..............Welcome to the Phenomenal Airline Services ............\n";
    cout << "*********************************************************************\n";
    int k = 0;
    int choice;
    do
    {
        cout << "\tHit the Option of your Choice\n";
        cout << "--------------------------------------------------------------------\n";
        cout << "\t1. Booking\t\t2. Flight Details\n";
        cout << "\t3. Search\t\t4. Modify\n";
        cout << "\t5. Cancellation\t\t6. Passenger Details\n";

        cout << "Please Enter your Preferred Choice :- ";
        cin >> choice;
        if(choice < 1 || choice > 6)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while(k != 0);

    switch (choice)
    {
        case 1:
            {
                BOOKING b;
                fstream f1;
                char ch;
                int book_id = 1;
                f1.open("booking.dat",ios::in|ios::out|ios::app|ios::binary);
                cout << "\t\tWelcome to Booking Services\n";
                cout << "\t\t---------------------------\n";

                do
                {
                    b.getName();
                    b.getGen();
                    b.getEmail();
                    b.getAadhar();
                    b.getMobile();
                    b.getTravel();
		    b.getSerial();
                    f1.write((char *)&b , sizeof(b));

                    cout << "\n\t\tBooking Details are following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout <<setw(2)<<"S.No"<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                    cout <<setw(2)<<"----"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                    b.disInfo();
                    cout << "\nDo you want to register again ?\n";
                    cout << "(Y for yes,N for no)";
                    cin >> ch;
                }while (ch == 'Y'|| ch == 'y');
                cout << "\n\t..........Booking Successful...............\n";

                char c1;
                cout << "\tPress 'q' to terminate or any other key to return to HomeScreen :- ";
                cin >>c1;
                if(c1 == 'q' || c1 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
                f1.close();
            }
            break;

        case 2:
            {
                adminPass();
                /*  FLIGHTS f;
                fstream f2;
                f2.open("flights.dat",ios::in|ios::out|ios::app);
                char ch = 'Y';
                while (ch == 'Y'||ch == 'y')
                  {
                      f.flightInfo();
                      f2.write((char *)&f,sizeof(f));

                      cout << "Do you want to add more Flights in the list(y/n) :- ";
                      cin >> ch;
                  }*/
                }
            break;

        case 3:
            {
                BOOKING s;
                int choice;
                fstream f3;
                char sName[20];
                char sEmail[20];
                long sMobile;
                long long sAadhar;
                f3.open("booking.dat",ios::in|ios::out|ios::binary);
                cout << "\tChoose the Criteria by which you want to search through the PASSENGERS list\n";
                cout <<"\t1. By Name\n\t2. By Email\n";
                cout <<"\t3. By Aadhar Number(Recommended)\n\t4. By Phone Number\n";

                cout << "Enter your Preferred Choice :- ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        {

                            int flag = 0;
                            cout << "Enter the name which you want to search :- ";
                            cin >> sName;
                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));
                            cout.setf(ios::left);
		    	    cout <<setw(2)<<"S.No"<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(2)<<"----"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;

                            while(f3.eof() != 1)
                            {
                                s.searchName(sName);
                                f3.read((char *)&s,sizeof(s));
                            }

                            if (flag == 0)
                            cout << "\t!!!!!!Search Query Not Found!!!!!!!!\n";
                            f3.close();

                            char c3_1;
                            cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                            cin >> c3_1;

                            if(c3_1 == 'q'|| c3_1 == 'Q')
                                exit(EXIT_FAILURE);
                            else
                                goto start;
                        }
                        break;

                    case 2:
                        {
                            cout << "Enter the Email-id you want to search :- ";
                            cin >> sEmail;

                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(2)<<"S.No"<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(2)<<"----"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;

                            while (f3.eof() != 1)
                            {
                               s.searchEmail(sEmail);
                               f3.read((char *)&s,sizeof(s));
                            }
                            f3.close();

                            if(flag == 0)
                                cout << "\t\tSearch Query Not Found !!!\n";

                            char c3_2;
                            cout << "\tPress 'q' to quit or Any Other Key to go to HomeScreen\n";
                            cin >> c3_2;

                            if(c3_2 == 'q' || c3_2 == 'Q')
                               exit (EXIT_FAILURE);
                            else
                                goto start;
                        }
                        break;

                    case 3:
                        {
                            int flag = 0;
                            cout << "Enter the Aadhar number which you want to search :- ";
                            cin >> sAadhar;

                            f3.seekg(0,ios::beg);
                            f3.read((char*)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(2)<<"S.No"<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(2)<<"----"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;

                            while (f3.eof() != 1)
                            {
                                s.searchAadhar(sAadhar);
                                f3.read((char *)&s,sizeof(s));
                            }

                            f3.close();

                            if(flag == 0)
                                cout << "\t\tSearch Query Not Found !!!!\n";

                            char c3_3;
                            cout << "\tPress 'q' to quit or Any Other Key to go to HomeScreen\n";
                            cin >> c3_3;

                            if(c3_3 == 'q' || c3_3 == 'Q')
                                exit(EXIT_FAILURE);
                            else
                                goto start;
                        }
                        break;

                    case 4:
                        {
                            cout << "Please Enter the phone number which you want to search :- ";
                            cin >> sMobile;

                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(2)<<"S.No"<<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(2)<<"----"<<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;

                            while (f3.eof() != 1)
                            {
                                s.searchMobile(sMobile);
                                f3.read((char *)&s,sizeof(s));
                            }

                            f3.close();

                            if(flag == 0)
                                cout << "\tSearch Query Not Found !!!!!!!!\n";

                            char c3_4;
                            cout << "\tPress 'q' to quit or Any other key to go to HomeScreen\n";
                            cin >> c3_4;

                            if(c3_4 == 'q' || c3_4 == 'Q')
                                exit(EXIT_FAILURE);
                            else
                                goto start;
                        }
                        break;
                }

            }
            break;

        case 4:
            {
                BOOKING m;
                fstream f4;
                int choice_4;
                f4.open("booking.dat",ios::in|ios::out|ios::binary);
                cout << "\t\t.............Welcome to the Modifications Portal...............\n";
                cout << "Please carefully choose among the following modifications you can perform on your already Booked Ticket\n";
                cout << "\t\t1. Edit Name\n";
                cout << "\t\t2. Edit Email\n";
                cout << "\t\t3. Edit Aadhar ID\n";
                cout << "\t\t4. Edit Mobile No.\n";

                cout << "Enter your preferred Choice :- ";
                cin >> choice_4;

                if(choice_4 >= 1 && choice_4 <= 4 )
                    switch(choice_4)
                    {
                        case 1:
                            {
                                char mName[20];
                                cout << "Enter the misspelt Name ;- ";
                                cin.get();
                                cin.getline(mName,20);

                                f4.seekg(0,ios::beg);
                                f4.read((char *)&m,sizeof(m));

                                while(f4.eof() != 1)
                                {
                                    m.modName(mName);
                                    f4.read((char *)&m,sizeof(m));
                                }
                                f4.write((char *)&m,sizeof(m));

                                f4.close();
                                if (flag == 0)
                                    cout << "\t\t!!! No matching name found !!!\n";

                                char c4_1;
                                cout << "\tPress 'q' to quit or Any other key to go to HomeScreen\n";
                                cin >> c4_1;

                                if(c4_1 == 'q' || c4_1 == 'Q')
                                    exit(EXIT_FAILURE);
                                else
                                    goto start;
                            }
                            break;

                        case 2:
                            {
                                char mEmail[30];
                                cout << "Enter the incorrect mail-id :- ";
                                cin.getline(mEmail,30);

                                f4.seekg(0,ios::beg);
                                f4.read((char *)&m,sizeof(m));

                                while(f4.eof() != 1)
                                {
                                    m.modEmail(mEmail);
                                    f4.read((char *)&m,sizeof(m));
                                }
                                f4.write((char *)&m,sizeof(m));
                                f4.close();

                                if (flag == 0)
                                    cout << "\t\tSearch Query not found\n";

                                char c4_2;
                                cout << "\tPress 'q' to quit or Any other key to go to HomeScreen\n";
                                cin >> c4_2;

                                if(c4_2 == 'q' || c4_2 == 'Q')
                                    exit(EXIT_FAILURE);
                                else
                                    goto start;
                            }
                            break;
                    }


            }
            break;

/*          case 5:
            {
                BOOKING c;
                fstream f5,fr;
                f5.open("booking.dat",ios::in|ios::out|ios::binary);
                fr.open("b.dat",ios::in|ios::out|ios::binary|ios::app);

                char nam[20];
                cout << "Enter the Name for which you want to cancel the ticket :- ";
                cin >> nam;

                f5.seekg(0,ios::beg);
                f5.read((char*)&c,sizeof(c));
                while (f5.eof() != 1)
                {
                    if(strcmp(nam,c.name) != 0)
                        fr.write((char *)&c,sizeof(c));
                    f5.read((char*)&c,sizeof(c));
                }

                cout << "\n\t******Ticket Cancellation Successful******\n";

                remove ("booking.dat");
                rename ("b.dat","booking.dat");

                f5.close();
                fr.close();
                char c5;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c5;

                if(c5 == 'q'|| c5 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;

            }
            break;
*/
        case 6:
            {
                BOOKING p;
                int count = 0;
                fstream f6;
                f6.open("booking.dat",ios::in|ios::out|ios::binary);
                f6.seekg(0,ios::beg);
                f6.read ((char *)&p,sizeof(p));
                cout.setf(ios::left);
                cout <<endl;
                cout <<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                cout <<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                while(f6.eof() != 1)
                {
                    p.disInfo();
                    f6.read ((char *)&p,sizeof(p));
                    count++;
                }
                f6.close();

                cout << "\n\tTotal Number of passengers is "<<count<<endl;
                char c6;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c6;

                if(c6 == 'q'|| c6 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
            }
    }
}
