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


#include "../QtDependencyResolver-Tests-DAL/IUsersRepository.h"
#include "../QtDependencyResolver-Tests-DAL/IRolesRepository.h"

#include "../QtDependencyResolver-Tests-DAL-Fake/FakeUsersRepository.h"
#include "../QtDependencyResolver-Tests-DAL-Fake/FakeRolesRepository.h"

#include "../QtDependencyResolver-Tests-BLL/IUsersDomainModel.h"
#include "../QtDependencyResolver-Tests-BLL/IRolesDomainModel.h"
#include "../QtDependencyResolver-Tests-BLL/IComplexDomainModel.h"

#include "../QtDependencyResolver-Tests-BLL-Native/NativeUsersDomainModel.h"
#include "../QtDependencyResolver-Tests-BLL-Native/NativeRolesDomainModel.h"
#include "../QtDependencyResolver-Tests-BLL-Native/NativeComplexDomainModel.h"

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
    void TestCase4();
    void TestCase5();
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

    resolver->Bind<Team>();

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

void DIContainerTest::TestCase4()
{
    QtDependencyResolver::DIContainerPtr resolver = QtDependencyResolver::DIContainerPtr(new QtDependencyResolver::DIContainer);
    resolver->Bind<QtDependencyResolver_Tests_BLL::IRolesDomainModel, QtDependencyResolver_Tests_BLL_Native::NativeRolesDomainModel>();
    resolver->Bind<QtDependencyResolver_Tests_DAL::IRolesRepository, QtDependencyResolver_Tests_DAL_Fake::FakeRolesRepository>();

    QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr rolesRepository =
            QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr(
                resolver->Resolve<QtDependencyResolver_Tests_DAL::IRolesRepository>());

    QString roleName = rolesRepository->GetRoleName(1);
    QString expectedProcessResult = QString("NativeRoleDomainModel::ProcessRoleName: ") + roleName;

    QtDependencyResolver_Tests_BLL::IRolesDomainModelPtr rolesDomainModel =
            QtDependencyResolver_Tests_BLL::IRolesDomainModelPtr(
                resolver->Resolve<QtDependencyResolver_Tests_BLL::IRolesDomainModel>());

    QString actualProcessResult = rolesDomainModel->ProcessRoleName(1);
    QVERIFY2(actualProcessResult == expectedProcessResult, "Invalid result from rolesDomainModel.ProcessRoleName()");
}

void DIContainerTest::TestCase5()
{
    QtDependencyResolver::DIContainerPtr resolver(new QtDependencyResolver::DIContainer);
    resolver->Bind<QtDependencyResolver_Tests_DAL::IUsersRepository, QtDependencyResolver_Tests_DAL_Fake::FakeUsersRepository>();
    resolver->Bind<QtDependencyResolver_Tests_DAL::IRolesRepository, QtDependencyResolver_Tests_DAL_Fake::FakeRolesRepository>();

    resolver->Bind<QtDependencyResolver_Tests_BLL::IUsersDomainModel, QtDependencyResolver_Tests_BLL_Native::NativeUsersDomainModel>();
    resolver->Bind<QtDependencyResolver_Tests_BLL::IRolesDomainModel, QtDependencyResolver_Tests_BLL_Native::NativeRolesDomainModel>();
    resolver->Bind<QtDependencyResolver_Tests_BLL::IComplexDomainModel, QtDependencyResolver_Tests_BLL_Native::NativeComplexDomainModel>();

    QtDependencyResolver_Tests_DAL::IUsersRepositoryPtr usersRepository(resolver->Resolve<QtDependencyResolver_Tests_DAL::IUsersRepository>());
    QString userName = usersRepository->GetUserName(1);
    QString expectedUserProcessResult = QString("NativeUsersDomainModel::ProcessUserName: ") + userName;
    QtDependencyResolver_Tests_BLL::IUsersDomainModelPtr usersDomainModel(resolver->Resolve<QtDependencyResolver_Tests_BLL::IUsersDomainModel>());
    QString actualUserProcessResult = usersDomainModel->ProcessUserName(1);
    QVERIFY2(actualUserProcessResult == expectedUserProcessResult, "Invalid result from usersDomainModel.ProcessUserName()");

    QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr rolesRepository(resolver->Resolve<QtDependencyResolver_Tests_DAL::IRolesRepository>());
    QString roleName = rolesRepository->GetRoleName(1);
    QString expectedRoleProcessResult = QString("NativeRoleDomainModel::ProcessRoleName: ") + roleName;
    QtDependencyResolver_Tests_BLL::IRolesDomainModelPtr rolesDomainModel(resolver->Resolve<QtDependencyResolver_Tests_BLL::IRolesDomainModel>());
    QString actualRoleProcessResult = rolesDomainModel->ProcessRoleName(1);
    QVERIFY2(actualRoleProcessResult == expectedRoleProcessResult, "Invalid result from rolesDomainModel.ProcessRoleName()");

    QString expectedComplexProcessResult = QString("NativeComplexDomainModel::DoSomeComplexWork: ") + userName + roleName;
    QtDependencyResolver_Tests_BLL::IComplexDomainModelPtr complexDomainModel(resolver->Resolve<QtDependencyResolver_Tests_BLL::IComplexDomainModel>());
    QString actualComplexProcessResult = complexDomainModel->DoSomeComplexWork();
    QVERIFY2(actualComplexProcessResult == expectedComplexProcessResult, "Invalid result from complexDomainModel.ProcessRoleName()");
}

QTEST_APPLESS_MAIN(DIContainerTest)

#include "DIContainerTest.moc"
