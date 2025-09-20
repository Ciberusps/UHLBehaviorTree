// Pavel Penkov 2025 All Rights Reserved.

#include "Modules/ModuleManager.h"

class FUHLBehaviorTreeModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FUHLBehaviorTreeModule, UHLBehaviorTree)


