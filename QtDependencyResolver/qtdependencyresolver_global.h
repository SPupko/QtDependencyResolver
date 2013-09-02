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

#ifndef QTDEPENDENCYRESOLVER_GLOBAL_H
#define QTDEPENDENCYRESOLVER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTDEPENDENCYRESOLVER_LIBRARY)
#  define QTDEPENDENCYRESOLVERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTDEPENDENCYRESOLVERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTDEPENDENCYRESOLVER_GLOBAL_H
