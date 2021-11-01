#include <QFrame>
#include <QPushbutton>

class SidePanel : public QFrame
{
        Q_OBJECT

    public:
        SidePanel(QFrame *parent = nullptr);
        QPushButton *panel_btns[4] = {new QPushButton, new QPushButton, new QPushButton, new QPushButton};

};