# 学生成绩管理系统

## 项目简介
一个用C语言开发的学生成绩管理系统，包含完整的增删改查功能。

## 功能特点
- 学生信息录入与保存
- 成绩查询与修改
- 数据文件存储
- 用户权限管理

## 文件说明
- `main.c` - 主程序
- `student_system.h` - 头文件
- `Browser.c` - 浏览功能
- `Enter.c` - 录入功能
- `Func.c` - 功能模块
- `Modify.c` - 修改功能
- `Usermanage.c` - 用户管理
- `student.txt` - 学生数据
- `user.txt` - 用户数据

## 使用方法
```bash
gcc main.c Browser.c Enter.c Func.c Modify.c Usermanage.c -o student_system./student_system
