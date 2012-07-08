/****************************************************************************
**Copyright (C) 2012 TrigenSoftware
**
**Permission is hereby granted, free of charge, to any person obtaining a
**copy of this software and associated documentation files (the "Software"),
**to deal in the Software without restriction, including without limitation
**the rights to use, copy, modify, merge, publish, distribute, sublicense,
**and/or sell copies of the Software, and to permit persons to whom the
**Software is furnished to do so, subject to the following conditions:
**
**The above copyright notice and this permission notice shall be included in
**all copies or substantial portions of the Software.
**
**THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
**IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
**FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
**AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
**LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
**FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
**DEALINGS IN THE SOFTWARE.
**
****************************************************************************/

#ifndef QTON_H
#define QTON_H

#include <QMap>
#include <QPair>
#include <QHash>
#include <QList>
#include <QVariant>
#include <QTextCodec>
#include <QStringList>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValueIterator>

class QTon
{
public:
    QTon();
    QTon(QString json);
    QTon(const QTon &hash, QString forcetype = "none");
    QTon(QList< QPair<QString,QVariant> > pairs, QString forcetype = "none");
    QTon(QHash<QString,QVariant> hash, QString forcetype = "none");
    QTon(QMap<QString,QVariant> map, QString forcetype = "none");
    QTon(QStringList keys, QHash<QString,QVariant> hash, QString forcetype = "none");
    QTon(QStringList keys, QMap<QString,QVariant> map, QString forcetype = "none");

    QStringList keys();
    QList<QVariant> values();

    QPair<QString,QVariant> pair(int index);
    QString key(QVariant value);
    QVariant value(QString key);

    QString toString();
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

    void seektype();
    bool isObject();
    bool isArray();
    bool setType(QString t); // "array", "object"
    bool setType(int t);
    QString typeOf();

    int count();

    void clear();

    QHash<QString,QVariant> h;
    QStringList k;
    bool autoType;
    int type; //0 - object, 1 - array;

private:
    QTon decode(QString json);
    QTon recDecode(QScriptValue value, bool isArray);
    QString encode(QTon hash);
    QString recEncode(QTon hash);
    QString clear_str(QString json);
    QString literal_encode(QString string);
};

Q_DECLARE_METATYPE(QTon);

#endif // QTON_H
