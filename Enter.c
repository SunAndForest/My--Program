#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"student_system.h"
int enterRecords(struct student **head){
	int choice;
	while(1){
		printf("================菜单=================\n");
		printf("+++++++++++++++++++++++++++++++++++++\n");
		printf("++         1.增加学生记录          ++\n");
		printf("++         2.删除学生记录          ++\n");
		printf("++         3.返回主菜单            ++\n");
		printf("+++++++++++++++++++++++++++++++++++++\n");
		printf("请选择（1-3）：");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				addRecords(head);
				break;
			case 2:
				deleteRecords(head);
				break;
			case 3:
				mainMenu();
				return 0;
			default:
				printf("输入错误！请输入（1-3）！\n");
		}
	}
	return 0;
}
void addRecords(struct student **head){
	int count,i;
	printf("请输入要添加学生记录的个数：");
	scanf("%d",&count);
	for(i=0;i<count;i++){
		struct student *newcode=(struct student *)malloc(sizeof(struct student));
		printf("请输入学生信息（学号 姓名 班级 c语言 大学英语 思想政治 高等数学 数据结构 数据库原理 ）：");
		scanf("%s%s%s%d%d%d%d%d%d",newcode->num,newcode->name,newcode->bj,
		&newcode->score[0],&newcode->score[1],&newcode->score[2],&newcode->score[3],&newcode->score[4],&newcode->score[5]);
		newcode->sum=newcode->score[0]+newcode->score[1]+newcode->score[2]+newcode->score[3]+newcode->score[4]+newcode->score[5];
		newcode->ave=newcode->sum/6.0;
		newcode->next=*head;
		*head=newcode;
	}
	achievementRank(*head);
		FILE *fp;
	if((fp=fopen("student.txt","w"))==NULL){
		printf("Do not open the file to write!\n");
		printf("添加失败！\n");
		}
	printf("正在保存数据......\n");
	struct student *current=*head;
	int write,flag2=1;
	while(current){
		current->sum=current->score[0]+current->score[1]+current->score[2]+current->score[3]+current->score[4]+current->score[5];
		current->ave=current->sum/6.0;
		write=fprintf(fp,"%s %s %s %d %d %d %d %d %d %d %.2f %d\n",current->num,current->name,current->bj,
		current->score[0],current->score[1],current->score[2],current->score[3],current->score[4],current->score[5],
		current->sum,current->ave,current->no);
		if(write<0){
			printf("%s写入文件失败！\n",current->name);
			flag2=0;
		}
		current=current->next;
	}
	if(flag2)
		printf("Succeed to save data!\n");
	if(flag2==1&&fp)
		printf("添加记录成功！\n");
	if(fclose(fp))
		printf("Do not close the file!\n");
}
void deleteRecords(struct student **head){
	char student_name[20];
	int count,i,flag;
	struct student *preceding,*current,*temp;
	printf("请输入要删除学生的个数：");
	scanf("%d",&count);
	for(i=0;i<count;i++){
		flag=1;
		preceding=*head,current=preceding->next;
		printf("请输入要删除学生的名字：");
		scanf("%s",student_name);
		if(strcmp(preceding->name,student_name)==0){
			temp=preceding;
			*head=(*head)->next;
			free(temp);
			flag=0;
			continue;
		}
		
			while(current!=NULL){
				if(strcmp(current->name,student_name)==0){
					preceding->next=current->next;
					temp=current;
					current=current->next;
					free(temp);
					flag=0;
					break;
				}
				else{
					preceding=current;
					current=current->next;
				}
			}
		if(flag)
			printf("未找到该学生！\n");
		if(!flag)
			printf("成功删除%s!\n",student_name);
	}
	achievementRank(*head);
		FILE *fp;
	if((fp=fopen("student.txt","w"))==NULL){
		printf("Do not open the file to write!\n");
		printf("删除失败！\n");
		}
	printf("正在保存数据......\n");
	current=*head;
	int write,flag2=1;
	while(current){
		write=fprintf(fp,"%s %s %s %d %d %d %d %d %d %d %.2f %d\n",current->num,current->name,current->bj,
		current->score[0],current->score[1],current->score[2],current->score[3],current->score[4],current->score[5],
		current->sum,current->ave,current->no);
		if(write<0){
			printf("%s写入文件失败！\n",current->name);
			flag2=0;
		}
		current=current->next;
	}
	if(flag2)
		printf("Succeed to save data!\n");
	if(flag==0&&flag2==1&&fp)
		printf("删除记录成功！\n");
	if(fclose(fp))
		printf("Do not close the file!\n");
}
