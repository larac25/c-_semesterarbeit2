#include <QWidget>
#include "zeichenfeld.h"

class meinWidget : public QWidget
{
    Q_OBJECT //wir verwenden QT Bibliothek (z.B. slots)

    private:
    zeichenFeld *meinZeichenFeld = new zeichenFeld;

    public:
    meinWidget(QWidget *parent = 0);

    private slots:
    void loadFile();
    void saveFile();
    void startGame(void);
    void pauseGame(void);
};
