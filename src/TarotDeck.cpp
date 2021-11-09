#include <QDir>
#include <random>
#include <TarotDeck.h>

TarotDeck::TarotDeck(QWidget *parent)
{
    cards_list = QDir("://art/cards/").entryList();
}

ScalingLabel* TarotDeck::drawCard(QSize max_size)
{   
    ScalingLabel *card = new ScalingLabel;
    card->max_size = max_size;
    QStringList cards_remaining = cardsRemaining(cards_list, cards_used);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, cards_remaining.count() - 1);

    QString selected_card = cards_remaining[distrib(gen)];
    cards_used.append(selected_card);

    QPixmap pixmap;
    if (pixmap.load("://art/cards/" + selected_card))
    {
        card->setPixmap(pixmap);
        QObject::connect(card, &ScalingLabel::released, card, &ScalingLabel::onRelease);
    }
    card->setAlignment(Qt::AlignCenter);

    return card;
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

void TarotDeck::reshuffle()
{
    cards_used.clear();
}