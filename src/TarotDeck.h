#ifndef TAROTDECK_H
#define TAROTDECK_H

#include <QStringList>
#include <ScalingLabel.h>

class TarotDeck : public QLabel
{
    public:
        TarotDeck(QWidget *parent = nullptr);
        ScalingLabel* drawCard(ScalingLabel *card_deck, QSize max_size);
        
    private:
        QStringList cardsRemaining(QStringList cards_list, QStringList cards_used);
        QStringList cards_list;
        QStringList cards_used;
};
#endif