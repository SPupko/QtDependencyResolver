#include "NativeComplexDomainModel.h"

using namespace QtDependencyResolver_Tests_BLL_Native;

NativeComplexDomainModel::NativeComplexDomainModel(QtDependencyResolver_Tests_DAL::IUsersRepository* usersRepository,
                                                   QtDependencyResolver_Tests_DAL::IRolesRepository* rolesRepository,
                                                   QObject *parent) :
    QtDependencyResolver_Tests_BLL::IComplexDomainModel(parent)
{
    _usersRepository = QtDependencyResolver_Tests_DAL::IUsersRepositoryPtr(usersRepository);
    _rolesRepository = QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr(rolesRepository);
}

NativeComplexDomainModel::~NativeComplexDomainModel()
{
}

QString NativeComplexDomainModel::DoSomeComplexWork() const
{
    QString userName =  _usersRepository->GetUserName(1);
    QString roleName = _rolesRepository->GetRoleName(1);
    QString result = QString("NativeComplexDomainModel::DoSomeComplexWork: ") + userName + roleName;

    return result;
}
