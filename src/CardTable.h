#include <QFrame>

class CardTable : public QFrame
{
    public:
        CardTable(QFrame *parent = nullptr);

    private:
        void ThreeCardSpread();
        void FiveCardCross();
        void SevenCardCrescent();
        void CelticCross();
};