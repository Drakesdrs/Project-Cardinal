#pragma once

class Material {
public:
	int type; // 5 for water, 6 for lava
	bool isFlammable;
	bool isNeverBuildable;
	bool isAlwaysDestroyable;
	bool isReplaceable;
	bool isLiquid;  // 0x0008
private:
	char pad2[0x3]; // 0x009
public:
	float translucency;  // 0x00C
	bool isBlockingMotion;
	bool isBlockingPrecipitation;
	bool isSolid;
	bool isSuperHot;
	float color[4];
};

class BlockLegacy {
private:
	char pad_0x0000[0xD8]; //0x0000
public:
	Material* Material; //0x00D8
};

class Block {
private:
	char pad_0x0000[0x10]; //0x0000
public:
	BlockLegacy* BlockLegacy; //0x0010

	Material* getMaterial() {
		using GetMaterial = Material * (__thiscall*)(Block*);
		static GetMaterial _GetMaterial = reinterpret_cast<GetMaterial>(Utils::FindSig("48 83 EC 28 48 8B 41 10 48 85 C0 74 0C 48 8B 80 ? ? ? ? 48 83 C4 28 C3 ? ? ? ? ? CC CC 48 89"));
		return _GetMaterial(this);
	}
};