#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<errno.h>
#include<malloc.h>
#define MAX_NAME 12
#define MAX_TEL 12
#define SIZE 500

//0. �˳�
//1. �����ϵ����Ϣ
//2. ɾ��ָ����ϵ����Ϣ
//3. ����ָ����ϵ����Ϣ
//4. �޸�ָ����ϵ����Ϣ
//5. ��ʾ������ϵ����Ϣ
//6. ���������ϵ��
//7. ����������������ϵ��
//8. ������ϵ�˵��ļ�
//9. ������ϵ��

int menu() {
	printf(" 1. �����ϵ����Ϣ\n");
	printf(" 2. ɾ��ָ����ϵ����Ϣ\n");
	printf(" 3. ����ָ����ϵ����Ϣ\n");
	printf(" 4. �޸�ָ����ϵ����Ϣ\n");
	printf(" 5. ��ʾ������ϵ����Ϣ\n");
	printf(" 6. ���������ϵ��\n");
	printf(" 7. ����������������ϵ��\n");
	printf(" 8. д���ļ�\n");
	printf(" 9. ��ȡ\n");
	printf(" 0. �˳�\n");
	printf(" Please select:");
	int choice;
	scanf("%d", &choice);
	return choice;
}

typedef struct Contact {
	//�绰+����
	char name[MAX_NAME];
	char telphone[MAX_TEL];
}Contact;

typedef struct Address_book {
	//ͨѶ¼��С+��Ч��ϵ�˸���
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
	/*FILE* ps = fopen("C:/Users/LB10000/Desktop/ͨѶ¼.txt", "r");
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
	FILE* ps = fopen("C:/Users/LB10000/Desktop/ͨѶ¼.txt", "a+");
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
	//  ��ʾ
	
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
	//���
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
		printf("Can I go ahead and add?\n1  ����\nother  ����\n");
		scanf("%d", &n);
	}
	system("cls");
}

void Del_Contact() {
	system("cls");
	//ɾ��
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
		printf("Can I go ahead and add?\n1  ����\nother  ����\n");
		scanf("%d", &n);
	}
	system("cls");
}

void Find_Contacts() {
	//����
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
	//�޸�
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
		printf("Can I go ahead and add?\n1  ����\nother  ����\n");
		scanf("%d", &n);
	}
	system("cls");
}

void Empty_Contacts() {
	//���
	system("cls");
	address_book.size = 0;
	printf("successful\n\n");
}

void Sort_Contacts() {
	//����
	system("cls");

	



	printf("successful\n\n");

}

void Preserving_Contacts() {
	//���浽�ļ�
	system("cls");
	FILE* ps = fopen("C:/Users/LB10000/Desktop/ͨѶ¼.txt", "at+");
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
			printf("see you��");
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