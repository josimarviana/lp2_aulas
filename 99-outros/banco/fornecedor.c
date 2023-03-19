#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }

  if (mysql_real_connect(con, "localhost", "josimar", "password", "sistema", 0, NULL, 0) == NULL)
  {
      finish_with_error(con);
  }

  if (mysql_query(con, "SELECT * FROM fornecedores"))
  {
      finish_with_error(con);
  }

  MYSQL_RES *result = mysql_store_result(con);

  if (result == NULL)
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;

  while ((row = mysql_fetch_row(result)))
  {
      for(int i = 0; i < num_fields; i++)
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }

      printf("\n");
  }

  mysql_free_result(result);
  mysql_close(con);

  exit(0);
}

/*
1-- Altere a linha if (mysql_real_connect(con, "localhost", "josimar", "password", "sistema", 0, NULL, 0) == NULL)
com os valores do usuário, senha, e nome do seu banco de dados

2-- Compilando o fonte, considere o nome do seu programa no lugar de fornecedor.c
gcc  fornecedor.c  -o fornecedor `mysql_config --cflags --libs`
--ou
gcc -I/usr/include/mysql fornecedor.c /usr/include/mysql/mysql.h -o fornecedor `mysql_config --cflags --libs`

3-- Execute o programa e veja se lista os usuários cadastrados na tabela de fornecedores

4-- Comandos de banco no código - pode brincar a vontade
https://zetcode.com/db/mysqlc/



*/
