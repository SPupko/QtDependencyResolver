#include "DIContainer.h"

#include <QMetaObject>
#include <QMetaMethod>
#include <QMetaType>
#include <QDebug>

using namespace DependencyResolver;

DIContainer::DIContainer(QObject *parent) :
    QObject(parent)
{
}

DIContainer::~DIContainer()
{
}

QObject *DIContainer::ResolveByName(QString typeName)
{
    QString classPrefix = "class ";

    if (!typeName.startsWith(classPrefix))
    {
        typeName = classPrefix + typeName;
    }

    if (typeName.endsWith("*"))
    {
        typeName.chop(1);
    }

    if (!_data.contains(typeName))
    {
        qDebug() << "DIContainer: " << typeName << " is not registered or may be you forgot specify namespace in constructor!";
        return NULL;
    }

    QMetaObject metaObject = _data.value(typeName);
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

        QObject* argValue = ResolveByName(argType);

        if (argValue == NULL)
        {
            return NULL;
        }

        argNamesList << argType.toUtf8();
        ctorArgs << QGenericArgument(argNamesList[index].data(), static_cast<const void *>(&argValue));
    }

    QObject* instance = metaObject.newInstance(
                ctorArgs[0], ctorArgs[1], ctorArgs[2], ctorArgs[3], ctorArgs[4],
            ctorArgs[5], ctorArgs[6], ctorArgs[7], ctorArgs[8], ctorArgs[9]);

    if (!instance)
    {
        qDebug() << "DIContainer: could not create an instance of class "
               << metaObject.className();
        return NULL;
    }

    return instance;
}
