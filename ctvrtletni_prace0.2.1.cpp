/*--------------------------------------------------------------- 
 Etapa 1 
 Vaším úkolem je vytvořit obchod který má funkce: 
 Nákup zboží ze min. 2 kategorií 
 Každé zboží může uživatel koupit Xkrát a má svůj cenový koeficient 
 Po ukončení nákupu dostane uživatel účtenku s celkovou cenou 
 --------------------------------------------------------------- 
 Etapa 2 
 Účtenka zobrazí položky které uživatel koupil. 
 Účtenka vygeneruje 2 náhodné kódy FIK a PKN(formát:     a       (Náhodné čísla) 
 Uživatel si bude moc zvolit zpusob platby, Karta kde bude muset zadat PIN aby prošla platba 
 (Pin muze byt vzdy stejny) 
 Přidejte 3. kategorii zboží která bude mít 2 cenové kategorie 
 S slevou 15% (zada slevovy kod - ILOVEPROGRAMOVANI) 
 beze slevy 
 Uživatel si může zvolit mezi těmito kategoriemi 
 --------------------------------------------------------------- 
 Etapa 3 
 Okomentujte všechny: 
 Funkce 
 Switche 
 Podivně pojmenovane proměnné (např. Wtfdoesthisdo = 5;) 
 Případné výpočty 
 Pokud uživatel nakoupil za více jak x(zvolte vy) oznamte že vyhrál lednici 
 Bonus: vytvořte šanci 1ku1000 že uživatel bude mít nákup zadarmo 
 --------------------------------------------------------------- 
 Etapa 4 
 Přidejte náhodně generované: 
 Číslo prodejny a pokladny 
 Jmeno pokladniho: Pepa, Veronika, Hammond 
 Optimalizujte váš kód 
 Soubor zazipujte a pošlete na mail 
 */ 
  
 #include <iostream> 
 #include <windows.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <time.h>
 #include <string>
 using namespace std; 
  
 int main(){ 
     string pokracovani, slevaKodTru=ILOVEPROGRAMOVANI, slevaKod; 
     int vyberHlavni,/* urcuje akci v hlavnim menu*/podVyber, zboziLoop, slevaVyber; 
     //pozice zbozi v poli odpovida ostatnim polim 
     string zbozi [4] [4]={ 
           { "Rolls",  "Buns", "Bread", "Donuts"}, //rohliky, housky, chleba, koblizky 
           { "Coffee", "Cola", "Virnea", "Water"}, //kava, cola, vinea, water 
           { "Kitcat", "Polomacene Oktavia", "Orao", "Snackers"},//dobroty bez slevy 
           { "Kitcat", "Polomacene Oktavia", "Orao", "Snackers"} //dobroty se slevou 
     }; 
     int kosik [4] [4] ={  //urcuje pocet daneho zbozi v kosiku 
           { 0, 0, 0, 0},//rohliky, housky, chleba, koblizky 
           { 0, 0, 0, 0},//kava, cola, vinea, water 
           { 0, 0, 0, 0},//dobroty bez slevy 
           { 0, 0, 0, 0} //dobroty se slevou 
         }; 
     double ceny [4] [4] ={ //urcuje ceny zbozi 
           { 2.99, 4.99, 49.99, 23.99},//rohliky, housky, chleba, koblizky 
           { 65.99, 49.99, 35.99, 29.99},//kava, cola, vinea, water 
           { 14.99, 19.99, 16.50, 17.99},//dobroty bez slevy 
           { 0.85*ceny [0][2], 0.85*ceny [1][2], 0.85*ceny [2][2], 0.85*ceny [3][2]} //dobroty se slevou 
         }, 
         finalniCena=0; 
     //string  // array pro zboží 
     bool reset1=1;/* opakovani hlavni menu (loop) 1=ano, 0=ne */ 
     while(reset1==1){ 
         bool reset2=1, resetSleva=1, resetCoupon=1;/* opakovani ostatnich menu*/ 
         system("cls"); 
         reset1=0;// aby se po vyberu neopakovalo hlavni menu 
         cout<< " Welcome to Vydl supermarket! \n Please choose a category. \n 1 - Pastry \n 2 - Drinks  \n 3 - Sweets \n 4 - Check out \n 5 - Cancel and close program \n To change the number of an item you want to buy, just reselect it. \n "; 
         cin>> vyberHlavni; 
         switch (vyberHlavni) {//vyber pro jednotlive kategorie 
             case (1):{//pecivo 
                 while(reset2==1){ 
                     reset2=0; 
                     system("cls"); 
                     cout<< " Category: Pastry \n Please select what do you want to buy. \n 1 - Rolls \n 2 - Buns \n 3 - Bread \n 4 - Donut \n 5 - Go back \n "; 
                     cin>>podVyber; 
                     switch(podVyber){ 
                         case(1):{ 
                             system("cls"); 
                             cout<<" Please type how many "<<zbozi[0] [0]<<" for "<<ceny [0][0]<<",- do you want to buy.\n "; 
                             cin>>kosik [0] [0]; 
                             reset2=1; 
                         }break; 
                         case(2):{ 
                             system("cls"); 
                             cout<<" Please type how many "<<zbozi[0] [1]<<" for "<<ceny [0][1]<<",- do you want to buy.\n "; 
                             cin>>kosik [0] [1]; 
                             reset2=1; 
                         }break; 
                         case(3):{ 
                             system("cls"); 
                             cout<<" Please type how many "<<zbozi[0] [2]<<" for "<<ceny [0][2]<<",- do you want to buy.\n "; 
                             cin>>kosik [0] [2]; 
                             reset2=1; 
                         }break; 
                         case(4):{ 
                             system("cls"); 
                             cout<<" Please type how many "<<zbozi[0] [3]<<" for "<<ceny [0][3]<<",- do you want to buy.\n "; 
                             cin>>kosik [0] [3]; 
                             reset2=1; 
                         }break; 
                         case(5):{ 
                             reset1=1; 
                         }break; 
                         default: 
                             cout<<" Wrong input please try again. \n Type anything to try again. \n "; 
                             reset2=1; 
                             cin>>pokracovani; 
                     } 
                 } 
             }break; 
             case (2):{ 
  
             }break; 
             case (3):{ 
                 while(resetSleva==1){
                     resetSleva=0;
                     system("cls");
                     cout<<" Do you want to use the discount coupon to get 15% off on Sweets? \n 1 - Yes \n 2 - No \n ";
                     cin<<slevaVyber;
                     switch(slevaVyber){
                         case(1):{
                             while (resetCoupon==1){
                                 resetCoupon=0;
                                 system ("cls");
                                 cout<<" Please enter the coupon code to continue.";
                                 cin>>slevaKod;
                                 if(slevaKod==slevaKodTru){
                                     cout<<" \n Correct! \n ";
                                     Sleep(1500);
                                     while(reset2==1){
                        
                                     }
                                 }else{
                                     cout<<" Wrong code, please try again in a few seconds. ";
                                     Sleep(2000);
                                     resetCoupon =1;
                                 };
                             }
                         }break;
                         case(2):{
            
                         }break;
                         default:
                             cout<<" Wrong input, please try again";
                             resetSleva=1;
                     }
                 }
             }break; 
             case (4):{//zaplatit 
                 system("cls"); 
                 cout<<" There are "; 
                 for(int checkoutLoop1=0; checkoutLoop1!=4;){ 
                     for(int checkoutLoop2=0; checkoutLoop2!=4;){ 
                         if(kosik[checkoutLoop1][checkoutLoop2] != 0){ 
                             cout<<kosik[checkoutLoop1][checkoutLoop2]<<" "<<zbozi[checkoutLoop1][checkoutLoop2]<<" "; 
                             if (checkoutLoop1==4){
                                 cout<<"( Sleva 15%)";
                             };
                         }; 
                         finalniCena=finalniCena + (kosik[checkoutLoop1][checkoutLoop2]*ceny[checkoutLoop1][checkoutLoop2]); 
                         checkoutLoop2++; 
                     } 
                     checkoutLoop1++; 
                 } 
                 cout<<"in your shopping cart. The cost of your purchase is "<<finalniCena<<",- crowns.\n "; 
                 cin>>pokracovani; 
             }break; 
             case (5):{ 
                 return  0; 
             }break; 
             default: 
                 cout<<" Wrong input please try again. \n Type anything to try again. \n "; 
                 reset1=1; 
                 cin>>pokracovani; 
         } 
     } 
 }