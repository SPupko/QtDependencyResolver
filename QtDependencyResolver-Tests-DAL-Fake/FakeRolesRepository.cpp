#include "FakeRolesRepository.h"

using namespace QtDependencyResolver_Tests_DAL_Fake;

FakeRolesRepository::FakeRolesRepository(QObject *parent) :
    QtDependencyResolver_Tests_DAL::IRolesRepository(parent)
{
    _roles.insert(1, QString("DBA"));
    _roles.insert(2, QString("Developer"));
    _roles.insert(3, QString("QA"));
}

FakeRolesRepository::~FakeRolesRepository()
{
}

QString FakeRolesRepository::GetRoleName(const quint8 &roleId) const
{
    return _roles.contains(roleId)
            ? _roles.value(roleId)
            : QString("Invalid roleId!");
}
