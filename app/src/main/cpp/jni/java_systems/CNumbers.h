#pragma once

// RPC
#define RPC_NUM  0x41
#define RPC_NUM_GENERATE  0x42
#define RPC_NUM_BUY  0x43
#define sendRPC_NUM	0x42

class CNumbers
{
public:
	static void Show(int balance);
    static void GenerateNumber(bool status);
    static void BuyNumber(bool status);
};

