/*---------------------------------------------------------------
 Etapa 1
 Vaším úkolem je vytvořit obchod který má funkce:
 Nákup zboží ze min. 2 kategorií
 Každé zboží může uživatel koupit Xkrát a má svůj cenový koeficient
 Po ukončení nákupu dostane uživatel účtenku s celkovou cenou
 ---------------------------------------------------------------
 Etapa 2
 Účtenka zobrazí položky které uživatel koupil.
 Účtenka vygeneruje 2 náhodné kódy FIK a PKN(formát:     a       (Náhodné čísla)
 Uživatel si bude moc zvolit zpusob platby, Karta kde bude muset zadat PIN aby prošla platba
 (Pin muze byt vzdy stejny)
 Přidejte 3. kategorii zboží která bude mít 2 cenové kategorie
 S slevou 15% (zada slevovy kod - ILOVEPROGRAMOVANI)
 beze slevy
 Uživatel si může zvolit mezi těmito kategoriemi
 ---------------------------------------------------------------
 Etapa 3
 Okomentujte všechny:
 Funkce
 Switche
 Podivně pojmenovane proměnné (např. Wtfdoesthisdo = 5;)
 Případné výpočty
 Pokud uživatel nakoupil za více jak x(zvolte vy) oznamte že vyhrál lednici
 Bonus: vytvořte šanci 1ku1000 že uživatel bude mít nákup zadarmo
 ---------------------------------------------------------------
 Etapa 4
 Přidejte náhodně generované:
 Číslo prodejny a pokladny
 Jmeno pokladniho: Pepa, Veronika, Hammond
 Optimalizujte váš kód
 Soubor zazipujte a pošlete na mail
 */

 #include <iostream>
 #include <cstdlib>
 #include <windows.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string>
 using namespace std;

 int main(){
     string pokracovani, slevaKodTru="ILOVEPROGRAMOVANI", slevaKod;
     double finalniCena=0;
     int vyberHlavni,podVyber, zboziLoop, slevaVyber, platbaVyber,/*urcuji akce ve ruznych menu*/ pocetVKosiku=0/*celkovy pocet veci v kosiku*/, random;//urcuje ruzna random cisla
     //pozice zbozi v poli odpovida ostatnim polim
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
     double ceny [4] [4] ={ //urcuje ceny zbozi
           { 2.990, 4.990, 49.990, 23.990},//rohliky, housky, chleba, koblizky
           { 65.990, 49.990, 35.990, 29.990},//kava, cola, vinea, water
           { 0.85*ceny [3][0], 0.85*ceny [3][1], 0.85*ceny [3][2], 0.85*ceny [3][3]}, //dobroty se slevou
           { 14.990, 19.990, 16.50, 17.990}//dobroty bez slevy
         };
     //string  // array pro zboží
     bool reset1=1, loopConfirm=1;/* opakovani hlavni menu (loop) 1=ano, 0=ne */
     while(reset1==1){
         bool reset2=1, resetSleva=1, resetCoupon=1;/* opakovani ostatnich menu*/
         system("cls");
         reset1=0;// aby se po vyberu neopakovalo hlavni menu
         cout<< " Welcome to Vydl supermarket! \n Please choose a category. \n 1 - Pastry \n 2 - Drinks  \n 3 - Sweets \n 4 - Check out \n 5 - Cancel and close program \n To change the number of an item you want to buy, just reselect it. \n ";
         cin>> vyberHlavni;
         switch (vyberHlavni) {//vyber pro jednotlive kategorie
             case (1):{//pecivo
                 while(reset2==1){
                     reset2=0;
                     system("cls");
                     cout<< " Category: Pastry \n Please select what do you want to buy. \n 1 - Rolls \n 2 - Buns \n 3 - Bread \n 4 - Donut \n 5 - Go back \n ";
                     cin>>podVyber;
                     switch(podVyber){
                         case(1):{//podvyber rohliku
                             system("cls");
                             cout<<" Please type how many "<<zbozi[0] [0]<<" for "<<ceny [0][0]<<",- do you want to buy.\n ";
                             cin>>kosik [0] [0];
                             reset2=1;
                         }break;
                         case(2):{//podvyber housek
                             system("cls");
                             cout<<" Please type how many "<<zbozi[0] [1]<<" for "<<ceny [0][1]<<",- do you want to buy.\n ";
                             cin>>kosik [0] [1];
                             reset2=1;
                         }break;
                         case(3):{//podvyber chlebu
                             system("cls");
                             cout<<" Please type how many "<<zbozi[0] [2]<<" for "<<ceny [0][2]<<",- do you want to buy.\n ";
                             cin>>kosik [0] [2];
                             reset2=1;
                         }break;
                         case(4):{//podvyber koblizku
                             system("cls");
                             cout<<" Please type how many "<<zbozi[0] [3]<<" for "<<ceny [0][3]<<",- do you want to buy.\n ";
                             cin>>kosik [0] [3];
                             reset2=1;
                         }break;
                         case(5):{//da uzivatele o jedno menu nahoru
                             reset1=1;
                         }break;
                         default://reakce pro spatny input
                             cout<<" Wrong input please try again. \n Type anything to try again. \n ";
                             reset2=1;
                             cin>>pokracovani;
                     }
                 }
             }break;
//-------------------------------------------------------------------------------------------------------------------------------------//
             case (2):{
                 while(reset2==1){
                     reset2=0;
                     system("cls");
                     cout<< " Category: Drinks \n Please select what do you want to buy. \n 1 - Coffee \n 2 - Cola \n 3 - Virnea \n 4 - Water \n 5 - Go back \n ";
                     cin>>podVyber;
                     switch(podVyber){
                         case(1):{//podvyber kafe
                             system("cls");
                             cout<<" Please type how many "<<zbozi[1] [0]<<" for "<<ceny [1][0]<<",- do you want to buy.\n ";
                             cin>>kosik [1] [0];
                             reset2=1;
                         }break;
                         case(2):{//podvyber koly
                             system("cls");
                             cout<<" Please type how many "<<zbozi[1] [1]<<" for "<<ceny [1][1]<<",- do you want to buy.\n ";
                             cin>>kosik [1] [1];
                             reset2=1;
                         }break;
                         case(3):{//podvyber viney
                             system("cls");
                             cout<<" Please type how many "<<zbozi[1] [2]<<" for "<<ceny [1][2]<<",- do you want to buy.\n ";
                             cin>>kosik [1] [2];
                             reset2=1;
                         }break;
                         case(4):{//podvyber vody
                             system("cls");
                             cout<<" Please type how many "<<zbozi[1] [3]<<" for "<<ceny [1][3]<<",- do you want to buy.\n ";
                             cin>>kosik [1] [3];
                             reset2=1;
                         }break;
                         case(5):{//zpet do menu nahoru
                             reset1=1;
                         }break;
                         default:
                             cout<<" Wrong input please try again. \n Type anything to try again. \n ";
                             reset2=1;
                             cin>>pokracovani;
                     }
                 }
             }break;
//-------------------------------------------------------------------------------------------------------------------------------------//
             case (3):{//susenky
                 while(resetSleva==1){
                     resetSleva=0;
                     system("cls");
                     cout<<" Do you want to use the discount coupon to get 15% off on Sweets? \n 1 - Yes \n 2 - No \n ";
                     cin>>slevaVyber;
                     switch(slevaVyber){
                         case(1):{//se slevou
                             while (resetCoupon==1){
                                 resetCoupon=0;
                                 system ("cls");
                                 cout<<" Please enter the coupon code to continue. \n ";
                                 cin>>slevaKod;
                                 if(slevaKod==slevaKodTru){
                                     cout<<" \n Correct! Processing... \n ";
                                     Sleep(1500);
                                     while(reset2==1){
                                        reset2=0;
                                        system("cls");
                                        cout<< " Category: Sweets \n Please select what do you want to buy. \n 1 - Kitcat \n 2 - Polomacene Oktavia \n 3 - Orao \n 4 - Snackers \n 5 - Go back \n ";
                                        cin>>podVyber;
                                        switch(podVyber){
                                            case(1):{
                                                system("cls");
                                                cout<<" Please type how many "<<zbozi[2] [0]<<" for "<<ceny [2][0]<<",- do you want to buy.\n ";
                                                cin>>kosik [2] [0];
                                                reset2=1;
                                            }break;
                                            case(2):{
                                                system("cls");
                                                cout<<" Please type how many "<<zbozi[2] [1]<<" for "<<ceny [2][1]<<",- do you want to buy.\n ";
                                                cin>>kosik [2] [1];
                                                reset2=1;
                                            }break;
                                            case(3):{
                                                system("cls");
                                                cout<<" Please type how many "<<zbozi[2] [2]<<" for "<<ceny [2][2]<<",- do you want to buy.\n ";
                                                cin>>kosik [2] [2];
                                                reset2=1;
                                            }break;
                                            case(4):{
                                                system("cls");
                                                cout<<" Please type how many "<<zbozi[2] [3]<<" for "<<ceny [2][3]<<",- do you want to buy.\n ";
                                                cin>>kosik [2] [3];
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
                                 }else{
                                     cout<<" Wrong code, please try again in a few seconds. ";
                                     Sleep(2000);
                                     resetCoupon =1;
                                 };
                             }
                         }break;
                         case(2):{//bez slevy
                            while(reset2==1){
                                reset2=0;
                                system("cls");
                                cout<< " Category: Sweets \n Please select what do you want to buy. \n 1 - Kitcat \n 2 - Polomacene Oktavia \n 3 - Orao \n 4 - Snackers \n 5 - Go back \n ";
                                cin>>podVyber;
                                switch(podVyber){
                                    case(1):{
                                        system("cls");
                                        cout<<" Please type how many "<<zbozi[3] [0]<<" for "<<ceny [3][0]<<",- do you want to buy.\n ";
                                        cin>>kosik [3] [0];
                                        reset2=1;
                                    }break;
                                    case(2):{
                                        system("cls");
                                        cout<<" Please type how many "<<zbozi[3] [1]<<" for "<<ceny [3][1]<<",- do you want to buy.\n ";
                                        cin>>kosik [3] [1];
                                        reset2=1;
                                    }break;
                                    case(3):{
                                        system("cls");
                                        cout<<" Please type how many "<<zbozi[3] [2]<<" for "<<ceny [3][2]<<",- do you want to buy.\n ";
                                        cin>>kosik [3] [2];
                                        reset2=1;
                                    }break;
                                    case(4):{
                                        system("cls");
                                        cout<<" Please type how many "<<zbozi[3] [3]<<" for "<<ceny [3][3]<<",- do you want to buy.\n ";
                                        cin>>kosik [3] [3];
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
                         default:
                             cout<<" Wrong input, please try again.";
                             resetSleva=1;
                             sleep(1500);
                     }
                 }
             }break;
             //ano slo by to udelat jeden switch s promenyma ale jak jeste zminim nize je 3:40 rano a uz nemuzu
//-------------------------------------------------------------------------------------------------------------------------------------//
             case (4):{//zaplatit
                 system("cls");
                 cout<<" There are \n |----------------------------------| \n ";
                 for(int checkoutLoop1=0; checkoutLoop1!=4;){//kontroluje pole po sloupcich pak po radkach a kdyz je v poli kosiku zapsane zbozi vypise ho
                     for(int checkoutLoop2=0; checkoutLoop2!=4;){
                         if(kosik[checkoutLoop1][checkoutLoop2] != 0){
                             cout<<kosik[checkoutLoop1][checkoutLoop2]<<"x "<<zbozi[checkoutLoop1][checkoutLoop2]<<" for "<<ceny [checkoutLoop1][checkoutLoop2]<<",- each ";
                             if (checkoutLoop1==2){//pokud je to zbozi z pole susenek se slevou pripise 15% slevu
                                 cout<<"(Sleva 15%)";
                             };
                             cout<<" \n ";
                             pocetVKosiku=pocetVKosiku+1;//pocita celkovy pocet veci v kosiku
                         };
                         finalniCena=finalniCena + (kosik[checkoutLoop1][checkoutLoop2]*ceny[checkoutLoop1][checkoutLoop2]);
                         checkoutLoop2++;//postupne pocita celkovou cenu
                     }
                     checkoutLoop1++;
                 }
                 cout<<"|----------------------------------| \n in your shopping cart. \n The cost of your purchase is "<<finalniCena<<",- czk.";
                 cout<<" \n Type in anything to continue to payment \n ";
                 cin>>pokracovani;
                 while(reset2==1){//vyber druhu platby
                     reset2=0;
                     system("cls");
                     cout<<" Which payment method do you want to use? \n 1 - Cash \n 2 - Credit/Debit card \n ";
                     cin>>platbaVyber;
                     switch(platbaVyber){
                        case(1):{//hotovost
                            for(int nic=0; nic!=2; nic++){//loading
                                for(int cas=1; cas!=5; cas++){
                                    system("cls");
                                    switch(cas){
                                        case(1):{
                                            cout<<" Printing... ";
                                        }break;
                                        case(2):{
                                            cout<<" Printing ...";
                                        }break;
                                        case(3):{
                                            cout<<" Printing. ..";
                                        }break;
                                        case(4):{
                                            cout<<" Printing.. .";
                                        }break;
                                    }
                                    Sleep(1000);
                                }
                            }
                            system("cls");
                            //line udelana uctenka na zpusob kontrolovani jako na radku 274 s casovejma odstupama aby to alespon vzdalene vypadalo jako tisknuti uctenky
                            cout<<"            Vydl supermarket           ";
                            Sleep(750);
                            cout<<"\n |----------------------------------| \n ";
                            Sleep(750);
                            for(int checkoutLoop1=0; checkoutLoop1!=4;){
                                for(int checkoutLoop2=0; checkoutLoop2!=4;){
                                    if(kosik[checkoutLoop1][checkoutLoop2] != 0){
                                        cout<<kosik[checkoutLoop1][checkoutLoop2]<<"x "<<zbozi[checkoutLoop1][checkoutLoop2]<<" for "<<ceny [checkoutLoop1][checkoutLoop2]<<",- each ";
                                        if (checkoutLoop1==2){
                                            cout<<"(Sleva 15%)";
                                        };
                                        cout<<" \n ";
                                        Sleep(750);
                                    };
                                    checkoutLoop2++;
                                }
                            checkoutLoop1++;
                            }
                            cout<<"|----------------------------------| \n The total cost of your purchase was "<<finalniCena<<",- czk.";
                            Sleep(750);
                            cout<<"\n FIK and PKN codes: ";
                            Sleep(750);
                            srand(time(0));//random funkce v loopu na FIK a PKN kody
                            for(int forKody=0; forKody!=6;forKody++){
                                cout<<(rand() % 10);
                            }
                            cout<<" and ";
                            for(int forKody=0; forKody!=6;forKody++){
                                cout<<(rand() % 10);
                            }
                            srand(time(0));//random sance na free nakup
                            random= (rand() % 1000);
                            if(random==1){
                                cout<<" \n Congratulations, you've gotten the lucky number (1 to 1000 chance) and have the shopping for free.";
                            }
                            if(finalniCena>1000){//free lednice za nakup za vice jak 1000kc (ano snazim se krachnout)
                                cout<<" \n Congratulations, you've won a free fridge for shopping for more than 1000,- czk.";
                            }
                            cout<<"\n Type anything to close.\n ";
                            cin>>pokracovani;
                        }break;
                        case(2):{
                            bool reset3=1;
                            while(reset3==1){
                                system("cls");//overeni pinu
                                cout<<" Please type in your pin \n ";
                                reset3=0;
                                int pin;
                                cin>>pin;
                                if(pin==6969){//odsud je to to stejne co nahore do radku 434 a ano je to ctrl c, ctrl v pac jsou prave 3:39 rano a uz mi to fakt nemysli
                                    cout<<"\n Correct! Please wait.\n ";
                                    Sleep(1500);
                                    for(int nic=0; nic!=2; nic++){
                                        for(int cas=1; cas!=5; cas++){
                                            system("cls");
                                            switch(cas){
                                                case(1):{
                                                    cout<<" Printing... ";
                                                }break;
                                                case(2):{
                                                    cout<<" Printing ...";
                                                }break;
                                                case(3):{
                                                    cout<<" Printing. ..";
                                                }break;
                                                case(4):{
                                                    cout<<" Printing.. .";
                                                }break;
                                            }
                                            Sleep(1000);
                                        }
                                    }
                                    system("cls");
                                    cout<<"            Vydl supermarket           ";
                                    Sleep(750);
                                    cout<<"\n |----------------------------------| \n ";
                                    Sleep(750);
                                    for(int checkoutLoop1=0; checkoutLoop1!=4;){
                                        for(int checkoutLoop2=0; checkoutLoop2!=4;){
                                            if(kosik[checkoutLoop1][checkoutLoop2] != 0){
                                                cout<<kosik[checkoutLoop1][checkoutLoop2]<<"x "<<zbozi[checkoutLoop1][checkoutLoop2]<<" for "<<ceny [checkoutLoop1][checkoutLoop2]<<",- each ";
                                                if (checkoutLoop1==2){
                                                    cout<<"(Sleva 15%)";
                                                };
                                                cout<<" \n ";
                                                Sleep(750);
                                            };
                                            checkoutLoop2++;
                                        }
                                    checkoutLoop1++;
                                    }
                                    cout<<"|----------------------------------| \n The total cost of your purchase was "<<finalniCena<<",- czk.";
                                    Sleep(750);
                                    cout<<"\n FIK and PKN codes: ";
                                    Sleep(750);
                                    srand(time(0));
                                    for(int forKody=0; forKody!=6;forKody++){
                                        cout<<(rand() % 10);
                                    }
                                    cout<<" and ";
                                    for(int forKody=0; forKody!=6;forKody++){
                                        cout<<(rand() % 10);
                                    }
                                    srand(time(0));
                                    random= (rand() % 1000);
                                    if(random==1){
                                        cout<<" \n Congratulations, you've gotten the lucky number (1 to 1000 chance) and have the shopping for free.";
                                    }
                                    if(finalniCena>1000){
                                        cout<<" \n Congratulations, you've won a free fridge for shopping for more than 1000,- czk.";
                                    }
                                    cout<<"\n Type anything to close.\n ";
                                    cin>>pokracovani;
                                }else{
                                    cout<<" Wrong pin, please try again. \n ";//pro moznost znovu zadani pinu
                                    Sleep(2000);
                                    reset3=1;
                                };
                            }
                        }break;
                        default:
                            cout<<" Wrong input, please try again. \n ";//blbuvzdorne potvrzovani
                            Sleep(2000);
                            reset2=1;
                     }
                 }
             }break;
             case (5):{
                 return  0;
             }break;
             default:
                 cout<<" Wrong input please try again. \n Type anything to try again. \n ";//opet blbuvzdorne
                 reset1=1;
                 cin>>pokracovani;
         }
     }
 }
