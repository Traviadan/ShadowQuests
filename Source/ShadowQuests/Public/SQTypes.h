#pragma once

#include "CoreMinimal.h"
#include "SQTypes.generated.h"

class UPrimaryDataAsset;

UENUM(BlueprintType)
enum class ESQDamageType : uint8
{
	EDT_Physical UMETA(DisplayName = "Physical Damage"),
	EDT_Stun UMETA(DisplayName = "Stun Damage"),

	EDT_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class ESQWeaponType : uint8
{
	EWT_CloseCombatBlade UMETA(DisplayName = "Klingenwaffen"),
	EWT_CloseCombatBlunt UMETA(DisplayName = "Knüppel"),
	EWT_CloseCombatOther UMETA(DisplayName = "Andere Nahkampfwaffen"),

	EWT_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class ESQItemCondition : uint8
{
	EIC_New UMETA(DisplayName = "Neu"),
	EIC_Used UMETA(DisplayName = "Gebraucht"),
	EIC_Defective UMETA(DisplayName = "Defekt"),
	EIC_Destroyed UMETA(DisplayName = "Zerstört"),

	EIC_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class ESQItemVisibility : uint8
{
	EIV_Normal UMETA(DisplayName = "Normal"),
	EIV_Hidden UMETA(DisplayName = "Versteckt"),
	EIV_Invisible UMETA(DisplayName = "Unsichtbar"),

	ESRIC_MAX UMETA(DisplayName = "DefaultMAX")
};

UENUM(BlueprintType)
enum class ESQLegality : uint8
{
	EL_Legal UMETA(DisplayName = "Legal"),
	EL_Restricted UMETA(DisplayName = "Eingeschränkt"),
	EL_Forbidden UMETA(DisplayName = "Verboten"),

	ELC_MAX UMETA(DisplayName = "DefaultMAX")
};

USTRUCT(BlueprintType)
struct FSQItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPrimaryDataAsset* ItemAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UPrimaryDataAsset*> ModifierAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESQItemCondition ItemCondition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ESQItemVisibility ItemVisibility;
};

USTRUCT(BlueprintType)
struct FSQWorldInformation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 InfoLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Information;
};