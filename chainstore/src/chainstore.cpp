	//로그인
	//본사 클래스 물건과 가맹점 관리
	//가맹점 클래스 주문 결재 발송
	//본사 물품등록 조회 삭제 수정 재고 파악 배송
	//본사 가맹점 등록 수정 삭제 조회
	//가맹점 가맹점 번호(본사에서 받기)
	//가맹점 지점명 점주이름 연락처 물품 주문내역 결제내역
#include <iostream>
#include <string>
using namespace std;

#include "Headquarters.h"
#include "franchisee.h"
#include "article.h"

int main() {

	int i,o=0,q=0,w=0;
	string adminID = "admin";
	string adminPASS = "1q2w3e4r!";
	string str,str1,str2;

	article a;
	Headquarters h;
	franchisee *f = new franchisee[100];

	while(1){
		cout << "1.로그인 2.가맹점 등록 3.종료" << endl;
		cout << "입력 : " ;
		cin >> i;
		if(i==1){
			cout << ">>로그인<<" << endl;
			cout << "ID : ";
			cin >> str;
			cout << "PASS : ";
			cin >> str1;
			if(str == adminID){
				if(str1 == adminPASS){
					cout << ">>로그인 완료<< " << endl;
					while(1){
						cout << "1.등록 2.삭제 3.조회 4.재고 확인 5.재고 등록 6.물품 배송 7.로그아웃" << endl;
						cout << "입력 : " ;
						cin >> i;
						if(i==1){
							cout << ">>가맹점 등록<<" << endl;
							//등록 신청이 온 가맹점이 있는지 확인 후 승인해줄것
							//등록 신청 전부 보여주고 그중에 골라서 승인
							for(int p=0; p<o; p++){
								if(false==f[p].tu()){
									f[p].print();
								}
							}
							cout << "뒤로가기 back 입력" << endl;
							cout << "등록 확인 할 가맹점 이름 입력 : ";
							cin >> str;

							if(str=="back"){
								cout << ">>뒤로가기<<" << endl;
							}
							else{
								for(int p=0; p<o; p++){
									f[p].ch(str);
								}
							}
						}
						else if(i==2){
							cout << ">>가맹점 삭제<<" << endl;
							//삭제 신청이 온 가맹점이 있는지 확인 후 승인해줄것
							//삭제 신청 리스트 전부 보여주고 그중에 골라서 삭제
							cout << "삭제 요청이 가맹점" << endl;
							cout << "뒤로 가기는 back 입력" << endl;
							for(int p=0; p<o; p++){
								f[p].print2();
							}
							cout << "가맹점 명 입력 : ";
							cin >> str;

							for(int p=0; p<o; p++){
								w=f[p].qq(str);
								if(w==1){
									break;
								}
							}
							if(w==1){
								for(int p=0; p<o; p++){
									if(f[p].ch2(str)){
										if(f[p].ch3()!=0){
											cout << "해당 가맹점에 물품이 남았습니다. 회수합니다." << endl;
											i=f[p].ch3();
											h.input(i);
											o=o-1;
										}
										q=1;
									}
									if(q==1){
										f[p]=f[p+1];
									}
								}
								if(q==0){
									cout << "해당하는 가맹점 명은 없습니다." << endl;
								}
								q=0;
							}
						}
						else if(i==3){
							cout << ">>가맹점 조회<<" << endl;
							cout << "가맹점 명 입력 : " ;
							cin >> str;
							for(int p=0; p<o; p++){
								if(str == f[p].ch4()){
									f[p].print1();
								}
							}
							//가맹점 명,사업자 번호, 대표자 이름 출력해주기
						}
						else if(i==4){
							cout << ">>재고 확인<<" << endl;
							cout << "재고 : " << h.output() << endl;
						}
						else if(i==5){
							cout << ">>재고 등록<<" << endl;
							cout << "입력 : ";
							cin >> i;
							h.input(i);
						}
						else if(i==6){
							cout << ">>물품 배송<<" << endl;
							cout << "가맹점 명 입력 : ";
							cin >> str;
							for(int p=0; p<o; p++){
								if(f[p].ch2(str)){
									cout << "보낼 물품 수량을 입력 : " ;
									cin >> i;
									if(i<=h.re()){
										f[p].ad(i); //보낸만큼 본사에서 수량 빼기
										h.ss(i);
									}
									else{
										cout << "보유 수량보다 많은 물품을 입력 하였습니다." << endl;
									}
								}
							}
							//if 해당 가맹점이 있다면 물건 몇개 보낼지 적어서 보내기
						}
						else if(i==7){
							cout << ">>로그아웃<<" << endl;
							break;
						}
						else{
							cout << ">>잘못된 입력<<" << endl;
						}
					}
				}
				else{
					cout << ">>비밀번호 오류<< " << endl;
				}
			}
			else{
				for(int p=0; p<o; p++){
					f[p].ch1(str,str1);
				}
			}

			//가맹점 로그인시에 가맹점 정보만 보여줄 것
		}
		else if(i==2){
			cout << ">>가맹점 등록<<" << endl;
			while(1){
				cout << "1.등록 2.상태확인 3.삭제요청 4.뒤로가기" << endl;
				cout << "입력 : ";
				cin >> i;
				if(i==1){
					cout << ">>등록<<" << endl;
					cout << "가맹점 명 입력 : " ;
					cin >> str;
					cout << "사업자 번호 입력 : ";
					cin >> str1;
					cout << "대표자 이름 입력 : ";
					cin >> str2;
					f[o].join(str,str1,str2);
					o++;
					// 아이디는 본사에서 만들어주고 상태확인 후 비밀번호 가맹점에서 설정
				}
				else if(i==2){
					cout << ">>상태확인<<" << endl;
					cout << "사업자 번호 입력 : ";
					cin >> str;
					for(int p=0; p<o; p++){
						f[p].check(str);
					}
					//본사에서 승인 완료 됬을시 본사에서 보내준 아이디,대표자 이름, 가맹점 명 보여줌
				}
				else if(i==3){
					cout << ">>삭제 요청<< " << endl;
					cout << "가맹점 명 입력 : " ;
					cin >> str;
					for(int p=0; p<o; p++){
						f[p].del(str);
					}
				}
				else if(i==4){
					cout << ">>뒤로가기<<" << endl;
					break;
				}
				else{
					cout << ">>잘못된 입력<<" << endl;
				}
			}
		}
		else if(i==3){
			cout << ">>종료<<" << endl;
			break;
		}
		else{
			cout << ">>잘못된 입력<<" << endl;
		}
	}

	return 0;
}
