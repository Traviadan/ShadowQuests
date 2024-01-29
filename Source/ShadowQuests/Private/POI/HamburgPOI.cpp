// Copyright (C) 2024 Thorsten Eggers <thorsten@eggers-bhv.de>


#include "POI/HamburgPOI.h"

UHamburgPOI::UHamburgPOI()
{
}

FPrimaryAssetId UHamburgPOI::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(TEXT("HamburgPOI"), AssetId);
}
