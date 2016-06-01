#include "pulcinella.h"

GtkWidget *win;
GtkWidget *h;
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *spin;
GtkObject *adj3;
GtkWidget *butt;
GtkWidget *lbl;
GtkWidget *pixmap1;
GdkPixmap *gdk_pixmap1;
GdkBitmap *mask1;	
GtkStyle *style1;
GdkGC *gc1;

void visual(GtkWidget *widget,gpointer data)
{
	int numero;
	numero=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin));
	switch(numero)
		{
		case 1 : gtk_label_set_text(GTK_LABEL(lbl),"l'Italia (l'Italia)"); break;
		case 2 : gtk_label_set_text(GTK_LABEL(lbl),"'a piccerella (la bambina)"); break;
		case 3 : gtk_label_set_text(GTK_LABEL(lbl),"'a jatta (il gatto)"); break;
		case 4 : gtk_label_set_text(GTK_LABEL(lbl),"'o puorco (il maiale)"); break;
		case 5 : gtk_label_set_text(GTK_LABEL(lbl),"'a mano (la mano)"); break;
		case 6 : gtk_label_set_text(GTK_LABEL(lbl),"chella ca guarda n'terra (quella che guarda per terra)"); break;
		case 7 : gtk_label_set_text(GTK_LABEL(lbl),"'o vasetto (il vaso da notte)"); break;
		case 8 : gtk_label_set_text(GTK_LABEL(lbl),"'a maronna (la madonna)"); break;
		case 9 : gtk_label_set_text(GTK_LABEL(lbl),"'a figliata (la figliolanza)"); break;
		case 10 : gtk_label_set_text(GTK_LABEL(lbl),"'e fasule (i fagioli)"); break;
		case 11 : gtk_label_set_text(GTK_LABEL(lbl),"'e surice (i topi)"); break;
		case 12 : gtk_label_set_text(GTK_LABEL(lbl),"'e surdate (i soldati)"); break;
		case 13 : gtk_label_set_text(GTK_LABEL(lbl),"Sant'Antonio (Sant'Antonio)"); break;
		case 14 : gtk_label_set_text(GTK_LABEL(lbl),"'o mbriaco (l'ubriaco)"); break;
		case 15 : gtk_label_set_text(GTK_LABEL(lbl),"'o guaglione (il ragazzo)"); break;
		case 16 : gtk_label_set_text(GTK_LABEL(lbl),"'o culo (il deretano)"); break;
		case 17 : gtk_label_set_text(GTK_LABEL(lbl),"'a disgrazia (la disgrazia)"); break;
		case 18 : gtk_label_set_text(GTK_LABEL(lbl),"'o sanghe (il sangue)"); break;
		case 19 : gtk_label_set_text(GTK_LABEL(lbl),"'a resata (la risata)"); break;
		case 20 : gtk_label_set_text(GTK_LABEL(lbl),"'a festa (la festa)"); break;
		case 21 : gtk_label_set_text(GTK_LABEL(lbl),"'a femmena annura (la donna nuda)"); break;
		case 22 : gtk_label_set_text(GTK_LABEL(lbl),"'o pazzo (il matto)"); break;
		case 23 : gtk_label_set_text(GTK_LABEL(lbl),"'o scemo (lo sciocco)"); break;
		case 24 : gtk_label_set_text(GTK_LABEL(lbl),"'e gguardie (le guardie)"); break;
		case 25 : gtk_label_set_text(GTK_LABEL(lbl),"Natale (Natale)"); break;
		case 26 : gtk_label_set_text(GTK_LABEL(lbl),"Nanninella (la piccola Anna)"); break;
		case 27 : gtk_label_set_text(GTK_LABEL(lbl),"'o cantaro (il pitale)"); break;
		case 28 : gtk_label_set_text(GTK_LABEL(lbl),"'e zizze (i seni)"); break;
		case 29 : gtk_label_set_text(GTK_LABEL(lbl),"'o pate d' 'e ccriature (il padre dei bimbi)"); break;
		case 30 : gtk_label_set_text(GTK_LABEL(lbl),"'e ppalle (le palle del tenente)"); break;
		case 31 : gtk_label_set_text(GTK_LABEL(lbl),"'o patrone e casa (il padrone di casa)"); break;
		case 32 : gtk_label_set_text(GTK_LABEL(lbl),"'o capitone (il capitone)"); break;
		case 33 : gtk_label_set_text(GTK_LABEL(lbl),"ll'anne 'e Cristo (gli anni di Cristo)"); break;
		case 34 : gtk_label_set_text(GTK_LABEL(lbl),"'a capa (la testa)"); break;
		case 35 : gtk_label_set_text(GTK_LABEL(lbl),"Aucielle (l'uccellino)"); break;
		case 36 : gtk_label_set_text(GTK_LABEL(lbl),"'e castagnelle (le nacchere)"); break;
		case 37 : gtk_label_set_text(GTK_LABEL(lbl),"'o monaco (il monaco)"); break;
		case 38 : gtk_label_set_text(GTK_LABEL(lbl),"'e mazzate (le botte)"); break;
		case 39 : gtk_label_set_text(GTK_LABEL(lbl),"'a funa 'naganna (la corda al collo)"); break;
		case 40 : gtk_label_set_text(GTK_LABEL(lbl),"'a poposcia (l'ernia)"); break;
		case 41 : gtk_label_set_text(GTK_LABEL(lbl),"'o curtiello (il coltello)"); break;
		case 42 : gtk_label_set_text(GTK_LABEL(lbl),"'o ccafè (il caffè)"); break;
		case 43 : gtk_label_set_text(GTK_LABEL(lbl),"onna pereta for 'o balcone (la donna al balcone)"); break;
		case 44 : gtk_label_set_text(GTK_LABEL(lbl),"'e ccancelle (la prigione)"); break;
		case 45 : gtk_label_set_text(GTK_LABEL(lbl),"'o vino bbuono (il vino buono)"); break;
		case 46 : gtk_label_set_text(GTK_LABEL(lbl),"'e renare (il denaro)"); break;
		case 47 : gtk_label_set_text(GTK_LABEL(lbl),"'o muorto (il morto)"); break;
		case 48 : gtk_label_set_text(GTK_LABEL(lbl),"'o muorto che parla (il morto che parla)"); break;
		case 49 : gtk_label_set_text(GTK_LABEL(lbl),"'a carne (la carne)"); break;
		case 50 : gtk_label_set_text(GTK_LABEL(lbl),"'o ppane (il pane)"); break;
		case 51 : gtk_label_set_text(GTK_LABEL(lbl),"'o ciardino (il giardino)"); break;
		case 52 : gtk_label_set_text(GTK_LABEL(lbl),"'a mamma (la mamma)"); break;
		case 53 : gtk_label_set_text(GTK_LABEL(lbl),"'o viecchio (il vecchio)"); break;
		case 54 : gtk_label_set_text(GTK_LABEL(lbl),"'o cappiello (il cappello)"); break;
		case 55 : gtk_label_set_text(GTK_LABEL(lbl),"'a musica (la musica)"); break;
		case 56 : gtk_label_set_text(GTK_LABEL(lbl),"'a caruta (la caduta)"); break;
		case 57 : gtk_label_set_text(GTK_LABEL(lbl),"'o scartellato (il gobbo)"); break;
		case 58 : gtk_label_set_text(GTK_LABEL(lbl),"'o pacco (il regalo)"); break;
		case 59 : gtk_label_set_text(GTK_LABEL(lbl),"'e pile (i peli)"); break;
		case 60 : gtk_label_set_text(GTK_LABEL(lbl),"'o lamiento (il lamento)"); break;
		case 61 : gtk_label_set_text(GTK_LABEL(lbl),"'o cacciatore (il cacciatore)"); break;
		case 62 : gtk_label_set_text(GTK_LABEL(lbl),"'o muorto accise (il morto ammazzato)"); break;
		case 63 : gtk_label_set_text(GTK_LABEL(lbl),"'a sposa la sposa)"); break;
		case 64 : gtk_label_set_text(GTK_LABEL(lbl),"'a sciammeria (la marsina)"); break;
		case 65 : gtk_label_set_text(GTK_LABEL(lbl),"'o chianto (il pianto)"); break;
		case 66 : gtk_label_set_text(GTK_LABEL(lbl),"'e ddoje zetelle (le due zitelle)"); break;
		case 67 : gtk_label_set_text(GTK_LABEL(lbl),"'o totaro (il totano)"); break;
		case 68 : gtk_label_set_text(GTK_LABEL(lbl),"'a zuppa cotta (la zuppa cotta)"); break;
		case 69 : gtk_label_set_text(GTK_LABEL(lbl),"sotto e 'ncoppa (sottosopra)"); break;
		case 70 : gtk_label_set_text(GTK_LABEL(lbl),"'o palazzo (il palazzo)"); break;
		case 71 : gtk_label_set_text(GTK_LABEL(lbl),"l'ommo e merda (uomo di merda)"); break;
		case 72 : gtk_label_set_text(GTK_LABEL(lbl),"'a meraviglia (lo stupore)"); break;
		case 73 : gtk_label_set_text(GTK_LABEL(lbl),"'o spitale (l'ospedale)"); break;
		case 74 : gtk_label_set_text(GTK_LABEL(lbl),"'a rotta (la grotta)"); break;
		case 75 : gtk_label_set_text(GTK_LABEL(lbl),"pullecenella (pulcinella)"); break;
		case 76 : gtk_label_set_text(GTK_LABEL(lbl),"'a funtana (la fontana)"); break;
		case 77 : gtk_label_set_text(GTK_LABEL(lbl),"'e diavule (i diavoli)"); break;
		case 78 : gtk_label_set_text(GTK_LABEL(lbl),"'a bella figliola (la prostituta)"); break;
		case 79 : gtk_label_set_text(GTK_LABEL(lbl),"'o mariuolo (il ladro)"); break;
		case 80 : gtk_label_set_text(GTK_LABEL(lbl),"'a vocca (la bocca)"); break;
		case 81 : gtk_label_set_text(GTK_LABEL(lbl),"'e sciure (i fiori)"); break;
		case 82 : gtk_label_set_text(GTK_LABEL(lbl),"'a tavula (la tavola imbandita)"); break;
		case 83 : gtk_label_set_text(GTK_LABEL(lbl),"'o maletiempo (il maltempo)"); break;
		case 84 : gtk_label_set_text(GTK_LABEL(lbl),"'a chiesa (la chiesa)"); break;
		case 85 : gtk_label_set_text(GTK_LABEL(lbl),"ll'anema o' priatorio (l'anima del purgatorio)"); break;
		case 86 : gtk_label_set_text(GTK_LABEL(lbl),"'a puteca (la bottega)"); break;
		case 87 : gtk_label_set_text(GTK_LABEL(lbl),"'e perucchie (i pidocchi)"); break;
		case 88 : gtk_label_set_text(GTK_LABEL(lbl),"'e casecavalle (i caciocavalli)"); break;
		case 89 : gtk_label_set_text(GTK_LABEL(lbl),"'a vecchia (la vecchia)"); break;
		case 90 : gtk_label_set_text(GTK_LABEL(lbl),"'a paura (la paura)"); break;
		}
}

void smorfia(GtkWidget *widget,gpointer data)
{
	win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable(GTK_WINDOW(win),FALSE);
	gtk_window_set_title(GTK_WINDOW(win),"Smorfia");
	gtk_widget_show(win);
	
	h=gtk_hbox_new(0,2);
	gtk_container_add(GTK_CONTAINER(win),h);
	gtk_container_set_border_width(GTK_CONTAINER(win),10);
	gtk_box_set_spacing(GTK_BOX(h),10);
	gtk_widget_show(h);
	
	style1=gtk_widget_get_default_style();
	gc1=style1->black_gc;
	gdk_pixmap1=gdk_pixmap_create_from_xpm_d(win->window,
						&mask1,
						&style1->bg[GTK_STATE_NORMAL],
						pulcinella_xpm);

	pixmap1=gtk_pixmap_new(gdk_pixmap1,mask1);
	gtk_box_pack_start(GTK_BOX(h),pixmap1,1,1,0);
	gtk_widget_show(pixmap1);
	
	vbox=gtk_vbox_new(0,2);
	gtk_box_pack_start(GTK_BOX(h),vbox,1,1,0);
	gtk_box_set_spacing(GTK_BOX(vbox),10);
	gtk_widget_show(vbox);
	
	hbox=gtk_hbox_new(0,2);
	gtk_box_pack_start(GTK_BOX(vbox),hbox,1,1,0);
	gtk_box_set_homogeneous(GTK_BOX(hbox),TRUE);
	gtk_widget_show(hbox);
		
	adj3=gtk_adjustment_new(0,1,90,1,0,0);
	spin=gtk_spin_button_new(GTK_ADJUSTMENT(adj3),0,0);
	gtk_box_pack_start(GTK_BOX(hbox),spin,1,1,0);
	gtk_widget_show(spin);
	
	butt=gtk_button_new_with_label("Visualizza");
	gtk_box_pack_start(GTK_BOX(hbox),butt,1,1,0);
	gtk_widget_set_size_request(butt,80,30);
	gtk_signal_connect(GTK_OBJECT(butt),"clicked",GTK_SIGNAL_FUNC(visual),NULL);
	gtk_widget_show(butt);
	
	lbl=gtk_label_new("");
	gtk_box_pack_start(GTK_BOX(vbox),lbl,1,1,0);
	gtk_widget_show(lbl);

}
