#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

#include "qtdependencyresolver-tests-dal_global.h"

namespace QtDependencyResolver_Tests_DAL
{
    class QTDEPENDENCYRESOLVERTESTSDALSHARED_EXPORT IUsersRepository : public QObject
    {
        Q_OBJECT
    public:
        explicit IUsersRepository(QObject *parent = 0);
        virtual ~IUsersRepository();

        virtual QString GetUserName(const quint8 &userId) const = 0;
    };

    typedef QSharedPointer<IUsersRepository> IUsersRepositoryPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_DAL::IUsersRepositoryPtr)
