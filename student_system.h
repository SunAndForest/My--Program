#ifndef STUDENT_SYSTEM_H
#define STUDENT_SYSTEM_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_USER_LEN 200
#define MAX_NAME_LEN 20
#define MAX_ID_LEN 4
#define MAX_CLASS_LEN 20
struct student{
	char num[MAX_ID_LEN];
	char name[MAX_NAME_LEN];
	char bj[MAX_CLASS_LEN];
	int score[6];
	int sum;
	float ave;
	int no;
	struct student *next;
};
struct User{
	char username[20];
	char password[20];
};
struct student * loadFromFile();
void achievementRank(struct student *head);
void saveAndExit(struct student *head);
void freelist(struct student *head);
void clean_input_buffer();
int login();
int mainMenu();
int browseRecords(struct student *head);
int namebrowse(struct student *head);
int numbrowse(struct student *head);
int bjbrowse(struct student *head);
int kcbrowse(struct student *head);
int allbrowse(struct student *head);
int modifyRecords(struct student *head);
int num_modify(struct student *head);
int name_modify(struct student *head);
int userManagement();
int redact_password();
int enterRecords(struct student **head);
void addRecords(struct student **head);
void deleteRecords(struct student **head);
#endif
