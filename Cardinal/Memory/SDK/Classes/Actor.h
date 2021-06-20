#pragma once
#include <bitset>
#include <vector>
#include <functional>

#include "TextHolder.h"

class Actor {
public:
	bool* onGround() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("0F B6 80 ? ? ? ? C3 CC CC CC CC 48 8B 41 ? F3") + 3);
		return reinterpret_cast<bool*>((uintptr_t)(this) + offset);
	}

	float* stepHeight() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("F3 0F 10 ? ? ? ? ? C3 CC CC CC 48 8B 41 ? 88 90 ? ? ? ? C3") + 4);
		return reinterpret_cast<float*>((uintptr_t)(this) + offset);
	}

	Vec2* bodyRot() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("F2 0F 11 87 ? ? ? ? F3 0F 10 8F ? ? ? ? F3") + 4);
		return reinterpret_cast<Vec2*>((uintptr_t)(this) + offset);
	}

	Vec3* velocity() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("0F 10 89 ? ? ? ? 0F 57 D2 F3 0F ? ? ? ? ? ? 0F 28 C1 0F") + 3);
		return reinterpret_cast<Vec3*>((uintptr_t)(this) + offset);
	}

	class BlockSource* getRegionConst() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 97 ? ? ? ? 48 8B ? ? ? ? ? ? ? 90 48 8B 5D DF") + 3);
		return *reinterpret_cast<BlockSource**>((uintptr_t)(this) + offset);
	}

	class Dimension* getDimension() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B B8 ? ? ? ? 48 8B BF ? ? ? ? 48 8B 1F 48 3B DF") + 3);
		return *reinterpret_cast<Dimension**>((uintptr_t)(this) + offset);
	}

	class Level* getLevel() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 8F ? ? ? ? 48 8B 11 FF 92 ? ? ? ? 48 8B 8F ? ? ? ? 48 8B") + 3);
		return *reinterpret_cast<Level**>((uintptr_t)(this) + offset);
	}

	class PlayerInventory* getSupplies() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 91 ? ? ? ? 80 BA ? ? ? ? ? ? ? 48 8B 8A ? ? ? ? 8B 52 ? 48 8B 01 48 FF 60 ? 48") + 3);
		return *reinterpret_cast<PlayerInventory**>((uintptr_t)(this) + offset);
	}

	void _setPos(Vec3* pos) {
		using SetPos = void(__thiscall*)(Actor*, Vec3*);
		static SetPos _SetPos = reinterpret_cast<SetPos>(Utils::FindSig("40 53 48 83 EC 20 8B 02 48 8B D9 89 81 ? ? ? ? 8B 42 04 89 81 ? ? ? ? 8B 42 08 89 81 ? ? ? ?"));
		_SetPos(this, pos);
	}

	void updateOwnerChunk() {
		using UpdateOwnerChunk = void(__thiscall*)(Actor*);
		static UpdateOwnerChunk _UpdateOwnerChunk = reinterpret_cast<UpdateOwnerChunk>(Utils::FindSig("48 89 5C 24 ? 48 89 74 24 ? 57 48 81 EC ? ? ? ? 48 8B D9 48 8B 89 ? ? ? ?"));
		_UpdateOwnerChunk(this);
	}

	long long getRuntimeId() {
		static unsigned int offset = NULL;
		if (offset == NULL)
			offset = *reinterpret_cast<int*>(Utils::FindSig("48 8B 87 ? ? ? ? C7 45 EF ? ? ? ? C7") + 3);
		return *reinterpret_cast<long long*>((uintptr_t)(this) + offset);
	}
private:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
public:
	virtual void _serverInitItemStackIds(void);
	virtual void _doInitialMove(void);
private:
	virtual void Function6();
public:
	virtual void reset(void);
	virtual __int64 getOnDeathExperience(void);
	virtual int getOwnerEntityType(void);
	virtual void remove(void);
	virtual void setPos(Vec3*);
private:
	virtual void Function12();
public:
	virtual __int64 getPredictedMovementValues(void);
	virtual __int64 getStateVectorComponent(void);
	virtual Vec3* getPos(void);
	virtual Vec3* getPosExtrapolated(float);
	virtual Vec3* getAttachPos(__int64 ActorLocation, float);
	virtual Vec3* getFiringPos(void);
	virtual void setRot(Vec2*);
	virtual void move(__int64 IActorMovementProxy, Vec3*);
	virtual void move(Vec3*);
	virtual Vec3* getInterpolatedRidingPosition(float);
	virtual float getInterpolatedBodyRot(float);
	virtual float getInterpolatedHeadRot(float);
	virtual float getInterpolatedBodyYaw(float);
	virtual float getYawSpeedInDegreesPerSecond(void);
	virtual float getInterpolatedWalkAnimSpeed(float);
	virtual Vec3* getWorldPosition(void);
private:
	virtual bool checkBlockCollisions(AABB*, std::function<void(class BlockSource*, class Block*, Vec3*, Actor*)>);
public:
	virtual void updateEntityInside(void);
	virtual void updateEntityInside(AABB*);
	virtual bool isFireImmune(void);
private:
	virtual void Function33();
public:
	virtual bool blockedByShield(__int64 ActorDamageSource, Actor*);
	virtual void teleportTo(Vec3*, bool, int, int);
	virtual void tryTeleportTo(Vec3*, bool, bool, int, int);
	virtual void chorusFruitTeleport(Vec3*);
	virtual void lerpTo(Vec3*, Vec2*, int);
	virtual void lerpMotion(Vec3*);
	virtual void tryCreateAddActorPacket(void);
	virtual void normalTick(void);
	virtual void baseTick(void);
	virtual void rideTick(void);
	virtual void positionRider(Actor*, float);
	virtual float getRidingHeight(void);
	virtual void startRiding(Actor*);
	virtual void addRider(Actor*);
	virtual void flagRiderToRemove(Actor*);
	virtual void getExitTip(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, __int64 InputMode);
	virtual bool intersects(Vec3*, Vec3*);
	virtual bool isFree(Vec3*);
	virtual bool isFree(Vec3*, float);
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual bool canShowNameTag(void);
private:
	virtual void Function56();
public:
	virtual void setNameTagVisible(bool);
private:
	virtual void Function57();
public:
	virtual TextHolder* getNameTag(void);
private:
	virtual void Function59();
public:
	virtual class TextHolder* getFormattedNameTag(void);
	virtual void filterFormattedNameTag(__int64 UIProfanityContext);
	virtual void setNameTag(std::string const&);
private:
	virtual void Function63();
public:
	virtual void setScoreTag(std::string const&);
	virtual TextHolder* getScoreTag(void);
	virtual bool isInWater(void);
	virtual bool hasEnteredWater(void);
	virtual bool isImmersedInWater(void);
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(__int64 MaterialType);
	virtual bool isOverWater(void);
	virtual void setBlockMovementSlowdownMultiplier(Vec3*);
	virtual void resetBlockMovementSlowdownMultiplier(void);
	virtual float getCameraOffset(void);
	virtual float getShadowHeightOffs(void);
	virtual float getShadowRadius(void);
	virtual Vec3* getHeadLookVector(float);
private:
	virtual void Function78();
public:
	virtual bool canSee(Vec3*);
	virtual bool canSee(Actor*);
	virtual bool isSkyLit(float);
	virtual float getBrightness(float);
private:
	virtual void Function83();
	virtual void Function84();
public:
	virtual void onAboveBubbleColumn(bool);
	virtual void onInsideBubbleColumn(bool);
	virtual bool isImmobile(void);
	virtual bool isSilent(void);
	virtual bool isPickable(void); /* Item Actor */
private:
	virtual void Function90();
public:
	virtual bool isSleeping(void);
private:
	virtual void Function92();
public:
	virtual void setSneaking(bool);
	virtual bool isBlocking(void);
	virtual bool isDamageBlocked(__int64 ActorDamageSource);
	virtual bool isAlive(void);
	virtual bool isOnFire(void);
	virtual bool isOnHotBlock(void);
private:
	virtual void Function99();
public:
	virtual bool isSurfaceMob(void);
private:
	virtual void Function101();
	virtual void Function102();
	virtual void Function103();
public:
	virtual bool isAffectedByWaterBottle(void);
	virtual bool canAttack(Actor*, bool);
	virtual bool setTarget(Actor*);
private:
	virtual void Function107();
public:
	virtual bool isValidTarget(Actor*);
	virtual void attack(Actor*);
	virtual float performRangedAttack(Actor*, float);
	virtual void adjustDamageAmount(int);
	virtual int getEquipmentCount(void);
	virtual void setOwner(__int64 ActorUniqueID);
	virtual void setSitting(bool);
private:
	virtual void Function114();
	virtual void Function115();
public:
	virtual __int64 getInventorySize(void);
	virtual __int64 getEquipSlots(void);
	virtual __int64 getChestSlots(void);
	virtual void setStanding(bool);
	virtual bool canPowerJump(void);
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual bool isEnchanted(void);
private:
	virtual void Function124();
	virtual void Function125();
public:
	virtual bool shouldRender(void);
	virtual bool isInvulnerableTo(__int64 ActorDamageSource);
	virtual __int64 getBlockDamageCause(Block*);
	virtual void actuallyHurt(int, __int64 ActorDamageSource, bool);
	virtual void animateHurt(void);
	virtual void doFireHurt(int);
	virtual void onLightningHit(void);
	virtual void onBounceStarted(Vec3i* blockPos, Block*);
	virtual void feed(int);
	virtual void handleEntityEvent(__int64 ActorEvent, int);
	virtual float getPickRadius(void); /* Item Actor?? */
	virtual __int64 getActorRendererId(void);
	virtual void spawnAtLocation(ItemStack*, float);
	virtual void spawnAtLocation(Block*, int, float);
	virtual void spawnAtLocation(Block*, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(int, int);
	virtual void despawn(void);
	virtual void killed(Actor*);
	virtual void awardKillScore(Actor*, int);
	virtual void setArmor(int ArmorSlot, ItemStack*);
	virtual ItemStack* getArmor(int ArmorSlot);
	virtual __int64 getArmorMaterialTypeInSlot(int ArmorSlot);
	virtual __int64 getArmorMaterialTextureTypeInSlot(int ArmorSlot);
	virtual __int64 getArmorColorInSlot(int ArmorSlot, int);
	virtual ItemStack* getEquippedSlot(int EquipmentSlot);
	virtual void setEquippedSlot(int EquipmentSlot, ItemStack*);
	virtual ItemStack* getSelectedItem(void);
	virtual void setCarriedItem(ItemStack*);
	virtual void setOffhandSlot(ItemStack*);
	virtual ItemStack* getEquippedTotem(void);
	virtual void consumeTotem(void);
	virtual void save(__int64 CompoundTag);
	virtual void saveWithoutId(__int64 CompoundTag);
	virtual void load(__int64 CompoundTag, __int64 DataLoadHelper);
	virtual void loadLinks(/*__int64 CompoundTag, std::vector<__int64 ActorLink, std::allocator<__int64 ActorLink>>, DataLoadHelper*/);
	virtual __int64 getEntityTypeId(void);
	virtual __int64 getRawName(void);
	virtual __int64 getSourceUniqueID(void);
	virtual void setOnFire(int duration);
	virtual void extinguishFire(void);
	virtual void thawFreezeEffect(void);
	virtual bool canFreeze(void);
	virtual bool isWearingLeatherArmor(void);
	virtual AABB* getHandleWaterAABB(void);
	virtual void handleInsidePortal(Vec3i* BlockPos);
	virtual __int64 getId(void);
	virtual __int64 getPortalWaitTime(void);
	virtual DWORD getDimensionId(void);
	virtual bool canChangeDimensions(void);
private:
	virtual void Function176();
public:
	virtual void changeDimension(int Dimension, bool);
	virtual __int64 getControllingPlayer(void);
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float, float, __int64 ActorDamageSource);
	virtual void handleFallDistanceOnServer(float, float, bool);
	virtual void playSynchronizedSound(__int64 LevelSoundEvent, Vec3*, int, bool);
	virtual void playSynchronizedSound(__int64 LevelSoundEvent, Vec3*, Block*, bool);
	virtual void onSynchedDataUpdate(int);
	virtual void canAddRider(Actor*);
private:
	virtual void Function186();
	virtual void Function187();
public:
	virtual bool inCaravan(void);
private:
	virtual void Function189();
public:
	virtual void tickLeash(void);
private:
	virtual void Function191();
	virtual void Function192();
public:
	virtual void stopRiding(bool, bool, bool);
	virtual void startSwimming(void);
	virtual void stopSwimming(void);
	virtual __int64 buildDebugInfo(void);
	virtual int getCommandPermissionLevel(void);
	virtual __int64 getMutableAttribute(__int64 Attribute);
	virtual __int64 getAttribute(int Attribute);
	virtual __int64 getDeathTime(void);
	virtual void heal(int);
	virtual bool isInvertedHealAndHarm(void);
	virtual bool canBeAffected(__int64 MobEffectInstance);
	virtual bool canBeAffected(int);
	virtual bool canBeAffectedByArrow(__int64 MobEffectInstance);
	virtual void onEffectAdded(__int64 MobEffectInstance);
	virtual void onEffectUpdated(__int64 MobEffectInstance);
	virtual void onEffectRemoved(__int64 MobEffectInstance);
	virtual __int64 getAnimationComponent(void);
	virtual void openContainerComponent(Player*);
	virtual void swing(void);
	virtual void useItem(__int64 ItemStackBase, __int64 ItemUseMethod, bool);
private:
	virtual void Function213();
	virtual void Function214();
	virtual void Function215();
public:
	virtual float getMapDecorationRotation(void);
	virtual float getRiderYRotation(Actor*);
	virtual float getYHeadRot(void);
	virtual bool isWorldBuilder(void);
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
	virtual void add(ItemStack*);
	virtual void drop(ItemStack*, bool);
	virtual __int64 getInteraction(Player*, __int64 ActorInteraction, Vec3*);
private:
	virtual void Function225();
	virtual void Function226();
public:
	virtual void setSize(float width, float height);
	virtual __int64 getLifeSpan(void);
	virtual void onOrphan(void);
	virtual void wobble(void);
	virtual bool wasHurt(void);
	virtual void startSpinAttack(void);
	virtual void stopSpinAttack(void);
	virtual bool setDamageNearbyMobs(bool);
private:
	virtual void Function335();
public:
	virtual void reloadLootTable(__int64 EquipmentTableDefinition);
	virtual void reloadLootTable(void);
	virtual __int64 getLootTable(void);
private:
	virtual void Function339();
	virtual void Function340();
public:
	virtual void kill(void);
	virtual void die(__int64 ActorDamageSource);
	virtual bool shouldTick(void);
	virtual void createMovementProxy(void);
	virtual __int64 getMovementProxy(void);
	virtual float getNextStep(float);
	virtual void updateEntitySpecificMolangVariables(__int64 RenderParams);
	virtual void useWebsocketEncryption(void);
private:
	virtual void Function349();
public:
	virtual bool outOfWorld(void);
	virtual void _hurt(__int64 ActorDamageSource, int, bool, bool);
	virtual void markHurt(void); /* Map */
	virtual __int64 _getAnimationComponent(__int64 /*std::shared_ptr<class AnimationComponent>*/, __int64 AnimationComponentGroup);
	virtual void readAdditionalSaveData(__int64 CompoundTag, __int64 DataLoadHelper);
	virtual void addAdditionalSaveData(__int64 CompoundTag);
	virtual void _playStepSound(Vec3i* BlockPos, Block*);
	virtual void _playFlySound(Vec3i* BlockPos, Block*);
private:
	virtual void Function358();
public:
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vec3*);
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles(void);
	virtual void updateInsideBlock(void);
	virtual void _removeRider(__int64 ActorUniqueID, bool, bool, bool);
	virtual void _onSizeUpdated(void);
private:
	virtual void Function367();
};