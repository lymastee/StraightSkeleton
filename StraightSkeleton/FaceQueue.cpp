#include "FaceQueue.h"

std::shared_ptr<Edge> FaceQueue::GetEdge()
{
    return edge;
}

bool FaceQueue::Closed()
{
    return closed;
}

bool FaceQueue::IsUnconnected()
{
    return edge == nullptr;
}

void FaceQueue::AddPush(std::shared_ptr<FaceNode> node, std::shared_ptr<FaceNode> newNode)
{
    if (!Closed())
    {
        if (newNode->List == nullptr && newNode->Previous == nullptr)
        {
            newNode->List = this;
            size++;

            if (node->Next == nullptr)
            {
                newNode->Previous = node;
                newNode->Next = nullptr;

                node->Next = newNode;
            }
            else
            {
                newNode->Previous = nullptr;
                newNode->Next = node;

                node->Previous = newNode;
            }
        }
    }
}

void FaceQueue::AddFirst(std::shared_ptr<FaceNode> node)
{
    if (node->List == nullptr)
    {
        if (first == nullptr)
        {
            first = node;

            node->List = this;
            node->Next = nullptr;
            node->Previous = nullptr;

            size++;
        }
    }
}

std::shared_ptr<FaceNode> FaceQueue::Pop(std::shared_ptr<FaceNode> node)
{
    if (node->List == this && size > 0 && node->IsEnd())
    {
        node->List = nullptr;

        spfn previous = nullptr;

        if (size == 1)
            first = nullptr;
        else
        {
            if (first == node)
            {
                if (node->Next != nullptr)
                    first = node->Next;
                else if (node->Previous != nullptr)
                    first = node->Previous;
            }
            if (node->Next != nullptr)
            {
                node->Next->Previous = nullptr;
                previous = node->Next;
            }
            else if (node->Previous != nullptr)
            {
                node->Previous->Next = nullptr;
                previous = node->Previous;
            }
        }

        node->Previous = nullptr;
        node->Next = nullptr;

        size--;
        return previous;
    }
    return nullptr;
}

void FaceQueue::SetEdge(std::shared_ptr<Edge> val)
{
    edge = val;
}

FaceQueue::~FaceQueue()
{
    //delete edge;
}

void FaceQueue::Close()
{
    closed = true;
}

size_t FaceQueue::Size()
{
    return size;
}

std::shared_ptr<FaceNode> FaceQueue::First()
{
    return first;
}
