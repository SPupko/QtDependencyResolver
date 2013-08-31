#include "InMemoryUsersRepository.h"

using namespace Repositories;

InMemoryUsersRepository::InMemoryUsersRepository(QObject *parent) :
    IUsersRepository(parent)
{
    _storage.insert(1, "Andrew Erlichson");
    _storage.insert(2, "Dwight Merriman");
    _storage.insert(3, "Martin Fowler");
}

InMemoryUsersRepository::~InMemoryUsersRepository()
{
}

QString InMemoryUsersRepository::GetUserName(const quint8 &id)
{
    return _storage.contains(id)
            ? _storage.value(id)
            : "Void";
}
