#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include "uart_v2.h"
#include "chordProcessing.h"

// main menu variables
GtkWidget	*window1;
GtkWidget	*box1;
GtkWidget	*mode1;
GtkWidget	*mode2;
GtkBuilder	*builder;

// mode 1 variables
GtkWidget	*window2;
GtkWidget	*box2;
GtkWidget	*main1;
GtkWidget	*button2;
GtkWidget	*button3;
GtkWidget	*button4;
GtkWidget	*button5;
GtkWidget	*button6;

// mode 2 variables
GtkWidget	*window3;
GtkWidget	*box3;
GtkWidget	*main2;
GtkWidget	*start;

// recording variables
GtkWidget	*window4;
GtkWidget	*box4;
GtkWidget	*sec5;
GtkWidget	*sec10;
GtkWidget	*sec15;
GtkWidget	*sec20;
GtkWidget	*sec25;
GtkWidget	*sec30;

// seconds variable
char sec[3];

int main(int argc, char *argv[]) {
	uart_init();
	// init Gtk
	gtk_init(&argc, &argv);
	
// Establish contact with xml code used to adjust widget settings
	builder = gtk_builder_new_from_file("ui.glade");
	window1 = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
	window2 = GTK_WIDGET(gtk_builder_get_object(builder, "window2"));
	window3 = GTK_WIDGET(gtk_builder_get_object(builder, "window3"));
	window4 = GTK_WIDGET(gtk_builder_get_object(builder, "window4"));
	//g_signal_connect(window1, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_builder_connect_signals(builder, NULL);
	
	// main menu
	box1 = GTK_WIDGET(gtk_builder_get_object(builder, "box1"));
	mode1 = GTK_WIDGET(gtk_builder_get_object(builder, "mode1"));
	mode2 = GTK_WIDGET(gtk_builder_get_object(builder, "mode2"));
	
	// mode 1
	box2 = GTK_WIDGET(gtk_builder_get_object(builder, "box2"));
	main1 = GTK_WIDGET(gtk_builder_get_object(builder, "main1"));
	button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
	button3 = GTK_WIDGET(gtk_builder_get_object(builder, "button3"));
	button4 = GTK_WIDGET(gtk_builder_get_object(builder, "button4"));
	button5 = GTK_WIDGET(gtk_builder_get_object(builder, "button5"));
	button6 = GTK_WIDGET(gtk_builder_get_object(builder, "button6"));
	
	// mode 2
	box3 = GTK_WIDGET(gtk_builder_get_object(builder, "box3"));
	main2 = GTK_WIDGET(gtk_builder_get_object(builder, "main2"));
	start = GTK_WIDGET(gtk_builder_get_object(builder, "start"));
	
	// recording
	box4 = GTK_WIDGET(gtk_builder_get_object(builder, "box4"));
	sec5 = GTK_WIDGET(gtk_builder_get_object(builder, "5s"));
	sec10 = GTK_WIDGET(gtk_builder_get_object(builder, "10s"));
	sec15 = GTK_WIDGET(gtk_builder_get_object(builder, "15s"));
	sec20 = GTK_WIDGET(gtk_builder_get_object(builder, "20s"));
	sec25 = GTK_WIDGET(gtk_builder_get_object(builder, "25s"));
	sec30 = GTK_WIDGET(gtk_builder_get_object(builder, "30s"));	
	
	gtk_widget_show(window1);
	gtk_widget_set_size_request(GTK_WIDGET(window1), 800, 400);
	
	gtk_main();
	
	return EXIT_SUCCESS;
}

// shows pre-programmed songs window
void on_mode1_clicked(GtkButton *m1) {
	gtk_widget_hide(window1);
	gtk_widget_show(window2);
	gtk_widget_set_size_request(GTK_WIDGET(window2), 800, 400);
}

// shows listening mode window
void on_mode2_clicked(GtkButton *m2) {
	gtk_widget_hide(window1);
	gtk_widget_show(window4);
	gtk_widget_set_size_request(GTK_WIDGET(window4), 800, 400);
}

// 5 seconds of recording
void on_5s_clicked(GtkButton *sec5) {
	gtk_widget_hide(window4);
	gtk_widget_show(window3);
	gtk_widget_set_size_request(GTK_WIDGET(window3), 800, 400);
	strcpy(sec, "5");
}

// 10 seconds of recording
void on_10s_clicked(GtkButton *sec10) {
	gtk_widget_hide(window4);
	gtk_widget_show(window3);
	gtk_widget_set_size_request(GTK_WIDGET(window3), 800, 400);
	strcpy(sec, "10");
}

// 15 seconds of recording
void on_15s_clicked(GtkButton *sec15) {
	gtk_widget_hide(window4);
	gtk_widget_show(window3);
	gtk_widget_set_size_request(GTK_WIDGET(window3), 800, 400);
	strcpy(sec, "15");
}

// 20 seconds of recording
void on_20s_clicked(GtkButton *sec20) {
	gtk_widget_hide(window4);
	gtk_widget_show(window3);
	gtk_widget_set_size_request(GTK_WIDGET(window3), 800, 400);
	strcpy(sec, "20");
}

// 25 seconds of recording
void on_25s_clicked(GtkButton *sec25) {
	gtk_widget_hide(window4);
	gtk_widget_show(window3);
	gtk_widget_set_size_request(GTK_WIDGET(window3), 800, 400);
	strcpy(sec, "25");
}

// 30 seconds of recording
void on_30s_clicked(GtkButton *sec30) {
	gtk_widget_hide(window4);
	gtk_widget_show(window3);
	gtk_widget_set_size_request(GTK_WIDGET(window3), 800, 400);
	strcpy(sec, "30");
}

// return to main menu in mode 1
void on_main1_clicked(GtkButton *r1) {
	gtk_widget_hide(window2);
	gtk_widget_show(window1);
}

// return to main menu in mode 2
void on_main2_clicked(GtkButton *r2) {
	gtk_widget_hide(window3);
	gtk_widget_show(window1);
}

// Adventure Time
void on_button2_clicked(GtkButton *s1) {
	uart_write("1");
}

// Riptide
void on_button3_clicked(GtkButton *s2) {
	uart_write("2");
}

// Somewhere Over The Rainbow
void on_button4_clicked(GtkButton *s3) {
	uart_write("3");
}

// Can't Help Falling In Love
void on_button5_clicked(GtkButton *s4) {
	uart_write("4");
}

// Looking Out For You
void on_button6_clicked(GtkButton *s5) {
	uart_write("5");
}

// Start Listening
void on_start_clicked(GtkButton *start) {
	uart_write("6");
  // system command to record audio
	char str1[] = "arecord -d ";
	char str2[] = " -r 44100 -D sysdefault:CARD=2 > audio.wav";
	char result[50];
	strcpy(result, str1);
	strcat(result, sec);
	strcat(result, str2);
	system(result);
  // system command to run chord extraction algorithm
	system("./streaming_extractor audio.wav audio.txt");
	chordparse();
}
