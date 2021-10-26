#include <QApplication>
#include <QMainWindow>
#include <QPushButton>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow window;
    window.resize(600, 400);
    QPushButton button;
    button.setText("Push me");
    window.setCentralWidget(&button);
    window.show();

    return app.exec();
}