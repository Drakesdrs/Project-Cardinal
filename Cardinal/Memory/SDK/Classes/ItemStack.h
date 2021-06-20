#pragma once

class Actor;
class Player;
class Block;
class BlockSource;
class Level;
class TextHolder;

class ItemStack {
private:
	uintptr_t** VTable;
public:
	class Item** item;

	int getId() {
		using GetId = int(__thiscall*)(ItemStack*);
		static GetId _GetId = reinterpret_cast<GetId>(Utils::FindSig("80 79 23 00 75 06 B8 ? ? ? ? C3"));
		return _GetId(this);
	}

	int getMaxStackSize() {
		using GetMaxStackSize = int(__thiscall*)(ItemStack*);
		static GetMaxStackSize _GetMaxStackSize = reinterpret_cast<GetMaxStackSize>(Utils::FindSig("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 70 33 FF 89 BC 24 ? ? ? ? 48 8B 41 08 48 85 C0"));
		return _GetMaxStackSize(this);
	}

	class Item* getItem() {
		using GetItem = Item * (__thiscall*)(ItemStack*);
		static GetItem _GetItem = reinterpret_cast<GetItem>(Utils::FindSig("48 8B 41 08 48 85 C0 74 04 48 8B 00 C3"));
		return _GetItem(this);
	}
};

class Item {
private:
	virtual ~Item();
public:
	virtual void initServer(__int64 /*Json::Value&*/);
private:
	virtual void Function2();
public:
	virtual __int64 getMaxUseDuration(__int64 ItemInstance);
	virtual __int64 getMaxUseDurationB(__int64 ItemInstance);
private:
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
public:
	virtual bool isCamera(void);
	virtual bool isDamageable(void);
private:
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
public:
	virtual bool isFood(void);
private:
	virtual void Function18();
	virtual void Function19();
public:
	virtual __int64 getCamera(void);
	virtual __int64 getFood(void);
private:
	virtual void Function22();
public:
	virtual void setMaxStackSize(UCHAR);
	virtual void setStackedByData(bool);
	virtual void setMaxDamage(int);
	virtual void setHandEquipped(void);
	virtual void setUseAnimation(__int64 UseAnimation);
	virtual void setMaxUseDuration(int);
	virtual void setRequiresWorldBuilder(bool);
	virtual void setExplodable(bool);
	virtual void setFireResistant(bool);
	virtual void setIsGlint(bool);
	virtual void setShouldDespawn(bool);
	virtual __int64 getResourceCount(__int64 Random, Block*, int, bool);
	virtual bool canBeDepleted(void);
private:
	virtual void Function36();
	virtual void Function37();
public:
	virtual bool isStackedByData(void);
	virtual __int16 getMaxDamage(void);
private:
	virtual void Function40();
public:
	virtual bool isHandEquipped(void);
private:
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
	virtual void Function50();
	virtual void Function51();
public:
	virtual void appendFormattedHovertext(__int64 ItemStackBase, Level*, TextHolder*, bool);
private:
	virtual void Function53();
	virtual void Function54();
	virtual void Function55();
	virtual void Function56();
	virtual void Function57();
	virtual void Function58();
private:
	virtual __int64 getDamageChance(int);
private:
	virtual void Function60();
	virtual void Function61();
	virtual void Function62();
	virtual void Function63();
public:
	virtual __int64 getDustColor(Block*);
private:
	virtual void Function65();
	virtual void Function66();
	virtual void Function67();
	virtual void Function68();
	virtual void Function69();
	virtual void Function70();
	virtual void Function71();
public:
	virtual __int64 getActorIdentifier(ItemStack*);
private:
	virtual void Function73();
	virtual void Function74();
public:
	virtual void buildIdAux(short, __int64 CompoundTag);
	virtual void use(ItemStack*, Player*);
	virtual void dispense(BlockSource*, __int64 Container, int, Vec3*, UCHAR);
	virtual void seTimeDepleted(ItemStack*, Level*, Player*);
	virtual void releaseUsing(ItemStack*, Player*, int);
private:
	virtual void Function80();
public:
	virtual void hurtActor(ItemStack*, Actor*, __int64 Mob);
private:
	virtual void Function82();
	virtual void Function83();
public:
	virtual void mineBlock(__int64 ItemInstance, Block*, int, int, int, Actor*);
	virtual void mineBlockB(__int64 ItemInstance, Block*, int, int, int, Actor*);
	virtual void buildDescriptionName(__int64 ItemStackBase);
	virtual void buildDescriptionId(__int64 ItemDescriptor, __int64 CompoundTag);
	virtual void buildEffectDescriptionName(__int64 ItemStackBase);
	virtual void buildCategoryDescriptionName(void);
	virtual void readUserData(__int64 ItemStackBase, __int64 IDataInput, __int64 ReadOnlyBinaryStream);
	virtual void writeUserData(__int64 ItemStackBase, __int64 IDataOutput);
	virtual unsigned __int8 getMaxStackSize(__int64 ItemDescriptor);
private:
	virtual void Function93();
	virtual void Function94();
public:
	virtual TextHolder* getCooldownType(void);
	virtual __int64 getCooldownTime(void);
	virtual void fixupCommon(__int64 ItemStackBase, Level*);
	virtual void fixupCommon(__int64 ItemStackBase);
	virtual __int64 getDamageValue(__int64 CompoundTag);
	virtual void setDamageValue(__int64 ItemStackBase);
	virtual int getInHandUpdateType(Player*, ItemStack*, ItemStack*, bool, bool);
	virtual int getInHandUpdateTypeB(Player*, ItemStack*, ItemStack*, bool, bool);
private:
	virtual void Function102();
public:
	virtual bool isSameItem(__int64 ItemStackBase, __int64 ItemStackBaseB);
	virtual void initClient(__int64 Json);
	virtual TextHolder* getInteractText(Player*);
private:
	virtual void Function106();
public:
	virtual bool isEmissive(int);
	virtual __int64 getLightEmission(int);
	virtual __int64 getIcon(__int64 ItemStackBase, int, bool);
private:
	virtual void Function110();
public:
	virtual void setIcon(__int64 TextureUVCoordinateSet);
	virtual void setIcon(TextHolder*);
	virtual void setIconAtlas(TextHolder*);
private:
	virtual void Function114();
	virtual void Function115();
	virtual void Function116();
public:
	virtual float getFurnaceBurnIntervalMultipler(__int64 ItemStackBase);
	virtual float getFurnaceXPmultiplier(__int64 ItemStackBase);
	virtual TextHolder* getAuxValuesDescription(void);
	virtual void _checkUseOnPermissions(Actor*, __int64 ItemStackBase, UCHAR const&, Vec3i*);
private:
	virtual void Function121();
public:
	virtual void _useOn(ItemStack*, Actor*, Vec3i*, UCHAR, float, float, float);
public:
	int16_t getId() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("0F B7 41 ? C3 33 C0 C3") + 3);
		return *reinterpret_cast<int16_t*>((uintptr_t)(this) + offset);
	}
};