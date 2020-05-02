// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Battle_Tanks/Battle_TanksGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBattle_TanksGameModeBase() {}
// Cross Module References
	BATTLE_TANKS_API UClass* Z_Construct_UClass_ABattle_TanksGameModeBase_NoRegister();
	BATTLE_TANKS_API UClass* Z_Construct_UClass_ABattle_TanksGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Battle_Tanks();
// End Cross Module References
	void ABattle_TanksGameModeBase::StaticRegisterNativesABattle_TanksGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABattle_TanksGameModeBase_NoRegister()
	{
		return ABattle_TanksGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ABattle_TanksGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABattle_TanksGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Battle_Tanks,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABattle_TanksGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Battle_TanksGameModeBase.h" },
		{ "ModuleRelativePath", "Battle_TanksGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABattle_TanksGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABattle_TanksGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABattle_TanksGameModeBase_Statics::ClassParams = {
		&ABattle_TanksGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ABattle_TanksGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABattle_TanksGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABattle_TanksGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABattle_TanksGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABattle_TanksGameModeBase, 3789563251);
	template<> BATTLE_TANKS_API UClass* StaticClass<ABattle_TanksGameModeBase>()
	{
		return ABattle_TanksGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABattle_TanksGameModeBase(Z_Construct_UClass_ABattle_TanksGameModeBase, &ABattle_TanksGameModeBase::StaticClass, TEXT("/Script/Battle_Tanks"), TEXT("ABattle_TanksGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABattle_TanksGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
