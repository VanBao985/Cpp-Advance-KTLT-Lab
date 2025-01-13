#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int a[100][1000];
int m,n,x;
char name[100][100];

void input(){
    int cnt = 1;
    while(cnt<=n){
        cout << "Nhap ten da thuc thu "<<cnt<<" :";
        cin.ignore();
        cin >> name[cnt];
        cout << "Nhap bac: ";
        cin >> m;
        cout << '\n';
        cout << "Nhap x: ";
        cin >> x;
        cout << '\n';
        for(int i=m;i>=0;i--){
            cout << "nhap he so bac " << i << ":";
            cin >> a[cnt][i];
            cout <<'\n';
        }
        cout<<"Ban da nhap thanh cong nhan phim bat ki de tiep tuc"<<'\n';
        char s;
        cin >> s;
        cout<<"___________________________"<<'\n';
        cnt++;
    }
}
void output(){
    int cnt = 1;
    while(cnt<=n){
        cout << "da thuc thu "<< cnt <<":"<<'\n';
        cout<<name[cnt]<<"(x)"<<"=";
        if(m == 0){ 
            cout << a[cnt][m];
            return;
        }
        if(a[cnt][m] != 0){
            if(m > 1) {
                if(a[cnt][m]== 1 ) cout<<"x^"<<m;
                if(a[cnt][m]== -1) cout<<"-x^"<<m;
                if(a[cnt][m]!=1 && a[cnt][m]!=-1) cout<<a[cnt][m]<<"x^"<<m;
            }
            if(m == 1){
                if(a[cnt][m]== 1 ) cout<<"x"<<m;
                if(a[cnt][m]== -1) cout<<"-x"<<m;
                if(a[cnt][m]!=1 && a[cnt][m]!=-1) cout<<a[m]<<"x";
            }
        }
        int i = m-1;
        if(i==0) {
            if(a[cnt][i]>0) cout << "+" <<a[cnt][i];
            if(a[cnt][i]<0) cout << a[cnt][i];
            return;
        }
        while(i>1){
            if(a[cnt][i]>0) {
                if(a[cnt][i]!=1) cout << "+" <<a[cnt][i] <<"x^" <<i;
                if(a[cnt][i]==1) cout << "+" <<"x^" <<i;  
            }
            if(a[cnt][i]<0){
                if(a[cnt][i]!=-1) cout <<a[cnt][i] <<"x^" <<i;
                if(a[cnt][i]==-1) cout <<"-x^" <<i;
            }
            i--;
        }
        if(i==1) {
            if(a[cnt][i]>0) {
                if(a[cnt][i]!=1) cout << "+" <<a[cnt][i]<<"x";
                if(a[cnt][i]==1) cout << "+" <<"x";
            }
            if(a[cnt][i]<0) {
                if(a[cnt][i]!= -1) cout << a[cnt][i]<<"x";
                if(a[cnt][i]== -1) cout <<"-x";
            }
            if(a[cnt][0]>0) cout << "+" <<a[cnt][0];
            if(a[cnt][0]<0) cout << a[cnt][0];
        }  
        cout<<'\n';
        cnt++;
    }  
}

void fx(){
    int cnt =1;
    while(cnt<=n){
        int f=0;
        for(int i=m;i>=0;i--){
            f+=a[cnt][i]*pow(x,i);
        }
        cout<<'\n';
        cout<<"Gia tri da thuc "<<name[cnt]<<"("<<x<<")"<<" la :"<<f<<'\n';
        cnt++;
    }
}

int main(){
   
    while(1){
         cout<<"------------------------------------------------\n";
        cout<<"**Phan Le Hai Dang                            **\n";
        cout<<"**Nhap 0 de thoat                             **\n";
        cout<<"Nhap 1 de nhap                                **\n";
        cout<<"Nhap 2 de in                                  **\n";
        cout<<"------------------------------------------------\n";

        cout<<"Nhap lua chon cua ban: \n";
        int tmp;
        cin >> tmp;
        if(tmp == 1) {
            cout << "nhap so luong da thuc :";
            cin >> n;
            cout <<'\n';
            input();
        }

        if(tmp == 2) {
            output();
            fx(); 
        }
        if(tmp == 0) break; 
    }
}