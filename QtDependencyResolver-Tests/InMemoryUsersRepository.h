/****************************************************************************
* Copyright (C) 2013 Sergey Pupko <s.d.pupko@gmail.com>
*
* This library is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

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
        Q_INVOKABLE explicit InMemoryUsersRepository(const QString &userName, QObject *parent = 0);
        virtual ~InMemoryUsersRepository();

        Q_INVOKABLE virtual QString GetUserName(const quint8 &id);

    private:
        QString _userName;
        QMap<quint8, QString> _storage;
    };

    typedef QSharedPointer<InMemoryUsersRepository> InMemoryUsersRepositoryPtr;
}

Q_DECLARE_METATYPE(Repositories::InMemoryUsersRepositoryPtr)
