#include "SplitChain.h"

SplitChain::SplitChain(spse event)
{
    _splitEvent = event;
}

SplitChain::~SplitChain()
{
    _splitEvent = nullptr;
}

std::shared_ptr<Edge> SplitChain::OppositeEdge()
{
    if (_splitEvent->GetType() != SE_VertexSplit)
        return _splitEvent->OppositeEdge;
    return nullptr;
}

std::shared_ptr<Edge> SplitChain::PreviousEdge()
{
    return _splitEvent->Parent->PreviousEdge;
}

std::shared_ptr<Edge> SplitChain::NextEdge()
{
    return _splitEvent->Parent->NextEdge;
}

std::shared_ptr<Vertex> SplitChain::PreviousVertex()
{
    auto p = _splitEvent->Parent->Previous;
    if (p->GetType() == CN_Vertex)
        return std::static_pointer_cast<Vertex>(p);
    return nullptr;
}

std::shared_ptr<Vertex> SplitChain::NextVertex()
{
    auto p = _splitEvent->Parent->Next;
    if (p->GetType() == CN_Vertex)
        return std::static_pointer_cast<Vertex>(_splitEvent->Parent->Next);
    return nullptr;
}

std::shared_ptr<Vertex> SplitChain::CurrentVertex()
{
    return _splitEvent->Parent;
}

EChainType SplitChain::ChainType()
{
    return EChainType::SPLIT;
}
