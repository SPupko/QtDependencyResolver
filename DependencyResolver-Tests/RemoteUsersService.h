#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedDataPointer>

#include "IUsersService.h"

namespace Services
{
    namespace RemoteServices
    {
        class RemoteUsersService : public IUsersService
        {
            Q_OBJECT
        public:
            Q_INVOKABLE explicit RemoteUsersService(QObject *parent = 0);
            virtual ~RemoteUsersService();

            virtual QString GetUserName(const quint8 &id);
        };

        typedef QSharedPointer<RemoteUsersService> RemoteUsersServicePtr;
    }
}

Q_DECLARE_METATYPE(Services::RemoteServices::RemoteUsersServicePtr)
