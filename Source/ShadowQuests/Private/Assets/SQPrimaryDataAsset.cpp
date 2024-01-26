// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "Assets/SQPrimaryDataAsset.h"

USQPrimaryDataAsset::USQPrimaryDataAsset()
{
}

FPrimaryAssetId USQPrimaryDataAsset::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(TEXT("SQDataAsset"), AssetId);
}
