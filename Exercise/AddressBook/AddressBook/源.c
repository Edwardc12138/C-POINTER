#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ContactInfo {
	char name[1024];
	char phone_number[1024];
} ContactInfo;

// 通讯录
typedef struct AddressBook {
	ContactInfo contact_info[1024];
	int size;
} AddressBook;

static AddressBook g_address_book;

// 打印全部联系人
void PrintAllContact() {
	printf("  共 %d 个联系人\n", g_address_book.size);
	for (int curr = 0; curr < g_address_book.size; ++curr) {
		ContactInfo *info = &g_address_book.contact_info[curr];
		printf("  [%4d] %s\n", curr, info->name);
	}
}

// 通讯录界面
void Menu() {
	printf("********************************\n");
	printf("*********** 通 讯 录 ***********\n");
	printf("********************************\n");
	PrintAllContact();
	printf("********************************\n");
	printf("**** 输入序号以查看详细信息 ****\n");
	printf("********************************\n");
	printf("** 10000 :新建 ** 10001 :搜索 **\n");
	printf("********************************\n");
	printf("** 10002 :清空 ** 10003 :退出 **\n");
	printf("********************************\n");
	printf("请输入: ");
}

// 查看联系人详细信息
void DetailInfo(int number) {
	system("cls");
	printf("********************************\n");
	printf("******** 联系人详细信息 ********\n");
	printf("********************************\n");
	ContactInfo *info = &g_address_book.contact_info[number];
	printf("  姓名: %s\n", info->name);
	printf("  电话: %s\n", info->phone_number);
	printf("********************************\n");
	printf("** 10000 :修改 ** 10001 :删除 **\n");
	printf("********************************\n");
	printf("********* 10002 :退出 **********\n");
	printf("********************************\n");
	printf("请输入: ");
	int chiose;
	scanf("%d", &chiose);
	while (chiose < 0 ||
		(chiose >= g_address_book.size && chiose < 10000) ||
		chiose > 10002) {
		printf("输入非法!请重输: ");
		scanf("%d", &chiose);
	}
	if (chiose == 10002) {
		return;
	}
}

// 新建联系人
void AddContact() {
	system("cls");
	if (g_address_book.size >= 1024) {
		printf("********************************\n");
		printf("******* 新增未能成功执行 *******\n");
		printf("********************************\n");
		system("pause");
		return;
	}
	ContactInfo *info = &g_address_book.contact_info[g_address_book.size];
	printf("********************************\n");
	printf("********** 新建联系人 **********\n");
	printf("********************************\n");
	printf("  姓名: ");
	scanf("%s", info->name);
	printf("  电话: ");
	scanf("%s", info->phone_number);
	printf("********************************\n");
	printf("*********** 新增成功 ***********\n");
	printf("********************************\n");
	++g_address_book.size;
	system("pause");
}

// 搜索联系人
void SearchContact() {
	system("cls");
	printf("********************************\n");
	printf("********** 搜索联系人 **********\n");
	printf("********************************\n");
	printf("请输入姓名: ");
	char name[1024] = { 0 };
	scanf("%s", name);
	printf("********************************\n");
	int count = 0;
	for (int curr = 0; curr < g_address_book.size; ++curr) {	// 打印所有匹配姓名的信息
		ContactInfo *info = &g_address_book.contact_info[curr];
		if (strcmp(info->name, name) == 0) {
			printf("  [%4d] %s\t%s\n", curr, info->name, info->phone_number);
			++count;
		}
	}
	printf("  共找到 %d 个联系人\n", count);
	printf("********************************\n");
	printf("**** 输入序号以查看详细信息 ****\n");
	printf("********************************\n");
	printf("********* 10000 :退出 **********\n");
	printf("********************************\n");
	printf("请输入: ");
	int chiose;
	scanf("%d", &chiose);
	while (chiose < 0 ||
		(chiose >= g_address_book.size && chiose != 10000)) {
		printf("输入非法!请重输: ");
		scanf("%d", &chiose);
	}
	if (chiose != 10000) {
		DetailInfo(chiose);	// 联系人详细信息
	}
	return;
}

int main() {
	void(*pfunc[3])() = { AddContact, SearchContact};

	while (1) {
		system("cls");
		// 开始界面
		Menu();
		int chiose;
		scanf("%d", &chiose);
		while (chiose < 0 ||
			   (chiose >= g_address_book.size && chiose < 10000) ||
			   chiose > 10003) {
			printf("输入非法!请重输: ");
			scanf("%d", &chiose);
		}
		if (chiose == 10003) {	// 退出
			break;
		}
		else if ((chiose - 10000) >= 0) {	// 功能
			(*pfunc[chiose % 10])();
		}
		else {
			DetailInfo(chiose);	// 联系人详细信息
		}
	}

	system("pause");
	return 0;
}