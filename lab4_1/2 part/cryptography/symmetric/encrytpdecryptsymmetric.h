#ifndef ENCRYTPDECRYPTSYMMETRIC_H
#define ENCRYTPDECRYPTSYMMETRIC_H

#include <QDialog>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QInputDialog>
#include <openssl/blowfish.h>
#include <QLabel>
#include <QTime>
#include <QClipboard>

#include <gtest/gtest.h>

namespace Ui {
class EncrytpDecryptSymmetric;
}

class EncrytpDecryptSymmetric : public QDialog
{
    Q_OBJECT

public:
    explicit EncrytpDecryptSymmetric(int enc, QWidget *parent = nullptr);
    ~EncrytpDecryptSymmetric();

    void set_key(QString key, int size);
private slots:
    void on_old_file_clicked();
    void on_convert_clicked();
    void on_new_file_clicked();
    void on_set_key_clicked();
    void on_WriteKey_clicked();
    void on_exit_clicked();

    void on_text_radiobtn_clicked();

    void on_file_radiobtn_clicked();

signals:
    void close_wndw();
private:
    Ui::EncrytpDecryptSymmetric *ui;
    int enc;
    QString new_filename;
    QString old_filename;

    BF_KEY *key= new BF_KEY;
    bool key_selected=false;//todo rename

    void set_all_disable();
    void check_can_convert();
    void set_filename_to_fileLBL(QString filename, QLabel *fileLBL);

    void set_old_and_new_filename(QString s);
    void encrypt_decrypt_file();
    void collapse_all();

    FRIEND_TEST(cryptogragry, encrypt_decrypt);
};

#endif // ENCRYTPDECRYPTSYMMETRIC_H
