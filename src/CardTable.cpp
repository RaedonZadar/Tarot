#include <QGraphicsPixmapItem>
#include <CardTable.h>

CardTable::CardTable(QWidget *parent)
{
    scene = new QGraphicsScene;
    this->setScene(scene);
    this->setObjectName("CardTable");
    this->setStyleSheet("#CardTable {border-image: url('://background/table.png')}");
}

void CardTable::applyConfig(QString config)
{
    /* Public slot used to apply tarot configurations to the CardTable based on  //
    // which configuration button was pressed. The configurations themselves are //
    // defined within their own method functions.                                */

    deck->reshuffle();
    QStringList configs = {"3 Card Spread", "5 Card Cross", 
                           "7 Card Crescent", "Celtic Cross"};
    int idx = configs.indexOf(config);
    switch (idx)
    {
        case 0:
            threeCardSpread();
            break;
    }
}

void CardTable::threeCardSpread()
{
    resetTable();
    
    for (int i = 0; i < 3; ++i)
    {
        three_cards[i] = deck->drawCard(getMaxCardSize());
        QGraphicsPixmapItem *pix = scene->addPixmap(three_cards[i]->pixmap());
        pix->setPos((pix->pixmap().width() + 20) * i, 0);
    }
}

void CardTable::resetTable()
{
    /* Private method function for resetting the base layout of card table. This //
    // function will delete all items, layouts and widgets in the base layout in //
    // order to reset it and will also clear all card pointers back to nullptr.  //
    // It is called at the start of each configuration function.                 */

    scene->clear();
}

QSize CardTable::getMaxCardSize()
{
    /* Calculates the maximum allowed size of drawn cards to maintain constant //
    // card sizes across all configurations and prevent scaling issues         */

    QSize size = this->size();
    size.rwidth() = size.width() / 7.5;
    size.rheight() = size.height() / 5;
    return size;
}