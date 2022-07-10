#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;
char jawaban,bot;
const char Batu='b';
const char Kertas='k';
const char Gunting='g';
string ronde[3]; //array banyaknya ronde
int point[2]={0,0}; // array untuk menentukan point/skor
int i,j;
struct tumpukan{
    int atas; //menentukan batas atas stack
    string nyawa[3]={"|<3|","|<3|","|<3|"}; // array banyaknya nyawa
}T;
void awal(){
    T.atas=2; //batas atas awal berada di indeks ke 2
}
// void untung menampilkan sisa nyawa
void nyawa(){
    if (T.atas !=-1){
        for(int i=T.atas;i>=0;i--){
            cout<<endl<<T.nyawa[i];
        }
        }else{
            cout<<"nyawa habis";
        }
}
// fungsi untuk merandom jawaban bot
int acak(){
    srand (time(0));
    
    int nomor = rand()%3;
    
    if(nomor==0) return Batu;
    if(nomor==1) return Gunting;
    if(nomor==2) return Kertas;
}
int bonus(){ //untuk merandom bonus nyawa apabila bonus()==1 maka nyawa player akan ditambah 1 apabila menang
    srand (time(0));
    
    int number = rand()%4;
    
    if(number==0) return 1;
}
// fungsi untuk menampilkan tampilan permainan
int display(){
    cout<<endl;
   
    cout<<"sisa nyawa anda: "<<endl;
     nyawa();
     cout<<endl;
     cout<<"Ronde "<<i+1;
    cout << "\nGim  batu gunting kertas" << endl;
    cout << "-----------------------------------"  << endl;
    cout << "(b) untuk batu " << endl << "(k) untuk kertas" << endl << "(g) gunting " << endl;
    cout << "pilih jagoan anda!"  << endl;
    cin >> jawaban;
    
    while (jawaban!='b' && jawaban!='k' && jawaban!='g' ) // program akan di ulang apabila inputan tidak sesuai
    {
        cout << "Milih opo koe ki jane " << endl;
        cout << "(b) untuk batu " << endl << "(k) untuk kertas" << endl << "(g) gunting " << endl;
        cin >> jawaban;
    }
 
    return jawaban;
} 
// void untuk output dari jawaban yang kita pilih
void pilihan(char jawaban) {
    if (jawaban == 'b') cout << "Batu" << endl;
    if (jawaban == 'k') cout << "Kertas" << endl;
    if (jawaban == 'g') cout << "Gunting" << endl;
}
//void untuk menentukan kalah atau menang
void situasi(char jawaban, char bot) {
    if (jawaban == Batu && bot == Kertas) {
        cout << "Kalah mas"<< endl;
        T.atas--; //T.atas akan dikurangi apabila kita kalah
        ronde[i]="kalah"; //kalimat kalah akan di input ke dalam array ronde
        point[1]++; // nilai dari array point indeks ke 1 akan ditambah 1
    }
    else if (jawaban == Kertas && bot == Gunting) {
        cout << "Kalah gan"<< endl;
        T.atas--;
         ronde[i]="kalah";
         point[1]++;
    }
    else if (jawaban == Gunting && bot == Batu) {
        cout << "Ciee kalah"<< endl;
        T.atas--;
         ronde[i]="kalah";
         point[1]++;
    }
    else if (jawaban == Batu && bot == Gunting) {
        cout << "Asek menang"<< endl;
         ronde[i]="menang"; //kalimat menang akan di input ke array ronde menyesuaikan ronde yang sedang berlangsung
         point[0]++; //nilai dari array point indeks ke 0 akan ditambah 1
         if (bonus()==1 && T.atas!=2){ //jika bonus()=1 maka T.atas akan ditambah 1 sehinggga nyawa bertambah
         	T.atas++;
		 }
    }
    else if (jawaban == Kertas && bot == Batu) {
        cout << "Anda menang"<< endl;
        ronde[i]="menang";
        point[0]++;
          if (bonus()==1 && T.atas!=2){ 
         	T.atas++;
		 }
    }
    else if (jawaban == Gunting && bot == Kertas) {
        cout << "Anjay menang"<< endl;
        ronde[i]="menang";
        point[0]++;
    if (bonus()==1 && T.atas!=2){ 
         	T.atas++;
		 }
    }
    else{
        cout << "Seri gan" << endl;
        ronde[i]="menang";
        point[0]++;
    }
       
}
//void dari inti permainan
void inti(){
	awal();
  for (i=0; i<3;i++){  // ronde akan diadakan sebanyak 3 kali
   display();
   if (bonus()==1){
   	cout<<"Bonus nyawa!!!"<<endl;
   }
    cout << "pilihanmu: "<< endl;
   pilihan(jawaban);
    
    cout << "Bot: "<< endl;
    bot = acak();
    pilihan(bot);
    
    situasi(jawaban, bot);
  }
 if (T.atas == 2 || T.atas == 1){
     cout<<"selamat anda menang ";
 }else if ( T.atas == 0 || T.atas==-1)  {
     cout<<"kalah kok sama bot ";
 }
 
}
//void untuk mengetahui histori permainan
void histori(){
	string cari;
	int ketemu=0;
	cout<<"Histori ronde yang ingin dicari (menang/kalah)";
	cin>>cari;
	for(j=0;j<3;j++){
	 if (ronde[j]==cari)
	  {
		  ketemu=1;
		  cout<<"ronde yang anda cari "<<j+1<<endl;
	  }
  }
  if (ketemu==0)
  {
  	cout<<"Data tidak ditemukan";	
	}
}
//void pengurutan skor
void skor(){
	int tmp;
for(i=0;i<2;i++){
	for(j=i+1;j<2;j++){
		if(point[i]<point[j]){ //apabila nilai dari point[i] lebih kecil dari point[j] makan program pengurutan akan dilakukan
		tmp=point[j];
		point[j]=point[i];
		point[i]=tmp;
	}
	}
}
if (T.atas == 2 || T.atas == 1){
     cout<<"selamat anda menang dengan skor"<<endl;
     cout<<"Anda\tBot"<<endl;
 }else if ( T.atas == 0 || T.atas==-1)  {
     cout<<"Anda kalah dengan skor"<<endl;
     cout<<"Bot\tAnda"<<endl;
 }
for(i=0;i<2;i++){ //perulangan untuk output skor
	cout<<point[i]<<"\t";
}
}
int main() {
	int pil;
	menu:
    cout<<"\n------Main menu------"<<endl;
    cout<<"1.Main game"<<endl;
    cout<<"2.History permainan"<<endl;
    cout<<"3.skor"<<endl;
    cout<<"4.Keluar"<<endl;
    cout<<"Pilih : ";
    cin>>pil;
    system("CLS");
    switch(pil){
    	case 1:
    		inti();
    		goto menu;
    	case 2:
    		histori();
    		goto menu;
    	case 3:
    		skor();
    		goto menu;
    	default:
    	break;
	}
 
 getch();
 
}
