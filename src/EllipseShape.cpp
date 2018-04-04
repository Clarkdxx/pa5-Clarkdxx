//
//  EllipseShape.cpp
//  main
//
//  Created by Xiaoxi Dai on 25/10/2017.
//

#include "EllipseShape.h"

EllipseShape::EllipseShape(const wxPoint& start) : Shape(start)
{
    
}

void EllipseShape::Draw(wxDC &dc) const
{
    wxRect rect(mTopLeft + mOffset, mBotRight + mOffset);
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    dc.DrawEllipse(rect);
}
