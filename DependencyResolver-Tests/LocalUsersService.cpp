#include "LocalUsersService.h"

using namespace Services::LocalServices;

LocalUsersService::LocalUsersService(Repositories::IUsersRepository* usersRepositorry, QObject *parent) :
    IUsersService(parent),
    _usersRepository(Repositories::IUsersRepositoryPtr(usersRepositorry))
{
}

LocalUsersService::~LocalUsersService()
{
}

QString LocalUsersService::GetUserName(const quint8 &id)
{
    return _usersRepository->GetUserName(id);
}
