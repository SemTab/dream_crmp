#pragma once

// RPC
#define RPC_AZS	0x35
#define sendRPC_AZS	0x41

class CAZS
{
public:
	static void Show(int fuelId, int maxFuel, float currentFuel, int price, int balance);
};

