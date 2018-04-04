//
//  EllipseShape.h
//  pa5
//
//  Created by Xiaoxi Dai on 25/10/2017.
//

#ifndef EllipseShape_h
#define EllipseShape_h

#include "Shape.h"

class EllipseShape : public Shape
{
public:
    EllipseShape(const wxPoint& start);
    void Draw(wxDC& dc) const override;
};

#endif /* EllipseShape_h */
