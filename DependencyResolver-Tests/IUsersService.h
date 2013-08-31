#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

namespace Services
{
    class IUsersService : public QObject
    {
        Q_OBJECT
    public:
        explicit IUsersService(QObject *parent = 0);
        virtual ~IUsersService();

        QString GetType();

        virtual QString GetUserName(const quint8 &id) = 0;
    };

    typedef QSharedPointer<IUsersService> IUsersServicePtr;
}

Q_DECLARE_METATYPE(Services::IUsersServicePtr)
