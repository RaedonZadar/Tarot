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
        void resizeEvent(QResizeEvent *);

    private:
        TarotDeck *deck = new TarotDeck;
        QBoxLayout *layout;
        void threeCardSpread();
        void fiveCardCross();
        void sevenCardCrescent();
        void celticCross();
        void resetTable(QLayout *layout);
        QSize getMaxCardSize();
        ScalingLabel *three_cards[3] = {};
        ScalingLabel *five_cards[5] = {};
        ScalingLabel *seven_cards[7] = {};
        ScalingLabel *ten_cards[10] = {};
};
#endif