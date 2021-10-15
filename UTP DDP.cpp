#include <iostream>
#include <string>

using namespace std;

//Fungsi untuk mengecek umur dibawah 3 Tahun
int cek_umur(int umur, int banyak_penumpang){
	if (umur <= 2){
		banyak_penumpang -= 1;
	}
	
	return banyak_penumpang;	
}

//Fungsi menghitung harga tiket
int garuda(int banyak_penumpang){
	
	int harga = banyak_penumpang*1500000;
	int ppn = 0.1*harga;
	int total = harga+ppn;
	
	return harga,ppn,total;
}

int sriwijaya(int banyak_penumpang){
	
	int harga = banyak_penumpang*1300000;
	int ppn = 0.1*harga;
	int total = harga+ppn;
	
	return harga,ppn,total;
}

int batik(int banyak_penumpang){
	
	int harga = banyak_penumpang*1200000;
	int ppn = 0.1*harga;
	int total = harga+ppn;
	
	return harga,ppn,total;
}

int lion(int banyak_penumpang){
		
	int harga = banyak_penumpang*1000000;
	int ppn = 0.1*harga;
	int total = harga+ppn;
	
	return harga,ppn,total;
}

//fungsi print tiket
void print_tiket(string nama_pesawat,int harga_tiket,string to,string from,string hari,int banyak_penumpang_tmp,string nama[],int umur[]){
	cout<<"============================================\n";
	cout<<"|              INVOICE TICKET              |\n";
	cout<<"============================================\n";
	cout<<"Pesawat      : "<<nama_pesawat <<endl;
	cout<<"Tujuan       : "<<from <<" - "<<to <<endl;
	cout<<"Hari/Tanggal : "<<hari <<endl;
	cout<<"============================================\n";
	
	for(int i = 0; i < banyak_penumpang_tmp; i++){
		
		cout<<"Penumpang "<< i+1 <<endl;
		cout<<"Nama         : "<<nama[i]<<endl;
		cout<<"Umur         : "<<umur[i]<<endl;
		cout<<endl;
	}
	
	cout<<"============================================\n";
	cout<<"                              Rp "<<harga_tiket<<endl;
	cout<<"============================================\n";
		
}


int main(){
	
	//Deklarasi Variabel
	int banyak_penumpang,pesawat,harga_tiket;
	string from,to,hari,x,nama_pesawat;
	string nama[10];
	int umur[10];
	
	//header
	cout<<"=======================================\n";
	cout<<"============= TERBANG KUY =============\n";
	cout<<"=======================================\n\n";
	
	cout<<"Selamat Datang di Terbang Kuy\n";
	cout<<"Toko No.1 di Indonesia\n \n";
	
	//Lokasi dan tujuan pembeli
	cout<<"Ketik Lokasi dan Tujuan Anda \n \n";
	cout<<"From : ";
	getline(cin,from);
	cout<<"To : ";
	getline(cin,to);
	cout<<"Hari/Tanggal : ";
	getline(cin,hari);
	
	//clear screen
	system("CLS");
	
	//Memilih Pesawat
	menu:	
		cout<<"____________________________-- PENCARIAN PESAWAT --____________________________\n\n";
		cout<<"	Tujuan Anda		Nama Pesawat		Tanggal Penerbangan\n\n";
		cout<<"1. "<<from <<" - "<<to <<"		Garuda Indonesia	"<<hari <<endl;
		cout<<"2. "<<from <<" - "<<to <<"		Sriwijaya Air		"<<hari <<endl;
		cout<<"3. "<<from <<" - "<<to <<"		Batik Air		"<<hari <<endl;
		cout<<"4. "<<from <<" - "<<to <<"		Lion Air		"<<hari <<endl <<endl;
		
		cout<<"Pilih Pesawat (1,2,3,4): ";
		cin>>pesawat;
		
		if (pesawat == 1 || pesawat == 2 || pesawat == 3 || pesawat == 4){
			goto data;
		}
		
		else {
			cout<<"\nMaaf Pesawat tidak ada\n\n";
			goto menu;
		}
	
	//Memasukan Data penumpang
	data:
		system("CLS");
		cout<<"___________________ DATA PENUMPANG ___________________\n\n";
		cout<<"Penumpang dibawah umur 3 tahun tidak di kenakan biaya\n";
		cout<<"______________________________________________________\n\n";
		cout<<"Banyak Penumpang : ";
		cin>>banyak_penumpang;
		cout<<endl;
		
		for(int i = 0 ; i < banyak_penumpang; i++){
				
			cout<<"Data ke - "<< i + 1 <<endl;
			cout<<"Nama : ";
			cin.ignore(1,'\n');
			getline(cin,nama[i]);
			cout<<"Umur : ";
			cin>>umur[i]; 
			cout<<endl;
		}
		cout<<endl;

	system("CLS");
	
	//Konfirmasi Data
	cout<<"_______________ KONFIRMASI DATA ______________\n\n";
	for(int i = 0; i < banyak_penumpang; i++){
		
		cout<<"Data ke - "<< i+1 <<endl;
		cout<<"Nama : "<<nama[i]<<endl;
		cout<<"Umur : "<<umur[i]<<endl;
		cout<<endl;
	}
	
	cout<<endl;
	
	//Verifikasi Data
	verif :
		cout<<"Apakah data sudah benar? (Y/N) : ";
		cin>>x;
		
		if(x == "N" || x == "n"){
			system("CLS");
			goto data;				
		}
		
		else if (x == "Y" || x == "y") {
			goto invoice;
		}
		
		else{
			cout<<"\nMaaf pilihan tidak diterima\n\n";
			goto verif;
		}
	
	//Print Tiket	
	invoice:
		int banyak_penumpang_tmp = banyak_penumpang;
		
		for(int i = 0; i < banyak_penumpang; i++){
			banyak_penumpang = cek_umur(umur[i],banyak_penumpang_tmp);
		}	
		
		if (pesawat == 1){
			nama_pesawat = "Garuda Indonesia";
			harga_tiket = garuda(banyak_penumpang);
			system("CLS");
			print_tiket(nama_pesawat,harga_tiket,to,from,hari,banyak_penumpang_tmp,nama,umur);
		}
		
		else if(pesawat == 2){
			nama_pesawat = "Sriwijaya Air";
			harga_tiket = sriwijaya(banyak_penumpang);
			system("CLS");
			print_tiket(nama_pesawat,harga_tiket,to,from,hari,banyak_penumpang_tmp,nama,umur);
		}
		
		else if(pesawat == 3){
			nama_pesawat = "Batik Air";
			harga_tiket = batik(banyak_penumpang);
			system("CLS");
			print_tiket(nama_pesawat,harga_tiket,to,from,hari,banyak_penumpang_tmp,nama,umur);
		}
		
		else if(pesawat == 4){
			nama_pesawat = "Lion Air";
			harga_tiket = lion(banyak_penumpang);
			system("CLS");
			print_tiket(nama_pesawat,harga_tiket,to,from,hari,banyak_penumpang_tmp,nama,umur);
		}
	
	cout<<endl;
	cout<<"Terima Kasih sudah berbelanja di Terbang Kuy Store!";
	
	return 0;
}

