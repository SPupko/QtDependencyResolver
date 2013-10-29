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

#include "Person.h"

namespace DataObjects
{
    class Team : public QObject
    {
        Q_OBJECT
    public:
        explicit Team(DataObjects::PersonPtr seniorJSDeveloper, DataObjects::PersonPtr ranger, QObject *parent = 0);
        virtual ~Team();

        QList<PersonPtr> GetPersons();
        void SetPersons(QList<PersonPtr> persons);

    private:
        QList<PersonPtr> _persons;
    };

    typedef QSharedPointer<Team> TeamPtr;
}

Q_DECLARE_METATYPE(DataObjects::TeamPtr)
