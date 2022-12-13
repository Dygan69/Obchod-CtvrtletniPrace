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
     int vyber, podVyber,podVyber2,/*urcuji akce ve ruznych menu*/ pocetVKosiku=0/*celkovy pocet veci v kosiku*/, random, platbaPotvrzeni, prodejna=(rand() % 34);//urcuje random prodejnu
     srand(time(0));
     int pokladna=(rand() % 10);//urcuje random pokladnu
     srand(time(0));
     int jmeno=(0 +(rand() % 4));//urcuje random jmeno
     //pozice zbozi v poli odpovida ostatnim polim
     string zbozi [4] [4]={
           { "Rolls",  "Buns", "Bread", "Donuts"}, //rohliky, housky, chleba, koblizky
           { "Coffee", "Cola", "Virnea", "Water"}, //kava, cola, vinea, water
           { "Kitcat", "Polomacene Oktavia", "Orao", "Snackers"},//dobroty bez slevy
           { "Kitcat", "Polomacene Oktavia", "Orao", "Snackers"} //dobroty se slevou
     },
     kategorie[1][4]{//nazvy pro kategorie
        { "Pastry",  "Drinks", "Sweets with 15% off", "Sweets"}
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

         // arraye pro zboží

     bool reset1=1;/*opakovani hlavniho menu(1.vrsty)*/
     while(reset1==1){//hlavni menu
         bool reset2=1/*2.vrstvy*/, reset3=1,/*pro overovani sladkosti*/ reset4=1,/*pro blbuvzdornost menu sladkosti*/ reset5=1,/*pro opakovani podmenu*/ resetPlatba=1;//opakovani menu platby
         system("cls");
         reset1=0;// aby se po vyberu neopakovalo hlavni menu
         cout<< " Welcome to Vydl supermarket! Shop number: "<< prodejna <<", Cash register number: "<<pokladna<<" \n "<<"My name is ";
         switch(jmeno){//random cislo ze zacatku -> switch -> jmeno
            case(1):{
                cout<<"Pepa.";
            }break;
            case(2):{
                cout<<"Veronika.";
            }break;
            case(3):{
                cout<<"Hammond.";
            }break;
            default:
                cout<<"Arnosht.";
         }
         cout<<" \n Please choose a category. \n 1 - Pastry \n 2 - Drinks  \n 3 - Sweets \n 4 - Check out \n 5 - Cancel and close program \n To change the number of an item you want to buy, just reselect it. \n ";
         cin>>vyber;
         if(vyber==1 || vyber==2|| vyber==3){//jako switch casy 1,2,3 ale setri radkama (nemusim vypisovat kazde podmenu zvlast kdyz mam jedno universalni)
            while(reset2==1){
                reset2=0;
                reset5=1;

                if(vyber==3){//tohle byla mrcha vymyslet ale pokud uzivatel zvoli 3 radek arraye(sladkosti se slevou) a nezada spravne kod tak ho menu nepusti dal a kdyz zada "Ne" tak mu to radek 3 premeni na 4 (sladkosti bez slevy)
                    while(reset3==1){
                        reset3=0;
                        system("cls");
                        cout<<" Do you want to use the discount coupon to get 15% off on Sweets? \n 1 - Yes \n 2 - No \n ";
                        cin>>podVyber2;
                        switch(podVyber2){//switch pro sladkosti (chci/nechci zadat kod pro slevu)
                            case(1):{
                                while(reset4==1){
                                    reset4=0;
                                    system("cls");
                                    cout<<" Please enter the coupon code to continue. \n ";
                                    cin>>slevaKod;
                                    if(slevaKod!=slevaKodTru){
                                        cout<<" \n Wrong code! Please try again. \n ";
                                        Sleep(1000);
                                        reset4=1;
                                    }else{
                                        cout<<" Correct!";
                                        Sleep(1200);
                                    }
                                }
                            }break;
                            case(2):{
                                vyber=4;
                            }break;
                            default:
                                cout<<" Wrong input please try again. \n Type anything to try again. \n ";
                                reset3=1;
                                cin>>pokracovani;
                        }
                    }
                }
                while(reset5==1){//konecne podmenu where the magic happens diky vybranym menu a podmenu najde souradnici v arrayi a prida zadany pocet na jeho souradnici do kosiku
                    reset5=0;
                    system("cls");
                    cout<< " Category: "<<kategorie[0][(vyber-1)]<<" \n Please select what do you want to buy. \n 1 - "<<zbozi[(vyber-1)][0]<<" \n 2 - "<<zbozi[(vyber-1)][1]<<" \n 3 - "<<zbozi[(vyber-1)][2]<<" \n 4 - "<<zbozi[(vyber-1)][3]<<" \n 5 - Go back \n ";
                    cin>>podVyber;
                    if(podVyber==1||podVyber==2||podVyber==3||podVyber==4){//opet pouzivam if misto switche pac se da vyvolat vice podminek pro jednu funkci
                        system("cls");
                        cout<<" Please type how many "<<zbozi[(vyber-1)] [(podVyber-1)]<<" for "<<ceny [(vyber-1)] [(podVyber-1)]<<",- do you want to buy.\n ";
                        cin>>kosik [(vyber-1)] [(podVyber-1)];
                        reset2=1;
                    }else if(podVyber==5){//da uzivatele o jedno menu nahoru
                        reset1=1;
                    }else{//reakce pro spatny input
                        cout<<" Wrong input please try again. \n Type anything to try again. \n ";
                        reset5=1;
                        cin>>pokracovani;
                    }
                }
            }
        }else if(vyber==4){//zaplatit
            while(resetPlatba==1){
                finalniCena=0;//aby se neduplikovala cena po vraceni nahoru z platby
                resetPlatba=0;
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
                        checkoutLoop2++;//postupne pocita celkovou cenu pricitanim ceny zbozi vynasobene poctem v kosiku
                    }
                    checkoutLoop1++;
                }
                cout<<"|----------------------------------| \n in your shopping cart. \n The cost of your purchase is "<<finalniCena<<",- czk.";
                cout<<" \n Type in \n 1 - Continue to payment \n 2 - Go back \n ";
                cin>>platbaPotvrzeni;
                if(platbaPotvrzeni==1){
                    while(reset2==1){//vyber druhu platby
                        reset2=0;
                        system("cls");
                        cout<<" Which payment method do you want to use? \n 1 - Cash \n 2 - Credit/Debit card \n ";
                        cin>>vyber;
                        switch(vyber){
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
                            //line udelana uctenka na zpusob kontrolovani jako na radku 127 s casovejma odstupama aby to alespon vzdalene vypadalo jako tisknuti uctenky
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
                                if(pin==6969){//odsud je to to stejne co nahore do radku 153 a ano je to ctrl c, ctrl v pac jsou prave 3:39 rano a uz mi to fakt nemysli
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
                }else{
                reset1=1;
                }
                if(platbaPotvrzeni!=1 && platbaPotvrzeni !=2){
                    cout<<" Wrong input, please try again. \n ";//blbuvzdorne potvrzovani
                    Sleep(2000);
                    resetPlatba=1;
                }
            }
         }else if(vyber==5){//potvrzeni vypnuti programu
                 system("cls");
                 cout<<" Are you sure? \n 1 - Yes \n 2 - No, go back \n ";
                 cin>>platbaPotvrzeni;
                 if(platbaPotvrzeni==1){
                    return  0;
                 }else{
                    reset1=1;
                 }
             }else{
                 cout<<" Wrong input please try again. \n Type anything to try again. \n ";//opet "blbuvzdorne"
                 reset1=1;
                 cin>>pokracovani;
             }
     }
 }//poslusne hlasim ze kod je mozna po optimalizaci lehce mene stabilni avsak kratsi o cca 250 radku I see this as an absolute win a taky nebude nyni tolik tezke pridat system upravovani nabizeneho zbozi
