#include<iostream>
#include<string.h>
#include<fstream>
#include<windows.h>

using namespace std;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
int members=100;
void start();
void cuslog();
void customer(string);
void log(int);
void newcus();
void menu(string);
void pizzas(string);
void go(int x,int y){
COORD c;
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void payment(string u){
    system("cls");cout<<"Hi";
    }
void chart(string u){
system("cls");
 go(45,3);SetConsoleTextAttribute(h,0x0B);cout<<" 1. Finish Ordering    ";SetConsoleTextAttribute(h,0x0C);cout<<"0. Homepage";
 go(62,0);SetConsoleTextAttribute(h,0x0A);cout<<" Logged as: ";SetConsoleTextAttribute(h,0x0E);cout<<u;
 go(1,1);SetConsoleTextAttribute(h,0x0A);cout<<"There We Are! Just Enter Foods' ID :)\n\n\n";SetConsoleTextAttribute(h,0x0E);
 go(3,6);cout<<"ID";go(15,6);cout<<"Name";go(32,6);cout<<"Price";go(48,6);cout<<"Time"; ;go(60,6);cout<<"Final Cost & Time"<<endl;;
SetConsoleTextAttribute(h,0x0F);
for(int i=0;i<80;i++){
    cout<<"-";
}
for(int j=6;j<25;j++){
go(8,j);cout<<"|";go(26,j);cout<<"|";go(42,j);cout<<"|";go(57,j);cout<<"|";
}
}
void order(string u){
struct foods{
int id;
string name;
string price;
};
foods all[12];
ifstream allfoods("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\AllFoods.txt");
for(int i=0;i<12;i++){
    allfoods>>all[i].id;
    allfoods>>all[i].name;
    allfoods>>all[i].price;
}
chart(u);
int pos=8,n,id,w,c=0;
bool check;
long int prices[12];int times[12];
ifstream pr("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Time&Prices.txt");for(int i=0;i<12;i++){pr>>prices[i];pr>>times[i];}
long int sum=0;int sumt=0;
while(true){
check=false;
go(3,pos);SetConsoleTextAttribute(h,0x0F);cin>>n;if(n==0){
ofstream t("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\TempIDs.txt");customer(u);return;}
else if(n==1){ofstream t("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\TempIDs.txt");
cout<<"\n\n";for(int i=0;i<80;i++){cout<<"-";}
SetConsoleTextAttribute(h,0x00);go(1,3);cout<<"Oops ID Doesnt Exist !";
go(3,pos);SetConsoleTextAttribute(h,0x00);cout<<"1";go(45,3);cout<<" 1. Finish Ordering";
pos+=5;go(58,pos);SetConsoleTextAttribute(h,0x0A);cout<<"Total Price: ";SetConsoleTextAttribute(h,0x0F);cout<<sum<<" T";SetConsoleTextAttribute(h,0x0A);go(58,pos+2);cout<<"Prepare Time: ";SetConsoleTextAttribute(h,0x0F);cout<<sumt<<" Mins";SetConsoleTextAttribute(h,0x0F);go(1,3);
SetConsoleTextAttribute(h,0x0B);cout<<"1.Payment & Finish Ordering    ";SetConsoleTextAttribute(h,0x0F);int x;cin>>x;
if(x==0){customer(u);return;}else if(x==1){payment(u);return;}}
ifstream ids("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\IDs.txt");
for(int i=0;i<12;i++){
ids>>id;if(id==n){ids.close();ofstream t("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\TempIDs.txt",::ios_base::app);
t<<n<<" ";t.close();c++;w=i;check=true;break;}
}
if(check==true){SetConsoleTextAttribute(h,0x00);go(1,3);cout<<"Oops ID Doesnt Exist !";SetConsoleTextAttribute(h,0x0C);if(w>=6&&w<=8){go(11,pos);}else{go(14,pos);}
sum+=prices[w];sumt+=times[w];cout<<all[w].name;go(31,pos);cout<<all[w].price;go(45,pos);cout<<times[w]<<" Minutes";pos+=2;}

else{
chart(u);
SetConsoleTextAttribute(h,0x0C);go(1,3);cout<<"Oops ID Doesnt Exist !";
ifstream tid("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\TempIDs.txt");
int s=0,d;pos=8;
for(int j=0;j<c;j++){
tid>>d;ifstream ids("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\IDs.txt");
for(int i=0;i<12;i++){
ids>>id;if(id==d){ids.close();w=i;break;}}
SetConsoleTextAttribute(h,0x0F);go(3,pos);cout<<all[w].id;SetConsoleTextAttribute(h,0x0C);if(w>=6&&w<=8){go(11,pos);}else{go(14,pos);}cout<<all[w].name;go(31,pos);cout<<all[w].price;pos+=2;}
}
if(pos>24){SetConsoleTextAttribute(h,0x0F);for(int j=25;j<32;j++){go(8,j);cout<<"|";go(26,j);cout<<"|";go(42,j);cout<<"|";}}
}
}
void drinks(string u){
struct foods{
int id;
string name;
string price;
string details;
string time;
};
foods dri[3];
ifstream gdri("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Drinks.txt");
for(int i=0;i<3;i++){
    gdri>>dri[i].id;
    gdri>>dri[i].name;
    gdri>>dri[i].price;
    gdri>>dri[i].details;
    gdri>>dri[i].time;
}
gdri.close();
system("cls");
while(true){
ifstream gdri("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Drinks.txt");
ifstream p("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Dst.txt");
int price[3],time[3];for(int j=0;j<3;j++){p>>price[j];p>>time[j];}p.close();
go(1,23);SetConsoleTextAttribute(h,0x0E);cout<<"1. Order\t";SetConsoleTextAttribute(h,0x0B);
cout<<"8. Sort by Price\t9. Sort by Time\t";SetConsoleTextAttribute(h,0x0C);cout<<"\t0.Main Menu";
go(62,0);SetConsoleTextAttribute(h,0x0A);cout<<" Logged as: ";SetConsoleTextAttribute(h,0x0E);cout<<u;SetConsoleTextAttribute(h,0x0C);
go(1,1);
cout<<"\n  D . R . I . N . K . S  \n";
SetConsoleTextAttribute(h,0x0E);
go(1,5);cout<<"ID";go(8,5);cout<<"Name";go(18,5);cout<<"Price";go(42,5);cout<<"Details";go(72,5);cout<<"Time"<<endl;;
SetConsoleTextAttribute(h,0x0F);
for(int i=0;i<80;i++){
    cout<<"-";
}
for(int j=5;j<15;j++){
go(4,j);cout<<"|";go(16,j);cout<<"|";go(25,j);cout<<"|";go(66,j);cout<<"|";
}
SetConsoleTextAttribute(h,0x0A);
go(0,6);
int pos=7;
for(int i=0;i<3;i++){
go(1,pos);cout<<dri[i].id;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(7,pos);cout<<dri[i].name;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(18,pos);cout<<dri[i].price;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(40,pos);cout<<dri[i].details;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(71,pos);cout<<dri[i].time;pos+=2;
}
go(1,19);
int n;
SetConsoleTextAttribute(h,0x0F);
cin>>n;
system("cls");
string t;
switch(n){
case 0:menu(u);return;
case 9:for(int i=0;i<3;i++){
    gdri>>dri[i].id;
    gdri>>dri[i].name;
    gdri>>dri[i].price;
    gdri>>dri[i].details;
    gdri>>dri[i].time;

}
gdri.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(time[i]>time[j]){
             int h=dri[i].id;dri[i].id=dri[j].id;dri[j].id=h;h=time[i];time[i]=time[j];time[j]=h;
             t=dri[i].name;dri[i].name=dri[j].name;dri[j].name=t;
             t=dri[i].price;dri[i].price=dri[j].price;dri[j].price=t;
             t=dri[i].details;dri[i].details=dri[j].details;dri[j].details=t;
             t=dri[i].time;dri[i].time=dri[j].time;dri[j].time=t;

 }
 }}break;
case 8:for(int i=0;i<3;i++){
    gdri>>dri[i].id;
    gdri>>dri[i].name;
    gdri>>dri[i].price;
    gdri>>dri[i].details;
    gdri>>dri[i].time;
}
gdri.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(price[i]>price[j]){
             int h=dri[i].id;dri[i].id=dri[j].id;dri[j].id=h;h=time[i];time[i]=time[j];time[j]=h;
             t=dri[i].name;dri[i].name=dri[j].name;dri[j].name=t;
             t=dri[i].price;dri[i].price=dri[j].price;dri[j].price=t;
             t=dri[i].details;dri[i].details=dri[j].details;dri[j].details=t;
             t=dri[i].time;dri[i].time=dri[j].time;dri[j].time=t;
}}
}break;

default:system("cls");go(0,17);SetConsoleTextAttribute(h,0x0C);cout<<" Oops Out of Range !";
}
}
}
void fchickens(string u){
struct foods{
int id;
string name;
string price;
string details;
string time;
};
foods chi[3];
ifstream gchi("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\FriedChickens.txt");
for(int i=0;i<3;i++){
    gchi>>chi[i].id;
    gchi>>chi[i].name;
    gchi>>chi[i].price;
    gchi>>chi[i].details;
    gchi>>chi[i].time;
}
gchi.close();
system("cls");
while(true){
ifstream gchi("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\FriedChickens.txt");
ifstream p("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Fst.txt");
int price[3],time[3];for(int j=0;j<3;j++){p>>price[j];p>>time[j];}p.close();
go(1,23);SetConsoleTextAttribute(h,0x0E);cout<<"1. Order\t";SetConsoleTextAttribute(h,0x0B);
cout<<"8. Sort by Price\t9. Sort by Time\t";SetConsoleTextAttribute(h,0x0C);cout<<"\t0.Main Menu";
go(62,0);SetConsoleTextAttribute(h,0x0A);cout<<" Logged as: ";SetConsoleTextAttribute(h,0x0E);cout<<u;SetConsoleTextAttribute(h,0x0C);
go(1,1);
cout<<"\n  F . R . I . E . D    C . H . I . C . K . E . N  \n";
SetConsoleTextAttribute(h,0x0E);
go(0,5);cout<<"ID";go(8,5);cout<<"Name";go(19,5);cout<<"Price";go(42,5);cout<<"Details";go(74,5);cout<<"Time"<<endl;;
SetConsoleTextAttribute(h,0x0F);
for(int i=0;i<80;i++){
    cout<<"-";
}
for(int j=5;j<15;j++){
go(2,j);cout<<"|";go(17,j);cout<<"|";go(25,j);cout<<"|";go(70,j);cout<<"|";
}
SetConsoleTextAttribute(h,0x0A);
go(0,6);
int pos=7;
for(int i=0;i<3;i++){
go(0,pos);cout<<chi[i].id;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(3,pos);cout<<chi[i].name;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(18,pos);cout<<chi[i].price;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(27,pos);cout<<chi[i].details;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(71,pos);cout<<chi[i].time;pos+=2;
}
go(1,19);
int n;
SetConsoleTextAttribute(h,0x0F);
cin>>n;
system("cls");
string t;
switch(n){
case 0:menu(u);return;
case 9:for(int i=0;i<3;i++){
    gchi>>chi[i].id;
    gchi>>chi[i].name;
    gchi>>chi[i].price;
    gchi>>chi[i].details;
    gchi>>chi[i].time;

}
gchi.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(time[i]>time[j]){
             int h=chi[i].id;chi[i].id=chi[j].id;chi[j].id=h;h=time[i];time[i]=time[j];time[j]=h;
             t=chi[i].name;chi[i].name=chi[j].name;chi[j].name=t;
             t=chi[i].price;chi[i].price=chi[j].price;chi[j].price=t;
             t=chi[i].details;chi[i].details=chi[j].details;chi[j].details=t;
             t=chi[i].time;chi[i].time=chi[j].time;chi[j].time=t;

 }
 }}break;
case 8:for(int i=0;i<3;i++){
    gchi>>chi[i].id;
    gchi>>chi[i].name;
    gchi>>chi[i].price;
    gchi>>chi[i].details;
    gchi>>chi[i].time;
}
gchi.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(price[i]>price[j]){
             int h=chi[i].id;chi[i].id=chi[j].id;chi[j].id=h;h=time[i];time[i]=time[j];time[j]=h;
             t=chi[i].name;chi[i].name=chi[j].name;chi[j].name=t;
             t=chi[i].price;chi[i].price=chi[j].price;chi[j].price=t;
             t=chi[i].details;chi[i].details=chi[j].details;chi[j].details=t;
             t=chi[i].time;chi[i].time=chi[j].time;chi[j].time=t;
}}
}break;

default:system("cls");go(0,17);SetConsoleTextAttribute(h,0x0C);cout<<" Oops Out of Range !";
}
}
}
void pizzas(string u){
struct foods{
int id;
string name;
string price;
string details;
string time;
};
foods piz[3];
ifstream gpiz("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Pizzas.txt");
system("cls");
for(int i=0;i<3;i++){
    gpiz>>piz[i].id;
    gpiz>>piz[i].name;
    gpiz>>piz[i].price;
    gpiz>>piz[i].details;
    gpiz>>piz[i].time;

}
gpiz.close();

while(true){
ifstream gpiz("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Pizzas.txt");
ifstream p("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Pst.txt");
int price[3],time[3];for(int j=0;j<3;j++){p>>price[j];p>>time[j];}p.close();
go(1,23);SetConsoleTextAttribute(h,0x0E);cout<<"1. Order\t";SetConsoleTextAttribute(h,0x0B);
cout<<"8. Sort by Price\t9. Sort by Time\t";SetConsoleTextAttribute(h,0x0C);cout<<"\t0.Main Menu";
go(62,0);SetConsoleTextAttribute(h,0x0A);cout<<" Logged as: ";SetConsoleTextAttribute(h,0x0E);cout<<u;SetConsoleTextAttribute(h,0x0C);
go(1,1);
cout<<"\n  P . I . Z . Z . A  \n";
SetConsoleTextAttribute(h,0x0E);
go(1,5);cout<<"ID";go(8,5);cout<<"Name";go(18,5);cout<<"Price";go(42,5);cout<<"Details";go(72,5);cout<<"Time"<<endl;;
SetConsoleTextAttribute(h,0x0F);
for(int i=0;i<80;i++){
    cout<<"-";
}
for(int j=5;j<15;j++){
go(4,j);cout<<"|";go(16,j);cout<<"|";go(25,j);cout<<"|";go(66,j);cout<<"|";
}
SetConsoleTextAttribute(h,0x0A);
go(0,6);

int pos=7;
for(int i=0;i<3;i++){
go(1,pos);cout<<piz[i].id;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(7,pos);cout<<piz[i].name;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(18,pos);cout<<piz[i].price;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(27,pos);cout<<piz[i].details;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(69,pos);cout<<piz[i].time;pos+=2;
}
go(1,19);
int n;
SetConsoleTextAttribute(h,0x0F);
cin>>n;
system("cls");
string t;
switch(n){
case 0:menu(u);return;
case 9:for(int i=0;i<3;i++){
    gpiz>>piz[i].id;
    gpiz>>piz[i].name;
    gpiz>>piz[i].price;
    gpiz>>piz[i].details;
    gpiz>>piz[i].time;

}
gpiz.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(time[i]>time[j]){
             int h=piz[i].id;piz[i].id=piz[j].id;piz[j].id=h;h=time[i];time[i]=time[j];time[j]=h;
             t=piz[i].name;piz[i].name=piz[j].name;piz[j].name=t;
             t=piz[i].price;piz[i].price=piz[j].price;piz[j].price=t;
             t=piz[i].details;piz[i].details=piz[j].details;piz[j].details=t;
             t=piz[i].time;piz[i].time=piz[j].time;piz[j].time=t;

 }
 }}break;
case 8:for(int i=0;i<3;i++){
    gpiz>>piz[i].id;
    gpiz>>piz[i].name;
    gpiz>>piz[i].price;
    gpiz>>piz[i].details;
    gpiz>>piz[i].time;

}
gpiz.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(price[i]>price[j]){
             int h=piz[i].id;piz[i].id=piz[j].id;piz[j].id=h;h=price[i];price[i]=price[j];price[j]=h;
             t=piz[i].name;piz[i].name=piz[j].name;piz[j].name=t;
             t=piz[i].price;piz[i].price=piz[j].price;piz[j].price=t;
             t=piz[i].details;piz[i].details=piz[j].details;piz[j].details=t;
             t=piz[i].time;piz[i].time=piz[j].time;piz[j].time=t;
}}
}break;

default:system("cls");go(0,17);SetConsoleTextAttribute(h,0x0C);cout<<" Oops Out of Range !";
}
}
}
void burgers(string u){
struct foods{
int id;
string name;
string price;
string details;
string time;
};
foods bur[3];
ifstream gbur("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Burgers.txt");
for(int i=0;i<3;i++){
    gbur>>bur[i].id;
    gbur>>bur[i].name;
    gbur>>bur[i].price;
    gbur>>bur[i].details;
    gbur>>bur[i].time;
}
gbur.close();
system("cls");
while(true){
ifstream gbur("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Burgers.txt");
ifstream p("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Foods\\Bst.txt");
int price[3],time[3];for(int j=0;j<3;j++){p>>price[j];p>>time[j];}p.close();
go(1,23);SetConsoleTextAttribute(h,0x0E);cout<<"1. Order\t";SetConsoleTextAttribute(h,0x0B);
cout<<"8. Sort by Price\t9. Sort by Time\t";SetConsoleTextAttribute(h,0x0C);cout<<"\t0.Main Menu";
go(62,0);SetConsoleTextAttribute(h,0x0A);cout<<" Logged as: ";SetConsoleTextAttribute(h,0x0E);cout<<u;SetConsoleTextAttribute(h,0x0C);
go(1,1);
cout<<"\n  B . U . R . G . E . R . S  \n";
SetConsoleTextAttribute(h,0x0E);
go(1,5);cout<<"ID";go(8,5);cout<<"Name";go(18,5);cout<<"Price";go(42,5);cout<<"Details";go(72,5);cout<<"Time"<<endl;;
SetConsoleTextAttribute(h,0x0F);
for(int i=0;i<80;i++){
    cout<<"-";
}
for(int j=5;j<15;j++){
go(4,j);cout<<"|";go(16,j);cout<<"|";go(25,j);cout<<"|";go(66,j);cout<<"|";
}
SetConsoleTextAttribute(h,0x0A);
go(0,6);
int pos=7;
for(int i=0;i<3;i++){
go(1,pos);cout<<bur[i].id;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(6,pos);cout<<bur[i].name;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(18,pos);cout<<bur[i].price;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(27,pos);cout<<bur[i].details;pos+=2;
}
pos=7;
for(int i=0;i<3;i++){
go(69,pos);cout<<bur[i].time;pos+=2;
}
go(1,19);
int n;
SetConsoleTextAttribute(h,0x0F);
cin>>n;
system("cls");
string t;
switch(n){
case 0:menu(u);return;
case 9:for(int i=0;i<3;i++){
    gbur>>bur[i].id;
    gbur>>bur[i].name;
    gbur>>bur[i].price;
    gbur>>bur[i].details;
    gbur>>bur[i].time;

}
gbur.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(time[i]>time[j]){
             int h=bur[i].id;bur[i].id=bur[j].id;bur[j].id=h;h=time[i];time[i]=time[j];time[j]=h;
             t=bur[i].name;bur[i].name=bur[j].name;bur[j].name=t;
             t=bur[i].price;bur[i].price=bur[j].price;bur[j].price=t;
             t=bur[i].details;bur[i].details=bur[j].details;bur[j].details=t;
             t=bur[i].time;bur[i].time=bur[j].time;bur[j].time=t;

 }
 }}break;
case 8:for(int i=0;i<3;i++){
    gbur>>bur[i].id;
    gbur>>bur[i].name;
    gbur>>bur[i].price;
    gbur>>bur[i].details;
    gbur>>bur[i].time;
}
gbur.close();
    for(int i=0;i<3;i++){for(int j=i+1;j<3;j++){ if(price[i]>price[j]){
             int h=bur[i].id;bur[i].id=bur[j].id;bur[j].id=h;h=time[i];time[i]=time[j];time[j]=h;
             t=bur[i].name;bur[i].name=bur[j].name;bur[j].name=t;
             t=bur[i].price;bur[i].price=bur[j].price;bur[j].price=t;
             t=bur[i].details;bur[i].details=bur[j].details;bur[j].details=t;
             t=bur[i].time;bur[i].time=bur[j].time;bur[j].time=t;

}}
}break;

default:system("cls");go(0,17);SetConsoleTextAttribute(h,0x0C);cout<<" Oops Out of Range !";
}
}
}
void menu(string u){
system("cls");
go(62,0);SetConsoleTextAttribute(h,0x0A);cout<<" Logged as: ";SetConsoleTextAttribute(h,0x0E);cout<<u;
go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. Back to Home Page";go(0,2);
SetConsoleTextAttribute(h,0x0E);
cout<<"\n Let's See What You Want !\n\n\n";
while(true){
SetConsoleTextAttribute(h,0x0A);
cout<<"1. Pizza\n\n2. Burger\n\n3. Fried Chicken\n\n4. Drinks\n\n";
int n;
SetConsoleTextAttribute(h,0x0F);
cin>>n;
switch(n){
case 0:customer(u);return;
case 1:pizzas(u);return;
case 2:burgers(u);return;
case 3:fchickens(u);return;
case 4:drinks(u);return;
default:system("cls");go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. Back to Home Page";go(0,0);SetConsoleTextAttribute(h,0x0E);
cout<<"\nLet's See What You Want !\n\n\n";SetConsoleTextAttribute(h,0x0C);cout<<"Oops So Far ! Please Only Press 1-4\n\n\n";
}
}
}
void manager(){
    system("cls");
    go(28,1);SetConsoleTextAttribute(h,0x0A);
    cout<<"Welcome Back Sir !\n\n";
    SetConsoleTextAttribute(h,0x0F);}
void customer(string u){
system("cls");
while(true){
go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. Sign Out";
go(28,1);
SetConsoleTextAttribute(h,0x0E);
cout<<"Welcome Back Dear "<<u<<" !\n\n";
SetConsoleTextAttribute(h,0x0A);
cout<<"\n\n\n1. Show Main Menu\n\n2. Start Ordering\n\n";
int n;
    SetConsoleTextAttribute(h,0x0F);
    cin>>n;
    switch(n){
        case 0:log(2);return;
        case 1:menu(u);return;
        case 2:order(u);return;
        default:system("cls");SetConsoleTextAttribute(h,0x0C);cout<<"\n\n\n\nOops So Far ! Only u can press 1";
}
}
}
void log(int a){
system("cls");
if(a==1){
    string user,pass;
    ifstream log("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Security\\ManLogin.txt");
    log>>user;log>>pass;
    log.close();
    string u,p;
    while(true){
    SetConsoleTextAttribute(h,0x0E);
    cout<<"\n Please Enter Your Username & Password\n\n";SetConsoleTextAttribute(h,0x0A);
    SetConsoleTextAttribute(h,0x0C);
    go(1,23);cout<<"0. Back to Login Page";go(0,5);SetConsoleTextAttribute(h,0x0A);
    cout<<"\n\n Username : ";SetConsoleTextAttribute(h,0x0F);cin>>u;SetConsoleTextAttribute(h,0x0A);if(u=="0"){start();return;}
    cout<<"\n\n Password : ";SetConsoleTextAttribute(h,0x0F);cin>>p;if(p=="0"){start();return;}
    if(u==user&&p==pass){
            manager();return ;}else{
                system("cls");SetConsoleTextAttribute(h,0x0C);cout<<"\n Username or Password is Wrong !\n\n";SetConsoleTextAttribute(h,0x0E);}
}
}
if(a==2){
go(28,1);
SetConsoleTextAttribute(h,0xF0);
cout<<" Welcome To Your Restaurant !\n\n\n";
while(true){
SetConsoleTextAttribute(h,0x0A);
cout<<"\n\n1.Already have account ?\n Press 1 to Login to Your Account\n\n\n";
cout<<"2.New Hear ?\n Press 2 to Craete Your own Account ! \n\n";
int n;
SetConsoleTextAttribute(h,0x0C);
go(1,23);cout<<"0. Back to Login Page";go(0,14);
SetConsoleTextAttribute(h,0x0F);
cin>>n;
if(n==1){cuslog();return;}
if(n==2){newcus();return;}
if(n==0){start();return;}
else{system("cls");go(28,1);
SetConsoleTextAttribute(h,0xF0);
cout<<" Welcome To Your Restaurant !\n\n";
SetConsoleTextAttribute(h,0x0C);
cout<<"\nOops So far! 1 or 2 ?\n";}
}

}
}
void cuslog(){
system("cls");
string user,pass;
go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. Back to Customer Page";go(0,0);
    while(true){
    ifstream in("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Security\\CusLogin.txt");
    string u,p;
    SetConsoleTextAttribute(h,0x0E);
    cout<<"\n Please Enter Your Username & Password\n\n";SetConsoleTextAttribute(h,0x0A);
    cout<<"\n Username : ";SetConsoleTextAttribute(h,0x0F);cin>>u;if(u=="0"){log(2);return;}
    SetConsoleTextAttribute(h,0x0A);
    cout<<"\n\n Password : ";SetConsoleTextAttribute(h,0x0F);
    cin>>p;if(p=="0"){log(2);return;}
    for(int j=0;j<members;j++){
        in>>user;
        if(user==u){in>>pass;if(pass==p){in.close();customer(u);return;}}
    }
    system("cls");
    SetConsoleTextAttribute(h,0x0C);
    cout<<"\n Username or Password is Wrong !\n\n";go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. Back to Customer Page";go(0,3);
}

}
void newcus(){
system("cls");
ofstream checkin;
string user,pass,p_ver;
go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. Back to Customer Page";
go(27,1);
SetConsoleTextAttribute(h,0xF0);
cout<<" Welcome to Our Restaurant Sir !"<<endl;
go(27,2);
cout<<" We are Proud to have you Here .\n\n\n\n";
SetConsoleTextAttribute(h,0x0E);
cout<<" Now Lets Create Your Account :\n\n"<<endl;
cout<<" Please Enter Your Username :\n\n";
SetConsoleTextAttribute(h,0x0C);
cout<<" NOTE : Your Username Should NOT Contains ANY Spaces !\n\n\n";
SetConsoleTextAttribute(h,0x0A);
cout<<"  Username : ";
SetConsoleTextAttribute(h,0x0F);
cin>>user;if(user=="0"){log(2);return;}
while(true){
SetConsoleTextAttribute(h,0x0E);
cout<<"\n Now Please Enter a Strong Password :\n\n";
SetConsoleTextAttribute(h,0x0C);
cout<<" NOTE : Your Password Should NOT Contains ANY Spaces !\n\n\n";
SetConsoleTextAttribute(h,0x0A);
cout<<"  Password : ";
SetConsoleTextAttribute(h,0x0F);
cin>>pass;if(pass=="0"){log(2);return;}
SetConsoleTextAttribute(h,0x0E);
cout<<"\n Please ReEnter Your Password : \n\n";
SetConsoleTextAttribute(h,0x0A);
cout<<"  Confirm Password : ";
SetConsoleTextAttribute(h,0x0F);
cin>>p_ver;if(p_ver=="0"){log(2);return;}
if(pass==p_ver){break;}else{system("cls");go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. Back to Customer Page";
go(27,1);
SetConsoleTextAttribute(h,0xF0);
cout<<" Welcome to Our Restaurant Sir !"<<endl;
go(27,2);
cout<<" We are Proud to have you Here .\n\n\n\n";
SetConsoleTextAttribute(h,0x0C);
cout<<" Passwords are Not Match ! Please Try Again\n\n";}
}
checkin.open("F:\\Codes\\CPP Codes\\Projects\\FastFood Management\\Files\\Security\\CusLogin.txt",ios_base::app);
checkin<<user<<" "<<pass<<endl;
members++;
checkin.close();
SetConsoleTextAttribute(h,0x0E);
cout<<"\nAll Done ! Now Your Account is Ready to Use .\n\n";
SetConsoleTextAttribute(h,0x0A);
cout<<"\nPress 1 to Login to Your Account ";
int n;
while(true){
    SetConsoleTextAttribute(h,0x0F);
    cin>>n;
    if(n==1){cuslog();return;}
    else{SetConsoleTextAttribute(h,0x0C);cout<<"You Can Only Press 1 Sir !\n";}
}
}
void start(){
system("cls");
while(true){
go(1,23);SetConsoleTextAttribute(h,0x0C);cout<<"0. GoodBye !";
go(33,1);SetConsoleTextAttribute(h,0xF0);cout<<" Hello Dear ";go(25,2);cout<<" Welcome To Your Restaurant ! \n\n";
SetConsoleTextAttribute(h,0x0E);
cout<<"\n\n Login as :\n \n"<<endl;
SetConsoleTextAttribute(h,0x0A);
cout<<"1. Customer\n\n2. Manager\n\n\n";
SetConsoleTextAttribute(h,0x0F);
string n;cin>>n;
        if(n=="1"||n=="Customer"||n=="customer"){
            log(2);return;}else if(n=="2"||n=="Manager"||n=="manager"){
                log(1);return;}else if(n=="0"){return;}else{system("cls");
                        SetConsoleTextAttribute(h,0x0C);cout<<"\nOops So far! 1 or 2 ?\n"<<endl;SetConsoleTextAttribute(h,0x0F);}
}
}
int main (){
start();
system("cls");
go(28,3);
SetConsoleTextAttribute(h,0x0A);
cout<<"Thank You for Choosing Us !";go(30,5);cout<<"We Wait For Your Back";
SetConsoleTextAttribute(h,0x00);go(0,21);
return 0;
}
