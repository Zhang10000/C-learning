#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<errno.h>
#include<malloc.h>
#define MAX_NAME 12
#define MAX_TEL 12
#define SIZE 500

//0. 退出
//1. 添加联系人信息
//2. 删除指定联系人信息
//3. 查找指定联系人信息
//4. 修改指定联系人信息
//5. 显示所有联系人信息
//6. 清空所有联系人
//7. 以名字排序所有联系人
//8. 保存联系人到文件
//9. 加载联系人

int menu() {
	printf(" 1. 添加联系人信息\n");
	printf(" 2. 删除指定联系人信息\n");
	printf(" 3. 查找指定联系人信息\n");
	printf(" 4. 修改指定联系人信息\n");
	printf(" 5. 显示所有联系人信息\n");
	printf(" 6. 清空所有联系人\n");
	printf(" 7. 以名字排序所有联系人\n");
	printf(" 8. 写入文件\n");
	printf(" 9. 读取\n");
	printf(" 0. 退出\n");
	printf(" Please select:");
	int choice;
	scanf("%d", &choice);
	return choice;
}

typedef struct Contact {
	//电话+名字
	char name[MAX_NAME];
	char telphone[MAX_TEL];
}Contact;

typedef struct Address_book {
	//通讯录大小+有效联系人个数
	Contact contact[SIZE];
	int size;
}Address_book;

Address_book address_book;

void Init() {
	address_book.size = 0;
	for (int i = 0; i < SIZE; ++i) {
		address_book.contact[i].name[0] = '\0';
		address_book.contact[i].telphone[0] = '\0';
	}
	/*FILE* ps = fopen("C:/Users/LB10000/Desktop/通讯录.txt", "r");
	if (ps == NULL) {
		perror("fopen");
		return;
	}
	Contact con;
	fread(&con.name, 8, 1, ps);
	fread(&con.telphone, 11, 1, ps);
	fclose(ps);
	for (int i = 0; i < 3; ++i) {

	}*/
}

void ReadFile() {
	FILE* ps = fopen("C:/Users/LB10000/Desktop/通讯录.txt", "a+");
	if (ps == NULL) {
		perror("fopen");
		return;
	}
	//for (int i = 0; i < address_book.size; ++i) {
	//	fwrite(address_book.contact[i].name, 12, 1, ps);
	//	fwrite(address_book.contact[i].telphone, 12, 1, ps);
	//}
	fread(&address_book.size, 4, 1, ps);
	rewind(ps);
	int i = 0;
	for (int i = 0; i < address_book.size; ++i){
		fread(&address_book.contact[i].name, 12, 1, ps);
		fread(&address_book.contact[i].telphone, 12, 1, ps);
		++i;
		rewind(ps);
	}
	fclose(ps);
}

void Dis_Contacts() {
	system("cls");
	//  显示
	
	if (address_book.size == 0) {
		printf("No contact data\n\n");
		return;
	}

	for (int i = 0; i < address_book.size; ++i) {
		Contact* contact = &address_book.contact[i];
		printf("%d) %s\t%s\n", i, contact->name, contact->telphone);
	}
}

void Add_Contact() {
	system("cls");
	//添加
	int n = 1;
	while (n == 1) {
		printf("Add contacts\n");

		printf("Please enter the contact name:");
		Contact* contact = &address_book.contact[address_book.size];
		scanf("%s", contact->name);

		printf("Please enter the contact number:");
		scanf("%s", contact->telphone);

		++address_book.size;
		Dis_Contacts();
		printf("successful!\n\n");
		printf("Can I go ahead and add?\n1  继续\nother  结束\n");
		scanf("%d", &n);
	}
	system("cls");
}

void Del_Contact() {
	system("cls");
	//删除
	int n = 1;
	while (n == 1) {
		Dis_Contacts();
		if (address_book.size == 0) {
			printf("No contact data\n\n");
			return;
		}
		printf("Please enter the serial number of the contact to be deleted:");
		int id;
		scanf("%d", &id);
		if (id < 0 || id >= address_book.size) {
			printf("The corresponding contact could not be found\n\n");
			return;
		}
		address_book.contact[id] = address_book.contact[address_book.size - 1];
		--address_book.size;
		system("cls");
		Dis_Contacts();
		printf("successful\n\n");
		printf("Can I go ahead and add?\n1  继续\nother  结束\n");
		scanf("%d", &n);
	}
	system("cls");
}

void Find_Contacts() {
	//查找
	system("cls");
	Dis_Contacts();
	if (address_book.size == 0) {
		printf("No contact data\n\n");
		return;
	}
	printf("Enter the name of the contact you want to find:");
	char name[1024];
	scanf("%s", &name);
	for (int i = 0; i < address_book.size; ++i) {
		Contact* contact = &address_book.contact[i];
		if (strcmp(contact->name, name) == 0) {
			printf("%d) %s\t%s\n", i, contact->name, contact->telphone);
		}
	}
}

void Mod_Contacts() {
	//修改
	system("cls");
	if (address_book.size == 0) {
		printf("No contact data\n\n");
		return;
	}
	int n = 1;
	while (n == 1) {
		Dis_Contacts();
		printf("Enter the serial number you want to modify for the contact:");
		int id;
		scanf("%d", &id);
		if (id<0 || id>address_book.size - 1) {
			printf("Lose what!!!\n\n");
			return;
		}
		printf("Change the contact number to:");
		scanf("%s", &address_book.contact[id].telphone);
		system("cls");
		printf("\n");
		printf("successful\n\n");
		Dis_Contacts();
		printf("Can I go ahead and add?\n1  继续\nother  结束\n");
		scanf("%d", &n);
	}
	system("cls");
}

void Empty_Contacts() {
	//清空
	system("cls");
	address_book.size = 0;
	printf("successful\n\n");
}

void Sort_Contacts() {
	//排序
	system("cls");

	



	printf("successful\n\n");

}

void Preserving_Contacts() {
	//保存到文件
	system("cls");
	FILE* ps = fopen("C:/Users/LB10000/Desktop/通讯录.txt", "at+");
	if (ps == NULL) {
		perror("fopen");
		return;
	}
	fwrite(address_book.size, 4, 1, ps);
	rewind(ps);
	for (int i = 0; i < address_book.size; ++i) {
		fwrite(address_book.contact[i].name, 12, 1, ps);
		fwrite(address_book.contact[i].telphone, 12, 1, ps);
	}
	fclose(ps);
	printf("successful\n\n");
}

void null() {}

typedef void(*Fnuc)();

int main() {
	Init();
	Fnuc arr[] = {
		null,
		Add_Contact,
		Del_Contact,
		Find_Contacts,
		Mod_Contacts,
		Dis_Contacts,
		Empty_Contacts,
		Sort_Contacts,
		Preserving_Contacts,
		ReadFile
	};
	while (1) {
		int choice = menu();
		if (choice == 0) {
			printf("see you！");
			break;
		}
		if (choice < 0 || choice>9) {
			system("cls");
			printf("What the hell are you doing!!!\nagain!\n");
			continue;
		}
		arr[choice]();
	}
	
	system("pause");
	return 0;
}