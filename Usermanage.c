#include<stdio.h>
#include<string.h>
#include"student_system.h"
int userManagement(){
	int choice;
	while(1){
		printf("================用户管理=================\n");
		printf("#####################################\n");
		printf("##           1.修改登录密码        ##\n");
		printf("##           2.返回主菜单          ##\n");
		printf("#####################################\n");
		printf("请选择（1-2）：");
		scanf("%d",&choice);
		clean_input_buffer();
		switch(choice){
			case 1:
				redact_password();
				break;
			case 2:
				mainMenu();
                return 0;
			default:
				printf("输入错误！请输入1-3！\n");
		}
	}
	return 0;
}
int login(){
	int i;
	char user_name[20],user_password[20];
	printf("========================================\n");
	printf("               登录页面                 \n");
	printf("========================================\n");
	FILE *fp;
	if((fp=fopen("user.txt","r"))==NULL){
		printf("不能打开用户信息文件！登录失败！\n");
		return 0;
	}
	for(i=5;i>0;i--){
		printf("请输入用户名：");
		scanf("%19s",user_name);
		printf("请输入密码:");
		scanf("%19s",user_password);
		rewind(fp);
		struct User temp_user; 
		while(fscanf(fp,"%s%s",temp_user.username,temp_user.password)==2){
			if(strcmp(temp_user.username,user_name)==0&&strcmp(temp_user.password,user_password)==0){
				if(fclose(fp))
					printf("不能关闭文件!\n");
				return 1;
			}
		}
		printf("用户名或密码错误\n");
		printf("还有%d次机会\n",i-1);
	}
	printf("登录失败！\n");
	if(fclose(fp))
		printf("不能关闭文件!\n");
	return 0;
}
int redact_password(){
	char old_password[20],user_name[20],new_password[20],confirm_password[20];
	struct User user[MAX_USER_LEN];
	printf("====================修改密码======================\n");
	int i=5,flag=1,count=0,found=0; 
	FILE *fp;
	if((fp=fopen("user.txt","r"))==NULL){
		printf("不能打开用户信息文件！修改失败！\n");
		return 0;
	} 
	printf("请输入用户名：");
	scanf("%s",user_name);
	struct User temp_user;
	while(fscanf(fp,"%s%s",temp_user.username,temp_user.password)==2){
		if(strcmp(user_name,temp_user.username)==0){
			flag=0;
			for(;i>0;i--){
				printf("请输入旧密码:");
				scanf("%s",old_password);
				clean_input_buffer();
				if(strcmp(old_password,temp_user.password)==0){
					do{
						printf("请输入新密码：");
						scanf("%s",new_password);
						clean_input_buffer();
						printf("请确认新密码：");
						scanf("%s",confirm_password);
						if(strcmp(new_password,confirm_password)!=0)
							printf("两次输入密码不一致！请重新输入！\n");
					}while(strcmp(new_password,confirm_password)!=0);
					strcpy(temp_user.password,new_password);
					found=1;
					break;
				}
				printf("旧密码错误！还有%d次机会！\n",i-1);
			}
		}
		strcpy(user[count].username,temp_user.username);
		strcpy(user[count].password,temp_user.password);
		count++;	
	}
	if(flag==0&&found==0) 
		printf("密码验证失败！\n");
	if(fclose(fp))
		printf("不能关闭文件!\n");
	if((fp=fopen("user.txt","w"))==NULL)
		printf("错误！不能保存文件！\n");
	for(i=0;i<count&&fp;i++){
		fprintf(fp,"%s %s\n",user[i].username,user[i].password);
	}
	if(flag){
		printf("未查询到该用户信息！\n");
		return 0;
	}
	if(flag==0&&found==1&&fp)
		printf("修改成功！成功保存数据！\n");
	if(found==0&&fp)
		printf("修改失败！成功保存原文件！\n");
	if(fp)
		if(fclose(fp))
			printf("不能关闭文件!\n");	
	return 0;
}

