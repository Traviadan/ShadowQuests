// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "World/LegworkDataAsset.h"

ULegworkDataAsset::ULegworkDataAsset()
{
}

FPrimaryAssetId ULegworkDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(TEXT("LegworkDataAsset"), AssetId);
}

void ULegworkDataAsset::GetInformationsByLevel(int32 Level, TArray<FSQWorldInformation>& OutInformations) const
{
	
	for (FSQWorldInformation WorldInfo : WorldInformations)
	{
		if (WorldInfo.InfoLevel <= Level)
		{
			OutInformations.Add(WorldInfo);
		}
		else
		{
			break;
		}
	}
}

bool ULegworkDataAsset::BelongsToMap(FName Map) const
{
	if (MapName == Map)
	{
		return true;
	}
	return false;
}

bool ULegworkDataAsset::IsInformationAboutTarget(FPrimaryAssetId TargetId) const
{
	if (About == TargetId)
	{
		return true;
	}
	return false;
}
