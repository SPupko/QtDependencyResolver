#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>
#include <QMap>

#include "../QtDependencyResolver-Tests-DAL/IUsersRepository.h"
#include "qtdependencyresolver-tests-dal-fake_global.h"

namespace  QtDependencyResolver_Tests_DAL_Fake
{
    class QTDEPENDENCYRESOLVERTESTSDALFAKESHARED_EXPORT FakeUsersRepository :
            public QtDependencyResolver_Tests_DAL::IUsersRepository
    {
        Q_OBJECT
    public:
        Q_INVOKABLE explicit FakeUsersRepository(QObject *parent = 0);
        virtual ~FakeUsersRepository();

        virtual QString GetUserName(const quint8 &userId) const;

    private:
        QMap<quint8, QString> _users;
    };

    typedef QSharedPointer<FakeUsersRepository> FakeUsersRepositoryPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_DAL_Fake::FakeUsersRepositoryPtr)
