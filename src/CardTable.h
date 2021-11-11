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
        void applyConfig(QString config); // used to setup a specific configuration of cards
        void resizeEvent(QResizeEvent *);

    private:
        TarotDeck *deck = new TarotDeck;
        QBoxLayout *layout;
        void threeCardSpread();
        void fiveCardCross();
        void sevenCardCrescent();
        void celticCross();
        void resetTable(QLayout *layout); // clears all items, sublayouts and widgets in the table layout
        QSize getMaxCardSize();
        ScalingLabel *three_cards[3] = {}; // initialise cards as null pointers
        ScalingLabel *five_cards[5] = {}; // initialise cards as null pointers
        ScalingLabel *seven_cards[7] = {}; // initialise cards as null pointers
        ScalingLabel *ten_cards[10] = {}; // initialise cards as null pointers
};
#endif