// Third Person Shooter Game, All Rights Reserved.

#include "TPSGameInstance.h"
#include "Sound/TPSSoundFuncLib.h"

void UTPSGameInstance::ToggleVolume()
{
    UTPSSoundFuncLib::ToggleSoundClassVolume(MasterSoundClass);
}