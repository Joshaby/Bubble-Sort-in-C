#include "bubbleSequencial.h"
#include "bubbleEncadeada.h"
#include <time.h>
#include <gtk/gtk.h>

GtkWidget *CreateWindow(char WindowName[]);

GtkWidget *CreateLabel(char LabelName[]);

GtkWidget *CreateButton(char ButtonName[]);

GtkWidget *CreateVBox();

int OpenWindowSequencial(int argc, char *argv[]);

int OpenWindowEncadeada(int argc, char *argv[]);

int OrdenaSequencial(int argc, char *argv[]);

int OrdenaEncadeada(int argc, char *argv[]);