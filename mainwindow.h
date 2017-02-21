#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <pcap.h>

#include "packettracer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void update_table(Packet packet);

private slots:
    void on_button_applyFilter_clicked();
    void on_button_close_handle_clicked();
    void on_button_capture_packet_clicked();
    void on_pushButton_filterSettings_clicked();
    void on_tableWidget_packets_cellDoubleClicked(int row, int column);


    void on_pushButton_statistics_clicked();

private:
    Ui::MainWindow *ui;

    PacketTracer packetTracer;

    int row_count; // Keep track of current row to populate with packet details
    QString status_bar_message;

    char *dev;
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;                     // Session handle
    struct bpf_program filter_expression;              // The compiled filter expression
    //char filter_exp[] = "port 443";	// The filter expression
    bpf_u_int32 mask;                   // The netmask of our sniffing device
    bpf_u_int32 net;                    // The IP of our sniffing device
    struct pcap_pkthdr header;          // The header that pcap gives us
    const u_char *packet;               // The actual packet

};

#endif // MAINWINDOW_H
