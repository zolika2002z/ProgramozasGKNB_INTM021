// 5/4, amely a 3/6 függvényes verziója 
#include<iostream>
//#include<cctype>  // ha nincs, nem működnek a makrók!?
#include<cstring> // strlen() fgv.-hez!

#define MAX 128
#define LT 7

using namespace std;

bool beker(char rszm[])
{
 cout << "\n Kérem a rendszámot: ";
 cin.getline(rszm,MAX); cout << endl;
 int hsz=strlen(rszm);
 if(hsz!=LT) return false;
 for(int i=0; i<LT; i++)
  { 
   if(i<3 and not isalpha(rszm[i])) return false;
   else if(i>=4 and not isdigit(rszm[i])) return false;
   else if(not (rszm[3]=='-' or rszm[3]=='_' or isspace(rszm[3])) ) return false;
  }
 return true;
}

void ertekel(char rszm[])
{
 bool es;
 for(int i=0; i<LT; i++)
    {
     es=0;
     if(isalnum(rszm[i])) { cout << "'" << rszm[i] << "' => alfanumerikus"; es=1; }
     if(islower(rszm[i])) cout << " és kisbetű";
     if(isupper(rszm[i])) cout << " és nagybetű";
     if(isprint(rszm[i])) {
       if(es) cout << " és nyomtatható!" << endl;
       else cout << "'" << rszm[i] << "' => nyomtatható!" << endl; }
     if(isspace(rszm[i])) cout << "'" << rszm[i] << "' => fehérkarakter!" << endl;
     if(not isxdigit(rszm[i])) cout << "'" << rszm[i] << "' => nem hexadecimális!" << endl;
     else cout << "'" << rszm[i] << "' => hexadecimális is!" << endl;
     rszm[i]=toupper(rszm[i]); // tolower(); kisbetűsre alakít
     if(i==3 and rszm[i]!='-') rszm[i]='-'; cout << endl; 
    } // for
 cout << "\n A rendszám helyes: " << rszm << endl;
}

int main() {
  char rsz[MAX];
  bool helyes;
  do {
        helyes=beker(rsz);
        if(helyes) ertekel(rsz);
        else cout << " Helytelen a rendszám!";
    } while(not helyes);
return 0;
}