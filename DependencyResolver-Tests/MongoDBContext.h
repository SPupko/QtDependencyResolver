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

namespace Repositories
{
    class MongoDBContext : public QObject
    {
        Q_OBJECT
    public:
        explicit MongoDBContext(QObject *parent = 0);
        virtual ~MongoDBContext();

        QString GetConnectionString();
        void SetConnectionString(const QString &value);

    private:
        QString _connectionString;
    };

    typedef QSharedPointer<MongoDBContext> MongoDBContextPtr;
}

Q_DECLARE_METATYPE(Repositories::MongoDBContextPtr)
