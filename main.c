#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneNumberList {
	char name[10];
	char phoneNumber[20];
	struct phoneNumberList* next;
} List;

void removePerson(List* head) {
	printf("삭제할 이름: ");
	char name[10];
	scanf("%s", name);
	List* i;
	List* previousIndexBeforeRemove = head;
	for(i=head; i->next!=NULL; i=i->next) {
		if(strcmp(i->name, name) == 0) {
			break;
		}
		previousIndexBeforeRemove=i;
	}
	List* removeIndex=i;
	previousIndexBeforeRemove->next=removeIndex->next;
	
	free(removeIndex);
	
	printf("%s 정보 삭제 완료!\n", name);
}

int findPhoneNumberOfPerson(List* head) {
	printf("검색할 이름: ");
	char name[10];
	scanf("%s", name);
	List* i;
	for(i=head; i->next!=NULL; i=i->next) {
		if(strcmp(i->name, name) == 0) {
			printf("%s\t%s\n", i->name, i->phoneNumber);
			return 1;
		}
	}
	
	return 0;
}

void printPhoneNumberList(List* head) {
	printf(" <<전화번호목록>>\n");
	List* i;
	for(i=head; i->next!=NULL; i=i->next) {
		printf("%s\t%s\t%d\n", i->name, i->phoneNumber, i->next);
	}
}

void registerPhoneNumber(List* list)  {
	printf("등록할 이름 : ");
	scanf("%s", list->name);
	printf("전화번호 : ");
	scanf("%s", list->phoneNumber);
	printf("%s 정보 등록 완료!\n", list->name);
}

int is_checkPassword(char* rightPassword) {
	int is_continue=1;
	int wrongPasswordCount=0;
	enum exitCondition {
		samePassword=1,
		wrongPassword=2
	};
	int whatIsTheExit;
	printf("비밀번호: ");
	while(is_continue) {
		char password[20];
		scanf("%s", password);
		int is_samePassword=strcmp(rightPassword, password)==0;
		if(is_samePassword) {
			whatIsTheExit=samePassword;
			is_continue=0;
		}
		else {
			++wrongPasswordCount;
		}
		if(!is_samePassword && wrongPasswordCount<3) {
			printf("비밀번호(%d회실패): ", wrongPasswordCount);
		}
		if(wrongPasswordCount==3){
			printf("비밀번호(%d회실패): 등록할 수 없음!\n", wrongPasswordCount);
			whatIsTheExit=wrongPassword;
			is_continue=0;
		}
	}
	
	switch(whatIsTheExit) {
		case samePassword: {
			return 1;
			break;
		}
		case wrongPassword: {
			return 0;
			break;
		}
		default: {
			return 0;
			break;
		}
	}
}

int main() {
	List* p=NULL, * head=NULL, * tail=NULL;
	p=(List*)malloc(sizeof(List));
	p->next=NULL;
	head=p;
	tail=p;

	strcpy(p->name, "나태희");
	strcpy(p->phoneNumber, "010-5228-7889");
	p->next=(List*)malloc(sizeof(List));
	tail=p->next;
	p=tail;
	p->next=NULL;

	strcpy(p->name, "유현빈");
	strcpy(p->phoneNumber, "010-5211-1472");
	p->next=(List*)malloc(sizeof(List));
	tail=p->next;
	p=tail;
	p->next=NULL;

	strcpy(p->name, "나원빈");
	strcpy(p->phoneNumber, "010-1235-8765");
	p->next=(List*)malloc(sizeof(List));
	tail=p->next;
	p=tail;
	p->next=NULL;

	strcpy(p->name, "문건영");
	strcpy(p->phoneNumber, "010-8282-8282");
	p->next=(List*)malloc(sizeof(List));
	tail=p->next;
	p=tail;
	p->next=NULL;
	
	
	
	char rightPassword[]="qwer1234";
	int is_continue=1;
	while(is_continue) {
		printf("전화번호 관리\n\n");
		printf("1. 등록[Tab] 2. 전체검색[Tab] 3. 특정인검색[Tab] 4. 제거[Tab] 5. 종료\n\n");
		printf("메뉴 선택: ");
	
		int menu;
		scanf("%d", &menu);
		switch(menu) {
			case 1: {
				printPhoneNumberList(head);
				printf("\n");
				if(is_checkPassword(rightPassword)==1) {
					registerPhoneNumber(p);
					p->next=(List*)malloc(sizeof(List));
					tail=p->next;
					p=tail;
					p->next=NULL;
				}
				else {
					printf("프로그램을 종료합니다.\n");
					is_continue=0;
				}
				break;
			}
			case 2: {
				printPhoneNumberList(head);
				break;
			}
			case 3: {
				findPhoneNumberOfPerson(head);
				break;
			}
			case 4: {
				removePerson(head);
				break;
			}
			case 5: {
				printf("프로그램을 종료합니다.\n");
				is_continue=0;
				break;
			}
			default: {
				break;
			}
		}
		printf("\n");
	}
	
}
