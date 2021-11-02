#include <ScalingLabel.h>

ScalingLabel::ScalingLabel(QWidget *parent)
    : QLabel(parent)
{
    // this->setContentsMargins(0, 0, 0, 0);
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
    return pix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void ScalingLabel::resizeEvent(QResizeEvent *e)
{
    if (!pix.isNull())
    {
        QLabel::setPixmap(scaledPixmap());
    }
}