#ifndef QTJSONKIT_H
#define QTJSONKIT_H

#include <QPair>
#include <QMap>
#include <QHash>
#include <QVariant>
#include <QDebug>
#include <QList>
#include <QStringList>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>

class QtJSONHash
{
public:
    QtJSONHash();
    QtJSONHash(const QtJSONHash &hash);
    QtJSONHash(QtJSONHash &hash);
    QtJSONHash(QList< QPair<QString,QVariant> > pairs);
    QtJSONHash(QHash<QString,QVariant> hash);
    QtJSONHash(QMap<QString,QVariant> map);
    QtJSONHash(QStringList keys, QHash<QString,QVariant> hash);
    QtJSONHash(QStringList keys, QMap<QString,QVariant> map);

    QStringList keys();
    QList<QVariant> values();

    QPair<QString,QVariant> pair(int index);
    QString key(QVariant value);
    QVariant value(QString key);

    QMap<QString,QVariant> toMap();
    QHash<QString,QVariant> toHash();
    QList< QPair<QString,QVariant> > toPairs();


    void push_front(QString key, QVariant value);
    void push_front(QPair<QString,QVariant> pair);
    void push_front(QList< QPair<QString,QVariant> > pairs, bool reverse = false);
    void push_back(QString key, QVariant value);
    void push_back(QPair<QString,QVariant> pair);
    void push_back(QList< QPair<QString,QVariant> > pairs, bool reverse = false);

    void insert(QString key, QVariant value);
    void insert(QPair<QString,QVariant> pair);
    void insert(QList< QPair<QString,QVariant> > pairs);

    QVariant &operator[](const QString &key);
    const QVariant operator[](const QString &key) const;

    QPair<QString,QVariant> first();
    QPair<QString,QVariant> last();

    bool move(int from, int to);
    bool remove(int at);
    bool remove(QString key);
    bool remove(QVariant value);
    bool removeFirst();
    bool removeLast();
    void reverse();

    bool contains(QString key);
    bool contains(QVariant value);

    int count();

    void clear();

private:
    QHash<QString,QVariant> main_hash;
    QStringList main_keys;

};

Q_DECLARE_METATYPE(QtJSONHash);

class QtJSONKit
{
public:
    QtJSONKit();

    QtJSONHash decode(QString json);
    QString encode(QtJSONHash hash);
    QString literal_encode(QString string);

private:
    QtJSONHash recDecode(QScriptValue value);
    QString recEncode(QtJSONHash hash);
};

#endif // QTJSONKIT_H
