#ifndef SCALINGLABEL_H
#define SCALINGLABEL_H

#include <QLabel>
#include <QPixmap>

class ScalingLabel : public QLabel
{
    Q_OBJECT

    public:
        ScalingLabel(QWidget *parent = nullptr);
        QPixmap scaledPixmap() const;
        void rotatePixmap(int rotation);
        ScalingLabel *match_scaling = nullptr;
        QSize max_size;

    public slots:
        void setPixmap(const QPixmap &, ScalingLabel * = nullptr);
        void resizeEvent(QResizeEvent *);

    private:
        QPixmap pix;
        QPixmap pix_rotated;
};
#endif