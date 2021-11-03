#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <QFrame>
#include <QPushbutton>
#include <ScalingLabel.h>

class SidePanel : public QFrame
{
    public:
        SidePanel(QFrame *parent = nullptr);
        QPushButton *panel_btns[4] = {new QPushButton, new QPushButton, new QPushButton, new QPushButton};

    private:
        ScalingLabel *card_deck;
};
#endif