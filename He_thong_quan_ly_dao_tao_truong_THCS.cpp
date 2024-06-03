#include <bits/stdc++.h>
using namespace std;

struct Student
{
	int khoilop;
	string name;
	long stt;
	string HanhKiem;
	float ToanTX1,ToanTX2,ToanGK,ToanCK,ToanTB;
	float VanTX1,VanTX2,VanGK,VanCK,VanTB;
	float NNTX1,NNTX2,NNGK,NNCK,NNTB;
	float GDCGTX1,GDCDTX2,GDCDGK,GDCDCK,GDCDTB;
	float SuTX1,SuTX2,SuGK,SuCK,SuTB;
	float DiaTX1,DiaTX2,DiaGK,DiaCK,DiaTB;
	float LiTX1,LiTX2,LiGK,LiCK,LiTB;
	float HoaTX1,HoaTX2,HoaGK,HoaCK,HoaTB;
	float SinhTX1,SinhTX2,SinhGK,SinhCK,SinhTB;
	float CNTX1,CNTX2,CNGK,CNCK,CNTB;
	float TinTX1,TinTX2,TinGK,TinCK,TinTB;
	string Theduc,Nghethuat;
	float TBmon;
};

struct HS
{
	Student s;
	HS *next;
};

typedef struct HS *hs;

// khoi tao sinh vien
hs makehs()
{
	Student s;
	cout << "Nhap thong tin hoc sinh:\n";
	cout << "Nhap khoi lop:"; cin >> s.khoilop;
	cout << "Nhap ten sinh vien:"; cin.ignore();
	getline(cin, s.name);
	cout << "Nhap STT hoc sinh:"; cin >> s.stt;
	cout << "Hanh kiem hoc sinh: \n"; 
	cout << "(Tot, Kha, Trung binh, Yeu";
	cin.ignore(); getline(cin, s.HanhKiem);
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
	cin.ignore(); getline(cin, s.Theduc);
	
	cout << "Mon Nghe Thuat:\n";
	cout << "Neu hoc sinh Dat -> Nhap: Dat";
	cout << "Neu hoc sinh khong Dat -> Nhap: Khong Dat";
	cin.ignore(); getline(cin, s.Nghethuat);
	
	s.TBmon = (s.ToanTB + s.VanTB + s.NNTB + s.GDCDTB + s.SuTB + s.DiaTB + s.LiTB + s.HoaTB + s.SinhTB + s.CNTB + s.TinTB) / 11;
	
	hs tmp = new HS();
	tmp->s = s;
	tmp->next = NULL;
}

// kiem tra danh sach rong
bool empty(hs a)
{
	return a == NULL;
}

// bo sung hoc sinh x vao dau danh sach
void insertfirst(hs &a)
{
	hs tmp = makesv();
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
		min->a = p->a;
		p->s.stt = tmp;
	}
}

// sap xep hoc sinh theo thu tu bang chu cai


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


// xoa hoc sinh co stt cho truoc 


// xoa hoc sinh co ten cho truoc


// thong ke hoc sinh theo hoc luc

// thong ke hoc sinh theo khoi lop


int main()
{
	sv head = NULL;
	hp head1 = NULL;
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
