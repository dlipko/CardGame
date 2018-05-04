#ifndef GAME_H
#define GAME_H

class InterLayer;

#include "player.h"
#include "user.h"
#include "party.h"

#include <QMap>
#include <QString>
#include <QSet>
#include <QPair>
#include <QDebug>


class Game
{
public:
    Game();


    void setInterLayer(InterLayer *interLayer);
    void logIn(QString login, QString password);
    void signUp(QString login, QString password);

    // поиск соперника для игры
    void findCouple(QString login);

    Player *getCouple(Player*);

    // обновление игры после хода игрока
    void update(QString login, int cardId);
    // игрок пасанул
    void pass(QString login);

    // методы для взаимодействия с промежуточным слоем
    QString getPartnerLogin(QString login);
    int getPartnerScore(QString login);
    int getScore(QString login);
    int getStageScore(QString login);
    int isMyTern(QString login);
    int winValue(QString login);
    Deck *getDeck(QString login);
    Deck *getPartnerDeck(QString login);
    Deck *getHeand(QString login);

private:
    InterLayer *_interLayer;
    // соттветствие логина и пользователя
    QMap<QString, User *> _user;
    // соответствие пользователя и игрока
    QMap<User *, Player *> _player;
    // соответствие двух игроков в партии
    QMap<Player *, Player *> _couple;
    // соответствие игрока и текущей партии
    QMap<Player *, Party *> _party;

    // пользоваель ожидающий соперника
    QString _waitingForCouple;

    User *_getUser(QString);
    Player *_getPlayerByLogin(QString);
    void _startParty(Player*, Player*);
    Party *_getPartyByPlayer(Player*);
    Player *_getPartner(Player*);
    QString _getLogin(Player *);
    bool _isMyTern(Player*);
    Deck* _getDeck(Player* player);

};

#endif // GAME_H