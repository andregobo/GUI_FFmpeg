#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
//#define MAX_PACKET 500
    QString input_1, map_2, codec_3, avancado_4, tempo_5, verbose_6, saida_7;



void MainWindow::alterar_comando(int pos)//Altera o comando
{
    QString comando;
    switch (pos)
    {
    case 1:
        if (ui->tex_entrada_1->text()=="")
        {
            input_1 = "";
        }
        else
        {
            input_1= " -i " + verif_esp(ui->tex_entrada_1->text());
        }
        if (ui->tex_entrada_2->text()!="")
        {
            input_1= input_1 + " -i " + verif_esp(ui->tex_entrada_2->text());
        }
        if (ui->tex_entrada_3->text()!="")
        {
            input_1= input_1 + " -i " + verif_esp(ui->tex_entrada_3->text());
        }
        if (ui->tex_entrada_4->text()!="")
        {
            input_1= input_1 + " -i " + verif_esp(ui->tex_entrada_4->text());
        }
        if (ui->tex_entrada_5->text()!="")
        {
            input_1= input_1 + " -i " + verif_esp(ui->tex_entrada_5->text());
        }
    break;

    case 2:
        multi_ativo();
        map_2="";
        int in;
        if(ui->multiprogramas->isChecked())
        {
            for(in=1;in<11;in++)
            {
                map_2=map_2+map_multi_prog(in);
            }


        }
        else
        {
            int lin;

            for(in=1;in<5;in++)
            {
                for(lin=0;lin<10;lin++)
                {
                    if(streams("ckbox",in,lin))
                    {
                        map_2= map_2 + " -map " + QString::number(in-1) + ":" + QString::number(lin);
                    }
                }
                lin=0;
            }
        }
        alterar_comando(4);
    break;

    case 3:
        codec_3="";
        if(ui->codec_video->checkState())
        {
            codec_3= " -vcodec copy";
        }
        if(ui->codec_audio->checkState())
        {
            codec_3= codec_3 + " -acodec copy";
        }

    break;

    case 4:

        avancado_4="";
//        if(ui->tex_transport_stream_id->text()!="")
//        {
//            avancado_4="  -mpegts_transport_stream_id " + ui->tex_transport_stream_id->text();
//        }

        if(ui->tex_original_network_id->text()!="")
        {
            avancado_4=avancado_4 + "  -mpegts_original_network_id " + ui->tex_original_network_id->text();
        }
        if(ui->tex_area_code->text()!="")
        {
            avancado_4=avancado_4 + "  -mpegts_area_code " + ui->tex_area_code->text();
        }

//        mpegts_guard_interval,
        if(ui->tex_guard_interval->text()!="")
        {
            avancado_4=avancado_4 + " -mpegts_guard_interval " + ui->tex_guard_interval->text();
        }

//        mpegts_transmission_mode,
        if(ui->tex_transmission_mode->text()!="")
        {
            avancado_4=avancado_4 + " -mpegts_transmission_mode " + ui->tex_transmission_mode->text();
        }

//        mpegts_physical_channel,

        if(ui->tex_physical_channel->text()!="")
        {
            avancado_4=avancado_4 + " -mpegts_physical_channel " + ui->tex_physical_channel->text();
        }

//        mpegts_virtual_channel
        if(ui->tex_virtual_channel->text()!="")
        {
            avancado_4=avancado_4 + " -mpegts_virtual_channel " + ui->tex_virtual_channel->text();
        }
//          muxrate
        if(ui->tex_muxrate->text()!="")
        {
            avancado_4=avancado_4 + " -muxrate " + ui->tex_muxrate->text();
        }
//          multiprogramas numero de programas
        if(ui->multiprogramas->isChecked())
        {
            avancado_4=avancado_4 + "  -mpegts_final_nb_services " + QString::number(num_programas());
        }
//          multiprogramas numero de programas
        if(ui->multiprogramas->isChecked())
        {
            if(ui->prog3_entra1->isChecked()||ui->prog3_entra2->isChecked()||ui->prog3_entra3->isChecked()||ui->prog3_entra4->isChecked()||ui->prog3_entra5->isChecked())
            {
                avancado_4=avancado_4 + "  -mpegts_transmission_profile 2";
            }
            else
            {
                avancado_4=avancado_4 + "  -mpegts_transmission_profile 1";
            }
        }


//        codec_3="";
//        if(ui->codec_video->checkState())
//        {
//            codec_3= "";
//        }
//        if(ui->codec_audio->checkState())
//        {
//            codec_3= " -strict -2";
//        }

    break;

    case 5:
        if(ui->tempo->text()!="")
        {
            tempo_5= " -t " + ui->tempo->text();
        }
        else
        {
            tempo_5=ui->tempo->text();
        }

    break;

    case 6:
        if(ui->tex_saida_1->text()=="")
        {
            saida_7= " " + verif_esp(ui->nome_saida->text());
        }
        else
        {
            saida_7= " " + verif_esp(ui->tex_saida_1->text()) + "/" + verif_esp(ui->nome_saida->text());
        }
    break;

    case 7:
        saida_7="";
        if(ui->saida_sobrescrever->isChecked())
        {
            saida_7=" -y";
        }
        if(ui->tex_saida_1->text()=="")
        {
            saida_7= saida_7 + " " + verif_esp(ui->nome_saida->text());
        }
        else
        {
            if(ui->nome_saida->text().indexOf(".")==-1)
            {
                saida_7= saida_7 +  " " + verif_esp(ui->tex_saida_1->text()) + "/" + verif_esp(ui->nome_saida->text())+".ts";
            }
            else
            {
                saida_7= saida_7 +  " " + verif_esp(ui->tex_saida_1->text()) + "/" + verif_esp(ui->nome_saida->text());
            }
        }
    break;


    }

    comando =  "gnome-terminal -x ffmpeg" + input_1 + map_2 + codec_3 + avancado_4 + tempo_5 + saida_7;

    ui->tex_comando->setText(comando);
}

void MainWindow::on_Rodar_clicked()
{
    QString comando;
    comando=ui->tex_comando->toPlainText();

    system(comando.toLatin1());

//    QProcess *proc = new QProcess(this);
//    proc->start("gnome-terminal -x");
//    if (!proc->waitForStarted()) {

//    }
}

void MainWindow::on_saida_1_clicked()
{
    QString filename = QFileDialog::getExistingDirectory(this,  tr("Escolha a pasta de destino da saída"));

    ui->tex_saida_1->setText(filename);

    alterar_comando(7);

}

void MainWindow::on_tex_saida_1_textChanged()
{
    alterar_comando(7);
}

void MainWindow::on_nome_saida_textChanged()
{
    alterar_comando(7);
}

// sobrescrever saida
void MainWindow::on_saida_sobrescrever_clicked()
{
    alterar_comando(7);
}

