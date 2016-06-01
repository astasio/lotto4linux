//copyright Antonio Stasio 2010 astasio@gmail.com
#include<stdlib.h>
#include<sys/stat.h>
#include<gtk/gtk.h>
#include<sqlite3.h>
#include<string.h>
#include<curl/curl.h>
#include "logo.h"
#include "storico.h"
#include "estrai.h"
#include "down.h"
#include "interfaccia.h"

int main(int argc,char **argv)
{
char *home;
home=getenv("HOME");
char path[strlen(home)+26];
sprintf(path,"%s%s",home,"/.lotto4linux/memoria.db");
FILE *db=fopen(path,"r");

if(db==NULL)
{
	char dir[strlen(home)+15];
	sprintf(dir,"%s%s",home,"/.lotto4linux/");
	mkdir(dir,0777);
	char *ErrMsg = 0;
	sqlite3 *db;
	char *database=path;
	sqlite3_open(database, &db);
	char query1[]="CREATE TABLE bari(giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query2[]="CREATE TABLE cagliari( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query3[]="CREATE TABLE firenze( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query4[]="CREATE TABLE genova( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query5[]="CREATE TABLE milano( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query6[]="CREATE TABLE napoli( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query7[]="CREATE TABLE palermo( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query8[]="CREATE TABLE roma( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query9[]="CREATE TABLE torino( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query10[]="CREATE TABLE venezia( giorno integer, mese integer,  anno integer, uno integer,  due integer, tre integer, quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	char query11[]="CREATE TABLE nazionale(giorno integer,mese integer, anno integer, uno integer,due integer, tre integer,quattro integer, cinque integer,CONSTRAINT constraint_ignore_dup UNIQUE (giorno,mese,anno,uno,due,tre,quattro,cinque) ON CONFLICT IGNORE)";
	sqlite3_exec(db, query1, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query2, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query3, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query4, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query5, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query6, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query7, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query8, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query9, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query10, NULL, 0, &ErrMsg);
	sqlite3_exec(db, query11, NULL, 0, &ErrMsg);
}

gtk_init(&argc, &argv);
build_win();
gtk_main();

return 0;
}
