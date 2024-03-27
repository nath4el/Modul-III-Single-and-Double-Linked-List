#include <iostream>
#include <iomanip>
using namespace std;

// Deklarasi Struct Node
struct Node {
    string Nama297;
    int Umur297;
    Node* next;
};

Node* head;
Node* tail;

// Inisialisasi Node
void inisialisasi297() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah linked list kosong
bool cek297() {
    return head == NULL;
}

// Tambah Node di depan
void depan297(string name, int age) {
    Node* baru = new Node;
    baru->Nama297 = name;
    baru->Umur297 = age;
    baru->next = NULL;

    if (cek297()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Node di belakang
void belakang297(string name, int age) {
    Node* baru = new Node;
    baru->Nama297 = name;
    baru->Umur297 = age;
    baru->next = NULL;

    if (cek297()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int jumlahlist297() {
    int jumlah = 0;
    Node* hitung = head;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

// Tambah Node di tengah
void tengah297(string name, int age, int posisi) {
    if (posisi < 1 || posisi > jumlahlist297()) {
        cout << "Tidak terjangkau!" << endl;
    } else if (posisi == 1) {
        cout << "Bukan di tengah." << endl;
    } else {
        Node* baru = new Node();
        baru->Nama297 = name;
        baru->Umur297 = age;

        Node* bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di depan
void hapus297() {
    if (!cek297()) {
        Node* hapus = head;

        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }

        delete hapus;
    } else {
        cout << "Kosong!" << endl;
    }
}

// Hapus Node di belakang
void hapusbelakang297() {
    if (!cek297()) {
        Node* hapus = tail;

        if (head != tail) {
            Node* bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }

        delete hapus;
    } else {
        cout << "Kosong!" << endl;
    }
}

// Hapus Node di tengah
void hapustengah297(int posisi) {
    if (posisi < 1 || posisi > jumlahlist297()) {
        cout << "Tidak terjangkau!" << endl;
    } else if (posisi == 1) {
        cout << "Bukan yang tengah." << endl;
    } else {
        Node* hapus;
        Node* bantu = head;
        Node* bantu2 = nullptr;
        int nomor = 1;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

// Ubah data di depan
void ubahdepan297(string name, int age) {
    if (!cek297()) {
        head->Nama297 = name;
        head->Umur297 = age;
    } else {
        cout << "Tidak ada yang berubah!" << endl;
    }
}

// Ubah data di tengah
void ubahtengah297(string name, int age, int posisi) {
    if (!cek297()) {
        if (posisi < 1 || posisi > jumlahlist297()) {
            cout << "Tidak Terjangkau!" << endl;
        } else if (posisi == 1) {
            cout << "Bukan yang Tengah." << endl;
        } else {
            Node* bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->Nama297 = name;
            bantu->Umur297 = age;
        }
    } else {
        cout << "Kosong!" << endl;
    }
}

// Ubah data di belakang
void ubahbelakang297(string name, int age) {
    if (!cek297()) {
        tail->Nama297 = name;
        tail->Umur297 = age;
    } else {
        cout << "Kosong" << endl;
    }
}

// Hapus semua Node
void hapuslist297() {
    Node* bantu = head;
    Node* hapus;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "Menghapus semua!" << endl;
}

// Tampilkan semua Node
void tampillist297() {
    Node* bantu = head;

    cout << left << setw(15) << "-Nama-" << right << setw(4) << "-Usia-" << endl;

    if (!cek297()) {
        while (bantu != NULL) {
            cout << left << setw(15) << bantu->Nama297 << right << setw(4) << bantu->Umur297 << endl;
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "Kosong!" << endl;
    }
}

int main() {
    inisialisasi297(); // Inisialisasi Linked List

    cout << "\n(A.)-=-=-= SELAMAT DATANG =-=-=-" << endl; // Menampilkan nama dan umur awal & menjawab poin a

    depan297("Karin", 18);
    depan297("Hoshino", 18);
    depan297("Akechi", 20);
    depan297("Yusuke", 19);
    depan297("Michael", 18);
    depan297("Jane", 20);
    depan297("John", 19);
    depan297("Nadhif", 19); // Mengubah "Albar" menjadi "Nadhif"

    tampillist297();

    // Menjawab poin b
    cout << "-=-=-= (B) Hapus data 'Akechi' =-=-=-" << endl;
    hapustengah297(6);
    tampillist297();

    // Menjawab poin c
    cout << "-=-=-= (C) Tambah data 'Futaba (18)' diantara John & Jane =-=-=-" << endl;
    tengah297("Futaba", 18, 3);
    tampillist297();

    // Menjawab poin d
    cout << "-=-=-= (D) Tambah data 'Igor (20)' di awal =-=-=-" << endl;
    depan297("Igor", 20);
    tampillist297();

    // Menjawab poin e & f
    cout << "-=-=-= (E) Ubah data 'Michael' menjadi 'Reyn (18)' =-=-=-" << endl;
    cout << "-=-=-= (F) Tampilan Akhir =-=-=-" << endl;
    ubahtengah297("Reyn", 18, 6);
    tampillist297();

    return 0;
}

