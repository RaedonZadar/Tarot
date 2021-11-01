#include <QFrame>
#include <QString>
#include <TarotDeck.h>

class CardTable : public QFrame
{
    public:
        CardTable(QFrame *parent = nullptr);

    public slots:
        void applyConfig(QString config);

    private:
        TarotDeck *deck = new TarotDeck;
        QLayout *layout;
        void threeCardSpread();
        void fiveCardCross();
        void sevenCardCrescent();
        void celticCross();
        void resetTable(QLayout *layout);
};