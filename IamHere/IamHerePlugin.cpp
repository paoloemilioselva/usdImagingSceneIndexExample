#include "IamHerePlugin.h"
#include "IamHere.h"

#include <pxr/base/plug/plugin.h>
#include <pxr/base/plug/registry.h>

PXR_NAMESPACE_USING_DIRECTIVE

TF_REGISTRY_FUNCTION(UsdImagingSceneIndexPlugin)
{
    UsdImagingSceneIndexPlugin::Define<IamHerePlugin>();
}

HdSceneIndexBaseRefPtr IamHerePlugin::AppendSceneIndex(HdSceneIndexBaseRefPtr const &inputScene)
{
    return IamHere::New(inputScene);
}
