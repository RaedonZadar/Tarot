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
        void rotatePixmap(int r);
        QSize max_size;

    public slots:
        void setPixmap(const QPixmap & = QPixmap());
        void resizeEvent(QResizeEvent *);
        void onRelease();

    signals:
        void releasedLMB();

    private:
        QPixmap card_front;
        QPixmap card_front_rotated;
        QPixmap card_back;
        QPixmap card_back_rotated;
        double rotation;
        bool is_face_down;

    protected:
        void mouseReleaseEvent(QMouseEvent *e);
};
#endif