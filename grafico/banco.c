#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  printf("MySQL client version: %s\n", mysql_get_client_info());

  exit(0);
}


/*
sudo apt install mysql-server
sudo apt-get install default-libmysqlclient-dev
gcc  banco.c  -o banco `mysql_config --cflags --libs`
https://zetcode.com/db/mysqlc/
https://www.treinaweb.com.br/blog/utilizando-o-mysql-em-uma-aplicacao-c
gcc -I/usr/include/mysql banco.c /usr/include/mysql/mysql.h -o banco `mysql_config --cflags --libs`
*/
