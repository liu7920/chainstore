#ifndef FRANCHISEE_H_
#define FRANCHISEE_H_

#include <iostream>
using namespace std;
#include "Headquarters.h"
#include "article.h"

class franchisee : public Headquarters{
	string ID; //id
	string PASS; //pass
	string business_number; //사업자 번호
	string representative; //대표자 이름
	string franchisee_name; //가맹점 명
	int de;
	int Quantity;
	bool b; // 승인 확인 여부
	int num;
public:
	franchisee(){
		this->ID=" ";
		this->PASS=" ";
		this->business_number=" ";
		this->representative=" ";
		this->franchisee_name=" ";
		this->b=false;
		this->Quantity=0;
		this->num=0;
		this->de=0;
	}
	void join(string str, string str1, string str2){ //가입 요청
		this->franchisee_name=str;
		this->business_number=str1;
		this->representative=str2;
	}
	void check(string str){

		if(business_number==str){
			cout << "ID : " << this->ID << endl;
			cout << "사업자 번호 : " << this->business_number << endl;
			cout << "대표자 이름 : " << this->representative << endl;
			cout << "가맹점 이름 : " << this->franchisee_name << endl;
			cout << "승인 여부 : " ;
			if(b==true){
				cout << "승인" << endl;
				if(num==0){
					num=1;
					cout << "비밀번호 설정 입력 : ";
					cin >> this->PASS;
				}
			}
			else if(b==false){
				cout << "승인 요청 중" << endl;
			}
		}
	}

	bool tu(){
		return b;
	}

	void print(){
		if(b==false){
			cout << "ID : " << this->ID << endl;
			cout << "사업자 번호 : " << this->business_number << endl;
			cout << "대표자 이름 : " << this->representative << endl;
			cout << "가맹점 이름 : " << this->franchisee_name << endl;
		}
	}

	void ch(string str){
		if(str==this->franchisee_name){
			cout << "가맹점 ID 설정 입력 : ";
			cin >> this->ID;
			this->b=true;
		}
	}

	void ch1(string str, string str1){
		if(this->ID==str && this->PASS==str1){
			cout << ">>로그인 성공<<" << endl;
			ran();
			cout << "현재 물품 수량 : " << this->Quantity << endl;
		}
	}

	int ch2(string str){
		if(this->franchisee_name==str){
			return 1;
		}
		return 0;
	}

	int ch3(){
		return this->Quantity;
	}

	void ad(int i){
		this->Quantity+=i;
	}

	string ch4(){
		return this->franchisee_name;
	}

	void print1(){
		cout << "ID : " << this->ID << endl;
		cout << "사업자 번호 : " << this->business_number << endl;
		cout << "가맹점 명 : "<< this->franchisee_name << endl;
		cout << "대표자 이름 : " << this->representative << endl;
	}

	void ran(){
		this->Quantity-=(rand()%10)+1;
		if(this->Quantity<0){
			this->Quantity=0;
		}
	}

	void del(string str){
		if(str==this->franchisee_name){
			this->de=1;
		}
	}

	void print2(){
		if(this->de==1){
			cout << "ID : " << this->ID << endl;
			cout << "사업자 번호 : " << this->business_number << endl;
			cout << "가맹점 명 : "<< this->franchisee_name << endl;
			cout << "대표자 이름 : " << this->representative << endl;
		}
	}

	int qq(string str){
		if(this->de==1 && this->franchisee_name==str){
			return 1;
		}
		return 0;
	}
	virtual ~franchisee();
};

#endif /* FRANCHISEE_H_ */
// 아이디는 본사에서 만들어주고 상태확인 후 비밀번호 가맹점에서 설정
//본사에서 승인 완료 됬을시 본사에서 보내준 아이디,대표자 이름, 가맹점 명 보여줌
