#include "NativeUsersDomainModel.h"

using namespace QtDependencyResolver_Tests_BLL_Native;

NativeUsersDomainModel::NativeUsersDomainModel(QtDependencyResolver_Tests_DAL::IUsersRepository* usersRepository, QObject *parent) :
    QtDependencyResolver_Tests_BLL::IUsersDomainModel(parent)
{
    _usersRepository = QtDependencyResolver_Tests_DAL::IUsersRepositoryPtr(usersRepository);
}

NativeUsersDomainModel::~NativeUsersDomainModel()
{
}

QString NativeUsersDomainModel::ProcessUserName(const quint8 &userId) const
{
    QString result = QString("NativeUsersDomainModel::ProcessUserName: ") + _usersRepository->GetUserName(userId);

    return result;
}
