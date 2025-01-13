/* HO VA TEN: TRUONG VAN HIEN
MSSV: 20194276
Lop thuc hanh: 710817 */

#include<bits/stdc++.h>

using namespace std;

typedef struct Dangvien
{
    int id;
    char name[100];
    int day;
    int month;
    int year;
    int salary;
    char chucvu[100];
    int trocap;
} Dang;

typedef struct Chibo
{
    char name[100];
    int quant;
    Dang member[100];
    int sumsalary;
    float sumDangphi;
    float sumtrocap;
}chibo;
int n, sumsalary = 0;
float sumDangphi = 0;
chibo cb[11];

void init(){
    printf("\n De4_8_IT3040_20211\n");
    printf("**   CHUONG TRINH QUAN LY Chi bo - Dang vien **\n");
    printf("**1. Nhap cac Chi bo                         **\n");
    printf("**2. In ket qua ds Chi bo Dang vien          **\n");
    printf("**3. Thoat                                   **\n");
    printf("***********************************************\n");
    printf("**       Nhap lua chon cua ban               **\n");
}
void insertlist(){
    printf("\nBan da chon nhap ds Chi bo Dang vien!\n");

    for (int i = 0; i < n; ++i){
        printf("Nhap thong tin Chi bo thu %d:\n", i+1);
        printf("\tTen Chi bo: ");
        scanf("%s", cb[i].name);
        printf("\n\tSo dang vien:");
        scanf("%d", &cb[i].quant);
        cb[i].sumsalary = 0;
        cb[i].sumDangphi = 0;
        printf("\n\tNhap ds Dang vien:\n");
        for (int j = 0; j < cb[i].quant; ++j){
            printf("\tDang vien thu %d", j+1);
            printf("\n\t\tso the:");
            scanf("%d", &cb[i].member[j].id);
            printf("\n\t\tTen Dang vien:");
            scanf("%s", cb[i].member[i].name);
            cin.clear();
            cin.ignore(10000,'\n');
            printf("\n\t\tNgay vao Dang:\n");
            printf("\t\tNgay: ");
            scanf("%d", &cb[i].member[i].day);
            printf("\t\tThang:");
            scanf("%d", &cb[i].member[i].month);
            printf("\t\tNam:");
            scanf("%d", &cb[i].member[i].year);
            printf("\n\t\tLuong:");
            scanf("%d", &cb[i].member[i].salary);
            cb[i].sumsalary += cb[i].member[i].salary;
            cb[i].sumDangphi += (float)cb[i].member[i].salary/100;
            printf("\n\t\tChuc vu:");
            scanf("%s", cb[i].member[i].chucvu);
            cin.clear();
            cin.ignore(10000,'\n');

        }
    }

}
void printlist(){
    printf("ban da chon xuat DS Chi bo, !");
    for(int i = 0; i < n; ++i){
        printf("____________________________________________________________\n\n");
        printf("\n\t\tTen chi bo: %s", cb[i].name);
        printf("\n\t\tSo Dang vien: %d", cb[i].quant);
        printf("\n\t\tTong luong: %d", cb[i].sumsalary);
        printf("\n\t\tTong thu Dang phi: %.2f", cb[i].sumDangphi);
        printf("\n\t\tTong nop DP Cap tren: %.2f", cb[i].sumDangphi*0.3);
        printf("\n\t\tTong tro Cap chuc vu: %.2f", cb[i].sumtrocap);
        printf("\n\t\tBang thu Dang Phi:");
        printf("\n\tSo the\tHotenDV\tNgayvaodang\tTuoi Dang\tChucvu\tTrocap\tLuong\tDangphi");
        for (int j = 0; j < cb[i].quant; ++j){
            printf("%d\t%s\t%d-%d-%d\t\t%d\t%s\t%d\t%d\t.2f\n", cb[i].member[j].id, cb[i].member[j].name, cb[i].member[j].day, cb[i].member[j].month, cb[i].member[j].year, 2022-cb[i].member[j].year, cb[i].member[j].chucvu, cb[i].member[j].trocap, cb[i].member[j].salary, (float)cb[i].member[j].salary/100.0);
        }
        sumsalary+= cb[i].sumsalary;
        sumDangphi+= cb[i].sumDangphi;
    }


    printf("Tong Luong cac chi bo: %d", sumsalary);
    printf("Tong Dang Phi thu duoc: %d", sumDangphi);
    printf("Tong nop cap tren: %d", sumDangphi*0.3);

}
int main(){
    int choice;
    printf("Truong Van Hien - 20194276 - 710817\n");
    printf("Nhap so Chi Bo: ");
    scanf("%d", &n);
    init();
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertlist();
        break;
    case 2:
        printlist();
        break;
    case 3:
        return 0;
    default:
        init();
        break;
    }
}
