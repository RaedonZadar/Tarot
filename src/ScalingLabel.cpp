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
    pix = p;
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
        {return pix_rotated.scaled(size.transposed(), Qt::KeepAspectRatio, Qt::SmoothTransformation);}
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