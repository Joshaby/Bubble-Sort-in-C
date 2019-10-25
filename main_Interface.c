#include "Interface.h"

int main(int argc, char *argv[]) {

    gtk_init(&argc, &argv); //comando para chamar todas as funçõoes da biblioteca gtk
    
    GtkWidget *Window = CreateWindow("Algoritimo Bubble Sort"),
              *Label  = CreateLabel("Escolha uma lista :"), 
              *Button  = CreateButton("Lista Sequencial"), 
              *Button1  = CreateButton("Lista Encadeada");
    GtkWidget *VBox = CreateVBox(); //ponteiros do tipo GtkWidget para fazer wigets como janela, botões, VBox e etc

    gtk_signal_connect(GTK_OBJECT(Button), "clicked", G_CALLBACK(OpenWindowSequencial), NULL); // atribuindo funções aos botões, que no caso iram abrir outras janelas
    gtk_signal_connect(GTK_OBJECT(Button1), "clicked", G_CALLBACK(OpenWindowEncadeada), NULL);

    gtk_container_add(GTK_CONTAINER(Window), VBox); // adição do box a janela principal
    
    gtk_box_pack_start(GTK_BOX(VBox), Label, false, false, 5);
    gtk_box_pack_start(GTK_BOX(VBox), Button, false, false, 5); //empacotamento dos widgets no box
    gtk_box_pack_start(GTK_BOX(VBox), Button1, false, false, 5);

    gtk_widget_show_all(Window); // comando para exibir os widgets

    gtk_main(); // loop da janela

    return 0;
}
