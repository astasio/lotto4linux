#include <stdlib.h>
#include <gtk/gtk.h> 

GtkWidget *button;

void estrai(GtkWidget *widget,gpointer data)
{
	srand(time(0));
	int x;
	int c[5]={0,0,0,0,0};
	for (int i=0;i<5;i++)
	{
		x=rand() % 91;
		int i2;
		for(i2=0;i2<5;i2++)
		{
			if(x==0)
			{
				//printf("%s\n","0 numero non valido!");
				i--;
			}
			if(c[i2]==x)
				{
					//printf("%d %s\n",x,"numero già uscito!");
					c[i2]--;
				}
		}
		c[i]=x;
	}
/*	GtkWidget *win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER_ALWAYS);
	gtk_window_set_resizable(GTK_WINDOW(win),FALSE);
	gtk_window_set_title(GTK_WINDOW(win),"Numeri Estratti");
	gtk_widget_set_size_request(GTK_WIDGET(win),400,50);
	gtk_widget_show(win);
*/
	char buff[3];
	char estrazione[62];
	strcpy(estrazione,"estrazione ruota di ");
	char *city=gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox));
	strcat(estrazione,city);
	strcat(estrazione,": - ");
	for(int i=0;i<5;i++)
		{
		sprintf(buff,"%d",c[i]);
		strcat(estrazione,buff);
		strcat(estrazione," - ");
		}
gtk_button_set_label(GTK_BUTTON(button),estrazione);
/*	GtkWidget *lbl=gtk_label_new(estrazione);
	gtk_container_add(GTK_CONTAINER(win),lbl);
	gtk_container_set_border_width(GTK_CONTAINER(win),10);
	gtk_widget_show(lbl);
*/
}
