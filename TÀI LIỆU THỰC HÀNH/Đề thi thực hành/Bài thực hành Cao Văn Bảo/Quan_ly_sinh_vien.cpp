#include<bits/stdc++.h>

using namespace std;

struct MonHoc{
    string MaMH;
    int soTinChi;
    float diemQT;
    float diemCK;
    float trongSoCK;
    float DiemMH;
    string ketQuaMH;
};

struct SinhVien{
    string MSSV;
    string HoTenSV;
    string gioiTinh;
    int soMonHoc;
    vector<MonHoc> DSMonHoc;
    float diemCPA;
    string xepLoai;
};


void infor(){
    cout << "Chuong trinh quan ly diem sinh vien" << endl;
    cout << "1. Nhap cac sinh vien" << endl;
    cout << "2. In thong tin SV, Ket qua hoc tap " << endl;
    cout << "0. Exit" << endl;
    cout << "*********************" << endl;
    cout << "Press to your selection" << endl;
}
 
vector<SinhVien> DSSinhVien;
int n;
void inputData(){
    cout << "Ban da chon nhap ds sinh vien" << endl;
    for (int i = 0; i < n; i++){
        SinhVien tempSV;
        string s;
        getline(cin, s);
        cout << "Nhap thong tin sinh vien thu: "<< i+1 << endl;
        cout << "Nhap ma so sinh vien: "; getline(cin, tempSV.MSSV) ;
        cout << endl << "Nhap ten sinh vien: "; getline(cin, tempSV.HoTenSV);
        cout << endl << "Nhap gioi tinh: "; getline(cin, tempSV.gioiTinh);
        cout << endl << "Nhap so mon hoc: "; cin >> tempSV.soMonHoc;
        for (int k = 0; k < tempSV.soMonHoc; k++){
            MonHoc tempMH;
            getline(cin, s);
            cout << "Nhap mon hoc thu " << k + 1 << endl;
            cout << "Nhap Ma MH: "; getline(cin, tempMH.MaMH);
            cout << endl << "Nhap so tin chi: "; cin >> tempMH.soTinChi;
            do {
                cout << endl << "Nhap trong so CK: "; cin >> tempMH.trongSoCK;
            }
            while (tempMH.trongSoCK < 0 || tempMH.trongSoCK > 1);
            cout << endl << "Nhap diem QT: "; cin >> tempMH.diemQT;
            cout << endl << "Nhap diem CK: "; cin >> tempMH.diemCK;
            tempMH.DiemMH = tempMH.diemCK * tempMH.trongSoCK + tempMH.diemQT * (1 - tempMH.trongSoCK);
            if (tempMH.DiemMH > 5){
                tempMH.ketQuaMH = "Pass";
            }
            else tempMH.ketQuaMH = " Fail";
            tempSV.DSMonHoc.push_back(tempMH);
        }
        DSSinhVien.push_back(tempSV);
    }
}

void printData(){
    cout << "Ban da chon xuat DS Sinh Vien!!" << endl;
    for (int i = 0; i < DSSinhVien.size(); i++) {
        cout << "MSSV" << DSSinhVien[i].MSSV;
        cout << "\t Ten sinh vien: " << DSSinhVien[i].HoTenSV << endl;
        cout << "So mon hoc: " << DSSinhVien[i].soMonHoc << endl;
        cout << "Ket qua hoc tap cac mon: " << endl;
        DSSinhVien[i].diemCPA = 0.0;
        int TongSoTC = 0;
        vector<MonHoc> dsMH = DSSinhVien[i].DSMonHoc;
        cout << "MaMonHoc\t SoTinChi\t TrongSo\t DiemQT\t\t DiemCK\t\t DiemMH\t KetquaMonHoc" << endl;
        for (int j = 0; j < dsMH.size(); j++) {
            cout << dsMH[j].MaMH << "\t\t" << dsMH[j].soTinChi << "\t\t" << dsMH[j].trongSoCK << "\t\t";
            cout << dsMH[j].diemQT << "\t\t" << dsMH[j].diemCK << "\t\t" << dsMH[j].DiemMH << "\t\t" << dsMH[j].ketQuaMH << endl;
            TongSoTC += dsMH[j].soTinChi;
            DSSinhVien[i].diemCPA += dsMH[j].DiemMH * dsMH[j].soTinChi;
        }
        DSSinhVien[i].diemCPA = DSSinhVien[i].diemCPA / TongSoTC;
        cout << "Diem CPA: " << DSSinhVien[i].diemCPA << endl;
        float DiemCPA = DSSinhVien[i].diemCPA;
        if (DiemCPA >= 9){
            DSSinhVien[i].xepLoai = "A+";
        }
        if (DiemCPA >= 8.5 && DiemCPA < 9){
            DSSinhVien[i].xepLoai = "A";
        }
        if (DiemCPA >= 7.5 && DiemCPA < 8.5){
            DSSinhVien[i].xepLoai = "B+";
        }
        if (DiemCPA >= 6.5 && DiemCPA < 7.5){
            DSSinhVien[i].xepLoai = "B";
        }if (DiemCPA >= 5 && DiemCPA < 6.5){
            DSSinhVien[i].xepLoai = "C";
        }
        if (DiemCPA >= 4 && DiemCPA < 5){
            DSSinhVien[i].xepLoai = "D";
        }if (DiemCPA < 4){
            DSSinhVien[i].xepLoai = "F";
        }
        cout << "Xep loai: " << DSSinhVien[i].xepLoai << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    int c;
    cout << "Kip 2 - Thu 6 - Tuan 41 - 738920" << endl;
    cout << "2023.2 Le Thi Hoa - 9959" << endl;
    cout << "Nhap so luong sinh vien:  ";
    cin >> n;
    cout << "Kip 2 - Thu 6 - Tuan 41 - 738920" << endl;
    cout << "2023.2 Le Thi Hoa - 9959" << endl;
    while (1)
    {
        infor();
        cin >> c;
        switch (c){
            case 1: inputData();
                break;
            case 2: printData();
                break;
            case 0: cout << "Ban da lua chon thoat!!";
				return 0;
            default: 
                break;
        }
    cout << "Ban da thuc hien xong" << endl;
    cout << endl;
    }
    return 0;
}

