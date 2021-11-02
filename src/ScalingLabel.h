#include <QLabel>
#include <QPixmap>

class ScalingLabel : public QLabel
{
    Q_OBJECT

    public:
        ScalingLabel(QWidget *parent = nullptr);
        QPixmap scaledPixmap() const;

    public slots:
        void setPixmap(const QPixmap &);
        void resizeEvent(QResizeEvent *);

    private:
        QPixmap pix;
};