#include "header.h"

int isEmpty(head& L) {
    return L == NULL;
}

void insertDepan(head& L, int databaru) {
    head baru;
    baru = (head)malloc(sizeof(TNode));
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (L == NULL)
        L = baru;
    else {
        baru->next = L;
        L->prev = baru;
        L = baru;
    }
}

void insertBelakang(head& L, int databaru) {
    head baru, bantu;
    baru = (head)malloc(sizeof(TNode));
    baru->data = databaru;
    baru->next = NULL;
    baru->prev = NULL;
    if (L == NULL)
        L = baru;
    else {
        bantu = L;
        while (bantu->next != NULL) bantu = bantu->next;
        bantu->next = baru;
        baru->prev = bantu;
    }
}

void hapusDepan(head& L) {
    head hapus;
    if (L != NULL) {
        hapus = L;
        if (L->next != NULL) {
            L = L->next;
            L->prev = NULL;
            free(hapus);
        } else {
            L = NULL;
            free(hapus);
        }
        cout << "Data Terhapus" << endl;
    } else {
        cout << "Data Masih Kosong" << endl;
    }
}

void hapusBelakang(head& L) {
    head bantu, hapus;
    if (L == NULL) {
        cout << "Linked list kosong ..........." << endl;
    } else {
        bantu = L;
        if (bantu->next == NULL) {
            free(bantu);
            L = NULL;
        } else {
            while (bantu->next != NULL) bantu = bantu->next;
            hapus = bantu;
            bantu = hapus->prev;
            bantu->next = NULL;
            free(hapus);
        }
        cout << "Data Terhapus" << endl;
    }
}

void clear(head& L) {
    head hapus, bantu;
    bantu = L;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        free(hapus);
    }
    L = NULL;
    cout << "Semua data berhasil dihapus" << endl;
}

void tampil(head& L) {
    head bantu;
    bantu = L;
    if (isEmpty(L)) {
        cout << "Data masih kosong" << endl;
    } else {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    }
}

void tampilBelakang(head& L) {
    if (isEmpty(L)) {
        cout << "Data masih kosong" << endl;
    } else {
        head bantu = L;
        while (bantu->next != NULL) {
            bantu = bantu->next;
        }
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->prev;
        }
        cout << endl;
    }
}

int hitungNode(head& L) {
    int count = 0;
    head bantu = L;
    while (bantu != NULL) {
        count++;
        bantu = bantu->next;
    }
    return count;
}

void printHeader(const string& title) {
    system("cls");
    cout << "=========================================\n";
    cout << "      " << title << "       \n";
    cout << "=========================================\n";
}

