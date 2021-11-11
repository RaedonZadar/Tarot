#include <math.h>
#include <QMouseEvent>
#include <ScalingLabel.h>

ScalingLabel::ScalingLabel(QWidget *parent)
    : QLabel(parent)
{
    this->setContentsMargins(0, 0, 0, 0);
    this->setMinimumSize(1,1);
    this->setScaledContents(false);

    card_back = QPixmap("://cards/Card Back.png");
    is_face_down = true;
}

void ScalingLabel::setPixmap(const QPixmap &p)
{
    p.isNull() ? card_front = card_back : card_front = p;
    QLabel::setPixmap(scaledPixmap());
}

QPixmap ScalingLabel::scaledPixmap() const
{
    QSize size = this->size();
    
    if (!max_size.isEmpty())
    {
        size.rwidth() = max_size.width();
        size.rheight() = max_size.height();
    }
    
    QPixmap card;
    if (!card_front_rotated.isNull())
        {is_face_down ? card = card_back_rotated : card = card_front_rotated;}
    else
        {is_face_down ? card = card_back : card = card_front;}

    return card.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void ScalingLabel::resizeEvent(QResizeEvent *e)
{
    if (!card_front.isNull())
    {
        QLabel::setPixmap(scaledPixmap());
    }
}

void ScalingLabel::rotatePixmap(int r)
{
    if (!card_front.isNull())
    {
        rotation = qDegreesToRadians(r);
        double sinr = sin(rotation);
        double cosr = cos(rotation);
        if (r)
        {
            QTransform rotate(cosr, sinr, -sinr, cosr, 0, 0);
            card_front_rotated = card_front.transformed(QTransform(rotate));
            card_back_rotated = card_back.transformed(QTransform(rotate));
        }
        else
        {
            card_front_rotated = QPixmap();
            card_back_rotated = QPixmap();
        }
        QLabel::setPixmap(scaledPixmap());
    }
}

void ScalingLabel::onRelease()
{
    is_face_down ? is_face_down = false : is_face_down = true;
    QLabel::setPixmap(scaledPixmap());
}

void ScalingLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        {emit releasedLMB();}
}