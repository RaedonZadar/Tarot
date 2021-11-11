#include <QDir>
#include <random>
#include <TarotDeck.h>

TarotDeck::TarotDeck(QWidget *parent)
{
    cards_list = QDir("://art/cards/").entryList();
}

ScalingLabel* TarotDeck::drawCard(QSize max_size)
{   
    // Create new card, set it's max size and randomly select an available image for it
    ScalingLabel *card = new ScalingLabel;
    card->max_size = max_size;
    QStringList cards_remaining = cardsRemaining(cards_list, cards_used);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> card_draw(0, cards_remaining.count() - 1);
    std::uniform_int_distribution<> rotation(-5, 5);

    QString selected_card = cards_remaining[card_draw(gen)];
    cards_used.append(selected_card);

    QPixmap pixmap;
    if (pixmap.load("://art/cards/" + selected_card))
    {
        card->setPixmap(pixmap);
        card->rotatePixmap(rotation(gen)); //adds minor rotation for card to appear naturally placed
        QObject::connect(card, &ScalingLabel::released, card, &ScalingLabel::onRelease);
    }
    card->setAlignment(Qt::AlignCenter);

    return card;
}

QStringList TarotDeck::cardsRemaining(QStringList cards_list, QStringList cards_used)
{
    /* Returns the remaining available cards to prevent duplicates appearing */
    
    QStringListIterator iter(cards_used);
    while (iter.hasNext())
    {
        cards_list.removeAll(iter.next());
    }
    return cards_list;
}

void TarotDeck::reshuffle()
{
    /* Clearing cards_used allows cardsRemaining to return the full deck of cards to draw from. //
    // Since cards are selected randomly, this is effectively a reshuffle.                      */
    
    cards_used.clear();
}