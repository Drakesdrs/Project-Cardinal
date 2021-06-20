#pragma once
#include "Actor.h"

#include "Dimension.h"
#include "Packet.h"

class Player : public Actor {
public:
	void setFieldOfView(float v) {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("F3 0F 59 B3 ? ? ? ? 0F") + 4);
		*(float*)((uintptr_t)(this) + offset) = v;
	}

	void printToChat(std::string message) {
		TextHolder t(message);
		this->displayTextObjectMessage(&t);
	}
	/*__int64 getRuntimeId() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 87 ? ? ? ? C7 45 EF ? ? ? ?") + 3);
		return *reinterpret_cast<__int64*>((uintptr_t)(this) + offset);
	}*/
public:
	virtual void knockback(Actor*, int, float, float, float, float, float);
	virtual void resolveDeathLoot(int, __int64 ActorDamageSource);
private:
	virtual void Function370();
public:
	virtual void setSleeping(bool);
	virtual void setSprinting(bool);
	virtual void playAmbientSound(void);
	virtual __int64 getAmbientSound(void);
	virtual __int64 getHurtSound(void);
	virtual __int64 getDeathSound(void);
	virtual __int64 getAmbientSoundPostponeTicks(void);
	virtual __int64 getAmbientSoundPostponeTicksRange(void);
	virtual __int64 getItemInHandIcon(ItemStack*, int);
	virtual float getSpeed(void);
	virtual void setSpeed(float);
	virtual float getJumpPower(void);
	virtual __int64 hurtEffects(__int64 ActorDamageSource, int, bool, bool);
	virtual __int64 getMeleeWeaponDamageBonus(Actor*);
	virtual __int64 getMeleeKnockbackBonus(void);
	virtual void travel(__int64* IMobMovementProxy, float, float, float);
	virtual void travel(float, float, float);
	virtual void applyFinalFriction(float, bool);
	virtual void updateWalkAnim(void);
	virtual void aiStep(__int64 IMobMovementProxy);
	virtual void aiStep(void);
	virtual void pushActors(void);
	virtual void lookAt(Actor*, float, float);
	virtual bool isLookingAtAnEntity(void);
	virtual bool checkSpawnRules(bool);
	virtual bool checkSpawnObstruction(void);
	virtual float getAttackAnim(float);
	virtual __int64 getItemUseDuration(void);
	virtual float getItemUseStartupProgress(void);
	virtual float getItemUseIntervalProgress(void);
	virtual __int64 getItemuseIntervalAxis(void);
	virtual __int64 getTimeAlongSwing(void);
private:
	virtual void Function403();
public:
	virtual float getMaxHeadXRot(void);
	virtual Actor* getLastHurtByMob(void);
	virtual void setLastHurtByMob(Actor*);
	virtual Actor* getLastHurtByPlayer(void);
	virtual void setLastHurtByPlayer(Player*);
	virtual Actor* getLastHurtMob(void);
	virtual void setLastHurtMob(Actor*);
private:
	virtual void Function411();
public:
	virtual void doHurtTarget(Actor*);
private:
	virtual void Function413();
public:
	virtual void leaveCaravan(void);
	virtual void joinCaravan(Actor*);
	virtual bool hasCaravanTail(void);
	virtual Actor* getCaravanHead(void);
	virtual __int64 getArmorValue(void);
	virtual __int64 getArmorCoverPercentage(void);
	virtual void hurtArmor(__int64 ActorDamageSource, int, std::bitset<4> const&);
	virtual void hurtArmor(__int64 ActorDamageSource, int);
	virtual void hurtArmorSlot(__int64 ActorDamageSource, int, int ArmorSlot);
	virtual void setDamagedArmor(int ArmorSlot, ItemStack*);
	virtual void sendArmorDamage(std::bitset<4> const&);
	virtual void sendArmor(std::bitset<4> const&);
	virtual bool containerChanged(int);
	virtual void updateEquipment(void);
	virtual void clearEquipment(void);
	virtual std::vector<ItemStack*> getAllArmor(void);
	virtual __int64 getAllArmorID(void);
	virtual ItemStack* getAllHand(void);
	virtual std::vector<ItemStack*> getAllEquipment(void);
	virtual __int64 getArmorTypeHash(void);
	virtual void dropEquipmentOnDeath(void);
	virtual void dropEquipmentOnDeath(__int64 ActorDamageSource, int);
	virtual void clearVanishEnchantedItemsOnDeath(void);
	virtual void sendInventory(bool);
	virtual void getDamageAfterMagicAbsorb(__int64 ActorDamageSource, int);
	virtual void createAIGoals(void);
private:
	virtual void Function440();
public:
	virtual void setItemSlot(int EquipmentSlot, ItemStack*);
	virtual void setTransitioningSitting(bool);
	virtual void attackAnimation(Actor*, float);
private:
	virtual void Function444();
	virtual void Function445();
	virtual void Function446();
public:
	virtual void ascendLadder(void);
	virtual void ascendScaffolding(void);
	virtual void _ascendScaffolding(void);
	virtual void descendScaffolding(void);
	virtual bool canAscendCurrentBlockByJumping(void);
	virtual void dropContainer(void);
	virtual void initBodyControl(void);
	virtual void jumpFromGround(__int64* IMobMovementProxy);
	virtual void jumpFromGround(void);
private:
	virtual void Function456();
public:
	virtual void newServerAiStep(void);
private:
	virtual void Function448();
public:
	virtual __int64 getDamageAfterEnchantReduction(__int64 ActorDamageSource, int);
	virtual __int64 getDamageAfterArmorAbsorb(__int64 ActorDamageSource, int);
	virtual void dropBags(void);
	virtual void tickDeath(void);
	virtual void updateGliding(void);
private:
	virtual void Function454();
public:
	virtual void prepareRegion(ChunkSource*);
	virtual void destroyRegion(void);
	virtual void suspendRegion(void);
	virtual void resendAllChunks(void);
	virtual void _fireWillChangeDimension(void);
	virtual void _fireDimensionChanged(void);
	virtual void changeDimensionWithCredits(int);
	virtual void tickWorld(__int64 Tick);
private:
	virtual void Function463();
public:
	virtual std::vector<__int64, __int64> getTickingOffsets(void);
	virtual void moveView(void);
	virtual void setName(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void checkMovementStats(Vec3*);
private:
	virtual void Function468();
	virtual void Function469();
public:
	virtual void respawn(void);
private:
	virtual void Function471();
public:
	virtual void resetPos(bool);
private:
	virtual void Function473();
public:
	virtual bool hasResource(int);
	virtual void completeUsingItem(void);
	virtual void setPermissions(int CommandPermissionLevel);
	virtual void startDestroying(void);
	virtual void stopDestroying(void);
private:
	virtual void Function479();
	virtual void Function480();
public:
	virtual void openTrading(__int64 ActorUniqueID, bool);
	virtual bool canOpenContainerScreen(void);
private:
	virtual void Function483();
	virtual void Function484();
public:
	virtual void openInventory(void);
private:
	virtual void Function486();
	virtual void Function487();
public:
	virtual void displayTextObjectMessage(TextHolder*);
	virtual void displayTextObjectWhisperMessage(TextHolder*);
	virtual void displayWhisperMessage(TextHolder*);
	virtual void startSleepInBed(Vec3i*);
	virtual void stopSleepInBed(bool, bool);
	virtual bool canStartSleepInBed(void);
	virtual __int64 getSleepTimer(void);
	virtual __int64 getPreviousTickSleepTimer(void);
private:
	virtual void Function496();
	virtual void Function497();
public:
	virtual bool isHostingPlayer(void);
	virtual bool isLoading(void);
	virtual bool isPlayerInitialized(void);
private:
	virtual void Function501();
public:
	virtual void registerTrackedBoss(__int64 ActorUniqueID);
	virtual void unRegisterTrackedBoss(__int64 ActorUniqueID);
	virtual void setPlayerGameType(int GameType);
	virtual void initHUDContainerManager(void);
	virtual void _crit(Actor*);
	virtual __int64 getEventing(void);
private:
	virtual void Function508();
public:
	virtual void sendEventPacket(Packet* EventPacket);
	virtual void addExperience(int);
	virtual void addLevels(int);
	virtual void setContainerData(__int64 IContainerManager, int, int);
	virtual void slotChanged(__int64 IContainerManager, __int64 Container, int, ItemStack*, ItemStack*, bool);
	virtual void inventoryChanged(__int64 Container, int, ItemStack*, ItemStack*, bool);
	virtual void refreshContainer(__int64 IContainerManager);
	virtual void deleteContainerManager(void);
	virtual void setFieldOfViewModifier(float);
	virtual bool is2DPositionRelevant(int Dimension, Vec3i* BlockPos);
	virtual bool isEntityRelevant(Actor*);
	virtual bool isTeacher(void);
	virtual void onSuspension(void);
	virtual void onLinkedSlotsChanged(void);
	virtual void startCooldown(Item*);
	virtual int getItemCooldownLeft(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual bool isItemInCooldown(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void endInventoryTransaction(__int64 InventoryTransaction);
	virtual void sendComplexInventoryTransaction(std::unique_ptr<__int64 /*ComplexInventoryTransaction*/, std::default_delete<__int64 /*ComplexInventoryTransaction*/>>);
	virtual void sendNetworkPacket(Packet*);
	virtual __int64 getPlayerEventCoordinator(void);
	virtual __int64 getMoveInputHandler(void);
	virtual __int64 getInputMode(void);
	virtual int getPlayMode(void);
	virtual void reportMovementTelemetry(__int64 MovementEventType);
	virtual void onMovePlayerPacketNormal(Vec3*, Vec2*, float);
};