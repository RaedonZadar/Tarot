#include <QDir>
#include <random>
#include <TarotDeck.h>

TarotDeck::TarotDeck(QWidget *parent)
{
    cards_list = QDir("://art/cards/").entryList();
}

void TarotDeck::createCard(ScalingLabel *card)
{   
    QStringList cards_remaining = cardsRemaining(cards_list, cards_used);

    if (cards_remaining.size() > 0)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, cards_remaining.count() - 1);

        QString selected_card = cards_remaining[distrib(gen)];
        cards_used.append(selected_card);

        QPixmap pixmap;
        if (pixmap.load("://art/cards/" + selected_card))
        {
            card->setPixmap(pixmap);
        }
        card->setAlignment(Qt::AlignCenter);
    }
}

QStringList TarotDeck::cardsRemaining(QStringList cards_list, QStringList cards_used)
{
    QStringListIterator iter(cards_used);
    while (iter.hasNext())
    {
        cards_list.removeAll(iter.next());
    }
    return cards_list;
}