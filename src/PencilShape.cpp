//
//  PencilShape.cpp
//  main
//
//  Created by Xiaoxi Dai on 25/10/2017.
//

#include "PencilShape.h"

PencilShape::PencilShape(const wxPoint& start) : Shape(start)
{
    mPoints.push_back(start);
}

void PencilShape::Draw(wxDC &dc) const
{
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    if(mPoints.size() == 1)
    {
        dc.DrawPoint(mPoints[0] + mOffset);
    }
    else
    {
        dc.DrawLines(mPoints.size(), mPoints.data(), mOffset.x, mOffset.y);
    }
}

void PencilShape::Update(const wxPoint &newPoint)
{
    Shape::Update(newPoint);
    mPoints.push_back(newPoint);
}

void PencilShape::Finalize()
{
    int xMin = 0, yMin = 0, xMax = 0, yMax = 0;
    int i = 0;
    for(auto point : mPoints)
    {
        if(i == 0)
        {
            xMin = point.x;
            xMax = point.x;
            yMin = point.y;
            yMax = point.y;
            i = 1;
        }
        if(point.x < xMin)
        {
            xMin = point.x;
        }
        if(point.x > xMax)
        {
            xMax = point.x;
        }
        if(point.y < yMin)
        {
            yMin = point.y;
        }
        if(point.y > yMax)
        {
            yMax = point.y;
        }
    }
    mTopLeft.x = xMin;
    mTopLeft.y = yMin;
    mBotRight.x = xMax;
    mBotRight.y = yMax;
}
