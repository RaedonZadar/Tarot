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
        QSize max_size;

    public slots:
        void setPixmap(const QPixmap & = QPixmap());
        void resizeEvent(QResizeEvent *);
        void onClick();

    private:
        QPixmap pix;
        QPixmap pix_rotated;
        QPixmap card_back = QPixmap("://cards/Card Back.png");
        bool face_down = true;

    protected:
        void mousePressEvent(QMouseEvent *e);
};
#endif