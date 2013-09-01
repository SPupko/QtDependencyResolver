/****************************************************************************
* Copyright (C) 2013 Sergey Pupko <s.d.pupko@gmail.com>
*
* This library is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "DIContainer.h"

#include <QMetaObject>
#include <QMetaMethod>
#include <QDebug>

using namespace DependencyResolver;

class DIContainer::P : public QObject
{
public:
    static const char* CLASS_PREFIX;

    explicit P(QObject *parent = 0) :
        QObject(parent)
    {
    }

    virtual ~P()
    {
    }

    void RegisterMetaObject(const QString &typeName, const QMetaObject &metaObject)
    {
        _metaObjects.insert(ClearTypeName(typeName), metaObject);
    }

    bool ContainsMetaObject(const QString &typeName)
    {
        return _metaObjects.contains(ClearTypeName(typeName));
    }

    QMetaObject GetMeataObject(const QString &typeName)
    {
        return ContainsMetaObject(typeName)
                ? _metaObjects.value(ClearTypeName(typeName))
                : QMetaObject();
    }

    void RegisterValue(const QString &typeName, const QString &key, const QVariant &value)
    {
        if (!_objects.contains(typeName))
        {
            _objects.insert(typeName, QHash<QString, QVariant>());
        }

        _objects[typeName].insert(key, value);
    }

    bool ContainsValue(const QString &typeName, const QString &key)
    {
        if (!_objects.contains(typeName))
        {
            return false;
        }

        if (!_objects[typeName].contains(key))
        {
            return false;
        }

        return true;
    }

    QVariant GetValue(const QString &typeName, const QString &key)
    {
        return ContainsValue(typeName, key)
                ? _objects[typeName].value(key)
                : QVariant();
    }

private:
    QString ClearTypeName(const QString &typeName)
    {
        QString result = typeName;

        return result.startsWith(CLASS_PREFIX)
                ? result.remove(CLASS_PREFIX)
                : result;
    }

private:
    QHash<QString, QMetaObject> _metaObjects;
    QHash<QString, QHash<QString, QVariant> > _objects;
};

const char* DIContainer::P::CLASS_PREFIX = "class ";

DIContainer::DIContainer(QObject *parent) :
    QObject(parent),
    _d(QSharedPointer<P>(new P))
{
}

DIContainer::~DIContainer()
{
}

void DIContainer::Register(const QString &typeName, const QMetaObject &metaObject)
{
    _d->RegisterMetaObject(typeName, metaObject);
}

void DIContainer::Register(const QString &typeName, const QString &key, const QVariant &value)
{
    _d->RegisterValue(typeName, key, value);
}

QObject *DIContainer::ResolveByName(QString typeName)
{
    if (typeName.endsWith("*"))
    {
        typeName.chop(1);
    }

    if (!_d->ContainsMetaObject(typeName))
    {
        qDebug() << "DIContainer: " << typeName << " is not registered or may be you forgot specify namespace in constructor!";
        return NULL;
    }

    QMetaObject metaObject = _d->GetMeataObject(typeName);
    QMetaMethod constructorType = metaObject.constructor(0);
    QList<QGenericArgument> ctorArgs;
    QList<QByteArray> argNamesList;

    for (quint8 index = 0; index < 10; index++)
    {
        if (index >= constructorType.parameterTypes().count())
        {
            argNamesList << QByteArray();
            ctorArgs << QGenericArgument();
            continue;
        }

        QString argType = constructorType.parameterTypes().at(index);
        QString argName = constructorType.parameterNames().at(index);

        if (argType == "QObject*" && argName == "parent")
        {
            argNamesList << QByteArray();
            ctorArgs << Q_ARG(QObject*, 0);
            continue;
        }

        if (_d->ContainsValue(argType, argName))
        {
            argNamesList << argType.toUtf8();
            ctorArgs << QGenericArgument(argNamesList[index].data(), _d->GetValue(argType, argName).constData());
            continue;
        }

        QObject* argValue = ResolveByName(argType);

        if (argValue == NULL)
        {
            return NULL;
        }

        argNamesList << argType.toUtf8();
        ctorArgs << QGenericArgument(argNamesList[index].data(), static_cast<const void *>(&argValue));
    }

    QObject* instance = metaObject.newInstance(ctorArgs[0], ctorArgs[1], ctorArgs[2], ctorArgs[3], ctorArgs[4],
            ctorArgs[5], ctorArgs[6], ctorArgs[7], ctorArgs[8], ctorArgs[9]);

    if (!instance)
    {
        qDebug() << "DIContainer: could not create an instance of class " << metaObject.className();
        return NULL;
    }

    return instance;
}
