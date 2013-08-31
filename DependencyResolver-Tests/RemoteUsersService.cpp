#include "RemoteUsersService.h"

using namespace Services::RemoteServices;

RemoteUsersService::RemoteUsersService(QObject *parent) :
    IUsersService(parent)
{
}

RemoteUsersService::~RemoteUsersService()
{
}

QString RemoteUsersService::GetUserName(const quint8 &id)
{
    Q_UNUSED(id);
    return "UserFromRemoteService";
}
