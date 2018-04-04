//
//  RectShape.h
//  pa5
//
//  Created by Xiaoxi Dai on 24/10/2017.
//

#ifndef RectShape_h
#define RectShape_h
#include "Shape.h"

class RectShape : public Shape
{
public:
    RectShape(const wxPoint& start);
    void Draw(wxDC& dc) const override;
};

#endif /* RectShape_h */
