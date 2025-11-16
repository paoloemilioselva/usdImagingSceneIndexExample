#ifndef IAMHEREPLUGIN_H
#define IAMHEREPLUGIN_H

#include <pxr/usdImaging/usdImaging/sceneIndexPlugin.h>
#include <pxr/pxr.h>

class IamHerePlugin: public pxr::UsdImagingSceneIndexPlugin
{
    pxr::HdSceneIndexBaseRefPtr AppendSceneIndex(
        pxr::HdSceneIndexBaseRefPtr const &inputScene) override;
};

#endif