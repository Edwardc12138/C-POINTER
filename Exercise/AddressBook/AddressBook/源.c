#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// ��ϵ����Ϣ
typedef struct ContactInfo {
	char name[1024];
	char phone_number[1024];
} ContactInfo;

// ͨѶ¼
typedef struct AddressBook {
	ContactInfo *contact_info;
	int size;
	int cap;
} AddressBook;

static AddressBook g_address_book;

// ��ӡȫ����ϵ��
void PrintAllContact() {
	printf("  �� %d ����ϵ��\n", g_address_book.size);
	for (int curr = 0; curr < g_address_book.size; ++curr) {
		ContactInfo *info = &g_address_book.contact_info[curr];
		printf("  [%4d] %s\n", curr, info->name);
	}
	if (g_address_book.size != 0) {
		printf("********************************\n");
		printf("**** ��������Բ鿴��ϸ��Ϣ ****\n");
	}
	printf("********************************\n");
}

// ͨѶ¼����
void Menu() {
	printf("********************************\n");
	printf("*********** ͨ Ѷ ¼ ***********\n");
	printf("********************************\n");
	PrintAllContact();
	printf("** 10000 :�½� ** 10001 :���� **\n");
	printf("********************************\n");
	printf("** 10002 :��� ** 10003 :�˳� **\n");
	printf("********************************\n");
	printf("������: ");
}

// �޸���ϵ����Ϣ
int UpdateContactInfo(int number) {
	system("cls");
	printf("********************************\n");
	printf("******** �޸���ϵ����Ϣ ********\n");
	printf("********************************\n");
	printf("****** ���� '/' �������� *******\n");
	printf("********************************\n");
	ContactInfo *info = &g_address_book.contact_info[number];
	char tmp_info[1024] = { 0 };
	setbuf(stdin, NULL);
	printf("  ����(%s): ", info->name);
	gets(tmp_info);
	if (tmp_info[0] != '/') {
		strcpy(info->name, tmp_info);
	}
	printf("  �绰(%s): ", info->phone_number);
	gets(tmp_info);
	if (tmp_info[0] != '/') {
		strcpy(info->phone_number, tmp_info);
	}
	printf("********************************\n");
	printf("*********** �޸ĳɹ� ***********\n");
	printf("********************************\n");
	system("pause");
	return 0;
}

// ɾ����ϵ��
int DeleteContact(int number) {
	printf("********************************\n");
	printf("****** ȷ��Ҫɾ������ϵ�� ******\n");
	printf("********************************\n");
	printf("****** / Y / ****** / N / ******\n");
	printf("********************************\n");
	printf("������: ");
	setbuf(stdin, NULL);
	char chiose = getchar();
	setbuf(stdin, NULL);	// ���û�����,��ջ�����
	if (chiose == 'Y' || chiose == 'y') {	// ��Сд����
		//g_address_book.contact_info[number] = g_address_book.contact_info[g_address_book.size - 1];
		//--g_address_book.size;
		// ����Ԫ��number֮���Ԫ����ǰ�ƶ�
		ContactInfo *info = g_address_book.contact_info;
		for (int curr = number; curr < g_address_book.size - 1; ++curr) {
			info[curr] = info[curr + 1];
		}
		--g_address_book.size;
		printf("********************************\n");
		printf("*********** ɾ���ɹ� ***********\n");
		printf("********************************\n");
		system("pause");
		return 1;
	}
	return 0;	// ȡ��ɾ��,���䶼��Ϊɾ��ʧ��
}

// �鿴��ϵ����ϸ��Ϣ
void DetailInfo(int number) {
	int(*pfunc[2])(int num) = { UpdateContactInfo, DeleteContact };
	while (1) {
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
		while (scanf("%d", &chiose) == 0 || chiose < 10000 || chiose > 10002) {
			setbuf(stdin, NULL);	// ��ջ�����
			printf("����Ƿ�!������: ");
		}
		if (chiose == 10002) {
			break;
		}
		else if ((*pfunc[chiose - 10000])(number)) {
			break;	// ɾ����ϵ�˺��˳���������
		}
	}
}

// ��������ϵ������
void SortContact() {
	ContactInfo *info = g_address_book.contact_info;
	ContactInfo tmp_info = info[g_address_book.size - 1];	// ���һ��Ԫ��
	int curr = g_address_book.size - 1;		// ���һ��Ԫ��λ��
	for (; curr > 0; --curr) {
		if (strcmp(info[curr - 1].name, tmp_info.name) > 0) {	// ǰһ��Ԫ�رȴ�����Ԫ�ش�
			info[curr] = info[curr - 1];	// ǰһ��Ԫ�غ���
		}
		else {
			info[curr] = tmp_info;		// ����,�����������ڵ�ǰλ��
			break;
		}
	}
	if (curr == 0) {		// ѭ������,������Ԫ�ر�����Ԫ�ض�С
		info[curr] = tmp_info;
	}
}

// �½���ϵ��
void AddContact() {
	system("cls");
	//if (g_address_book.size >= 1024) {
	//	printf("********************************\n");
	//	printf("******* ����δ�ܳɹ�ִ�� *******\n");
	//	printf("********************************\n");
	//	system("pause");
	//	return;
	//}
	if (g_address_book.size >= g_address_book.cap) {	// �ڴ�ռ�����
														// ���������ڴ�ռ�
		g_address_book.contact_info =
			(ContactInfo *)realloc(g_address_book.contact_info, 2 * g_address_book.size * sizeof(ContactInfo));
		// �޸�����
		g_address_book.cap = 2 * g_address_book.size;
	}
	ContactInfo *info = &g_address_book.contact_info[g_address_book.size];
	printf("********************************\n");
	printf("********** �½���ϵ�� **********\n");
	printf("********************************\n");
	printf("  ����: ");
	setbuf(stdin, NULL);
	gets(info->name);
	printf("  �绰: ");
	gets(info->phone_number);
	printf("********************************\n");
	printf("*********** �����ɹ� ***********\n");
	printf("********************************\n");
	++g_address_book.size;
	SortContact();
	system("pause");
}

// ������ϵ��
void SearchContact() {
	if (g_address_book.size == 0) {
		printf("********************************\n");
		printf("********** ͨѶ¼Ϊ�� **********\n");
		printf("********************************\n");
		system("pause");
		return;
	}
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
	if (count != 0) {
		printf("********************************\n");
		printf("**** ��������Բ鿴��ϸ��Ϣ ****\n");
	}
	printf("********************************\n");
	printf("********* 10000 :�˳� **********\n");
	printf("********************************\n");
	printf("������: ");
	int chiose;
	while (scanf("%d", &chiose) == 0 || chiose < 0 ||
		(chiose >= g_address_book.size && chiose != 10000)) {
		setbuf(stdin, NULL);	// ��ջ�����
		printf("����Ƿ�!������: ");
	}
	if (chiose != 10000) {
		DetailInfo(chiose);	// ��ϵ����ϸ��Ϣ
	}
	return;
}

// �����ϵ��
void ClearAllContact() {
	if (g_address_book.size == 0) {
		printf("********************************\n");
		printf("********** ͨѶ¼Ϊ�� **********\n");
		printf("********************************\n");
		system("pause");
		return;
	}
	printf("********************************\n");
	printf("******* ȷ��Ҫ�����ϵ�� *******\n");
	printf("********************************\n");
	printf("****** / Y / ****** / N / ******\n");
	printf("********************************\n");
	printf("������: ");
	setbuf(stdin, NULL);
	char chiose = getchar();
	setbuf(stdin, NULL);	// ���û�����,��ջ�����
	if (chiose == 'Y' || chiose == 'y') {	// ��Сд����
		g_address_book.size = 0;
		printf("********************************\n");
		printf("*********** ��ճɹ� ***********\n");
		printf("********************************\n");
		system("pause");
	}
	// ȡ��,���䶼��Ϊʧ��
}

// ȥ��������ϵ���Ƕ���Ļ��з�
char * DelWrap(char *str) {
	if (str == NULL) {
		return NULL;
	}
	int len = strlen(str);
	str[len - 1] = str[len];
	return str;
}

// ������ϵ��
void loadContactInfo() {
	// ���ļ�
	FILE *fp = fopen("../contactinfo.txt", "r");
	if (fp == NULL) {	// �п�
		printf("%s\n", strerror(errno));
		system("pause");
		return;
	}
	char buf[1024] = { 0 };	// ���뻺��
	while (fgets(buf,1024,fp) != NULL) {
		if (g_address_book.size >= g_address_book.cap) {	// �ڴ�ռ�����
			// ���������ڴ�ռ�
			g_address_book.contact_info = 
				(ContactInfo *)realloc(g_address_book.contact_info, 2 * g_address_book.size * sizeof(ContactInfo));
			// �޸�����
			g_address_book.cap = 2 * g_address_book.size;
		}
		ContactInfo *info = &g_address_book.contact_info[g_address_book.size];
		strcpy(info->name, DelWrap(buf));
		++g_address_book.size;
		if (fgets(buf, 1024, fp) != NULL) {
			strcpy(info->phone_number, DelWrap(buf));
		}
	}
	// �ر��ļ�
	fclose(fp);
}

// ������ϵ����Ϣ
void SaveContactInfo() {
	// ���ļ�
	FILE *fp = fopen("../contactinfo.txt", "w");
	if (fp == NULL) {	// �п�
		printf("%s\n", strerror(errno));
		system("pause");
		return;
	}
	// �����ݱ��浽�ļ���
	for (int curr = 0; curr < g_address_book.size; ++curr) {
		ContactInfo *info = &g_address_book.contact_info[curr];
		fprintf(fp, "%s\n", info->name);
		fprintf(fp, "%s\n", info->phone_number);
	}
	// �ر��ļ�
	fclose(fp);
}

// ��ʼ��
void Init() {
	// ��ʼ����ϵ������Ϊ64��
	g_address_book.contact_info = (ContactInfo *)malloc(64 * sizeof(ContactInfo));
	g_address_book.size = 0;
	g_address_book.cap = 64;
	loadContactInfo();	// �������е���ϵ��
}

int main() {
	void(*pfunc[3])() = { AddContact, SearchContact, ClearAllContact };
	Init();

	while (1) {
		system("cls");
		// ��ʼ����
		Menu();
		int chiose;
		while (scanf("%d", &chiose) == 0 || chiose < 0 ||
			   (chiose >= g_address_book.size && chiose < 10000) ||
			   chiose > 10003) {
			setbuf(stdin, NULL);	// ��ջ�����
			printf("����Ƿ�!������: ");
		}
		if (chiose == 10003) {	// �˳�
			SaveContactInfo();
			free(g_address_book.contact_info);
			break;
		}
		else if ((chiose - 10000) >= 0) {	// ����
			(*pfunc[chiose - 10000])();
		}
		else {
			DetailInfo(chiose);	// ��ϵ����ϸ��Ϣ
		}
	}

	system("pause");
	return 0;
}