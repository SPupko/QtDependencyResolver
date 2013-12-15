#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

#include "qtdependencyresolver-tests-dal_global.h"

namespace QtDependencyResolver_Tests_DAL
{
    class QTDEPENDENCYRESOLVERTESTSDALSHARED_EXPORT IRolesRepository : public QObject
    {
        Q_OBJECT
    public:
        explicit IRolesRepository(QObject *parent = 0);
        virtual ~IRolesRepository();

        virtual QString GetRoleName(const quint8 &roleId) const = 0;
    };

    typedef QSharedPointer<IRolesRepository> IRolesRepositoryPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr)
