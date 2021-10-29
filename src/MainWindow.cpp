#include <QGridLayout>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Initialise();
}

void MainWindow::Initialise()
{   
    // Create widget and set it as the central widget
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    // Create layout for the central widget
    QGridLayout *grid = new QGridLayout;
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setColumnStretch(0, 4);
    grid->setColumnStretch(1, 1);
    widget->setLayout(grid);

    // Create frame for the tarot card reading area
    QFrame *table = new QFrame;
    table->setStyleSheet("border-image: url('://background/table.png')");
    grid->addWidget(table, 0, 0);

    // Create frame for the tarot configuration buttons and tarot deck
    QFrame *panel = new QFrame;
    QVBoxLayout *panel_layout = new QVBoxLayout;
    panel->setLayout(panel_layout);
    panel->setObjectName("panel");
    panel->setStyleSheet("QFrame#panel {background-image: url('://background/panel.jpg');"
                                       "border: 5px solid black}");
    grid->addWidget(panel, 0, 1);

    // Create frame for the tarot configuration buttons
    QFrame *panel_btns_frame = new QFrame;
    QVBoxLayout *panel_btns_layout = new QVBoxLayout;
    panel_btns_frame->setLayout(panel_btns_layout);
    panel_btns_frame->setStyleSheet("QFrame {border: 2px solid red}");
    panel_btns_frame->setContentsMargins(20, 0, 20, 0);
    panel_layout->addWidget(panel_btns_frame);

    // Create tarot configuration buttons
    QPushButton *panel_btns[4] = {new QPushButton, new QPushButton, new QPushButton, new QPushButton};
    QString *panel_btns_text[4] = {new QString("3 Card Spread"), new QString("5 Card Cross"),
                                   new QString("7 Card Crescent"), new QString("Celtic Cross")};
    for (int i = 0; i < 4; ++i)
    {
        panel_btns[i]->setText(*panel_btns_text[i]);
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
    panel_deck_label->setContentsMargins(10, 10, 10, 10);
    panel_layout->addWidget(panel_deck_label);

}