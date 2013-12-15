#include "FakeUsersRepository.h"

using namespace QtDependencyResolver_Tests_DAL_Fake;

FakeUsersRepository::FakeUsersRepository(QObject *parent) :
    QtDependencyResolver_Tests_DAL::IUsersRepository(parent)
{
    _users.insert(1, QString("Ivanov"));
    _users.insert(2, QString("Petrov"));
    _users.insert(3, QString("Fedorov"));
}

FakeUsersRepository::~FakeUsersRepository()
{
}

QString FakeUsersRepository::GetUserName(const quint8 &userId) const
{
    return _users.contains(userId)
            ? _users.value(userId)
            : QString("Invalid userId!");
}
