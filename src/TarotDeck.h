#ifndef TAROTDECK_H
#define TAROTDECK_H

#include <QStringList>
#include <ScalingLabel.h>

class TarotDeck : public QLabel
{
    public:
        TarotDeck(QWidget *parent = nullptr);
        ScalingLabel* drawCard(QSize max_size); // create new non-duplicate card
        void reshuffle(); // shuffle used cards back into the tarot deck

    private:
        QStringList cardsRemaining(QStringList cards_list, QStringList cards_used);
        QStringList cards_list; // store total list of card images
        QStringList cards_used; // store list of card images already in use
};
#endif