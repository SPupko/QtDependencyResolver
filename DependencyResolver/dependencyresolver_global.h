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

#ifndef DEPENDENCYRESOLVER_GLOBAL_H
#define DEPENDENCYRESOLVER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DEPENDENCYRESOLVER_LIBRARY)
#  define DEPENDENCYRESOLVERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DEPENDENCYRESOLVERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DEPENDENCYRESOLVER_GLOBAL_H
