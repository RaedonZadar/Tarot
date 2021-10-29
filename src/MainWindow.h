#include <QWidget>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    public:
        MainWindow(QWidget *parent = nullptr);

    private:
        void Initialise();
};