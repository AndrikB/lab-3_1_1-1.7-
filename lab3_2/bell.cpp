#include "bell.h"
#include "ui_bell.h"

bell::bell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bell)
{
    ui->setupUi(this);
    player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators("C:/Users/blagi/source/repos/2 course/lab3_2/sound/pf.mp3")));
    player->setVolume(100);
    player->play();
}

bell::~bell()
{
    player->stop();
    delete ui;
    delete player;

}

void bell::closeEvent(QCloseEvent *event)
{
    this->player->stop();

}
