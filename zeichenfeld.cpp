#include <QtGui>
#include <QMessageBox>
#include <QKeyEvent>
#include <QFont>
#include <QLabel>
#include "zeichenfeld.h"


QPainter painter;

zeichenFeld::zeichenFeld(QWidget *parent) : QWidget(parent)
{
    setPalette(QPalette(QColor(250, 250, 200)));
    setAutoFillBackground(true);
    setMouseTracking(false);

    timer=new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    label=new QLabel(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(update()));

        lastX=100;
        lastY=-100;
        lastA=300;
        lastB=0;
        lastC=450;
        lastD=-70;
        lastE=200;
        lastF=-200;
        increment=0;
        score=0;

        //Punktestand implementieren
        label->setNum(score);
        label->setGeometry(50,30,50,30);
        label->setFont(QFont("Times", 18, QFont::Bold));

}

zeichenFeld::~zeichenFeld()
{
}

void zeichenFeld::paintEvent(QPaintEvent *event)
{
    painter.begin(this);
    painter.setBrush(QBrush(Qt::blue));
    painter.drawRect(x, y, 70, 30); // Spielfigur erstellen
    painter.setBrush(QBrush(Qt::blue));
    painter.drawEllipse(450,10,10,10); // Lebensanzeige
    painter.drawEllipse(465,10,10,10); // "
    painter.drawEllipse(480,10,10,10); // "
    painter.end();

    //hier werden die "Gegner" implementiert

    int x,y,a,b,c,d,e,f;

        painter.begin(this);
        x=lastX-25;
        y=lastY-25;
        a=lastA-25;
        b=lastB-25;
        c=lastC-25;
        d=lastD-25;
        e=lastE-25;
        f=lastF-25;


        painter.setBrush(QBrush(Qt::red));
        painter.drawEllipse(x,y,40,40);
        if (increment)
            if(lastY<550) lastY++;
            else {
                score++;                    //Der Punktestand wird erhöht, sobald das Objekt das Spielfeld unten verlässt
                label->setNum(score);
                lastY=0;                    //Das Objekt fällt anschließend erneut von oben herunter
            }

        painter.setBrush(QBrush(Qt::green));
        painter.drawRect(a,b,20,10);
        if(increment)
            if(lastB<550) lastB++;
            else {
                score++;
                label->setNum(score);
                lastB=0;
            }
        painter.setBrush(QBrush(Qt::yellow));
        painter.drawRect(c,d,30,30);
        if(increment)
            if(lastD<550) lastD++;
            else {
                score++;
                label->setNum(score);
                lastD=0;
            }
        painter.setBrush(QBrush(Qt::cyan));
        painter.drawEllipse(e,f,60,60);
        if(increment)
            if(lastF<550) lastF++;
            else {
                score++;
                label->setNum(score);
                lastF=0;
            }
        painter.end();


    }


//Spielsteuerung durch die Pfeiltasten der Tastatur
void zeichenFeld::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_Left)
    {
        if(x>=25)
          x = x - 25;
        update();
    }

    if (event->key() == Qt::Key_Right)
    {
        if(x<415)
          x = x + 25;
        update();
    }
}


//Speichern des Spielstandes (alle wichtigen Werte werden in eine Datei geschrieben)
void zeichenFeld::serialize(QFile &file)
{

    QTextStream out(&file);


    out << "p " << x << "p " << score << "p " << lastY << "p " << lastB << "p " << lastD << "p " << lastF;
}


//Laden eines Spielstandes (die Werte werden aus der Datei gelesen)
void zeichenFeld::deserialize(QFile &file)
{

    char c;


    QTextStream in(&file);

    while (in.status() == QTextStream::Ok)
    {
        in >> c;
        if (in.status() == QTextStream::ReadPastEnd) break;

        if (c!='p')
        {
            QMessageBox::warning(this, tr("Objektfehler"),
                                 tr("Folgender Objekttyp ist unbekannt: ") + c,QMessageBox::Ok);
            return;
        }


        in >> x >> c >> score >> c >> lastY >> c >> lastB >> c >> lastD >> c >> lastF; // Leerstellen werden vom '>>' Operator 'konmsumiert';
        // Zeilenenden nicht.

    }

    update();
}
