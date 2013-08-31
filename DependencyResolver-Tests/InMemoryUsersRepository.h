#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>
#include <QMap>

#include "IUsersRepository.h"

namespace Repositories
{
    class InMemoryUsersRepository : public IUsersRepository
    {
        Q_OBJECT
    public:
        Q_INVOKABLE explicit InMemoryUsersRepository(QObject *parent = 0);
        virtual ~InMemoryUsersRepository();

        virtual QString GetUserName(const quint8 &id);

    private:
        QMap<quint8, QString> _storage;
    };

    typedef QSharedPointer<InMemoryUsersRepository> InMemoryUsersRepositoryPtr;
}

Q_DECLARE_METATYPE(Repositories::InMemoryUsersRepositoryPtr)
