#QTon Class Reference

The QTon (Qt Object Notation) is a container/encoder/decoder of JSON.

##Public vars:
>bool [autoType](https://github.com/TrigenSoftware/QTon#bool-qtonautotype "")

##Public Functions:
> [QTon()](https://github.com/TrigenSoftware/QTon#qtonqton "") <br/>
> [QTon(QString json)](https://github.com/TrigenSoftware/QTon#qtonqtonqstring-json "") <br/>
> [QTon(const QTon &hash, QString forcetype = "none")](https://github.com/TrigenSoftware/QTon#qtonqtonconst-qton-hash-qstring-forcetype--none "") <br/>
> [QTon(QList< QPair< QString, QVariant > > pairs, QString forcetype = "none")](https://github.com/TrigenSoftware/QTon#qtonqtonqlist-qpair-qstring-qvariant---pairs-qstring-forcetype--none "") <br/>
> [QTon(QHash< QString, QVariant > hash, QString forcetype = "none")](https://github.com/TrigenSoftware/QTon#qtonqtonqhash-qstring-qvariant--hash-qstring-forcetype--none "") <br/>
> [QTon(QMap< QString, QVariant > map, QString forcetype = "none")](https://github.com/TrigenSoftware/QTon#qtonqtonqmap-qstring-qvariant--map-qstring-forcetype--none "") <br/>
> [QTon(QStringList keys, QHash< QString, QVariant > hash, QString forcetype = "none")](https://github.com/TrigenSoftware/QTon#qtonqtonqstringlist-keys-qhash-qstring-qvariant--hash-qstring-forcetype--none "") <br/>
> [QTon(QStringList keys, QMap< QString, QVariant > map, QString forcetype = "none")](https://github.com/TrigenSoftware/QTon#qtonqtonqstringlist-keys-qmap-qstring-qvariant--map-qstring-forcetype--none "") <br/>
> QStringList [keys()](https://github.com/TrigenSoftware/QTon#qstringlist-qtonkeys "") <br/>
> QList< QVariant > [values()](https://github.com/TrigenSoftware/QTon#qlist-qvariant--qtonvalues "") <br/>
> QPair< QString, QVariant > [pair(int index)](https://github.com/TrigenSoftware/QTon#qpair-qstring-qvariant--qtonpairint-index "") <br/>
> QString [key(QVariant value)](https://github.com/TrigenSoftware/QTon#qstring-qtonkeyqvariant-value "") <br/>
> QVariant [value(QString key)](https://github.com/TrigenSoftware/QTon#qvariant-qtonvalueqstring-key "") <br/>
> QString [toString()](https://github.com/TrigenSoftware/QTon#qstring-qtontostring "") <br/>
> QMap< QString, QVariant > [toMap()](https://github.com/TrigenSoftware/QTon#qmap-qstring-qvariant--qtontomap "") <br/>
> QHash< QString, QVariant > [toHash()](https://github.com/TrigenSoftware/QTon#qhash-qstring-qvariant--qtontohash "") <br/>
> QList< QPair< QString, QVariant > > [toPairs()](https://github.com/TrigenSoftware/QTon#qlist-qpair-qstring-qvariant---qtontopairs "") <br/>
> void [push_front(QString key, QVariant value)](https://github.com/TrigenSoftware/QTon#void-qtonpush_frontqstring-key-qvariant-value "") <br/>
> void [push_front(QPair< QString, QVariant > pair)](https://github.com/TrigenSoftware/QTon#void-qtonpush_frontqpair-qstring-qvariant--pair "") <br/>
> void [push_front(QList< QPair< QString, QVariant > > pairs, bool reverse = false)](https://github.com/TrigenSoftware/QTon#void-qtonpush_frontqlist-qpair-qstring-qvariant---pairs-bool-reverse--false "") <br/>
> void [push_back(QString key, QVariant value)](https://github.com/TrigenSoftware/QTon#void-qtonpush_backqstring-key-qvariant-value "") <br/>
> void [push_back(QPair< QString, QVariant > pair)](https://github.com/TrigenSoftware/QTon#void-qtonpush_backqpair-qstring-qvariant--pair "") <br/>
> void [push_back(QList< QPair< QString, QVariant > > pairs, bool reverse = false)](https://github.com/TrigenSoftware/QTon#void-qtonpush_backqlist-qpair-qstring-qvariant---pairs-bool-reverse--false "") <br/>
> void [insert(QString key, QVariant value)](https://github.com/TrigenSoftware/QTon#void-qtoninsertqstring-key-qvariant-value "") <br/>
> void [insert(QPair< QString, QVariant > pair)](https://github.com/TrigenSoftware/QTon#void-qtoninsertqpair-qstring-qvariant--pair "") <br/>
> void [insert(QList< QPair< QString, QVariant > > pairs)](https://github.com/TrigenSoftware/QTon#void-qtoninsertqlist-qpair-qstring-qvariant--pairs "") <br/>
> QVariant [&operator&#91;&#93;(const QString &key)](https://github.com/TrigenSoftware/QTon#qvariant-qtonoperatorconst-qstring-key "") <br/>
> const QVariant [operator&#91;&#93;(const QString &key) const](https://github.com/TrigenSoftware/QTon#const-qvariant-qtonoperatorconst-qstring-key-const "") <br/>
> QPair< QString, QVariant > [first()](https://github.com/TrigenSoftware/QTon#qpair-qstring-qvariant--qtonfirst "") <br/>
> QPair< QString, QVariant > [last()](https://github.com/TrigenSoftware/QTon#qpair-qstring-qvariant--qtonlast "") <br/>
> bool [move(int from, int to)](https://github.com/TrigenSoftware/QTon#bool-qtonmoveint-from-int-to "") <br/>
> bool [remove(int at)](https://github.com/TrigenSoftware/QTon#bool-qtonremoveint-at "") <br/>
> bool [remove(QString key)](https://github.com/TrigenSoftware/QTon#bool-qtonremoveqstring-key "") <br/>
> bool [remove(QVariant value)](https://github.com/TrigenSoftware/QTon#bool-qtonremoveqvariant-value "") <br/>
> bool [removeFirst()](https://github.com/TrigenSoftware/QTon#bool-qtonremovefirst "") <br/>
> bool [removeLast()](https://github.com/TrigenSoftware/QTon#bool-qtonremovelast "") <br/>
> void [reverse()](https://github.com/TrigenSoftware/QTon#void-qtonreverse "") <br/>
> bool [contains(QString key)](https://github.com/TrigenSoftware/QTon#bool-qtoncontainsqstring-key "") <br/>
> bool [contains(QVariant value)](https://github.com/TrigenSoftware/QTon#bool-qtoncontainsqvariant-value "") <br/>
> void [seektype()](https://github.com/TrigenSoftware/QTon#void-qtonseektype "") <br/>
> bool [isObject()](https://github.com/TrigenSoftware/QTon#bool-qtonisobject "") <br/>
> bool [isArray()](https://github.com/TrigenSoftware/QTon#bool-qtonisarray "") <br/>
> bool [setType(QString t)](https://github.com/TrigenSoftware/QTon#bool-qtonsettypeqstring-t "") <br/>
> bool [setType(int t)](https://github.com/TrigenSoftware/QTon#bool-qtonsettypeint-t "") <br/>
> QString [typeOf()](https://github.com/TrigenSoftware/QTon#qstring-qtontypeof "") <br/>
> int [count()](https://github.com/TrigenSoftware/QTon#int-qtoncount "") <br/>
> bool [isEmpty()](https://github.com/TrigenSoftware/QTon#bool-qtonisempty "") <br/>
> void [clear()](https://github.com/TrigenSoftware/QTon#void-qtonclear "") <br/>
> QString [literal_encode(QString string)](https://github.com/TrigenSoftware/QTon#qstring-qtonliteral_encodeqstring-string "") <br/>

##Detailed Description
The QTon is a container/encoder/decoder of JSON.

In fact it is QHash<QString,QVariant> but with external list of keys (QStringList), because in QHash's data is stored randomly. In QTon  data is stored in the order in which they have been filled (as in the QStringList).

Functions which presented in QTon are similar functions in QHash.

**Necessary:** add "script" in *.pro. e.g.:
    QT += core gui\   
               webkit\ 
               network\ 
               script

##Member Type Documentation

>###bool QTon::autoType

If this true, then type(array or object) of QTon will be automatically assigned.

>###QTon::QTon()

Constructs an empty object notation.

>###QTon::QTon(QString json)

Construct an object notation from JSON string.

>###QTon::QTon(const QTon &hash, QString forcetype = "none")

Construct an QTon from another QTon object. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QList< QPair< QString, QVariant > > pairs, QString forcetype = "none")

Construct an object notation from QList of QPairs. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QHash< QString, QVariant > hash, QString forcetype = "none")

Construct an object notation from QHash. Data will stored randomly. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QMap< QString, QVariant > map, QString forcetype = "none")

Construct an object notation from QMap. Data will be stored in ascending order. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QStringList keys, QHash< QString, QVariant > hash, QString forcetype = "none")

Construct an object notation from QHash. Data will be stored link in keys(QStringList). If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QStringList keys, QMap< QString, QVariant > map, QString forcetype = "none")

Construct an object notation from QMap. Data will be stored link in keys(QStringList). If forcetype is "array" or "object", this type will be assigned. 

>###QStringList QTon::keys()

Returns a list containing all the keys in the object notation.

>###QList< QVariant > QTon::values()

Returns a list containing all the values in the object notation.

>###QPair< QString, QVariant > QTon::pair(int index)

Returns a key-value pair at index(int).

>###QString QTon::key(QVariant value)

Returns the first key mapped to value.

>###QVariant QTon::value(QString key)

Returns the value associated with the key.

>###QString QTon::toString()

Returns the JSON string.

>###QMap< QString, QVariant > QTon::toMap()

Returns the map. Data will be stored in ascending order. 

>###QHash< QString, QVariant > QTon::toHash()

Returns the hash. Data will stored randomly.

>###QList< QPair< QString, QVariant > > QTon::toPairs()

Returns the list of pairs.

>###void QTon::push_front(QString key, QVariant value)

Inserts key-value at the beginning of the object notation.

>###void QTon::push_front(QPair< QString, QVariant > pair)

Inserts key-value pair at the beginning of the object notation.

>###void QTon::push_front(QList< QPair< QString, QVariant > > pairs, bool reverse = false)

Inserts key-value pairs at the beginning of the object notation. If reverse is true, list will be pushed reversed.

>###void QTon::push_back(QString key, QVariant value)

Inserts key-value at the end of the object notation.

>###void QTon::push_back(QPair< QString, QVariant > pair)

Inserts key-value pair at the end of the object notation.

>###void QTon::push_back(QList< QPair< QString, QVariant > > pairs, bool reverse = false)

Inserts key-value pairs at the end of the object notation. If reverse is true, list will be pushed reversed.

>###void QTon::insert(QString key, QVariant value)

It is equivalent to push_back(QString key, QVariant value).

>###void QTon::insert(QPair< QString, QVariant > pair)

It is equivalent to push_back(QPair< QString, QVariant > pair).

>###void QTon::insert(QList< QPair< QString, QVariant> > pairs)

It is equivalent to push_back(QList< QPair< QString, QVariant > > pairs).

>###QVariant QTon::&operator&#91;&#93;(const QString &key)

Returns the value associated with the key as a modifiable reference.

If the object notation contains no item with the key, the function inserts a default-constructed value into the object notation with the key, and returns a reference to it. If the object notation contains multiple items with the key, this function returns a reference to the most recently inserted value.

>###const QVariant QTon::operator&#91;&#93;(const QString &key) const

This is an overloaded function. Same as value().

>###QPair< QString, QVariant > QTon::first()

Returns the first key-value pair.

>###QPair< QString, QVariant > QTon::last()

Returns the last key-value pair.

>###bool QTon::move(int from, int to)

Moves the item at index position from to index position to. Returns true if from(int) and to(int) is exist.

>###bool QTon::remove(int at)

Remove key-value pair at at(int). Returns true if at(int) is exist.

>###bool QTon::remove(QString key)

Remove key-value pair where key is key(QString). Returns true if key(QString) is exist.

>###bool QTon::remove(QVariant value)

Remove key-value pair where value is value(QVariant). Returns true if value(QVariant) is exist.

>###bool QTon::removeFirst()

Remove first key-value pair. Returns true if first pair is exist.

>###bool QTon::removeLast()

Remove last key-value pair. Returns true if last pair is exist.

>###void QTon::reverse()

Reverse keys list.

>###bool QTon::contains(QString key)

Return true if key exist.

>###bool QTon::contains(QVariant value)

Return true if value exist.

>###void QTon::seektype()

Check object notation and set type("array" or "object") to this.

>###bool QTon::isObject()

Return true if type is "object".

>###bool QTon::isArray()

Return true if type is "array".

>###bool QTon::setType(QString t)

Set type("array" or "object") to object notation. Return true t(QString) is "array" or "object".

>###bool QTon::setType(int t)

Set type(1 -"array" or 0 - "object") to object notation. Return true t(QString) is 0 or 1.

>###QString QTon::typeOf()

Returns "array" or "object".

>###int QTon::count()

Count of key-value pairs.

>###bool QTon::isEmpty()

Return true if count of items is 0.

>###void QTon::clear()

Removes all items from the object notation.

>###QString QTon::literal_encode(QString string)

Convert string to JSON-ready string. 