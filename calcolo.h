#include<gtk/gtk.h>
#include "euro.h"

GtkWidget *win;
GtkWidget *h2;
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *lbl;
GtkObject *adj;
GtkObject *adj2;
GtkWidget *hbox2;
GtkWidget *lbl3;
GtkWidget *spbutt;
GtkWidget *spbutt3;
GtkWidget *butt;
GtkWidget *ris;
GtkWidget *pixmap2;
GdkPixmap *gdk_pixmap2;
GdkBitmap *mask2;
GtkStyle *style2;
GdkGC *gc2;

void calc(GtkWidget *widget,gpointer data)
{
int num;
float money,vincita=0.0;
money=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(spbutt));
num=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spbutt3));
switch(num)
	{
	case 1 : vincita=(money*11.232)-(((money*11.232)/100)*6); break;
	case 2 : vincita=(money*250.00)-(((money*250.00)/100)*6); break;
	case 3 : vincita=(money*4500.00)-(((money*4500.00)/100)*6); break;
	case 4 : vincita=(money*120000.00)-(((money*120000.00)/100)*6); break;
	case 5 : vincita=(money*6000000.00)-(((money*6000000.00)/100)*6); break;
	}
if(vincita>6000000.000000)
	{
	vincita=6000000.00;
	}
char risul[17];
sprintf(risul,"%s %.2f","€: ",vincita);
gtk_label_set_text(GTK_LABEL(ris),risul);
}

void calcolo(GtkWidget *widget,gpointer data)
{

	win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable(GTK_WINDOW(win),FALSE);
	gtk_window_set_title(GTK_WINDOW(win),"Calcolo Vincita");
	gtk_widget_show(win);

	vbox=gtk_vbox_new(0,5);
	gtk_box_set_spacing(GTK_BOX(vbox),10);	
	gtk_container_add(GTK_CONTAINER(win),vbox);
	gtk_container_set_border_width(GTK_CONTAINER(win),10);
	gtk_widget_show(vbox);
	
	h2=gtk_hbox_new(0,2);
	gtk_box_set_spacing(GTK_BOX(h2),10);
	gtk_box_pack_start(GTK_BOX(vbox),h2,1,1,0);
	gtk_widget_show(h2);	
	
	style2=gtk_widget_get_default_style();
	gc2=style2->black_gc;
	gdk_pixmap2=gdk_pixmap_create_from_xpm_d(win->window,
						&mask2,
						&style2->bg[GTK_STATE_NORMAL],
						euro_xpm);

	pixmap2=gtk_pixmap_new(gdk_pixmap2,mask2);
	gtk_box_pack_start(GTK_BOX(h2),pixmap2,1,1,0);
	gtk_widget_show(pixmap2);
	
	ris=gtk_label_new("");
	gtk_box_pack_start(GTK_BOX(h2),ris,1,1,0);
	gtk_widget_show(ris);
	
	hbox=gtk_hbox_new(0,2);
	gtk_box_set_spacing(GTK_BOX(hbox),10);
	gtk_box_pack_start(GTK_BOX(vbox),hbox,1,1,0);
	gtk_widget_show(hbox);
		
	lbl=gtk_label_new("Inserisci l'importo giocato, €:");
	gtk_box_pack_start(GTK_BOX(hbox),lbl,1,1,0);
	gtk_widget_show(lbl);
	
	adj=gtk_adjustment_new(0,0,10000,0.1,0,0);
	spbutt=gtk_spin_button_new(GTK_ADJUSTMENT(adj),0,2);
	gtk_box_pack_start(GTK_BOX(hbox),spbutt,1,1,0);
	gtk_widget_show(spbutt);
	
	hbox2=gtk_hbox_new(0,2);
	gtk_box_set_spacing(GTK_BOX(hbox2),10);
	gtk_box_pack_start(GTK_BOX(vbox),hbox2,1,1,0);
	gtk_widget_show(hbox2);
	
	lbl3=gtk_label_new("Quanti numeri sono usciti?: ");
	gtk_box_pack_start(GTK_BOX(hbox2),lbl3,1,1,0);
	gtk_widget_show(lbl3);	
	
	adj2=gtk_adjustment_new(0,1,5,1,0,0);
	spbutt3=gtk_spin_button_new(GTK_ADJUSTMENT(adj2),1,0);
	gtk_box_pack_start(GTK_BOX(hbox2),spbutt3,1,1,0);
	gtk_widget_show(spbutt3);
	
	butt=gtk_button_new_with_label("calcola");
	gtk_box_pack_start(GTK_BOX(vbox),butt,1,1,0);
	gtk_widget_show(butt);
	gtk_signal_connect(GTK_OBJECT(butt),"clicked",GTK_SIGNAL_FUNC(calc),NULL);
}
