//
//  LineShape.h
//  pa5
//
//  Created by Xiaoxi Dai on 25/10/2017.
//

#ifndef LineShape_h
#define LineShape_h
#include "Shape.h"

class LineShape : public Shape
{
public:
    LineShape(const wxPoint& start);
    void Draw(wxDC& dc) const override;
};


#endif /* LineShape_h */
