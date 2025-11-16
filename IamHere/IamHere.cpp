#include "IamHere.h"

IamHereRefPtr IamHere::New(const pxr::HdSceneIndexBaseRefPtr& inputSceneIndex)
{
    return pxr::TfCreateRefPtr( new IamHere(inputSceneIndex) );
}

IamHere::IamHere(const pxr::HdSceneIndexBaseRefPtr& inputSceneIndex)
    : pxr::HdSingleInputFilteringSceneIndexBase(inputSceneIndex)
{
    
    std::cout << "I am here initialized" << std::endl;
}

IamHere::~IamHere()
{
}

pxr::HdSceneIndexPrim IamHere::GetPrim(const pxr::SdfPath& primPath) const
{
    pxr::HdSceneIndexPrim prim = _GetInputSceneIndex()->GetPrim(primPath);
    return prim;
}

pxr::SdfPathVector IamHere::GetChildPrimPaths(const pxr::SdfPath& primPath) const
{
    return _GetInputSceneIndex()->GetChildPrimPaths(primPath);
}

void IamHere::_PrimsAdded(
    const pxr::HdSceneIndexBase& sender,
    const pxr::HdSceneIndexObserver::AddedPrimEntries& entries)
{
    _SendPrimsAdded(entries);
}

void IamHere::_PrimsRemoved(
    const pxr::HdSceneIndexBase& sender,
    const pxr::HdSceneIndexObserver::RemovedPrimEntries& entries)
{
    if (!_IsObserved()) {
        return;
    }
    _SendPrimsRemoved(entries);
}

void IamHere::_PrimsDirtied(
    const pxr::HdSceneIndexBase& sender,
    const pxr::HdSceneIndexObserver::DirtiedPrimEntries& entries)
{
    _SendPrimsDirtied(entries);
}