#include "IUsersRepository.h"

using namespace Repositories;

IUsersRepository::IUsersRepository(QObject *parent) :
    QObject(parent)
{
}

IUsersRepository::~IUsersRepository()
{
}

QString IUsersRepository::GetType()
{
    return this->metaObject()->className();
}
