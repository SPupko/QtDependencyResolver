# QtDependencyResolver

QtDependencyResolver is a simple, ready-to-use library, that provide you ability to make IoC via DIContainer in your solution.
DIContainer is based on Qt Meta-Object System and use invoke method to make a constructor injection.

You can bind your interfaces and base classes to a concrete implementation and retrieve instances later.

## Usage

To bind your classes you must create a **DIContainer** instance and use the **Bind** method:
    
    DIContainer* resolver = new DIContainer();
    resolver->Bind<IUsersService, LocalUsersService>();
    resolver->Bind<IUsersRepository, MongoDBUsersRepository>();

Then for resolving your interfaces or base classes you must use the **Resolve** method:

    IUserService* userService = resolver->Resolve<IUsersService>();

**Note:** *Only constructors that are declared with the Q_INVOKABLE modifier are made available to be invoked using QMetaObject::invokeMethod() through the meta-object system.
For more details look on DIContainerTest.cpp in DependencyResolver-Tests library.*

## Resources

https://github.com/SPupko/QtDependencyResolver (Git Repository)

https://github.com/SPupko/QtDependencyResolver/issues (Bug Reports)

https://github.com/SPupko/QtDependencyResolver/wiki (Wiki)
  
