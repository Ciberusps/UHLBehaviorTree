// Pavel Penkov 2025 All Rights Reserved.

#include "UHLBTMathOperations.h"

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


void FUHLBTOperationOnBBValue::SetCurrentBBKeyValueType(EBlackboardValueType CurrentBBKeyValueType_In)
{
	CurrentBBKeyValueType = CurrentBBKeyValueType_In;
}

int32 FUHLBTOperationOnBBValue::CalculateIntResult(UBehaviorTreeComponent& OwnerComp, int32 CurrentValue) const
{
	int32 Result = CurrentValue;

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent) return Result;
			
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = IntValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = CurrentValue + IntValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = CurrentValue * IntValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = CurrentValue / IntValue.GetValue(OwnerComp);
	}

	return Result;
}

float FUHLBTOperationOnBBValue::CalculateFloatResult(
	UBehaviorTreeComponent& OwnerComp, float CurrentValue) const
{
	float Result = CurrentValue;

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent) return Result;
			
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = FloatValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = CurrentValue + FloatValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = CurrentValue * FloatValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = CurrentValue / FloatValue.GetValue(OwnerComp);
	}

	return Result;
}

FVector FUHLBTOperationOnBBValue::CalculateVectorResult(
	UBehaviorTreeComponent& OwnerComp, FVector CurrentValue) const
{
	FVector Result = CurrentValue;

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent) return Result;
			
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = VectorValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = CurrentValue + VectorValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = CurrentValue * VectorValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = CurrentValue / VectorValue.GetValue(OwnerComp);
	}

	return Result;
}

FRotator FUHLBTOperationOnBBValue::CalculateRotatorResult(
	UBehaviorTreeComponent& OwnerComp, FRotator CurrentValue) const
{
	FRotator Result = CurrentValue;

	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent) return Result;
			
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = RotatorValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = CurrentValue + RotatorValue.GetValue(OwnerComp);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = (CurrentValue.Euler() * RotatorValue.GetValue(OwnerComp).Euler()).ToOrientationRotator();
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = (CurrentValue.Euler() / RotatorValue.GetValue(OwnerComp).Euler()).ToOrientationRotator();
	}

	return Result;
}

FString FUHLBTOperationOnBBValue::ToStringIntValue(FString KeyName) const
{
	FString Result = "";
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = FString::Printf(TEXT("Set \"%s\" to %s"), *KeyName, *IntValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = FString::Printf(TEXT("Add \"%s\" to %s"), *IntValue.ToString(), *KeyName);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = FString::Printf(TEXT("Multiply \"%s\" by %s"), *KeyName, *IntValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = FString::Printf(TEXT("Divide \"%s\" by %s"), *KeyName, *IntValue.ToString());
	}
	return Result;
}

FString FUHLBTOperationOnBBValue::ToStringFloatValue(FString KeyName) const
{
	FString Result = "";
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = FString::Printf(TEXT("Set \"%s\" to %sf"), *KeyName, *FloatValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = FString::Printf(TEXT("Add \"%s\" to %s"), *FloatValue.ToString(), *KeyName);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = FString::Printf(TEXT("Multiply \"%s\" by %sf"), *KeyName, *FloatValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = FString::Printf(TEXT("Divide \"%s\" by %sf"), *KeyName, *FloatValue.ToString());
	}
	return Result;
}

FString FUHLBTOperationOnBBValue::ToStringVectorValue(FString KeyName) const
{
	FString Result = "";
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = FString::Printf(TEXT("Set \"%s\" to %sf"), *KeyName, *VectorValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = FString::Printf(TEXT("Add \"%s\" to %s"), *VectorValue.ToString(), *KeyName);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = FString::Printf(TEXT("Multiply \"%s\" by %sf"), *KeyName, *VectorValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = FString::Printf(TEXT("Divide \"%s\" by %sf"), *KeyName, *VectorValue.ToString());
	}
	return Result;
}

FString FUHLBTOperationOnBBValue::ToStringRotatorValue(FString KeyName) const
{
	FString Result = "";
	if (MathOperation == EUHL_MathOperations::Set)
	{
		Result = FString::Printf(TEXT("Set \"%s\" to %sf"), *KeyName, *RotatorValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Add)
	{
		Result = FString::Printf(TEXT("Add \"%s\" to %s"), *RotatorValue.ToString(), *KeyName);
	}
	else if (MathOperation == EUHL_MathOperations::Multiply)
	{
		Result = FString::Printf(TEXT("Multiply \"%s\" by %sf"), *KeyName, *RotatorValue.ToString());
	}
	else if (MathOperation == EUHL_MathOperations::Divide)
	{
		Result = FString::Printf(TEXT("Divide \"%s\" by %sf"), *KeyName, *RotatorValue.ToString());
	}
	return Result;
}
