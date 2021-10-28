#include <QPushButton>
#include <QGridLayout>
#include <MainWindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    CreateButton("Push me");
}

void MainWindow::CreateButton(QString text)
{
    QWidget *widget = new QWidget;
    widget->setStyleSheet("background-color: red");

    QGridLayout *grid = new QGridLayout;
    grid->setSpacing(0);
    grid->setContentsMargins(0, 0, 0, 0);
    grid->setColumnStretch(0, 4);
    grid->setColumnStretch(1, 1);
    widget->setLayout(grid);

    QPushButton *button = new QPushButton;
    button->setText(text);
    button->setStyleSheet("background-color: blue");
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    grid->addWidget(button, 0, 0);

    QPushButton *button2 = new QPushButton;
    button2->setText("No, push me!");
    button2->setStyleSheet("background-color: green");
    button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    grid->addWidget(button2, 0, 1);

    setCentralWidget(widget);
}