#include "pch.h"

#include <cstddef>
#include <iostream>

class Avril_FSD::Server* ptr_HostServer = NULL;

Avril_FSD::Framework_Server::Framework_Server()
{
	std::cout << "entered => Framework_Server::Framework_Server()" << std::endl;

	Set_Server_Assembly(new class Avril_FSD::Server());
	while (Get_Server_Assembly() == NULL) { /* wait untill created */ }
	std::cout << "Created => Avril_FSD::Server()" << std::endl;
	Get_Server_Assembly()->Get_Execute()->Initialise();

	Get_Server_Assembly()->Get_Data()->Initialise_GameInstance();

	Get_Server_Assembly()->Get_Execute()->Initialise_Threads();
}

Avril_FSD::Framework_Server::~Framework_Server()
{
	delete ptr_HostServer;
}

class Avril_FSD::Server* Avril_FSD::Framework_Server::Get_Server_Assembly()
{
	return ptr_HostServer;
}

void Avril_FSD::Framework_Server::Set_Server_Assembly(Server* server)
{
	ptr_HostServer = server;
}
