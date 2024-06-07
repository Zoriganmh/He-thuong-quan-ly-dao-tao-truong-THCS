#include <bits/stdc++.h>
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
	string loai;
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
	cout << "Nhap khoi lop:"; cin >> s.khoilop;
	string name;
	cout << "Nhap ten sinh vien:"; cin.ignore();
	getline(cin, name);
	chuanhoa(name); s.name = name;
	cout << "Nhap STT hoc sinh:"; cin >> s.stt;
	cout << "Hanh kiem hoc sinh: \n"; 
	cout << "(Tot, Kha, Trung binh, Yeu";
	string hanhkiem;
	cin.ignore(); getline(cin, hanhkiem);
	chuanhoa(hanhkiem); s.HanhKiem = hanhkiem;
	cout << "Nhap diem cac mon hoc:\n";
	
	cout << "Mon toan:\n";
	cout << "Diem thuong xuyen: "; cin >> s.ToanTX1 >> s.ToanTX2;
	cout << "Diem giua ki: "; cin >> s.ToanGK;
	cout << "Diem cuoi ki: "; cin >> s.ToanCK;
	s.ToanTB = s.ToanTX1*0.1 + s.ToanTX2*0.1 + s.ToanGK*0.3 + s.ToanCK*0.5;
	
	cout << "Mon Ngu Van:\n";
	cout << "Diem thuong xuyen: "; cin >> s.VanTX1 >> s.VanTX2;
	cout << "Diem giua ki: "; cin >> s.VanGK;
	cout << "Diem cuoi ki: "; cin >> s.VanCK;
	s.VanTB = s.VanTX1*0.1 + s.VanTX2*0.1 + s.VanGK*0.3 + s.VanCK*0.5;
	
	cout << "Mon Ngoai Ngu:\n";
	cout << "Diem thuong xuyen: "; cin >> s.NNTX1 >> s.NNTX2;
	cout << "Diem giua ki: "; cin >> s.NNGK;
	cout << "Diem cuoi ki: "; cin >> s.NNCK;
	s.NNTB = s.NNTX1*0.1 + s.NNTX2*0.1 + s.NNGK*0.3 + s.NNCK*0.5;
	
	cout << "Mon Giao Duc Cong Dan:\n";
	cout << "Diem thuong xuyen: "; cin >> s.GDCDTX1 >> s.GDCDTX2;
	cout << "Diem giua ki: "; cin >> s.GDCDGK;
	cout << "Diem cuoi ki: "; cin >> s.GDCDCK;
	s.GDCDTB = s.GDCDTX1*0.1 + s.GDCDTX2*0.1 + s.GDCDGK*0.3 + s.GDCDCK*0.5;
	
	cout << "Mon Lich Su:\n";
	cout << "Diem thuong xuyen: "; cin >> s.SuTX1 >> s.SuTX2;
	cout << "Diem giua ki: "; cin >> s.SuGK;
	cout << "Diem cuoi ki: "; cin >> s.SuCK;
	s.SuTB = s.SuTX1*0.1 + s.SuTX2*0.1 + s.SuGK*0.3 + s.SuCK*0.5;
	
	cout << "Mon Dia ly:\n";
	cout << "Diem thuong xuyen: "; cin >> s.DiaTX1 >> s.DiaTX2;
	cout << "Diem giua ki: "; cin >> s.DiaGK;
	cout << "Diem cuoi ki: "; cin >> s.DiaCK;
	s.DiaTB = s.DiaTX1*0.1 + s.DiaTX2*0.1 + s.DiaGK*0.3 + s.DiaCK*0.5;
	
	cout << "Mon Vat Ly:\n";
	cout << "Diem thuong xuyen: "; cin >> s.LiTX1 >> s.LiTX2;
	cout << "Diem giua ki: "; cin >> s.LiGK;
	cout << "Diem cuoi ki: "; cin >> s.LiCK;
	s.LiTB = s.LiTX1*0.1 + s.LiTX2*0.1 + s.LiGK*0.3 + s.LiCK*0.5;
	
	cout << "Mon Hoa Hoc:\n";
	cout << "Diem thuong xuyen: "; cin >> s.HoaTX1 >> s.HoaTX2;
	cout << "Diem giua ki: "; cin >> s.HoaGK;
	cout << "Diem cuoi ki: "; cin >> s.HoaCK;
	s.HoaTB = s.HoaTX1*0.1 + s.HoaTX2*0.1 + s.HoaGK*0.3 + s.HoaCK*0.5;
	
	cout << "Mon Sinh Hoc:\n";
	cout << "Diem thuong xuyen: "; cin >> s.SinhTX1 >> s.SinhTX2;
	cout << "Diem giua ki: "; cin >> s.SinhGK;
	cout << "Diem cuoi ki: "; cin >> s.SinhCK;
	s.SinhTB = s.SinhTX1*0.1 + s.SinhTX2*0.1 + s.SinhGK*0.3 + s.SinhCK*0.5;
	
	cout << "Mon Cong Nghe:\n";
	cout << "Diem thuong xuyen: "; cin >> s.CNTX1 >> s.CNTX2;
	cout << "Diem giua ki: "; cin >> s.CNGK;
	cout << "Diem cuoi ki: "; cin >> s.CNCK;
	s.CNTB = s.CNTX1*0.1 + s.CNTX2*0.1 + s.CNGK*0.3 + s.CNCK*0.5;
	
	cout << "Mon Tin Hoc:\n";
	cout << "Diem thuong xuyen: "; cin >> s.TinTX1 >> s.TinTX2;
	cout << "Diem giua ki: "; cin >> s.TinGK;
	cout << "Diem cuoi ki: "; cin >> s.TinCK;
	s.TinTB = s.TinTX1*0.1 + s.TinTX2*0.1 + s.TinGK*0.3 + s.TinCK*0.5;
	
	cout << "Mon The Duc:\n";
	cout << "Neu hoc sinh Dat -> Nhap: Dat";
	cout << "Neu hoc sinh khong Dat -> Nhap: Khong Dat";
	string theduc;
	cin.ignore(); getline(cin, theduc);
	chuanhoa(theduc); s.Theduc = theduc;
	
	cout << "Mon Nghe Thuat:\n";
	cout << "Neu hoc sinh Dat -> Nhap: Dat";
	cout << "Neu hoc sinh khong Dat -> Nhap: Khong Dat";
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
		if(a.HanhKiem == Tot){
			if(dem3 >= 1 && dem4 == 0){
				a.loai = Kha;
				cout << "Hoc sinh kha";
			}
			else if(dem4 >= 1){
				a.loai = Trung Binh;
				cout << "Hoc sinh trung binh"
			}
			else if(dem5 >= 1){
				a.loai == Yeu;
				cout << "Hoc sinh yeu";
			}
			else{
				if(a.Nghethuat == Dat && a.Theduc == Dat){
					if(a.ToanTB >= 8 || a.VanTB >= 8 || a.NNTB >= 8){
						a.loai = Gioi;
						cout << "Hoc sinh gioi";
					}
					else {
						a.loai = Kha;
						cout << "Hoc sinh kha";
					}
				} 
				else {
					a.loai = Kha;
					cout << "Hoc sinh kha";
				}
			}
		}
		else if(a.HanhKiem == Yeu){
			a.loai = Khong Qua;
			cout << "Hoc sinh dup";
		}
		else {
			a.loai = Kha;
			cout << "Hoc sinh kha";
		}
	}
	
	// dieu kien hoc sinh kha
	else if( 6 <= a.TBmon < 8){
		if(a.HanhKiem == Yeu){
			a.loai = Khong Qua;
			cout << "Hoc sinh dup";
		}
		else {
			if(dem4 >= 1){
				a.loai = Trung Binh;
				cout << "Hoc sinh trung binh";
			}
			else if(dem5 >= 1){
				a.loai == Yeu;
				cout << "Hoc sinh yeu";
			}
			else{
				if(a.Nghethuat != Dat || a.Theduc != Dat){
					a.loai = Trung Binh;
					cout << "Hoc sinh trung binh";
				}
				else if(a.Nghethuat == Dat && a.Theduc == Dat){
					if(a.ToanTB >= 6.5 || a.VanTB >= 6.5 || a.NNTB >= 6.5){
						a.loai = Kha;
						cout << "Hoc sinh kha";
					}
					else {
						a.loai = Trung Binh;
						cout << "Hoc sinh trung binh";
					}
				}
			}
		}
	}
	
	// dieu kien hoc sinh trung binh 
	else if( 5 <= a.TBmon < 6.5){
		if(a.HanhKiem == Yeu){
			a.loai = Khong Qua;
			cout << "Hoc sinh dup";
		}
		else {
			if(dem5 >= 1){
				a.loai = Yeu;
				cout << "Hoc sinh yeu";
			}
			else{
				if(a.Nghethuat != Dat || a.Theduc != Dat){
					a.loai = Yeu;
					cout << "Hoc sinh yeu";
				}
				else if(a.Nghethuat == Dat && a.Theduc == Dat){
					if(a.ToanTB >= 5 || a.VanTB >= 5 || a.NNTB >= 5){
						a.loai = Trung Binh;
						cout << "Hoc sinh trung binh";
					}
					else {
						a.loai = Yeu;
						cout << "Hoc sinh yeu";
					}
				}
			}
		}
	}
	
	// dieu kien hoc sinh yeu
	else if(a.TBmon < 3.5){
		a.loai == Yeu;
		cout << "Hoc sinh yeu";
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


// duyet 1 hoc sinh
void duyeths(Student s)
{
	cout << "Khoi lop: " << s.khoilop << endl;
	cout << "Ho Ten: " << s.name << endl;
	cout << "STT theo ds lop: " << s.stt << endl;
	cout << "Hanh kiem: " << s.HanhKiem << endl;
	cout << "Diem cac mon hoc:\n";
	cout << "Mon Toan: " << s.ToanTX1 << " " << s.ToanTX2 << " " << s.ToanGK << " " << s.ToanCK << " " << s.ToanTB << endl;
	cout << "Mon Ngu Van: " << s.VanTX1 << " " << s.VanTX2 << " " << s.VanGK << " " << s.VanCK << " " << s.VanTB << endl;
	cout << "Mon Ngoai Ngu: " << s.NNTX1 << " " << s.NNTX2 << " " << s.NNGK << " " << s.NNCK << " " << s.NNTB << endl;
	cout << "Mon Giao duc cong dan: " << s.GDCDTX1 << " " << s.GDCDTX2 << " " << s.GDCDGK << " " << s.GDCDCK << " " << s.GDCDTB << endl;
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
void duyetds(hs a)
{
	int n = Sizehs(a);
	for (int i = 0; i < n; i++)
	{
		duyeths(a->s);
		a = a->next;
	}
	cout << endl;
}

// duyet ds hoc sinh theo khoi lop
void duyetdskhoi(hs a, int x){
	int n = Sizehs(a);
	for (int i = 0; i < n; i++)
	{
		if(a->s.khoilop == x){
			duyeths(a->s);
		}
		a = a->next;
	}
	cout << endl;
} 


// tim kiem hoc sinh co khoi lop cho truoc
void findhs1(hs a, int x)
{
	hs p = a;
	Student as = p->s;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++)
	{
		p = p->next;
		if (as.khoilop == x)
		{
			duyeths(p->s);
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
			duyeths(p->s);
		}
	}
}

// tim kiem hoc sinh theo ten
void findhs3(hs a, string nem){
	hs p = a;
	Student as = p->s;
	int n = Sizehs(a);
	for (int i = 0; i < n; i++)
	{
		p = p->next;
		if (as.name == nem)
		{
			duyeths(p->s);
		}
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


// xoa hoc sinh co ten cho truoc
void deletehs2(hs &h, string nem){
	int n = Sizehs(h);
	hs p = h;
	hs q = NULL;
	for(int i = 0 ; i < n ; i++){
		if(p->s.name != nem){
			q = p;
			p = p->next;
		} else{
			q->next = p->next;
		break;
		}
	}
}


// sua thong tin hoc sinh 


// thong ke hoc sinh

void thongke(hs a){
	hs p = a;
	while(p->next != NULL){
		
		if(a.loai == Gioi) ++dem1;
		if(a.loai == Kha) ++dem2;
		if(a.loai == Trung Binh) ++dem3;
		if(a.loai == Yeu) ++dem4;
		if(a.loai == Khong Qua) ++dem5;
		
		
	}
}


// thong ke hoc sinh theo khoi lop 


// menu


int main()
{
	hs head = NULL;
	while (1)
	{
		cout << "Menu\n";
		cout << "1.Bo sung sinh vien x vao dau danh sach\n";
		cout << "2.Bo sung sinh vien x vao giua danh sach, truoc phan tu node duoc tro boi p \n";
		cout << "3.Bo sung sinh vien x vao giua danh sach, sau phan tu node duoc tro boi p \n";
		cout << "4.Tim kiem sinh vien co ma so sinh vien cho truoc \n";
		cout << "5.Tim kiem sinh vien o truoc sinh vien duoc tro boi p\n";
		cout << "6.Bo sung sinh vien vao sau sinh vien co ma so sinh vien cho truoc\n";
		cout << "7.Xoa sinh vien duoc tro boi p";
		cout << "8.Xoa sinh vien o truoc sinh vien duoc tro boi p\n";
		cout << "9.Xoa sinh vien o sau sinh vien duoc tro boi p\n";
		cout << "10.Tim mon hoc cua sinh vien co ma so mon hoc cho truoc\n";
		cout << "11.Bo sung mon hoc moi\n";
		cout << "12.Loai bo mon hoc co ma mon cho truoc\n";
		cout << "0.Thoat\n";
		int lc;
		cout << "Nhap lua chon: ";
		cin >> lc;
		if (lc == 0)
		{
			return 0;
		}
		else if (lc == 1)
		{
			insertfirst(head);
		}
		else if (lc == 2)
		{
			int pos;
			cout << "Nhap vi tri can bo sung:";
			cin >> pos;
			insertmiddle1(head, pos);
		}
		else if (lc == 3)
		{
			int pos;
			cout << "Nhap vi tri can bo sung:";
			cin >> pos;
			insertmiddle2(head, pos);
		}
		else if (lc == 4)
		{
			long ms;
			cout << "Nhap mssv cua sinh vien can tim: ";
			cin >> ms;
			findsv(head, ms);
		}
		else if (lc == 5)
		{
			long vt;
			cout << "Nhap vi tri p: ";
			cin >> vt;
			findsvq(head, vt);
		}
		else if (lc == 6)
		{
			long mss;
			cout << "Nhap ma so sinh vien can tro: ";
			cin >> mss;
			insertsv(head, mss);
		}
		else if (lc == 7)
		{
			int vt1;
			cout << "Nhap vi tri can xoa: ";
			cin >> vt1;
			deletesv(head, vt1);
		}
		else if (lc == 8)
		{
			int vt2;
			cout << "Nhap vi tri can tro: ";
			cin >> vt2;
			deletesvtruoc(head, vt2);
		}
		else if (lc == 9)
		{
			int vt3;
			cout << "Nhap vi tri can tro: ";
			cin >> vt3;
			deletesvsau(head, vt3);
		}
		else if (lc == 10)
		{
			string msmh;
			cout << "Nhap ma so mon hoc can tim: ";
			getline(cin, msmh);
			findhp(head1, msmh);
		}
		else if (lc == 11)
		{
			inserthp(head1);
			sapxep(head1);
		}
		else if (lc == 12)
		{
			string msmh1;
			cout << "Nhap ma so cua mon hoc can xoa: ";
			getline(cin, msmh1);
			deletehp(head1, msmh1);
		}
	}
}
