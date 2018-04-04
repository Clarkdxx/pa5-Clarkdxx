//
//  SetPenCommand.cpp
//  main
//
//  Created by Xiaoxi Dai on 26/10/2017.
//

#include "SetPenCommand.h"
#include "Shape.h"
#include "PaintModel.h"

SetPenCommand::SetPenCommand(const wxPoint& start, std::shared_ptr<Shape> shape) : Command(start, shape)
{
    mOldPen = mShape->GetPen();
}

void SetPenCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    mNewPen.SetWidth(model->GetPenWidth());
    mNewPen.SetColour(model->GetPenColor());
    mShape->SetPen(mNewPen);
}

void SetPenCommand::Undo(std::shared_ptr<PaintModel> model)
{
    mShape->SetPen(mOldPen);
    model->SetPenWidth(mOldPen.GetWidth());
    model->SetPenColor(mOldPen.GetColour());
}

void SetPenCommand::Redo(std::shared_ptr<PaintModel> model)
{
    mShape->SetPen(mNewPen);
    model->SetPenWidth(mNewPen.GetWidth());
    model->SetPenColor(mNewPen.GetColour());
}
