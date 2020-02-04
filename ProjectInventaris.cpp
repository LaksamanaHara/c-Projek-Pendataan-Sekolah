#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#define max 100

using namespace std;

//variabel global
struct inventaris
{
	char nama[30],id[5],jalan[30],kec[30],kota[30],prov[30];
} inven[max];


int i,j,k,p,q,pilih;
char cari[20], keluar,temp[100];
FILE *f;

//procedure

void InputData();
void Tampilan();
void Pencarian();
void Cetak();
void shorting();

//main Program
int main(){
	
	//menu Awal
	
	awal:
		cout <<"Pilihan"<<endl;
		
		cout <<"1. Masukan Nama Sekolah"<<endl;
		cout <<"2. Tampilkan Data"<<endl;
		cout <<"3. Pencarian Data"<<endl;
		cout <<"4. Sorting Data"<<endl;
		cout <<"5. Cetak Data"<<endl;
		cout <<"6. Selesai"<<endl;
		cout <<"Pilih (1-6) : "; cin>>pilih;
		system("cls");
		switch(pilih)
		{ 
			case 1 : //Proses inputan data
			InputData();
			system("cls"); goto awal;
			
			case 2 : //InputanDATA
			cout << "D A T A   S E K O L A H\n\n";
			Tampilan();
			getch(); system("cls"); goto awal;
			
			case 3 : //Proses Pencarian Data
			Pencarian();
			getch(); system("cls"); goto awal;
			
			case 4 : //proses sorting data
			shorting();
			getch(); system("cls"); goto awal;
			
			case 5 : //Cetak File txt
			Cetak();
			getch() ; system("cls"); goto awal;
			
			case 6 : //Keluar gaess
			cout <<"Ingin Keluar (y/n) : ";
			cin >> keluar;
			if (keluar == 'y' || keluar == 'Y')
			{
				exit(0);
			}
			else
			{
				system("cls"); goto awal;
			}
			default : cout<<"\n Pilihan Tidak Tersedia";
			getch(); system("cls"); goto awal;
		}	
}

void InputData()
{
			f=fopen("Data Sekolah.txt", "w");
			cout << "Masukan Jumlah Data yang Dibutuhkan : "; cin>>j;
			cout <<endl<<endl;
			cin.ignore();
			for(int i =1; i<=j;i++ ){
					cout <<"Data ke-"<<i<<endl;
					cout <<"Nama Data\t : "; cin.getline(inven[i].nama,sizeof(inven[i].nama));
					cout <<"ID\t\t : "; cin.getline(inven[i].id,sizeof(inven[i].nama));
					cout <<"Jalan\t\t : "; cin.getline(inven[i].jalan,sizeof(inven[i].jalan));
					cout <<"Kecamatan\t : "; cin.getline(inven[i].kec,sizeof(inven[i].kec));
					cout <<"Kota/Kabupaten\t : "; cin.getline(inven[i].kota,sizeof(inven[i].kota));
					cout <<"Provinsi\t : "; cin.getline(inven[i].prov,sizeof(inven[i].prov));
					cout <<endl;
			}
			cout<<endl;
                fwrite(&j, sizeof(j), 1, f);
                fwrite(&inven, sizeof(inven), 1, f);
                fclose(f);
					
		
		

}

void Tampilan()
{		f=fopen("Data sekolah.txt", "r");
        fread(&j, sizeof(j), 1, f);
        fread(&inven, sizeof(inven), 1, f);
		for(int i=1;i<=j;i++){
		cout <<"Data ke-"<<i<<endl;
		cout <<"Nama Data\t : "<<inven[i].nama<<endl;
		cout <<"ID\t\t : "<<inven[i].id<<endl;
		cout <<"Jalan\t\t : "<<inven[i].jalan<<endl;
		cout <<"Kecamatan\t : "<<inven[i].kec<<endl;
		cout <<"Kota/Kabupaten\t : "<<inven[i].kota<<endl;
		cout <<"Provinsi\t : "<<inven[i].prov<<endl;
		cout <<endl;
		} 
		 fclose(f);
}
void Pencarian()
{
	k=0;
	cout<<"\nCari ID : "; cin>>cari;
	for(i=1; i<=j; i++)
	{
		if(strcmp(cari,inven[i].id)==0)
		{
			cout<<"\nID Ditemukan Didata ke-"<<i<< " Dengan nama "<<inven[i].nama<<endl;
			cout <<"Jalan\t\t : "<<inven[i].jalan<<endl;
			cout <<"Kecamatan\t : "<<inven[i].kec<<endl;
			cout <<"Kota/Kabutpaten\t : "<<inven[i].kota<<endl;
			cout <<"Provinsi\t : "<<inven[i].prov<<endl;
			cout <<endl;
			k++;
		}
	}
	if (k!=0)
	{
		cout <<"Jumlah ID yang Ditemukan "<<k<<" ID ";
	}
	else
	{
		cout <<"ID Tidak Ditemukan";
	}
}

void Cetak()
{
	
	ofstream file_keluaran;
	file_keluaran.open("Data Sekolah.TXT");
	cout<<"Berhasil Dicetak.."<<endl<<"Silakan Cek di TXT"<<endl;
	for(i=1; i<=j; i++)
	{
		file_keluaran<<"Data ke-"<<i<<endl;
		file_keluaran<<"Nama Data -"<<inven[i].nama<<endl;
		file_keluaran<<"ID -"<<inven[i].id<<endl;
		file_keluaran<<"Jalan -"<<inven[i].jalan<<endl;
		file_keluaran<<"Kecamatan -"<<inven[i].kec<<endl;
		file_keluaran<<"Kota/Kabupaten -"<<inven[i].kota<<endl;
		file_keluaran<<"Provinsi -"<<inven[i].prov<<endl;
	}
	file_keluaran.close();
}

void shorting()
{
	for(p=1; p<=j; p++){
		for(q=1; q<=j; q++){
			if(inven[p].nama > inven[q].nama){
				strcpy(temp,inven[q].nama); 
			 
				strcpy(inven[q].nama,inven[p].nama);
				strcpy (inven[p].nama,temp);
			
			}
		}
	}
	cout << "Hasil Pengurutan : \n";
for(p=1; p<=j; p++){
	cout << "Data ke" <<p<<" = " << inven[p].nama<<endl;
	cout << "Data ke" <<p<<" = " << inven[p].id<<endl;
	cout << "Data ke" <<p<<" = " << inven[p].jalan<<endl;
	cout << "Data ke" <<p<<" = " << inven[p].kec<<endl;
	cout << "Data ke" <<p<<" = " << inven[p].kota<<endl;
	cout << "Data ke" <<p<<" = " << inven[p].prov<<endl;
}
getch();
	
}
