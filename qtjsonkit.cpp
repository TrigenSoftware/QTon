#include "qtjsonkit.h"

QtJSONKit::QtJSONKit()
{

}

QtJSONHash QtJSONKit::decode(QString json)
{

    QScriptValue value;
    QScriptEngine ng;

    value = ng.evaluate("(" + json + ")");

    return recDecode(value);
}

QtJSONHash QtJSONKit::recDecode(QScriptValue value)
{
    QtJSONHash tmp;
    QScriptValueIterator iterator(value);

    while(iterator.hasNext()){
          iterator.next();
          if(iterator.value().isArray() || iterator.value().isObject()) tmp[iterator.name()] = QVariant::fromValue(recDecode(iterator.value()));
          else if(iterator.name()!="length") {
              tmp[iterator.name()] = iterator.value().toVariant();
          }
    }

    return tmp;
}

QString QtJSONKit::encode(QtJSONHash hash)
{
    qDebug()<<hash.toPairs();
    return recEncode(hash);
}

QString QtJSONKit::recEncode(QtJSONHash hash)
{
    bool numeric;
    qDebug()<<hash.toPairs();
    //hash.keys().first().toInt(&numeric);

    QString opn = "{ ", cls = " }";
    if(numeric) opn = "[ ", cls = " ]";

    QString ret = "";
    int j = 0;

    foreach(QString key, hash.keys()){
        /*QString okey = "\""+key+"\" : ";
        if(numeric) okey = "";
        qDebug()<<QString(hash.value(key).typeName());
        if(QString(hash.value(key).typeName()) == "QVariantHash"){
            ret+=okey+recEncode(hash.value(key).value);
        } else {
            QString c =  "\"";
            if(QString(hash.value(key).typeName()) != "QString")c = "";
            ret+=okey+c+literal_encode(hash.value(key).toString())+c;
        }
        if(j++ != hash.keys().count()-1)ret+=", ";*/
    }

    return opn+ret+cls;
}

QString QtJSONKit::literal_encode(QString string)
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

    return string;
}

QtJSONHash::QtJSONHash()
{
}

QtJSONHash::QtJSONHash(const QtJSONHash &hash)
{

}

QtJSONHash::QtJSONHash(QtJSONHash &hash)
{
    QtJSONHash(hash.toPairs());
}

QtJSONHash::QtJSONHash(QList<QPair<QString, QVariant> > pairs)
{
    for(int i=0;i<pairs.count();i++){
        main_keys.push_back(pairs.at(i).first);
        main_hash[pairs.at(i).first] = pairs.at(i).second;
    }
}

QtJSONHash::QtJSONHash(QHash<QString, QVariant> hash)
{
    main_keys = hash.keys();
    main_hash = hash;
}

QtJSONHash::QtJSONHash(QMap<QString, QVariant> map)
{
    main_keys = map.keys();
    for(int i=0;i<map.keys().count();i++){
        main_hash[map.keys().at(i)] = map.value(map.keys().at(i));
    }
}

QtJSONHash::QtJSONHash(QStringList keys, QHash<QString, QVariant> hash)
{
    main_keys = keys;
    main_hash = hash;
}

QtJSONHash::QtJSONHash(QStringList keys, QMap<QString, QVariant> map)
{
    main_keys = keys;
    for(int i=0;i<map.keys().count();i++){
        main_hash[map.keys().at(i)] = map.value(map.keys().at(i));
    }
}

QStringList QtJSONHash::keys()
{
    return main_keys;
}

QList<QVariant> QtJSONHash::values()
{
    return main_hash.values();
}

QPair<QString, QVariant> QtJSONHash::pair(int index)
{
    QPair<QString, QVariant> ret;

    if(index < main_keys.count()) ret = QPair<QString, QVariant>(main_keys.at(index), main_hash.value(main_keys.at(index)) );

    return ret;
}

QString QtJSONHash::key(QVariant value)
{
    return main_hash.key(value);
}

QVariant QtJSONHash::value(QString key)
{
    return main_hash.value(key);
}

QMap<QString, QVariant> QtJSONHash::toMap()
{
    QMap<QString, QVariant> ret;

    for(int i=0;i<main_keys.count();i++){
        ret[main_keys.at(i)] = main_hash.value(main_keys.at(i));
    }

    return ret;
}

QHash<QString, QVariant> QtJSONHash::toHash()
{
    QHash<QString, QVariant> ret;

    for(int i=0;i<main_keys.count();i++){
        ret[main_keys.at(i)] = main_hash.value(main_keys.at(i));
    }

    return ret;
}

QList<QPair<QString, QVariant> > QtJSONHash::toPairs()
{
    QList<QPair<QString, QVariant> > ret;

    for(int i=0;i<main_keys.count();i++){
        ret.push_back(QPair<QString,QVariant>(main_keys.at(i), main_hash.value(main_keys.at(i))));
    }

    return ret;
}

void QtJSONHash::push_front(QString key, QVariant value)
{
    remove(key);

    main_keys.push_front(key);
    main_hash[key] = value;
}

void QtJSONHash::push_front(QPair<QString, QVariant> pair)
{
    push_front(pair.first, pair.second);
}

void QtJSONHash::push_front(QList<QPair<QString, QVariant> > pairs, bool reverse)
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

void QtJSONHash::push_back(QString key, QVariant value)
{
    remove(key);

    main_keys.push_back(key);
    main_hash[key] = value;
}

void QtJSONHash::push_back(QPair<QString, QVariant> pair)
{
    push_back(pair.first, pair.second);
}

void QtJSONHash::push_back(QList<QPair<QString, QVariant> > pairs, bool reverse)
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

void QtJSONHash::insert(QString key, QVariant value)
{
    if(main_keys.contains(key)) main_hash[key] = value;
    else push_back(key,value);
}

void QtJSONHash::insert(QPair<QString, QVariant> pair)
{
    insert(pair.first, pair.second);
}

void QtJSONHash::insert(QList<QPair<QString, QVariant> > pairs)
{
    for(int i=0;i<pairs.count();i++){
        insert(pairs.at(i).first,pairs.at(i).second);
    }
}

QVariant &QtJSONHash::operator [](const QString &key)
{
    bool exist = false;
    foreach(QString k, main_keys){
        if(k == key) exist = true;
    }
    if(!exist){
        insert(key,"");
    }

    QHash<QString, QVariant>::iterator i;
    for(i=main_hash.begin();i!=main_hash.end();++i){
        if(i.key() == key) return i.value();
    }
}

const QVariant QtJSONHash::operator [](const QString &key) const
{
    return main_hash[key];
}

QPair<QString, QVariant> QtJSONHash::first()
{
    return toPairs().first();
}

QPair<QString, QVariant> QtJSONHash::last()
{
    return toPairs().last();
}

bool QtJSONHash::move(int from, int to)
{
    if(!(from<main_keys.length() && to<main_keys.length())) return false;

    main_keys.move(from,to);
    return true;
}

bool QtJSONHash::remove(int at)
{
    if(!(at<main_keys.length())) return false;

    main_keys.removeAt(at);
    return true;
}

bool QtJSONHash::remove(QString key)
{
    for(int i=0;i<main_keys.count();i++){
        if(main_keys.at(i) == key) {
            main_hash.remove(key);
            main_keys.removeAt(i);
            return true;
        }
    }

    return false;
}

bool QtJSONHash::remove(QVariant value)
{
    for(int i=0;i<main_hash.values().count();i++){
        if(main_hash.values().at(i) == value) {
            main_hash.remove(main_hash.key(value));
            remove(main_hash.key(value));
            return true;
        }
    }

    return false;
}

bool QtJSONHash::removeFirst()
{
    return remove(main_keys.first());
}

bool QtJSONHash::removeLast()
{
    return remove(main_keys.last());
}

void QtJSONHash::reverse()
{
    QStringList tmp;

    for(int i=main_keys.count()-1;i>-1;i--){
        tmp.push_back(main_keys.at(i));
    }

    main_keys = tmp;
}

bool QtJSONHash::contains(QString key)
{
    return main_keys.contains(key);
}

bool QtJSONHash::contains(QVariant value)
{
    return main_hash.values().contains(value);
}

int QtJSONHash::count()
{
    return main_keys.count();
}

void QtJSONHash::clear()
{
    main_hash.clear();
    main_keys.clear();
}

