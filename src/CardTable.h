#include <QFrame>
#include <QString>

class CardTable : public QFrame
{
    public:
        CardTable(QFrame *parent = nullptr);

    public slots:
        void applyConfig(QString config);

    private:
        void ThreeCardSpread();
        void FiveCardCross();
        void SevenCardCrescent();
        void CelticCross();
};