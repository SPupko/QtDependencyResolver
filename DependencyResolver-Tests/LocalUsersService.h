#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedDataPointer>

#include "IUsersService.h"
#include "IUsersRepository.h"

using namespace Repositories;

namespace Services
{
    namespace LocalServices
    {
        class LocalUsersService : public IUsersService
        {
            Q_OBJECT
        public:
            Q_INVOKABLE explicit LocalUsersService(Repositories::IUsersRepository* usersRepositorry, QObject *parent = 0);
            virtual ~LocalUsersService();

            virtual QString GetUserName(const quint8 &id);

        private:
            Repositories::IUsersRepositoryPtr _usersRepository;
        };

        typedef QSharedPointer<LocalUsersService> LocalUsersServicePtr;
    }
}
Q_DECLARE_METATYPE(Services::LocalServices::LocalUsersServicePtr)
