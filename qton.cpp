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

#include "qton.h"

QTon::QTon()
{
    autoType = true;
}

QTon::QTon(QString json)
{
    QTon hash = decode(json);

    h = hash.h;
    k = hash.k;

    autoType = hash.autoType;
    setType(hash.type);
}

QTon::QTon(const QTon &hash, QString forcetype)
{
    h = hash.h;
    k = hash.k;

    autoType = hash.autoType;
    if(!setType(forcetype)) setType(hash.type);
}

QTon::QTon(QList<QPair<QString, QVariant> > pairs, QString forcetype)
{
    for(int i=0;i<pairs.count();i++){
        k.push_back(pairs.at(i).first);
        h[pairs.at(i).first] = pairs.at(i).second;
    }

    autoType = true;
    setType(forcetype);
    seektype();
}

QTon::QTon(QHash<QString, QVariant> hash, QString forcetype)
{
    k = hash.keys();
    h = hash;

    autoType = true;
    setType(forcetype);
    seektype();
}

QTon::QTon(QMap<QString, QVariant> map, QString forcetype)
{
    k = map.keys();
    for(int i=0;i<map.keys().count();i++){
        h[map.keys().at(i)] = map.value(map.keys().at(i));
    }

    autoType = true;
    setType(forcetype);
    seektype();
}

QTon::QTon(QStringList keys, QHash<QString, QVariant> hash, QString forcetype)
{
    k = keys;
    h = hash;

    autoType = true;
    setType(forcetype);
    seektype();
}

QTon::QTon(QStringList keys, QMap<QString, QVariant> map, QString forcetype)
{
    k = keys;
    for(int i=0;i<map.keys().count();i++){
        h[map.keys().at(i)] = map.value(map.keys().at(i));
    }

    autoType = true;
    setType(forcetype);
    seektype();
}

QStringList QTon::keys()
{
    return k;
}

QList<QVariant> QTon::values()
{
    return h.values();
}

QPair<QString, QVariant> QTon::pair(int index)
{
    QPair<QString, QVariant> ret;

    if(index < k.count()) ret = QPair<QString, QVariant>(k.at(index), h.value(k.at(index)) );

    return ret;
}

QString QTon::key(QVariant value)
{
    return h.key(value);
}

QVariant QTon::value(QString key)
{
    return h.value(key);
}

QString QTon::toString()
{
    return encode(*this);
}

QMap<QString, QVariant> QTon::toMap()
{
    QMap<QString, QVariant> ret;

    for(int i=0;i<k.count();i++){
        ret[k.at(i)] = h.value(k.at(i));
    }

    return ret;
}

QHash<QString, QVariant> QTon::toHash()
{
    QHash<QString, QVariant> ret;

    for(int i=0;i<k.count();i++){
        ret[k.at(i)] = h.value(k.at(i));
    }

    return ret;
}

QList<QPair<QString, QVariant> > QTon::toPairs()
{
    QList<QPair<QString, QVariant> > ret;

    for(int i=0;i<k.count();i++){
        ret.push_back(QPair<QString,QVariant>(k.at(i), h.value(k.at(i))));
    }

    return ret;
}

void QTon::push_front(QString key, QVariant value)
{
    remove(key);

    k.push_front(key);
    h[key] = value;

    seektype();
}

void QTon::push_front(QPair<QString, QVariant> pair)
{
    push_front(pair.first, pair.second);
}

void QTon::push_front(QList<QPair<QString, QVariant> > pairs, bool reverse)
{
    QList<QPair<QString, QVariant> > tmp = pairs;
    if(!reverse){
        for(int i=pairs.count()-1;i>-1;i--){
            tmp.push_back(pairs.at(i));
        }
    }

    for(int i=0;i<tmp.count();i++){
        push_front(tmp.at(i));
    }
}

void QTon::push_back(QString key, QVariant value)
{
    remove(key);

    k.push_back(key);
    h[key] = value;

    seektype();
}

void QTon::push_back(QPair<QString, QVariant> pair)
{
    push_back(pair.first, pair.second);
}

void QTon::push_back(QList<QPair<QString, QVariant> > pairs, bool reverse)
{
    QList<QPair<QString, QVariant> > tmp = pairs;
    if(reverse){
        for(int i=pairs.count()-1;i>-1;i--){
            tmp.push_back(pairs.at(i));
        }
    }

    for(int i=0;i<tmp.count();i++){
        push_back(tmp.at(i));
    }
}

void QTon::insert(QString key, QVariant value)
{
    if(k.contains(key)) h[key] = value;
    else push_back(key,value);

    seektype();
}

void QTon::insert(QPair<QString, QVariant> pair)
{
    insert(pair.first, pair.second);
}

void QTon::insert(QList<QPair<QString, QVariant> > pairs)
{
    for(int i=0;i<pairs.count();i++){
        insert(pairs.at(i).first,pairs.at(i).second);
    }
}

QVariant &QTon::operator [](const QString &key)
{
    bool exist = false;
    foreach(QString k, k){
        if(k == key) exist = true;
    }
    if(!exist){
        insert(key,"");
        seektype();
    }

    QHash<QString, QVariant>::iterator i;
    for(i=h.begin();i!=h.end();++i){
        if(i.key() == key) return i.value();
    }
}

const QVariant QTon::operator [](const QString &key) const
{
    return h[key];
}

QPair<QString, QVariant> QTon::first()
{
    return toPairs().first();
}

QPair<QString, QVariant> QTon::last()
{
    return toPairs().last();
}

bool QTon::move(int from, int to)
{
    if(!(from<k.length() && to<k.length())) return false;

    k.move(from,to);
    return true;
}

bool QTon::remove(int at)
{
    if(!(at<k.length())) return false;

    k.removeAt(at);
    seektype();

    return true;
}

bool QTon::remove(QString key)
{
    for(int i=0;i<k.count();i++){
        if(k.at(i) == key) {
            h.remove(key);
            k.removeAt(i);
            return true;
        }
    }

    seektype();

    return false;
}

bool QTon::remove(QVariant value)
{
    for(int i=0;i<h.values().count();i++){
        if(h.values().at(i) == value) {
            h.remove(h.key(value));
            remove(h.key(value));
            return true;
        }
    }

    seektype();

    return false;
}

bool QTon::removeFirst()
{
    return remove(k.first());
}

bool QTon::removeLast()
{
    return remove(k.last());
}

void QTon::reverse()
{
    QStringList tmp;

    for(int i=k.count()-1;i>-1;i--){
        tmp.push_back(k.at(i));
    }

    k = tmp;
}

bool QTon::contains(QString key)
{
    return k.contains(key);
}

bool QTon::contains(QVariant value)
{
    return h.values().contains(value);
}

bool QTon::isObject()
{
    return !type;
}

bool QTon::isArray()
{
    return type;
}

bool QTon::setType(QString t)
{
    if(t == "object") type = 0;
    else if(t == "array") type = 1;
    else return false;

    autoType = false;

    return true;
}

bool QTon::setType(int t)
{
    if(t == 0) type = 0;
    else if(t == 1) type = 1;
    else return false;

    autoType = false;

    return true;
}

QString QTon::typeOf()
{
    if(type) return "array";
    else return "object";
}

int QTon::count()
{
    return k.count();
}

bool QTon::isEmpty()
{
    return (k.count() == 0);
}

void QTon::clear()
{
    h.clear();
    k.clear();
}

void QTon::seektype()
{
    if(!autoType) return;

    bool m = true, b;
    foreach(QString key,k){
        key.toInt(&b);
        m = m && b;
    }

    type = m;
}

QTon QTon::decode(QString json)
{

    QScriptValue value;
    QScriptEngine ng;

    json = clear_str(json);
    value = ng.evaluate("(" + json + ")");

    return recDecode(value,(json.at(0) == QChar(*QString("[").toAscii().data())));
}

QTon QTon::recDecode(QScriptValue value, bool isArray)
{
    QTon tmp;
    QScriptValueIterator iterator(value);

    while(iterator.hasNext()){
          iterator.next();
          if(iterator.value().isArray() || iterator.value().isObject()) tmp[iterator.name()] = QVariant::fromValue(recDecode(iterator.value(),iterator.value().isArray()));
          else if(iterator.name()!="length") {
              tmp[iterator.name()] = iterator.value().toVariant();
          }
    }

    tmp.setType(isArray);

    return tmp;
}

QString QTon::encode(QTon hash)
{
    return recEncode(hash);
}

QString QTon::recEncode(QTon hash)
{
    bool isArray = hash.isArray();

    QString opn = "{ ", cls = " }";
    if(isArray) opn = "[ ", cls = " ]";

    QString ret = "";
    int j = 0;

    foreach(QString key, hash.keys()){
        QString okey = "\""+key+"\" : ";
        if(isArray) okey = "";
        if(QString(hash.value(key).typeName()) == "QTon"){
            ret+=okey+recEncode(hash.value(key).value<QTon>());
        } else {
            QString c = "\"";
            if(QString(hash.value(key).typeName()) != "QString")c = "";
            ret+=okey+c+literal_encode(hash.value(key).toString())+c;
        }
        if(j++ != hash.keys().count()-1)ret+=", ";
    }

    return opn+ret+cls;
}


QString QTon::clear_str(QString json)
{
    QString ret = "";
    bool may = true;

    for(int i=0;i<json.length();i++){
      if(json.at(i) == QChar(*QString("\"").toAscii().data())) may = !may;
      if(json.at(i) != QChar(*QString(" ").toAscii().data()) || !may) ret += json.at(i);
    }
    return ret;
}

QString QTon::literal_encode(QString string)
{
    string.replace("\\","\\\\");
    string.replace("/","\\/");
    string.replace("\"","\\\"");
    string.replace("\?","\\?");
    string.replace("\a","\\a");
    string.replace("\b","\\b");
    string.replace("\f","\\f");
    string.replace("\r","\\r");
    string.replace("\n","\\n");
    string.replace("\t","\\t");
    string.replace("\v","\\v");

    QString res;
    res.reserve(6 * string.size());
    for(QString::const_iterator it = string.begin(); it != string.end(); ++it) {
        QChar ch = *it;
        ushort code = ch.unicode();
        if (code < 0x80) {
          res += ch;
        } else {
          res += "\\u";
          res += QString::number(code, 16).rightJustified(4, '0');
        }
    }
    string = res;

    return string;
}
