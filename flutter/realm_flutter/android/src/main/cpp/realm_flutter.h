////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2021 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef ANDROID_REALM_FLUTTER_H
#define ANDROID_REALM_FLUTTER_H

#include "dart_api_dl.h"

#define Dart_PostCObject Dart_PostCObject_DL

#define Dart_PostInteger Dart_PostInteger_DL

#define Dart_NewNativePort Dart_NewNativePort_DL

#define Dart_CloseNativePort Dart_CloseNativePort_DL

#define Dart_IsError Dart_IsError_DL

#define Dart_IsApiError Dart_IsApiError_DL

#define Dart_IsUnhandledExceptionError Dart_IsUnhandledExceptionError_DL

#define Dart_IsCompilationError Dart_IsCompilationError_DL

#define Dart_IsFatalError Dart_IsFatalError_DL

#define Dart_GetError Dart_GetError_DL

#define Dart_ErrorHasException Dart_ErrorHasException_DL

#define Dart_ErrorGetException Dart_ErrorGetException_DL

#define Dart_ErrorGetStackTrace Dart_ErrorGetStackTrace_DL

#define Dart_NewApiError Dart_NewApiError_DL

#define Dart_NewCompilationError Dart_NewCompilationError_DL

#define Dart_NewUnhandledExceptionError Dart_NewUnhandledExceptionError_DL

#define Dart_PropagateError Dart_PropagateError_DL

#define Dart_ToString Dart_ToString_DL

#define Dart_IdentityEquals Dart_IdentityEquals_DL

#define Dart_HandleFromPersistent Dart_HandleFromPersistent_DL

#define Dart_HandleFromWeakPersistent Dart_HandleFromWeakPersistent_DL

#define Dart_NewPersistentHandle Dart_NewPersistentHandle_DL

#define Dart_SetPersistentHandle Dart_SetPersistentHandle_DL

#define Dart_DeletePersistentHandle Dart_DeletePersistentHandle_DL

#define Dart_NewWeakPersistentHandle Dart_NewWeakPersistentHandle_DL

#define Dart_DeleteWeakPersistentHandle Dart_DeleteWeakPersistentHandle_DL

#define Dart_Post Dart_Post_DL

#define Dart_NewSendPort Dart_NewSendPort_DL

#define Dart_SendPortGetId Dart_SendPortGetId_DL

#define Dart_EnterScope Dart_EnterScope_DL

#define Dart_ExitScope Dart_ExitScope_DL













#define Dart_Allocate Dart_Allocate_DL

#define Dart_AllocateWithNativeFields Dart_AllocateWithNativeFields_DL

#define Dart_BooleanValue Dart_BooleanValue_DL

#define Dart_ClassLibrary Dart_ClassLibrary_DL

#define Dart_ClassName Dart_ClassName_DL

#define Dart_Cleanup Dart_Cleanup_DL

#define Dart_ClosureFunction Dart_ClosureFunction_DL

#define Dart_CreateIsolateGroup Dart_CreateIsolateGroup_DL

#define Dart_CreateIsolateGroupFromKernel Dart_CreateIsolateGroupFromKernel_DL

#define Dart_CurrentIsolate Dart_CurrentIsolate_DL

#define Dart_CurrentIsolateData Dart_CurrentIsolateData_DL

#define Dart_CurrentIsolateGroup Dart_CurrentIsolateGroup_DL

#define Dart_CurrentIsolateGroupData Dart_CurrentIsolateGroupData_DL

#define Dart_DebugName Dart_DebugName_DL

#define Dart_DoubleValue Dart_DoubleValue_DL

#define Dart_DumpNativeStackTrace Dart_DumpNativeStackTrace_DL

#define Dart_EmptyString Dart_EmptyString_DL

#define Dart_EnterIsolate Dart_EnterIsolate_DL

#define Dart_ExitIsolate Dart_ExitIsolate_DL

#define Dart_False Dart_False_DL

#define Dart_FunctionIsStatic Dart_FunctionIsStatic_DL

#define Dart_FunctionName Dart_FunctionName_DL

#define Dart_FunctionOwner Dart_FunctionOwner_DL

#define Dart_GetClass Dart_GetClass_DL

#define Dart_GetDataFromByteBuffer Dart_GetDataFromByteBuffer_DL

#define Dart_GetField Dart_GetField_DL

#define Dart_GetImportsOfScheme Dart_GetImportsOfScheme_DL

#define Dart_GetLoadedLibraries Dart_GetLoadedLibraries_DL

#define Dart_GetMessageNotifyCallback Dart_GetMessageNotifyCallback_DL

#define Dart_GetNativeArguments Dart_GetNativeArguments_DL

#define Dart_GetNativeArgument Dart_GetNativeArgument_DL

#define Dart_GetNativeBooleanArgument Dart_GetNativeBooleanArgument_DL

#define Dart_GetNativeDoubleArgument Dart_GetNativeDoubleArgument_DL

#define Dart_GetNativeArgumentCount Dart_GetNativeArgumentCount_DL

#define Dart_GetNativeFieldsOfArgument Dart_GetNativeFieldsOfArgument_DL

#define Dart_GetNativeInstanceField Dart_GetNativeInstanceField_DL

#define Dart_GetNativeInstanceFieldCount Dart_GetNativeInstanceFieldCount_DL

#define Dart_GetNativeIntegerArgument Dart_GetNativeIntegerArgument_DL

#define Dart_GetNativeIsolateGroupData Dart_GetNativeIsolateGroupData_DL

#define Dart_GetNativeResolver Dart_GetNativeResolver_DL

#define Dart_SetNativeResolver Dart_SetNativeResolver_DL

#define Dart_GetNativeStringArgument Dart_GetNativeStringArgument_DL

#define Dart_GetNativeSymbol Dart_GetNativeSymbol_DL

#define Dart_GetNonNullableType Dart_GetNonNullableType_DL

#define Dart_GetNullableType Dart_GetNullableType_DL

#define Dart_GetPeer Dart_GetPeer_DL

#define Dart_GetStaticMethodClosure Dart_GetStaticMethodClosure_DL

#define Dart_GetStickyError Dart_GetStickyError_DL

#define Dart_GetType Dart_GetType_DL

#define Dart_GetTypeOfExternalTypedData Dart_GetTypeOfExternalTypedData_DL

#define Dart_GetTypeOfTypedData Dart_GetTypeOfTypedData_DL

#define Dart_HasStickyError Dart_HasStickyError_DL

#define Dart_IdentityEquals Dart_IdentityEquals_DL

#define Dart_InstanceGetType Dart_InstanceGetType_DL

#define Dart_IntegerFitsIntoInt64 Dart_IntegerFitsIntoInt64_DL

#define Dart_IntegerFitsIntoUint64 Dart_IntegerFitsIntoUint64_DL

#define Dart_IntegerToHexCString Dart_IntegerToHexCString_DL

#define Dart_IntegerToInt64 Dart_IntegerToInt64_DL

#define Dart_IntegerToUint64 Dart_IntegerToUint64_DL

#define Dart_Invoke Dart_Invoke_DL


#define Dart_InvokeClosure Dart_InvokeClosure_DL

#define Dart_InvokeConstructor Dart_InvokeConstructor_DL

#define Dart_IsBoolean Dart_IsBoolean_DL

#define Dart_IsByteBuffer Dart_IsByteBuffer_DL

#define Dart_IsClosure Dart_IsClosure_DL

#define Dart_IsDouble Dart_IsDouble_DL

#define Dart_IsExternalString Dart_IsExternalString_DL

#define Dart_IsFunction Dart_IsFunction_DL

#define Dart_IsFuture Dart_IsFuture_DL

#define Dart_IsInstance Dart_IsInstance_DL

#define Dart_IsInteger Dart_IsInteger_DL

#define Dart_IsKernel Dart_IsKernel_DL

#define Dart_IsKernelIsolate Dart_IsKernelIsolate_DL

#define Dart_IsLegacyType Dart_IsLegacyType_DL

#define Dart_IsLibrary Dart_IsLibrary_DL

#define Dart_IsList Dart_IsList_DL

#define Dart_IsMap Dart_IsMap_DL

#define Dart_IsNonNullableType Dart_IsNonNullableType_DL

#define Dart_IsNull Dart_IsNull_DL

#define Dart_IsNumber Dart_IsNumber_DL

#define Dart_IsolateData Dart_IsolateData_DL

#define Dart_IsolateFlagsInitialize Dart_IsolateFlagsInitialize_DL

#define Dart_IsolateGroupData Dart_IsolateGroupData_DL

#define Dart_IsolateMakeRunnable Dart_IsolateMakeRunnable_DL

#define Dart_IsolateServiceId Dart_IsolateServiceId_DL

#define Dart_IsPausedOnExit Dart_IsPausedOnExit_DL

#define Dart_IsPausedOnStart Dart_IsPausedOnStart_DL

#define Dart_IsPrecompiledRuntime Dart_IsPrecompiledRuntime_DL

#define Dart_IsServiceIsolate Dart_IsServiceIsolate_DL

#define Dart_IsString Dart_IsString_DL

#define Dart_IsStringLatin1 Dart_IsStringLatin1_DL

#define Dart_IsTearOff Dart_IsTearOff_DL

#define Dart_IsType Dart_IsType_DL

#define Dart_IsTypedData Dart_IsTypedData_DL

#define Dart_IsTypeVariable Dart_IsTypeVariable_DL

#define Dart_IsVariable Dart_IsVariable_DL

#define Dart_IsVMFlagSet Dart_IsVMFlagSet_DL

#define Dart_KernelIsolateIsRunning Dart_KernelIsolateIsRunning_DL

#define Dart_KernelListDependencies Dart_KernelListDependencies_DL

#define Dart_KernelPort Dart_KernelPort_DL

#define Dart_KillIsolate Dart_KillIsolate_DL

#define Dart_LibraryHandleError Dart_LibraryHandleError_DL

#define Dart_LibraryResolvedUrl Dart_LibraryResolvedUrl_DL

#define Dart_LibraryUrl Dart_LibraryUrl_DL

#define Dart_ListGetAsBytes Dart_ListGetAsBytes_DL

#define Dart_ListGetAt Dart_ListGetAt_DL

#define Dart_ListGetRange Dart_ListGetRange_DL

#define Dart_ListLength Dart_ListLength_DL

#define Dart_ListSetAsBytes Dart_ListSetAsBytes_DL

#define Dart_ListSetAt Dart_ListSetAt_DL

#define Dart_LoadLibraryFromKernel Dart_LoadLibraryFromKernel_DL

#define Dart_LoadScriptFromKernel Dart_LoadScriptFromKernel_DL

#define Dart_LookupLibrary Dart_LookupLibrary_DL

#define Dart_MapContainsKey Dart_MapContainsKey_DL

#define Dart_MapGetAt Dart_MapGetAt_DL

#define Dart_MapKeys Dart_MapKeys_DL

#define Dart_New Dart_New_DL

#define Dart_NewBoolean Dart_NewBoolean_DL

#define Dart_NewByteBuffer Dart_NewByteBuffer_DL

#define Dart_NewDouble Dart_NewDouble_DL

#define Dart_NewExternalLatin1String Dart_NewExternalLatin1String_DL

#define Dart_NewExternalTypedData Dart_NewExternalTypedData_DL

#define Dart_NewExternalTypedDataWithFinalizer Dart_NewExternalTypedDataWithFinalizer_DL

#define Dart_NewExternalUTF16String Dart_NewExternalUTF16String_DL

#define Dart_NewInteger Dart_NewInteger_DL

#define Dart_NewIntegerFromHexCString Dart_NewIntegerFromHexCString_DL

#define Dart_NewIntegerFromUint64 Dart_NewIntegerFromUint64_DL

#define Dart_NewList Dart_NewList_DL

#define Dart_NewListOf Dart_NewListOf_DL

#define Dart_NewListOfType Dart_NewListOfType_DL

#define Dart_NewListOfTypeFilled Dart_NewListOfTypeFilled_DL

#define Dart_NewStringFromCString Dart_NewStringFromCString_DL

#define Dart_NewStringFromUTF16 Dart_NewStringFromUTF16_DL

#define Dart_NewStringFromUTF32 Dart_NewStringFromUTF32_DL

#define Dart_NewStringFromUTF8 Dart_NewStringFromUTF8_DL

#define Dart_NewTypedData Dart_NewTypedData_DL

#define Dart_NotifyIdle Dart_NotifyIdle_DL

#define Dart_NotifyLowMemory Dart_NotifyLowMemory_DL

#define Dart_Null Dart_Null_DL

#define Dart_ObjectEquals Dart_ObjectEquals_DL

#define Dart_ObjectIsType Dart_ObjectIsType_DL

#define Dart_PrepareToAbort Dart_PrepareToAbort_DL

#define Dart_ReThrowException Dart_ReThrowException_DL

#define Dart_RootLibrary Dart_RootLibrary_DL

#define Dart_ScopeAllocate Dart_ScopeAllocate_DL

#define Dart_SetBooleanReturnValue Dart_SetBooleanReturnValue_DL

#define Dart_SetDartLibrarySourcesKernel Dart_SetDartLibrarySourcesKernel_DL

#define Dart_SetDoubleReturnValue Dart_SetDoubleReturnValue_DL

#define Dart_SetEnvironmentCallback Dart_SetEnvironmentCallback_DL

#define Dart_SetField Dart_SetField_DL

#define Dart_SetIntegerReturnValue Dart_SetIntegerReturnValue_DL

#define Dart_SetLibraryTagHandler Dart_SetLibraryTagHandler_DL

#define Dart_SetMessageNotifyCallback Dart_SetMessageNotifyCallback_DL

#define Dart_SetNativeInstanceField Dart_SetNativeInstanceField_DL

#define Dart_SetPausedOnExit Dart_SetPausedOnExit_DL

#define Dart_SetPausedOnStart Dart_SetPausedOnStart_DL

#define Dart_SetPeer Dart_SetPeer_DL

#define Dart_SetReturnValue Dart_SetReturnValue_DL

#define Dart_SetRootLibrary Dart_SetRootLibrary_DL

#define Dart_SetShouldPauseOnExit Dart_SetShouldPauseOnExit_DL

#define Dart_SetShouldPauseOnStart Dart_SetShouldPauseOnStart_DL

#define Dart_SetStickyError Dart_SetStickyError_DL

#define Dart_SetWeakHandleReturnValue Dart_SetWeakHandleReturnValue_DL

#define Dart_ShouldPauseOnExit Dart_ShouldPauseOnExit_DL

#define Dart_ShouldPauseOnStart Dart_ShouldPauseOnStart_DL

#define Dart_WaitForEvent Dart_WaitForEvent_DL

#define Dart_WriteProfileToTimeline Dart_WriteProfileToTimeline_DL

#define Dart_ShutdownIsolate Dart_ShutdownIsolate_DL

#define Dart_StartProfiling Dart_StartProfiling_DL

#define Dart_StopProfiling Dart_StopProfiling_DL

#define Dart_StringGetProperties Dart_StringGetProperties_DL

#define Dart_StringLength Dart_StringLength_DL

#define Dart_StringStorageSize Dart_StringStorageSize_DL

#define Dart_StringToCString Dart_StringToCString_DL

#define Dart_StringToLatin1 Dart_StringToLatin1_DL

#define Dart_StringToUTF16 Dart_StringToUTF16_DL

#define Dart_StringToUTF8 Dart_StringToUTF8_DL

#define Dart_ThreadDisableProfiling Dart_ThreadDisableProfiling_DL

#define Dart_ThreadEnableProfiling Dart_ThreadEnableProfiling_DL

#define Dart_ThrowException Dart_ThrowException_DL

#define Dart_ToString Dart_ToString_DL

#define Dart_True Dart_True_DL

#define Dart_TypedDataAcquireData Dart_TypedDataAcquireData_DL

#define Dart_TypedDataReleaseData Dart_TypedDataReleaseData_DL

#define Dart_TypeDynamic Dart_TypeDynamic_DL

#define Dart_TypeNever Dart_TypeNever_DL

#define Dart_TypeToNonNullableType Dart_TypeToNonNullableType_DL

#define Dart_TypeToNullableType Dart_TypeToNullableType_DL

#define Dart_TypeVoid Dart_TypeVoid_DL

#define Dart_VersionString Dart_VersionString_DL

#endif //ANDROID_REALM_FLUTTER_H
