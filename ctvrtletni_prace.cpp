#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    string pokracovani;
    int vyberHlavni,/* urcuje akci v hlavnim menu*/podVyber, zboziLoop;
    //pozice zbozi v arrayi odpovida ostatnim arrayum
    string zbozi [4] [4]={
          { "Rolls",  "Buns", "Bread", "Donuts"}, //rohliky, housky, chleba, koblizky
          { "Coffee", "Cola", "Virnea", "Water"}, //kava, cola, vinea, water
          { "Kitcat", "Polomacene Oktavia", "Orao", "Snackers"},//dobroty bez slevy
          { "Kitcat", "Polomacene Oktavia", "Orao", "Snackers"} //dobroty se slevou
    };
    int kosik [4] [4] ={  //urcuje pocet daneho zbozi v kosiku
          { 0, 0, 0, 0},//rohliky, housky, chleba, koblizky
          { 0, 0, 0, 0},//kava, cola, vinea, water
          { 0, 0, 0, 0},//dobroty bez slevy
          { 0, 0, 0, 0} //dobroty se slevou
        };
    float ceny [4] [4] ={ //urcuje ceny zbozi
          { 2.99, 4.99, 49.99, 23.99},//rohliky, housky, chleba, koblizky
          { 65.99, 49.99, 35.99, 29.99},//kava, cola, vinea, water
          { 14.99, 19.99, 16.50, 17.99},//dobroty bez slevy
          { 0.85*ceny [0][2], 0.85*ceny [1][2], 0.85*ceny [2][2], 0.85*ceny [3][2]} //dobroty se slevou
        },
        finalniCena=0;
    //string  // array pro zboží
    bool reset1=1;/* opakovani hlavni menu (loop) 1=ano, 0=ne */
    while(reset1==1){
        bool reset2=1;/* opakovani menu peciva*/
        system("cls");
        reset1=0;// aby se po vyberu neopakovalo hlavni menu
        cout<< " Welcome to Vydl supermarket! \n Please choose a category. \n 1 - Pastry \n 2 - Sweets \n 3 - Drinks \n 4 - Check out \n 5 - Cancel and close program \n To change the number of an item you want to buy, just reselect it. \n ";
        cin>> vyberHlavni;
        switch (vyberHlavni) {//vyber pro jednotlive kategorie
            case (1):{//pecivo
                while(reset2==1){
                    reset2=0;
                    system("cls");
                    cout<< " Category: Pastry \n Please select what do you want to buy. \n 1 - Rolls \n 2 - Buns \n 3 - Bread \n 4 - Donut \n 5 - Go back \n ";
                    cin>>podVyber;
                    switch(podVyber){
                        case(1):{
                            system("cls");
                            cout<<" Please type how many "<<zbozi[0] [0]<<" for "<<ceny [0][0]<<",- do you want to buy.\n ";
                            cin>>kosik [0] [0];
                            reset2=1;
                        }break;
                        case(2):{
                            system("cls");
                            cout<<" Please type how many "<<zbozi[1] [0]<<" for "<<ceny [1][0]<<",- do you want to buy.\n ";
                            cin>>kosik [1] [0];
                            reset2=1;
                        }break;
                        case(3):{
                            system("cls");
                            cout<<" Please type how many "<<zbozi[2] [0]<<" for "<<ceny [2][0]<<",- do you want to buy.\n ";
                            cin>>kosik [2] [0];
                            reset2=1;
                        }break;
                        case(4):{
                            system("cls");
                            cout<<" Please type how many "<<zbozi[3] [0]<<" for "<<ceny [3][0]<<",- do you want to buy.\n ";
                            cin>>kosik [3] [0];
                            reset2=1;
                        }break;
                        case(5):{
                            reset1=1;
                        }break;
                        default:
                            cout<<" Wrong input please try again. \n Type anything to try again. \n ";
                            reset2=1;
                            cin>>pokracovani;
                    }
                }
            }break;
            case (2):{

            }break;
            case (3):{

            }break;
            case (4):{//zaplatit
                system("cls");
                cout<<" There are ";
                for(int checkoutLoop1=0; checkoutLoop1!=4;){
                    for(int checkoutLoop2=0; checkoutLoop2!=4;){
                        if(kosik[checkoutLoop1][checkoutLoop2] != 0){
                            cout<<kosik[checkoutLoop1][checkoutLoop2]<<" "<<zbozi[checkoutLoop1][checkoutLoop2]<<" ";
                        };
                        finalniCena=finalniCena + (kosik[checkoutLoop1][checkoutLoop2]*ceny[checkoutLoop1][checkoutLoop2]);
                        checkoutLoop2++;
                    }
                    checkoutLoop1++;
                }
                cout<<"in your shopping cart. The cost of your purchase is "<<finalniCena<<",- crowns.\n ";
                cin>>pokracovani;
            }break;
            case (5):{
                return  0;
            }break;
            default:
                cout<<" Wrong input please try again. \n Type anything to try again. \n ";
                reset1=1;
                cin>>pokracovani;
        }
    }
}
