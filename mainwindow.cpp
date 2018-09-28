#include <QtGui>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QMessageBox>
#include "mainwindow.h"

meinWidget::meinWidget(QWidget *parent) : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Ende")); //Button Spiel beenden
    quit->setFont(QFont("Times", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *saver = new QPushButton(tr("Sichern"));  //Button Speichern
    saver->setFont(QFont("Times", 18, QFont::Bold));
    connect(saver, SIGNAL(clicked()), this, SLOT(saveFile()));

    QPushButton *loader = new QPushButton(tr("Laden"));  //Button Laden
    loader->setFont(QFont("Times", 18, QFont::Bold));
    connect(loader, SIGNAL(clicked()), this, SLOT(loadFile()));

    QPushButton *starter = new QPushButton(tr("Start")); //Button Spiel starten
    starter->setFont(QFont("Times",18, QFont::Bold));
    connect(starter, SIGNAL(clicked()), this, SLOT(startGame()));

    QPushButton *pause = new QPushButton(tr("Pause")); //Button Spiel pausieren
    pause->setFont(QFont("Times",18, QFont::Bold));
    connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));

    meinZeichenFeld->setFixedSize(500, 500);
    meinZeichenFeld->setFocusPolicy(Qt::ClickFocus); //das muss rein, damit die Tastatur berücksichtigt wird!

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(quit, 0, 0);
    gridLayout->addWidget(saver, 0, 1);
    gridLayout->addWidget(loader, 0, 2);
    gridLayout->addWidget(starter, 0, 3);
    gridLayout->addWidget(pause, 0, 4);
    gridLayout->addWidget(meinZeichenFeld,2, 2, 5, 5);
    gridLayout->setColumnStretch(1, 10);
    setLayout(gridLayout);

}


//Dialog zum Speichern des Spielstandes
void meinWidget::saveFile()
{

    QFileDialog dialog(this);
        QString fileName;
        QFile file;

        dialog.setFileMode(QFileDialog::AnyFile);
        fileName = dialog.getSaveFileName(this,
                                          tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

        if (fileName.isNull()==false)
        {
            file.setFileName(fileName);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QMessageBox::warning(this, tr("Dateifehler"),
                                     tr("Folgende Datei kann nicht verwendet werden: ") + fileName,QMessageBox::Ok);
            }

            meinZeichenFeld->serialize(file);
            file.close();
            return;
        }

}


//Laden der gespeicherten Datei
void meinWidget::loadFile(void)
{
    QFileDialog dialog(this);
    QString fileName;
    QFile file;

    dialog.setFileMode(QFileDialog::AnyFile);
    fileName = dialog.getOpenFileName(this,
                                      tr("Speichern als"), ".", tr("Zeichnungen (*.myz)"));

    if (fileName.isNull()==false)
    {
        file.setFileName(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, tr("Dateifehler"),
                                 tr("Folgende Datei kann nicht geÃ¶ffnet werden: ") + fileName,QMessageBox::Ok);
        }

        meinZeichenFeld->deserialize(file);
        file.close();
        return;
    }
}

//Starten des Spiels
void meinWidget::startGame(void){

   meinZeichenFeld->startGame();
}


//Pausieren des Spiels
void meinWidget::pauseGame(void){

    meinZeichenFeld->pauseGame();
}
