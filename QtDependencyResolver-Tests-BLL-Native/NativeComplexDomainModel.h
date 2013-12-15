#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>


#include "../QtDependencyResolver-Tests-BLL/IComplexDomainModel.h"
#include "../QtDependencyResolver-Tests-DAL/IUsersRepository.h"
#include "../QtDependencyResolver-Tests-DAL/IRolesRepository.h"
#include "qtdependencyresolver-tests-bll-native_global.h"

namespace QtDependencyResolver_Tests_BLL_Native
{
    class QTDEPENDENCYRESOLVERTESTSBLLNATIVESHARED_EXPORT NativeComplexDomainModel :
            public QtDependencyResolver_Tests_BLL::IComplexDomainModel
    {
        Q_OBJECT
    public:
        Q_INVOKABLE explicit NativeComplexDomainModel(QtDependencyResolver_Tests_DAL::IUsersRepository* usersRepository,
                                                      QtDependencyResolver_Tests_DAL::IRolesRepository* rolesRepository,
                                                      QObject *parent = 0);
        virtual ~NativeComplexDomainModel();

        virtual QString DoSomeComplexWork() const;

    private:
        QtDependencyResolver_Tests_DAL::IUsersRepositoryPtr _usersRepository;
        QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr _rolesRepository;
    };

    typedef QSharedPointer<NativeComplexDomainModel> NativeComplexDomainModelPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_BLL_Native::NativeComplexDomainModelPtr)
