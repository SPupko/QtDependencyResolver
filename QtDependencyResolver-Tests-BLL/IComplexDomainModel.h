#pragma once

#include <QObject>
#include <QMetaType>
#include <QSharedPointer>

#include "qtdependencyresolver-tests-bll_global.h"

namespace QtDependencyResolver_Tests_BLL
{
    class QTDEPENDENCYRESOLVERTESTSBLLSHARED_EXPORT IComplexDomainModel : public QObject
    {
        Q_OBJECT
    public:
        explicit IComplexDomainModel(QObject *parent = 0);
        virtual ~IComplexDomainModel();

        virtual QString DoSomeComplexWork() const = 0;
    };

    typedef QSharedPointer<IComplexDomainModel> IComplexDomainModelPtr;
}

Q_DECLARE_METATYPE(QtDependencyResolver_Tests_BLL::IComplexDomainModelPtr)
