#include <QSpacerItem>
#include <CardTable.h>

CardTable::CardTable(QFrame *parent)
{
    layout = new QHBoxLayout;
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(20);
    this->setLayout(layout);
    this->setObjectName("CardTable");
    this->setStyleSheet("QFrame#CardTable {border-image: url('://background/table.png')}");
}

void CardTable::applyConfig(QString config, ScalingLabel *card_deck)
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
            threeCardSpread(card_deck);
            break;
        case 1:
            fiveCardCross(card_deck);
            break;
        case 2:
            sevenCardCrescent(card_deck);
            break;
        case 3:
            celticCross(card_deck);
            break;
        case 4:
            resetTable(layout);
            break;

        default:
            break;
    }
}

void CardTable::threeCardSpread(ScalingLabel *card_deck)
{
    resetTable(layout);

    layout->setSpacing(20);
    layout->addStretch(3);
    for (int i = 0; i < 3; ++i)
    {
        ScalingLabel *card = deck->drawCard(card_deck);
        layout->addWidget(card, 2);
    }
    layout->addStretch(3);
}

void CardTable::fiveCardCross(ScalingLabel *card_deck)
{
    resetTable(layout);

    QWidget *grid_widget = new QWidget;
    layout->addWidget(grid_widget);
    QGridLayout *grid = new QGridLayout;
    grid_widget->setLayout(grid);
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setSpacing(20);

    // grid->setRowStretch(0, 1);
    // grid->setRowStretch(1, 2);
    // grid->setRowStretch(2, 2);
    // grid->setRowStretch(3, 2);
    // grid->setRowStretch(4, 1);
    // grid->setColumnStretch(0, 2);
    // grid->setColumnStretch(1, 1);
    // grid->setColumnStretch(2, 1);
    // grid->setColumnStretch(3, 1);
    // grid->setColumnStretch(4, 2);

    int idx_row[5] = {2, 3, 2, 1, 2};
    int idx_col[5] = {2, 2, 1, 2, 3};
    for (int i = 0; i < 5; ++i)
    {
        ScalingLabel *card = deck->drawCard(card_deck);
        grid->addWidget(card, idx_row[i], idx_col[i]);
    }
}

void CardTable::sevenCardCrescent(ScalingLabel *card_deck)
{
    resetTable(layout);

    QWidget *widget[5] = {new QWidget, new QWidget, new QWidget,
                          new QWidget, new QWidget};
    QVBoxLayout *v_layout[5] = {new QVBoxLayout, new QVBoxLayout, new QVBoxLayout,
                                new QVBoxLayout, new QVBoxLayout};
    
    for (int i = 0; i < 5; ++i)
    {
        layout->addWidget(widget[i]);
        widget[i]->setLayout(v_layout[i]);
        v_layout[i]->setContentsMargins(0, 0, 0, 0);
        v_layout[i]->setSpacing(20);

        if (i != 2)
        {
            ScalingLabel *card = deck->drawCard(card_deck);
            v_layout[i]->addWidget(card);
        }
        else if (i == 2)
        {
            QWidget *mid_widget = new QWidget;
            QHBoxLayout *mid_layout = new QHBoxLayout;
            ScalingLabel *card[2] = {deck->drawCard(card_deck),
                                     deck->drawCard(card_deck)};
            mid_widget->setLayout(mid_layout);
            v_layout[i]->addWidget(mid_widget);
            mid_layout->setContentsMargins(0, 0, 0, 0);
            mid_layout->setSpacing(20);
            mid_layout->addWidget(card[0]);
            mid_layout->addWidget(card[1]);
        }
        if (i == 4)
        {
            ScalingLabel *card = deck->drawCard(card_deck);
            v_layout[2]->insertWidget(0, card);
        }
    }
}

void CardTable::celticCross(ScalingLabel *card_deck)
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