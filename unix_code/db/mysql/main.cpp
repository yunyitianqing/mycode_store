#include <mysql/mysql.h>
#include<stdio.h>
int main()
{
	MYSQL mysql;
	mysql_init(&mysql);
	MYSQL_RES *result;
	MYSQL_ROW row;
	mysql_init(&mysql);
	mysql_real_connect(&mysql,"127.0.0.1","root","witailab","test",0,NULL,0);
	mysql_query( &mysql , "SET NAMES 'utf8'");
	mysql_query(&mysql,"SELECT * FROM student");
	result=mysql_store_result(&mysql);
	while((row=mysql_fetch_row(result))){

           fprintf(stdout,"%s | %s | %s | %s | %s\n",row[0],row[1],row[2],row[3],row[4]);

    }
	mysql_close(&mysql);
	return 0;
}
