# 🧠 UHLBehaviorTree 🌳

**UHLBehaviorTree** - pack of helpfull AI nodes for behavior tree. Most needed AI nodes toolset for developing at least 3d-action AI - GameplayFocus, Random choices using RandomChance and RandomSelector, PlayAnimMontage to play attacks animations, InRange and InAngle to check distance to enemy and required angle

Support: `UE5.4 (at least) - UE5.6`

![AiModule](https://github.com/user-attachments/assets/4becb592-c02e-423a-bf80-fcfc629ce518)

## ✨ Features

- AI nodes
  - `GameplayFocus` - set focus on actor
  - `RandomChance` - randomize actions
  - `InRange` - check distance to enemy
  - `InAngle` - check angle to enemy
  - `PlayAnimMontage` - play attack animation
  - `SetBBValue` - set blackboard value
  - `DebugPrintBBValue` - print blackboard value
  - `DebugPrintString` - print string on screen
  - `InvokeGameplayAbility` - activate/deactivate GAS Gameplay Ability by tag, with optional "wait for finishing"
  - `TurnTo` - turn enemy using turn animations

## 🚀 Install & ⬆️ Update

#### From source (recommended)

```bash
// install as git submodule to your plugins folder
git submodule add https://github.com/Ciberusps/UHLAI.git ./Plugins/UHLAI
git submodule add https://github.com/Ciberusps/UHLBehaviorTree.git ./Plugins/UHLBehaviorTree

// to update plugin
git submodule update --remote`
```

## 📄 Documentation

> - Composite
>   - [RandomSelector](#btc_randomselector)
> - Services
>   - [GameplayFocus](#setgameplayfocus)
> - Decorators
>   - [CheckGASGameplayTagsOnActor](#checkgasgameplaytagsonactor)
>   - [InAngle](#inangle)
>   - [InRange](#inrange)
>   - [LoopRandomCount](#looprandomcount)
>   - [RandomChance](#randomchance)
>   - [TimeLimitRandom](#timelimitrandom)
> - Tasks
>   - [SetBBValue](#setbbvalue)
>   - [DebugPrintBBValue](#debugprintbbvalue)
>   - [DebugPrintString](#debugprintstring)
>   - [InvokeGameplayAbility](#invokegameplayability)
>   - [PlayAnimMontage](#playanimmontage)
>   - [TurnTo](#turnto)

#### `UHLAIPerceptionComponent`

⚒️ InProgress

#### `BTC_RandomSelector`

Select random child node using weights

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/ad19828d-032f-4938-9106-2763ec6fb1fd)

<details>
  <summary>With cool validations</summary>

#### Warns if summary of weights > 1

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/78c62bb9-1b1e-4f5a-89b2-68ea4b445ec2)

#### Warns if chances array have more items then child nodes

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/8dc579a0-7f89-4f27-8a1b-a43fa9889496)

#### Shows error if child nodes count > than chances count

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/b8416859-a557-4378-85e3-27091f631b54)

</details>

#### `CheckGASGameplayTagsOnActor`

**BTD_CheckGASGameplayTagsOnActor** - checks that actor has GAS gameplay tags specified.

> [!WARNING]
> Don't mess with `UBTDecorator_CheckGameplayTagsOnActor` - its only checks `GameplayTags` on actor itself not on `AbilitySystem`.

Requirements:

- actor should implement `IAbilitySystemInterface` to get `AbilitySystemComponent`

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/f1581009-b9cd-408f-84de-2475b43012ae)

#### `InAngle`

**BTD_InAngle** - decorator to check is enemy in one of specified angle ranges. Useful in developing big enemies, for example we developing dragon we want to know is player under the right wing or leg, is player in front of dragon or behind and so on.

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/20f95715-a013-4b5f-8107-cd72d3163f4a)

#### `InRange`

**BTD_InRange** - decorator to check distance between actors. Compliant with "MoveTo" node have same settings `bIncludeSelfCapsuleRadius` and `bIncludeTargetCapsuleRadius` to check distance excluding capsules radiuses

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/5ee47572-0fdb-4afa-bbd1-d18eafb86807)
![InRange](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/e32b5d05-de82-4dfb-80d1-539c866008ff)

#### `LoopRandomCount`

**BTD_LoopRandomCount** - randomized version of decorator `Loop`

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/9a97dd83-d5d3-4cfd-a9bb-830ce7f4c450)

#### `TimeLimitRandom`

**BTD_TimeLimitRandom** - randomized version of decorator `TimeLimit`

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/4fd5b54f-5066-4b47-9425-fac0f92b1b07)

#### `RandomChance`

**BTD_RandomChance** - commonly used decorator to randomize actions. Fine for single child node, extra bad for multiple nodes due to chance regression, for randomization between multiple child nodes better to use [RandomSelector](#btc_randomselector)

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/b469a200-5655-440a-a754-8f8f544a38a2)

#### `SetGameplayFocus`

**BTS_SetGameplayFocus** - alternative for "Set default focus". SetGameplayFocus made right way - prevents rotation jittering while enemy rotation.
One of most common problems that anybody stucks when starting developing AI - "focus dont work"/"focus works wrong".

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/c0add45c-76ef-44bc-b97c-0c56901e6e03)
![GameplayFocus](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/0126fc2b-8a20-4b61-93d8-b1ead6802057)

Requirements:

- turn on `UseControllerDesiredRotation`
- turn off
  - `bOrientRotationToMovement`
  - `UseControllerRotationYaw`
  - `UseControllerRotationPitch`
  - `UseControllerRotationRoll`


Troubleshooting:

- check that nothing "ClearFocus"
- check that MoveTo uses "AllowStafe"

#### `SetBBValue`

**BTT_SetBBValue** - helps settings values in blackboard, supports all blackboard types and for some values event provides opportunity to make calculations like `int`

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/baf4ea25-5d19-482d-a60c-799663def759)

#### `DebugPrintBBValue`

**BTT_DebugPrintBBValue** - prints BB value of any type

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/d138c011-fc9a-438e-bd39-658480cd95bf)

#### `DebugPrintString`

**BTT_DebugPrintString** - simple task for printing debug info on screen

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/510e9766-37be-4f43-a60f-e0e012521841)

#### `InvokeGameplayAbility`

**BTT_InvokeGameplayAbility** - activate/deactivate GAS Gameplay Ability by tag, with optional "wait for finishing"

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/1916c411-7068-43db-9e69-3e6190874de5)

#### `PlayAnimMontage`

**BTT_PlayAnimMontage** - play anim montage with option to customize PlayRate, Starting Position, Start Section Name and stopping montage on task abort

![image](https://github.com/Ciberusps/unreal-helper-library/assets/14001879/5026ebdc-689d-4dba-a168-22ae8d6850bf)

#### `TurnTo`

**BTT_TurnTo** - turn to enemy using turn animations
Drop in replacement for "RotateToFaceBBEntry" but with option to "RotateTo" with animations
To get settings from actor requires `IUHLActorSettings` to be implemented on character
