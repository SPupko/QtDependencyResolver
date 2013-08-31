#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

namespace Repositories
{
    class IUsersRepository : public QObject
    {
        Q_OBJECT
    public:
        explicit IUsersRepository(QObject *parent = 0);
        virtual ~IUsersRepository();

        QString GetType();

        virtual QString GetUserName(const quint8 &id) = 0;
    };

    typedef QSharedPointer<IUsersRepository> IUsersRepositoryPtr;
}

Q_DECLARE_METATYPE(Repositories::IUsersRepositoryPtr)
