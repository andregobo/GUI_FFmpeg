#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
//#define MAX_PACKET 500

//Botões de ajuda da aba avançados
void MainWindow::on_h_area_code_clicked()
{
    QMessageBox msgBox1;//cria a caixa de mensagem
    msgBox1.setStandardButtons(QMessageBox::Ok);
    msgBox1.setText("Area code = campo com 12 bits que corresponde ao codigo de area especificado pelos orgaos responsaveis");
    msgBox1.exec();
}
void MainWindow::on_h_guard_interval_clicked()
{
    QMessageBox msgBox1;
    msgBox1.setStandardButtons(QMessageBox::Ok);
    msgBox1.setText("Guard interval = campo com 2 bits que deve indicar o intervalo de guarda de guarda utilizado, 00 para intervalo de guarda igual a 1/32, 01 para intervalo de guarda igual a 1/16, 10 para intervalo de guarda igual a 1/8, 11 para intervalo de guarda igual a 1/4");
    msgBox1.exec();
}
void MainWindow::on_h_transmission_mode_clicked()
{
    QMessageBox msgBox1;
    msgBox1.setStandardButtons(QMessageBox::Ok);
    msgBox1.setText("Transmission mode = campo com 2 bits que indica o modo de informacao, 00 para modo 1, 01 para modo 2, 10 para modo 3, 11 nao definido");
    msgBox1.exec();
}
void MainWindow::on_h_physical_channel_clicked()
{
    QMessageBox msgBox1;
    msgBox1.setStandardButtons(QMessageBox::Ok);
    msgBox1.setText("Physical channel = numero do canal fisico ao qual o TS esta associado");
    msgBox1.exec();
}
void MainWindow::on_h_virtual_chanel_clicked()
{
    QMessageBox msgBox1;
    msgBox1.setStandardButtons(QMessageBox::Ok);
    msgBox1.setText("Virtual channel = numero do canal virtual ao qual o TS esta associado");
    msgBox1.exec();
}
void MainWindow::on_h_original_network_ID_clicked()
{
    QMessageBox msgBox1;
    msgBox1.setStandardButtons(QMessageBox::Ok);
    msgBox1.setText("Original_network_id = campo de 16 bits que serve como etiqueta para o especificar o identificador do sistema de distribuicao original.");
    msgBox1.exec();
}
//void MainWindow::on_tex_transport_stream_id_textChanged()
//{
//    alterar_comando(4);
//}
//Quando o usuário modifica o texto nas linha de edição da aba avaçado
void MainWindow::on_tex_guard_interval_textChanged()
{
    alterar_comando(4);    //comando que escreve o Comando
}
void MainWindow::on_tex_area_code_textChanged()
{
    alterar_comando(4);    
}

void MainWindow::on_tex_transmission_mode_textChanged()
{
    alterar_comando(4);    
}

void MainWindow::on_tex_physical_channel_textChanged()
{
    alterar_comando(4);    
}

void MainWindow::on_tex_virtual_channel_textChanged()
{
    alterar_comando(4);    
}

void MainWindow::on_tex_original_network_id_textChanged()
{
    alterar_comando(4);    
}

void MainWindow::on_tex_muxrate_textChanged()
{
    alterar_comando(4);    
}


