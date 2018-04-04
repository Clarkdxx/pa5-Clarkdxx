//
//  RectShape.cpp
//  main
//
//  Created by Xiaoxi Dai on 24/10/2017.
//

#include "RectShape.h"

RectShape::RectShape(const wxPoint& start) : Shape(start)
{
    
}

void RectShape::Draw(wxDC &dc) const
{
    wxRect rect(mTopLeft + mOffset, mBotRight + mOffset);
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    dc.DrawRectangle(rect);
}
