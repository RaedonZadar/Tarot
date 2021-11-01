#include <QLabel>
#include <QDir>

class Card : public QLabel
{
    public:
        Card(QLabel *parent = nullptr);
        
    private:
        QStringList CardsRemaining(QStringList cards_list, QStringList cards_used);
        QStringList cards_list = QDir(":/art/cards/").entryList();
        QStringList cards_used;
};