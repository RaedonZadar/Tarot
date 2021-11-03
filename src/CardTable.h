#ifndef CARDTABLE_H
#define CARDTABLE_H

#include <QFrame>
#include <QString>
#include <QLayout>
#include <TarotDeck.h>

class CardTable : public QFrame
{
    public:
        CardTable(QFrame *parent = nullptr);

    public slots:
        void applyConfig(QString config);

    private:
        TarotDeck *deck = new TarotDeck;
        QBoxLayout *layout;
        void threeCardSpread();
        void fiveCardCross();
        void sevenCardCrescent();
        void celticCross();
        void resetTable(QLayout *layout);
};
#endif