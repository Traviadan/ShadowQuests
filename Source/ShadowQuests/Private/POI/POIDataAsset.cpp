// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "POI/POIDataAsset.h"

UPOIDataAsset::UPOIDataAsset()
{
}

FPrimaryAssetId UPOIDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(TEXT("POIDataAsset"), AssetId);
}
