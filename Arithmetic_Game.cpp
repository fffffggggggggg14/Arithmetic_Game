#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enLevel {Easy = 1, Mod, Hard, Mix};
enum enType {Add = 1, Sub, Mul, Div, Mi};

void App();
int RandNumber(string S, int FROM);
void BakeApp(int n);
enLevel ReadAppLevel(string S, int FROM, int TO);
enType ReadAppType(string S, int FROM, int TO);
string STRINGLevel(int n);
string STRINGType(int n);
string STRINGTYPE_(int n);
int LevelNumber(int n);
int RandNumber(int FROM, int TO);
void PRINTFAndCheckNumber(int i, int n, int Level, string STRINGTYPE, int Type, int &T, int &F);
void PRINTFNumber(int i, int n, int n1, int n2, string STRINGTYPE);
bool CheckQuestion(int Type, int n1, int n2);
void TrueQuestion(int &T);
void FalseQuestion(int &F);
void PRINTFPASS(int T, int F);
void PRINTFData(int n, string StringLevel, string StringType, int T, int F);
void ClearApp();

int main(void){
srand((unsigned)time(NULL));
App();
return 0;
}

void App(){
int n;
string Y;
do{
ClearApp();
n = RandNumber("How Many Questions: ", 1);
BakeApp(n);

do{
cout << "App Again (Y/N): ";
cin >> Y;
}while(Y != "Y" && Y != "y" && Y != "N" && Y != "n");

}while(Y == "Y" || Y == "y");
}

int RandNumber(string S, int FROM){
int n;
do{
cout << S;
cin >> n;
}while(n < FROM);
return n;
}

void BakeApp(int n){
int Level, Type, T = 0, F = 0;
string StringLevel, StringType, STRINGTYPE;
Level = ReadAppLevel("Level [1]Easy, [2]Mod, [3]Hard, [4]Mix: ", 1, 4);
Type = ReadAppType("Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix: ", 1, 5);
StringLevel = STRINGLevel(Level);
StringType = STRINGType(Type);
STRINGTYPE = STRINGTYPE_(Type);

for(int i = 0; i < n; i++){
PRINTFAndCheckNumber(i, n, Level, STRINGTYPE, Type, T, F);
}

PRINTFPASS(T, F);
PRINTFData(n, StringLevel, StringType, T, F);

}

enLevel ReadAppLevel(string S, int FROM, int TO){
int n;
do{
cout << S;
cin >> n;
}while(n < FROM || n > TO);
return (enLevel)n;
}

enType ReadAppType(string S, int FROM, int TO){
int n;
do{
cout << S;
cin >> n;
}while(n < FROM && n > TO);
return (enType)n;
}

string STRINGLevel(int n){
string S[4] = {"Easy", "Mod", "Hard", "Mix"};
return S[n - 1];
}

string STRINGType(int n){
string S[5] = {"Add", "Sub", "Mul", "Div", "Mix"};
return S[n - 1];
}

string STRINGTYPE_(int n){
string S[5] = {"+", "-", "*", "/", ""};
return S[n - 1];
}

int LevelNumber(int n){
if(n == enLevel::Easy){return RandNumber(0, 10);}
if(n == enLevel::Mod){return RandNumber(10, 100);}
if(n == enLevel::Hard){return RandNumber(100, 1000);}
if(n == enLevel::Mix){return RandNumber(0, 1000);}
}

int RandNumber(int FROM, int TO){
return rand() % (TO - FROM + 1) + 1;
}

void PRINTFAndCheckNumber(int i, int n, int Level, string STRINGTYPE, int Type, int &T, int &F){
int n1 = LevelNumber(Level), n2 = LevelNumber(Level);

if(Type == enType::Mi){
Type = RandNumber(1, 4);
STRINGTYPE = STRINGTYPE_(Type);
}


PRINTFNumber(i, n, n1, n2, STRINGTYPE);

if(CheckQuestion(Type, n1, n2)){
TrueQuestion(T);
}
else{FalseQuestion(F);}

}


void PRINTFNumber(int i, int n, int n1, int n2, string STRINGTYPE){
cout << "Question [" << i + 1 << "/" << n << "]\n\n";
cout << n1 << endl;
cout << n2 << " " << STRINGTYPE <<  endl;
cout << "____________________________________\n";
}

bool CheckQuestion(int Type, int n1, int n2){
int X;
cin >> X;

if(Type == enType::Add){
if(X == (n1 + n2)){return 1;}
return 0;
}

if(Type == enType::Sub){
if(X == (n1 - n2)){return 1;}
return 0;
}

if(Type == enType::Mul){
if(X == (n1 * n2)){return 1;}
return 0;
}

if(Type == enType::Div){
if(X == (n1 / n2)){return 1;}
return 0;
}
}

void TrueQuestion(int &T){
cout << "True (-:\n\n";
system("color 2F");
T++;
}

void FalseQuestion(int &F){
cout << "False )-:\n\n";
system("color 4F");
cout << "\a";
F++;
}

void PRINTFPASS(int T, int F){
if(T >= F){
cout << "_______________________________________\n";
cout << "P A S S  (-:\n";
cout << "_______________________________________\n";
}
else {
cout << "_______________________________________\n";
cout << "N O   P A S S  )-:\n";
cout << "_______________________________________\n";
}
}

void PRINTFData(int n, string StringLevel, string StringType, int T, int F){
cout << "Count Question: " << n << endl;
cout << "Level: " << StringLevel << endl;
cout << "Type: " << StringType << endl;
cout << "True: " << T << endl;
cout << "False: " << F << endl;
cout << "_________________________________________\n";
}

void ClearApp(){
system("color 0F");
system ("cls");
}