#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int jumlah;
string _namaFile; // inisialisasi namaFile untuk baca file

struct data{    // struct buat biodata mahasiswa (nama, alamat, nim, berat badan, nilai)
    string nama, alamat;
    int nim, beratBadan;
    int nilai;
}biodata[50];

int _shell_sort (int[]); //inisialisasi fungsi shellSort
void _inputData();  //inisialisasi fungsi input data
void _bubbleSort(int*,int); //inisialisasi fungsi bubbleSort
void _insertionSort();  //inisialisasi fungsi IsertionSort
void _selectionSort();  //inisialisasi fungsi SelecrtionSort
void _sequentialSearch(); // inisialisasi fungsi SequentialSearch
void _binarySearch(); // inisialisasi fungsi binarySearch
void _buatFile();  //inisialisasi fungsi Buat File
//void _bacaFile();  //inisialisasi fungsi Baca FIle


int main(){

    int pilih, metode;
    char back, choose;
    do{
    cout<<endl;
    cout<<"|___ BIODATA MAHASISWA ___ |"<<endl; // halaman Utama
    cout<<"============================="<<endl;
    cout<<"Pilihan Menu"<<endl;
    cout<<"[1] Input Data"<<endl;
    cout<<"[2] Pengurutan Data"<<endl;
    cout<<"[3] Cari Data"<<endl;
    cout<<"[4] Buat & Baca Data"<<endl;
    cout<<"Pilih Menu : ";
    cin>>pilih;
    switch (pilih){
        case 1 : _inputData(); // halaman 1 (input data)
        break;
        case 2 : do{ // halaman sorting memiliki beberapa metode
                    cout<<endl;
                    cout<<"Pilih Metode Sorting"<<endl;
                    cout<<"[1] Bubble Sort"<<endl;
                    cout<<"[2] Insertion Sort"<<endl;
                    cout<<"[3] Selection Sort"<<endl;
                    cout<<"[4] Shell Sort"<<endl;
                    cout<<"Masukkan Pilihan : ";
                    cin>>metode;
                    switch(metode){ // metode sorting
                        case 1 : int Array[5],*pointer;
                        cout<<"Data belum urut"<<endl;
                        for(int j=1; j<=jumlah; j++){
                            cout<<biodata[j].nilai<<" ";
                            cout<<endl;
                        }
                                for(int num=1;num<=jumlah;num++)
                                {
                                Array[num] = biodata[num].nilai;
                                }
                                pointer=Array;
                                _bubbleSort(pointer,jumlah); //bubble sort
                        break;
                        case 2: _insertionSort();
                        break;
                        case 3 : _selectionSort();
                        break;
                        case 4 : 
                        int data[jumlah];
                        for(int b=1; b<=jumlah; b++){
                             data[jumlah] = biodata[b].nilai;
                        }
                        _shell_sort(data);
                        cout<<endl;
                        for(int k=1; k<=jumlah; k++){
                        cout<<data[k]<<" ";
                        }
                        break;    
                    }

            cout<<endl<<endl;
            cout<<"Pilih Metode Lain? (y/n) ";
            cin>>choose;
            system("cls");
            }while(choose == 'y' || choose == 'Y'); // Pemilihan menu metode sorting
        break;
        case 3 :
        int metode2;
        char backMetode;
        do{
        cout<<endl;
        cout<<"Metode Search"<<endl;
        cout<<"[1] Sequential Search"<<endl;
        cout<<"[2] Binary Search"<<endl;
        cout<<"Masukkan Metode Search : ";
        cin>>metode2;
        cout<<endl;
        switch(metode2){
            case 1 :_sequentialSearch();
            break;
            case 2 : _binarySearch();
        break;
        }
        cout<<endl;
        cout<<"Pilih Metode Lain? (y/n) ";
        cin>>backMetode;
        system("cls");
        }while(backMetode == 'y' || backMetode == 'Y');
        break;
        case 4 : // membuat dan membaca file dengan struct
        int pill;
        char backto;
        do{
        cout<<"Buat & Baca File"<<endl;
        cout<<"[1] Buat File"<<endl;
        cout<<"[2] Baca File"<<endl;
        cout<<"Mau Buat atau Baca? (1/2) : ";
        cin>>pill;
        switch(pill){
            case 1:_buatFile(); 
            break;
           case 2 : _bacaFile();
        }
        cout<<endl;
        cout<<"Pilih Metode Lain? (y/n) ";
        cin>>backto;
        system ("cls");
        }while(backto == 'y' || backto =='Y');
    }
    cout<<endl;
    cout<<"Kembali Ke menu? (Y/N) ";
    cin>>back;
    system("cls");
    }while (back == 'y' || back == 'Y'); // metode kembali ke menu

}

void _inputData(){    // fungsi input data dengan struct
    cout<<"--- Input Data ---"<<endl;
    cout<<"Masukkan Jumlah Data : ";
    cin>>jumlah;
    for(int i=1; i<=jumlah; i++){
        cout<<endl;
        cout<<"data ke-"<<i<<endl;
        cout<<"Input Nama\t : ";
        cin>>biodata[i].nama;
        cout<<"Input NIM\t : ";
        cin>>biodata[i].nim;
        cout<<"Input Nilai\t : ";
        cin>>biodata[i].nilai;
        cout<<"Input Berat Badan: ";
        cin>>biodata[i].beratBadan;
        cout<<"Input Alamat\t : ";
        cin>>biodata[i].alamat;

    }
}


void _bubbleSort(int *pointer,int jumlahh2){ //fungsi sorting bubbleSort dengan pointer
           jumlah = jumlahh2;
              int i,j,swap;
              for(i=1;i<jumlah;i++)
              {
                     for(j=i;j<=jumlah;j++)
                     {
                           if(*(pointer+i)>*(pointer+j))
                           {
                           swap=*(pointer+j);
                           *(pointer+j)=*(pointer+i);
                           *(pointer+i)=swap;
                          
                           }
                    
                     }
              }
            cout<<"Data yang Telah Diurutkan : "<<endl;
              for(i=1;i<=jumlah;i++)
              {
              cout<<*(pointer+i)<<"  ";
              }
}

void _insertionSort(){ // sorting dengan insertionSort
    int number;
    cout<<endl;
    cout<<"=== Insertion Sort ==="<<endl;
    cout<<"Data belum urut"<<endl;
        for(int j=1; j<=jumlah; j++){
            cout<<biodata[j].nilai<<" ";
            cout<<endl;
        }
    for (int i=1; i<=jumlah; i++){
        number = biodata[i].nilai;
        int j = i-1;
        while(biodata[j].nilai>number && j>=0){
            biodata[j+1].nilai = biodata[j].nilai;
            j--;
        }
        biodata[j+1].nilai = number;
    }
    cout<<"Data yang Telah Diurutkan : "<<endl;
    for (int x=1 ;x<=jumlah; x++)
    cout<<biodata[x].nilai<<" ";
}

void _selectionSort(){ // sorting dengan selectionSort
    int number;
    cout<<endl;
    cout<<"=== Selection Sort ==="<<endl;
        cout<<"Data belum urut"<<endl;
        for(int j=1; j<=jumlah; j++){
            cout<<biodata[j].nilai<<" ";
            cout<<endl;
        }
    for(int i=1; i<=jumlah; i++){
        for(int j=i+1; j<=jumlah; j++ ){
            if(biodata[i].nilai >= biodata[j].nilai){
                number = biodata[i].nilai;
                biodata[i].nilai = biodata[j].nilai;
                biodata[j].nilai = number;
            }
        }
    }
    cout<<"Data yang Telah Diurutkan : "<<endl;
    for(int x=1; x<=jumlah; x++){
        cout<<biodata[x].nilai<<" ";
    }
}

int _shell_sort(int array[]){ // fungsi shellSort
        int i=0, j=0, k=0, mid=0;
    for( k=jumlah/2; k>0; k/=2){
        for ( j=k; j<jumlah; j++){
            for ( i=j-k; i>=0; i-=k){
                if(array[i + k] >= array[i])
                break;
                else{
                    mid = array[i];
                    array[i] = array[i+k];
                    array[i + k] = mid;
                }
            }
        }
    }
    return 0;
}

void _sequentialSearch(){     //cari dengan metode sequential search
      int cariNilai, i, flag = 0;
        cout << "=== Sequential Search ==="<<endl;
        for(int n=1; n<=jumlah; n++)
        cout<<biodata[n].nilai<<"\n";
        cout<<endl;
      cout<<"Nilai yang dicari : ";
      cin>>cariNilai;
      for(i = 1; i<=jumlah; i++)
      {
        if(biodata[i].nilai==cariNilai){
            flag = 1;
            break;
        }
      }
      if(flag==1){
            cout<<endl;
            cout<<"Nama\t\t : "<<biodata[i].nama<<endl;
            cout<<"NIM\t\t : "<<biodata[i].nim<<endl;
            cout<<"Nilai\t\t : "<<cariNilai<<"*"<<endl;
            cout<<"Berat Badan\t : "<<biodata[i].beratBadan<<endl;
            cout<<"Alamat\t\t : "<<biodata[i].alamat<<endl;
      }else{
        cout<<"Tidak ada Mahasiswa yang mendapat nilai "<<cariNilai<<endl;
      }
}
void _binarySearch(){ // searching data menggunakan binary search
            int a; 
            cout << "=== Binary Search ==="<<endl;
        for(a=1; a<=jumlah; a++){
            cout<<biodata[a].nilai<<" ";
            cout<<endl;
        }
            int i, cariNilai,j;
            bool found;

            cout<<"Nilai yang dicari : ";
            cin>>cariNilai;
            
            found = false;
            i =0;
            j=a;
            while((!found)& (i<=j)){
                a = (i+j)/2;
                if(cariNilai == biodata[a].nilai)
                found = true;
                else{
                    if(cariNilai <= biodata[a].nilai)
                    j= a- 1;
                    else
                    i=a+1;

                }

            }
            if(found){
            cout<<endl;
            cout<<"Nama\t\t : "<<biodata[a].nama<<endl;
            cout<<"NIM\t\t : "<<biodata[a].nim<<endl;
            cout<<"Nilai\t\t : "<<cariNilai<<"*"<<endl;
            cout<<"Berat Badan\t : "<<biodata[a].beratBadan<<endl;
            cout<<"Alamat\t\t : "<<biodata[a].alamat<<endl;
            }else{
            cout<<"Tidak ada Mahasiswa yang mendapat nilai "<<cariNilai<<endl;
            }
}

void _buatFile(){ // membuat File sesai dengan isi di input data

    ofstream _fileku;
    cout<<"Masukkan Nama File : ";
    cin>>_namaFile;
    _fileku.open(_namaFile, ios::app);
    for(int i = 1; i<=jumlah; i++){
    _fileku<<biodata[i].nama<<endl;
    _fileku<<biodata[i].nim<<endl;
     _fileku<<biodata[i].nilai<<endl;
     _fileku<<biodata[i].beratBadan<<endl;
     _fileku<<biodata[i].alamat<<endl;
     }

     if(!_fileku.is_open()){
         cout<<"File Tidak Bisa Dibuka";
         exit(1);
     }
    
    _fileku.close();
}

void _bacaFile(){ // baca file yang diinput sebelumnya
   ifstream _filesaya;
    int jumlah;
    cout<<"Masukkan nama File : ";
    cin>>_namaFile;
    cout<<"Masukkan Jumlah Data : ";
    cin>>jumlah;
    
    cout<<endl;
     _filesaya.open(_namaFile.c_str());

     if(!_filesaya.is_open()){
         cout<<"Tidak Bisa Membuka File";
         exit(1);
     }

    while(!_filesaya.eof()){
        for(int i = 1; i<=jumlah; i++){
        _filesaya>>biodata[i].nama;
        _filesaya>>biodata[i].nim;
        _filesaya>>biodata[i].nilai;
        _filesaya>>biodata[i].beratBadan;
        _filesaya>>biodata[i].alamat;
        //cout<<endl;
        }
        _filesaya.close();

    }
    for(int i = 1; i<=jumlah; i++){ // menampilkan isi file sesuai dengan index
    cout<<"Nama\t\t : "<<biodata[i].nama<<endl;
    cout<<"NIM\t\t : "<<biodata[i].nim<<endl;
    cout<<"Nilai\t\t : "<<biodata[i].nilai<<endl;
    cout<<"Berat Badan\t : "<<biodata[i].beratBadan<<endl;
    cout<<"Alamat\t\t : "<<biodata[i].alamat<<endl;
    cout<<endl;
    }
    
}



