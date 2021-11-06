#include <QVBoxLayout>
#include <QLabel>
#include <SidePanel.h>

SidePanel::SidePanel(QFrame *parent)
    : QFrame(parent)
{
    // Create frame for the tarot configuration buttons and tarot deck
    QVBoxLayout *panel_layout = new QVBoxLayout;
    panel_layout->setContentsMargins(20, 20, 20, 20);
    this->setLayout(panel_layout);
    this->setObjectName("panel");
    this->setStyleSheet("QFrame#panel {background-image: url('://background/panel.png');"
                                      "border: 5px solid black}");

    // Create frame for the tarot configuration buttons
    QFrame *panel_btns_frame = new QFrame;
    QVBoxLayout *panel_btns_layout = new QVBoxLayout;
    panel_btns_layout->setSpacing(10);
    panel_btns_layout->setContentsMargins(30, 30, 30, 30);
    panel_btns_frame->setLayout(panel_btns_layout);
    panel_layout->addWidget(panel_btns_frame, 2);

    // Create tarot configuration buttons
    QString *panel_btns_text[4] = {new QString("3 Card Spread"), new QString("5 Card Cross"),
                                    new QString("7 Card Crescent"), new QString("Celtic Cross")};
    for (int i = 0; i < 4; ++i)
    {
        panel_btns[i]->setText(*panel_btns_text[i]);
        panel_btns[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        panel_btns[i]->setMaximumHeight(50);
        panel_btns_layout->addWidget(panel_btns[i], Qt::AlignCenter);
    }

    // Create tarot deck
    card_deck = new ScalingLabel;
    card_deck->max_size = getMaxCardSize();
    QPixmap pixmap;
    if (pixmap.load("://cards/Card Back.png"))
    {
        card_deck->setObjectName("CardDeck");
        card_deck->setPixmap(pixmap);
    }
    card_deck->setAlignment(Qt::AlignCenter);
    panel_layout->addWidget(card_deck, 1);
}

void SidePanel::resizeEvent(QResizeEvent *e)
{
    if (!card_deck->pixmap().isNull())
    {
        QSize size = getMaxCardSize();
        card_deck->max_size = size;
    }
}

QSize SidePanel::getMaxCardSize()
{
    QSize size = this->size();
    size.rwidth() = size.width() * (4. / 7.5);
    size.rheight() = size.height() / 5;
    return size;
}