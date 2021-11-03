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
        void applyConfig(QString config, ScalingLabel *card_deck);

    private:
        TarotDeck *deck = new TarotDeck;
        QBoxLayout *layout;
        void threeCardSpread(ScalingLabel *card_deck);
        void fiveCardCross(ScalingLabel *card_deck);
        void sevenCardCrescent(ScalingLabel *card_deck);
        void celticCross(ScalingLabel *card_deck);
        void resetTable(QLayout *layout);
};
#endif