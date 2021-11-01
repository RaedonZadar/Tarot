#include <random>
#include <Card.h>

Card::Card(QLabel *parent)
{
    QStringList cards_remaining = CardsRemaining(cards_list, cards_used);
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, cards_remaining.count());

    QString selected_card = cards_remaining[distrib(gen)];
    cards_used.append(selected_card);

    QPixmap pixmap;
    if(pixmap.load("://art/cards/" + selected_card))
    {
        pixmap = pixmap.scaled(240, 320);
        setPixmap(pixmap);
    }
    setAlignment(Qt::AlignCenter);
    setContentsMargins(20, 20, 20, 20);
}

QStringList Card::CardsRemaining(QStringList cards_list, QStringList cards_used)
{
    QStringListIterator iter(cards_used);
    while(iter.hasNext())
    {
        cards_list.removeAll(iter.next());
    }
    return cards_list;
}