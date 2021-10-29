#include <QScrollArea>
#include <QFrame>
#include <QPixmap>
#include <QPushButton>
#include <QGridLayout>
#include <MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    Initialise();
}

void MainWindow::Initialise()
{    
    QWidget *widget = new QWidget;

    QGridLayout *grid = new QGridLayout;
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setColumnStretch(0, 4);
    grid->setColumnStretch(1, 1);
    widget->setLayout(grid);

    QFrame *table = new QFrame;
    table->setStyleSheet("border-image: url('://background/table.png')");
    grid->addWidget(table, 0, 0);

    QFrame *panel = new QFrame;
    panel->setStyleSheet("background-image: url('://background/panel.jpg');"
                         "border: 5px solid black;");
    grid->addWidget(panel, 0, 1);

    setCentralWidget(widget);
}