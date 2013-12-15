#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

#include "../QtDependencyResolver-Tests-BLL/IUsersDomainModel.h"
#include "../QtDependencyResolver-Tests-DAL/IUsersRepository.h"
#include "qtdependencyresolver-tests-bll-native_global.h"

namespace QtDependencyResolver_Tests_BLL_Native
{
    class QTDEPENDENCYRESOLVERTESTSBLLNATIVESHARED_EXPORT NativeUsersDomainModel :
            public QtDependencyResolver_Tests_BLL::IUsersDomainModel
    {
        Q_OBJECT
    public:
        Q_INVOKABLE explicit NativeUsersDomainModel(QtDependencyResolver_Tests_DAL::IUsersRepository* usersRepository, QObject *parent = 0);
        virtual ~NativeUsersDomainModel();

        virtual QString ProcessUserName(const quint8 &userId) const;

    private:
        QtDependencyResolver_Tests_DAL::IUsersRepositoryPtr _usersRepository;
    };

    typedef QSharedPointer<NativeUsersDomainModel> NativeUsersDomainModelPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_BLL_Native::NativeUsersDomainModelPtr)
