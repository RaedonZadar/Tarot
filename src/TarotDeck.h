#include <QStringList>
#include <ScalingLabel.h>

class TarotDeck : public QLabel
{
    public:
        TarotDeck(QWidget *parent = nullptr);
        void createCard(ScalingLabel *card);
        
    private:
        QStringList cardsRemaining(QStringList cards_list, QStringList cards_used);
        QStringList cards_list;
        QStringList cards_used;
};