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

#include <QString>
#include <QtTest>

#include "../DependencyResolver/DIContainer.h"

#include "IUsersService.h"
#include "LocalUsersService.h"
#include "RemoteUsersService.h"

#include "IUsersRepository.h"
#include "InMemoryUsersRepository.h"
#include "MongoUsersRepository.h"
#include "MongoDBContext.h"

using namespace Services;
using namespace Repositories;

class DIContainerTest : public QObject
{
    Q_OBJECT
    
public:
    DIContainerTest();
    
private Q_SLOTS:
    void testCase1();
    void testCase2();
};

DIContainerTest::DIContainerTest()
{
}

void DIContainerTest::testCase1()
{
    DependencyResolver::DIContainerPtr resolver = DependencyResolver::DIContainerPtr(new DependencyResolver::DIContainer);
    resolver->Bind<IUsersService, RemoteServices::RemoteUsersService>();
    resolver->Bind<IUsersService, LocalServices::LocalUsersService>();
    resolver->Bind<IUsersRepository, InMemoryUsersRepository>();
    resolver->Bind("userName", "Sergey Pupko");

    IUsersServicePtr usersService = IUsersServicePtr(resolver->Resolve<IUsersService>());
    if (usersService.isNull())
    {
        QFAIL("Resolving failure! NULL service from resolver");
    }
    else
    {
        QString actual = usersService->GetType();
        QString expected = "Services::LocalServices::LocalUsersService";
        QString msg("Resolving failure! Expected: " + expected + ", Actual: " + actual);
        QVERIFY2(actual == expected, msg.toUtf8());
    }
}

void DIContainerTest::testCase2()
{
    DependencyResolver::DIContainerPtr resolver = DependencyResolver::DIContainerPtr(new DependencyResolver::DIContainer);
    resolver->Bind<IUsersService, LocalServices::LocalUsersService>();
    resolver->Bind<IUsersRepository, MongoUsersRepository>();

    MongoDBContextPtr mongoContext = MongoDBContextPtr(new MongoDBContext);
    mongoContext->SetConnectionString("mongodb://Username:Password@linus.mongohq.com:xxx");
    resolver->Bind("mongoDBContext", QVariant::fromValue(mongoContext));

    IUsersServicePtr usersService = IUsersServicePtr(resolver->Resolve<IUsersService>());
    if (usersService.isNull())
    {
        QFAIL("Resolving failure! NULL service from resolver");
    }
    else
    {
        QString actual = usersService->GetType();
        QString expected = "Services::LocalServices::LocalUsersService";
        QString msg("Resolving failure! Expected: " + expected + ", Actual: " + actual);
        QVERIFY2(actual == expected, msg.toUtf8());
    }
}

QTEST_APPLESS_MAIN(DIContainerTest)

#include "DIContainerTest.moc"
