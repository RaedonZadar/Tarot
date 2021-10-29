#include <QWidget>
#include <QMainWindow>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);

    private:
        void Initialise();
};