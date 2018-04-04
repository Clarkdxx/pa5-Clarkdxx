//
//  PencilShape.h
//  pa5
//
//  Created by Xiaoxi Dai on 25/10/2017.
//

#ifndef PencilShape_h
#define PencilShape_h
#include <vector>
#include "Shape.h"

class PencilShape : public Shape
{
public:
    PencilShape(const wxPoint& start);
    void Draw(wxDC& dc) const override;
    void Update(const wxPoint& newPoint) override;
    void Finalize() override;
private:
    std::vector<wxPoint> mPoints;
};

#endif /* PencilShape_h */
