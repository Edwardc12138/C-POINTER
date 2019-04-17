#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// 联系人信息
typedef struct ContactInfo {
	char name[1024];
	char phone_number[1024];
} ContactInfo;

// 通讯录
typedef struct AddressBook {
	ContactInfo *contact_info;
	int size;
	int cap;
} AddressBook;

static AddressBook g_address_book;

// 打印全部联系人
void PrintAllContact() {
	printf("  共 %d 个联系人\n", g_address_book.size);
	for (int curr = 0; curr < g_address_book.size; ++curr) {
		ContactInfo *info = &g_address_book.contact_info[curr];
		printf("  [%4d] %s\n", curr, info->name);
	}
	if (g_address_book.size != 0) {
		printf("********************************\n");
		printf("**** 输入序号以查看详细信息 ****\n");
	}
	printf("********************************\n");
}

// 通讯录界面
void Menu() {
	printf("********************************\n");
	printf("*********** 通 讯 录 ***********\n");
	printf("********************************\n");
	PrintAllContact();
	printf("** 10000 :新建 ** 10001 :搜索 **\n");
	printf("********************************\n");
	printf("** 10002 :清空 ** 10003 :退出 **\n");
	printf("********************************\n");
	printf("请输入: ");
}

// 修改联系人信息
int UpdateContactInfo(int number) {
	system("cls");
	printf("********************************\n");
	printf("******** 修改联系人信息 ********\n");
	printf("********************************\n");
	printf("****** 输入 '/' 跳过该项 *******\n");
	printf("********************************\n");
	ContactInfo *info = &g_address_book.contact_info[number];
	char tmp_info[1024] = { 0 };
	setbuf(stdin, NULL);
	printf("  姓名(%s): ", info->name);
	gets(tmp_info);
	if (tmp_info[0] != '/') {
		strcpy(info->name, tmp_info);
	}
	printf("  电话(%s): ", info->phone_number);
	gets(tmp_info);
	if (tmp_info[0] != '/') {
		strcpy(info->phone_number, tmp_info);
	}
	printf("********************************\n");
	printf("*********** 修改成功 ***********\n");
	printf("********************************\n");
	system("pause");
	return 0;
}

// 删除联系人
int DeleteContact(int number) {
	printf("********************************\n");
	printf("****** 确定要删除该联系人 ******\n");
	printf("********************************\n");
	printf("****** / Y / ****** / N / ******\n");
	printf("********************************\n");
	printf("请输入: ");
	setbuf(stdin, NULL);
	char chiose = getchar();
	setbuf(stdin, NULL);	// 怕用户乱输,清空缓冲区
	if (chiose == 'Y' || chiose == 'y') {	// 大小写均可
		//g_address_book.contact_info[number] = g_address_book.contact_info[g_address_book.size - 1];
		//--g_address_book.size;
		// 所有元素number之后的元素向前移动
		ContactInfo *info = g_address_book.contact_info;
		for (int curr = number; curr < g_address_book.size - 1; ++curr) {
			info[curr] = info[curr + 1];
		}
		--g_address_book.size;
		printf("********************************\n");
		printf("*********** 删除成功 ***********\n");
		printf("********************************\n");
		system("pause");
		return 1;
	}
	return 0;	// 取消删除,乱输都视为删除失败
}

// 查看联系人详细信息
void DetailInfo(int number) {
	int(*pfunc[2])(int num) = { UpdateContactInfo, DeleteContact };
	while (1) {
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
		while (scanf("%d", &chiose) == 0 || chiose < 10000 || chiose > 10002) {
			setbuf(stdin, NULL);	// 清空缓冲区
			printf("输入非法!请重输: ");
		}
		if (chiose == 10002) {
			break;
		}
		else if ((*pfunc[chiose - 10000])(number)) {
			break;	// 删除联系人后退出到主界面
		}
	}
}

// 对新增联系人排序
void SortContact() {
	ContactInfo *info = g_address_book.contact_info;
	ContactInfo tmp_info = info[g_address_book.size - 1];	// 最后一个元素
	int curr = g_address_book.size - 1;		// 最后一个元素位置
	for (; curr > 0; --curr) {
		if (strcmp(info[curr - 1].name, tmp_info.name) > 0) {	// 前一个元素比待排序元素大
			info[curr] = info[curr - 1];	// 前一个元素后移
		}
		else {
			info[curr] = tmp_info;		// 否则,待排序数就在当前位置
			break;
		}
	}
	if (curr == 0) {		// 循环结束,待排序元素比所有元素都小
		info[curr] = tmp_info;
	}
}

// 新建联系人
void AddContact() {
	system("cls");
	//if (g_address_book.size >= 1024) {
	//	printf("********************************\n");
	//	printf("******* 新增未能成功执行 *******\n");
	//	printf("********************************\n");
	//	system("pause");
	//	return;
	//}
	if (g_address_book.size >= g_address_book.cap) {	// 内存空间满了
														// 重新申请内存空间
		g_address_book.contact_info =
			(ContactInfo *)realloc(g_address_book.contact_info, 2 * g_address_book.size * sizeof(ContactInfo));
		// 修改容量
		g_address_book.cap = 2 * g_address_book.size;
	}
	ContactInfo *info = &g_address_book.contact_info[g_address_book.size];
	printf("********************************\n");
	printf("********** 新建联系人 **********\n");
	printf("********************************\n");
	printf("  姓名: ");
	setbuf(stdin, NULL);
	gets(info->name);
	printf("  电话: ");
	gets(info->phone_number);
	printf("********************************\n");
	printf("*********** 新增成功 ***********\n");
	printf("********************************\n");
	++g_address_book.size;
	SortContact();
	system("pause");
}

// 搜索联系人
void SearchContact() {
	if (g_address_book.size == 0) {
		printf("********************************\n");
		printf("********** 通讯录为空 **********\n");
		printf("********************************\n");
		system("pause");
		return;
	}
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
	if (count != 0) {
		printf("********************************\n");
		printf("**** 输入序号以查看详细信息 ****\n");
	}
	printf("********************************\n");
	printf("********* 10000 :退出 **********\n");
	printf("********************************\n");
	printf("请输入: ");
	int chiose;
	while (scanf("%d", &chiose) == 0 || chiose < 0 ||
		(chiose >= g_address_book.size && chiose != 10000)) {
		setbuf(stdin, NULL);	// 清空缓冲区
		printf("输入非法!请重输: ");
	}
	if (chiose != 10000) {
		DetailInfo(chiose);	// 联系人详细信息
	}
	return;
}

// 清空联系人
void ClearAllContact() {
	if (g_address_book.size == 0) {
		printf("********************************\n");
		printf("********** 通讯录为空 **********\n");
		printf("********************************\n");
		system("pause");
		return;
	}
	printf("********************************\n");
	printf("******* 确定要清空联系人 *******\n");
	printf("********************************\n");
	printf("****** / Y / ****** / N / ******\n");
	printf("********************************\n");
	printf("请输入: ");
	setbuf(stdin, NULL);
	char chiose = getchar();
	setbuf(stdin, NULL);	// 怕用户乱输,清空缓冲区
	if (chiose == 'Y' || chiose == 'y') {	// 大小写均可
		g_address_book.size = 0;
		printf("********************************\n");
		printf("*********** 清空成功 ***********\n");
		printf("********************************\n");
		system("pause");
	}
	// 取消,乱输都视为失败
}

// 去掉加载联系人是读入的换行符
char * DelWrap(char *str) {
	if (str == NULL) {
		return NULL;
	}
	int len = strlen(str);
	str[len - 1] = str[len];
	return str;
}

// 加载联系人
void loadContactInfo() {
	// 打开文件
	FILE *fp = fopen("../contactinfo.txt", "r");
	if (fp == NULL) {	// 判空
		printf("%s\n", strerror(errno));
		system("pause");
		return;
	}
	char buf[1024] = { 0 };	// 输入缓冲
	while (fgets(buf,1024,fp) != NULL) {
		if (g_address_book.size >= g_address_book.cap) {	// 内存空间满了
			// 重新申请内存空间
			g_address_book.contact_info = 
				(ContactInfo *)realloc(g_address_book.contact_info, 2 * g_address_book.size * sizeof(ContactInfo));
			// 修改容量
			g_address_book.cap = 2 * g_address_book.size;
		}
		ContactInfo *info = &g_address_book.contact_info[g_address_book.size];
		strcpy(info->name, DelWrap(buf));
		++g_address_book.size;
		if (fgets(buf, 1024, fp) != NULL) {
			strcpy(info->phone_number, DelWrap(buf));
		}
	}
	// 关闭文件
	fclose(fp);
}

// 保存联系人信息
void SaveContactInfo() {
	// 打开文件
	FILE *fp = fopen("../contactinfo.txt", "w");
	if (fp == NULL) {	// 判空
		printf("%s\n", strerror(errno));
		system("pause");
		return;
	}
	// 将数据保存到文件中
	for (int curr = 0; curr < g_address_book.size; ++curr) {
		ContactInfo *info = &g_address_book.contact_info[curr];
		fprintf(fp, "%s\n", info->name);
		fprintf(fp, "%s\n", info->phone_number);
	}
	// 关闭文件
	fclose(fp);
}

// 初始化
void Init() {
	// 初始化联系人上限为64人
	g_address_book.contact_info = (ContactInfo *)malloc(64 * sizeof(ContactInfo));
	g_address_book.size = 0;
	g_address_book.cap = 64;
	loadContactInfo();	// 加载已有的联系人
}

int main() {
	void(*pfunc[3])() = { AddContact, SearchContact, ClearAllContact };
	Init();

	while (1) {
		system("cls");
		// 开始界面
		Menu();
		int chiose;
		while (scanf("%d", &chiose) == 0 || chiose < 0 ||
			   (chiose >= g_address_book.size && chiose < 10000) ||
			   chiose > 10003) {
			setbuf(stdin, NULL);	// 清空缓冲区
			printf("输入非法!请重输: ");
		}
		if (chiose == 10003) {	// 退出
			SaveContactInfo();
			free(g_address_book.contact_info);
			break;
		}
		else if ((chiose - 10000) >= 0) {	// 功能
			(*pfunc[chiose - 10000])();
		}
		else {
			DetailInfo(chiose);	// 联系人详细信息
		}
	}

	system("pause");
	return 0;
}