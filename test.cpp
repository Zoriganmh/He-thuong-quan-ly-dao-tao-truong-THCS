#include <bits/stdc++.h>
#include <sstream>
using namespace std;

Student s;
	cout << "Nhap thong tin hoc sinh:\n";
	cout << "Nhap khoi lop: "; cin >> s.khoilop;
	string name;
	cout << "Nhap ten sinh vien: "; cin.ignore();
	getline(cin, name);
	chuanhoa(name); s.name = name;
	cout << "Nhap STT hoc sinh: "; cin >> s.stt;
	cout << "Hanh kiem hoc sinh: \n"; 
	cout << "(Tot, Kha, Trung binh, Yeu)\n";
	string hanhkiem;
	cin.ignore(); getline(cin, hanhkiem);
	chuanhoa(hanhkiem); s.HanhKiem = hanhkiem;
	cout << "Nhap diem cac mon hoc:\n";
	
	cout << "Mon toan:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.ToanTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.ToanTX2;
	cout << "Diem giua ki: "; cin >> s.ToanGK;
	cout << "Diem cuoi ki: "; cin >> s.ToanCK;
	s.ToanTB = s.ToanTX1*0.1 + s.ToanTX2*0.1 + s.ToanGK*0.3 + s.ToanCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Ngu Van:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.VanTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.VanTX2;
	cout << "Diem giua ki: "; cin >> s.VanGK;
	cout << "Diem cuoi ki: "; cin >> s.VanCK;
	s.VanTB = s.VanTX1*0.1 + s.VanTX2*0.1 + s.VanGK*0.3 + s.VanCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Ngoai Ngu:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.NNTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.NNTX2;
	cout << "Diem giua ki: "; cin >> s.NNGK;
	cout << "Diem cuoi ki: "; cin >> s.NNCK;
	s.NNTB = s.NNTX1*0.1 + s.NNTX2*0.1 + s.NNGK*0.3 + s.NNCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Giao Duc Cong Dan:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.GDCDTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.GDCDTX2;
	cout << "Diem giua ki: "; cin >> s.GDCDGK;
	cout << "Diem cuoi ki: "; cin >> s.GDCDCK;
	s.GDCDTB = s.GDCDTX1*0.1 + s.GDCDTX2*0.1 + s.GDCDGK*0.3 + s.GDCDCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Lich Su:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.SuTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.SuTX2;
	cout << "Diem giua ki: "; cin >> s.SuGK;
	cout << "Diem cuoi ki: "; cin >> s.SuCK;
	s.SuTB = s.SuTX1*0.1 + s.SuTX2*0.1 + s.SuGK*0.3 + s.SuCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Dia ly:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.DiaTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.DiaTX2;
	cout << "Diem giua ki: "; cin >> s.DiaGK;
	cout << "Diem cuoi ki: "; cin >> s.DiaCK;
	s.DiaTB = s.DiaTX1*0.1 + s.DiaTX2*0.1 + s.DiaGK*0.3 + s.DiaCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Vat Li: \n";
	cout << "Diem thuong xuyen 1: "; cin >> s.LiTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.LiTX2;
	cout << "Diem giua ki: "; cin >> s.LiGK;
	cout << "Diem cuoi ki: "; cin >> s.LiCK;
	s.LiTB = s.LiTX1*0.1 + s.LiTX2*0.1 + s.LiGK*0.3 + s.LiCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Hoa Hoc:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.HoaTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.HoaTX2;
	cout << "Diem giua ki: "; cin >> s.HoaGK;
	cout << "Diem cuoi ki: "; cin >> s.HoaCK;
	s.HoaTB = s.HoaTX1*0.1 + s.HoaTX2*0.1 + s.HoaGK*0.3 + s.HoaCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Sinh Hoc:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.SinhTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.SinhTX2;
	cout << "Diem giua ki: "; cin >> s.SinhGK;
	cout << "Diem cuoi ki: "; cin >> s.SinhCK;
	s.SinhTB = s.SinhTX1*0.1 + s.SinhTX2*0.1 + s.SinhGK*0.3 + s.SinhCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Cong Nghe:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.CNTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.CNTX2;
	cout << "Diem giua ki: "; cin >> s.CNGK;
	cout << "Diem cuoi ki: "; cin >> s.CNCK;
	s.CNTB = s.CNTX1*0.1 + s.CNTX2*0.1 + s.CNGK*0.3 + s.CNCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon Tin Hoc:\n";
	cout << "Diem thuong xuyen 1: "; cin >> s.TinTX1; 
	cout << "Diem thuong xuyen 2: "; cin >> s.TinTX2;
	cout << "Diem giua ki: "; cin >> s.TinGK;
	cout << "Diem cuoi ki: "; cin >> s.TinCK;
	s.TinTB = s.TinTX1*0.1 + s.TinTX2*0.1 + s.TinGK*0.3 + s.TinCK*0.5;
	
	cout << "\n-----------------------\n";
	cout << "Mon The Duc:\n";
	cout << "Neu hoc sinh Dat -> Nhap: Dat\n";
	cout << "Neu hoc sinh khong Dat -> Nhap: Khong Dat\n";
	string theduc;
	cin.ignore(); getline(cin, theduc);
	chuanhoa(theduc); s.Theduc = theduc;
	
	cout << "\n-----------------------\n";
	cout << "Mon Nghe Thuat:\n";
	cout << "Neu hoc sinh Dat -> Nhap: Dat\n ";
	cout << "Neu hoc sinh khong Dat -> Nhap: Khong Dat\n";
	string nghethuat;
	cin.ignore(); getline(cin, nghethuat);
	chuanhoa(nghethuat); s.Nghethuat = nghethuat;
	
	s.TBmon = (s.ToanTB + s.VanTB + s.NNTB + s.GDCDTB + s.SuTB + s.DiaTB + s.LiTB + s.HoaTB + s.SinhTB + s.CNTB + s.TinTB) / 11;
	
	hs tmp = new HS();
	tmp->s = s;
	tmp->next = NULL;

int main(){
	while(1){
		cout << "Ban la:" << endl;
		cout << "1.Hoc sinh" << endl;
		cout << "2.Giao vien" << endl;
		cout << "3.Phu huynh" << endl;
		cout << "0.Thoat" << endl;
		int lc; cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 0){
			return 0;
		}
		else if(lc == 1){
			int lc1;
			cout << ""
		}
	}
}