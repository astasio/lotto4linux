#include<stdlib.h>
GtkListStore *list_store;
GtkTreeIter   iter;
GtkWidget *combobox;
GtkWidget *treeview;
enum
{
	COLUMN_DATA,
	COLUMN_UNO,
	COLUMN_DUE,
	COLUMN_TRE,
	COLUMN_QUATTRO,
	COLUMN_CINQUE,
	N_COLUMNS
};

int  callback(void *null,int record, char **rows, char **col_name)
{
	char data[11];
	strcpy(data,rows[0]);
	strcat(data,"/");
	strcat(data,rows[1]);
	strcat(data,"/");
	strcat(data,rows[2]);
	gtk_list_store_append (list_store, &iter); 
	gtk_list_store_set (list_store, &iter,
	COLUMN_DATA,data,
	COLUMN_UNO,atoi(rows[3]),
	COLUMN_DUE,atoi(rows[4]),
	COLUMN_TRE,atoi(rows[5]),
	COLUMN_QUATTRO,atoi(rows[6]),
	COLUMN_CINQUE,atoi(rows[7]),
	-1);
	return 0;
}

void storico ()
{
	GtkTreeModel *model = gtk_tree_view_get_model(GTK_TREE_VIEW(treeview));
	g_object_ref(model); 
	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), NULL);

	gtk_list_store_clear(GTK_LIST_STORE(list_store));
	char *ErrMsg = 0;
	sqlite3 *db;
	char *home;
	home=getenv("HOME");
	char path[strlen(home)+26];
	sprintf(path,"%s%s",home,"/.lotto4linux/memoria.db");
	char *database=path;
	char *city=gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox));
	char query[65];
	char *q1="select * from "; 
	char *q2=" order by anno DESC,mese DESC,giorno DESC";
	strcpy(query,q1);
	strcat(query,city);
	strcat(query,q2);
	sqlite3_open(database, &db);
	sqlite3_exec(db, query, callback, 0, &ErrMsg);
	sqlite3_close(db);

	gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
	g_object_unref(model);
}
