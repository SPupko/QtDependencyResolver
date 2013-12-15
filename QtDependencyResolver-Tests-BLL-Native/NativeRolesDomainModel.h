#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

#include "../QtDependencyResolver-Tests-BLL/IRolesDomainModel.h"
#include "../QtDependencyResolver-Tests-DAL/IRolesRepository.h"
#include "qtdependencyresolver-tests-bll-native_global.h"

namespace QtDependencyResolver_Tests_BLL_Native
{
    class QTDEPENDENCYRESOLVERTESTSBLLNATIVESHARED_EXPORT NativeRolesDomainModel :
            public QtDependencyResolver_Tests_BLL::IRolesDomainModel
    {
        Q_OBJECT
    public:
        Q_INVOKABLE explicit NativeRolesDomainModel(QtDependencyResolver_Tests_DAL::IRolesRepository* rolesRepository, QObject *parent = 0);
        virtual ~NativeRolesDomainModel();

        virtual QString ProcessRoleName(const quint8 &roleId) const;

    private:
        QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr _rolesRepository;
    };

    typedef QSharedPointer<NativeRolesDomainModel> NativeRolesDomainModelPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_BLL_Native::NativeRolesDomainModelPtr)
