#include <QHBoxLayout>
#include <CardTable.h>

CardTable::CardTable(QFrame *parent)
{
    layout = new QHBoxLayout;
    setLayout(layout);
    setObjectName("CardTable");
    setStyleSheet("QFrame#CardTable {border-image: url('://background/table.png')}");
}

void CardTable::applyConfig(QString config)
{
    /* Public slot used to apply tarot configurations to the CardTable based on   //
    // which configuration button was pressed. The configurations themselves are  //
    // defined within their own method functions                                  */
    QStringList configs = {"3 Card Spread", "5 Card Cross", 
                           "7 Card Crescent", "Celtic Cross"};
    int idx = configs.indexOf(config);
    switch (idx)
    {
        case 0:
            threeCardSpread();
            break;
        case 1:
            fiveCardCross();
            break;
        case 2:
            sevenCardCrescent();
            break;
        case 3:
            celticCross();
            break;
        case 4:
            resetTable(layout);
            break;

        default:
            break;
    }
}

void CardTable::threeCardSpread()
{
    resetTable(layout);

    for (int i = 0; i < 3; ++i)
    {
        QLabel *card = new QLabel;
        deck->createCard(card);
        layout->addWidget(card);
    }
}

void CardTable::fiveCardCross()
{
    resetTable(layout);
}

void CardTable::sevenCardCrescent()
{
    resetTable(layout);
}

void CardTable::celticCross()
{
    resetTable(layout);
}

void CardTable::resetTable(QLayout *layout)
{
    if (layout->count() > 0)
    {
        QLayoutItem *item;
        QLayout *sublayout;
        QWidget *widget;
        while (item = layout->takeAt(0))
        {
            if ((sublayout = item->layout()) != 0) {resetTable(sublayout); delete sublayout;}
            else if ((widget = item->widget()) != 0) {delete widget;}
            else {delete item;}
        }
    }
}