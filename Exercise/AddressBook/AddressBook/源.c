#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ContactInfo {
	char name[1024];
	char phone_number[1024];
} ContactInfo;

// ͨѶ¼
typedef struct AddressBook {
	ContactInfo contact_info[1024];
	int size;
} AddressBook;

static AddressBook g_address_book;

// ��ӡȫ����ϵ��
void PrintAllContact() {
	printf("  �� %d ����ϵ��\n", g_address_book.size);
	for (int curr = 0; curr < g_address_book.size; ++curr) {
		ContactInfo *info = &g_address_book.contact_info[curr];
		printf("  [%4d] %s\n", curr, info->name);
	}
}

// ͨѶ¼����
void Menu() {
	printf("********************************\n");
	printf("*********** ͨ Ѷ ¼ ***********\n");
	printf("********************************\n");
	PrintAllContact();
	printf("********************************\n");
	printf("**** ��������Բ鿴��ϸ��Ϣ ****\n");
	printf("********************************\n");
	printf("** 10000 :�½� ** 10001 :���� **\n");
	printf("********************************\n");
	printf("** 10002 :��� ** 10003 :�˳� **\n");
	printf("********************************\n");
	printf("������: ");
}

// �鿴��ϵ����ϸ��Ϣ
void DetailInfo(int number) {
	system("cls");
	printf("********************************\n");
	printf("******** ��ϵ����ϸ��Ϣ ********\n");
	printf("********************************\n");
	ContactInfo *info = &g_address_book.contact_info[number];
	printf("  ����: %s\n", info->name);
	printf("  �绰: %s\n", info->phone_number);
	printf("********************************\n");
	printf("** 10000 :�޸� ** 10001 :ɾ�� **\n");
	printf("********************************\n");
	printf("********* 10002 :�˳� **********\n");
	printf("********************************\n");
	printf("������: ");
	int chiose;
	scanf("%d", &chiose);
	while (chiose < 0 ||
		(chiose >= g_address_book.size && chiose < 10000) ||
		chiose > 10002) {
		printf("����Ƿ�!������: ");
		scanf("%d", &chiose);
	}
	if (chiose == 10002) {
		return;
	}
}

// �½���ϵ��
void AddContact() {
	system("cls");
	if (g_address_book.size >= 1024) {
		printf("********************************\n");
		printf("******* ����δ�ܳɹ�ִ�� *******\n");
		printf("********************************\n");
		system("pause");
		return;
	}
	ContactInfo *info = &g_address_book.contact_info[g_address_book.size];
	printf("********************************\n");
	printf("********** �½���ϵ�� **********\n");
	printf("********************************\n");
	printf("  ����: ");
	scanf("%s", info->name);
	printf("  �绰: ");
	scanf("%s", info->phone_number);
	printf("********************************\n");
	printf("*********** �����ɹ� ***********\n");
	printf("********************************\n");
	++g_address_book.size;
	system("pause");
}

// ������ϵ��
void SearchContact() {
	system("cls");
	printf("********************************\n");
	printf("********** ������ϵ�� **********\n");
	printf("********************************\n");
	printf("����������: ");
	char name[1024] = { 0 };
	scanf("%s", name);
	printf("********************************\n");
	int count = 0;
	for (int curr = 0; curr < g_address_book.size; ++curr) {	// ��ӡ����ƥ����������Ϣ
		ContactInfo *info = &g_address_book.contact_info[curr];
		if (strcmp(info->name, name) == 0) {
			printf("  [%4d] %s\t%s\n", curr, info->name, info->phone_number);
			++count;
		}
	}
	printf("  ���ҵ� %d ����ϵ��\n", count);
	printf("********************************\n");
	printf("**** ��������Բ鿴��ϸ��Ϣ ****\n");
	printf("********************************\n");
	printf("********* 10000 :�˳� **********\n");
	printf("********************************\n");
	printf("������: ");
	int chiose;
	scanf("%d", &chiose);
	while (chiose < 0 ||
		(chiose >= g_address_book.size && chiose != 10000)) {
		printf("����Ƿ�!������: ");
		scanf("%d", &chiose);
	}
	if (chiose != 10000) {
		DetailInfo(chiose);	// ��ϵ����ϸ��Ϣ
	}
	return;
}

int main() {
	void(*pfunc[3])() = { AddContact, SearchContact};

	while (1) {
		system("cls");
		// ��ʼ����
		Menu();
		int chiose;
		scanf("%d", &chiose);
		while (chiose < 0 ||
			   (chiose >= g_address_book.size && chiose < 10000) ||
			   chiose > 10003) {
			printf("����Ƿ�!������: ");
			scanf("%d", &chiose);
		}
		if (chiose == 10003) {	// �˳�
			break;
		}
		else if ((chiose - 10000) >= 0) {	// ����
			(*pfunc[chiose % 10])();
		}
		else {
			DetailInfo(chiose);	// ��ϵ����ϸ��Ϣ
		}
	}

	system("pause");
	return 0;
}