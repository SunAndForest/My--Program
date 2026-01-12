#include<stdio.h>
#include<string.h>
#include"student_system.h"
int browseRecords(struct student *head){
	int choice;
	while(1){
		printf("===========================查询菜单=============================\n");
		printf("==                      1.按姓名查询                          ==\n");
		printf("==                      2.按学号查询                          ==\n");
		printf("==                      3.按班级查询                          ==\n");
		printf("==                      4.按课程查询                          ==\n");
		printf("==                      5.浏览全部记录                        ==\n");
		printf("==                      6.返回主菜单                          ==\n");
		printf("================================================================\n");
		printf("请选择1-6：");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				namebrowse(head);
				break;
			case 2:
				numbrowse(head);
				break;
			case 3:
				bjbrowse(head);
				break;
			case 4:
				kcbrowse(head);
				break;
			case 5:
				allbrowse(head);
				break;
			case 6:
				mainMenu();
				return 0;
			default:
				printf("警告！输入错误！请输入1-6...\n");
		}
	}
	return 0;
}
int namebrowse(struct student *head){
	char student_name[20];
	struct student *current=head;
	int flag=1;
	printf("请输入要查询学生的名字：");
	scanf("%19s",student_name);
	while(current!=NULL){
		if(strcmp(student_name,current->name)==0){
			printf("班级:%s\n",current->bj);
			printf("该学生的成绩为：\n");
			printf("c语言 大学英语 思想政治 高等数学 数据结构 数据库原理 总分 名次\n");
			printf("%d\t%d\t%d\t%d\t%d\t  %d\t     %d\t%d\n",
			current->score[0],current->score[1],current->score[2],current->score[3],current->score[4],current->score[5],current->sum,current->no);
			flag=0;
			break;
		}
		current=current->next;
	}
	if(flag) 
		printf("未查询到该学生成绩！请检查姓名是否输入正确！\n");
	return 0;
}
int numbrowse(struct student *head){
	char student_num[20];
	int flag=1;
	struct student *current=head;
	printf("请输入要查询的学号：");
	scanf("%19s",student_num);
	while(current!=NULL){
		if(strcmp(student_num,current->num)==0){
			printf("姓名：%s\t班级：%s\n成绩：\n",current->name,current->bj);
			printf("c语言 大学英语 思想政治 高等数学 数据结构 数据库原理 总分 名次\n");
			printf("%d\t%d\t%d\t%d\t  %d\t     %d\t%d\t%d\n",
			current->score[0],current->score[1],current->score[2],current->score[3],current->score[4],current->score[5],current->sum,current->no);
			flag=0;
			break;	
		}
		current=current->next;
	}
	if(flag)
		printf("未查询到该学号信息！\n");
	return 0;
}
int bjbrowse(struct student *head){
	char student_class[20];
	int flag=1;
	struct student *current=head;
	printf("请输入要查询的班级:");
	scanf("%19s",student_class);
	printf("学号 姓名 c语言 大学英语 思想政治 高等数学 数据结构 数据库原理 总分 名次\n");
	while(current!=0){
		if(strcmp(student_class,current->bj)==0){
			printf("%s  %s %d\t%d\t%d\t%d\t  %d\t     %d\t%d\n",current->num,current->name,
			current->score[0],current->score[1],current->score[2],current->score[3],current->score[4],current->score[5],current->sum,current->no);
			flag=0;
		}
		current=current->next;
	}
	if(flag)
		printf("未查询到该班级信息！\n");
	return 0;
}
int kcbrowse(struct student *head){
	char coursenames[6][20]={"c语言","大学英语","思想政治","高等数学","数据结构","数据库原理"};
	char student_course[20];
	int flag=1,count=0,i;
	float pass=0,average=0;
	struct student *current=head;
	printf("请输入要查询的课程：");
	scanf("%s",student_course);
	for(i=0;i<6;i++){
		if(strcmp(student_course,coursenames[i])==0){
			flag=0;
			break;
	    }
	}
	if(flag){
		printf("未查询到该课程信息！\n");
		return 0;
	}
	printf("学号 姓名 %s\n",student_course);
	while(current!=NULL){
		printf("%s %s %d\n",current->num,current->name,current->score[i]);
		count++;
		if(current->score[i]>=60)
			pass++;
		average+=current->score[i];
		current=current->next;
	}
	average/=count;
	pass=pass/count*100;
	printf("%s平均分为:%.2f,及格率为:%.2f%%\n",student_course,average,pass);
	return 0;
}
int allbrowse(struct student *head){
	struct student *current=head;
	int count=0,i,j;
	while(current!=NULL){
		count++;
		current=current->next;
	}
	current=head;
	struct student *array[count],*temp;
	for(i=0;i<count;i++){
		array[i]=current;
		current=current->next;
	}
	for(i=0;i<count-1;i++){
		for(j=0;j<count-1-i;j++){
			if(array[j]->no>array[j+1]->no){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;	
			}
		}
	}
	printf("学号 姓名 班级 c语言 大学英语 思想政治 高等数学 数据结构 数据库原理 总分 平均分 名次\n"); 
	for(i=0;i<count;i++){
		printf("%s %s %s %d\t%d\t%d\t%d\t%d\t  %d\t     %d\t%.2f\t%d\n",
		array[i]->num,array[i]->name,array[i]->bj,
		array[i]->score[0],array[i]->score[1],array[i]->score[2],
		array[i]->score[3],array[i]->score[4],array[i]->score[5],
		array[i]->sum,array[i]->ave,array[i]->no);
	}
	return 0;
}
