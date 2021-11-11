#include <math.h>
#include <ScalingLabel.h>

ScalingLabel::ScalingLabel(QWidget *parent)
    : QLabel(parent)
{
    this->setContentsMargins(0, 0, 0, 0);
    this->setMinimumSize(1,1);
    this->setScaledContents(false);
}

void ScalingLabel::setPixmap(const QPixmap &p)
{
    p.isNull() ? pix = card_back : pix = p;
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
    
    if (!pix_rotated.isNull())
    {
        if (face_down)
            {return card_back_rotated.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);}
        else 
            {return pix_rotated.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);}
    }
    else
    {
        if (face_down)
            {return card_back.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);}
        else
            {return pix.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);}
    }
}

void ScalingLabel::resizeEvent(QResizeEvent *e)
{
    if (!pix.isNull())
    {
        QLabel::setPixmap(scaledPixmap());
    }
}

void ScalingLabel::rotatePixmap(int r)
{
    if (!pix.isNull())
    {
        rotation = qDegreesToRadians(r);
        double sinr = sin(rotation);
        double cosr = cos(rotation);
        if (r)
        {
            QTransform rotate(cosr, sinr, -sinr, cosr, 0, 0);
            pix_rotated = pix.transformed(QTransform(rotate));
            card_back_rotated = card_back.transformed(QTransform(rotate));
        }
        else
        {
            pix_rotated = QPixmap();
            card_back_rotated = QPixmap();
        }
        QLabel::setPixmap(scaledPixmap());
    }
}

void ScalingLabel::onRelease()
{
    face_down ? face_down = false : face_down = true;
    QLabel::setPixmap(scaledPixmap());
}

void ScalingLabel::mouseReleaseEvent(QMouseEvent *e)
{
    emit released();
}