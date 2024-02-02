#include<iostream> 
#include<fstream>
#include<iomanip>
#include<windows.h> 
using namespace std;

void menu();
class ManageMenu
{
protected:
    string userName; 
public:
    ManageMenu()
    {
        system("color 0A");
        cout << "\t Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu();
    }
    ~ManageMenu(){}
};


class Customers
{
    public:
        string name,gender,address;
        int age, mobileNo;
        static int cusID;
        char all[999];
        void getDetails()
        {
            ofstream out("old-customer.txt", ios::app);
            {
                cout << "Enter Customer ID: ";
                cin >> cusID;
                cout << "Enter NAme: ";
                cin >> name;
                cout << "Enter Age : ";
                cin >> age;
                cout << "Enter Mobile Number : ";
                cin >> mobileNo;
                cout << "Enter Address : ";
                cin >> address;
                cout << "Enter Gender : ";
                cin >> gender;
            }

            out << "\nCustomer ID: " << cusID <<"\nName: " << name << "\nAge: " << age << "\nMobile Number : " << mobileNo << "\nAdress: " <<address << "\nGender: " << gender << endl ;
            out.close();
            cout << "\nSAVED \nNOTE:  We save your details record for future purpose\n" << endl;
        }
        void showDetails()
        {
            ifstream in("old-customers.txt");
            {
                if(!in)
                {
                    cout << "File Error!" << endl;
                }
                while(!(in.eof()))
                {
                    in.getline(all,999);
                    cout << all << endl;
                }
                in.close();               
            }
        }
};

int Customers::cusID;


class Cabs{
    public:
    int cabChoice;
    int kilometers;
    float cabCost;  
    static float lastcabCost; 

     void cabDetails()
     {
        cout<<"We collaboraeted with fastest, safest and smartest cab service around the country"<<endl;
        cout<<"------------------ABC Cabs-------------------\n"<<endl;
        cout<<"1. Rent a Standard Cab - Rs. 15 for 1KM"<<endl;
        cout<<"2. Rent a Luxury Car - Rs.25 per 1KM"<<endl;

        cout<<"\n To Calculate the cost for your journey:"<<endl;
        cout<<"Enter which kind of cab you need:";
        cin>>cabChoice;
        cout<<"Enter kilometers you have to travel:";
        cin>>kilometers;

        int hireCab;
        if(cabChoice == 1){
            cabCost = kilometers * 15;
            cout<<"\n Your tour cost"<<cabCost<<"rupees for a Standard Cab"<<endl;
            cout<<"Press 1 to hire this cab: or";
            cout<<"Press 2 to select another car";
            cin >>hireCab;
            
            system("CLS");
            
            if (hireCab == 1){
                lastcabCost = cabCost;
                cout<<"\n You have successfully hired a Standard cab"<<endl;
                cout<<"Go to Menu and take the receipt"<<endl;
            }
            else if(hireCab == 2)
            {
                cabDetails();
            }
            else{
                cout<<"Invalid Input! Redirecting to Previous Menu \n Please Wait!"<<endl;
                Sleep(999);
                system("CLS");
                cabDetails();
            }
        }
        
        else if(cabChoice == 2){
          cabCost = kilometers * 25;
            cout<<"\n Your tour cost"<<cabCost<<"rupees for a Luxury Cab"<<endl;
            cout<<"Press 1 to hire this cab: or";
            cout<<"Press 2 to select another car";
            cin >>hireCab;
            
            system("CLS");
            
            if (hireCab == 1){
                lastcabCost = cabCost;
                cout<<"\n You have successfully hired a Luxury cab"<<endl;
                cout<<"Go to Menu and take the receipt"<<endl;
            }
            else if(hireCab == 2)
            {
                cabDetails();
            }
            else{
                cout<<"Invalid Input! Redirecting to Previous Menu \n Please Wait!"<<endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }
          
        }
        else{
            cout<<"Invalid Input! Redirecting to Main Menu \n Please Wait!"<<endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout<<"\n Press 1 to Redirect Main Menu: ";
        cin>>hireCab;
        system("CLS");
        if (hireCab == 1){
            menu();
        }
        else{
            menu();
        }
      }
};
float Cabs::lastcabCost;
class Booking 
{
  public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;  /////////
    void hotels(){
      string hotelNo[]={"Avendra","ChoiceYou","ElephantBay"};
      for (int a=0 ; a < 3;a++){
        cout<<(a+1)<<". Hotel"<<hotelNo[a]<<endl;
      }
      cout<<"\n Currently we collaborate with above hotels!"<<endl;
      cout <<"Press any key to back or \n Enter number of the hotel you want to book:";
      cin >>choiceHotel;
      system ("CLS");
      if (choiceHotel==1){
        cout<<"-----WELCOME TO HOTEL AVENDRA-----\n"<<endl;
        cout<<"The Garden , food and beverage.Enjoy all you can drink , stay cool and get chilled in the summer sun "<<endl;
        cout <<"Package offered by Avendra :\n"<<endl;
        cout <<"1.Standard Pack"<<endl;
        cout<<"\t All basic facilities you need just for :Rs.5000.00"<<endl;
        cout <<"2.Premium Pack"<<endl;
        cout <<"\t Enjoy Premium :Rs.10000.00"<<endl;
        cout <<"3.Luxury Pack"<<endl;
        cout <<"\t Live a Luxury at Avendra : Rs15000.00 "<<endl;

        cout <<"\n Press another key to back or\n Enter package number you want to book : ";
        cin >> packChoice;

        if (packChoice==1){
          hotelCost=5000.00;
          cout <<"\nYou have successfully booked Standard Pack at Avendra"<<endl;
          cout<<"Goto Menu and take the receipt"<<endl;
        }
        else if (packChoice==2){
          hotelCost=10000.00;
          cout <<"\nYou have successfully booked Premium Pack at Avendra"<<endl;
          cout<<"Goto Menu and take the receipt"<<endl;
        }
         else if (packChoice==3){
          hotelCost=15000.00;
          cout <<"\nYou have successfully booked Luxury Pack at Avendra"<<endl;
          cout<<"Goto Menu and take the receipt"<<endl;
        }
         else {
          cout<<"Invalid Input !! Redirecting to Previous Menue \nPlease Wait!!"<<endl;
          Sleep(1100);
          system("CLS");
          hotels();
        }
        int gotoMenu;
        cout <<"\n Press 1 to redirect main menu: ";
        cin >>gotoMenu;
        system("CLS");
        if (gotoMenu ==1){
          //menu();
        }
        else {
          //menu();
        }
      }
      else if (choiceHotel==2){
        cout<<"-----WELCOME TO CHOICEYOU -----\n"<<endl;
        cout<<"Swimming Pool ||Free Wifi || Family Rooms \n Fitness Center | Restaurant & Bar"<<endl;
        cout <<"Package offered by ChoiceYou :\n"<<endl;
        cout <<"1.Family Pack"<<endl;
        cout<<"\t Rs.15000.00 for a day "<<endl;
        cout <<"2.Couple Pack"<<endl;
        cout <<"\t Rs.10000.00 for a day "<<endl;
        cout <<"3.Single Pack"<<endl;
        cout <<"\t Rs5000.00  for a day "<<endl;
        //243
        cout <<"\n Press another key to back or\n Enter package number you want to book : ";
        cin >> packChoice;

        if (packChoice==1){
          hotelCost=15000.00;
          cout <<"\nYou have successfully booked Family Pack at ChoiceYou "<<endl;
          cout<<"Goto Menu and take the receipt"<<endl;
        }
        else if (packChoice==2){
          hotelCost=10000.00;
          cout <<"\nYou have successfully booked Couple Pack at ChoiceYou"<<endl;
          cout<<"Goto Menu and take the receipt"<<endl;
        }
         else if (packChoice==3){
          hotelCost=15000.00;
          cout <<"\nYou have successfully booked Single Pack at ChoiceYou"<<endl;
          cout<<"Goto Menu and take the receipt"<<endl;
        }
         else {
          cout<<"Invalid Input !! Redirecting to Previous Menue \nPlease Wait!!"<<endl;
          Sleep(1100);
          system("CLS");
          hotels();
        }
        int gotoMenu;
        cout <<"\n Press 1 to redirect main menu: ";
        cin >>gotoMenu;
        system("CLS");
        if (gotoMenu ==1){
          menu();
        }
        else {
          menu();
        }
      }
      else if (choiceHotel==3){
        cout<<"-----WELCOME TO ELEPHANTBAY -----\n"<<endl;
        cout<<"Set in tropical garden on the bank of the Maha Oya river While Seeing Elephants "<<endl;
        cout<<"Amazing off this Summer :Rs 5000.00 for a day !!!"<<endl;
        
        cout <<"\n Press another key to back or \n Press 1 to book this special package : ";
        cin >> packChoice;

        if (packChoice==1){
          hotelCost=5000.00;
          cout <<"\nYou have successfully booked ElephantBay Special Pack"<<endl;
          cout<<"Goto Menu and take the receipt"<<endl;
        }   
         else {
          cout<<"Invalid Input !! Redirecting to Previous Menue \nPlease Wait!!"<<endl;
          Sleep(1100);
          system("CLS");
          hotels();
        }
        int gotoMenu;
        cout <<"\n Press 1 to redirect main menu: ";
        cin >>gotoMenu;
        system("CLS"); 
        if (gotoMenu ==1){
          menu();
        }
        else {
          menu();
        }
      }
      else {
        cout <<"Invalid Input ! Redirecting to Previous Menu \n Please Wait "<<endl;
        Sleep(1100);
        system("CLS");
        menu();
      }
    
    }
};
float Booking::hotelCost;
class charges : public Booking, Cabs, Customers
{
    public:
    void printBill()
    {
        ofstream outf("receipt.txt");
        {
            outf<< "-------ABC Travel Agency-----"<<endl;
            outf<< "--------Reciept------------"<<endl;
            outf<< "____________________________"<<endl;

            outf <<"Customer ID: "<<Customers:: cusID << endl <<endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t" << fixed <<setprecision(2)<<Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t"<< fixed << setprecision(2) << Cabs::lastcabCost << endl;
            outf << "__________________________________"<<endl;
            outf << "Total Charge:\t\t" << fixed << setprecision(2) << Booking::hotelCost+Cabs::lastcabCost << endl;
            outf << "__________________________________" << endl;
            outf << "-----------Thank You --------------" <<endl;

        }

        outf.close();

    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File opening error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all,999);
                cout << all << endl;
            } 
        }
        inf.close();
    }
};
void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;

    cout << "\t\t      *ABC Travels * \n" << endl;
    cout << "------------------------ Main Menu ------------------" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout <<" \t|\t\t\t\t\t" << endl;
    cout << " \t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t| \t Cab Management     -> 2\t|" << endl;
    cout << "\t|\tBookings Management  -> 3\t|" << endl;
    cout << "\t|\t Charges & Bill      -> 4\t|" << endl;
    cout << "\t|\t Exit                 -> 5\t|" << endl;
    cout <<"\t|\t\t\t\t\t" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;

    cout << "\n Enter your Choice";
    cin >> mainChoice;

    system("CLS");

    Customers a2;
    Cabs a3;
    Booking a4;
    charges a5;

    if (mainChoice == 1){
        cout << "-------Customers--------\n" << endl;
        cout << "1. Eneter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\n Enter Choice : ";
        cin >> inChoice;
        system ("CLS");
        if (inChoice ==1){
            a2.getDetails();
        }
        else if (inChoice ==2){
            a2.showDetails();
        }
        else {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();        
        }
        cout << "\nPress 1 to Redirect main menu :";
        cin >>  gotoMenu;
        system ("CLS");
        if (gotoMenu == 1){
            menu();
        }
        else {
            menu();
        }
    }    
        else if (mainChoice == 2){
            a3.cabDetails();
        }

        else if(mainChoice == 3){
            cout <<"---> Book a luxury Hotel using the system <---" << endl;
            a4.hotels();
        }
        else if(mainChoice == 4){
            cout << "-->Get your receipt <--" << endl;
            a5.printBill();

            cout << "Yur receipt is already printed, you can get it from file path\n" << endl;
            cout << "To display your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
            cin >> gotoMenu;

            if(gotoMenu == 1){
                system("CLS");
                a5.showBill();
                cout << "\nPress 1 to redirect main menu ";
                cin >> gotoMenu;
                system("CLS");
                if(gotoMenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            else{
                system("CLS");
                menu();
            }
        }
        else if(mainChoice == 5){
            cout << "--GOOD-BYE--" << endl;
            Sleep(999);
            system("CLS");
            menu();
        }
        else{
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
    
};

int main()
{
    ManageMenu startObj;
    return 0;
};