#include<stdlib.h>

enum
{
	COLUMN_NUMERO,
	COLUMN_GIORNO,
	COLUMN_MESE,
	COLUMN_ANNO,
	N_COLS
};

int estrazioni[90][4];

int  dati(void *null,int record, char **rows, char **col_name)
{
	if(atoi(rows[3])>0) 
	{
		if(atoi(rows[3])<91)
		{
			estrazioni[atoi(rows[3])][0]=atoi(rows[0]);
			estrazioni[atoi(rows[3])][1]=atoi(rows[1]);
			estrazioni[atoi(rows[3])][2]=atoi(rows[2]);
			estrazioni[atoi(rows[3])][3]=atoi(rows[3]);
		}
	}
	if(atoi(rows[4])>0)
	{
		if(atoi(rows[4])<91)
		{
			estrazioni[atoi(rows[4])][0]=atoi(rows[0]);
			estrazioni[atoi(rows[4])][1]=atoi(rows[1]);
			estrazioni[atoi(rows[4])][2]=atoi(rows[2]);
			estrazioni[atoi(rows[4])][3]=atoi(rows[4]);
		}
	}
	if(atoi(rows[5])>0)
	{
		if(atoi(rows[5])<91)
		{
			estrazioni[atoi(rows[5])][0]=atoi(rows[0]);
			estrazioni[atoi(rows[5])][1]=atoi(rows[1]);
			estrazioni[atoi(rows[5])][2]=atoi(rows[2]);
			estrazioni[atoi(rows[5])][3]=atoi(rows[5]);
		}
	}
	if(atoi(rows[6])>0)
	{
		if(atoi(rows[6])<91)
		{
			estrazioni[atoi(rows[6])][0]=atoi(rows[0]);
			estrazioni[atoi(rows[6])][1]=atoi(rows[1]);
			estrazioni[atoi(rows[6])][2]=atoi(rows[2]);
			estrazioni[atoi(rows[6])][3]=atoi(rows[6]);
		}
	}
	if(atoi(rows[7])>0)
	{
		if(atoi(rows[7])<91)
		{
			estrazioni[atoi(rows[7])][0]=atoi(rows[0]);
			estrazioni[atoi(rows[7])][1]=atoi(rows[1]);
			estrazioni[atoi(rows[7])][2]=atoi(rows[2]);
			estrazioni[atoi(rows[7])][3]=atoi(rows[7]);
		}
	}
	return 0;
}

void ritardatari ()
{
	char *ErrMsg = 0;
	sqlite3 *db;
	char *home;
	home=getenv("HOME");
	char path[strlen(home)+26];
	sprintf(path,"%s%s",home,"/.lotto4linux/memoria.db");
	char *database=path;
	char *city=gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox));
	char query[70];
	char *q1="SELECT * FROM "; 
	char *q2=" ORDER BY anno,mese,giorno";
	strcpy(query,q1);
	strcat(query,city);
	strcat(query,q2);
	sqlite3_open(database, &db);
	sqlite3_exec(db, query, dati, 0, &ErrMsg);
	sqlite3_close(db);

	char titolo[50];
	strcpy(titolo,"Ritardatari sulla ruota di ");
	strcat(titolo,city);

	GtkWidget *result=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(result),GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable(GTK_WINDOW(result),FALSE);
	gtk_window_set_title(GTK_WINDOW(result),titolo);

	GtkWidget *scroller=gtk_scrolled_window_new(0,0);
	gtk_container_add(GTK_CONTAINER(result),scroller);
	
	GtkListStore *lista=gtk_list_store_new(N_COLS,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
	
	GtkWidget *tree=gtk_tree_view_new_with_model(GTK_TREE_MODEL(lista));
	gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(tree),GTK_TREE_VIEW_GRID_LINES_BOTH);
	gtk_container_add(GTK_CONTAINER(scroller),tree);
	gtk_widget_set_size_request(tree,350,300);
	GtkCellRenderer *cell=gtk_cell_renderer_text_new();
	g_object_set(G_OBJECT(cell),"background","orange",NULL);
	GtkCellRenderer *cell2=gtk_cell_renderer_text_new();

	GtkTreeViewColumn *cols1=gtk_tree_view_column_new_with_attributes("Numero",cell,"text",COLUMN_NUMERO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree),cols1);

	GtkTreeViewColumn *cols2=gtk_tree_view_column_new_with_attributes("Giorno",cell2,"text",COLUMN_GIORNO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree),cols2);

	GtkTreeViewColumn *cols3=gtk_tree_view_column_new_with_attributes("Mese",cell2,"text",COLUMN_MESE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree),cols3);

	GtkTreeViewColumn *cols4=gtk_tree_view_column_new_with_attributes("Anno",cell2,"text",COLUMN_ANNO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree),cols4);

	GtkTreeIter   iter;
	
	gtk_widget_show_all(result);
	
	for(int i=1;i<91;i++)
	{
		if(estrazioni[i][3]==0)
		{
			NULL;
		}
	else
	{
	gtk_list_store_append (lista, &iter); 
	gtk_list_store_set (lista, &iter,
	COLUMN_NUMERO,estrazioni[i][3],
	COLUMN_GIORNO,estrazioni[i][0],
	COLUMN_MESE,estrazioni[i][1],
	COLUMN_ANNO,estrazioni[i][2],
	-1);
	}
	}
	gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(lista), COLUMN_MESE, GTK_SORT_ASCENDING);
	gtk_tree_sortable_set_sort_column_id(GTK_TREE_SORTABLE(lista), COLUMN_ANNO, GTK_SORT_ASCENDING);
}

