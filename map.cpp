#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
//#define MAX_PACKET 500


//--------------------------------------------------CONTROLE DE CKBOX DOS MAPS (STREAMS)----------------------------------
QString MainWindow::map_multi_prog(int cont)//chamado para escrever as configurações de map
{
    switch (cont)
        {
        case 1:
            return multi_map_choice(multi_conexao(1),1,1);
        break;
        case 2:
            return multi_map_choice(multi_conexao(2),1,2);
        break;
        case 3:
            return multi_map_choice(multi_conexao(3),1,3);
        break;
        case 4:
            return multi_map_choice(multi_conexao(4),1,4);
        break;
        case 5:
            return multi_map_choice(multi_conexao(5),1,5);
        break;
        case 6:
            return multi_map_choice(multi_conexao(1),2,1);
        break;
        case 7:
            return multi_map_choice(multi_conexao(2),2,2);
        break;
        case 8:
            return multi_map_choice(multi_conexao(3),2,3);
        break;
        case 9:
            return multi_map_choice(multi_conexao(4),2,4);
        break;
        case 10:
            return multi_map_choice(multi_conexao(5),2,5);
        break;

        }
    return "";
}
QString MainWindow::multi_map_choice(QString map,int choice, int in)
{
    if(choice==1)
    {
        if(map.length()==18)//retorna map de vídeo
        {
            return map.mid(0,9);
        }
        else
        {
             //qDebug() << ui->abas->currentIndex();
            if(map!="0"&&ui->abas->currentIndex()==2)//verifica se realmente existem duas streams na entradas
            {
                QMessageBox msgBox1;//informa o usuário do erro
                msgBox1.setStandardButtons(QMessageBox::Ok);
                msgBox1.setText("Deve-se selecionar duas streams em cada entrada utilizada. Verifique programa "+QString::number(in));
                msgBox1.exec();
            }
            return "";
        }

    }
    else
    {
        if(map.length()==18)
        {
            return map.mid(9,9);//retorna map de áudio
        }
        else
        {
            return "";
        }
    }
}

QString MainWindow::multi_conexao(int prog)//faz a relação programa/entrada
{
    switch (prog)
        {
        case 1:
            if(ui->prog1_entra1->isChecked())
            {
                return multi_ret_entrada(1);
            }
            if(ui->prog1_entra2->isChecked())
            {
                return multi_ret_entrada(2);
            }
            if(ui->prog1_entra3->isChecked())
            {
                return multi_ret_entrada(3);
            }
            if(ui->prog1_entra4->isChecked())
            {
                return multi_ret_entrada(4);
            }
            if(ui->prog1_entra5->isChecked())
            {
                return multi_ret_entrada(5);
            }
        break;
        case 2:
            if(ui->prog2_entra1->isChecked())
            {
                return multi_ret_entrada(1);
            }
            if(ui->prog2_entra2->isChecked())
            {
                return multi_ret_entrada(2);
            }
            if(ui->prog2_entra3->isChecked())
            {
                return multi_ret_entrada(3);
            }
            if(ui->prog2_entra4->isChecked())
            {
                return multi_ret_entrada(4);
            }
            if(ui->prog2_entra5->isChecked())
            {
                return multi_ret_entrada(5);
            }
        break;
        case 3:
            if(ui->prog3_entra1->isChecked())
            {
                return multi_ret_entrada(1);
            }
            if(ui->prog3_entra2->isChecked())
            {
                return multi_ret_entrada(2);
            }
            if(ui->prog3_entra3->isChecked())
            {
                return multi_ret_entrada(3);
            }
            if(ui->prog3_entra4->isChecked())
            {
                return multi_ret_entrada(4);
            }
            if(ui->prog3_entra5->isChecked())
            {
                return multi_ret_entrada(5);
            }
        break;
        case 4:
            if(ui->prog4_entra1->isChecked())
            {
                return multi_ret_entrada(1);
            }
            if(ui->prog4_entra2->isChecked())
            {
                return multi_ret_entrada(2);
            }
            if(ui->prog4_entra3->isChecked())
            {
                return multi_ret_entrada(3);
            }
            if(ui->prog4_entra4->isChecked())
            {
                return multi_ret_entrada(4);
            }
            if(ui->prog4_entra5->isChecked())
            {
                return multi_ret_entrada(5);
            }
        case 5:
            if(ui->prog5_entra1->isChecked())
            {
                return multi_ret_entrada(1);
            }
            if(ui->prog5_entra2->isChecked())
            {
                return multi_ret_entrada(2);
            }
            if(ui->prog5_entra3->isChecked())
            {
                return multi_ret_entrada(3);
            }
            if(ui->prog5_entra4->isChecked())
            {
                return multi_ret_entrada(4);
            }
            if(ui->prog5_entra5->isChecked())
            {
                return multi_ret_entrada(5);
            }
        break;
    }
    return "0";
}
QString MainWindow::multi_ret_entrada(int in)//constroi o texto do map
{
    int lin;
    QString map;
    map="";
    for(lin=0;lin<10;lin++)
    {
       if(streams("ckbox",in,lin))//verdadeiro se a stream foi selecionada
       {
           map= map + " -map " + QString::number(in-1) + ":" + QString::number(lin);
       }
    }
    lin=0;
    return map;
}
void MainWindow::multi_ativo()//ativa multiplos programas
{
    int entradas;
    entradas=num_entrada();//verifica o numero de entradas
//    qDebug() << QString::number(entrsadas);
    switch (entradas)
        {
        case 0:
            ui->des_prog1->setChecked(1);
            ui->prog1_entra1->setDisabled(1);
            ui->prog1_entra2->setDisabled(1);
            ui->prog1_entra3->setDisabled(1);
            ui->prog1_entra4->setDisabled(1);
            ui->prog1_entra5->setDisabled(1);
            ui->multiprogramas->setChecked(0);
            alterar_comando(4);
            ui->des_prog1->setChecked(1);
            on_des_prog2_clicked();
            ui->des_prog2->setChecked(1);
            ui->des_prog2->setDisabled(1);
            ui->prog2_entra1->setDisabled(1);
            ui->prog2_entra2->setDisabled(1);
            ui->prog2_entra3->setDisabled(1);
            ui->prog2_entra4->setDisabled(1);
            ui->prog1_entra5->setDisabled(1);
        break;

        case 1:
            ui->prog1_entra1->setDisabled(0);
            ui->prog1_entra2->setDisabled(1);
            ui->prog1_entra3->setDisabled(1);
            ui->prog1_entra4->setDisabled(1);
            ui->prog1_entra5->setDisabled(1);
        break;
        case 2:
            ui->prog1_entra1->setDisabled(0);
            ui->prog1_entra2->setDisabled(0);
            ui->prog1_entra3->setDisabled(1);
            ui->prog1_entra4->setDisabled(1);
            ui->prog1_entra5->setDisabled(1);
        break;
        case 3:
            ui->prog1_entra1->setDisabled(0);
            ui->prog1_entra2->setDisabled(0);
            ui->prog1_entra3->setDisabled(0);
            ui->prog1_entra4->setDisabled(1);
            ui->prog1_entra5->setDisabled(1);
        break;
        case 4:
            ui->prog1_entra1->setDisabled(0);
            ui->prog1_entra2->setDisabled(0);
            ui->prog1_entra3->setDisabled(0);
            ui->prog1_entra4->setDisabled(0);
            ui->prog1_entra5->setDisabled(1);
        break;
        case 5:
            ui->prog1_entra1->setDisabled(0);
            ui->prog1_entra2->setDisabled(0);
            ui->prog1_entra3->setDisabled(0);
            ui->prog1_entra4->setDisabled(0);
            ui->prog1_entra5->setDisabled(0);
        break;
        }
    if(ui->prog1_entra1->isChecked()||ui->prog1_entra2->isChecked()||ui->prog1_entra3->isChecked()||ui->prog1_entra4->isChecked()||ui->prog1_entra5->isChecked())
    {
        ui->multiprogramas->setChecked(1);
        switch (entradas)
            {
            case 1:
                ui->des_prog2->setDisabled(0);
                ui->prog2_entra1->setDisabled(0);
                ui->prog2_entra2->setDisabled(1);
                ui->prog2_entra3->setDisabled(1);
                ui->prog2_entra4->setDisabled(1);
                ui->prog2_entra5->setDisabled(1);
            break;
            case 2:
                ui->des_prog2->setDisabled(0);
                ui->prog2_entra1->setDisabled(0);
                ui->prog2_entra2->setDisabled(0);
                ui->prog2_entra3->setDisabled(1);
                ui->prog2_entra4->setDisabled(1);
                ui->prog2_entra5->setDisabled(1);
            break;
            case 3:
                ui->des_prog2->setDisabled(0);
                ui->prog2_entra1->setDisabled(0);
                ui->prog2_entra2->setDisabled(0);
                ui->prog2_entra3->setDisabled(0);
                ui->prog2_entra4->setDisabled(1);
                ui->prog2_entra5->setDisabled(1);
            break;
            case 4:
                ui->des_prog2->setDisabled(0);
                ui->prog2_entra1->setDisabled(0);
                ui->prog2_entra2->setDisabled(0);
                ui->prog2_entra3->setDisabled(0);
                ui->prog2_entra4->setDisabled(0);
                ui->prog2_entra5->setDisabled(1);
            break;
            case 5:
                ui->des_prog2->setDisabled(0);
                ui->prog2_entra1->setDisabled(0);
                ui->prog2_entra2->setDisabled(0);
                ui->prog2_entra3->setDisabled(0);
                ui->prog2_entra4->setDisabled(0);
                ui->prog2_entra5->setDisabled(0);
            break;
            }
    }
    else
    {
        ui->des_prog2->setDisabled(1);
        ui->prog2_entra1->setDisabled(1);
        ui->prog2_entra2->setDisabled(1);
        ui->prog2_entra3->setDisabled(1);
        ui->prog2_entra4->setDisabled(1);
        ui->prog2_entra5->setDisabled(1);
    }
    if(ui->prog2_entra1->isChecked()||ui->prog2_entra2->isChecked()||ui->prog2_entra3->isChecked()||ui->prog2_entra4->isChecked()||ui->prog2_entra5->isChecked())
    {
        switch (entradas)
            {
            case 1:
                ui->des_prog3->setDisabled(0);
                ui->prog3_entra1->setDisabled(0);
                ui->prog3_entra2->setDisabled(1);
                ui->prog3_entra3->setDisabled(1);
                ui->prog3_entra4->setDisabled(1);
                ui->prog3_entra5->setDisabled(1);
            break;
            case 2:
                ui->des_prog3->setDisabled(0);
                ui->prog3_entra1->setDisabled(0);
                ui->prog3_entra2->setDisabled(0);
                ui->prog3_entra3->setDisabled(1);
                ui->prog3_entra4->setDisabled(1);
                ui->prog3_entra5->setDisabled(1);
            break;
            case 3:
                ui->des_prog3->setDisabled(0);
                ui->prog3_entra1->setDisabled(0);
                ui->prog3_entra2->setDisabled(0);
                ui->prog3_entra3->setDisabled(0);
                ui->prog3_entra4->setDisabled(1);
                ui->prog3_entra5->setDisabled(1);
            break;
            case 4:
                ui->des_prog3->setDisabled(0);
                ui->prog3_entra1->setDisabled(0);
                ui->prog3_entra2->setDisabled(0);
                ui->prog3_entra3->setDisabled(0);
                ui->prog3_entra4->setDisabled(0);
                ui->prog3_entra5->setDisabled(1);
            break;
            case 5:
                ui->des_prog3->setDisabled(0);
                ui->prog3_entra1->setDisabled(0);
                ui->prog3_entra2->setDisabled(0);
                ui->prog3_entra3->setDisabled(0);
                ui->prog3_entra4->setDisabled(0);
                ui->prog3_entra5->setDisabled(0);
            break;
            }
    }
    else
    {
        ui->des_prog3->setDisabled(1);
        ui->prog3_entra1->setDisabled(1);
        ui->prog3_entra2->setDisabled(1);
        ui->prog3_entra3->setDisabled(1);
        ui->prog3_entra4->setDisabled(1);
        ui->prog3_entra5->setDisabled(1);
    }
    if(ui->prog3_entra1->isChecked()||ui->prog3_entra2->isChecked()||ui->prog3_entra3->isChecked()||ui->prog3_entra4->isChecked()||ui->prog3_entra5->isChecked())
    {
        switch (entradas)
            {
            case 1:
                ui->des_prog4->setDisabled(0);
                ui->prog4_entra1->setDisabled(0);
                ui->prog4_entra2->setDisabled(1);
                ui->prog4_entra3->setDisabled(1);
                ui->prog4_entra4->setDisabled(1);
                ui->prog4_entra5->setDisabled(1);
            break;
            case 2:
                ui->des_prog4->setDisabled(0);
                ui->prog4_entra1->setDisabled(0);
                ui->prog4_entra2->setDisabled(0);
                ui->prog4_entra3->setDisabled(1);
                ui->prog4_entra4->setDisabled(1);
                ui->prog4_entra5->setDisabled(1);
            break;
            case 3:
                ui->des_prog4->setDisabled(0);
                ui->prog4_entra1->setDisabled(0);
                ui->prog4_entra2->setDisabled(0);
                ui->prog4_entra3->setDisabled(0);
                ui->prog4_entra4->setDisabled(1);
                ui->prog4_entra5->setDisabled(1);
            break;
            case 4:
                ui->des_prog4->setDisabled(0);
                ui->prog4_entra1->setDisabled(0);
                ui->prog4_entra2->setDisabled(0);
                ui->prog4_entra3->setDisabled(0);
                ui->prog4_entra4->setDisabled(0);
                ui->prog4_entra5->setDisabled(1);
            break;
            case 5:
                ui->des_prog4->setDisabled(0);
                ui->prog4_entra1->setDisabled(0);
                ui->prog4_entra2->setDisabled(0);
                ui->prog4_entra3->setDisabled(0);
                ui->prog4_entra4->setDisabled(0);
                ui->prog4_entra5->setDisabled(0);
            break;
            }
    }
    else
    {
        ui->des_prog4->setDisabled(1);
        ui->prog4_entra1->setDisabled(1);
        ui->prog4_entra2->setDisabled(1);
        ui->prog4_entra3->setDisabled(1);
        ui->prog4_entra4->setDisabled(1);
        ui->prog4_entra5->setDisabled(1);
    }
    if(ui->prog4_entra1->isChecked()||ui->prog4_entra2->isChecked()||ui->prog4_entra3->isChecked()||ui->prog4_entra4->isChecked()||ui->prog4_entra5->isChecked())
    {
        switch (entradas)
            {
            case 1:
                ui->des_prog5->setDisabled(0);
                ui->prog5_entra1->setDisabled(0);
                ui->prog5_entra2->setDisabled(1);
                ui->prog5_entra3->setDisabled(1);
                ui->prog5_entra4->setDisabled(1);
                ui->prog5_entra5->setDisabled(1);
            break;
            case 2:
                ui->des_prog5->setDisabled(0);
                ui->prog5_entra1->setDisabled(0);
                ui->prog5_entra2->setDisabled(0);
                ui->prog5_entra3->setDisabled(1);
                ui->prog5_entra4->setDisabled(1);
                ui->prog5_entra5->setDisabled(1);
            break;
            case 3:
                ui->des_prog5->setDisabled(0);
                ui->prog5_entra1->setDisabled(0);
                ui->prog5_entra2->setDisabled(0);
                ui->prog5_entra3->setDisabled(0);
                ui->prog5_entra4->setDisabled(1);
                ui->prog5_entra5->setDisabled(1);
            break;
            case 4:
                ui->des_prog5->setDisabled(0);
                ui->prog5_entra1->setDisabled(0);
                ui->prog5_entra2->setDisabled(0);
                ui->prog5_entra3->setDisabled(0);
                ui->prog5_entra4->setDisabled(0);
                ui->prog5_entra5->setDisabled(1);
            break;

            case 5:
                ui->des_prog5->setDisabled(0);
                ui->prog5_entra1->setDisabled(0);
                ui->prog5_entra2->setDisabled(0);
                ui->prog5_entra3->setDisabled(0);
                ui->prog5_entra4->setDisabled(0);
                ui->prog5_entra5->setDisabled(0);
            break;
            }
    }
    else
    {
        ui->des_prog5->setDisabled(1);
        ui->prog5_entra1->setDisabled(1);
        ui->prog5_entra2->setDisabled(1);
        ui->prog5_entra3->setDisabled(1);
        ui->prog5_entra4->setDisabled(1);
        ui->prog5_entra5->setDisabled(1);
    }
    if(ui->des_prog2->isChecked())
    {
        ui->des_prog3->setDisabled(1);
        ui->prog3_entra1->setDisabled(1);
        ui->prog3_entra2->setDisabled(1);
        ui->prog3_entra3->setDisabled(1);
        ui->prog3_entra4->setDisabled(1);
        ui->prog3_entra5->setDisabled(1);
    }
}

int MainWindow::num_entrada()//informa numero de entradas
{
    if(ui->tex_entrada_1->text()!="")
    {
        if(ui->tex_entrada_2->text()!="")
        {
            if(ui->tex_entrada_3->text()!="")
            {
                if(ui->tex_entrada_4->text()!="")
                {
                    if(ui->tex_entrada_5->text()!="")
                    {
                        return 5;
                    }
                    return 4;
                }
                return 3;
            }
            return 2;
        }
        return 1;
    }
    return 0;
}
int MainWindow::num_programas()//informa numeros de programas

{
    if(ui->prog1_entra1->isChecked()||ui->prog1_entra2->isChecked()||ui->prog1_entra3->isChecked()||ui->prog1_entra4->isChecked()||ui->prog1_entra5->isChecked())
    {
        if(ui->prog2_entra1->isChecked()||ui->prog2_entra2->isChecked()||ui->prog2_entra3->isChecked()||ui->prog2_entra4->isChecked()||ui->prog2_entra5->isChecked())
        {
            if(ui->prog3_entra1->isChecked()||ui->prog3_entra2->isChecked()||ui->prog3_entra3->isChecked()||ui->prog3_entra4->isChecked()||ui->prog3_entra5->isChecked())
            {
                if(ui->prog4_entra1->isChecked()||ui->prog4_entra2->isChecked()||ui->prog4_entra3->isChecked()||ui->prog4_entra4->isChecked()||ui->prog4_entra5->isChecked())
                {
                    if(ui->prog5_entra1->isChecked()||ui->prog5_entra2->isChecked()||ui->prog5_entra3->isChecked()||ui->prog5_entra4->isChecked()||ui->prog5_entra5->isChecked())
                    {
                       return 5;
                    }
                    return 4;
                }
                return 3;
            }
            return 2;
        }
        return 1;
    }
    return 0;
}

int MainWindow::streams(QString nome, int entrada, int indice)//altera maps
{

    switch (entrada)
        {
        case 1:
            switch (indice)
            {
            case 0:
                if(nome=="desativar")
                {
                    ui->input1_0x0->setChecked(0);
                    ui->input1_0x0->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input1_0x0->checkState();
                }
                else
                {
                    ui->input1_0x0->setVisible(1);
                    ui->input1_0x0->setText(nome);
                }
            break;
            case 1:
            if(nome=="desativar")
            {
                ui->input1_0x1->setChecked(0);
                ui->input1_0x1->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x1->checkState();
            }
            else
            {
                ui->input1_0x1->setVisible(1);
                ui->input1_0x1->setText(nome);
            }
        break;
       case 2:
            if(nome=="desativar")
            {
                ui->input1_0x2->setChecked(0);
                ui->input1_0x2->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x2->checkState();
            }
            else
            {
                ui->input1_0x2->setVisible(1);
                ui->input1_0x2->setText(nome);
            }
        break;
       case 3:
            if(nome=="desativar")
            {
                ui->input1_0x3->setChecked(0);
                ui->input1_0x3->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x3->checkState();
            }
            else
            {
                ui->input1_0x3->setVisible(1);
                ui->input1_0x3->setText(nome);
            }
        break;
       case 4:
            if(nome=="desativar")
            {
                ui->input1_0x4->setChecked(0);
                ui->input1_0x4->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x4->checkState();
            }
            else
            {
                ui->input1_0x4->setVisible(1);
                ui->input1_0x4->setText(nome);
            }
        break;
       case 5:
            if(nome=="desativar")
            {
                ui->input1_0x5->setChecked(0);
                ui->input1_0x5->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x5->checkState();
            }
            else
            {
                ui->input1_0x5->setVisible(1);
                ui->input1_0x5->setText(nome);
            }
        break;
       case 6:
            if(nome=="desativar")
            {
                ui->input1_0x6->setChecked(0);
                ui->input1_0x6->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x6->checkState();
            }
            else
            {
                ui->input1_0x6->setVisible(1);
                ui->input1_0x6->setText(nome);
            }
        break;
       case 7:
            if(nome=="desativar")
            {
                ui->input1_0x7->setChecked(0);
                ui->input1_0x7->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x7->checkState();
            }
            else
            {
                ui->input1_0x7->setVisible(1);
                ui->input1_0x7->setText(nome);
            }
        break;
       case 8:
            if(nome=="desativar")
            {
                ui->input1_0x8->setChecked(0);
                ui->input1_0x8->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x8->checkState();
            }
            else
            {
                ui->input1_0x8->setVisible(1);
                ui->input1_0x8->setText(nome);
            }
        break;
       case 9:
            if(nome=="desativar")
            {
                ui->input1_0x9->setChecked(0);
                ui->input1_0x9->setVisible(0);
            }
                else if (nome=="ckbox")
            {
                   return ui->input1_0x9->checkState();
            }
            else
            {
                ui->input1_0x9->setVisible(1);
                ui->input1_0x9->setText(nome);
            }
        break;
        }
        break;
        case 2:
            switch (indice)
            {
            case 0:
                if(nome=="desativar")
                {
                    ui->input2_0x0->setChecked(0);
                    ui->input2_0x0->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x0->checkState();
                }
                else
                {
                    ui->input2_0x0->setVisible(1);
                    ui->input2_0x0->setText(nome);
                }
            break;
           case 1:
                if(nome=="desativar")
                {
                    ui->input2_0x1->setChecked(0);
                    ui->input2_0x1->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x1->checkState();
                }
                else
                {
                    ui->input2_0x1->setVisible(1);
                    ui->input2_0x1->setText(nome);
                }
            break;
           case 2:
                if(nome=="desativar")
                {
                    ui->input2_0x2->setChecked(0);
                    ui->input2_0x2->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x2->checkState();
                }
                else
                {
                    ui->input2_0x2->setVisible(1);
                    ui->input2_0x2->setText(nome);
                }
            break;
           case 3:
                if(nome=="desativar")
                {
                    ui->input2_0x3->setChecked(0);
                    ui->input2_0x3->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x3->checkState();
                }
                else
                {
                    ui->input2_0x3->setVisible(1);
                    ui->input2_0x3->setText(nome);
                }
            break;
           case 4:
                if(nome=="desativar")
                {
                    ui->input2_0x4->setChecked(0);
                    ui->input2_0x4->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x4->checkState();
                }
                else
                {
                    ui->input2_0x4->setVisible(1);
                    ui->input2_0x4->setText(nome);
                }
            break;
           case 5:
                if(nome=="desativar")
                {
                    ui->input2_0x5->setChecked(0);
                    ui->input2_0x5->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x5->checkState();
                }
                else
                {
                    ui->input2_0x5->setVisible(1);
                    ui->input2_0x5->setText(nome);
                }
            break;
           case 6:
                if(nome=="desativar")
                {
                    ui->input2_0x6->setChecked(0);
                    ui->input2_0x6->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x6->checkState();
                }
                else
                {
                    ui->input2_0x6->setVisible(1);
                    ui->input2_0x6->setText(nome);
                }
            break;
           case 7:
                if(nome=="desativar")
                {
                    ui->input2_0x7->setChecked(0);
                    ui->input2_0x7->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x7->checkState();
                }
                else
                {
                    ui->input2_0x7->setVisible(1);
                    ui->input2_0x7->setText(nome);
                }
            break;
           case 8:
                if(nome=="desativar")
                {
                    ui->input2_0x8->setChecked(0);
                    ui->input2_0x8->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x8->checkState();
                }
                else
                {
                    ui->input2_0x8->setVisible(1);
                    ui->input2_0x8->setText(nome);
                }
            break;
           case 9:
                if(nome=="desativar")
                {
                    ui->input2_0x9->setChecked(0);
                    ui->input2_0x9->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input2_0x9->checkState();
                }
                else
                {
                    ui->input2_0x9->setVisible(1);
                    ui->input2_0x9->setText(nome);
                }
            break;
            }
        break;
        case 3:
            switch (indice)
            {
           case 0:
                if(nome=="desativar")
                {
                    ui->input3_0x0->setChecked(0);
                    ui->input3_0x0->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x0->checkState();
                }
                else
                {
                    ui->input3_0x0->setVisible(1);
                    ui->input3_0x0->setText(nome);
                }
            break;
           case 1:
                if(nome=="desativar")
                {
                    ui->input3_0x1->setChecked(0);
                    ui->input3_0x1->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x1->checkState();
                }
                else
                {
                    ui->input3_0x1->setVisible(1);
                    ui->input3_0x1->setText(nome);
                }
            break;
           case 2:
                if(nome=="desativar")
                {
                    ui->input3_0x2->setChecked(0);
                    ui->input3_0x2->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x2->checkState();
                }
                else
                {
                    ui->input3_0x2->setVisible(1);
                    ui->input3_0x2->setText(nome);
                }
            break;
           case 3:
                if(nome=="desativar")
                {
                    ui->input3_0x3->setChecked(0);
                    ui->input3_0x3->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x3->checkState();
                }
                else
                {
                    ui->input3_0x3->setVisible(1);
                    ui->input3_0x3->setText(nome);
                }
            break;
           case 4:
                if(nome=="desativar")
                {
                    ui->input3_0x4->setChecked(0);
                    ui->input3_0x4->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x4->checkState();
                }
                else
                {
                    ui->input3_0x4->setVisible(1);
                    ui->input3_0x4->setText(nome);
                }
            break;
           case 5:
                if(nome=="desativar")
                {
                    ui->input3_0x5->setChecked(0);
                    ui->input3_0x5->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x5->checkState();
                }
                else
                {
                    ui->input3_0x5->setVisible(1);
                    ui->input3_0x5->setText(nome);
                }
            break;
           case 6:
                if(nome=="desativar")
                {
                    ui->input3_0x6->setChecked(0);
                    ui->input3_0x6->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x6->checkState();
                }
                else
                {
                    ui->input3_0x6->setVisible(1);
                    ui->input3_0x6->setText(nome);
                }
            break;
           case 7:
                if(nome=="desativar")
                {
                    ui->input3_0x7->setChecked(0);
                    ui->input3_0x7->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x7->checkState();
                }
                else
                {
                    ui->input3_0x7->setVisible(1);
                    ui->input3_0x7->setText(nome);
                }
            break;
           case 8:
                if(nome=="desativar")
                {
                    ui->input3_0x8->setChecked(0);
                    ui->input3_0x8->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x8->checkState();
                }
                else
                {
                    ui->input3_0x8->setVisible(1);
                    ui->input3_0x8->setText(nome);
                }
            break;
           case 9:
                if(nome=="desativar")
                {
                    ui->input3_0x9->setChecked(0);
                    ui->input3_0x9->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input3_0x9->checkState();
                }
                else
                {
                    ui->input3_0x9->setVisible(1);
                    ui->input3_0x9->setText(nome);
                }
            break;
            }
        break;
        case 4:
            switch (indice)
            {
           case 0:
                if(nome=="desativar")
                {
                    ui->input4_0x0->setChecked(0);
                    ui->input4_0x0->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x0->checkState();
                }
                else
                {
                    ui->input4_0x0->setVisible(1);
                    ui->input4_0x0->setText(nome);
                }
            break;
           case 1:
                if(nome=="desativar")
                {
                    ui->input4_0x1->setChecked(0);
                    ui->input4_0x1->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x1->checkState();
                }
                else
                {
                    ui->input4_0x1->setVisible(1);
                    ui->input4_0x1->setText(nome);
                }
            break;
           case 2:
                if(nome=="desativar")
                {
                    ui->input4_0x2->setChecked(0);
                    ui->input4_0x2->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x2->checkState();
                }
                else
                {
                    ui->input4_0x2->setVisible(1);
                    ui->input4_0x2->setText(nome);
                }
            break;
           case 3:
                if(nome=="desativar")
                {
                    ui->input4_0x3->setChecked(0);
                    ui->input4_0x3->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x3->checkState();
                }
                else
                {
                    ui->input4_0x3->setVisible(1);
                    ui->input4_0x3->setText(nome);
                }
            break;
           case 4:
                if(nome=="desativar")
                {
                    ui->input4_0x4->setChecked(0);
                    ui->input4_0x4->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x4->checkState();
                }
                else
                {
                    ui->input4_0x4->setVisible(1);
                    ui->input4_0x4->setText(nome);
                }
            break;
           case 5:
                if(nome=="desativar")
                {
                    ui->input4_0x5->setChecked(0);
                    ui->input4_0x5->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x5->checkState();
                }
                else
                {
                    ui->input4_0x5->setVisible(1);
                    ui->input4_0x5->setText(nome);
                }
            break;
           case 6:
                if(nome=="desativar")
                {
                    ui->input4_0x6->setChecked(0);
                    ui->input4_0x6->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x6->checkState();
                }
                else
                {
                    ui->input4_0x6->setVisible(1);
                    ui->input4_0x6->setText(nome);
                }
            break;
           case 7:
                if(nome=="desativar")
                {
                    ui->input4_0x7->setChecked(0);
                    ui->input4_0x7->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x7->checkState();
                }
                else
                {
                    ui->input4_0x7->setVisible(1);
                    ui->input4_0x7->setText(nome);
                }
            break;
           case 8:
                if(nome=="desativar")
                {
                    ui->input4_0x8->setChecked(0);
                    ui->input4_0x8->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x8->checkState();
                }
                else
                {
                    ui->input4_0x8->setVisible(1);
                    ui->input4_0x8->setText(nome);
                }
            break;
           case 9:
                if(nome=="desativar")
                {
                    ui->input4_0x9->setChecked(0);
                    ui->input4_0x9->setVisible(0);
                }
                    else if (nome=="ckbox")
                {
                       return ui->input4_0x9->checkState();
                }
                else
                {
                    ui->input4_0x9->setVisible(1);
                    ui->input4_0x9->setText(nome);
                }
            break;

    }
        break;
        case 5:
            switch (indice)
                {
               case 0:
                    if(nome=="desativar")
                    {
                        ui->input5_0x0->setChecked(0);
                        ui->input5_0x0->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x0->checkState();
                    }
                    else
                    {
                        ui->input5_0x0->setVisible(1);
                        ui->input5_0x0->setText(nome);
                    }
                break;
               case 1:
                    if(nome=="desativar")
                    {
                        ui->input5_0x1->setChecked(0);
                        ui->input5_0x1->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x1->checkState();
                    }
                    else
                    {
                        ui->input5_0x1->setVisible(1);
                        ui->input5_0x1->setText(nome);
                    }
                break;
               case 2:
                    if(nome=="desativar")
                    {
                        ui->input5_0x2->setChecked(0);
                        ui->input5_0x2->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x2->checkState();
                    }
                    else
                    {
                        ui->input5_0x2->setVisible(1);
                        ui->input5_0x2->setText(nome);
                    }
                break;
               case 3:
                    if(nome=="desativar")
                    {
                        ui->input5_0x3->setChecked(0);
                        ui->input5_0x3->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x3->checkState();
                    }
                    else
                    {
                        ui->input5_0x3->setVisible(1);
                        ui->input5_0x3->setText(nome);
                    }
                break;
               case 4:
                    if(nome=="desativar")
                    {
                        ui->input5_0x4->setChecked(0);
                        ui->input5_0x4->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x4->checkState();
                    }
                    else
                    {
                        ui->input5_0x4->setVisible(1);
                        ui->input5_0x4->setText(nome);
                    }
                break;
               case 5:
                    if(nome=="desativar")
                    {
                        ui->input5_0x5->setChecked(0);
                        ui->input5_0x5->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x5->checkState();
                    }
                    else
                    {
                        ui->input5_0x5->setVisible(1);
                        ui->input5_0x5->setText(nome);
                    }
                break;
               case 6:
                    if(nome=="desativar")
                    {
                        ui->input5_0x6->setChecked(0);
                        ui->input5_0x6->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x6->checkState();
                    }
                    else
                    {
                        ui->input5_0x6->setVisible(1);
                        ui->input5_0x6->setText(nome);
                    }
                break;
               case 7:
                    if(nome=="desativar")
                    {
                        ui->input5_0x7->setChecked(0);
                        ui->input5_0x7->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x7->checkState();
                    }
                    else
                    {
                        ui->input5_0x7->setVisible(1);
                        ui->input5_0x7->setText(nome);
                    }
                break;
               case 8:
                    if(nome=="desativar")
                    {
                        ui->input5_0x8->setChecked(0);
                        ui->input5_0x8->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x8->checkState();
                    }
                    else
                    {
                        ui->input5_0x8->setVisible(1);
                        ui->input5_0x8->setText(nome);
                    }
                break;
               case 9:
                    if(nome=="desativar")
                    {
                        ui->input5_0x9->setChecked(0);
                        ui->input5_0x9->setVisible(0);
                    }
                        else if (nome=="ckbox")
                    {
                           return ui->input5_0x9->checkState();
                    }
                    else
                    {
                        ui->input5_0x9->setVisible(1);
                        ui->input5_0x9->setText(nome);
                    }
                break;
    }
        break;


    }
                return 0;

}


//-----------------------------------------------------ALTERA COMANDO QUANDO A STREAM É SELECIONADA-------------------------------------------
void MainWindow::on_input1_0x0_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x1_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x2_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x3_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x4_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x5_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x6_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x7_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x8_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input1_0x9_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x0_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x1_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x2_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x3_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x4_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x5_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x6_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x7_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x8_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input2_0x9_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x0_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x1_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x2_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x3_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x4_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x5_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x6_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x7_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x8_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input3_0x9_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x0_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x1_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x2_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x3_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x4_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x5_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x6_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x7_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x8_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input4_0x9_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x0_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x1_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x2_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x3_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x4_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x5_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x6_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x7_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x8_clicked()
{
alterar_comando(2);
}
void MainWindow::on_input5_0x9_clicked()
{
alterar_comando(2);
}
//-------------------------------ALTERAR COMANDO QUANDO PROGRAMAS SÃO LINCADOS COM ENTRADA-----------------------------

void MainWindow::on_prog1_entra1_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog1_entra2_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog1_entra3_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog1_entra4_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog2_entra1_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog2_entra2_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog2_entra3_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog2_entra4_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog3_entra1_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog3_entra2_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog3_entra3_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog3_entra4_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog4_entra1_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog4_entra2_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog4_entra3_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog4_entra4_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog5_entra1_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog5_entra2_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog5_entra3_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog5_entra4_clicked()
{
    alterar_comando(2);
}

void MainWindow::on_prog1_entra5_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog2_entra5_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog3_entra5_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog4_entra5_clicked()
{
    alterar_comando(2);
}
void MainWindow::on_prog5_entra5_clicked()
{
    alterar_comando(2);
}
//---------------------------------------------CONTROLA BOTAO DE MULTIPLOS PROGRAMAS-----------------------
void MainWindow::on_multiprogramas_clicked()
{
    alterar_comando(4);
    if(!ui->multiprogramas->isChecked())
    {
        on_des_prog2_clicked();
        ui->des_prog1->setChecked(1);
        ui->des_prog2->setChecked(1);
        ui->des_prog2->setDisabled(1);
        ui->prog2_entra1->setDisabled(1);
        ui->prog2_entra2->setDisabled(1);
        ui->prog2_entra3->setDisabled(1);
        ui->prog2_entra4->setDisabled(1);
        ui->prog2_entra5->setDisabled(1);
        on_des_prog2_clicked();

    }
}
//----------------------------------------------DESABILITA PROGRAMAS---------------------------
void MainWindow::on_des_prog5_clicked()
{
    alterar_comando(2);
    alterar_comando(4);
    multi_ativo();
}
void MainWindow::on_des_prog4_clicked()
{
    ui->des_prog5->setChecked(1);
    ui->des_prog5->setDisabled(1);
    ui->prog5_entra1->setDisabled(1);
    ui->prog5_entra2->setDisabled(1);
    ui->prog5_entra3->setDisabled(1);
    ui->prog5_entra4->setDisabled(1);
    ui->prog5_entra5->setDisabled(1);
    alterar_comando(2);
    alterar_comando(4);
    multi_ativo();
}
void MainWindow::on_des_prog3_clicked()
{
    on_des_prog4_clicked();
    ui->des_prog4->setChecked(1);
    ui->des_prog4->setDisabled(1);
    ui->prog4_entra1->setDisabled(1);
    ui->prog4_entra2->setDisabled(1);
    ui->prog4_entra3->setDisabled(1);
    ui->prog4_entra4->setDisabled(1);
    ui->prog4_entra5->setDisabled(1);
    multi_ativo();
}


void MainWindow::on_des_prog2_clicked()
{
    on_des_prog3_clicked();
    ui->des_prog3->setChecked(1);
    ui->des_prog3->setDisabled(1);
    ui->prog3_entra1->setDisabled(1);
    ui->prog3_entra2->setDisabled(1);
    ui->prog3_entra3->setDisabled(1);
    ui->prog3_entra4->setDisabled(1);
    ui->prog3_entra5->setDisabled(1);
    multi_ativo();
}

