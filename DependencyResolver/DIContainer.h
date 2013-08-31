#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>
#include <QDebug>

#include "dependencyresolver_global.h"

namespace DependencyResolver
{
    class DEPENDENCYRESOLVERSHARED_EXPORT DIContainer : public QObject
    {
        Q_OBJECT
    public:
        explicit DIContainer(QObject *parent = 0);
        virtual ~DIContainer();

        template <typename ResolvableType, typename Type>
        void Bind()
        {
            QObject* typeToObjectCastCheck = static_cast<Type*>(0); Q_UNUSED(typeToObjectCastCheck);
            ResolvableType* typeToResolvableTypeCastCheck = static_cast<Type*>(0); Q_UNUSED(typeToResolvableTypeCastCheck);
            _data.insert(QString(typeid(ResolvableType).name()), static_cast<Type*>(0)->staticMetaObject);
        }

        template <typename ResolvableType>
        ResolvableType* Resolve()
        {
            return qobject_cast<ResolvableType*>(ResolveByName(QString(typeid(ResolvableType).name())));
        }

    private:
        QObject* ResolveByName(QString typeName);

    private:
        QHash<QString, QMetaObject> _data;
    };

    typedef QSharedPointer<DIContainer> DIContainerPtr;
}

Q_DECLARE_METATYPE(DependencyResolver::DIContainerPtr)
