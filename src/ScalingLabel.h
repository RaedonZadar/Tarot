#ifndef SCALINGLABEL_H
#define SCALINGLABEL_H

#include <QLabel>
#include <QPixmap>

class ScalingLabel : public QLabel
{
    Q_OBJECT

    public:
        ScalingLabel(QWidget *parent = nullptr);
        QPixmap scaledPixmap(ScalingLabel * = nullptr) const;
        ScalingLabel *match_scaling = nullptr;

    public slots:
        void setPixmap(const QPixmap &, ScalingLabel * = nullptr);
        void resizeEvent(QResizeEvent *);

    private:
        QPixmap pix;
};
#endif