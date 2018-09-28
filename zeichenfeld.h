#include <QWidget>
#include <QFile>
#include <vector>
#include <QTimer>
#include <QLabel>

class zeichenFeld : public QWidget
{
    Q_OBJECT

    public:
    zeichenFeld(QWidget *parent = 0);
    void serialize(QFile &file);
    void deserialize(QFile &file);
    ~zeichenFeld();


    void startGame(void) { timer->start(10); increment=1; label->setNum(score); }
    void pauseGame(void) { timer->stop(); increment=0; label->setNum(score); }


    private:
    int x=225, y=450;
    QTimer *timer;
    int lastX;
    int lastY;
    int lastA;
    int lastB;
    int lastC;
    int lastD;
    int lastE;
    int lastF;
    int increment;
    QLabel *label;
    int score;


    protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent* event);

};
