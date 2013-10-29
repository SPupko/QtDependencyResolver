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

#include "../QtDependencyResolver/DIContainer.h"

#include "IUsersService.h"
#include "LocalUsersService.h"
#include "RemoteUsersService.h"

#include "IUsersRepository.h"
#include "InMemoryUsersRepository.h"
#include "MongoUsersRepository.h"

#include "MongoDBContext.h"
#include "Person.h"
#include "Team.h"

using namespace Services;
using namespace Repositories;
using namespace DataObjects;

class DIContainerTest : public QObject
{
    Q_OBJECT
    
public:
    DIContainerTest();
    
private Q_SLOTS:
    void testCase1();
    void testCase2();
    void TestCase3();
};

DIContainerTest::DIContainerTest()
{
}

void DIContainerTest::testCase1()
{
    QtDependencyResolver::DIContainerPtr resolver = QtDependencyResolver::DIContainerPtr(new QtDependencyResolver::DIContainer);
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
    QtDependencyResolver::DIContainerPtr resolver = QtDependencyResolver::DIContainerPtr(new QtDependencyResolver::DIContainer);
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

void DIContainerTest::TestCase3()
{
    QtDependencyResolver::DIContainerPtr resolver = QtDependencyResolver::DIContainerPtr(new QtDependencyResolver::DIContainer);

    PersonPtr p1 = PersonPtr(new Person);
    p1->SetName("Alexander Solovyov");
    // http://vk.com/video1361643_166064387
    // http://frameworksdays.com/event/js-frameworks-day-2013/review/Functional-Reactive-Programming-%26-ClojureScript
    // http://solovyov.net/
    p1->SetPosition("seniorJSDeveloper");
    resolver->Bind(p1->GetPosition(), QVariant::fromValue(p1));

    PersonPtr p2 = PersonPtr(new Person);
    p2->SetName("Maxim Dorofeev");
    // http://www.slideshare.net/Cartmendum/shewhart-6sigma-and-snowflakemen
    p2->SetPosition("ranger");
    resolver->Bind(p2->GetPosition(), QVariant::fromValue(p2));

    TeamPtr team = TeamPtr(resolver->Resolve<Team>());

    if (team.isNull())
    {
        QFAIL("Resolving failure! NULL team from resolver");
    }

    QList<PersonPtr> persons = team->GetPersons();

    if (persons.size() != 2)
    {
        QFAIL("Persons size failure!");
    }
}

QTEST_APPLESS_MAIN(DIContainerTest)

#include "DIContainerTest.moc"
