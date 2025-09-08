#include "pch.h"

#include <cstddef>
#include <iostream>

class Avril_FSD::Server* ptr_HostServer = NULL;

Avril_FSD::Framework_Server::Framework_Server()
{
	std::cout << "entered => Framework_Server::Framework_Server()" << std::endl;

	Set_Server_Assembly(new class Avril_FSD::Server());
	while (Get_Server_Assembly() == NULL) { /* wait untill created */ }
	std::cout << "Created => Created Server Assembly" << std::endl;

	Get_Server_Assembly()->Get_Execute()->Initialise_Libraries();
	std::cout << "Created => INIT Libraries" << std::endl;
}


Avril_FSD::Framework_Server::~Framework_Server()
{
	delete ptr_HostServer;
}

void Avril_FSD::Framework_Server::Initialise_Program(class Avril_FSD::Framework_Server* obj)
{
	obj->Get_Server_Assembly()->Get_Execute()->Initialise(obj);
	std::cout << "Created => INIT Server" << std::endl;
	

	obj->Get_Server_Assembly()->Get_Data()->Initialise_GameInstance();
	std::cout << "Created => Game Instance" << std::endl;

	obj->Get_Server_Assembly()->Get_Execute()->Initialise_Threads(obj);
	std::cout << "Created => Thread(s)" << std::endl;
}

class Avril_FSD::Server* Avril_FSD::Framework_Server::Get_Server_Assembly()
{
	return ptr_HostServer;
}

void Avril_FSD::Framework_Server::Set_Server_Assembly(Server* server)
{
	ptr_HostServer = server;
}
