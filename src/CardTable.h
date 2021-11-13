#ifndef CARDTABLE_H
#define CARDTABLE_H

#include <QGraphicsView>
#include <TarotDeck.h>

class CardTable : public QGraphicsView
{
    public:
        CardTable(QWidget *parent = nullptr);

    public slots:
        void applyConfig(QString config); // used to setup a specific configuration of cards

    private:
        TarotDeck *deck = new TarotDeck;
        QGraphicsScene *scene;
        ScalingLabel *three_cards[3] = {}; // initialise cards as null pointers
        void threeCardSpread();
        void resetTable();
        QSize getMaxCardSize();
};
#endif