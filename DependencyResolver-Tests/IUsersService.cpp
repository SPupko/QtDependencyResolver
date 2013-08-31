#include "IUsersService.h"

using namespace Services;

IUsersService::IUsersService(QObject *parent) :
    QObject(parent)
{
}

IUsersService::~IUsersService()
{
}

QString IUsersService::GetType()
{
    return this->metaObject()->className();
}
