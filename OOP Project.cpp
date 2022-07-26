#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <unistd.h>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iomanip>
#define max 10

using namespace std;

string name;
string date;
string ttime;
string gender;

void Restaurant();
void Mall();
void Police_Station();
void Excise_and_taxation_department();
void Pharmacy();

int main()
{
    char choice;
    string occupation;
    string info;
    int option;

        cout<<"\t\t\t***Welcome to virtual city***"<<endl;
        cout<<"You need to fill the following form for taking the tour of the city "<<endl;
        cout<<"\t\t\t***Form***"<<endl;
        cout<<"Name:";
        getline(cin, name);
        cout<<endl;
        cout<<"Gender:";
        cin.ignore();
        getline(cin, gender);
        cout<<endl;
        cout<<"Occupation:";
        cin>>occupation;
        cout<<endl;
        cout<<"How did you hear about us?"<<endl;
        cout<<"-> News outlet"<<endl;
        cout<<"-> Referral"<<endl;
        cout<<"-> Internet ad"<<endl;
        cout<<"-> Any other source"<<endl;
        cin.ignore();
        getline(cin, info);
        cout<<endl;
        cout<<"At which time you would like to visit the virtual city.(For example if you want to take the tour in the morning enter morning)"<<endl;
        cout<<"-> Morning"<<endl;
        cout<<"-> Afternoon"<<endl;
        cout<<"-> Night"<<endl;
        cin>>ttime;
        cout<<endl;
        cout<<"At which date you will take the tour, (Date format : day/month/year )"<<endl;
        cin>>date;

        cout<<"You need to have the following card at the day of the tour"<<endl;
        cout<<"**********************************"<<endl;
        cout<<"\tName:"<<name<<endl;
        cout<<"\tOccupation:"<<occupation<<endl;
        cout<<"\tTime:"<<ttime<<endl;
        cout<<"'\tDate of the tour:"<<date<<endl;
        cout<<"**********************************"<<endl;


       cout<<"Manger :Welcome "<<name<<" to the vitual city.\n\tI hope by the end of the tour you will for sure buy a place here."<<endl;
       cout<<"\tVirtual city have all the facilities.\n\tWe have Restaurant, Pharmacy, Police Station everything is available here"<<endl;
       cout<<"\tYou can visit all these places one by one."<<endl;
       do
       {
        cout<<"Kindly enter the serial of the palce you would like to visit"<<endl;
        cout<<"****************************************************************"<<endl;
        cout<<"\t1. Mall"<<endl;
        cout<<"\t2. Police Station"<<endl;
        cout<<"\t3. Excise and taxation department"<<endl;
        cout<<"\t4. Pharmacy"<<endl;
        cout<<"\t5. Restaurant"<<endl;
        cout<<"\t0. Exit"<<endl;
        cout<<"****************************************************************"<<endl;

        cin>>option;

        switch(option)
        {
        case 1:
            Mall();
            break;
        case 2:
            Police_Station();
            break;
        case 3:
            Excise_and_taxation_department();
            break;
        case 4:
            Pharmacy();
            break;
        case 5:
            Restaurant();
           break;
        }  
            
       } while (option!=0);    
}

class Res
{
    public:
    string breakfast;
    int bf[18];

    string desifood;
    int dff[12];

    string fastfood;
    int ff[12];

    string Desert;
    int df[9];

    string number;
    int cvv;
    string expiry;
    string NName;
    
    void SETCreditCard();

    void displayCreditCard();

    double billForAfternoon(int nf ,int inf[], char l, int nd, int ind[], int di, int adi[], Res d, Res f, Res dd);
    
    void receiptForAfternoonCredit(int nf ,int inf[], char l, int nd, int ind[], int di, int adi[], Res d, Res f, Res dd);

    void receiptForAfternoonCash(int nf ,int inf[], char l, int nd, int ind[],int di, int adi[], int am,Res d, Res f, Res dd);

    double billformorning(int b, int ab[], Res obj);

    void receiptForMorningCredit(int b, int ab[], Res obj);
    
    void receiptForMorningCash(int b, int ab[], Res obj, int am);
};

void Res::SETCreditCard()
{
    cout<<"Number(12 digit): "<<endl;
    cin>>number;
    cout<<endl;
    cout<<"Cvv(3 digit): "<<endl;
    cin>>cvv;
    cout<<endl;
    cout<<"Expiry(m/y): "<<endl;
    cin.ignore();
    getline(cin, expiry);
    cout<<endl;
    cout<<"Name: "  <<endl;
    cin.ignore();
    getline(cin, NName);
    cout<<endl;
}

void Res::displayCreditCard()
{
    cout<<"Number(12 digit): ";
    cout<<number;
    cout<<endl;
    cout<<"Cvv(3 digit): ";
    cout<<cvv;
    cout<<endl;
    cout<<"Expiry(m/y): ";
    cout<<expiry;
    cout<<endl;
    cout<<"Name: " ;
    cout<<NName;
    cout<<endl;
}

double Res::billForAfternoon(int nf ,int inf[], char l, int nd, int ind[], int di, int adi[], Res d, Res f, Res dd)
    {
        double bill=0;
        for(int u=1 ; u<=12 ; u++)
            {
                for(int k=0 ; k<nf; k++)
                {
                    if(inf[k]==u)
                    {
                        bill+=f.ff[u-1];
                    }
                }
            }

        for(int u=1 ; u<=12 ; u++) 
        {
            for(int k=0 ; k<di; k++)
            {
                if(adi[k]==u)
                {
                    bill+=d.dff[u-1];
                }
            }
        }    
    
        if(l=='Y')
            {
                for(int u=1 ; u<=9 ; u++)
                {
                    for(int k=0 ; k<nd; k++)
                    {
                        if(ind[k]==u)
                        {
                            bill+=dd.df[u-1];
                        }
                    }
                }
            } 

        return bill;
    }

void Res::receiptForAfternoonCredit(int nf ,int inf[], char l, int nd, int ind[], int di, int adi[], Res d, Res f, Res dd)
{
    cout<<"**********************************************************************************"<<endl;   
    cout<<"\t\t\t->->->RECEIPT<-<-<-"<<endl;
    cout<<"Details of the credit card:"<<endl;
    displayCreditCard();
    cout<<endl;

    cout<<"Total Amount ";
    cout<<"                                               ";
    cout<<billForAfternoon(nf , inf,  l,  nd,  ind,  di,  adi,  d,  f,  dd)<<endl;

    cout<<"Amount deducted";
    cout<<"                                            ";
    cout<<billForAfternoon( nf , inf,  l,  nd,  ind,  di,  adi,  d,  f,  dd)<<endl;

    cout<<"Return amount";
    cout<<"                                              ";
    cout<<"0.0 Rs"<<endl;     

    cout<<"**********************************************************************************"<<endl;
}

void Res::receiptForAfternoonCash(int nf ,int inf[], char l, int nd, int ind[],int di, int adi[], int am,Res d, Res f, Res dd)
{
    cout<<"**********************************************************************************"<<endl;
    cout<<"\t\t\t->->->RECEIPT<-<-<-"<<endl;

    cout<<"Total Amount ";
    cout<<"                                               ";
    cout<<billForAfternoon( nf , inf,  l,  nd,  ind,  di,  adi,  d,  f,  dd)<<endl;

    cout<<"Amount deducted";
    cout<<"                                            ";
    cout<<am<<endl;

    cout<<"Return amount";
    cout<<"                                              ";
    cout<<(am)-(billForAfternoon( nf , inf,  l,  nd,  ind,  di,  adi,  d,  f,  dd))<<endl;

    cout<<"**********************************************************************************"<<endl;
}

double Res::billformorning(int b, int ab[], Res obj)
{
    double bill=0;
    for(int u=1 ; u<=12 ; u++)
    {
        for(int k=0 ; k<b; k++)
        {
            if(ab[k]==u)
            {
                bill+=obj.bf[u-1];
            }
        }
    }
    return bill;
}

void Res::receiptForMorningCredit(int b, int ab[], Res obj)
{
    cout<<"**********************************************************************************"<<endl;   
    cout<<"\t\t\t->->->RECEIPT<-<-<-"<<endl;
    cout<<"Details of the credit card:"<<endl;
    displayCreditCard();
    cout<<endl;

    cout<<"Total Amount ";
    cout<<"                                               ";
    cout<<billformorning( b,  ab,  obj)<<endl;

    cout<<"Amount deducted";
    cout<<"                                            ";
    cout<<billformorning( b,  ab,  obj)<<endl;

    cout<<"Return amount";
    cout<<"                                              ";
    cout<<"0.0 Rs"<<endl;

    cout<<"**********************************************************************************"<<endl;
}

void Res::receiptForMorningCash(int b, int ab[], Res obj, int am)
{
    cout<<"**********************************************************************************"<<endl;
    cout<<"\t\t\t->->->RECEIPT<-<-<-"<<endl;

    cout<<"Total Amount ";
    cout<<"                                               ";
    cout<<billformorning( b,  ab,  obj)<<endl;

    cout<<"Amount deducted";
    cout<<"                                            ";
    cout<<am<<endl;

    cout<<"Return amount";
    cout<<"                                              ";
    cout<<(am)-(billformorning( b,  ab,  obj))<<endl;

    cout<<"**********************************************************************************"<<endl;
}

void  Restaurant()
{
    string place , pro, pro1;;
    char c , gg , ds;

    int NumItemF; //fast food
    int itemNumF[NumItemF];

    int NumItemD; //desert
    int *itemNumD = new int[NumItemD]; 

    int NumItemDi; //desi food
    int *itemNumDi = new int[NumItemDi];

    int NumItemB; // Bill
    int *itemNumB= new int[NumItemB];


    Res Breakf[18] , pbeakfast, Desif[12], PDesif, Fastf[12], PFastf, Desertf[9],PDesertf ,customer ;

    Breakf[0].breakfast="1)1 egg, home fries and toast";
    Breakf[1].breakfast="2)2 eggs, horne fries, toast";
    Breakf[2].breakfast="3)2 eggs and corn beef hash, horne fries and toast";
                                                                                    
    Breakf[3].breakfast="4)one pancake";
    Breakf[4].breakfast="5)short stack (2) pancakes";
    Breakf[5].breakfast="6)short stack with berries and whipped cream";

    Breakf[6].breakfast="7)plain omelette, fries and toast";
    Breakf[7].breakfast="8)cheese omelette, fries, toast";
    Breakf[8].breakfast="9)american omelette, fries and toast";

    Breakf[9].breakfast="10)bacon";
    Breakf[10].breakfast="11)sausage";
    Breakf[11].breakfast="12)english muffin";
    Breakf[12].breakfast="13)cold cereal";
    Breakf[13].breakfast="14)hot oatmeal";
    Breakf[14].breakfast="15)cottage cheese";

    Breakf[15].breakfast="16)coffee";
    Breakf[16].breakfast="17)tea";
    Breakf[17].breakfast="18)fresh squeezed juice";

    pbeakfast.bf[0]=100;
    pbeakfast.bf[1]=200;
    pbeakfast.bf[2]=250;
    pbeakfast.bf[3]=300;
    pbeakfast.bf[4]=600;
    pbeakfast.bf[5]=700;
    pbeakfast.bf[6]=150;
    pbeakfast.bf[7]=200;
    pbeakfast.bf[8]=180;
    pbeakfast.bf[9]=80;
    pbeakfast.bf[10]=95;
    pbeakfast.bf[11]=120;
    pbeakfast.bf[12]=170;
    pbeakfast.bf[13]=140;
    pbeakfast.bf[14]=190;
    pbeakfast.bf[15]=75;
    pbeakfast.bf[16]=50;
    pbeakfast.bf[17]=60;

    Desif[0].desifood="1)Eggplany pakora";
    Desif[1].desifood="2)Vegetable pakora";
    Desif[2].desifood="3)Samosa chaat";
    Desif[3].desifood="4)Masla dosas";
    Desif[4].desifood="5)Tandoori Roti";
    Desif[5].desifood="6)Keema naan";
    Desif[6].desifood="7)Cheese naan";
    Desif[7].desifood="8)Vegetable biryani";
    Desif[8].desifood="9)Chicken biryani";
    Desif[9].desifood="10)Paneer biryani";
    Desif[10].desifood="11)Chicken tandoori";
    Desif[11].desifood="12)Tandoori mix grill";
    
    PDesif.dff[0]=120;
    PDesif.dff[1]=120;
    PDesif.dff[2]=100;
    PDesif.dff[3]=200;
    PDesif.dff[4]=50;
    PDesif.dff[5]=70;
    PDesif.dff[6]=100;
    PDesif.dff[7]=250;
    PDesif.dff[8]=500;
    PDesif.dff[9]=450;
    PDesif.dff[10]=300;
    PDesif.dff[11]=550;

    Fastf[0].fastfood="1)Zinger burger";
    Fastf[1].fastfood="2)Tower burger";
    Fastf[2].fastfood="3)Jalapeno burger";
    Fastf[3].fastfood="4)Special pizza";
    Fastf[4].fastfood="5)Supreme pizza";
    Fastf[5].fastfood="6)Vegetarian pizza";
    Fastf[6].fastfood="7)Shawarma";
    Fastf[7].fastfood="8)Bar B Q wings";
    Fastf[8].fastfood="9)Soft drinks";
    Fastf[9].fastfood="10)Classical american beef steak";
    Fastf[10].fastfood="11)Classic pepper beef steak";
    Fastf[11].fastfood="12)Classical chicken pepper steak";
                                                                    
    PFastf.ff[0]=250;
    PFastf.ff[1]=280;
    PFastf.ff[2]=200;
    PFastf.ff[3]=1000;
    PFastf.ff[4]=950;
    PFastf.ff[5]=750;
    PFastf.ff[6]=150;
    PFastf.ff[7]=180;
    PFastf.ff[8]=50;
    PFastf.ff[9]=1200;
    PFastf.ff[10]=1100;
    PFastf.ff[11]=950;

    Desertf[0].Desert="1)Choclate chip cookies";       
    Desertf[1].Desert="2)Peach Cobbler";
    Desertf[2].Desert="3)Vanilla gelato";
    Desertf[3].Desert="4)Mascarphone cake with berries";
    Desertf[4].Desert="5)Cheesecake with rasberry coulis";               
    Desertf[5].Desert="6)Home made pastry cake";
    Desertf[6].Desert="7)Fruit of the forest juice";
    Desertf[7].Desert="8)Tempered chocolate coulant";           
    Desertf[8].Desert="9)Depurative juice";
                
    PDesertf.df[0]=100;
    PDesertf.df[1]=55;
    PDesertf.df[2]=200;
    PDesertf.df[3]=450;
    PDesertf.df[4]=500;
    PDesertf.df[5]=400;
    PDesertf.df[6]=200;
    PDesertf.df[7]=300;
    PDesertf.df[8]=200;


    gg=gender.at(0);

    if(gg=='m'|| gg=='M')
    {
        pro="He";
        pro1="gentleman";
    }
    else
    {
        pro="She";
        pro1="lady";
    }

    cout<<"\t\t\t*** Welcome to  Pablo chef ***"<<endl;
    cout<<"Chef: How are you sir? Who is this "<<pro1<<"?"<<endl;
    
    cout<<"Manager: Doing good just a bit hungry and tired.\n\t"<<pro<<" is "<<name<<". \n\t"<<pro<<" came here to visit  virtual city."<<endl;
    
    cout<<"Chef: oh I see ! Nice to meet to you "<<name <<" you are welcome to the virtual city.\n\t Please come in we serve the worlds best food."<<endl;
    
    cout<<name<<": Thanks chef!"<<endl;
    
    cout<<"Chef: Where would you like to dine in.\n\tWe have space in open area, on the roof top and also have the covered area."<<endl;
    cin.ignore();
    getline(cin, place);
    cout<<"Chef: As you wish ! Let me take you to the " <<place<<endl;

    c=ttime.at(0);

    switch(c)
    {

    case 'm':
    case 'M':

        cout<<"Chef: Isnt it a lovely morning."<<endl;
        
        cout<<"Manger: Indeed"<<endl;
        
        cout<<"Chef: The waiter is coming with the menu .\n\t Will see you later with the food . Enjoy!"<<endl;
        
        cout<<"Waiter: Welcome sir! As its moring so we are serving the breakfast.\n\tHere is the menu."<<endl;
        cout<<"**********************************************************************************"<<endl;
        cout<<"\t\t\t***Breakfat Menu***"<<endl<<endl;
        cout<<"EGG DISHES"<<endl;
        cout<<Breakf[0].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[0]<<endl;
        cout<<Breakf[1].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[1]<<endl;
        cout<<Breakf[2].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[2]<<endl<<endl;
        cout<<"SWEET STACKS"<<endl;
        cout<<Breakf[3].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[3]<<endl;
        cout<<Breakf[4].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[4]<<endl;
        cout<<Breakf[5].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[5]<<endl<<endl;
        cout<<"OMELETTES"<<endl;
        cout<<Breakf[6].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[6]<<endl;
        cout<<Breakf[7].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[7]<<endl;
        cout<<Breakf[8].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[8]<<endl<<endl;
        cout<<"SIDES"<<endl;
        cout<<Breakf[9].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[9]<<endl;
        cout<<Breakf[10].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[10]<<endl;
        cout<<Breakf[11].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[11]<<endl;
        cout<<Breakf[12].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[12]<<endl;
        cout<<Breakf[13].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[13]<<endl;
        cout<<Breakf[14].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[14]<<endl<<endl;
        cout<<"DRINKS"<<endl;
        cout<<Breakf[15].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[15]<<endl;
        cout<<Breakf[16].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[16]<<endl;
        cout<<Breakf[17].breakfast; cout<<"                                                            "; cout<<pbeakfast.bf[17]<<endl;
        cout<<"**********************************************************************************"<<endl;
        cout<<endl;
        cout<<"Waiter: What would you like to order."<<endl;
        cout<<"Manager: "<<name <<" will order"<<endl;
        cout<<"Waiter: How many items will you order?"<<endl;
        
        cin>>NumItemB;

        cout<<endl;
        cout<<"Kindly enter the dish number only.(for example if you want to order chicken biryani enter 9)"<<endl;
        for(int s=0; s<NumItemB; s++)
        {
            cin>>itemNumB[s];
            cout<<endl;
        }

        cout<<"Waiter: It would take 25 mins till then you can listen to the music or can read the newspaper"<<endl;
        cout<<"\t\t\t------------waiting-------------"<<endl;
        cout<<"Chef: Here is your food .Enjoy!"<<endl;

        cout<<"Manager: kindly sent the bill"<<endl;
        cout<<"Chef: Okay the waiter will soon give you the bill."<<endl;
        cout<<"Waiter: here is your bill."<<endl<<endl;
        cout<<"**********************************************************************************"<<endl;
        cout<<"\t\t\t->->->BILL<-<-<-"<<endl<<endl;
        for(int u=1 ; u<=12 ; u++)
        {
            for(int k=0 ; k<NumItemB; k++)
            {
                if(itemNumB[k]==u)
                {
                    cout<<Breakf[u-1].breakfast; 
                    cout<<"                                                            "; 
                    cout<<pbeakfast.bf[u-1]<<endl;
                }
            }
        }
        cout<<"**********************************************************************************"<<endl;
        
        cout<<"Total Amount ";
        cout<<"                                            ";
        cout<<customer.billformorning(NumItemB,itemNumB,pbeakfast);
        cout<<endl;

        int w;

        cout<<"Waiter: Which payment method you like to use"<<endl;
        cout<<"\t1)Credit card"<<endl; 
        cout<<"\t2)Cash."<<endl;
        cout<<"Enter 1 or 2"<<endl;
        cin>>w;
        if(w==1)
        {
            cout<<"Kindly enter the details of your credit card"<<endl;
            customer.SETCreditCard();
            cout<<endl;
            cout<<"Waiter: Here is your receipt"<<endl;
            customer.receiptForMorningCredit(NumItemB,itemNumB,pbeakfast);
        }
        else
        {
            int Cash;
            cout<<"Enter the amount"<<endl;
            cin>>Cash;
            cout<<"Waiter: Here is your receipt"<<endl;
            customer.receiptForMorningCash(NumItemB,itemNumB,pbeakfast,Cash);
        }

        cout<<"Chef:Thanks for visiting us!"<<endl;
        break;

    case 'n':
    case 'N':

        cout<<"Chef:Isn't it a lovely day"<<endl;
        cout<<"Chef: The waiter is coming with the menu .Will see you later with the food . Enjoy!"<<endl;
        cout<<"Waiter: Welcome sir! As its night time so we are serving dinner .\n\tHere is the menu.We serve desi food as well as Fast food .\n\t Here is the menu."<<endl<<endl;

        cout<<"**********************************************************************************"<<endl;
        cout<<"\t\t\t***Dinner Menu***"<<endl<<endl;
        cout<<"\t\t\t->->->DESI FOOD<-<-<-"<<endl<<endl;
        cout<<"APPETIZERS"<<endl;
        cout<<Desif[0].desifood;cout<<"                                  ";cout<<PDesif.dff[0]<<" Rs"<<endl;
        cout<<Desif[1].desifood;cout<<"                                 ";cout<<PDesif.dff[1]<<" Rs"<<endl;
        cout<<Desif[2].desifood;cout<<"                                     ";cout<<PDesif.dff[2]<<" Rs"<<endl;
        cout<<Desif[3].desifood;cout<<"                                      ";cout<<PDesif.dff[3]<<" Rs"<<endl<<endl;
        cout<<"SIDES AND BREADS"<<endl;
        cout<<Desif[4].desifood; cout<<"                                     ";cout<<PDesif.dff[4]<<" Rs"<<endl;
        cout<<Desif[5].desifood;cout<<"                                      ";cout<<PDesif.dff[5]<<" Rs"<<endl;
        cout<<Desif[6].desifood;cout<<"                                      ";cout<<PDesif.dff[6]<<" Rs"<<endl<<endl;
        cout<<"BIRYANI"<<endl;
        cout<<Desif[7].desifood;cout<<"                                ";cout<<PDesif.dff[7]<<" Rs"<<endl;
        cout<<Desif[8].desifood;cout<<"                                  ";cout<<PDesif.dff[8]<<" Rs"<<endl;
        cout<<Desif[9].desifood;cout<<"                                  ";cout<<PDesif.dff[9]<<" Rs"<<endl<<endl;
        cout<<"TANDOORI"<<endl;
        cout<<Desif[10].desifood;cout<<"                                ";cout<<PDesif.dff[10]<<" Rs"<<endl;
        cout<<Desif[11].desifood;cout<<"                              ";cout<<PDesif.dff[11]<<" Rs"<<endl<<endl;
        cout<<"\t\t\t->->->FAST FOOD<-<-<-"<<endl<<endl;
        cout<<"BURGER"<<endl;
        cout<<Fastf[0].fastfood;cout<<"                                            ";cout<<PFastf.ff[0]<<" Rs"<<endl;
        cout<<Fastf[1].fastfood;cout<<"                                             ";cout<<PFastf.ff[1]<<" Rs"<<endl;
        cout<<Fastf[2].fastfood;cout<<"                                          ";cout<<PFastf.ff[2]<<" Rs"<<endl<<endl;
        cout<<"PIZZA"<<endl;
        cout<<Fastf[3].fastfood;cout<<"                                            ";cout<<PFastf.ff[3]<<" Rs"<<endl;
        cout<<Fastf[4].fastfood;cout<<"                                            ";cout<<PFastf.ff[4]<<" Rs"<<endl;
        cout<<Fastf[5].fastfood;cout<<"                                          ";cout<<PFastf.ff[5]<<" Rs"<<endl<<endl;
        cout<<"SIDE ORDER"<<endl;
        cout<<Fastf[6].fastfood;cout<<"                                                 ";cout<<PFastf.ff[6]<<" Rs"<<endl;
        cout<<Fastf[7].fastfood;cout<<"                                            ";cout<<PFastf.ff[7]<<" Rs"<<endl;
        cout<<Fastf[8].fastfood;cout<<"                                              ";cout<<PFastf.ff[8]<<" Rs"<<endl<<endl;
        cout<<"STEAK"<<endl;
        cout<<Fastf[9].fastfood;cout<<"                            ";cout<<PFastf.ff[9]<<" Rs"<<endl;
        cout<<Fastf[10].fastfood;cout<<"                                ";cout<<PFastf.ff[10]<<" Rs"<<endl;
        cout<<Fastf[11].fastfood;cout<<"                           ";cout<<PFastf.ff[11]<<" Rs"<<endl;
        cout<<"**********************************************************************************"<<endl;
        cout<<endl;

        cout<<"Waiter: What would you like to order."<<endl;
        cout<<"Manager: "<<name <<" will order"<<endl;
        cout<<"Waiter: How many items will you order?(Desi food section)"<<endl;
        cin>>NumItemDi;

        cout<<endl;
        cout<<"Kindly enter the dish number only.(for example if you want to order chicken biryani enter 9)"<<endl;
        for(int s=0; s<NumItemDi; s++)
        {
            cin>>itemNumDi[s];
            cout<<endl;
        }
        
        cout<<"Waiter: How many items will you order?(fast food section)"<<endl;
        cin>>NumItemF;
        cout<<endl;
        cout<<"Kindly enter the dish number only.(for example if you want to order zinger burger enter 1)"<<endl;
        for(int a=0; a<NumItemF; a++)
        {
            cin>>itemNumF[a];
            cout<<endl;
        }
        
        cout<<"Waiter: It would take 25 mins till then you can listen to the music or can read the newspaper"<<endl;
        cout<<"\t\t\t------------waiting-------------"<<endl;
        cout<<"Chef: Here is your food .Hope you have an afternoon as lovely as you are.Enjoy!"<<endl;
        cout<<"Waiter:We also serve deserts would you like to have one (Y/N)?"<<endl;
        cin>>ds;
        cout<<endl;
        if(ds=='Y'||ds=='y')
        {
            cout<<"Here is the menu for the desert"<<endl<<endl;
            cout<<"**********************************************************************************"<<endl;
            cout<<"\t\t\t***Desert Menu***"<<endl<<endl;
            cout<<"MUFFINS"<<endl;
            cout<<Desertf[0].Desert;cout<<"                                        ";cout<< PDesertf.df[0]<<" Rs"<<endl;
            cout<<Desertf[1].Desert;cout<<"                                                 ";cout<< PDesertf.df[1]<<" Rs"<<endl;
            cout<<Desertf[2].Desert;cout<<"                                               ";cout<< PDesertf.df[2]<<" Rs"<<endl<<endl;
            cout<<"CAKES"<<endl;
            cout<<Desertf[3].Desert;cout<<"                                ";cout<< PDesertf.df[3]<<" Rs"<<endl;
            cout<<Desertf[4].Desert;cout<<"                              " ;cout<< PDesertf.df[4]<<" Rs"<<endl;
            cout<<Desertf[5].Desert;cout<<"                                        ";cout<< PDesertf.df[5]<<" Rs"<<endl<<endl;
            cout<<"SALTY DESERTS"<<endl;
            cout<<Desertf[6].Desert;cout<<"                                    ";cout<< PDesertf.df[6]<<" Rs"<<endl;
            cout<<Desertf[7].Desert;cout<<"                                   ";cout<< PDesertf.df[7]<<" Rs"<<endl;
            cout<<Desertf[8].Desert;cout<<"                                             ";cout<< PDesertf.df[8]<<" Rs"<<endl;
            cout<<"**********************************************************************************"<<endl;
            cout<<endl;
            cout<<"Waiter: How many items will you order?"<<endl;
            cin>>NumItemD;
            cout<<endl;
            cout<<"Kindly enter the dish number only.(for example if you want to order Vanilla gelato enter 3)"<<endl;
            for(int m=0; m<NumItemD; m++)
            {
                cin>>itemNumD[m];
                cout<<endl;
            }
            cout<<"Waiter : Thanks for ordering it would not take much time."<<endl;
            cout<<"\t\t\t---------waiting---------"<<endl;
            cout<<"Chef: Here is you delicious desert .Have fun"<<endl;
        }
        else
        {
            cout<<"Waiter : OK as you wish!"<<endl;
        }
        cout<<"Manager: kindly sent the bill"<<endl;
        cout<<"Chef: Okay the waiter will soon give you the bill."<<endl;
        cout<<"Waiter: here is your bill."<<endl<<endl;
        cout<<"**********************************************************************************"<<endl;
        cout<<"\t\t\t->->->BILL<-<-<-"<<endl<<endl;
        for(int u=1 ; u<=12 ; u++)
        {
            for(int k=0 ; k<NumItemDi; k++)
            {
                if(itemNumDi[k]==u)
                {
                    cout<<Desif[u-1].desifood;
                    cout<<"                                  ";
                    cout<<PDesif.dff[u-1]<<" Rs"<<endl;
                }
            }
        }

        for(int u=1 ; u<=12 ; u++) 
        {
            for(int k=0 ; k<NumItemF; k++)
            {
                if(itemNumF[k]==u)
                {
                    cout<<Fastf[u-1].fastfood;
                    cout<<"                                            ";
                    cout<<PFastf.ff[u-1]<<" Rs"<<endl;
                }
            }
        }    
        
        if(ds=='Y'||ds=='y')
        {
            for(int u=1 ; u<=9 ; u++)
            {
                for(int k=0 ; k<NumItemD; k++)
                {
                    if(itemNumD[k]==u)
                    {
                        cout<<Desertf[u-1].Desert;
                        cout<<"                                            ";
                        cout<<PDesertf.df[u-1]<<" Rs"<<endl;

                    }
                }
            }
        }   

        
        cout<<"**********************************************************************************"<<endl;
        cout<<"Total Amount ";
        cout<<"                                            ";
        cout<<customer.billForAfternoon(NumItemF ,itemNumF,ds, NumItemD, itemNumD,NumItemDi, itemNumDi,PDesif,PFastf,PDesertf);
        cout<<endl;

        int f;

        cout<<"Waiter: Which payment method you like to use"<<endl;
        cout<<"\t1)Credit card"<<endl; 
        cout<<"\t2)Cash."<<endl;
        cout<<"Enter 1 or 2"<<endl;

        cin>>f;

        if(f==1)
        {
            cout<<"Kindly enter the details of your credit card"<<endl;
            customer.SETCreditCard();
            cout<<endl;
            cout<<"Waiter: Here is your receipt"<<endl;
            customer.receiptForAfternoonCredit(NumItemF ,itemNumF,ds, NumItemD, itemNumD,NumItemDi, itemNumDi,PDesif,PFastf,PDesertf);
        }
        else
        {
            int Cash;
            cout<<"Enter the amount"<<endl;
            cin>>Cash;
            cout<<"Waiter: Here is your receipt"<<endl;
            customer.receiptForAfternoonCash(NumItemF ,itemNumF,ds, NumItemD, itemNumD,NumItemDi, itemNumDi,Cash,PDesif,PFastf,PDesertf);
        }

        cout<<"Chef:Thanks for visiting us!"<<endl;
        break;

    case 'a':
    case 'A':
        cout<<"Waiter: Welcome sir! As its afternoon so we are serving lunch .\n\tHere is the menu.We serve desi food as well as Fast food .\n\t Here is the menu."<<endl<<endl;
        cout<<"Chef: The waiter is coming with the menu .Will see you later with the food . Enjoy!"<<endl;

        cout<<"**********************************************************************************"<<endl;
        cout<<"\t\t\t***Lunch Menu***"<<endl<<endl;
        cout<<"\t\t\t->->->DESI FOOD<-<-<-"<<endl<<endl;
        cout<<"APPETIZERS"<<endl;
        cout<<Desif[0].desifood;cout<<"                                  ";cout<<PDesif.dff[0]<<" Rs"<<endl;
        cout<<Desif[1].desifood;cout<<"                                 ";cout<<PDesif.dff[1]<<" Rs"<<endl;
        cout<<Desif[2].desifood;cout<<"                                     ";cout<<PDesif.dff[2]<<" Rs"<<endl;
        cout<<Desif[3].desifood;cout<<"                                      ";cout<<PDesif.dff[3]<<" Rs"<<endl<<endl;
        cout<<"SIDES AND BREADS"<<endl;
        cout<<Desif[4].desifood; cout<<"                                     ";cout<<PDesif.dff[4]<<" Rs"<<endl;
        cout<<Desif[5].desifood;cout<<"                                      ";cout<<PDesif.dff[5]<<" Rs"<<endl;
        cout<<Desif[6].desifood;cout<<"                                      ";cout<<PDesif.dff[6]<<" Rs"<<endl<<endl;
        cout<<"BIRYANI"<<endl;
        cout<<Desif[7].desifood;cout<<"                                ";cout<<PDesif.dff[7]<<" Rs"<<endl;
        cout<<Desif[8].desifood;cout<<"                                  ";cout<<PDesif.dff[8]<<" Rs"<<endl;
        cout<<Desif[9].desifood;cout<<"                                  ";cout<<PDesif.dff[9]<<" Rs"<<endl<<endl;
        cout<<"TANDOORI"<<endl;
        cout<<Desif[10].desifood;cout<<"                                ";cout<<PDesif.dff[10]<<" Rs"<<endl;
        cout<<Desif[11].desifood;cout<<"                              ";cout<<PDesif.dff[11]<<" Rs"<<endl<<endl;
        cout<<"\t\t\t->->->FAST FOOD<-<-<-"<<endl<<endl;
        cout<<"BURGER"<<endl;
        cout<<Fastf[0].fastfood;cout<<"                                            ";cout<<PFastf.ff[0]<<" Rs"<<endl;
        cout<<Fastf[1].fastfood;cout<<"                                             ";cout<<PFastf.ff[1]<<" Rs"<<endl;
        cout<<Fastf[2].fastfood;cout<<"                                          ";cout<<PFastf.ff[2]<<" Rs"<<endl<<endl;
        cout<<"PIZZA"<<endl;
        cout<<Fastf[3].fastfood;cout<<"                                            ";cout<<PFastf.ff[3]<<" Rs"<<endl;
        cout<<Fastf[4].fastfood;cout<<"                                            ";cout<<PFastf.ff[4]<<" Rs"<<endl;
        cout<<Fastf[5].fastfood;cout<<"                                          ";cout<<PFastf.ff[5]<<" Rs"<<endl<<endl;
        cout<<"SIDE ORDER"<<endl;
        cout<<Fastf[6].fastfood;cout<<"                                                 ";cout<<PFastf.ff[6]<<" Rs"<<endl;
        cout<<Fastf[7].fastfood;cout<<"                                            ";cout<<PFastf.ff[7]<<" Rs"<<endl;
        cout<<Fastf[8].fastfood;cout<<"                                              ";cout<<PFastf.ff[8]<<" Rs"<<endl<<endl;
        cout<<"STEAK"<<endl;
        cout<<Fastf[9].fastfood;cout<<"                            ";cout<<PFastf.ff[9]<<" Rs"<<endl;
        cout<<Fastf[10].fastfood;cout<<"                                ";cout<<PFastf.ff[10]<<" Rs"<<endl;
        cout<<Fastf[11].fastfood;cout<<"                           ";cout<<PFastf.ff[11]<<" Rs"<<endl;
        cout<<"**********************************************************************************"<<endl;
        cout<<endl;

        cout<<"Waiter: What would you like to order."<<endl;
        cout<<"Manager: "<<name <<" will order"<<endl;
        cout<<"Waiter: How many items will you order?(Desi food section)"<<endl;
        cin>>NumItemDi;

        cout<<endl;
        cout<<"Kindly enter the dish number only.(for example if you want to order chicken biryani enter 9)"<<endl;
        for(int s=0; s<NumItemDi; s++)
        {
            cin>>itemNumDi[s];
            cout<<endl;
        }
        
        cout<<"Waiter: How many items will you order?(fast food section)"<<endl;
        cin>>NumItemF;
        cout<<endl;
        cout<<"Kindly enter the dish number only.(for example if you want to order zinger burger enter 1)"<<endl;
        for(int a=0; a<NumItemF; a++)
        {
            cin>>itemNumF[a];
            cout<<endl;
        }
        
        
        cout<<"Waiter: It would take 25 mins till then you can listen to the music or can read the newspaper"<<endl;
        cout<<"\t\t\t------------waiting-------------"<<endl;
        cout<<"Chef: Here is your food .Hope you have an afternoon as lovely as you are.Enjoy!"<<endl;
        cout<<"Waiter:We also serve deserts would you like to have one (Y/N)?"<<endl;
        cin>>ds;
        cout<<endl;

        if(ds=='Y'||ds=='y')
        {
            cout<<"Here is the menu for the desert"<<endl<<endl;
            cout<<"**********************************************************************************"<<endl;
            cout<<"\t\t\t***Desert Menu***"<<endl<<endl;
            cout<<"MUFFINS"<<endl;
            cout<<Desertf[0].Desert;cout<<"                                        ";cout<< PDesertf.df[0]<<" Rs"<<endl;
            cout<<Desertf[1].Desert;cout<<"                                                 ";cout<< PDesertf.df[1]<<" Rs"<<endl;
            cout<<Desertf[2].Desert;cout<<"                                               ";cout<< PDesertf.df[2]<<" Rs"<<endl<<endl;
            cout<<"CAKES"<<endl;
            cout<<Desertf[3].Desert;cout<<"                                ";cout<< PDesertf.df[3]<<" Rs"<<endl;
            cout<<Desertf[4].Desert;cout<<"                              " ;cout<< PDesertf.df[4]<<" Rs"<<endl;
            cout<<Desertf[5].Desert;cout<<"                                        ";cout<< PDesertf.df[5]<<" Rs"<<endl<<endl;
            cout<<"SALTY DESERTS"<<endl;
            cout<<Desertf[6].Desert;cout<<"                                    ";cout<< PDesertf.df[6]<<" Rs"<<endl;
            cout<<Desertf[7].Desert;cout<<"                                   ";cout<< PDesertf.df[7]<<" Rs"<<endl;
            cout<<Desertf[8].Desert;cout<<"                                             ";cout<< PDesertf.df[8]<<" Rs"<<endl;
            cout<<"**********************************************************************************"<<endl;
            cout<<endl;
            cout<<"Waiter: How many items will you order?"<<endl;
            cin>>NumItemD;
            cout<<endl;
            cout<<"Kindly enter the dish number only.(for example if you want to order Vanilla gelato enter 3)"<<endl;
            for(int m=0; m<NumItemD; m++)
            {
                cin>>itemNumD[m];
                cout<<endl;
            }
            cout<<"Waiter : Thanks for ordering it would not take much time."<<endl;
            cout<<"\t\t\t---------waiting---------"<<endl;
            cout<<"Chef: Here is you delicious desert .Have fun"<<endl;
        }
        else
        {
            cout<<"Waiter : OK as you wish!"<<endl;
        }
        cout<<"Manager: kindly sent the bill"<<endl;
        cout<<"Chef: Okay the waiter will soon give you the bill."<<endl;
        cout<<"Waiter: here is your bill."<<endl<<endl;
        cout<<"**********************************************************************************"<<endl;
        cout<<"\t\t\t->->->BILL<-<-<-"<<endl<<endl;
        for(int u=1 ; u<=12 ; u++)
        {
            for(int k=0 ; k<NumItemDi; k++)
            {
                if(itemNumDi[k]==u)
                {
                    cout<<Desif[u-1].desifood;
                    cout<<"                                  ";
                    cout<<PDesif.dff[u-1]<<" Rs"<<endl;
                }
            }
        }

        for(int u=1 ; u<=12 ; u++)
        {
            for(int k=0 ; k<NumItemF; k++)
            {
                if(itemNumF[k]==u)
                {
                    cout<<Fastf[u-1].fastfood;
                    cout<<"                                            ";
                    cout<<PFastf.ff[u-1]<<" Rs"<<endl;
                }
            }
        }    
        
        if(ds=='Y'||ds=='y')
        {
            for(int u=1 ; u<=9 ; u++)
            {
                for(int k=0 ; k<NumItemD; k++)
                {
                    if(itemNumD[k]==u)
                    {
                    cout<<Desertf[u-1].Desert;
                    cout<<"                                            ";
                    cout<<PDesertf.df[u-1]<<" Rs"<<endl;

                    }
                }
            }
        }   

        
        cout<<"**********************************************************************************"<<endl;
        cout<<"Total Amount ";
        cout<<"                                            ";
        cout<<customer.billForAfternoon(NumItemF ,itemNumF,ds, NumItemD, itemNumD,NumItemDi, itemNumDi,PDesif,PFastf,PDesertf);
        cout<<endl;
        int h;

        cout<<"Waiter: Which payment method you like to use"<<endl;
        cout<<"\t1)Credit card"<<endl; 
        cout<<"\t2)Cash."<<endl;
        cout<<"Enter 1 or 2"<<endl;
        cin>>h;

        if(h==1)
        {
            cout<<"Kindly enter the details of your credit card"<<endl;
            customer.SETCreditCard();
            cout<<endl;
            cout<<"Waiter: Here is your receipt"<<endl;
            customer.receiptForAfternoonCredit(NumItemF ,itemNumF,ds, NumItemD, itemNumD,NumItemDi, itemNumDi,PDesif,PFastf,PDesertf);
        }
        else
        {
            int Cash;
            cout<<"Enter the amount"<<endl;
            cin>>Cash;
            cout<<"Waiter: Here is your receipt"<<endl;
            customer.receiptForAfternoonCash(NumItemF ,itemNumF,ds, NumItemD, itemNumD,NumItemDi, itemNumDi,Cash,PDesif,PFastf,PDesertf);
        }
        cout<<"Chef:Thanks for visiting us!"<<endl;
        break;
    }

}

class mall
{
public:
  int brands;
  void show()
  {
    ifstream x("mall.txt");
    if (!x)
      cout << "\nNo of Outlets = 10\n";
    else
    {
      x >> brands;
      cout << "\nTOTAL BRAND OUTLETS:  " << brands << endl;
      x.close();
    }
  }
};
class Eproduct : public virtual mall
{
public:
  int quan;
  char name[20];
  char color[20];
  char size[20];
  int checkout;


  void cal()
  {
    
  }
  void file();
  void get();
};
void Eproduct::get()
{
  int s;
  cout << "\nChoose Brand : \n";
  cout << "\n1.J. Junaid Jamshaid";
  cout << "\n2.Ethnic Outfitters";
  cout << "\n3.Khaddi";
  cout << "\n4.Gul Ahmed";
  cout << "\n5.Al-Karam Studio \n";
  cin >> s;

  cout << "\ninput product name: \nfor instance: Shirt,Trousers,Scarf \n";
  cin >> name;
  cout << "\ninput product color: \nAvailable colors: Red,Black,Blue,Handprinted,Multicolored \n";
  cin >> color;
  cout << "\ninput size of product: \nAvailable Sizes: Small,Medium,Large,Extra-Large \n";
  cin >> size;
  cout << "\ntotal product quantity: \n";
  cin >> quan;
  cout<< "\nPlease press 1 to checkout \n";
  cin >> checkout;
  cout<< "\n======================================================================================\n";
  cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
  cout<< "\n======================================================================================\n";
  cal();
  file();
}
void Eproduct::file()
{
  char file[20];
  strcpy(file, color);
  strcat(file, ".txt");
  ofstream f(file);
  f << "\nproduct name: " << name << "\nproduct id: " << color << "\ncost price of product: " << size << "\nquantity: " << quan;
  f.close();
}

class Wproduct : public virtual mall
{
protected:
  int BRAND;
  char pname[20];
  char pcolor[10];
  char psize[20];
  int postquan;
  int Wchkt;
  void cal()
  {
    cout<< "\nHappy Shopping \n";
  }
  void getstaff();
  void file();
};
void Wproduct::getstaff()
{
  cout << "\nChoose Brand: \n";
  cout << "\n1.GUCCI \n";
  cout << "\n2.Versace: \n";
  cout << "\n3.Louis Vuitton: \n";
  cout << "\n4.Dior: \n";
  cout << "\n5.ZARA: \n";

  cin >> BRAND;
  cout << "\ninput product name: \nfor instance: Shirt,Trousers,Scarf: \n";
  cin >> pname;
  cout << "\ninput product color: \nAvailable colors: Red,Black,Blue,Handprinted,Multicolored \n";
  cin >> pcolor;
  cout << "\ninput size of product: \nAvailable Sizes: Small,Medium,Large,Extra-Large \n";
  cin >> psize;
  cout << "\ntotal product quantity: \n";
  cin >> postquan;
  cout<< "\nPlease press 1 to checkout \n";
  cin >> Wchkt;
  cout<< "\n======================================================================================\n";
  cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
  cout<< "\n======================================================================================\n";
  cal();
  file();
  // }
}
void Wproduct::file()
{
  char file[20];
  strcpy(file, pcolor);
  strcat(file, ".txt");
  ofstream f(file);
  f << "\nnumber of products: " << postquan << "\nproduct brand: " << BRAND << "\nproduct name :" << pname << "\nproduct color: " << pcolor;
  f.close();
}

class amount : public Wproduct, public Eproduct
{

public:
  void add();
  void update_item();
  void update_emp();
};
void amount::add()
{
  int ch;
  char name[20];
  while (1)
  {
    cout << "1.)Eastren Outfits\n2.)Westren Outfits\n3.)Exit\n";
    cout << "Enter choice\n";
    cin >> ch;
    if (ch == 1)
    {
      get();
      ofstream x("ooo.txt");
      x << brands;
      x.close();
    }
    else if (ch == 2)
    {
      getstaff();
      ofstream x("ooo.txt");
      x << brands;
      x.close();
    }
    else if (ch == 3)
      break;
    else
      cout << "Invaid Option. Please re-enter\n";
  }
}

void amount::update_item()
{
  char id[20];
  char pid[20];
  char c;
  cout << "\nINPUT product ID to modify\n";
  cin >> id;
  char file[20];
  char file2[20];
  strcpy(file, id);
  strcat(file, ".txt");
  fstream fout(file, ios::in | ios::out);
  if (!fout)
  {
    cout << "file couldn't be opened. product ID not found. \n";
  }
  else
  {
    cout << "file found! \n";
    cout << "\nupdate product name: \n";
    cin >> name;
    cout << "\nupdate total product quantity: \n";
    cin >> quan;
  }
}
void amount::update_emp()
{
  char id[20];
  char c;
  cout << "\nINPUT item ID to modify: ";
  cin >> id;
  char file[20];
  strcpy(file, id);
  strcat(file, ".txt");
  fstream fout(file, ios::in | ios::out);
  if (!fout)
  {
    cout << "file couldn't be opened. product ID not found. \n";
  }
  cout << "modify item type: \n";
  cin >> pname;
  fout << "\nnumber of items: " << postquan << "\nitem brand: " << BRAND << "\nitem name :" << pname << "\nitem color: " << pcolor;
  fout.close();
}

void admin()
{
  while (1)
  {
    cout << "\n\t\t\t==============================\n";
    cout << "\n\t\t\t     WELCOME TO THE CITY MALL  \n";
    cout << "\n\t\t\t==============================\n\n";
    cout << "\n\t\t\t* * * * * * * * * * * * * * * *\n";
    cout << "\n\t\t\t1. Clothes\n\n\t\t\t2. Shoestore\n\n\t\t\t3. Bookstore\n\n\t\t\t4. Games Store\n\n\t\t\t5.Exit\n";
    cout << "\n\n\t\t\tSelect your choice\n";
    int u;
    cin >> u;
    if (u == 1)
    {
      amount a;
      a.show();
      a.add();
    }
    else if (u == 2)
    {
      char shoeM[20];
      char Sstyle[20];
      char Scolor[10];
      int Sz;
      int Np;
      int Schkt;
      cout << "\nWELCOME TO THE ShoeStore \n";
      cout << "\n=============================\n";
      cout << "\nPlease select the material \nIn Stock; Leather,Textile,Plastic,Velvet,Fiber\n";
      cin >> shoeM;
      cout << "\nPlease select the style\nFor Men ; Shoes or Sandles\nFor Women ; Heels or Flats\n";
      cin >> Sstyle;
      cout << "\nPlease choose the color \nAvailable in ; Black,Grey and Blue\n";
      cin >> Scolor;
      cout << "\nPlease enter the size\n";
      cin >> Sz;
      cout << "\nPlease enter the no of pairs to be purchased \n";
      cin >> Np;
      cout<< "\nPlease press 1 to checkout \n";
      cin >> Schkt;
      cout<< "\n======================================================================================\n";
      cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
      cout<< "\n======================================================================================\n";

     
    }
    else if (u == 3)
    {
      char Bname[20];
      char Aname[20];
      int copies;
      int Bchkt;
      cout << "\nWELCOME TO THE BOOKSTORE \n";
      cout << "\n=============================\n";
      cout << "\nPlease enter the book you are looking for \n In Stock ; FIASCO,ROIT,DIVERGENT,JINNAH,ARTSY,COLUMBUS \n";
      cin >> Bname;
      cout << "\nPlease enter the Author's name \n Books by ; JOHNSON,WILLIAMS,PERRY,HENREY,MUZAFIR,ADAMS \n";
      cin >> Aname;
      cout << "\nPlease enter the no of copies \n";
      cin >> copies;
      cout<< "\nPlease press 1 to checkout \n";
      cin >> Bchkt;
      cout<< "\n======================================================================================\n";
      cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
      cout<< "\n======================================================================================\n";
      
    }
    else if (u == 4)
    {
      char Gname[20];
      char Psname[20];
      int Drives;
      int Gchkt;
      cout << "\nWELCOME TO THE Games Store \n";
      cout << "\n=============================\n";
      cout << "\nPlease enter the Video Game you are looking for \n Currently Available ; SIMS , BLACK , FORTNITE , MINECRAFT , ROBLOX , OVERWATCH\n";
      cin >> Gname;
      cout << "\nPlease select the play station\nIn Stock for; Ps3 and Ps4\n";
      cin >> Psname;
      cout << "\nPlease enter the no of drives \n";
      cin >> Drives;
      cout<< "\nPlease press 1 to checkout \n";
      cin >> Gchkt;
      cout<< "\n======================================================================================\n";
      cout<< "\nTHANKYOU for your visit,you will be checked out shortly via message.Happy Shopping\n";
      cout<< "\n======================================================================================\n";
    }
    else if (u == 5)
    {
      break;
    }
    else
      cout << "Invalid option. Please select one of the available options\n";
  }
}

void Mall()

{
  int ch;
  do
  {
    cout << "\n \t\t\t=========================\n";
    cout << "\n\t\t\tWELCOME TO THE CITY MALL  \n";
    cout << "\n \t\t\t=========================\n\n";
    cout << "\n \t\t\t* * * * * * * * * * * * ";
    cout << "\n\t\t\t  1. VIEW MENU";
    cout << "\n\t\t\t  2. BACK TO MAIN MENU";
    cout << "\n\t\t\t* * * * * * * * * * * *\n";
    cout << "\n\t\t\t Enter Your choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
      admin();
      break;
    default:
      break;
    }
  }while(ch!= 2);
}

class vehicles
{
    public:
    string name1;
    string receipt_number;
    string chassis_number;
    string engine_number;
    string model;
    string check;
    float price;
    int seconds = 0;
    // Create Objects of Ofstream and ifstream 
    ofstream myfile , fout;  
    ifstream fin;

    void getData();
    void computer_data();
    bool isexist(string check);
    void MRI();             // MRI = Motor Registering Inspector
    void intial_sign();
    
	
    // MRA = Motor Resgistering Authority
    bool MRA(string receipt_number,string chassis_number,string engine_number,string model )                             
    {
        int flag = 0;
        // checking recript number

        if (receipt_number.length() == 6)
        {
            for (int i = 0; i <= receipt_number.length() ; i++)
            {
                
                switch (i)
                {
                case 0:
                    if (isalpha(receipt_number[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 1:
                    if (isalpha(receipt_number[i]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 2:
                    if (receipt_number[i]== '-')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 3:
                    if (isdigit(receipt_number[i]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 4:
                    if (isdigit(receipt_number[i]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 5:
                    if (isdigit(receipt_number[i]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                
                default:
                    break;
                }
                
                if (flag==1)
                {
                    break;
                }
                
            }
            
        }
        else
        {
            flag = 1;
            cout<<"Receipt Number not in range."<<endl;              // for out of range
        }


        // checking chassis number


        if (chassis_number.length() == 8)
        {
            for (int i = 0; i <= chassis_number.length() ; i++)
            {
                
                switch (i)
                {
                case 0:
                    if (isalpha(chassis_number[0]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 1:
                    if (isalpha(chassis_number[1]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 2:
                    if (isdigit(chassis_number[2]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 3:
                    if (isdigit(chassis_number[3]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 4:
                    if (isdigit(chassis_number[4]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 5:
                    if (isdigit(chassis_number[5]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 6:
                    if (isdigit(chassis_number[6]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 7:
                    if (isdigit(chassis_number[7]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Chassis number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                default:
                    break;
                }
                if (flag==1)
                {
                    break;
                }
                
            }
            
        }
        else
        {
            flag = 1;
            cout<<"Chassis Number not in range."<<endl;              // for out of range
        }

        // checking engine number


        if (engine_number.length() == 7)
        {
            for (int i = 0; i <= engine_number.length() ; i++)
            {
                
                switch (i)
                {
                case 0:
                    if (isdigit(engine_number[0]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Engine number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 1:
                    if (isdigit(engine_number[1]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Engine number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 2:
                    if (isdigit(engine_number[2]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Engine number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 3:
                    if (isdigit(engine_number[3]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Engine number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 4:
                    if (isdigit(engine_number[4]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Engine number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 5:
                    if (isdigit(engine_number[5]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Engine number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 6:
                    if (isdigit(engine_number[6]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Engine number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                default:
                    break;
                }
                if (flag==1)
                {
                    break;
                }
                
            }
            
        }
        else
        {
            flag = 1;
            cout<<"Engine Number not in range."<<endl;              // for out of range
        }

        // checking model

        if (model.length() == 4)
        {
            for (int i = 0; i <= model.length() ; i++)
            {
                
                switch (i)
                {
                case 0:
                    if (isdigit(model[0]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 1:
                    if (isdigit(model[1]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 2:
                    if (isdigit(model[2]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 3:
                    if (isdigit(model[3]))
                    {
                        break;
                    }
                    else
                    {
                        cout<<"Receipt number is invalid."<<endl;
                        flag=1;
                    }
                    break;

                default:
                    break;
                }
                if (flag==1)
                {
                    break;
                }
                
            }
            
        }
        else
        {
            flag = 1;
            cout<<"Model not in range."<<endl;              // for out of range
        }
        if (flag==1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

};

void vehicles::getData()
{
    cout<<"Please provide the infomation:\n\n";
    cout<<"Enter Receipt Number: "<<endl<<"Sample: XY-123 "<<endl;
	cin>>receipt_number;
    cout<<"Enter your Name: "<<endl;
    cin.ignore();
    getline(cin,name1);
    //cin>>name;
    cout<<"Enter the price of the vehical: "<<endl;
	cin>>price;
	cout<<"Enter Chassis Number: "<<endl<<"Sample: AB000000 "<<endl;
	cin>>chassis_number;
    cout<<"Enter Engine Number: "<<endl<<"Sample: 0000000 "<<endl;
	cin>>engine_number;
	cout<<"Enter Model: "<<endl<<"Sample: 0000 "<<endl;
	cin>>model;
    using namespace this_thread;     // sleep_for, sleep_until
    using namespace chrono_literals; // ns, us, ms, s, h, etc.
    using chrono::system_clock;

    cout<<"Please wait..."<<endl;
    sleep_for(2s);
    sleep_until(system_clock::now() + 1s);
    cout<<"Thanks for the information."<<endl;
}
void vehicles::computer_data()      // saving data in the MVRS(Motor Vehicle Registering System)
{
    myfile.open (name1+".txt");
    myfile <<"Receipt number is: "<< receipt_number<<endl;
    myfile <<"Name: "<< name1 <<endl;
    myfile <<"Price: "<< price <<endl;
    myfile <<"Chassis number is: "<< chassis_number<<endl;
    myfile <<"Engine number is: "<< engine_number<<endl;
    myfile <<"Model is: "<< model;
    myfile.close();
    
    if (isexist(name1+".txt")==true)
    {               
        cout<<"Data has been stored successfully."<<endl;
    }
    else
    {
        cout<<"Data is not stored."<<endl;
    }
    
}
void vehicles:: MRI()
    {

        float registration_fees = price *1/100 ;
        int registration_book_fees = 650;
        int number_plate_charges = 560;
        int life_token = 1500;
        float payment_receipt = registration_fees+registration_book_fees+ number_plate_charges+life_token;

        myfile.open(name1+"_Payment_Receipt.txt");
        myfile <<"Receipt number is: "<< receipt_number<<endl;
        myfile <<"Name: "<< name1 <<endl;
        myfile <<"Registration fees: "<<registration_fees<<endl;
        myfile <<"Registration book fees: "<<registration_book_fees<<endl;
        myfile <<"Number plate charges: "<<number_plate_charges<<endl;
        myfile <<"Life token: "<<life_token<<endl;
        myfile <<"Payment Receipt: "<<payment_receipt;
        myfile.close();
    }

bool vehicles::isexist(string name1)
{
    
    fin.open(name1);
    if(fin) 
    {
        return true;
    } 
    else
    {
        return false;
    }
}

void vehicles::intial_sign()
{
    fin.open(name1+".txt");
    fout.open (name1+".txt" , ios::app); // Append mode
    if(fin.is_open())
    {
        fout<< "\n\nApproved!!\n"; // Writing data to file
    }
    fin.close();
    fout.close(); // Closing the file
}

void Excise_and_taxation_department()
{
    vehicles v1;
    int selection;

    do
    {
        cout<<"Welcome to Excise and taxation department"<<endl;
        cout<<"1. Registration of vehicle"<<endl;
        cout<<"0. Back to main menu"<<endl;
        cin>>selection;
        switch (selection)
        {
            case 1:
                v1.getData();
                while (v1.MRA(v1.receipt_number,v1.chassis_number,v1.engine_number,v1.model)!=true)
                {
                    v1.getData();
                }

                v1.computer_data();

                v1.MRI();        
            
                using namespace this_thread;     // sleep_for, sleep_until
                using namespace chrono_literals; // ns, us, ms, s, h, etc.
                using chrono::system_clock;
                
                cout<<"Checking your file, please wait."<<endl;
                sleep_for(3s);
                sleep_until(system_clock::now() + 1s);
                cout<<"Approved!!"<<endl;
                v1.intial_sign();

                break;

            default:
                cout<<"Invalid choice"<<endl;
                break;
        }

    } while (selection != 0);
    
}



class PAL: public vehicles  // Police Assistance Line (PAL)
{
    public:
    string name2;
    string cnic;   
    string subject;
    string problem;
    string details;
    ofstream file , outFile;   
    ifstream inFile;

    void get_information();
    void application();
    void commissioner();
    void police_center();
    bool checker(string cnic)
    {
        int flag = 0;

        if (cnic.length() == 15)
        {
            for (int i = 0; i <= cnic.length() ; i++)
            {
                switch (i)
                {
                case 0:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;

                case 1:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 2:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 3:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 4:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 5:
                    if (cnic[i]== '-')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 6:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 7:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 8:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 9:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 10:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 11:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 12:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 13:
                    if (cnic[i]== '-')
                    {
                        break;
                    }
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;
                case 14:
                    if (isdigit(cnic[i]))
                    {
                        break;
                    } 
                    else
                    {
                        cout<<"CNIC number is invalid."<<endl;
                        flag=1;
                    }
                    break;                   

                default:
                    break;
                }
                
                if (flag==1)
                {
                    break;
                }
                
            }
            
        }
        else
        {
            flag = 1;
            cout<<"CNIC Number not in range."<<endl;              // for out of range
        }       
        if (flag==1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    void report_check();
};

void PAL::get_information()
{   
    cout<<"Enter your Name: ";
    cin.ignore();
    getline(cin,name2);

    cout<<"Enter your CNIC number"<<endl<<"Sample: 12345-1234567-1 "<<endl;
    
    getline(cin,cnic);

    cout<<"Subject of report: ";
 
    getline(cin,subject);
    cout<<"Details: ";
    getline(cin,details);    
}

void PAL::application()
{
    file.open (name2+".txt");
    
    file <<"Name: "<< name2 <<endl;
    file <<"CNIC number: "<< cnic <<endl;
    file <<"Subject of report: "<< subject<<endl;
    file <<"Details: "<< details;
    file.close();
}

void PAL::commissioner()
{
    if (isexist(name2+".txt")==true)
    {               
        
        inFile.seekg(0, ios::end);  
        if (inFile.tellg() == 0) 
        {    
            application();
        }
        else
        {
            inFile.open(name2+".txt");
            outFile.open (name2+".txt" , ios::app); // Append mode
            if(inFile.is_open())
            {
                outFile<< "\n\nApproved!!\n"; // Writing data to file
            }
            inFile.close();
            outFile.close(); // Closing the file
            }
    }
    else
    {
        application();
    }

}

void PAL::police_center()
{
    bool is_here=0;

    inFile.open(name2+".txt");

    string find = "Approved!!";

    while(!inFile.eof())
	{
		string temp = "";
        
		getline(inFile,temp);

		for(int i=0;i<find.size();i++)
		{
            temp[i] = find[i];
            
            if(temp[i]==find[i])
            {
				is_here = 1;
            }
			else
			{
				is_here = 0;
				break;
			}
		}
	}

    inFile.close();
    if (is_here == 1)
    {
        cout<<"Thank you sir we will work on your application soon.\nThanks for visiting."<<endl;
    }
    else
    {
        cout<<"Sir your application is not correct... please bring the correct application."<<endl;
    }
}

void Police_Station()
{
    PAL p;
    int selection;

    do
    {
        cout<<"Welcome to Police Station"<<endl;
        cout<<"1. Report"<<endl;
        cout<<"0. Back to main menu"<<endl;
        cin>>selection;
        switch (selection)
        {
            case 1:
                p.get_information();

                while (p.checker(p.cnic)!=true)
                {
                    p.get_information();
                }

                using namespace this_thread;     // sleep_for, sleep_until
                using namespace chrono_literals; // ns, us, ms, s, h, etc.
                using chrono::system_clock;

                cout<<"Please wait..."<<endl;
                sleep_for(2s);
                sleep_until(system_clock::now() + 1s);
                cout<<"Your application has been noted."<<endl;

                p.application();
                using namespace this_thread;     // sleep_for, sleep_until
                using namespace chrono_literals; // ns, us, ms, s, h, etc.
                using chrono::system_clock;

                cout<<"Please wait will Commissioner is checking your file..."<<endl;
                sleep_for(3s);
                sleep_until(system_clock::now() + 1s);
                p.commissioner();
                cout<<"Your file has been checked!"<<endl;


                using namespace this_thread;     // sleep_for, sleep_until
                using namespace chrono_literals; // ns, us, ms, s, h, etc.
                using chrono::system_clock;

                cout<<"Forwarding your file to the Police Center..."<<endl;
                sleep_for(2s);
                sleep_until(system_clock::now() + 1s);
                p.police_center();

                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }

    } while (selection != 0);
}


class medicineType
{
public:

    void take_order();
    void order_list();
	void exit();  
	medicineType();//constuctor

};

medicineType::medicineType ()
{

}	


struct node //constract node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Panadol","Vitamin C(500mg)","Azithromycin","Morphine","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;				//pointer declaration 


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

void medicineType::take_order()		//function to take_order
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n"<<endl;

	node *temp;
	temp=new node;

				cout<<"Drugs ID "<<"\tDrugs Type"<<"   \t\tDrugs Name"<<"          Drugs price"<<endl;
				cout <<"**************************************************************************\n";
                cout<<"01"<<"\t"<<"\tOTC"<<"\t\t"<<"    Panadol"<<"			 2.00"<<endl;
                cout<<"02"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		 3.00"<<endl;
                cout<<"03"<<"\t"<<"\tOTC"<<"\t\t"<<"    Azithromycin"<<"		 1.00"<<endl;
                cout<<"04"<<"\t"<<"\tOTC"<<"\t\t"<<"    Morphine"<<"		 4.00"<<endl;
                cout<<"05"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	 	 1.00"<<endl;
                cout<<"06"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		 5.00"<<endl;
                cout<<"07"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		 7.00"<<endl;
                cout<<"08"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"			 4.00"<<endl;
                cout<<"09"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			 3.00"<<endl;
                cout<<"10"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		 5.00"<<endl;
                cout<<" "<<endl;
    
	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->reciept_number;
	cout<< "Enter Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" rupees"<<endl;
        system("PAUSE");
                      
	}
    cout << "Order Taken Successfully"<<endl;
    cout<<"--------------------------------------------------------------------------"<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"---------------------------------------------------------------------------"<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order


void medicineType::order_list()		//Function to display receipt
{
	int i, num, num2;	
	bool found;			//variable to search 
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"=--------------------------------------------------------------------------"<<endl;
	cout <<"\t\tHere is the Order list\n"; 


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"Reciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;
				

			
		cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" RM"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


}
}	//End function receipt


void medicineType::exit() 
{
	cout<<"\nYou choose to exit.\n"<<endl;
}	

void Pharmacy()
{
    system("COLOR 0");	
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t   Welcome to pharmacy \n"<<endl;
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t3. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
			case 1:
			{
				medicine.take_order();	//function add
				break;
			}	//end case 1
			

		case 2:
			{
				medicine.order_list();	//function order
				system("PAUSE");
				break;
			}	//end case 2
        case 3:
			{
				medicine.exit();	//function exit
				goto a;
				break;
			}	//end case 3

		
		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}//end defeault
		}//end Switch
	}while(menu!=3);//end do
	a://goto
	cout<<"thank you"<<endl;
	system ("PAUSE");
}

