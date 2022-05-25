#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  printf("MySQL client version: %s\n", mysql_get_client_info());

  exit(0);
}


/*
1-- Instalando o banco no Linux
sudo apt install mysql-server

2-- Instalando fontes do cliente do banco para o include <mysql.h>
sudo apt-get install default-libmysqlclient-dev

2-- Passos de instalação e configuração para windows
https://www.treinaweb.com.br/blog/utilizando-o-mysql-em-uma-aplicacao-c

3-- Acessando o banco para preencher dados básicos
sudo mysql

4-- Criando banco de dados
create database sistema;

5-- Acessando banco de dados
use sistema;

6-- Criando tabela fornecedores
CREATE TABLE fornecedores(
  codigo int(4) AUTO_INCREMENT,
  nome varchar(30) NOT NULL,
  email varchar(50),
PRIMARY KEY (codigo)
);

7-- Inserindo dados na tabela fornecedores
INSERT INTO fornecedores(codigo, nome, email) VALUES (null, “Ricardo”, “ricoarrigoni@gmail.com”) ;
INSERT INTO fornecedores(codigo, nome, email) VALUES (null, “João”, “joao@gmail.com”) ;
INSERT INTO fornecedores(codigo, nome, email) VALUES (null, “Maria”, “maria@gmail.com”) ;

8-- Selecionando dados da tabela de fornecedores
SELECT * FROM fornecedores;

9-- Criando usuário para gerenciamento do banco de dados
CREATE USER 'josimar'@'localhost' IDENTIFIED BY 'password';

10-- Alterando padrão de senha do usuário
ALTER USER 'josimar'@'localhost' IDENTIFIED WITH mysql_native_password BY 'password';

11-- Dando acesso ao usuário para tabelas
GRANT ALL PRIVILEGES ON * . * TO 'josimar'@'localhost';

12-- Atualizando alterações de usuário
FLUSH PRIVILEGES;

13-- Saindo do prompt de comando do banco
exit;

14-- Instalar o DBeaver ou Mysql Workbench ou semelhante e configurar o usuário de banco conforme descrito nos passos anteriores

15-- Compilando o fonte, considere o nome do seu programa no lugar de banco.c
gcc  fornecedor.c  -o banco `mysql_config --cflags --libs`
--ou
gcc -I/usr/include/mysql banco.c /usr/include/mysql/mysql.h -o banco `mysql_config --cflags --libs`

16-- Executar o programa, a saída deve ser a versão do mysql

*/
