# c-_semesterarbeit2
Semesterarbeit Teil 2, C++ Kurs bei Prof. Eide, Sommersemester 2018

Bei dieser Arbeit wurde Stufe 1 der Semesterarbeit (Teil 2) erfolgreich umgesetzt.
Das Spiel besteht aus einem Spielfeld. In diesem Spielfeld ist ein Avatar (blaues Rechteck) am unteren Rand des Feldes, der mit Hilfer der Pfeiltasten der Tastatur nach links oder nach rechts bewegt werden kann. Zudem ist oben rechts eine Lebensanzeige in Form von drei ausgefüllten Kreisen zu sehen. In der oberen linken Enke befindet sich der Punktestand. Zu Beginn des Spiels steht dieser auf 0.
Das Spiel kann mit dem "Start"-Button begonnen werden. Sobald dieser ausgelöst wurde, fallen verschiedene Objekte (Gegner) von oben herab. Sobald ein Objekt das Spielfeld am unteren Rand verlassen hat, steigt der Punktestand um 1 und das Objekt beginnt erneut von oben herunterzufallen. Die Logik des Punktezählers ist also wie folgt: Fällt ein Objekt "unversehrt" aus dem Spielfeld heraus, erhält der Spieler einen Punkt.
Über den "Pause"-Button kann das Spiel angehalten werden. Das Spiel friert ein, bis erneut der "Start"-Button gedrückt wird.
Zudem kann der aktuelle Spielstand über einen "Speichern"-Button gespeichert werden. Mit dem Button "Laden", können alte, gespeicherte Spielstände wieder hergestellt werden. Der Punktestand scheint davon zunächst nicht beeinflusst zu werden. Doch sobald "Start" gedrückt wird, springt die Punktzahl auf den Wert, der aus dem gespeicherten Spielstand hervorgeht.
Das Spiel kann über einen "Ende"-Button beendet werden.
