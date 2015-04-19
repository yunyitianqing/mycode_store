#include"db.h"
#include<stdio.h>

//db for student key:number
//data: name,sex,age,source

int main()
{
	DB* mydb=db_open("../data/db_student",O_RDWR|O_CREAT|,FILE_MODE);
	if(DB==0)
	{
		printf("DB open error\n");
		exit(1);
	}
	if(db_store(mydb,"1205030206","peter\r\nman\r\n21\r\n85\r\n",DB_INSERT))
	{
		printf("store error\n");
		//exit(2);
	}
	if(db_store(mydb,"1205030207","angle\r\nwoman\r\n20\r\n90\r\n",DB_INSERT))
	{
		printf("store error\n");
		//exit(2);
	}
	char *student_output;
	student_out=putdb_fetch(mydb,"1205030207");
	if(student_output==0)
	{
		printf("fetch error\n");
		//exit(3);
	}
	else
	{
		printf("%s\n",student_output);
	}
	db_close(mydb);
	return 0;
}
