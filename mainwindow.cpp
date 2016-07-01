#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <iostream>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QProcess>

#include <qfile.h>
#include <qtextstream.h>
#include <iostream>

#include <QCoreApplication>

#include <QString>
#include <QDebug>

#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int in, lin;
    for(in=1;in<6;in++)//desativa todas as checkbox dos maps
    {
        for(lin=0;lin<10;lin++)
        {
            streams("desativar",in,lin);
        }
        lin=0;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_codec_video_stateChanged()
{
    alterar_comando(3);//altera o comando
}
void MainWindow::on_codec_audio_stateChanged()
{
    alterar_comando(3);
}

//-------------------------------------------DURAÇÃO DO TS---------------------------------------
void MainWindow::on_tempo_editingFinished()
{
    alterar_comando(5);//Altera o comando
}
//-------------------------------CORRIGIR PROBLEMA DO ESPAÇO----------------------------
QString MainWindow::verif_esp(QString comando)//na linha de comando para especificar pastas e nomes de arquivos deve-se utilizar "\ " ao invés de " "
{
//    qDebug() << comando;
    int caract;
    caract=0;
    if(comando.indexOf(" ",caract))
    {
        while (comando.indexOf(" ",caract)!=-1)
        {
            comando.replace(comando.indexOf(" ",caract),1,"\\ ");
            caract=comando.indexOf(" ",caract)+3;
//            qDebug() << comando;
        }
    }
//    qDebug() << comando;
    return comando;
}

void MainWindow::on_Rodar_clicked()
{
    QString comando;
    comando=ui->tex_comando->toPlainText();
    system(comando.toLatin1());//abre o terminal e roda  comando

//    QProcess *proc = new QProcess(this);
//    proc->start("gnome-terminal -x");
//    if (!proc->waitForStarted()) {
//    }
}





void MainWindow::on_help_clicked()
{
    system("gnome-open Help.pdf");//abre o arquivo de tutorial, (Shadow build deve estar desmarcado)
}
