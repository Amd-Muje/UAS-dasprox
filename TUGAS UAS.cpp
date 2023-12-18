#include <iostream>
#include <string>

using namespace std;


void garis();
int login();
int menuutama();
int menulogin();
float pembayaran(float totalharga);
int menuAdmin();
void menuPembeli();
float kembalian(float totalharga);
void listbarangdibeli(float totalharga);
float prosesakhir(float totalharga);
void tambahStok(int stok[], int index);
void gantiHarga(int hargabarang[], int index);


int stok[] = {2, 5, 7, 6, 8};
int hargabarang[] = {1000, 300, 1500, 100, 400};


int main() {
    menuutama();
    return 0;
}

void garis() {
    cout << "+================================================+\n\n";
}

int login() {
    // Fungsi login belum diimplementasikan
    return 0;
}

int menuutama() {
    char pilihan;

    garis();

    cout << "Selamat datang di Smart Komputer\n";
    cout << "Apakah anda\n 1. Admin\n 2. Pembeli\n\n";
    garis();
    cout << "Jawaban anda : ";
    cin >> pilihan;

    switch (pilihan) {
        case '1':
            menulogin();
            break;

        case '2':
            menuPembeli();
            break;

        default:
            cout << "pilihan tidak valid\n";
            garis();
            menuutama();
    }

    return 0;
}

int menulogin() {
    string id, idyangdimasukan, password, passwordyangdimasukan;

    id = "admin";
    password = "admin123";

    garis();
    cout << "\nselamat datang\n";
    cout << "silahkan login kan akun anda\n";
    cout << "ID: ";
    cin >> idyangdimasukan;
    cout << "password: ";
    cin >> passwordyangdimasukan;

    if (id == idyangdimasukan && password == passwordyangdimasukan) {
        menuAdmin();
    } else {
        cout << "Id atau password salah silahkan login kembali \n";
        menulogin();
    }

    garis();
    return 0;
}

float pembayaran(float totalharga) {
    float pembayaran;
    cout << "Total harga: " << totalharga << endl;
    cout << "Masukkan jumlah pembayaran: ";
    cin >> pembayaran;

    while (pembayaran < totalharga) {
        cout << "Jumlah pembayaran kurang, silakan masukkan lagi: ";
        cin >> pembayaran;
    }

    return pembayaran;
}

int menuAdmin() {
    garis();
    cout << "Menu Admin\n";
    cout << "1. Tambah Stok\n";
    cout << "2. Ganti Harga Barang\n";
    cout << "3. Keluar\n";
    garis();

    int pilihan;
    cout << "Pilih menu: ";
    cin >> pilihan;

    int index;

    switch (pilihan) {
        case 1:
            cout << "Masukkan indeks barang yang ingin ditambah stok: ";
            cin >> index;
            tambahStok(stok, index);
            break;

        case 2:
            cout << "Masukkan indeks barang yang ingin diganti harga: ";
            cin >> index;
            gantiHarga(hargabarang, index);
            break;

        case 3:
            cout << "Keluar dari menu admin\n";
            break;

        default:
            cout << "Pilihan tidak valid\n";
    }

    return 0;
}

void tambahStok(int stok[], int index) {
    int tambahan;
    cout << "Masukkan jumlah stok tambahan: ";
    cin >> tambahan;

    stok[index] += tambahan;

    cout << "Stok berhasil ditambahkan. Stok sekarang: " << stok[index] << endl;
}

void gantiHarga(int hargabarang[], int index) {
    int hargaBaru;
    cout << "Masukkan harga baru: ";
    cin >> hargaBaru;

    hargabarang[index] = hargaBaru;

    cout << "Harga berhasil diganti. Harga sekarang: " << hargabarang[index] << endl;
}


void menuPembeli() {
    float totalharga = 0;

    int pilihan;

    char belilagi;


    cout << "1. laptop " << "[" << stok[0] << "]" << endl;
    cout << "2. handphone " << "[" << stok[1] << "]" << endl;
    cout << "3. komputer " << "[" << stok[2] << "]" << endl;
    cout << "4. lcd " << "[" << stok[3] << "]" << endl;
    cout << "5. printer " << "[" << stok[4] << "]" << endl;

    pilih:
    cout << "pilihan barang ";
    cin >> pilihan;

    if (pilihan >= 1 && pilihan <= 5) {
        if (stok[pilihan - 1] > 0) {
            totalharga += hargabarang[pilihan - 1];
            stok[pilihan - 1]--;
            cout << "masih ingin tambah barang lagi ? (Y/N)";
            cin >> belilagi;
            if (belilagi == 'y' || belilagi == 'Y') {
                goto pilih;
            } else {
                listbarangdibeli(totalharga);
            }
        } else {
            cout << "barang habis\n";
        }
    } else {
        cout << "pilihan tidak valid\n";
    }
}

float kembalian(float totalharga, float pembayaran) {
    return pembayaran - totalharga;
}

void listbarangdibeli(float totalharga) {
    cout << "Ini total barang anda: " << totalharga << endl;
    float bayar = pembayaran(totalharga);
    float kembali = kembalian(totalharga, bayar);
    cout << "Kembalian: " << kembali << endl;
    prosesakhir(totalharga);
}

float prosesakhir(float totalharga) {
    // Implementasi prosesakhir sesuai kebutuhan
    return 0;
}
