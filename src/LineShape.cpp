//
//  LineShape.cpp
//  main
//
//  Created by Xiaoxi Dai on 25/10/2017.
//

#include "LineShape.h"

LineShape::LineShape(const wxPoint& start) : Shape(start)
{
    
}

void LineShape::Draw(wxDC &dc) const
{
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
    dc.DrawLine(mStartPoint + mOffset, mEndPoint + mOffset);
}
