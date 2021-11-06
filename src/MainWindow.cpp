#include <QDebug>
#include <QGridLayout>
#include <MainWindow.h>
#include <CardTable.h>
#include <SidePanel.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   
    // Create widget and set it as the central widget
    QWidget *widget = new QWidget;
    setMinimumSize(1250, 759);
    setWindowIcon(QIcon("://icon/Icon.png"));
    setCentralWidget(widget);

    // Create layout for the central widget
    QGridLayout *grid = new QGridLayout;
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setColumnStretch(0, 4);
    grid->setColumnStretch(1, 1);
    widget->setLayout(grid);

    // Create card table for the tarot card reading area
    CardTable *table = new CardTable;
    grid->addWidget(table, 0, 0);

    // Create side panel for the tarot configuration buttons and tarot deck
    SidePanel *panel = new SidePanel;
    grid->addWidget(panel, 0, 1);

    // Connect SidePanel buttons to CardTable
    for (int i = 0; i < 4; ++i)
    {
        QPushButton *btn = panel->panel_btns[i];
        QString config = btn->text();
        ScalingLabel *card_deck = panel->card_deck;
        QObject::connect(btn, &QPushButton::released, [table, config, card_deck](){table->applyConfig(config, card_deck);});
    }
}