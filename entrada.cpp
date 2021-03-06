#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
//#define MAX_PACKET 500

//-------------------------------------------------------------------------VERIFICAR ENTRADA---------------------------------
void MainWindow::verificar_entrada(QString arquivo)
{
    QString ckbox, aux;
    QFile f(arquivo);//define o arquivo que será lido
    int index1, index2, numstream, i;
    f.open(QFile::ReadOnly);
    QTextStream in(&f);
    QString texto = in.readAll();// le o arquivo
    index1=0;

    if(texto.indexOf("Stream #0.")>0)//verifica as Streams, foi encontrado casos tanto casos com "Stream #0." quanto "Stream #0:"
    {
        for(numstream=0;numstream<10;numstream++)
        {
            aux= "Stream #0." + QString::number(numstream);
            qDebug() << aux;
            index1=texto.indexOf(aux);
            index2=texto.indexOf(" ",index1);
            for(i=0;i<3;i++)
            {
                index2=texto.indexOf(" ",index2+1);
            }
           // qDebug() << index1;
            if(index1>1)
            {
                ckbox=texto.mid(index1,index2-index1);
                streams(ckbox,arquivo.mid(7,1).toInt(),numstream);
            //    qDebug() << ckbox;
            }
        }
    }
    if(texto.indexOf("Stream #0:")>0)//verifica as Streams, foi encontrado casos tanto casos com "Stream #0." quanto "Stream #0:"
    {
        for(numstream=0;numstream<10;numstream++)
        {
            aux= "Stream #0:" + QString::number(numstream);
            //qDebug() << aux;
            index1=texto.indexOf(aux);
            index2=texto.indexOf(" ",index1);
            for(i=0;i<3;i++)
            {
                index2=texto.indexOf(" ",index2+1);
            }
            //qDebug() << index1;
            if(index1>1)
            {
                ckbox=texto.mid(index1,index2-index1);
                streams(ckbox,arquivo.mid(7,1).toInt(),numstream);
              //  qDebug() << ckbox;
            }
        }
    }
// Primeira implementaçãopara os maps, em determinados TS ele não funcionava corretamente
    // ------------------------------------------------------------Video--------------------------------------------------------------------------------
/*
    caracter=0;
    numstream=0;
    index1=texto.indexOf(": Video: ",caracter);
    index2=-1;
//    qDebug() << texto;
    if(index1>-1)
    {
        while(index1!=index2)
        {
            index1=texto.indexOf(": Video: ",caracter);
            index2=texto.lastIndexOf(": Video: ");
            tipo=texto.indexOf(" ",index1+11);
            ini_stream=texto.indexOf("Stream",index1-20);
            ckbox=texto.mid(ini_stream,tipo-ini_stream);
            streams(ckbox,arquivo.mid(7,1).toInt(),numstream);
            numstream=numstream+1;
            caracter=index1+9;
        }
    }
    //---------------------------------------------Audio--------------------------------------------------------------------------------
    caracter=0;
    index1=texto.indexOf(": Audio: ",caracter);
    index2=-1;
    if(index1>-1)
    {
        while(index1!=index2)
        {
            index1=texto.indexOf(": Audio: ",caracter);
            index2=texto.lastIndexOf(": Audio: ");
            tipo=texto.indexOf(" ",index1+10);
            ini_stream=texto.indexOf("Stream",index1-40);
            ckbox=texto.mid(ini_stream,tipo-ini_stream);
//            qDebug() << ckbox;
//            qDebug() << arquivo.mid(7,1).toInt();
//            qDebug() << numstream;
            streams(ckbox,arquivo.mid(7,1).toInt(),numstream);
            numstream=numstream+1;
            caracter=index1+9;
        }
    }
    // ----------------------------------------------------------Subtitle--------------------------------------------------------------------------------
    caracter=0;
    index1=texto.indexOf(": Subtitle: ",caracter);
    index2=-1;
    if(index1>-1)
    {
        while(index1!=index2)
        {
            index1=texto.indexOf(": Subtitle: ",caracter);
            index2=texto.lastIndexOf(": Subtitle: ");
            tipo=texto.indexOf(" ",index1+13);
            ini_stream=texto.indexOf("Stream",index1-20);
            ckbox=texto.mid(ini_stream,tipo-ini_stream);
            streams(ckbox,arquivo.mid(7,1).toInt(),numstream);
            numstream=numstream+1;
            caracter=index1+9;
        }
    }
*/
    f.close();
}
//-------------------------------------------------------------ENTRADAS-----------------------------------------------------------
void MainWindow::on_entrada_1_clicked()//botão de entrada clicado
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Escolha o arquivo de Entrada"));//abre janela para selecionar arquivo
    ui->tex_entrada_1->setText(filename);//escreve o caminho na linha de edição
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)//apaga os maps antigos
    {
        streams("desativar",1,i);
    }
    alterar_comando(1);// altera o comando
   // qDebug() << ui->tex_entrada_1->text();
  //  qDebug() << filename.toLatin1();
  //  qDebug() << verif_esp(ui->tex_entrada_1->text());
   // qDebug() << verif_esp(filename).toLatin1();

    system("ffmpeg -i " + ui->tex_entrada_1->text().toLatin1() + " 2>entrada1");//diz para o FFmpeg analisar a entrada e escrevo o resultado em arquivo txt
    verificar_entrada("entrada1");//escreve os maps
    multi_ativo();//altera aba multiplos programas
    if(filename!="")//se o arquivo não foi selecionado apaga todas as entradas.
    {
        ui->entrada_2->setDisabled(0);
        ui->tex_entrada_2->setDisabled(0);
        ui->excluir_entrada_2->setDisabled(0);
    }
}
void MainWindow::on_entrada_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Escolha o arquivo de Entrada"));
    ui->tex_entrada_2->setText(filename);
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",2,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + verif_esp(filename).toLatin1() + " 2>entrada2");
    verificar_entrada("entrada2");
    multi_ativo();
    if(filename!="")
    {
        ui->entrada_3->setDisabled(0);
        ui->tex_entrada_3->setDisabled(0);
        ui->excluir_entrada_3->setDisabled(0);
    }
}
void MainWindow::on_entrada_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Escolha o arquivo de Entrada"));
    ui->tex_entrada_3->setText(filename);
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",3,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + verif_esp(filename).toLatin1() + " 2>entrada3");
    verificar_entrada("entrada3");
    multi_ativo();
    if(filename!="")
    {
        ui->entrada_4->setDisabled(0);
        ui->tex_entrada_4->setDisabled(0);
        ui->excluir_entrada_4->setDisabled(0);
    }
}
void MainWindow::on_entrada_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Escolha o arquivo de Entrada"));
    ui->tex_entrada_4->setText(filename);
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",4,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + verif_esp(filename).toLatin1() + " 2>entrada4");
    verificar_entrada("entrada4");
    multi_ativo();
    if(filename!="")
    {
        ui->entrada_5->setDisabled(0);
        ui->tex_entrada_5->setDisabled(0);
        ui->excluir_entrada_5->setDisabled(0);
    }
}
void MainWindow::on_entrada_5_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Escolha o arquivo de Entrada"));
    ui->tex_entrada_5->setText(filename);
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",5,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + verif_esp(filename).toLatin1() + " 2>entrada5");
    verificar_entrada("entrada5");
    multi_ativo();
}
//--------------------------------------------------------------EXCLUIR ENTRADAS-----------------------------------------------------------
void MainWindow::on_excluir_entrada_1_clicked()//botão excluir entrada clicado
{
    //reinicia os multiplos programas
    ui->multiprogramas->setChecked(0);
    on_multiprogramas_clicked();

    ui->tex_entrada_1->setText("");//exclui texto da linha de edição
    alterar_comando(1);//altera o comando
    int lin;//apaga entradas
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",1,lin);
    }
    alterar_comando(2);
    desab_entrada_2();//exclui as entradas de maior numero
    on_excluir_entrada_2_clicked();
}
void MainWindow::on_excluir_entrada_2_clicked()
{
    //reinicia os multiplos programas
    ui->multiprogramas->setChecked(0);
    on_multiprogramas_clicked();
    ui->tex_entrada_2->setText("");
    alterar_comando(1);
    int lin;//apaga entradas
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",2,lin);
    }
    desab_entrada_3();
    on_excluir_entrada_3_clicked();
    alterar_comando(2);
}
void MainWindow::on_excluir_entrada_3_clicked()
{
    //reinicia os multiplos programas
    ui->multiprogramas->setChecked(0);
    on_multiprogramas_clicked();
    ui->tex_entrada_3->setText("");
    alterar_comando(1);
    int lin;//apaga entradas
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",3,lin);
    }
    desab_entrada_4();
    on_excluir_entrada_4_clicked();
    alterar_comando(2);
}
void MainWindow::on_excluir_entrada_4_clicked()
{
    //reinicia os multiplos programas
    ui->multiprogramas->setChecked(0);
    on_multiprogramas_clicked();
    ui->tex_entrada_4->setText("");
    alterar_comando(1);
    int lin;//apaga entradas
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",4,lin);
    }
    desab_entrada_5();
    on_excluir_entrada_5_clicked();
    alterar_comando(2);
}
void MainWindow::on_excluir_entrada_5_clicked()
{
    //reinicia os multiplos programas
    ui->multiprogramas->setChecked(0);
    on_multiprogramas_clicked();
    ui->tex_entrada_5->setText("");
    alterar_comando(1);
    int lin;//apaga entradas
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",5,lin);
    }
    alterar_comando(2);
}
//---------------------------------------------------------ALTERAÇÃO PELO USUARIO-----------------------------------------------------------------
void MainWindow::on_tex_entrada_1_editingFinished()//quando o usuario altera manualmente a linha de edição
{
    int i;//apaga os maps antigos antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",1,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + ui->tex_entrada_1->text().toLatin1() + " 2>entrada1");//analisa com o FFmpeg a entrada
    verificar_entrada("entrada1");
    alterar_comando(2);
    if(ui->tex_entrada_1->text()=="")//se o usuario excluiu o texto da entrada, exclui as entradas de umero maior
    {
        desab_entrada_2();
    }
}
void MainWindow::on_tex_entrada_2_editingFinished()
{
    QString filename=ui->tex_entrada_2->text();
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",2,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + ui->tex_entrada_2->text().toLatin1() + " 2>entrada2");
    verificar_entrada("entrada2");
    alterar_comando(2);


    {
        desab_entrada_3();
    }
}
void MainWindow::on_tex_entrada_3_editingFinished()
{
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",3,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + ui->tex_entrada_3->text().toLatin1() + " 2>entrada3");
    verificar_entrada("entrada3");
    alterar_comando(2);

    if(ui->tex_entrada_3->text()=="")
    {
        desab_entrada_4();
    }
}
void MainWindow::on_tex_entrada_4_editingFinished()
{
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",4,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + ui->tex_entrada_4->text().toLatin1() + " 2>entrada4");
    verificar_entrada("entrada4");
    alterar_comando(2);
    if(ui->tex_entrada_4->text()=="")
    {
        desab_entrada_5();
    }
}
void MainWindow::on_tex_entrada_5_editingFinished()
{
    int i;//apaga as entradas antigas
    for (i=0;i<10;i++)
    {
        streams("desativar",5,i);
    }
    alterar_comando(1);
    system("ffmpeg -i " + ui->tex_entrada_5->text().toLatin1() + " 2>entrada5");
    verificar_entrada("entrada5");
    alterar_comando(2);

}
//--------------------------DESABILITAR ENTRADAS----------------------------------
void MainWindow::desab_entrada_2()//impossibilita o usuário de defiir entrada
{
    int lin;//apaga maps da entrada
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",2,lin);
    }
    ui->tex_entrada_2->setText("");
    ui->entrada_2->setDisabled(1);
    ui->tex_entrada_2->setDisabled(1);
    ui->excluir_entrada_2->setDisabled(1);
    desab_entrada_3();
    desab_entrada_4();
    alterar_comando(2);
}
void MainWindow::desab_entrada_3()
{
    int lin;//apaga maps da entrada
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",3,lin);
    }
    ui->tex_entrada_3->setText("");
    ui->entrada_3->setDisabled(1);
    ui->tex_entrada_3->setDisabled(1);
    ui->excluir_entrada_3->setDisabled(1);
    desab_entrada_4();
    alterar_comando(2);
}
void MainWindow::desab_entrada_4()
{
    int lin;//apaga maps da entrada
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",4,lin);
    }
    ui->tex_entrada_4->setText("");
    ui->entrada_4->setDisabled(1);
    ui->tex_entrada_4->setDisabled(1);
    ui->excluir_entrada_4->setDisabled(1);
    alterar_comando(2);
    desab_entrada_5();
}

void MainWindow::desab_entrada_5()
{
    int lin;//apaga maps da entrada
    for(lin=0;lin<10;lin++)
    {
        streams("desativar",5,lin);
    }
    ui->tex_entrada_5->setText("");
    ui->entrada_5->setDisabled(1);
    ui->tex_entrada_5->setDisabled(1);
    ui->excluir_entrada_5->setDisabled(1);
    alterar_comando(2);
}
