#include "Interface.h"

GtkWidget *CreateWindow(char WindowName[]) {
    GtkWidget *Window;
    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL); // criação da janela
    gtk_window_set_title(GTK_WINDOW(Window), WindowName); // setando nome titulo da janela
    gtk_window_set_default_size(GTK_WINDOW(Window), 500, 500); // setando tamanho da janela 
    gtk_signal_connect(GTK_OBJECT(Window), "destroy", GTK_SIGNAL_FUNC(gtk_main_quit), NULL); // atribuindo a função gtk_main_quit quando a janela retornar o sinal destroy, isso quando é apertado o botão fechar janela
    gtk_window_set_resizable(GTK_WINDOW(Window), FALSE); // setando que a janela não seja redimensionada
    return Window; 
}

GtkWidget *CreateLabel(char LabelName[]) {
    GtkWidget *Label;
    Label = gtk_label_new(NULL); // criação da label
    gtk_label_set_text(GTK_LABEL(Label), LabelName); //setando texto do label
    gtk_widget_set_size_request(Label, 200, 60); // definindo tamanho do label
    return Label;
}

GtkWidget *CreateButton(char ButtonName[]) {
    GtkWidget *Button; // criação da botão
    Button = gtk_button_new_with_label(ButtonName); //setando texto do botão
    gtk_widget_set_size_request(Button, 200, 50); // definindo tamanho do botão
    return Button;
}

GtkWidget *CreateVBox() {
    GtkWidget *VBox;
    VBox = gtk_vbox_new(true, 5);
    return VBox;
}

int OrdenaSequencial(int argc, char *argv[]) {

    gtk_init(&argc, &argv);

    int *lista = (int*)malloc(MAX1 * sizeof(int));

    TXTtoLIST1(lista);

    clock_t Temp; // definindo variavel do tipo clock_t

    Temp = clock(); // iniciando contagem 
    Bubble1(lista);
    Temp = clock() - Temp; // Tempo inicial menos final

    LISTtoTXT1(lista);

    char Tempo[30];
    char LabelText[30] = {"Tempo de execucao: "};

    // para achar o tempo em milisecundos, é divido o Tempo por CLOCK_PER_SECONDS e esse é dividido por mil, por fim temos o tempo em milisecundos
    // é divido novamento por mil, para obter em segundos, pois convertendo diretamente para segundos, mostrara o tempo em segundos fechado, ou seja, sem os milisegundos
    sprintf(Tempo, "%lf", ((double)Temp)/((CLOCKS_PER_SEC/1000))/1000); // é usado o sprintf para gravar o tempo, passando o formato desejado, seja float, int, para um array de char
    strcat(LabelText, Tempo);// concatena o tempo com outra lista para pode gerar o texto do label                                           
    strcat(LabelText, " s");                                            

    GtkWidget *Window2 = CreateWindow("Lista Sequencial"), 
              *Label2  = CreateLabel(LabelText);

    GtkWidget *VBox2 = CreateVBox(); 
    
    gtk_container_add(GTK_CONTAINER(Window2), VBox2);
    gtk_box_pack_start(GTK_BOX(VBox2), Label2, false, false, 5);

    gtk_widget_show_all(Window2);

    gtk_main();
}

int OpenWindowSequencial(int argc, char *argv[]) {

    gtk_init(&argc, &argv);
    
    GtkWidget *Window = CreateWindow("Lista Sequencial"), 
              *Label  = CreateLabel("Escolha as opcoes:"), 
              *Button  = CreateButton("Gerar TXT"), 
              *Button1  = CreateButton("Ordenar");

    GtkWidget *VBox = CreateVBox(); 
    
    gtk_container_add(GTK_CONTAINER(Window), VBox);
    gtk_box_pack_start(GTK_BOX(VBox), Label, false, false, 5);
    gtk_box_pack_start(GTK_BOX(VBox), Button, false, false, 5);
    gtk_box_pack_start(GTK_BOX(VBox), Button1, false, false, 5);

    gtk_signal_connect(GTK_OBJECT(Button), "clicked", G_CALLBACK(CreateRandomTXT1), NULL);
    gtk_signal_connect(GTK_OBJECT(Button1), "clicked", G_CALLBACK(OrdenaSequencial), NULL);

    gtk_widget_show_all(Window);

    gtk_main();
}

int OrdenaEncadeada(int argc, char *argv[]) {

    gtk_init(&argc, &argv);

    nocab Cabeca;

    CriarLista(&Cabeca);

    TXTtoLIST(&Cabeca);

    clock_t Temp;

    Temp = clock();
    BubbleSort(&Cabeca);
    Temp = clock() - Temp;

    LISTtoTXT(&Cabeca);

    char Tempo[35];
    char LabelText[35] = {"Tempo de execucao: "};
    sprintf(Tempo, "%lf", ((double)Temp)/((CLOCKS_PER_SEC/1000))/1000);
    strcat(LabelText, Tempo);
    strcat(LabelText, " s");

    GtkWidget *Window1 = CreateWindow("Lista Encadeada"), 
              *Label1  = CreateLabel(LabelText);

    GtkWidget *VBox1 = CreateVBox(); 
    
    gtk_container_add(GTK_CONTAINER(Window1), VBox1);
    gtk_box_pack_start(GTK_BOX(VBox1), Label1, false, false, 5);

    gtk_widget_show_all(Window1);

    gtk_main();

}

int OpenWindowEncadeada(int argc, char *argv[]) {

    gtk_init(&argc, &argv);
    
    GtkWidget *Window = CreateWindow("Lista Encadeada"), 
              *Label  = CreateLabel("Escolha as opcoes:"), 
              *Button  = CreateButton("Gerar TXT"), 
              *Button1  = CreateButton("Ordenar");

    GtkWidget *VBox = CreateVBox(); 
    
    gtk_container_add(GTK_CONTAINER(Window), VBox);
    gtk_box_pack_start(GTK_BOX(VBox), Label, false, false, 5);
    gtk_box_pack_start(GTK_BOX(VBox), Button, false, false, 5);
    gtk_box_pack_start(GTK_BOX(VBox), Button1, false, false, 5);

    gtk_signal_connect(GTK_OBJECT(Button), "clicked", G_CALLBACK(CreateRandomTXT), NULL);
    gtk_signal_connect(GTK_OBJECT(Button1), "clicked", G_CALLBACK(OrdenaEncadeada), NULL);

    gtk_widget_show_all(Window);

    gtk_main();
}