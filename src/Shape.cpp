#include "Shape.h"
#include <algorithm>

Shape::Shape(const wxPoint& start)
	:mStartPoint(start)
	,mEndPoint(start)
	,mTopLeft(start)
	,mBotRight(start)
{
    mPen = *wxBLACK_PEN;
    mBrush = *wxWHITE_BRUSH;
    mOffset.x = 0;
    mOffset.y = 0;
}

// Tests whether the provided point intersects
// with this shape
bool Shape::Intersects(const wxPoint& point) const
{
	bool retVal = false;
	wxPoint topleft;
	wxPoint botright;
	GetBounds(topleft, botright);
	if (point.x >= topleft.x && point.x <= botright.x &&
		point.y >= topleft.y && point.y <= botright.y)
	{
		retVal = true;
	}
	return retVal;
}

// Update shape with new provided point
void Shape::Update(const wxPoint& newPoint)
{
	mEndPoint = newPoint;

	// For most shapes, we only have two points - start and end
	// So we can figure out the top left/bottom right bounds
	// based on this.
	mTopLeft.x = std::min(mStartPoint.x, mEndPoint.x);
	mTopLeft.y = std::min(mStartPoint.y, mEndPoint.y);
	mBotRight.x = std::max(mStartPoint.x, mEndPoint.x);
	mBotRight.y = std::max(mStartPoint.y, mEndPoint.y);
}

void Shape::Finalize()
{
	// Default finalize doesn't do anything
}

void Shape::GetBounds(wxPoint& topLeft, wxPoint& botRight) const
{
	topLeft = mTopLeft + mOffset;
	botRight = mBotRight + mOffset;
}

wxPen Shape::GetPen()
{
    return mPen;
}

wxBrush Shape::GetBrush()
{
    return mBrush;
}

void Shape::SetPen(const wxPen& pen)
{
    mPen = pen;
}

void Shape::SetBrush(const wxBrush& brush)
{
    mBrush = brush;
}

void Shape::DrawSelection(wxDC& dc)
{
    wxPoint topLeft, botRight;
    topLeft.x = mTopLeft.x - 3;
    topLeft.y = mTopLeft.y - 3;
    botRight.x = mBotRight.x + 3;
    botRight.y = mBotRight.y + 3;
    wxRect rect(topLeft + mOffset, botRight + mOffset);
    wxPen pen = *wxBLACK_DASHED_PEN;
    wxBrush brush = *wxTRANSPARENT_BRUSH;
    dc.SetPen(pen);
    dc.SetBrush(brush);
    dc.DrawRectangle(rect);
    dc.SetPen(mPen);
    dc.SetBrush(mBrush);
}

void Shape::SetOffset(wxPoint offset)
{
    mOffset = offset;
}

wxPoint Shape::GetOffset()
{
    return mOffset;
}
