#include <iostream>
#include <cstdlib>
#define max 3
using namespace std;
char Batu,Kertas,Gunting;
char jawaban,bot;

const char keluaran [3]={Batu='b', Kertas = 'k', Gunting = 'g'};
struct tumpukan{
    int atas;
    string data[max]={"<3","<3","<3"};
}T;
void awal(){
    T.atas=2;
}

void tampil(){
    if (T.atas !=-1){
        for(int i=T.atas;i>=0;i--){
            cout<<"\n| "<<T.data[i]<<" |";
        }
        }else{
            cout<<"nyawa habis";
        }
}

int acak(){
    srand (time(0));
    
    int nomor = rand()%3+1;
    
    if(nomor==1) return keluaran[0];
    if(nomor==2) return keluaran[1];
    if(nomor==3) return keluaran[2];
}

int display(){
    cout<<"\nSisa nyawa anda: ";
     tampil();
    cout << "\nGim  batu gunting kertas" << endl;
    cout << "-----------------------------------"  << endl;
    cout << "(b) untuk batu " << endl << "(k) untuk kertas" << endl << "(g) gunting " << endl;
    cout << "pilih jagoan anda!"  << endl;
    cin >> jawaban;
    
    while (jawaban!='b' && jawaban!='k' && jawaban!='g' )
    {
        cout << "Milih opo koe ki jane " << endl;
        cout << "(b) untuk batu " << endl << "(k) untuk kertas" << endl << "(g) gunting " << endl;
        cin >> jawaban;
    }
 
    return jawaban;
} 
void pilihan(char jawaban) {
    if (jawaban == 'b') cout << "Batu" << endl;
    if (jawaban == 'k') cout << "Kertas" << endl;
    if (jawaban == 'g') cout << "Gunting" << endl;
}
void situasi(char jawaban, char bot) {
    if (jawaban == Batu && bot == Kertas) {
        cout << "yahaha kalah kok sama bot"<< endl;
        T.atas--;
    }
    else if (jawaban == Kertas && bot == Gunting) {
        cout << "yahaha kalah kok sama bot"<< endl;
        T.atas--;
        
    }
    else if (jawaban == Gunting && bot == Batu) {
        cout << "Blok kalah kok mbek bot su!!"<< endl;
        T.atas--;
        
    }
    else if (jawaban == Batu && bot == Gunting) {
        cout << "weleh menang no"<< endl;
        
    }
    else if (jawaban == Kertas && bot == Batu) {
        cout << "asu iso menang no"<< endl;
        
    }
    else if (jawaban == Gunting && bot == Kertas) {
        cout << "asu menang no"<< endl;
    }
    else{
        cout << "NT bro" << endl;
    }
       
}
int main() {
    awal();
  for (int i=0; i<3;i++){  
   display();
    cout << "pilihanmu: "<< endl;
   pilihan(jawaban);
    
    cout << "Bot: "<< endl;
    bot = acak();
    pilihan(bot);
    
    situasi(jawaban, bot);
  }
 if (T.atas == 2 || T.atas == 1){
     cout<<"selamat ";
 }else if ( T.atas == 0 || T.atas==-1)  {
     cout<<"kalah ";
 }
  
}
