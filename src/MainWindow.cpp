#include <QGridLayout>
#include <QFrame>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <MainWindow.h>
#include <SidePanel.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Initialise();
}

void MainWindow::Initialise()
{   
    // Create widget and set it as the central widget
    QWidget *widget = new QWidget;
    setMinimumSize(1200, 600);
    setWindowIcon(QIcon("://cards/Icon.png"));
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

    // Create side panel for the tarot configuration buttons and tarot deck
    SidePanel *panel = new SidePanel;
    grid->addWidget(panel, 0, 1);
}