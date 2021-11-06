#include <ScalingLabel.h>

ScalingLabel::ScalingLabel(QWidget *parent)
    : QLabel(parent)
{
    this->setMinimumSize(1,1);
    this->setScaledContents(false);
}

void ScalingLabel::setPixmap(const QPixmap &p, ScalingLabel *match)
{
    pix = p;
    match_scaling = match;
    QLabel::setPixmap(scaledPixmap(match_scaling));
}

QPixmap ScalingLabel::scaledPixmap(ScalingLabel *match_scaling) const
{
    QSize size;
    if (match_scaling != nullptr) {size = match_scaling->size();}
    else {size = this->size();}
    
    if (!max_size.isEmpty())
    {
        if (size.width() > max_size.width()) {size.rwidth() = max_size.width();}
        if (size.height() > max_size.height()) {size.rheight() = max_size.height();}
    }
    
    return pix.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void ScalingLabel::resizeEvent(QResizeEvent *e)
{
    if (!pix.isNull())
    {
        QLabel::setPixmap(scaledPixmap(match_scaling));
    }
}