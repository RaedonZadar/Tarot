#include <QWidget>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
};