#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


    int num_programas();

    void on_des_prog4_clicked();

    QString multi_map_choice(QString map,int choice, int in);

    QString multi_conexao(int prog);

    QString multi_ret_entrada(int in);

    QString map_multi_prog(int cont);


    int num_entrada();

    void multi_ativo();

    int streams(QString nome, int entrada, int indice);

    void on_codec_video_stateChanged();




    void alterar_comando(int);

    void on_entrada_1_clicked();

    void on_saida_1_clicked();

    void on_excluir_entrada_1_clicked();

    void on_Rodar_clicked();

    void on_entrada_2_clicked();

    void on_entrada_3_clicked();

    void on_entrada_4_clicked();
    void on_entrada_5_clicked();
    void on_excluir_entrada_2_clicked();

    void on_excluir_entrada_3_clicked();

    void on_excluir_entrada_4_clicked();
    void on_excluir_entrada_5_clicked();
    void on_tex_saida_1_textChanged();

    void on_nome_saida_textChanged();

    void verificar_entrada(QString text);

    void on_input1_0x0_clicked();
    void on_input1_0x1_clicked();
    void on_input1_0x2_clicked();
    void on_input1_0x3_clicked();
    void on_input1_0x4_clicked();
    void on_input1_0x5_clicked();
    void on_input1_0x6_clicked();
    void on_input1_0x7_clicked();
    void on_input1_0x8_clicked();
    void on_input1_0x9_clicked();
    void on_input2_0x0_clicked();
    void on_input2_0x1_clicked();
    void on_input2_0x2_clicked();
    void on_input2_0x3_clicked();
    void on_input2_0x4_clicked();
    void on_input2_0x5_clicked();
    void on_input2_0x6_clicked();
    void on_input2_0x7_clicked();
    void on_input2_0x8_clicked();
    void on_input2_0x9_clicked();
    void on_input3_0x0_clicked();
    void on_input3_0x1_clicked();
    void on_input3_0x2_clicked();
    void on_input3_0x3_clicked();
    void on_input3_0x4_clicked();
    void on_input3_0x5_clicked();
    void on_input3_0x6_clicked();
    void on_input3_0x7_clicked();
    void on_input3_0x8_clicked();
    void on_input3_0x9_clicked();
    void on_input4_0x0_clicked();
    void on_input4_0x1_clicked();
    void on_input4_0x2_clicked();
    void on_input4_0x3_clicked();
    void on_input4_0x4_clicked();
    void on_input4_0x5_clicked();
    void on_input4_0x6_clicked();
    void on_input4_0x7_clicked();
    void on_input4_0x8_clicked();
    void on_input4_0x9_clicked();
    void on_input5_0x0_clicked();
    void on_input5_0x1_clicked();
    void on_input5_0x2_clicked();
    void on_input5_0x3_clicked();
    void on_input5_0x4_clicked();
    void on_input5_0x5_clicked();
    void on_input5_0x6_clicked();
    void on_input5_0x7_clicked();
    void on_input5_0x8_clicked();
    void on_input5_0x9_clicked();

    void on_tex_entrada_1_editingFinished();
    void on_tex_entrada_2_editingFinished();
    void on_tex_entrada_3_editingFinished();
    void on_tex_entrada_4_editingFinished();
    void on_tex_entrada_5_editingFinished();

    void on_codec_audio_stateChanged();

    void on_tempo_editingFinished();

    QString verif_esp(QString comando);

//    void on_tex_transport_stream_id_textChanged();

    void on_tex_guard_interval_textChanged();

    void on_tex_area_code_textChanged();

    void on_tex_transmission_mode_textChanged();

    void on_tex_physical_channel_textChanged();

    void on_tex_virtual_channel_textChanged();

    void on_tex_original_network_id_textChanged();

    void on_tex_muxrate_textChanged();

    void on_prog1_entra1_clicked();
    void on_prog1_entra2_clicked();
    void on_prog1_entra3_clicked();
    void on_prog1_entra4_clicked();
    void on_prog2_entra1_clicked();
    void on_prog2_entra2_clicked();
    void on_prog2_entra3_clicked();
    void on_prog2_entra4_clicked();
    void on_prog3_entra1_clicked();
    void on_prog3_entra2_clicked();
    void on_prog3_entra3_clicked();
    void on_prog3_entra4_clicked();
    void on_prog4_entra1_clicked();
    void on_prog4_entra2_clicked();
    void on_prog4_entra3_clicked();
    void on_prog4_entra4_clicked();
    void on_prog5_entra1_clicked();
    void on_prog5_entra2_clicked();
    void on_prog5_entra3_clicked();
    void on_prog5_entra4_clicked();
    void on_prog5_entra5_clicked();
    void on_prog1_entra5_clicked();
    void on_prog2_entra5_clicked();
    void on_prog3_entra5_clicked();
    void on_prog4_entra5_clicked();

    void on_multiprogramas_clicked();

    void on_des_prog3_clicked();

    void on_des_prog2_clicked();

    void desab_entrada_2();

    void desab_entrada_3();

    void desab_entrada_4();

    void desab_entrada_5();

    void on_saida_sobrescrever_clicked();

    void on_des_prog5_clicked();

    void on_h_area_code_clicked();

    void on_h_guard_interval_clicked();

    void on_h_transmission_mode_clicked();

    void on_h_physical_channel_clicked();

    void on_h_virtual_chanel_clicked();

    void on_h_original_network_ID_clicked();

    void on_help_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
