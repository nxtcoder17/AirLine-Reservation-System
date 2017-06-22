#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <cstdio>
using namespace std;

class BOOKING
{
    public :
        char name[20];
        char add[50];
        char email[50];
        long mobile;
        int age;
        char sex;
        char departure[25];
        char arrival[25];
        char date[10];
        long long aadhar;
    public :
        int getInfo()
        {
            cout << "Enter Passenger's Name :- ";
            cin.get();
            cin.getline(name,20);

            cout << "Enter the Address Details :- ";
            cin.getline(add,50);

            cout << "Enter your email address :- ";
            cin.getline(email,50);

            cout << "Enter your Phone Number :- ";
            cin >> mobile;

            cout << "Enter your Age :- ";
            cin >> age;

            cout <<"Enter Sex(M/F) :- ";
            cin >> sex;

            cout << "Enter Aadhar Number :- ";
            cin >> aadhar;

            int n;
            int k = 0;
            do
            {
                cout << "\n\t\tSelect Your City of Departure\n";
                cout << "\t\t-----------------------------\n";
		        cout << "\t1. Patna\n";
		        cout << "\t2. Amritsar\n";
		        cout << "\t3. Bengaluru\n";
		        cout << "\t4. New Delhi\n";
		        cout << "\t5. Mumbai\n";
		        cout << "\t6. Chandigarh\n";

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
                cout << "\t1. New Delhi\n";
                cout << "\t2. Patna\n";
                cout << "\t3. Mumbai\n";
                cout << "\t4. Bengaluru\n";
                cout << "\t5. Chennai\n";
                cout << "\t6. Pondicherry\n";

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
                   default:
                        cout << "Invalid choice . Please Try Again.\n";
                        p++;
                }
            }while(p != 0);

            cout << "Date of Journey ( DD/MM/YYYY ) :- ";
            cin >> date;
        }

        int disInfo()
        {
            cout.setf(ios::left);
            cout <<setw(15)<< name <<setw(12)<< date <<setw(20)<< add <<setw(15)<< mobile <<setw(30)<<email<<setw(20)<<aadhar<<setw(12)<< departure <<setw(12)<< arrival<<endl;
        }

};
class FLIGHTS
{
    char flight_no[10];
    char flight_carrier[20];
    char time_depart[10];
    char time_arrival[10];

    public :
        int flightInfo()
        {
            cout << "Enter the Flight Number :- ";
            cin >>flight_no;

            cout << "Enter the Flight Carrier Name :- ";
            cin >> flight_carrier;

            cout << "Enter the departure time :- ";
            cin >> time_depart;

            cout << "Enter the arrival time :- ";
            cin >> time_arrival;
        }
};

int main()
{
start :
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
        if(choice<1 || choice >6)
        {
            cout << "\nInvalid Choice . Please Try Again .\n";
            k++;
        }
    }while (k != 0);

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
                    b.getInfo();
                    f1.write((char *)&b , sizeof(b));

                    cout << "\n\t\tBooking Details are following\n";
                    cout << "\t\t-----------------------------\n";
                    cout.setf(ios::left);
                    cout <<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                    cout <<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
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

        /*  case 2:
            {
                FLIGHTS f;
                fstream f2;
                f2.open("flights.dat",ios::in|ios::out|ios::app);
                char ch = 'Y';
                while (ch == 'Y'||ch == 'y')
                  {
                      f.flightInfo();
                      f2.write((char *)&f,sizeof(f));

                      cout << "Do you want to add more Flights in the list(y/n) :- ";
                      cin >> ch;
                  }
            }*/

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
                cout << "\tChoose the Criteria by which you want to search the PASSENGERS list\n";
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
                            cout <<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                            while (f3.eof() != 1)
                            {
                                if (strcmp(sName,s.name) == 0)
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
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
                            int flag = 0;
                            cout << "Enter the Email-id you want to search :- ";
                            cin >> sEmail;

                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                            while (f3.eof() != 1)
                            {
                                if (strcmp(sEmail,s.email) == 0)
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
                               f3.read((char *)&s,sizeof(s));
                            }

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
                            cout <<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;

                            while (f3.eof() != 1)
                            {
                                if(sAadhar == s.aadhar)
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
                            }

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
                            int flag = 0;
                            cout << "Please Enter the phone number which you want to search :- ";
                            cin >> sMobile;

                            f3.seekg(0,ios::beg);
                            f3.read((char *)&s,sizeof(s));

                            cout.setf(ios::left);
                            cout <<setw(15)<<"Name"<<setw(12)<<"Date"<<setw(20)<<"Address"<<setw(15)<<"Mobile"<<setw(30)<<"Email"<<setw(20)<<"Aadhar"<<setw(12)<<"Depart."<<setw(12)<<"Arrival"<<endl;
                            cout <<setw(15)<<"----"<<setw(12)<<"----"<<setw(20)<<"-------"<<setw(15)<<"------"<<setw(30)<<"-----"<<setw(20)<<"------"<<setw(12)<<"-------"<<setw(12)<<"-------"<<endl;
                            while (f3.eof() != 0)
                            {
                                if (sMobile,s.mobile)
                                {
                                    s.disInfo();
                                    flag = 1;
                                }
                            }

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
                }

            }
            break;

        case 4:
            {
                BOOKING m;
                int line;
                fstream f4;
                cout << "Enter the line number which you want to modify :- ";
                cin >> line;

                int pos;
                pos = (line -1) *sizeof(m);
                f4.open("booking.dat",ios::in|ios::out|ios::binary);

                f4.seekp(pos,ios::beg);
                m.getInfo();
                f4.write((char *)&m,sizeof(m));
                f4.close();

                char c4;
                cout << "\tEnter 'q' to quit or Any Other key to go to HomeScreen\n";
                cin >> c4;

                if(c4 == 'q'|| c4 == 'Q')
                    exit(EXIT_FAILURE);
                else
                    goto start;
            }
            break;

        case 5:
            {
                BOOKING c;
                fstream f4,fr;
                f4.open("booking.dat",ios::in|ios::out|ios::binary);
                fr.open("b.dat",ios::in|ios::out|ios::binary|ios::app);

                char nam[20];
                cout << "Enter the Name which you want to delete :- ";
                cin >> nam;

                f4.seekg(0,ios::beg);
                f4.read((char*)&c,sizeof(c));
                while (f4.eof() != 1)
                {
                    if(strcmp(nam,c.name) != 0)
                        fr.write((char *)&c,sizeof(c));
                    f4.read((char*)&c,sizeof(c));
                }

                cout << "\n\t******Ticket Cancellation Successful******\n";

                remove ("booking.dat");
                rename ("b.dat","booking.dat");

                f4.close();
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
