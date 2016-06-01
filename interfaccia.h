#include "calcolo.h"
#include "smorfia.h"
#include "crediti.h"
#include "ritardatari.h"

GtkWidget *window;
GtkWidget *combobox;
GtkWidget *button;
GtkWidget *scroll;
GtkWidget *treeview;
GtkWidget *pixmap;
GdkPixmap *gdk_pixmap;
GdkBitmap *mask;
GtkStyle *style;
GdkGC *gc;
GtkWidget *statusbar;
GtkWidget *progressbar;


void chiudi (GtkWidget *widget,gpointer data)
{ 
	gtk_main_quit();
}

void build_win()
{
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(chiudi),NULL);
	gtk_window_set_title(GTK_WINDOW(window),"Lotto4Linux");
	gtk_widget_set_size_request(GTK_WIDGET(window),450,600);
	gtk_widget_show(window);

	GtkWidget *first_hbox=gtk_hbox_new(0,2);
	gtk_box_set_spacing(GTK_BOX(first_hbox),10);
	gtk_container_add(GTK_CONTAINER(window),first_hbox);
	gtk_container_set_border_width(GTK_CONTAINER(window),3);


	GtkWidget *vbox=gtk_vbox_new(0,5);
	gtk_box_set_spacing(GTK_BOX(vbox),10);
	gtk_box_pack_start(GTK_BOX(first_hbox),vbox,1,1,0);
	//gtk_container_set_border_width(GTK_CONTAINER(window),3);

/* creazione menubar*/

	GtkWidget *bar=gtk_menu_bar_new();
	gtk_box_pack_start(GTK_BOX(vbox),bar,1,1,0);
	gtk_box_set_child_packing(GTK_BOX(vbox),bar,FALSE,FALSE,0,GTK_PACK_START);

	GtkWidget *file=gtk_menu_item_new_with_label("File");
	gtk_menu_shell_append(GTK_MENU_SHELL(bar),file);

	GtkWidget *filemenu=gtk_menu_new();

	GtkWidget *aggiorna=gtk_menu_item_new_with_label("Aggiorna Estrazioni");
	gtk_menu_append(GTK_MENU(filemenu),aggiorna);
	gtk_signal_connect(GTK_OBJECT(aggiorna),"activate",GTK_SIGNAL_FUNC(down),NULL);

	GtkWidget *uscita=gtk_menu_item_new_with_label("Esci");
	gtk_menu_append(GTK_MENU(filemenu),uscita);
	gtk_signal_connect(GTK_OBJECT(uscita),"activate",GTK_SIGNAL_FUNC(chiudi),NULL);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM (file), filemenu);

	GtkWidget *visualizza=gtk_menu_item_new_with_label("Visualizza");
	gtk_menu_shell_append(GTK_MENU_SHELL(bar),visualizza);

	GtkWidget *visualizzamenu=gtk_menu_new();

	GtkWidget *caricatutto=gtk_menu_item_new_with_label("Storico Estrazioni");
	gtk_menu_append(GTK_MENU(visualizzamenu),caricatutto);
	gtk_signal_connect(GTK_OBJECT(caricatutto),"activate",GTK_SIGNAL_FUNC(storico),NULL);

	GtkWidget *ritard=gtk_menu_item_new_with_label("Numeri ritardatari");
	gtk_menu_append(GTK_MENU(visualizzamenu),ritard);
	gtk_signal_connect(GTK_OBJECT(ritard),"activate",GTK_SIGNAL_FUNC(ritardatari),NULL);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(visualizza),visualizzamenu);

	GtkWidget *strumenti=gtk_menu_item_new_with_label("Strumenti");
	gtk_menu_shell_append(GTK_MENU_SHELL(bar),strumenti);

	GtkWidget *strumentimenu=gtk_menu_new();

	GtkWidget *calcolovincita=gtk_menu_item_new_with_label("Calcolo Vincita");
	gtk_menu_append(GTK_MENU(strumentimenu),calcolovincita);
	gtk_signal_connect(GTK_OBJECT(calcolovincita),"activate",GTK_SIGNAL_FUNC(calcolo),NULL);

	GtkWidget *tombola=gtk_menu_item_new_with_label("Smorfia");
	gtk_menu_append(GTK_MENU(strumentimenu),tombola);
	gtk_signal_connect(GTK_OBJECT(tombola),"activate",GTK_SIGNAL_FUNC(smorfia),NULL);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(strumenti),strumentimenu);

	GtkWidget *aiuto=gtk_menu_item_new_with_label("Aiuto");
	gtk_menu_shell_append(GTK_MENU_SHELL(bar),aiuto);

	GtkWidget *aiutomenu=gtk_menu_new();

	GtkWidget *credit=gtk_menu_item_new_with_label("Crediti");
	gtk_menu_append(GTK_MENU(aiutomenu),credit);
	gtk_signal_connect(GTK_OBJECT(credit),"activate",GTK_SIGNAL_FUNC(crediti),NULL);
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(aiuto),aiutomenu);

	/* fine creazione menubar*/

	GtkWidget *frame1=gtk_frame_new("Ruote");
	gtk_frame_set_shadow_type(GTK_FRAME(frame1),GTK_SHADOW_IN);
	gtk_box_pack_start(GTK_BOX(vbox),frame1,1,1,0);
	gtk_box_set_child_packing(GTK_BOX(vbox),frame1,FALSE,FALSE,0,GTK_PACK_START);

	GtkWidget *hbox=gtk_hbox_new(0,5);
	gtk_container_add(GTK_CONTAINER(frame1),hbox);	
	gtk_box_set_homogeneous(GTK_BOX(hbox),FALSE);

	combobox=gtk_combo_box_new_text();
	gtk_widget_set_size_request(combobox,80,30);
	gtk_box_pack_start(GTK_BOX(hbox),combobox,1,1,0);
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"bari");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"cagliari");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"firenze");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"genova");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"milano");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"napoli");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"palermo");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"roma");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"torino");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"venezia");
	gtk_combo_box_append_text(GTK_COMBO_BOX(combobox),"nazionale");
	gtk_combo_box_set_active(GTK_COMBO_BOX(combobox),0);
	gtk_widget_show(combobox);

	style=gtk_widget_get_default_style();
	gc=style->black_gc;
	gdk_pixmap=gdk_pixmap_create_from_xpm_d(window->window,
						&mask,
						&style->bg[GTK_STATE_NORMAL],
						logo_xpm);

	pixmap=gtk_pixmap_new(gdk_pixmap,mask);
	gtk_box_pack_start(GTK_BOX(hbox),pixmap,1,1,0);
	
	GtkWidget *frame2=gtk_frame_new("Estrazioni");
	gtk_frame_set_shadow_type(GTK_FRAME(frame2),GTK_SHADOW_OUT);
	gtk_box_pack_start(GTK_BOX(vbox),frame2,1,1,0);
	gtk_box_set_child_packing(GTK_BOX(vbox),frame2,TRUE,TRUE,0,GTK_PACK_START);

	GtkWidget *hbox1=gtk_hbox_new(0,5);
	gtk_container_add(GTK_CONTAINER(frame2),hbox1);
	gtk_container_set_border_width(GTK_CONTAINER(frame2),3);
	gtk_box_set_homogeneous(GTK_BOX(hbox1),TRUE);

	GtkWidget *vbox1=gtk_vbox_new(0,5);
	gtk_box_set_spacing(GTK_BOX(vbox1),10);
	gtk_container_add(GTK_CONTAINER(hbox1),vbox1);
	gtk_container_set_border_width(GTK_CONTAINER(hbox1),3);
	gtk_box_set_homogeneous(GTK_BOX(vbox1),FALSE);
	
	button=gtk_button_new_with_label("Genera Estrazione");
	gtk_box_pack_start(GTK_BOX(vbox1),button,1,1,0);
	gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(estrai),NULL);
	gtk_box_set_child_packing(GTK_BOX(vbox1),button,FALSE,FALSE,0,GTK_PACK_START);

	scroll=gtk_scrolled_window_new(0,0);
	gtk_box_pack_start(GTK_BOX(vbox1),scroll,1,1,0);
	gtk_box_set_child_packing(GTK_BOX(vbox1),scroll,TRUE,TRUE,0,GTK_PACK_START);

	list_store=gtk_list_store_new(N_COLUMNS,G_TYPE_STRING,
						G_TYPE_INT,
						G_TYPE_INT,
						G_TYPE_INT,
						G_TYPE_INT,
						G_TYPE_INT);

	treeview=gtk_tree_view_new_with_model(GTK_TREE_MODEL(list_store));
	gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(treeview),GTK_TREE_VIEW_GRID_LINES_BOTH);
	gtk_container_add(GTK_CONTAINER(scroll),treeview);
	GtkCellRenderer *cell=gtk_cell_renderer_text_new();
	GtkCellRenderer *cellcolor=gtk_cell_renderer_text_new();
	g_object_set(G_OBJECT(cellcolor),"background","orange",NULL);

	GtkTreeViewColumn *column=gtk_tree_view_column_new_with_attributes("Data",cellcolor,"text",COLUMN_DATA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);

	GtkTreeViewColumn *column2=gtk_tree_view_column_new_with_attributes("uno",cell,"text",COLUMN_UNO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column2);

	GtkTreeViewColumn *column3=gtk_tree_view_column_new_with_attributes("due",cell,"text",COLUMN_DUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column3);

	GtkTreeViewColumn *column4=gtk_tree_view_column_new_with_attributes("tre",cell,"text",COLUMN_TRE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column4);

	GtkTreeViewColumn *column5=gtk_tree_view_column_new_with_attributes("quattro",cell,"text",COLUMN_QUATTRO,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column5);

	GtkTreeViewColumn *column6=gtk_tree_view_column_new_with_attributes("cinque",cell,"text",COLUMN_CINQUE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column6);

	statusbar=gtk_statusbar_new();
	gtk_box_pack_start(GTK_BOX(vbox),statusbar,1,1,0);
	gtk_box_set_child_packing(GTK_BOX(vbox),statusbar,FALSE,FALSE,0,GTK_PACK_END);

	gtk_widget_show_all(window);
	
}
