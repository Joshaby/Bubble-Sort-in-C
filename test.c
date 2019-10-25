#include <stdbool.h>
#include <gtk/gtk.h>

int main (int *argc, char *argv[]) {

    gtk_init(&argc, &argv); //comando para chamar todas as funçõoes da biblioteca gtk

    GtkWidget *Window, *Label, *Button, *VBox, *HBox, *HBox1; //ponteiros do tipo GtkWidget para fazer wigets como janela, botões, VBox e etc

    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL); //criação da janela
    gtk_window_set_default_size(GTK_WINDOW(Window), 550, 550); //definição para que a janela seja de tamanho 550X550
    gtk_window_set_resizable(GTK_WINDOW(Window), NULL); //faz com que a janela não seja redimensionada;
    gtk_signal_connect(G_OBJECT(Window), "destroy", GTK_SIGNAL_FUNC(gtk_main_quit), NULL); //quando a janela retorna a sinal de destroy, isso apertando o X dessa janela, ele ira ser fechada

    Label = gtk_label_new(NULL); //criação de um label
    gtk_label_set_text(GTK_LABEL(Label), "Aperte em baixo"); //coloca o texto "Aperte embaixo" no label
    gtk_widget_set_size_request(GTK_LABEL(Label), 200, 60); //defini o tamanho do label

    Button = gtk_button_new_with_label("aqui");
    gtk_widget_set_size_request(GTK_BUTTON(Button), 200, 60); //defini o tamanho do botão
    gtk_signal_connect(G_OBJECT(Button), "clicked", G_CALLBACK(gtk_main_quit), NULL); //função para qaundo o botão for apertada, a janela seja destruida

    VBox = gtk_vbox_new(false, 5); //vbox é utilizada para poder adicionar outros widget em ordem vertical
    gtk_container_add(GTK_WINDOW(Window), VBox); //adicionada um vbox a janela

    // HBox = gtk_hbox_new(true, 5); //vbox é utilizada para poder adicionar outros widget em ordem horizontal
    // HBox1 = gtk_hbox_new(true, 5); //vbox é utilizada para poder adicionar outros widget em ordem horizontal

    // gtk_box_pack_start(GTK_BOX(VBox), HBox, false, false, 5);
    // gtk_box_pack_start(GTK_BOX(VBox), HBox1, false, false, 5);
    gtk_box_pack_start(GTK_BOX(VBox), Label, false, false, 5);
    gtk_box_pack_start(GTK_BOX(VBox), Button, false, false, 5);

    //empacota o algun widget no vbox,é usado false, false, respectivamente, para ele não se expandir para direita e esquerda, encosta na borda da janela e para não expandir para cima e para baixo
    // o número 5 indica a distancia de algum widget até a borda;
    //gcc -o gtk Interface.c Interface.h main_Interface.c bubbleSequencial.c bubbleSequencial.h `pkg-config --cflags --libs gtk+-2.0`
    // ./gtk para executar
    gtk_widget_show_all(Window);

    gtk_main();

    return 0;
}
