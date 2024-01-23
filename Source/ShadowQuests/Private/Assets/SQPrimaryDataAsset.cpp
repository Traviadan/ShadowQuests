// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Assets/SQPrimaryDataAsset.h"

USQPrimaryDataAsset::USQPrimaryDataAsset() :
	AssetType(TEXT("SQDataAsset"))
{
}

FPrimaryAssetId USQPrimaryDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(AssetType, AssetId);
}
