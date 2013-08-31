#include <QString>
#include <QtTest>

#include "../DependencyResolver/DIContainer.h"

#include "IUsersService.h"
#include "LocalUsersService.h"
#include "RemoteUsersService.h"

#include "IUsersRepository.h"
#include "InMemoryUsersRepository.h"

using namespace Services;
using namespace Repositories;

class DIContainerTest : public QObject
{
    Q_OBJECT
    
public:
    DIContainerTest();
    
private Q_SLOTS:
    void testCase1();
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
