#include<stdio.h>
#include"student_system.h"
int mainMenu(){
	struct student *head=loadFromFile();
	int choice;
	if(head==NULL){
		printf("警告！未加载到任何数据或加载失败！\n按回车退出系统！\n");
		return 0;
	}
	while(1){
	    printf("====================主菜单=====================\n");
	    printf("***********************************************\n");
		printf("**               1.查询记录                  **\n");
		printf("**               2.修改记录                  **\n");
		printf("**               3.增减记录                  **\n");
		printf("**               4.用户管理                  **\n");
		printf("**               5.退出系统                  **\n");
		printf("***********************************************\n");
		printf("请选择功能（1-5）:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				browseRecords(head);
				break;
			case 2:
				modifyRecords(head);
				break;
			case 3:
				enterRecords(&head);
				break;
			case 4:
				userManagement();
				break;
			case 5:
				saveAndExit(head);
			default:
				printf("无效选择，请选择1-5！\n");
		}
	}
	return 0;
}
struct student * loadFromFile(){
	FILE *fp;
	int count=0; 
	struct student *head=NULL;
	if((fp=fopen("student.txt","r"))==NULL){
		printf("Do not open the file!\n");
		return NULL;
	}
	printf("数据正在加载中......\n");
	while(1){
		struct student *newcode=(struct student *)malloc(sizeof(struct student));
		if(newcode==NULL){
			printf("Failed to allocate memory!\n");
		    freelist(head);
			if(fclose(fp))
		    	printf("Do not close the file!\n");
			return NULL;
		}
		int read;
		if((read=fscanf(fp,"%19s%19s%3s%d%d%d%d%d%d%d%f%d",newcode->num,newcode->name,newcode->bj,
		&newcode->score[0],&newcode->score[1],&newcode->score[2],&newcode->score[3],&newcode->score[4],&newcode->score[5],
		&newcode->sum,&newcode->ave,&newcode->no))==EOF){
			free(newcode);
			break;
		}
		else if(read!=12){
			printf("警告！读取错误！期望12字段，实际读取到%d字段！\n",read);
			free(newcode);
			int ch;
			while((ch=fgetc(fp))!='\n'&&ch!=EOF);
			continue;
		}
		newcode->sum=newcode->score[0]+newcode->score[1]+newcode->score[2]+newcode->score[3]+newcode->score[4]+newcode->score[5];
		newcode->ave=newcode->sum/6.0;
		newcode->next=head;
		head=newcode;
		count++;
	}
	printf("成功加载%d条学生记录\n",count);
    achievementRank(head);
	printf("排名计算已完成\n");
	if(fclose(fp))
		printf("Do not close the file!\n");
	return head;
}
void achievementRank(struct student *head){
	int rank;
	struct student *i,*j;
	for(i=head;i!=NULL;i=i->next){
		rank=1;
		for(j=head;j!=NULL;j=j->next)
			if(j->sum>i->sum)
				rank++;
		i->no=rank;
	}
}
void saveAndExit(struct student *head){
	FILE *fp;
	if((fp=fopen("student.txt","w"))==NULL){
		printf("Do not open the file to write!\n");
		printf("正在退出系统......\n");
		freelist(head);
		exit(EXIT_FAILURE);
	}
	printf("正在保存数据......\n");
	struct student *current=head;
	while(current){
		fprintf(fp,"%s %s %3s %d %d %d %d %d %d %d %.2f %d\n",current->num,current->name,current->bj,
		current->score[0],current->score[1],current->score[2],current->score[3],current->score[4],current->score[5],
		current->sum,current->ave,current->no);
		current=current->next;
	}
	printf("Succeed to save data!\n");
	if(fclose(fp))
		printf("Do not close the file!\n");
	printf("正在退出系统......\n");
	freelist(head);
	exit(EXIT_SUCCESS);
}
void freelist(struct student *head){
	struct student *current=head,*temp;
		while(current){
			temp=current;
			current=current->next;
			free(temp);
	    }
}
void clean_input_buffer(){
	int ch;
	while((ch=getchar())!='\n'&&ch!=EOF);
}
