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
    
    if (face_down && !pix_rotated.isNull())
        {return card_back.scaled(size.transposed(), Qt::KeepAspectRatio, Qt::SmoothTransformation);}
    else if (!pix_rotated.isNull())
        {return pix_rotated.scaled(size.transposed(), Qt::KeepAspectRatio, Qt::SmoothTransformation);}
    else if (face_down)
        {return card_back.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);}
    else
        {return pix.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);}
}

void ScalingLabel::resizeEvent(QResizeEvent *e)
{
    if (!pix.isNull())
    {
        QLabel::setPixmap(scaledPixmap());
    }
}

void ScalingLabel::rotatePixmap(int rotation)
{
    if (rotation == 0) {pix_rotated = QPixmap();}
    else {pix_rotated = pix.transformed(QTransform().rotate(rotation));}
    QLabel::setPixmap(scaledPixmap());
}

void ScalingLabel::onClick()
{
    face_down ? face_down = false : face_down = true;
    QLabel::setPixmap(scaledPixmap());
}

void ScalingLabel::mousePressEvent(QMouseEvent *e)
{
    onClick();
}