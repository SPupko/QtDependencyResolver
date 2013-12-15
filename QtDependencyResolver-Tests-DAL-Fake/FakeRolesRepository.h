#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>
#include <QMap>

#include "../QtDependencyResolver-Tests-DAL/IRolesRepository.h"
#include "qtdependencyresolver-tests-dal-fake_global.h"

namespace  QtDependencyResolver_Tests_DAL_Fake
{
    class QTDEPENDENCYRESOLVERTESTSDALFAKESHARED_EXPORT FakeRolesRepository :
            public QtDependencyResolver_Tests_DAL::IRolesRepository
    {
        Q_OBJECT
    public:
        Q_INVOKABLE explicit FakeRolesRepository(QObject *parent = 0);
        virtual ~FakeRolesRepository();

        virtual QString GetRoleName(const quint8 &roleId) const;

    private:
        QMap<quint8, QString> _roles;
    };

    typedef QSharedPointer<FakeRolesRepository> FakeRolesRepositoryPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_DAL_Fake::FakeRolesRepositoryPtr)
