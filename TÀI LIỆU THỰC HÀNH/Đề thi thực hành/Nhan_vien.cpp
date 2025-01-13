#include <bits/stdc++.h>
using namespace std;

typedef struct NhanVien {
    char ma_nv[30];
    char hoten[30];
    int nam_sinh;
    double hs_luong;
    double luong;
    char chuc_danh[30];
    int PCCV;
    double tong_luong;
    double cong_doan_phi;
} NV;

typedef struct PhongBan {
    char ten[30];
    char dia_chi[30];
    int so_luong_nv;
    double luong_toi_thieu;
    NV *dsNV;
    double tong_luong = 0;
    double tong_cdp = 0;
} PB;

void tinh_PCCV(NV &nv) {
    if(!strcmp(nv.chuc_danh, "GVCC")) nv.PCCV = 2000;
    else if(!strcmp(nv.chuc_danh, "GVC")) nv.PCCV = 1500;
    else if(!strcmp(nv.chuc_danh, "GV")) nv.PCCV = 1000;
    else if(!strcmp(nv.chuc_danh, "CBKT")) nv.PCCV = 750;
    else if(!strcmp(nv.chuc_danh, "CBHC")) nv.PCCV = 500;
}

void tinh_tong_luong(NV &nv, double luong_tt) {
    nv.luong = nv.hs_luong * luong_tt;
    nv.tong_luong = nv.luong + nv.PCCV;
    nv.cong_doan_phi = 0.01 * nv.tong_luong;
}

void nhap_xau(char xau[]) {
    fflush(stdin);
    char a;
    int length = 0;
    while(length <= 30) {
        a = getchar();
        xau[length] = a;
        if(a == '\n') break;
        length++;
    }
    xau[length] = 0;
    fflush(stdin);
    //printf("Nhap thanh cong\n");
}

int main() {
    cout << "Nguyen Trung Hai - 20204545" << endl;
    cout << "Nhap so phong ban: ";
    int so_phong_ban;
    cin >> so_phong_ban;

    PB *dsPB = (PB*) malloc(sizeof(PB) * so_phong_ban);


    while(1) {
        cout << endl;
        fflush(stdin);
        cout << "** \t CHUONG TRINH QUAN LY Phong Ban - Nhan Vien \t **" << endl;
        cout << "**1. Nhap cac Phong ban \t **" << endl;
        cout << "**2. In ket qua ds phong ban va Nhan vien \t **" << endl;
        cout << "**0. Thoat \t **" << endl;
        cout << "****************************************" << endl;
        cout << "** \t Nhap lua chon cua ban \t **" << endl;
        char mode;
        mode = getchar();
        if(mode == '0') break;
        switch(mode) {

            case '1': 
            cout << "Ban da chon nhap ds phong ban nhan vien" << endl;
            for(int i = 0; i < so_phong_ban; i++) {

                //Nhap thong tin phong ban
                cout << "Nhap thong tin phong ban thu " << i+1 << ":" << endl;

                cout << "Ten Phong Ban: ";
                nhap_xau(dsPB[i].ten);
                cout << "Dia chi: ";
                nhap_xau(dsPB[i].dia_chi);

                cout << "Luong toi thieu: ";
                cin >> dsPB[i].luong_toi_thieu;
                cout << "So nhan vien: ";
                cin >> dsPB[i].so_luong_nv;
                dsPB[i].dsNV = (NV*) malloc(sizeof(NV) * dsPB[i].so_luong_nv);

                //Nhap thong tin nhan vien trong phong ban
                cout << "Nhap ds Nhan vien:" << endl;
                for(int j = 0; j < dsPB[i].so_luong_nv; j++) {
                    cout << "Nhap thong tin nhan vien thu " << j+1 << ":" << endl;

                    cout << "MaNV: ";
                    nhap_xau(dsPB[i].dsNV[j].ma_nv);

                    cout << "Ho ten Nhan vien: ";
                    nhap_xau(dsPB[i].dsNV[j].hoten);
                    cout << "thanh cong" << endl;

                    cout << "Nhap Nam sinh: ";
                    cin >> dsPB[i].dsNV[j].nam_sinh;

                    cout << "Nhap HS Luong: ";
                    cin >> dsPB[i].dsNV[j].hs_luong;

                    cout << "Nhap chuc danh: ";
                    nhap_xau(dsPB[i].dsNV[j].chuc_danh);

                    tinh_PCCV(dsPB[i].dsNV[j]);
                    tinh_tong_luong(dsPB[i].dsNV[j], dsPB[i].luong_toi_thieu);
                    cout << endl;

                    dsPB[i].tong_luong += dsPB[i].dsNV[j].tong_luong;
                    dsPB[i].tong_cdp += dsPB[i].dsNV[j].cong_doan_phi;
                    cout << endl;
                }

                cout << endl;
            }
            break;

            case '2':
            cout << "Ban da chon xuat DS Phong ban" << endl;
            for(int i = 0; i < so_phong_ban; i++) {

                //Xuat thong tin phong ban
                cout << "Ten phong ban: " << dsPB[i].ten << endl;
                cout << "Dia chi: " << dsPB[i].dia_chi << endl;
                cout << "Luong TT: " << dsPB[i].luong_toi_thieu << endl;
                cout << "Tong Luong PB: " << dsPB[i].tong_luong << endl;
                cout << "Tong CD Phi: " << dsPB[i].tong_cdp << endl;
                cout << "Bang Luong Nhan vien: " << endl;


                cout << "MaNV \t HotenNV \t Chucdanh \t PCCV \t HesoL \t Luong \t\t CDp \t\t Con nhan" << endl;
                for(int j = 0; j < dsPB[i].so_luong_nv; j++) {
                    NV nv = dsPB[i].dsNV[j];
                    printf("%s \t %s \t %s \t\t %d \t %.2lf \t %.2lf \t %.2lf \t\t %.2lf \n",
                         nv.ma_nv, nv.hoten, nv.chuc_danh, nv.PCCV, nv.hs_luong, nv.tong_luong, nv.cong_doan_phi, nv.tong_luong - nv.cong_doan_phi);
                }
            }
            break;
        }
    }


}