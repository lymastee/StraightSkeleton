#pragma once
#include <string>
//#include <format>
#include <memory>
#include "Vector2d.h"

enum SkeletonEventType
{
    SE_Edge,
    SE_Split,
    SE_MultiSplit,
    SE_Pick,
    SE_MultiEdge,
    SE_VertexSplit,
};

class SkeletonEvent
{
private:
    using spv2d = std::shared_ptr<Vector2d>;
public:
    struct SkeletonEventComparer
    {
        bool operator()(SkeletonEvent& left, SkeletonEvent& right)
        {
            return left.Distance < right.Distance;
        }
    };
    spv2d V = nullptr;
    double Distance;    
    SkeletonEvent(spv2d point, double distance);
    virtual ~SkeletonEvent();
    std::string ToString();
    virtual SkeletonEventType GetType() const = 0;
    virtual bool IsObsolete() { return false; };
};

