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

#include "Team.h"

using namespace DataObjects;

Team::Team(PersonPtr seniorJSDeveloper, PersonPtr ranger, QObject *parent) :
    QObject(parent)
{
    _persons
            << seniorJSDeveloper
            << ranger;
}

Team::~Team()
{
}

QList<PersonPtr> Team::GetPersons()
{
    return _persons;
}

void Team::SetPersons(QList<PersonPtr> persons)
{
    _persons = persons;
}
