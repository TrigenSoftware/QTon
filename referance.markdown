#QTon Class Reference

The QTon (Qt Object Notation) is a container/encoder/decoder of JSON.

##Public vars:
>bool autoType

##Public Functions:
> [QTon()](https://github.com/TrigenSoftware/QTon/blob/master/referance.markdown#bool-qtonautotype "QTon()") <br/>
> QTon(QString json)
> QTon(const QTon &hash, QString forcetype = "none")
> QTon(QList< QPair<QString,QVariant> > pairs, QString forcetype = "none")
> QTon(QHash<QString,QVariant> hash, QString forcetype = "none")
> QTon(QMap<QString,QVariant> map, QString forcetype = "none")
> QTon(QStringList keys, QHash<QString,QVariant> hash, QString forcetype = "none")
> QTon(QStringList keys, QMap<QString,QVariant> map, QString forcetype = "none")
> QStringList keys()
> QList<QVariant> values()
> QPair<QString,QVariant> pair(int index)
> QString key(QVariant value)
> QVariant value(QString key)
> QString toString()
> QMap<QString,QVariant> toMap()
> QHash<QString,QVariant> toHash()
> QList< QPair<QString,QVariant> > toPairs()
> void push_front(QString key, QVariant value)
> void push_front(QPair<QString,QVariant> pair)
> void push_front(QList< QPair<QString,QVariant> pairs, bool reverse = false)
> void push_back(QString key, QVariant value)
> void push_back(QPair<QString,QVariant> pair)
> void push_back(QList< QPair<QString,QVariant> > pairs, bool reverse = false)
> void insert(QString key, QVariant value)
> void insert(QPair<QString,QVariant> pair)
> void insert(QList< QPair<QString,QVariant> > pairs)
> QVariant &operator[](const QString &key)
> const QVariant operator[](const QString &key) const
> QPair<QString,QVariant> first()
> QPair<QString,QVariant> last()
> bool move(int from, int to)
> bool remove(int at)
> bool remove(QString key)
> bool remove(QVariant value)
> bool removeFirst()
> bool removeLast()
> void reverse()
> bool contains(QString key)
> bool contains(QVariant value)
> void seektype()
> bool isObject()
> bool isArray()
> bool setType(QString t)
> bool setType(int t)
> QString typeOf()
> int count()
> bool isEmpty()
> void clear() 
> QString literal_encode(QString string);

##Detailed Description
The QTon is a container/encoder/decoder of JSON.

In fact it is QHash<QString,QVariant> but with external list of keys (QStringList), because in QHash's data is stored randomly. In QTon  data is stored in the order in which they have been filled (as in the QStringList).

Functions which presented in QTon are similar functions in QHash.

##Member Type Documentation

>###bool QTon::autoType

If this true, then type(array or object) of QTon will be automatically assigned.

>###QTon::QTon()

Constructs an empty object notation.

>###QTon::QTon(QString json)

Construct an object notation from JSON string.

>###QTon::QTon(const QTon &hash, QString forcetype = "none")

Construct an QTon from another QTon object. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QList< QPair<QString,QVariant> > pairs, QString forcetype = "none")

Construct an object notation from QList of QPairs. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QHash<QString,QVariant> hash, QString forcetype = "none")

Construct an object notation from QHash. Data will stored randomly. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QMap<QString,QVariant> map, QString forcetype = "none")

Construct an object notation from QMap. Data will be stored in ascending order. If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QStringList keys, QHash<QString,QVariant> hash, QString forcetype = "none")

Construct an object notation from QHash. Data will be stored link in keys(QStringList). If forcetype is "array" or "object", this type will be assigned. 

>###QTon::QTon(QStringList keys, QMap<QString,QVariant> map, QString forcetype = "none")

Construct an object notation from QMap. Data will be stored link in keys(QStringList). If forcetype is "array" or "object", this type will be assigned. 

>###QStringList QTon::keys()

Returns a list containing all the keys in the object notation.

>###QList<QVariant> QTon::values()

Returns a list containing all the values in the object notation.

>###QPair<QString,QVariant> QTon::pair(int index)

Returns a key-value pair at index(int).

>###QString QTon::key(QVariant value)

Returns the first key mapped to value.

>###QVariant QTon::value(QString key)

Returns the value associated with the key.

>###QString QTon::toString()

Returns the JSON string.

>###QMap<QString,QVariant> QTon::toMap()

Returns the map. Data will be stored in ascending order. 

>###QHash<QString,QVariant> QTon::toHash()

Returns the hash. Data will stored randomly.

>###QList< QPair<QString,QVariant> > QTon::toPairs()

Returns the list of pairs.

>###void QTon::push_front(QString key, QVariant value)

Inserts key-value at the beginning of the object notation.

>###void QTon::push_front(QPair<QString,QVariant> pair)

Inserts key-value pair at the beginning of the object notation.

>###void QTon::push_front(QList< QPair<QString,QVariant> pairs, bool reverse = false)

Inserts key-value pairs at the beginning of the object notation. If reverse is true, list will be pushed reversed.

>###void QTon::push_back(QString key, QVariant value)

Inserts key-value at the end of the object notation.

>###void QTon::push_back(QPair<QString,QVariant> pair)

Inserts key-value pair at the end of the object notation.

>###void QTon::push_back(QList< QPair<QString,QVariant> pairs, bool reverse = false)

Inserts key-value pairs at the end of the object notation. If reverse is true, list will be pushed reversed.

>###void QTon::insert(QString key, QVariant value)

It is equivalent to push_back(QString key, QVariant value).

>###void QTon::insert(QPair<QString,QVariant> pair)

It is equivalent to push_back(QPair<QString,QVariant> pair).

>###void QTon::insert(QList< QPair<QString,QVariant> pairs)

It is equivalent to ush_back(QList< QPair<QString,QVariant> pairs).

>###QVariant QTon::&operator[](const QString &key)

Returns the value associated with the key as a modifiable reference.

If the object notation contains no item with the key, the function inserts a default-constructed value into the object notation with the key, and returns a reference to it. If the object notation contains multiple items with the key, this function returns a reference to the most recently inserted value.

>###const QVariant QTon::operator[](const QString &key) const

This is an overloaded function. Same as value().

>###QPair<QString,QVariant> QTon::first()

Returns the first key-value pair.

>###QPair<QString,QVariant> QTon::last()

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