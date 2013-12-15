#include "NativeRolesDomainModel.h"

using namespace QtDependencyResolver_Tests_BLL_Native;

NativeRolesDomainModel::NativeRolesDomainModel(QtDependencyResolver_Tests_DAL::IRolesRepository* rolesRepository, QObject *parent) :
    QtDependencyResolver_Tests_BLL::IRolesDomainModel(parent)
{
    _rolesRepository = QtDependencyResolver_Tests_DAL::IRolesRepositoryPtr(rolesRepository);
}

NativeRolesDomainModel::~NativeRolesDomainModel()
{
}

QString NativeRolesDomainModel::ProcessRoleName(const quint8 &roleId) const
{
    QString result = QString("NativeRoleDomainModel::ProcessRoleName: ") + _rolesRepository->GetRoleName(roleId);

    return result;
}
