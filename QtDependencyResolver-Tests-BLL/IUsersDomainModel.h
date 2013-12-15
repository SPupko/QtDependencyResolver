#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

#include "qtdependencyresolver-tests-bll_global.h"

namespace QtDependencyResolver_Tests_BLL
{
    class QTDEPENDENCYRESOLVERTESTSBLLSHARED_EXPORT IUsersDomainModel : public QObject
    {
        Q_OBJECT
    public:
        explicit IUsersDomainModel(QObject *parent = 0);
        virtual ~IUsersDomainModel();

        virtual QString ProcessUserName(const quint8 &userId) const = 0;
    };

    typedef QSharedPointer<IUsersDomainModel> IUsersDomainModelPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_BLL::IUsersDomainModelPtr)
