#include<stdio.h>
#include<string.h>
#include"student_system.h"
int modifyRecords(struct student *head){
	int choice;
	while(1){
		printf("==================菜单=================\n");
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf("@@             1.输入学号修改        @@\n");
		printf("@@             2.输入名字修改        @@\n");
		printf("@@             3.返回主菜单          @@\n");
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf("请选择1-3：");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				num_modify(head);
				break;
			case 2:
				name_modify(head);
				break;
			case 3:
				return 0;
			default:
				printf("输入错误!请输入1-3！\n");
		}
	}
	return 0;
} 
int num_modify(struct student *head){
	char coursenames[6][20]={"c语言","大学英语","思想政治","高等数学","数据结构","数据库原理"};
	char student_num[20],student_course[20];
	int flag=1,flag2=1,write,score,i,count,j;
	struct student *current=head;
	if(head==NULL)
		return 0;
	printf("请输入要修改的学生学号：");
	scanf("%s",student_num);
	clean_input_buffer(); 
	while(current!=NULL){
		if(strcmp(student_num,current->num)==0){
			printf("请输入要修改的科目数(1-6)：") ;
			scanf("%d",&count);
			for(j=0;j<count;j++){
			printf("请输入要修改的科目：");
			scanf("%s",student_course); 
			clean_input_buffer();
			for(i=0;i<6;i++)
				if(strcmp(student_course,coursenames[i])==0)
					break;
			if(i==6){
				printf("未找到该科目！请重新输入！\n");
				j--;
				continue;
			}
			printf("请输入修改后的分数：");
			scanf("%d",&score);
			current->score[i]=score;
			}
			current->sum=current->score[0]+current->score[1]+current->score[2]+current->score[3]+current->score[4]+current->score[5];
			current->ave=current->sum/6.0; 
			achievementRank(head); 
			flag=0;
			break;
		}
		current=current->next;
	}
	if(flag)
		printf("未查询到该学号学生信息！\n");
	FILE *fp;
		if((fp=fopen("student.txt","w"))==NULL){
			printf("打开文件失败！修改失败！\n");
			return 0;
		}
	current=head;
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
	if(flag2){
		printf("Succeed to save data!\n");
	}
	if(flag==0&&flag2)
		printf("修改成功！\n");
	if(fclose(fp))
		printf("Do not close the file!\n");
	return 0;
}
int name_modify(struct student *head){
	char coursenames[6][20]={"c语言","大学英语","思想政治","高等数学","数据结构","数据库原理"};
	char student_name[20],student_course[20];
	int flag=1,flag2=1,write,score,i,count,j;
	struct student *current=head;
	if(head==NULL)
		return 0;
	printf("请输入要修改的学生姓名：");
	scanf("%s",student_name);
	clean_input_buffer();
	while(current!=NULL){
		if(strcmp(student_name,current->name)==0){
			printf("请输入要修改的科目数(1-6)：") ;
			scanf("%d",&count);
			for(j=0;j<count;j++){
			printf("请输入要修改的科目：");
			scanf("%s",student_course); 
			clean_input_buffer();
			for(i=0;i<6;i++)
				if(strcmp(student_course,coursenames[i])==0)
					break;
			if(i==6){
				printf("未找到该科目！请重新输入！\n");
				j--;
				continue;
			}
			printf("请输入修改后的分数：");
			scanf("%d",&score);
			current->score[i]=score;
			}
			current->sum=current->score[0]+current->score[1]+current->score[2]+current->score[3]+current->score[4]+current->score[5];
			current->ave=current->sum/6.0; 
			achievementRank(head); 
			flag=0;
			break;
		}
		current=current->next;
	}
	if(flag)
		printf("未查询到该姓名学生信息！\n");
	FILE *fp;
		if((fp=fopen("student.txt","w"))==NULL){
			printf("打开文件失败！修改失败！\n");
			return 0;
		}
	current=head;
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
	if(flag2){
		printf("Succeed to save data!\n");
	}
	if(flag==0&&flag2)
		printf("修改成功！\n");
	if(fclose(fp))
		printf("Do not close the file!\n");
	return 0;
}
