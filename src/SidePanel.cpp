#include <QVBoxLayout>
#include <QPushbutton>
#include <QLabel>
#include <SidePanel.h>

SidePanel::SidePanel(QFrame *parent)
    : QFrame(parent)
{
    // Create frame for the tarot configuration buttons and tarot deck
    QVBoxLayout *panel_layout = new QVBoxLayout;
    this->setLayout(panel_layout);
    this->setObjectName("panel");
    this->setStyleSheet("QFrame#panel {background-image: url('://background/panel.jpg');"
                                        "border: 5px solid black}");

    // Create frame for the tarot configuration buttons
    QFrame *panel_btns_frame = new QFrame;
    QVBoxLayout *panel_btns_layout = new QVBoxLayout;
    panel_btns_layout->setSpacing(10);
    panel_btns_layout->setContentsMargins(40, 30, 40, 30);
    panel_btns_frame->setLayout(panel_btns_layout);
    // panel_btns_frame->setStyleSheet("QFrame {border: 2px solid red}");
    panel_layout->addWidget(panel_btns_frame);

    // Create tarot configuration buttons
    QPushButton *panel_btns[4] = {new QPushButton, new QPushButton, new QPushButton, new QPushButton};
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
    QLabel *panel_deck_label = new QLabel;
    QPixmap pixmap;
    if (pixmap.load("://cards/Card Back.png"))
    {
        pixmap = pixmap.scaled(300, 400, Qt::KeepAspectRatio);
        panel_deck_label->setPixmap(pixmap);
    }
    panel_deck_label->setAlignment(Qt::AlignCenter);
    panel_deck_label->setContentsMargins(20, 20, 20, 20);
    panel_layout->addWidget(panel_deck_label);
}