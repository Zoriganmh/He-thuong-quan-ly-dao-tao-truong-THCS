#include <bits/stdc++.h>
using namespace std;

struct Hocphan{
	string mshp;
	string nameHP;
	int soTin;
	float TSQT, TSCK;
};

struct HP{
	Hocphan a;
	HP *next;
};

struct diemHocphan{
	float MSHK;
	float diemQT, diemCK;
	string mshp;
};

struct diemHP{
	diemHocphan h;
	diemHP *next;
};

struct Student{
	long mssv;
	string nameSV;
	float gpa;
	diemHP* k;
};
 
struct SV{
	Student s;
	SV *next;
};

typedef struct diemHP* dhp;
typedef struct HP* hp;
typedef struct SV* sv;


// khoi tao sinh vien 
sv makesv(){
	Student s;
	cout << "Nhap thong tin sinh vien:\n";
	cout << "Nhap ma so:"; cin >> s.mssv;
	cout << "Nhap ten sinh vien:"; cin.ignore();
	getline(cin, s.nameSV);
	cout << "Nhap gpa:"; cin >> s.gpa;
	int n;
	cout << "So hoc phan da hoc:"; cin >> n;
	dhp head1 = new diemHP();
	head1->next = NULL;
	for(int i = 0; i < n; i++){
		dhp moi = head1;
		moi->next = head1;
		head1 = moi;
		cout << "Nhap diem hoc phan: \n";
		cout << "Hoc ky:"; cin >> s.k->h.MSHK;
		cout << "Ma so hoc phan:" ; cin.ignore();
		getline(cin, s.k->h.mshp);
		cout << "Diem qua trinh:"; cin >> s.k->h.diemQT ;
		cout << "Diem cuoi ky:"; cin >> s.k->h.diemCK;
		head1->h = s.k->h;
	}
	sv tmp = new SV();
	tmp->s = s;
	tmp->next = NULL;
}

// kiem tra danh sach rong
bool empty(sv a){
	return a == NULL;
}

// bo sung sinh vien x vao dau danh sach
void insertfirst(sv &a){
	sv tmp = makesv();
	if(a == NULL){
		a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}

// khoi tao hoc phan
hp makehp(){
	Hocphan a;
	cout << "Nhap thong tin hoc phan: \n";
	cout << "So tin chi hoc phan: "; cin >> a.soTin;
	cout << "Ten hoc phan: "; cin.ignore();
	getline(cin, a.nameHP);
	cout << "Ma so hoc phan: "; cin.ignore();
	getline(cin, a.mshp);
	cout << "Trong so qua trinh: "; cin >> a.TSQT;
	cout << "Trong so cuoi ki: "; cin >> a.TSCK;
	hp tmp = new HP();
	tmp->a = a;
	tmp->next = NULL;
}

// bo sung hoc phan moi vao dau danh sach
void inserthp(hp &a){
	hp tmp = makehp();
	if(a == NULL){
		a = tmp;
	}
	else{
		tmp->next = a;
		a = tmp;
	}
}

// dem so hoc phan
int Sizehp(hp a){
	int dem = 0;
	while(a != NULL){
		++dem;
		a = a->next;
	}
	return dem;
}

// bo sung hoc phan moi vao sau mon hoc co ma so cho truoc
void inserthpmoi(hp &a, string x){
	hp p = a;
	Hocphan as = p->a;
	int n = Sizehp(a);
	for(int i = 0 ; i < n ; i++){
		if(as.mshp != x){
			p = p->next;
		} else{
		break;
		}
	}
	hp tmp = makehp();
	tmp->next = p->next;
	p->next = tmp;
}

// xoa mon hoc co ma mon cho truoc
void deletehp(hp h, string ms){
	int n = Sizehp(h);
	hp p = h;
	hp q = NULL;
	for(int i = 0 ; i < n ; i++){
		if(p->a.mshp != ms){
			q = p;
			p = p->next;
		} else{
		q->next = p->next;
		}
	}
}

// sap xep cac mon hoc theo thu tu tang dan cua so tin chi
void sapxep(hp &h){
	hp p = h;
	for(p; p->next = NULL; p = p->next){
		hp min = p;
		for(hp q = p->next; q != NULL ; q = q->next){
			if(q->a.soTin < min->a.soTin){
				min = q;
			}
		}
		int tmp = min->a.soTin;
		min->a = p->a;
		p->a.soTin = tmp;
	}
}

// dem so phan tu
int Sizesv(sv a){
	int dem = 0;
	while(a != NULL){
		++dem;
		a = a->next;
	}
	return dem;
}

// dem so hoc phan da hoc cua 1 sinh vien
int Sizedhp(Student a){
	int dem = 0;
	dhp tmp = a.k;
	while(tmp != 0){
		++dem;
		tmp = tmp->next;
	}
	return dem;
}

// bo sung sinh vien x vao giua danh sach, truoc phan tu node duoc tro boi p
void insertmiddle1(sv &a, int pos){
	int n = Sizesv(a);
	if(pos <= 0){
		cout << "khong hop le"; return;
	}
	else if(pos == 1){
		insertfirst(a); return;
	}
	sv q = NULL;
	sv p = a;
	for(int i = 1; i <= pos - 1; i++){
		q = p;
		p=p->next;
	}
	sv tmp = makesv();
	tmp->next = q->next;
	q->next = tmp;
}

// bo sung sinh vien x vao giua danh sach, sau phan tu node duoc tro boi p
void insertmiddle2(sv &a, int pos){
	int n = Sizesv(a);
	if(pos <= 0){
		cout << "khong hop le"; return;
	}
	else if(pos == 1){
		insertfirst(a); return;
	}
	sv p = a;
	for(int i = 1; i < pos - 1; i++){
		p=p->next;
	}
	sv tmp = makesv();
	tmp->next = p->next;
	p->next = tmp;
}

// bo sung sinh vien vao sau sinh vien co ma so sinh vien cho truoc
void insertsv(sv &a, long x){
	sv p = a;
	Student as = p->s;
	int n = Sizesv(a);
	for(int i = 0 ; i < n ; i++){
		if(as.mssv != x){
			p = p->next;
		} else{
		break;
		}
	}
	sv tmp = makesv();
	tmp->next = p->next;
	p->next = tmp;
	}

// xoa sinh vien duoc tro boi con tro p
void deletesv(sv &a, int pos){
	if( pos <= 0 || pos > Sizesv(a)) return;
	sv q = NULL, p = a;
	for(int i = 1; i < pos ; i++){
		q = p;
		p = p->next;
	}
	if(q = NULL){
		a = a->next;
	}
	else {
		q->next = p->next;
	}
}

// xoa sinh vien o truoc sinh vien duoc tro boi p
void deletesvtruoc(sv&a, int pos){
	if( pos <= 0 || pos > Sizesv(a)) return;
	sv r = NULL, q = NULL, p = a;
	for(int i = 1; i < pos ; i++){
		r = q;
		q = p;
		p = p->next;
	}
	if(r = NULL){
		a = a->next;
	}
	else {
		r->next = q->next;
	}
}

// xoa sinh vien o sau sinh vien duoc tro boi p
void deletesvsau(sv&a, int pos){
	if( pos <= 0 || pos > Sizesv(a)) return;
	sv q = NULL, p = a;
	for(int i = 1; i < pos ; i++){
		p = p->next;
	}
	q = p->next;
	if(p = NULL){
		a = a->next;
	}
	else {
		p->next = q->next;
	}
}

// in 1 mon hoc 
void inhp(Hocphan a){
	cout << "MSHP: " << a.mshp << endl;
	cout << "Ten hoc phan: " << a.nameHP << endl;
	cout << "So tin hoc phan: " << a.soTin << endl;
	cout << "Trong so qua trinh: " << a.TSQT << endl;
	cout << "Trong so cuoi ki: " << a.TSCK << endl;
}

// in 1 sinh vien
void insv(Student s, int n){
	cout << "MSSV: " << s.mssv << endl;
	cout << "Ho Ten: " << s.nameSV << endl;
	cout << "GPA: " << s.gpa << endl;
	cout << "Danh sach hoc phan: \n";
	for(int i = 0; i < n ; i++){
		cout << "Ma so hoc ky: " << s.k->h.MSHK << endl;
		cout << "Ma so hoc phan: " << s.k->h.mshp << endl;
		cout << "Diem qua trinh: " << s.k->h.diemQT << endl;
		cout << "Diem cuoi ki: " << s.k->h.diemCK << endl;
		s.k = s.k->next;
	}
}

// in danh sach sinh vien
void inds(sv a){
	int n = Sizesv(a);
	int f = Sizedhp(a->s);
	for(int i = 0; i < n; i++){
		insv(a->s,f);
		a = a->next;
	}
	cout << endl;
}

// tim kiem sinh vien o truoc sinh vien duoc tro boi p va in sinh vien do ra man hinh
void findsvq(sv a, int pos){
	sv q = NULL, p = a;
	for(int i = 1; i < pos ; i++){
		q = p;
		p = p->next;
	}
	Student as = q->s;
	int f = Sizedhp(a->s);
	insv(q->s,f);
}

// tim kiem sinh vien bang mssv cho truoc va in sinh vien do ra man hinh 	
void findsv(sv a, long x){
	sv p = a;
	Student as = p->s;
	int n = Sizesv(a);
	for(int i = 0 ; i < n ; i++){
		if(as.mssv != x){
			p = p->next;
		} else{
		int f = Sizedhp(p->s);
		insv(p->s,f);
		break;
		}
	}
}

// tim mon hoc co ma so mon hoc cho truoc va in ra man hinh
void findhp(hp a, string x){
	hp p = a;
	Hocphan as = p->a;
	int n = Sizehp(a);
	for(int i = 0 ; i < n ; i++){
		if(as.mshp != x){
			p = p->next;
		} else{
		inhp(p->a);
		break;
		}
	}
}


int main(){
	sv head = NULL;
	hp head1 = NULL;
	while(1){
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
	int lc; cout << "Nhap lua chon: "; cin >> lc;
	if(lc == 0){
		return 0;
	}
	else if(lc == 1){
		insertfirst(head);
	}
	else if(lc == 2){
		int pos; cout << "Nhap vi tri can bo sung:"; cin >> pos;
		insertmiddle1(head,pos);
	}
	else if(lc == 3){
		int pos; cout << "Nhap vi tri can bo sung:"; cin >> pos;
		insertmiddle2(head,pos);
	}
	else if (lc == 4){
		long ms;
		cout << "Nhap mssv cua sinh vien can tim: "; cin >> ms;
		findsv(head,ms);
	}
	else if (lc == 5){
		long vt;
		cout << "Nhap vi tri p: "; cin >> vt;
		findsvq(head,vt);
	}
	else if (lc == 6){
		long mss;
		cout << "Nhap ma so sinh vien can tro: "; cin >> mss;
		insertsv(head,mss);
	}
	else if (lc == 7){
		int vt1;
		cout << "Nhap vi tri can xoa: "; cin >> vt1;
		deletesv(head,vt1);
	}
	else if (lc == 8){
		int vt2;
		cout << "Nhap vi tri can tro: "; cin >> vt2;
		deletesvtruoc(head,vt2);
	}
	else if (lc == 9){
		int vt3;
		cout << "Nhap vi tri can tro: "; cin >> vt3;
		deletesvsau(head,vt3);
	}
	else if (lc == 10){
		string msmh;
		cout << "Nhap ma so mon hoc can tim: ";
		getline(cin, msmh);
		findhp(head1,msmh);
	}
	else if (lc == 11){
		inserthp(head1);
		sapxep(head1);
	}
	else if(lc == 12){
		string msmh1;
		cout << "Nhap ma so cua mon hoc can xoa: ";
		getline(cin, msmh1);
		deletehp(head1,msmh1);
	}
  }
}


















