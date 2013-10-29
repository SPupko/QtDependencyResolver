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

#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>
#include <QVariant>

#include "qtdependencyresolver_global.h"

namespace QtDependencyResolver
{
    class QTDEPENDENCYRESOLVERSHARED_EXPORT DIContainer : public QObject
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
            Register(QString(typeid(ResolvableType).name()), static_cast<Type*>(0)->staticMetaObject);
        }

        void Bind(const QString &key, const QVariant &value)
        {
            Register(value.typeName(), key, value);
        }

        template <typename ResolvableType>
        ResolvableType* Resolve()
        {
            return qobject_cast<ResolvableType*>(ResolveByName(QString(typeid(ResolvableType).name())));
        }

        QObject* ResolveByName(QString typeName);

    private:
        void Register(const QString &typeName, const QMetaObject &metaObject);
        void Register(const QString &typeName, const QString &key, const QVariant &value);

    private:
        class P; QSharedPointer<P> _d;
    };

    typedef QSharedPointer<DIContainer> DIContainerPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver::DIContainerPtr)
