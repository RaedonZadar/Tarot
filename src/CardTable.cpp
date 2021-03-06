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

    layout->setSpacing(20);
    layout->addStretch(3);
    for (int i = 0; i < 3; ++i)
    {
        three_cards[i] = deck->drawCard(getMaxCardSize());
        layout->addWidget(three_cards[i], 2);
    }
    layout->addStretch(3);
}

void CardTable::fiveCardCross()
{
    resetTable(layout);

    QWidget *grid_widget = new QWidget;
    QGridLayout *grid = new QGridLayout;
    layout->addStretch(3);
    layout->addWidget(grid_widget, 5);
    layout->addStretch(3);
    grid_widget->setLayout(grid);
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setSpacing(20);

    grid->setRowStretch(0, 1);
    grid->setRowStretch(1, 2);
    grid->setRowStretch(2, 2);
    grid->setRowStretch(3, 2);
    grid->setRowStretch(4, 1);

    int idx_row[5] = {2, 3, 2, 1, 2};
    int idx_col[5] = {2, 2, 1, 2, 3};
    for (int i = 0; i < 5; ++i)
    {
        five_cards[i] = deck->drawCard(getMaxCardSize());
        grid->addWidget(five_cards[i], idx_row[i], idx_col[i]);
    }
}

void CardTable::sevenCardCrescent()
{
    resetTable(layout);

    QWidget *widget[5] = {new QWidget, new QWidget, new QWidget,
                          new QWidget, new QWidget};
    QVBoxLayout *v_layout[5] = {new QVBoxLayout, new QVBoxLayout, new QVBoxLayout,
                                new QVBoxLayout, new QVBoxLayout};

    QWidget *mid_widget = new QWidget;
    QHBoxLayout *mid_layout = new QHBoxLayout;
    v_layout[2]->addWidget(mid_widget, 3);
    mid_widget->setLayout(mid_layout);
    mid_layout->setContentsMargins(0, 0, 0, 0);
    mid_layout->setSpacing(20);
    
    for (int i = 0; i < 7; ++i) {seven_cards[i] = deck->drawCard(getMaxCardSize());}

    layout->addStretch(1);
    for (int i = 0; i < 5; ++i)
    {
        layout->addWidget(widget[i], 3);
        widget[i]->setLayout(v_layout[i]);
        v_layout[i]->setContentsMargins(0, 0, 0, 0);
        v_layout[i]->setSpacing(20);
    }
    layout->addStretch(1);
    layout->setStretch(3, 7);

    v_layout[0]->addStretch(3);
    v_layout[1]->addStretch(2);
    v_layout[2]->insertStretch(0, 1);
    v_layout[3]->addStretch(2);
    v_layout[4]->addStretch(3);

    v_layout[0]->addWidget(seven_cards[0], 3);
    v_layout[1]->addWidget(seven_cards[1], 1);
    mid_layout->addWidget(seven_cards[2]);
    mid_layout->addWidget(seven_cards[3]);
    v_layout[3]->addWidget(seven_cards[4], 1);
    v_layout[4]->addWidget(seven_cards[5], 3);
    v_layout[2]->insertWidget(1, seven_cards[6], 3);

    v_layout[0]->addStretch(2);
    v_layout[1]->addStretch(1);
    v_layout[2]->addStretch(1);
    v_layout[3]->addStretch(1);
    v_layout[4]->addStretch(2);
}

void CardTable::celticCross()
{
    resetTable(layout);

    QWidget *widget[2] = {new QWidget, new QWidget};
    QGridLayout *grid = new QGridLayout;
    QVBoxLayout *v_layout = new QVBoxLayout;
    layout->addStretch(2);
    layout->addWidget(widget[0], 7);
    layout->addWidget(widget[1], 3);
    layout->addStretch(2);
    widget[0]->setLayout(grid);
    widget[1]->setLayout(v_layout);
    grid->setContentsMargins(0, 50, 0, 50);
    grid->setSpacing(20);
    v_layout->setContentsMargins(0, 50, 0, 50);
    v_layout->setSpacing(5);

    for (int i = 0; i < 10; ++i) {ten_cards[i] = deck->drawCard(getMaxCardSize());}
    
    ten_cards[1]->rotatePixmap(90);
    grid->addWidget(ten_cards[0], 1, 1);
    grid->addWidget(ten_cards[1], 1, 1, Qt::AlignBottom);

    int idx_row[4] = {2, 1, 0, 1};
    int idx_col[4] = {1, 0, 1, 2};
    for (int i = 2; i < 6; ++i) {grid->addWidget(ten_cards[i], idx_row[i-2], idx_col[i-2]);}
    for (int i = 6; i < 10; ++i) {v_layout->insertWidget(0, ten_cards[i]);}
}

void CardTable::resetTable(QLayout *layout)
{
    /* Private method function for resetting the base layout of card table. This //
    // function will delete all items, layouts and widgets in the base layout in //
    // order to reset it and will also clear all card pointers back to nullptr.  //
    // It is called at the start of each configuration function.                 */

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
    for (int i = 0; i < 3; ++i) {three_cards[i] = nullptr;}
    for (int i = 0; i < 5; ++i) {five_cards[i] = nullptr;}
    for (int i = 0; i < 7; ++i) {seven_cards[i] = nullptr;}
    for (int i = 0; i < 10; ++i) {ten_cards[i] = nullptr;}
}

void CardTable::resizeEvent(QResizeEvent *e)
{
    /* Provide each card object with their maximum allowed size each time the window is resized */

    QSize size = getMaxCardSize();
    
    for (int i = 0; i < 10; ++i)
    {
        if (i < 3 && three_cards[i] != nullptr)
        {
            if (!three_cards[i]->pixmap().isNull()) {three_cards[i]->max_size = size;}
        }
        if (i < 5 && five_cards[i] != nullptr)
        {
            if (!five_cards[i]->pixmap().isNull()) {five_cards[i]->max_size = size;}
        }
        if (i < 7 && seven_cards[i] != nullptr)
        {
            if (!seven_cards[i]->pixmap().isNull()) {seven_cards[i]->max_size = size;}
        }
        if (i < 10 && ten_cards[i] != nullptr)
        {
            if (!ten_cards[i]->pixmap().isNull()) {ten_cards[i]->max_size = size;}
        }
    }
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