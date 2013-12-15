#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

#include "qtdependencyresolver-tests-bll_global.h"

namespace QtDependencyResolver_Tests_BLL
{
    class QTDEPENDENCYRESOLVERTESTSBLLSHARED_EXPORT IRolesDomainModel : public QObject
    {
        Q_OBJECT
    public:
        explicit IRolesDomainModel(QObject *parent = 0);
        virtual ~IRolesDomainModel();

        virtual QString ProcessRoleName(const quint8 &roleId) const = 0;
    };

    typedef QSharedPointer<IRolesDomainModel> IRolesDomainModelPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_BLL::IRolesDomainModelPtr)
