#include <QLabel>
#include <QStringList>

class TarotDeck : public QLabel
{
    public:
        TarotDeck(QWidget *parent = nullptr);
        void createCard(QLabel *card);
        
    private:
        QStringList cardsRemaining(QStringList cards_list, QStringList cards_used);
        QStringList cards_list;
        QStringList cards_used;
};