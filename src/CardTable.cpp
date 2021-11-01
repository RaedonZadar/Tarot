#include <QHBoxLayout>
#include <CardTable.h>
#include <Card.h>

CardTable::CardTable(QFrame *parent)
{
    setObjectName("CardTable");
    setStyleSheet("QFrame#CardTable {border-image: url('://background/table.png')}");
}

void CardTable::ThreeCardSpread()
{
    setContentsMargins(50, 30, 50, 30);
    QHBoxLayout *layout = new QHBoxLayout;
    setLayout(layout);
    Card *cards[3] = {new Card, new Card, new Card};
    for(int i = 0; i < 3; ++i)
    {
        layout->addWidget(cards[i]);
    }
}

void CardTable::applyConfig(QString config)
{
    QString configs[4] = {QString("3 Card Spread"), QString("5 Card Cross"),
                          QString("7 Card Crescent"), QString("Celtic Cross")};
    int idx = configs->indexOf(config);
    switch (idx)
    {
    case 0:
        ThreeCardSpread();
        break;
    
    default:
        break;
    }
}