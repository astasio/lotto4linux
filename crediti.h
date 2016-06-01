GtkWidget *winc;
GtkWidget *v;
GtkWidget *nome;
GtkWidget *autore;
GtkWidget *licenza;

void crediti(GtkWidget *widget,gpointer data)
{
	winc=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(winc),GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable(GTK_WINDOW(winc),FALSE);
	gtk_window_set_title(GTK_WINDOW(winc),"Crediti");
	gtk_widget_show(winc);

//GtkWidget *first_hbox;
	v=gtk_vbox_new(0,5);
	gtk_box_set_spacing(GTK_BOX(v),10);	
	gtk_container_add(GTK_CONTAINER(winc),v);
	gtk_container_set_border_width(GTK_CONTAINER(winc),10);
	gtk_widget_show(v);
	
		
	nome=gtk_label_new("Lotto4Linux\n vers: 0.3.0");
	gtk_box_pack_start(GTK_BOX(v),nome,1,1,0);
	gtk_widget_show(nome);
		
	autore=gtk_link_button_new_with_label("mailto:astasio@gmail.com","contatta l'autore");
	gtk_box_pack_start(GTK_BOX(v),autore,1,1,0);
	gtk_widget_show(autore);		
		
	licenza=gtk_link_button_new_with_label("http://www.gnu.org/licenses/gpl.html","Licenza GNU");
	gtk_box_pack_start(GTK_BOX(v),licenza,1,1,0);
	gtk_widget_show(licenza);

}
