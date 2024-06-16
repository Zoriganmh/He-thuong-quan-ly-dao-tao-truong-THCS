#include <bits/stdc++.h>
#include <fstream>

using namespace std;


// chuan hoa ten hoc sinh 
void chuanhoa(string &h){
	stringstream ss(h);
	string res = "", word;
	while(ss >> word){
		res += toupper(word[0]);
		for (int j = 1; j < word.size(); j++){
			res += tolower(word[j]);
		}
		res += " ";
	}
	res.pop_back();
	h = res;
}


struct Student
{
	int khoilop;
	string name;
	long stt;
	string HanhKiem;
	float ToanTX1,ToanTX2,ToanGK,ToanCK,ToanTB;
	float VanTX1,VanTX2,VanGK,VanCK,VanTB;
	float NNTX1,NNTX2,NNGK,NNCK,NNTB;
	float GDCDTX1,GDCDTX2,GDCDGK,GDCDCK,GDCDTB;
	float SuTX1,SuTX2,SuGK,SuCK,SuTB;
	float DiaTX1,DiaTX2,DiaGK,DiaCK,DiaTB;
	float LiTX1,LiTX2,LiGK,LiCK,LiTB;
	float HoaTX1,HoaTX2,HoaGK,HoaCK,HoaTB;
	float SinhTX1,SinhTX2,SinhGK,SinhCK,SinhTB;
	float CNTX1,CNTX2,CNGK,CNCK,CNTB;
	float TinTX1,TinTX2,TinGK,TinCK,TinTB;
	string Theduc,Nghethuat;
	float TBmon;
	int loai;
};

struct HS
{
	Student s;
	HS *next;
};

typedef struct HS *hs;

// khoi tao hoc sinh 
hs makehs()
{
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
}


// dem so hoc sinh gioi, kha, trung binh, yeu
int demhs(Student a, int x){
	int demgioi = 0, demkha = 0, demtb = 0,demyeu = 0,demsieuyeu = 0;
	
	if(a.ToanTB >= 8) ++demgioi;
	if(6.5 <= a.ToanTB < 8) ++demkha;
	if(5 <= a.ToanTB < 6.5) ++demtb;
	if(3.5 <= a.ToanTB < 5) ++demyeu;
	if(a.ToanTB < 3.5) ++demsieuyeu;
	
	if(a.VanTB >= 8) ++demgioi;
	if(6.5 <= a.VanTB < 8) ++demkha;
	if(5 <= a.VanTB < 6.5) ++demtb;
	if(3.5 <= a.VanTB < 5) ++demyeu;
	if(a.VanTB < 3.5) ++demsieuyeu;
	
	if(a.NNTB >= 8) ++demgioi;
	if(6.5 <= a.NNTB < 8) ++demkha;
	if(5 <= a.NNTB < 6.5) ++demtb;
	if(3.5 <= a.NNTB < 5) ++demyeu;
	if(a.NNTB < 3.5) ++demsieuyeu;
	
	if(a.GDCDTB >= 8) ++demgioi;
	if(6.5 <= a.GDCDTB < 8) ++demkha;
	if(5 <= a.GDCDTB < 6.5) ++demtb;
	if(3.5 <= a.GDCDTB < 5) ++demyeu;
	if(a.GDCDTB < 3.5) ++demsieuyeu;
	
	if(a.SuTB >= 8) ++demgioi;
	if(6.5 <= a.SuTB < 8) ++demkha;
	if(5 <= a.SuTB < 6.5) ++demtb;
	if(3.5 <= a.SuTB < 5) ++demyeu;
	if(a.SuTB < 3.5) ++demsieuyeu;
	
	if(a.DiaTB >= 8) ++demgioi;
	if(6.5 <= a.DiaTB < 8) ++demkha;
	if(5 <= a.DiaTB < 6.5) ++demtb;
	if(3.5 <= a.DiaTB < 5) ++demyeu;
	if(a.DiaTB < 3.5) ++demsieuyeu;
	
	if(a.LiTB >= 8) ++demgioi;
	if(6.5 <= a.LiTB < 8) ++demkha;
	if(5 <= a.LiTB < 6.5) ++demtb;
	if(3.5 <= a.LiTB < 5) ++demyeu;
	if(a.LiTB < 3.5) ++demsieuyeu;
	
	if(a.HoaTB >= 8) ++demgioi;
	if(6.5 <= a.HoaTB < 8) ++demkha;
	if(5 <= a.HoaTB < 6.5) ++demtb;
	if(3.5 <= a.HoaTB < 5) ++demyeu;
	if(a.HoaTB < 3.5) ++demsieuyeu;
	
	if(a.SinhTB >= 8) ++demgioi;
	if(6.5 <= a.SinhTB < 8) ++demkha;
	if(5 <= a.SinhTB < 6.5) ++demtb;
	if(3.5 <= a.SinhTB < 5) ++demyeu;
	if(a.SinhTB < 3.5) ++demsieuyeu;
	
	if(a.CNTB >= 8) ++demgioi;
	if(6.5 <= a.CNTB < 8) ++demkha;
	if(5 <= a.CNTB < 6.5) ++demtb;
	if(3.5 <= a.CNTB < 5) ++demyeu;
	if(a.CNTB < 3.5) ++demsieuyeu;
	
	if(a.TinTB >= 8) ++demgioi;
	if(6.5 <= a.TinTB < 8) ++demkha;
	if(5 <= a.TinTB < 6.5) ++demtb;
	if(3.5 <= a.TinTB < 5) ++demyeu;
	if(a.TinTB < 3.5) ++demsieuyeu;
	
	if(x == 1) return demgioi;
	if(x == 2) return demkha;
	if(x == 3) return demtb;
	if(x == 4) return demyeu;
	if(x == 5) return demsieuyeu;
}


// danh gia ket qua hoc tap cua hoc sinh 
void danhgia(Student a){
	int dem1 = demhs(a, 1);
	int dem2 = demhs(a, 2);
	int dem3 = demhs(a, 3);
	int dem4 = demhs(a, 4);
	int dem5 = demhs(a, 5);
	
	// dieu kien hoc sinh gioi
	if(a.TBmon >= 8){
		if(a.HanhKiem == "Tot"){
			if(dem3 >= 1 && dem4 == 0){
				a.loai = 2;
				cout << "Hoc sinh kha";
			}
			else if(dem4 >= 1){
				a.loai = 3;
				cout << "Hoc sinh trung binh";
			}
			else if(dem5 >= 1){
				a.loai = 4;
				cout << "Hoc sinh yeu";
			}
			else{
				if(a.Nghethuat == "Dat" && a.Theduc == "Dat"){
					if(a.ToanTB >= 8 || a.VanTB >= 8 || a.NNTB >= 8){
						a.loai = 1;
						cout << "Hoc sinh gioi";
					}
					else {
						a.loai = 2;
						cout << "Hoc sinh kha";
					}
				} 
				else {
					a.loai = 2;
					cout << "Hoc sinh kha";
				}
			}
		}
		else if(a.HanhKiem == "Yeu"){
			a.loai = 5;
			cout << "Hoc sinh dup";
		}
		else {
			a.loai = 2;
			cout << "Hoc sinh kha";
		}
	}
	
	// dieu kien hoc sinh kha
	else if( 6 <= a.TBmon < 8){
		if(a.HanhKiem == "Yeu"){
			a.loai = 5;
			cout << "Hoc sinh dup";
		}
		else {
			if(dem4 >= 1){
				a.loai = 3;
				cout << "Hoc sinh trung binh";
			}
			else if(dem5 >= 1){
				a.loai == 4;
				cout << "Hoc sinh yeu";
			}
			else{
				if(a.Nghethuat != "Dat" || a.Theduc != "Dat"){
					a.loai = 3;
					cout << "Hoc sinh trung binh";
				}
				else if(a.Nghethuat == "Dat" && a.Theduc == "Dat"){
					if(a.ToanTB >= 6.5 || a.VanTB >= 6.5 || a.NNTB >= 6.5){
						a.loai = 2;
						cout << "Hoc sinh kha";
					}
					else {
						a.loai = 3;
						cout << "Hoc sinh trung binh";
					}
				}
			}
		}
	}
	
	// dieu kien hoc sinh trung binh 
	else if( 5 <= a.TBmon < 6.5){
		if(a.HanhKiem == "Yeu"){
			a.loai = 5;
			cout << "Hoc sinh dup";
		}
		else {
			if(dem5 >= 1){
				a.loai = 4;
				cout << "Hoc sinh yeu";
			}
			else{
				if(a.Nghethuat != "Dat" || a.Theduc != "Dat"){
					a.loai = 4;
					cout << "Hoc sinh yeu";
				}
				else if(a.Nghethuat == "Dat" && a.Theduc == "Dat"){
					if(a.ToanTB >= 5 || a.VanTB >= 5 || a.NNTB >= 5){
						a.loai = 3;
						cout << "Hoc sinh trung binh";
					}
					else {
						a.loai = 4;
						cout << "Hoc sinh yeu";
					}
				}
			}
		}
	}
	
	// dieu kien hoc sinh yeu
	else if(a.TBmon < 3.5){
		if(a.HanhKiem == "Yeu"){
			a.loai = 5;
			cout << "Hoc sinh dup";
		}
		else{
			a.loai = 4;
			cout << "Hoc sinh yeu";
		}
	}
	
}


// kiem tra danh sach rong
bool empty(hs a)
{
	return a == NULL;
}

// bo sung hoc sinh x vao dau danh sach
void insertfirst(hs &a)
{
	hs tmp = makehs();
	if (a == NULL)
	{
		a = tmp;
	}
	else
	{
		tmp->next = a;
		a = tmp;
	}
}

// dem so hoc sinh
int Sizehs(hs a)
{
	int dem = 0;
	while (a != NULL)
	{
		++dem;
		a = a->next;
	}
	return dem;
}

// sap xep hoc sinh theo thu tu tang dan cua stt
void sapxep(hs &h)
{
	hs p = h;
	for (p; p->next = NULL; p = p->next)
	{
		hs min = p;
		for (hs q = p->next; q != NULL; q = q->next)
		{
			if (q->s.stt < min->s.stt)
			{
				min = q;
			}
		}
		int tmp = min->s.stt;
		min->s = p->s;
		p->s.stt = tmp;
	}
}


// sap xep hoc sinh theo thu tu tang dan cua khoi lop
void sapxep2(hs &h){
	hs p = h;
	for (p; p->next = NULL; p = p->next)
	{
		hs min = p;
		for (hs q = p->next; q != NULL; q = q->next)
		{
			if (q->s.khoilop < min->s.khoilop)
			{
				min = q;
			}
		}
		int tmp = min->s.khoilop;
		min->s = p->s;
		p->s.khoilop = tmp;
	}
}


// sap xep hoc sinh theo ten (thu tu bang chu cai)

string tachten(string s, int i){
	string ten = "";
	while(s[s.length() - 1] != ' '){
		ten.insert(ten.begin() + 0, s[s.length() - 1]);
		s.pop_back();
	}
	s.pop_back();
	if(i == 1){
		return s;
	}
	if(i == 2){
		return ten;
	}
}

void sapxep1(hs &h){
	hs p = h;
	for (p; p->next = NULL; p = p->next){
		hs min = p;
		for (hs q = p->next; q != NULL; q = q->next){
			if(tachten(q->s.name, 2) < tachten(min->s.name,2) ){
				min = q;
			}
			if(tachten(q->s.name, 2) == tachten(min->s.name,2)){
				if(tachten(q->s.name, 1) < tachten(min->s.name,1) ){
				min = q;
				}
			}
		}
		string tmp = min->s.name;
		min->s = p->s;
		p->s.name = tmp;
	}
}
 // Sap xep hoc sinh theo TBmon
void sapxep3(hs &h) {
 	hs p = h;
	for (p; p->next = NULL; p = p->next)
	{
		hs max = p;
		for (hs q = p->next; q != NULL; q = q->next)
		{
			if (q->s.TBmon > max->s.TBmon){
				max = q;
			}
			if(q->s.TBmon == max->s.TBmon){
				sapxep1(h);	}
		int tmp = max->s.TBmon;
		max->s = p->s;
		p->s.TBmon = tmp;
	}
}}

//Sap xep theo loai hoc sinh (tu gioi den yeu)
void sapxep4(hs &h){
 	hs p = h;
	for (p; p->next = NULL; p = p->next)
	{
		hs min = p;
		for (hs q = p->next; q != NULL; q = q->next)
		{
			if (q->s.loai < min->s.loai)
			{
				min = q;
			}
			if(q->s.loai == min->s.loai){
				sapxep3(h);}
		}
		int tmp = min->s.loai;
		min->s = p->s;
		p->s.loai = tmp;
	}
}
 // Sap xep theo TB mon hoc tu cao xuong thap
	//Mon Toan
void sapxepTBmontheokhoi(hs &a, int x){
	hs p = a;
	int lc;
 	cout << "Danh sach sinh vien sap xep theo TB mon: " << endl;
	cout << "1.Mon Toan: "  << endl;
	cout << "2.Mon Van: " << endl;
	cout << "3.Mon NN: " <<  endl;
	cout << "4.Mon Li: " <<  endl;
	cout << "5.Mon Hoa: " <<  endl;
	cout << "6.Mon Sinh: " <<  endl;
	cout << "7.Mon GDCD: " <<  endl;
	cout << "8.Mon Su: " <<  endl;
	cout << "9.Mon Dia: " <<  endl;
	cout << "10.Mon Tin: " <<  endl;
	cout << "11.Mon CN: " <<  endl;
	cout << "Nhap mon can xem: "; cin >> lc;
	float k;
	// mon toan
	if(lc == 1){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.ToanTB > max->s.ToanTB){
					max = q;
				}
				if(q->s.ToanTB == max->s.ToanTB){
					sapxep3(a);	
				}
				int tmp = max->s.ToanTB;
				max->s.ToanTB = p->s.ToanTB;
				p->s.ToanTB = tmp;
			}
		}
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.ToanTB << endl;	
			}
		}
	}
	// mon van
	else if(lc == 2){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.VanTB > max->s.VanTB){
					max = q;
				}
				if(q->s.VanTB == max->s.VanTB){
					sapxep3(a);	
				}
				int tmp = max->s.VanTB;
				max->s.VanTB = p->s.VanTB;
				p->s.VanTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.VanTB << endl;	
			}
		}
	}
	// mon ngoai ngu
	else if(lc == 3){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.NNTB > max->s.NNTB){
					max = q;
				}
				if(q->s.NNTB == max->s.NNTB){
					sapxep3(a);	
				}
				int tmp = max->s.NNTB;
				max->s.NNTB = p->s.NNTB;
				p->s.NNTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.NNTB << endl;	
			}
		}
	}
	// mon vat li
	else if(lc == 4){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.LiTB > max->s.LiTB){
					max = q;
				}
				if(q->s.LiTB == max->s.LiTB){
					sapxep3(a);	
				}
				int tmp = max->s.LiTB;
				max->s.LiTB = p->s.LiTB;
				p->s.LiTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.LiTB << endl;	
			}
		}
	}
	// mon hoa hoc
	else if(lc == 5){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.HoaTB > max->s.HoaTB){
					max = q;
				}
				if(q->s.HoaTB == max->s.HoaTB){
					sapxep3(a);	
				}
				int tmp = max->s.HoaTB;
				max->s.HoaTB = p->s.HoaTB;
				p->s.HoaTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.HoaTB << endl;	
			}
		}
	}
	// mon sinh hoc
	else if(lc == 6){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.SinhTB > max->s.SinhTB){
					max = q;
				}
				if(q->s.SinhTB == max->s.SinhTB){
					sapxep3(a);	
				}
				int tmp = max->s.SinhTB;
				max->s.SinhTB = p->s.SinhTB;
				p->s.SinhTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.SinhTB << endl;	
			}
		}
	}
	// mon giao duc cong dan
	else if(lc == 7){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.GDCDTB > max->s.GDCDTB){
					max = q;
				}
				if(q->s.GDCDTB == max->s.GDCDTB){
					sapxep3(a);	
				}
				int tmp = max->s.GDCDTB;
				max->s.GDCDTB = p->s.GDCDTB;
				p->s.GDCDTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.GDCDTB << endl;	
			}
		}
	}
	// mon lich su
	else if(lc == 8){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.SuTB > max->s.SuTB){
					max = q;
				}
				if(q->s.SuTB == max->s.SuTB){
					sapxep3(a);	
				}
				int tmp = max->s.SuTB;
				max->s.SuTB = p->s.SuTB;
				p->s.SuTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.SuTB << endl;	
			}
		}
	}
	// mon dia li
	else if(lc == 9){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.DiaTB > max->s.DiaTB){
					max = q;
				}
				if(q->s.DiaTB == max->s.DiaTB){
					sapxep3(a);	
				}
				int tmp = max->s.DiaTB;
				max->s.DiaTB = p->s.DiaTB;
				p->s.DiaTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.DiaTB << endl;	
			}
		}
	}
	// mon tin hoc
	else if(lc == 10){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.TinTB > max->s.TinTB){
					max = q;
				}
				if(q->s.TinTB == max->s.TinTB){
					sapxep3(a);	
				}
				int tmp = max->s.TinTB;
				max->s.TinTB = p->s.TinTB;
				p->s.TinTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.TinTB << endl;	
			}
		}
	}
	// mon cong nghe
	else if(lc == 11){
		for (p; p->next = NULL; p = p->next){
			hs max = p;
			for(hs q = p->next; q != NULL; q = q->next){
				if(q->s.CNTB > max->s.CNTB){
					max = q;
				}
				if(q->s.CNTB == max->s.CNTB){
					sapxep3(a);	
				}
				int tmp = max->s.CNTB;
				max->s.CNTB = p->s.CNTB;
				p->s.CNTB = tmp;
			}
		}	
		hs l = a;
		int f = 1;
		for(l; l->next != NULL; l = l->next){
			if(l->s.khoilop == x){
				cout <<"Hoc sinh dung thu: " << f << endl; ++f;
				cout <<"Ho Ten: " << l->s.name << endl;
				cout <<"Diem trung binh mon toan: " << l->s.CNTB << endl;	
			}
		}
	}
}

// duyet thong tin ca nhan 1 hoc sinh
void duyettt(Student s){
	cout << "Khoi lop: " << s.khoilop << endl;
	cout << "Ho Ten: " << s.name << endl;
	cout << "STT theo ds lop: " << s.stt << endl;	
}

// duyet 1 hoc sinh
void duyeths(Student s){
	cout << "\n-----------------------\n";
	cout << "Khoi lop: " << s.khoilop << endl;
	cout << "Ho Ten: " << s.name << endl;
	cout << "STT theo ds lop: " << s.stt << endl;
	cout << "Hanh kiem: " << s.HanhKiem << endl;
	cout << "Diem cac mon hoc:\n";
	cout << "Mon Toan: " << s.ToanTX1 << " " << s.ToanTX2 << " " << s.ToanGK << " " << s.ToanCK << " " << s.ToanTB << endl;
	cout << "Mon Ngu Van: " << s.VanTX1 << " " << s.VanTX2 << " " << s.VanGK << " " << s.VanCK << " " << s.VanTB << endl;
	cout << "Mon Ngoai Ngu: " << s.NNTX1 << " " << s.NNTX2 << " " << s.NNGK << " " << s.NNCK << " " << s.NNTB << endl;
	cout << "Mon GDCD: " << s.GDCDTX1 << " " << s.GDCDTX2 << " " << s.GDCDGK << " " << s.GDCDCK << " " << s.GDCDTB << endl;
	cout << "Mon Lich Su: " << s.SuTX1 << " " << s.SuTX2 << " " << s.SuGK << " " << s.SuCK << " " << s.SuTB << endl;
	cout << "Mon Dia Li: " << s.DiaTX1 << " " << s.DiaTX2 << " " << s.DiaGK << " " << s.DiaCK << " " << s.DiaTB << endl;
	cout << "Mon Vat Ly: " << s.LiTX1 << " " << s.LiTX2 << " " << s.LiGK << " " << s.LiCK << " " << s.LiTB << endl;
	cout << "Mon Hoa Hoc: " << s.HoaTX1 << " " << s.HoaTX2 << " " << s.HoaGK << " " << s.HoaCK << " " << s.HoaTB << endl;
	cout << "Mon Sinh Hoc: " << s.SinhTX1 << " " << s.SinhTX2 << " " << s.SinhGK << " " << s.SinhCK << " " << s.SinhTB << endl;
	cout << "Mon Cong Nghe: " << s.CNTX1 << " " << s.CNTX2 << " " << s.CNGK << " " << s.CNCK << " " << s.CNTB << endl;
	cout << "Mon Tin Hoc: " << s.TinTX1 << " " << s.TinTX2 << " " << s.TinGK << " " << s.TinCK << " " << s.TinTB << endl;
	cout << "Mon The Duc: " << s.Theduc << endl;
	cout << "Mon Nghe Thuat: " << s.Nghethuat << endl;
	cout << "Diem trung binh tat ca cac mon: " << s.TBmon << endl;
	// danh gia hoc sinh (xu ly xau)
	danhgia(s);
}

// duyet ds hoc sinh
void duyetds(hs a){
	hs p = a;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++)
	{
		duyeths(p->s);
		p = p->next;
	}
	cout << endl;
}

// duyet ds hoc sinh theo khoi lop
void duyetdskhoi(hs a, int x){
	hs p = a;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++)
	{
		if(p->s.khoilop == x){
			duyeths(p->s);
		}
		p = p->next;
	}
	cout << endl;
} 

// tim kiem hoc sinh co khoi lop cho truoc
void findhs1(hs a, int x)
{
	hs p = a;
	Student as = p->s;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++){
		p = p->next;
		if (as.khoilop == x)
		{
			duyettt(p->s);
		}
	}
}

// tim kiem hoc sinh co khoi lop va stt cho truoc 
void findhs2(hs a, int x, long y )
{
	hs p = a;
	Student as = p->s;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++)
	{
		p = p->next;
		if (as.khoilop == x && as.stt == y)
		{
			duyettt(p->s);
		}
	}
}

// tim kiem hoc sinh theo ten
void findhs3(hs a, string nem){
	hs p = a;
	Student as = p->s;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++){
		if (as.name == nem){
			duyettt(p->s);
		}
		p = p->next;
	}
}

// tim kiem hoc sinh theo ten va khoi lop cho truoc
void findhs4(hs a, string nem, int x){
	hs p = a;
	Student as = p->s;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++){
		if (as.name == nem && as.khoilop == x){
			duyettt(p->s);
		}
		p = p->next;
	}
}


// xoa hoc sinh o dau 
void deletefirst(hs &a){
	if(a == NULL) return;
	a = a->next;
}

// xoa hoc sinh o cuoi
void deletelast(hs &a){
	if(a == NULL) return;
	hs q = NULL, p = a;
	while(p->next != NULL){
		q = p;
		p = p->next;
	}
	if(q == NULL){
		a = NULL;
	}
	else{
		q->next = NULL;
	}
}

// xoa hoc sinh 1 khoi lop 
void deletehs3(hs &h, int x){
	int n = Sizehs(h);
	hs p = h;
	hs q = NULL;
	for(int i = 0 ; i < n ; i++){
		if(p->s.khoilop == x ){
			q->next = p->next;
		} else{
			q = p;
		}
		p = p->next;
	}
}


// xoa hoc sinh co stt cho truoc 
void deletehs4(hs &h, long x){
	int n = Sizehs(h);
	hs p = h;
	hs q = NULL;
	for(int i = 0 ; i < n ; i++){
		if(p->s.stt == x ){
			q->next = p->next;
		} else{
			q = p;
		}
		p = p->next;
	}
}


// xoa hoc sinh co khoi lop va stt tuong ung
void deletehs1(hs &h, int x, long y){
	int n = Sizehs(h);
	hs p = h;
	hs q = NULL;
	for(int i = 0 ; i < n ; i++){
		if(p->s.khoilop == x && p->s.stt == y){
			q->next = p->next;
			break;
		} else{
			q = p;
			p = p->next;
		}
	}
}


// xoa hoc sinh co ten cho truoc va khoi lop cho truoc
void deletehs2(hs &h, string nem, int x){
	int n = Sizehs(h);
	hs p = h;
	hs q = NULL;
	chuanhoa(nem);
	for(int i = 0 ; i < n ; i++){
		if(p->s.khoilop == x && p->s.name == nem){
			q->next = p->next;
			break;
		} else{
			q = p;
			p = p->next;
		}
	}
}


// sua thong tin hoc sinh co ten va khoi lop cho truoc
void sua(hs &a,string y, int x, int k){
	int lc;
	// tim kiem hoc sinh co ten y va khoi lop k
	hs p = a;
	int n = Sizehs(a);
	for(int i = 0; i < n; i++){
		if(p->s.name == y && p->s.khoilop == k){
			break;
		}
		a = a->next;
	}
	// sua nhung thong tin khac
	if(x == 0){
		cout << "Thong tin hoc sinh hien tai: " << endl;
		cout << "1.Khoi lop: " << a->s.khoilop << endl;
		cout << "2.Ho va ten: "<< a->s.name << endl;
		cout << "3.So thu tu: "<< a->s.stt << endl;
		cout << "4.Hanh kiem: "<< a->s.HanhKiem << endl;
		cout << "Nhap lua chon thong tin can sua: "; cin >> lc;
		if(lc == 1){
			cout << "Khoi lop moi: "; cin >> a->s.khoilop;
		}
		else if(lc == 2){
			string nem;
			cout << "Ho va ten hoc sinh: ";cin.ignore();
			getline(cin, nem);
			chuanhoa(nem);
			a->s.name = nem;
		}
		else if(lc == 3){
			cout << "So thu tu moi: "; cin >> a->s.stt;
		}
		else if(lc == 4){
			string hanhkiemmoi;
			cout << "Hanh kiem hoc sinh: "; cin.ignore();
			getline(cin, hanhkiemmoi);
			chuanhoa(hanhkiemmoi);
			a->s.HanhKiem = hanhkiemmoi;
		}
	}
	// mon toan
	else if(x == 1){
		cout << "Diem mon toan hien tai: " << a->s.ToanTX1 << " " << a->s.ToanTX2 << " " << a->s.ToanGK << " " << a->s.ToanCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.ToanTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.ToanTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.ToanGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.ToanCK;
		}
	}
	// mon van
	else if(x == 2){
		cout << "Diem mon van hien tai: " << a->s.VanTX1 << " " << a->s.VanTX2 << " " << a->s.VanGK << " " << a->s.VanCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.VanTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.VanTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.VanGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.VanCK;
		}
	}
	// mon ngoai ngu
	else if(x == 3){
		cout << "Diem mon ngoai ngu hien tai: " << a->s.NNTX1 << " " << a->s.NNTX2 << " " << a->s.NNGK << " " << a->s.NNCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.NNTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.NNTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.NNGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.NNCK;
		}
	}
	// mon GĐCD
	else if(x == 4){
		cout << "Diem mon GDCD hien tai: " << a->s.GDCDTX1 << " " << a->s.GDCDTX2 << " " << a->s.GDCDGK << " " << a->s.GDCDCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.GDCDTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.GDCDTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.GDCDGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.GDCDCK;
		}
	}
	// mon lich su
	else if(x == 5){
		cout << "Diem mon lich su hien tai: " << a->s.SuTX1 << " " << a->s.SuTX2 << " " << a->s.SuGK << " " << a->s.SuCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.SuTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.SuTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.SuGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.SuCK;
		}
	}
	// mon dia li
	else if(x == 6){
		cout << "Diem mon dia li hien tai: " << a->s.DiaTX1 << " " << a->s.DiaTX2 << " " << a->s.DiaGK << " " << a->s.DiaCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.DiaTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.DiaTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.DiaGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.DiaCK;
		}
	}
	// mon vat li
	else if(x == 7){
		cout << "Diem mon dia li hien tai: " << a->s.LiTX1 << " " << a->s.LiTX2 << " " << a->s.LiGK << " " << a->s.LiCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.LiTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.LiTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.LiGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.LiCK;
		}
	}
	// mon hoa hoc
	else if(x == 8){
		cout << "Diem mon dia li hien tai: " << a->s.HoaTX1 << " " << a->s.HoaTX2 << " " << a->s.HoaGK << " " << a->s.HoaCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.HoaTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.HoaTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.HoaGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.HoaCK;
		}
	}
	// mon sinh hoc
	else if(x == 9){
		cout << "Diem mon dia li hien tai: " << a->s.SinhTX1 << " " << a->s.SinhTX2 << " " << a->s.SinhGK << " " << a->s.SinhCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.SinhTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.SinhTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.SinhGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.SinhCK;
		}
	}
	// mon cong nghe
	else if(x == 10){
		cout << "Diem mon dia li hien tai: " << a->s.CNTX1 << " " << a->s.CNTX2 << " " << a->s.CNGK << " " << a->s.CNCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.CNTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.CNTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.CNGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.CNCK;
		}
	}
	// mon tin hoc
	else if(x == 11){
		cout << "Diem mon dia li hien tai: " << a->s.TinTX1 << " " << a->s.TinTX2 << " " << a->s.TinGK << " " << a->s.TinCK << " " << endl;
		cout << "Diem can sua: " << endl;
		cout << "1.Diem thuong xuyen 1" << endl;
		cout << "2.Diem thuong xuyen 2" << endl;
		cout << "3.Diem giua ki" << endl;
		cout << "4.Diem cuoi ki" << endl;
		cout << "Nhap lua chon: "; cin >> lc;
		if(lc == 1){
			cout << "Diem moi: ";cin >> a->s.TinTX1;
		}
		else if(lc == 2){
			cout << "Diem moi: ";cin >> a->s.TinTX2;
		}
		else if(lc == 3){
			cout << "Diem moi: ";cin >> a->s.TinGK;
		}
		else if(lc == 4){
			cout << "Diem moi: ";cin >> a->s.TinCK;
		}
	}
	// 2 mon nghe thuat 
	else if(x == 12){
		cout << "Trang thai 2 mon hoc danh gia bang nhan xet: " << endl;
		cout << "1.Mon Nghe thuat: " << a->s.Nghethuat << endl;
		cout << "2.Mon The duc: " << a->s.Theduc << endl;
		cout << "Nhap mon can sua: "; cin >> lc;
		string sua;
		if(lc == 1){
			cout << "Nhap nhan xet cua mon Nghe thuat: " << endl;
			getline(cin, sua); chuanhoa(sua);
			a->s.Nghethuat = sua;
		}
		else if(lc == 2){
			cout << "Nhap nhan xet cua mon The duc: " << endl;
			getline(cin, sua); chuanhoa(sua);
			a->s.Theduc = sua;
		}
	}
	
}


// thong ke hoc sinh
void thongke(hs a){
	float dem1 = 0, dem2 = 0, dem3 = 0, dem4 = 0, dem5 = 0;
	int n = Sizehs(a);
	hs p = a;
	while(p->next != NULL){
		if(a->s.loai == 1) ++dem1;
		if(a->s.loai == 2) ++dem2;
		if(a->s.loai == 3) ++dem3;
		if(a->s.loai == 4) ++dem4;
		if(a->s.loai == 5) ++dem5;
		p = p->next;
	}
	float tbgioi = dem1 / n * 100;
	float tbkha = dem2 / n * 100;
	float tbtb = dem3 / n * 100;
	float tbyeu = dem4 / n * 100;
	float tbdup = dem5 / n * 100;
	
	cout << "Tong cong " << n << " hoc sinh" << endl;
	cout << dem1 << " hoc sinh gioi chiem " << tbgioi << " %" << endl;
	cout << dem2 << " hoc sinh kha chiem " << tbkha << " %" << endl;
	cout << dem3 << " hoc sinh trung binh chiem " << tbtb << " %" << endl;
	cout << dem4 << " hoc sinh yeu chiem " << tbyeu << " %" << endl;
	cout << dem5 << " hoc sinh dup chiem " << tbdup << " %" << endl;
}


// thong ke hoc sinh theo khoi lop
void thongkekhoi(hs a, int x){
	float dem1 = 0, dem2 = 0, dem3 = 0, dem4 = 0, dem5 = 0;
	int n = Sizehs(a);
	hs p = a;
	while(p->next != NULL){
		if(a->s.khoilop == x){
			if(a->s.loai == 1) ++dem1;
			if(a->s.loai == 2) ++dem2;
			if(a->s.loai == 3) ++dem3;
			if(a->s.loai == 4) ++dem4;
			if(a->s.loai == 5) ++dem5;
		}
		p = p->next;
	}
	float tbgioi = dem1 / n * 100;
	float tbkha = dem2 / n * 100;
	float tbtb = dem3 / n * 100;
	float tbyeu = dem4 / n * 100;
	float tbdup = dem5 / n * 100;
	
	cout << "Khoi lop " << x  << " tong cong " << n << " hoc sinh" << endl;
	cout << dem1 << " hoc sinh gioi chiem " << tbgioi << " %" << endl;
	cout << dem2 << " hoc sinh kha chiem " << tbkha << " %" << endl;
	cout << dem3 << " hoc sinh trung binh chiem " << tbtb << " %" << endl;
	cout << dem4 << " hoc sinh yeu chiem " << tbyeu << " %" << endl;
	cout << dem5 << " hoc sinh dup chiem " << tbdup << " %" << endl;
}




int main(){
	hs head = NULL;
	/*
	Student s;

	// nhap file
	ifstream file;
	file.open("Input.txt"); // mo file
	int b;
	file >> b;
	for(int i = 0; i < b; i++){
		file >> s.khoilop;
		file.ignore(); getline(file, s.name);
		file >> s.stt;
		file.ignore(); getline(file, s.HanhKiem);
		// mon toan
		file >> s.ToanTX1 >> s.ToanTX2 >> s.ToanGK >> s.ToanCK;
		s.ToanTB = s.ToanTX1*0.1 + s.ToanTX2*0.1 + s.ToanGK*0.3 + s.ToanCK*0.5;
		// mon van
		file >> s.VanTX1 >> s.VanTX2 >> s.VanGK >> s.VanCK;
		s.VanTB = s.VanTX1*0.1 + s.VanTX2*0.1 + s.VanGK*0.3 + s.VanCK*0.5;
		// mon ngoai ngu
		file >> s.NNTX1 >> s.NNTX2 >> s.NNGK >> s.NNCK;
		s.NNTB = s.NNTX1*0.1 + s.NNTX2*0.1 + s.NNGK*0.3 + s.NNCK*0.5;
		// mon GDCD
		file >> s.GDCDTX1 >> s.GDCDTX2 >> s.GDCDGK >> s.GDCDCK;
		s.GDCDTB = s.GDCDTX1*0.1 + s.GDCDTX2*0.1 + s.GDCDGK*0.3 + s.GDCDCK*0.5;
		// mon lich su
		file >> s.SuTX1 >> s.SuTX2 >> s.SuGK >> s.SuCK;
		s.SuTB = s.SuTX1*0.1 + s.SuTX2*0.1 + s.SuGK*0.3 + s.SuCK*0.5;
		// mon dia li
		file >> s.DiaTX1 >> s.DiaTX2 >> s.DiaGK >> s.DiaCK;
		s.DiaTB = s.DiaTX1*0.1 + s.DiaTX2*0.1 + s.DiaGK*0.3 + s.DiaCK*0.5;
		// mon vat li
		file >> s.LiTX1 >> s.LiTX2 >> s.LiGK >> s.LiCK;
		s.LiTB = s.LiTX1*0.1 + s.LiTX2*0.1 + s.LiGK*0.3 + s.LiCK*0.5;
		// mon hoa hoc
		file >> s.HoaTX1 >> s.HoaTX2 >> s.HoaGK >> s.HoaCK;
		s.HoaTB = s.HoaTX1*0.1 + s.HoaTX2*0.1 + s.HoaGK*0.3 + s.HoaCK*0.5;
		// mon sinh hoc
		file >> s.SinhTX1 >> s.SinhTX2 >> s.SinhGK >> s.SinhCK;
		s.SinhTB = s.SinhTX1*0.1 + s.SinhTX2*0.1 + s.SinhGK*0.3 + s.SinhCK*0.5;
		// mon cong nghe
		file >> s.CNTX1 >> s.CNTX2 >> s.CNGK >> s.CNCK;
		s.CNTB = s.CNTX1*0.1 + s.CNTX2*0.1 + s.CNGK*0.3 + s.CNCK*0.5;
		// mon tin hoc
		file >> s.TinTX1 >> s.TinTX2 >> s.TinGK >> s.TinCK;
		s.TinTB = s.TinTX1*0.1 + s.TinTX2*0.1 + s.TinGK*0.3 + s.TinCK*0.5;
		// 2 mon danh gia bang nhan xet
		file.ignore(); getline(file, s.Nghethuat);
		file.ignore(); getline(file, s.Theduc);
		
		s.TBmon = (s.ToanTB + s.VanTB + s.NNTB + s.GDCDTB + s.SuTB + s.DiaTB + s.LiTB + s.HoaTB + s.SinhTB + s.CNTB + s.TinTB) / 11;
		
		hs tmp = new HS();
		tmp->s = s;
		tmp->next = NULL;
		head = tmp;
		head = head->next;
	}
	// dong file
	file.close();  
	*/
	
	// san 3 hs
	Student s;
	
	   	// hs thu 1
	   	
	   	s.khoilop = 8;
	   	s.name = "Nong Van Den";
	   	s.stt = 26;
	   	s.HanhKiem = "Tot";
	   	
	   	s.ToanTX1 = 9;
	   	s.ToanTX2 = 9;
	   	s.ToanGK = 9;
	   	s.ToanCK = 9;
	   	
	   	s.VanTX1 = 8;
	   	s.VanTX2 = 8;
	   	s.VanGK = 7;
	   	s.VanCK = 6.5;
	   	
	   	s.NNTX1 = 9;
	   	s.NNTX2 = 8;
	   	s.NNGK = 6.5;
	   	s.NNCK = 6;
	   	
	   	s.GDCDTX1 = 9;
	   	s.GDCDTX2 = 10;
	   	s.GDCDGK = 9;
	   	s.GDCDCK = 9;
	   	
	   	s.SuTX1 = 9;
	   	s.SuTX2 = 8;
	   	s.SuGK = 8;
	   	s.SuCK = 7.5;
	   	
	   	s.DiaTX1 = 9;
	   	s.DiaTX2 = 10;
	   	s.DiaGK = 9.5;
	   	s.DiaCK = 9;
	   	
	   	s.LiTX1 = 9;
	   	s.LiTX2 = 10;
	   	s.LiGK = 8;
	   	s.LiCK = 8;
	   	
	   	s.HoaTX1 = 9;
	   	s.HoaTX2 = 10;
	   	s.HoaGK = 9.5;
	   	s.HoaCK = 9;
	   	
	   	s.SinhTX1 = 9;
	   	s.SinhTX2 = 10;
	   	s.SinhGK = 7.5;
	   	s.SinhCK = 7;
	   	
	   	s.CNTX1 = 10;
	   	s.CNTX2 = 10;
	   	s.CNGK = 9;
	   	s.CNCK = 10;
	   	
	   	s.TinTX1 = 10;
		s.TinTX2 = 10;
		s.TinGK = 10;
		s.TinCK = 9.5; 
		
		s.Theduc = "Dat";
		s.Nghethuat = "Dat";
		
		s.ToanTB = s.ToanTX1*0.1 + s.ToanTX2*0.1 + s.ToanGK*0.3 + s.ToanCK*0.5;
		s.VanTB = s.VanTX1*0.1 + s.VanTX2*0.1 + s.VanGK*0.3 + s.VanCK*0.5;
		s.NNTB = s.NNTX1*0.1 + s.NNTX2*0.1 + s.NNGK*0.3 + s.NNCK*0.5;
		s.GDCDTB = s.GDCDTX1*0.1 + s.GDCDTX2*0.1 + s.GDCDGK*0.3 + s.GDCDCK*0.5;
		s.SuTB = s.SuTX1*0.1 + s.SuTX2*0.1 + s.SuGK*0.3 + s.SuCK*0.5;
		s.DiaTB = s.DiaTX1*0.1 + s.DiaTX2*0.1 + s.DiaGK*0.3 + s.DiaCK*0.5;
		s.LiTB = s.LiTX1*0.1 + s.LiTX2*0.1 + s.LiGK*0.3 + s.LiCK*0.5;
		s.HoaTB = s.HoaTX1*0.1 + s.HoaTX2*0.1 + s.HoaGK*0.3 + s.HoaCK*0.5;
		s.SinhTB = s.SinhTX1*0.1 + s.SinhTX2*0.1 + s.SinhGK*0.3 + s.SinhCK*0.5;
		s.CNTB = s.CNTX1*0.1 + s.CNTX2*0.1 + s.CNGK*0.3 + s.CNCK*0.5;
		s.TinTB = s.TinTX1*0.1 + s.TinTX2*0.1 + s.TinGK*0.3 + s.TinCK*0.5;
		s.TBmon = (s.ToanTB + s.VanTB + s.NNTB + s.GDCDTB + s.SuTB + s.DiaTB + s.LiTB + s.HoaTB + s.SinhTB + s.CNTB + s.TinTB) / 11;
			   	
	  	hs tmp = new HS();
		tmp->s = s;
		tmp->next = NULL;
		head = tmp;
		
		// hs thu 2
		hs q = head;
		hs p = head;
		while(p->next != NULL){
			p = p->next;
		}
	   	s.khoilop = 8;
	   	s.name = "Cao Van Luong";
	   	s.stt = 14;
	   	s.HanhKiem = "Kha";
	   	
	   	s.ToanTX1 = 8;
	   	s.ToanTX2 = 9;
	   	s.ToanGK = 8;
	   	s.ToanCK = 7;
	   	
	   	s.VanTX1 = 9;
	   	s.VanTX2 = 8;
	   	s.VanGK = 8.5;
	   	s.VanCK = 8;
	   	
	   	s.NNTX1 = 9;
	   	s.NNTX2 = 10;
	   	s.NNGK = 8;
	   	s.NNCK = 8.5;
	   	
	   	s.GDCDTX1 = 9;
	   	s.GDCDTX2 = 10;
	   	s.GDCDGK = 9;
	   	s.GDCDCK = 9;
	   	
	   	s.SuTX1 = 9;
	   	s.SuTX2 = 8;
	   	s.SuGK = 8;
	   	s.SuCK = 7.5;
	   	
	   	s.DiaTX1 = 9;
	   	s.DiaTX2 = 10;
	   	s.DiaGK = 9.5;
	   	s.DiaCK = 9;
	   	
	   	s.LiTX1 = 8;
	   	s.LiTX2 = 8;
	   	s.LiGK = 7;
	   	s.LiCK = 6.5;
	   	
	   	s.HoaTX1 = 8;
	   	s.HoaTX2 = 7.5;
	   	s.HoaGK = 7;
	   	s.HoaCK = 6;
	   	
	   	s.SinhTX1 = 9;
	   	s.SinhTX2 = 10;
	   	s.SinhGK = 7.5;
	   	s.SinhCK = 7;
	   	
	   	s.CNTX1 = 10;
	   	s.CNTX2 = 10;
	   	s.CNGK = 9;
	   	s.CNCK = 10;
	   	
	   	s.TinTX1 = 10;
		s.TinTX2 = 10;
		s.TinGK = 10;
		s.TinCK = 9.5; 
		
		s.Theduc = "Dat";
		s.Nghethuat = "Dat";
		
		s.ToanTB = s.ToanTX1*0.1 + s.ToanTX2*0.1 + s.ToanGK*0.3 + s.ToanCK*0.5;
		s.VanTB = s.VanTX1*0.1 + s.VanTX2*0.1 + s.VanGK*0.3 + s.VanCK*0.5;
		s.NNTB = s.NNTX1*0.1 + s.NNTX2*0.1 + s.NNGK*0.3 + s.NNCK*0.5;
		s.GDCDTB = s.GDCDTX1*0.1 + s.GDCDTX2*0.1 + s.GDCDGK*0.3 + s.GDCDCK*0.5;
		s.SuTB = s.SuTX1*0.1 + s.SuTX2*0.1 + s.SuGK*0.3 + s.SuCK*0.5;
		s.DiaTB = s.DiaTX1*0.1 + s.DiaTX2*0.1 + s.DiaGK*0.3 + s.DiaCK*0.5;
		s.LiTB = s.LiTX1*0.1 + s.LiTX2*0.1 + s.LiGK*0.3 + s.LiCK*0.5;
		s.HoaTB = s.HoaTX1*0.1 + s.HoaTX2*0.1 + s.HoaGK*0.3 + s.HoaCK*0.5;
		s.SinhTB = s.SinhTX1*0.1 + s.SinhTX2*0.1 + s.SinhGK*0.3 + s.SinhCK*0.5;
		s.CNTB = s.CNTX1*0.1 + s.CNTX2*0.1 + s.CNGK*0.3 + s.CNCK*0.5;
		s.TinTB = s.TinTX1*0.1 + s.TinTX2*0.1 + s.TinGK*0.3 + s.TinCK*0.5;
		s.TBmon = (s.ToanTB + s.VanTB + s.NNTB + s.GDCDTB + s.SuTB + s.DiaTB + s.LiTB + s.HoaTB + s.SinhTB + s.CNTB + s.TinTB) / 11;
			   	
	  	hs tpp = new HS();
		tpp->s = s;
		tpp->next = NULL;
		p->next = tpp;
		
		// hs thu 3
		s.khoilop = 7;
	   	s.name = "Phung Thanh Khoai";
	   	s.stt = 26;
	   	s.HanhKiem = "Kha";
	   	
	   	s.ToanTX1 = 7;
	   	s.ToanTX2 = 8;
	   	s.ToanGK = 7;
	   	s.ToanCK = 7;
	   	
	   	s.VanTX1 = 9;
	   	s.VanTX2 = 8;
	   	s.VanGK = 8.5;
	   	s.VanCK = 8;
	   	
	   	s.NNTX1 = 7;
	   	s.NNTX2 = 8;
	   	s.NNGK = 6;
	   	s.NNCK = 5.5;
	   	
	   	s.GDCDTX1 = 9;
	   	s.GDCDTX2 = 10;
	   	s.GDCDGK = 9;
	   	s.GDCDCK = 9;
	   	
	   	s.SuTX1 = 9;
	   	s.SuTX2 = 8;
	   	s.SuGK = 8;
	   	s.SuCK = 7.5;
	   	
	   	s.DiaTX1 = 9;
	   	s.DiaTX2 = 10;
	   	s.DiaGK = 9.5;
	   	s.DiaCK = 9;
	   	
	   	s.LiTX1 = 7;
	   	s.LiTX2 = 7;
	   	s.LiGK = 6;
	   	s.LiCK = 6.5;
	   	
	   	s.HoaTX1 = 7;
	   	s.HoaTX2 = 7;
	   	s.HoaGK = 7;
	   	s.HoaCK = 6;
	   	
	   	s.SinhTX1 = 9;
	   	s.SinhTX2 = 10;
	   	s.SinhGK = 7.5;
	   	s.SinhCK = 7;
	   	
	   	s.CNTX1 = 10;
	   	s.CNTX2 = 10;
	   	s.CNGK = 9;
	   	s.CNCK = 10;
	   	
	   	s.TinTX1 = 8;
		s.TinTX2 = 9;
		s.TinGK = 8;
		s.TinCK = 8; 
		
		s.Theduc = "Dat";
		s.Nghethuat = "Dat";
		
		s.ToanTB = s.ToanTX1*0.1 + s.ToanTX2*0.1 + s.ToanGK*0.3 + s.ToanCK*0.5;
		s.VanTB = s.VanTX1*0.1 + s.VanTX2*0.1 + s.VanGK*0.3 + s.VanCK*0.5;
		s.NNTB = s.NNTX1*0.1 + s.NNTX2*0.1 + s.NNGK*0.3 + s.NNCK*0.5;
		s.GDCDTB = s.GDCDTX1*0.1 + s.GDCDTX2*0.1 + s.GDCDGK*0.3 + s.GDCDCK*0.5;
		s.SuTB = s.SuTX1*0.1 + s.SuTX2*0.1 + s.SuGK*0.3 + s.SuCK*0.5;
		s.DiaTB = s.DiaTX1*0.1 + s.DiaTX2*0.1 + s.DiaGK*0.3 + s.DiaCK*0.5;
		s.LiTB = s.LiTX1*0.1 + s.LiTX2*0.1 + s.LiGK*0.3 + s.LiCK*0.5;
		s.HoaTB = s.HoaTX1*0.1 + s.HoaTX2*0.1 + s.HoaGK*0.3 + s.HoaCK*0.5;
		s.SinhTB = s.SinhTX1*0.1 + s.SinhTX2*0.1 + s.SinhGK*0.3 + s.SinhCK*0.5;
		s.CNTB = s.CNTX1*0.1 + s.CNTX2*0.1 + s.CNGK*0.3 + s.CNCK*0.5;
		s.TinTB = s.TinTX1*0.1 + s.TinTX2*0.1 + s.TinGK*0.3 + s.TinCK*0.5;
		s.TBmon = (s.ToanTB + s.VanTB + s.NNTB + s.GDCDTB + s.SuTB + s.DiaTB + s.LiTB + s.HoaTB + s.SinhTB + s.CNTB + s.TinTB) / 11;
			
		while(q->next != NULL){
			q = q->next;
		}	   	
	  	hs tkt = new HS();
	  	tkt->s = s;
		tkt->next = NULL;
		q->next = tkt;
		
	
	while(1){
		cout << "Ban la:" << endl;
		cout << "1.Giao vien" << endl;
		cout << "2.Phu huynh" << endl;
		cout << "0.Thoat" << endl;
		int lc1; cout << "Nhap lua chon: "; cin >> lc1;
		if(lc1 == 0){
			return 0;
		}
		else if(lc1 == 1){
			int lc2;
            cout << "\n-----------------------\n";
            cout << "1. Them hoc sinh\n";
            cout << "2. Danh sach hoc sinh\n";
			cout << "3. Tim kiem va sua thong tin cua hoc sinh\n";
			cout << "4. Xoa hoc sinh\n";
			cout << "5. Thong ke hoc sinh\n";
            cout << "6. Quay lai\n";
            cout << "0.Thoat\n";
            cout << "Chon chuc nang: ";
            cin >> lc2;
            if(lc2 == 0){
            	return 0;
			}
            else if(lc2 == 1){
                insertfirst(head);
        	}	
            else if(lc2 == 2){
            	int lc3;
				cout << "\n-----------------------\n";
				cout << "1. Danh sach hoc sinh toan truong:\n";
				cout << "2. Danh sach hoc sinh khoi lop sap xep theo stt:\n";
				cout << "3. Danh sach hoc sinh khoi lop sap xep theo ten:\n";
				cout << "4. Danh sach hoc sinh khoi lop sap xep theo TBM giam dan:\n";
				cout << "5. Danh sach hoc sinh khoi lop sap xep theo xep loai hoc sinh giam dan:\n";
				cout << "6. Quay lai\n";
				cout << "0.Thoat\n";
				cout << "Chon chuc nang: ";
				cin >> lc3;
				if(lc3 == 0){
					return 0;
				}
				else if(lc3 == 1){
					sapxep1(head);
					duyetdskhoi(head,6);
					duyetdskhoi(head,7);
					duyetdskhoi(head,8);
					duyetdskhoi(head,9);
				}
				else if(lc3 == 2){
					sapxep2(head);
					int khoi;
					cout << "Nhap khoi can xem: "; cin >> khoi;
					duyetdskhoi(head, khoi);
				}
				else if(lc3 == 3){
					sapxep1(head);
					int khoi;
					cout << "Nhap khoi can xem: "; cin >> khoi;
					duyetdskhoi(head, khoi);
				}
				else if(lc3 == 4){
					int khoi;
					cout << "Nhap khoi can xem: "; cin >> khoi;
					sapxepTBmontheokhoi(head,khoi);
				}
				else if(lc3 == 5){
					sapxep4(head);
					int khoi;
					cout << "Nhap khoi can xem: "; cin >> khoi;
					duyetdskhoi(head, khoi);
				}
				else if(lc3 == 6){
					break;
				}
			}
			else if(lc2 == 3){
				int lc3;
				cout << "\n-----------------------\n";
				cout << "1. Tim kiem hoc sinh:\n";
				cout << "2. Sua thong tin hoc sinh:\n";
				cout << "3. Quay lai\n";
				cout << "4. Thoat\n";
				cout << "Chon chuc nang: "; cin >> lc3;
				if(lc3 == 0){
					return 0;
				}
                else if(lc3 == 1){
                	int lc4;
					cout << "\n-----------------------\n";
					cout << "1. Tim kiem hoc sinh theo khoi lop va stt\n";
					cout << "2. Tim kiem hoc sinh theo ho va ten\n";
					cout << "3. Tim kiem hoc sinh theo ten va khoi lop\n";
					cout << "4. Quay lai\n";
					cout << "0. Thoat\n";
					cin >> lc4;
					if(lc4 == 0){
						return 0;
					}
					else if(lc4 == 1){
						int khoi; 
						long stt;
						cout << "Nhap khoi lop va stt cua hoc sinh: "; cin >> khoi >> stt;
						findhs2(head,khoi,stt);
					}
					else if(lc4 == 2){
						string nem;
						cout << "Nhap ten hoc sinh: ";
						getline(cin, nem);
						chuanhoa(nem);
						findhs3(head, nem);
					}
					else if(lc4 == 3){
						string nem;
						int khoi;
						cout << "Nhap khoi lop cua hoc sinh: "; cin >> khoi;
						cout << "Nhap ten hoc sinh: "; cin.ignore();
						getline(cin, nem);
						chuanhoa(nem);
						findhs4(head, nem, khoi);
					}
					else if(lc4 == 4){
						break;
					}
				}
				else if(lc3 == 2){
					string ten;
					int khoi;
					cout << "Nhap khoi lop cua hoc sinh: "; cin >> khoi;
					cout << "Ho va ten sinh can sua: "; cin.ignore();
					getline(cin,ten);
					chuanhoa(ten);
					int lcsua;
					cout << "\n-----------------------\n";
					cout << "1. Thong tin ca nhan:\n";
					cout << "2. Diem mon Toan:\n";
					cout << "3. Diem mon Van:\n";
					cout << "4. Diem mon NN:\n";
					cout << "5. Diem mon GDCD:\n";
					cout << "6. Diem mon Lich Su:\n";
					cout << "7. Diem mon Dia Ly:\n";
					cout << "8. Diem mon Vat Ly:\n";
					cout << "9. Diem mon Hoa Hoc:\n";
					cout << "10. Diem mon Sinh Hoc:\n";
					cout << "11. Diem mon Cong Nghe:\n";
					cout << "12. Diem mon Tin Hoc:\n";
					cout << "13. Diem 2 mon Nghe Thuat, The Duc:\n";
					cout << "Chon muc can sua: ";
					cin >> lcsua;
					switch (lcsua){
						case 1: 
							sua(head,ten,0,khoi);
							break;
						case 2: 
							sua(head,ten,1,khoi);
							break;
						case 3: 
							sua(head,ten,2,khoi);
							break;
						case 4: 
							sua(head,ten,3,khoi);
							break;
						case 5: 
							sua(head,ten,4,khoi);
							break;
						case 6: 
							sua(head,ten,5,khoi);
							break;
						case 7: 
							sua(head,ten,6,khoi);
							break;
						case 8: 
							sua(head,ten,7,khoi);
							break;
						case 9: 
							sua(head,ten,8,khoi);
							break;
						case 10: 
							sua(head,ten,9,khoi);
							break;
						case 11: 
							sua(head,ten,10,khoi);
							break;
						case 12: 
							sua(head,ten,11,khoi);
							break;
						case 13: 
							sua(head,ten,12,khoi);
							break;
						default:
							cout << "Chuc nang khong hop le, vui long chon lai.\n";
					}
				}				
			}    
            else if(lc2 == 4){
            	int lc3;
				cout << "\n-----------------------\n";
				cout << "1. Xoa hoc sinh theo khoi lop:\n";
				cout << "2. Xoa hoc sinh theo ten va khoi lop:\n";
				cout << "3. Xoa hoc sinh theo stt trong khoi lop:\n";
				cout << "4. Quay lai\n";
				cout << "0. Thoat\n";
				cout << "Chon chuc nang: ";
				cin >> lc3;
                if( lc3 == 0){
                	return 0;
				}
				else if(lc3 == 1){
					int khoilop;
					cout << "Khoi lop can xoa: ";
					cin >>khoilop;
	                deletehs3(head,khoilop);
				}
				else if(lc3 == 2){
					int khoi;
					string ten;
					cout << "Ho va ten hoc sinh can xoa: "; cin.ignore();
					getline(cin,ten);
					chuanhoa(ten);
					cout << "Nhap khoi lop cua hoc sinh: "; cin >> khoi;
		            deletehs2(head,ten,khoi);
				}
				else if(lc3 == 3){
					int khoilop1;
					long stt;
					cout << "Khoi lop can xoa: ";
					cin >>khoilop1;
					cout << "STT can xoa: ";
					cin >>stt;
	               	deletehs1(head,khoilop1,stt);
				}
				else if(lc3 == 4){
					break;
				}
			}
			else if(lc2 == 5){
				int lc3;
				cout << "\n-----------------------\n";
				cout << "1. Thong ke hoc sinh toan truong:\n";
				cout << "2. Thong ke hoc sinh theo khoi lop:\n";
				cout << "0. Thoat\n";
				cout << "Chon chuc nang: ";
				cin >> lc3;
               	switch (lc3){
               		case 0: 
               			return 0;
                   	case 1: 
					   thongke(head);
					   break;
					case 2:
						int khoilop;
						cout << "Khoi lop can xem: ";
						cin >>khoilop;
		                thongkekhoi(head,khoilop);
						break;
					default:
	                    cout << "Chuc nang khong hop le, vui long chon lai.\n";
				}
			}
			else if(lc2 == 6){
				cout << "Thoat menu giao vien.\n";
                break;
			}     
            else{
            	cout << "Chuc nang khong hop le, vui long chon lai.\n";
			}
        }
		else if(lc1 == 2){
            int lc2;
            cout << "\n-----------------------\n";
            cout << "1. Xem danh sach hoc sinh\n";
            cout << "2. Xem chi tiet mot hoc sinh\n";
            cout << "3. Thoat\n";
            cout << "Chon chuc nang: ";
            cin >> lc2;
 			if(lc2 == 1){
 				int lc3;
				cout << "\n-----------------------\n";
				cout << "1. Xem danh sach toan truong:\n";
				cout << "2. Xem danh sach theo khoi lop\n";
				cout << "Chon chuc nang: ";
				cin >> lc3;
                switch (lc3){
	                case 1:{
						duyetds(head);
						break;
					}
					case 2:{
						int khoilop;
						cout << "Khoi lop can xem: ";
		                cin >> khoilop;
		                duyetdskhoi(head,khoilop);
		                break;
					}
					default:
	                    cout << "Chuc nang khong hop le, vui long chon lai.\n";
				}
			}
			else if(lc2 == 2){
				int lc3;
				cout << "\n-----------------------\n";
				cout << "1. Tim kiem hoc sinh theo khoi lop va stt:\n";
				cout << "2. Tim kiem hoc sinh theo ho va ten\n";
				cin >> lc3;
                switch (lc3){
	                case 1:{
		                int stt, khoilop;
						cout << "Nhap khoi lop hoc sinh can xem: ";
		                cin >> khoilop;
		                cout << "Nhap STT hoc sinh can xem: ";
		                cin >> stt;
		                hs tmp = head;
		                findhs2(tmp,khoilop,stt);
		                break;
					}
					case 2:{
						string ten;
						cout << "Ho va ten sinh can xem: "; cin.ignore();
		                getline(cin,ten);
						chuanhoa(ten);
		                hs tmp = head;
	                    findhs3(head,ten);
	                    break;
					}
					default:
	                    cout << "Chuc nang khong hop le, vui long chon lai.\n";
				}
			}
			else{
				cout << "Chuc nang khong hop le, vui long chon lai.\n";
			}
        }
    	else{
            cout << "Lua chon khong hop le, vui long chon lai.\n";
        }
    }
    return 0;
}	


	

