//
//  SetBrushCommand.cpp
//  main
//
//  Created by Xiaoxi Dai on 26/10/2017.
//

#include "SetBrushCommand.h"
#include "Shape.h"
#include "PaintModel.h"

SetBrushCommand::SetBrushCommand(const wxPoint& start, std::shared_ptr<Shape> shape) : Command(start, shape)
{
    mOldBrush = mShape->GetBrush();
}

void SetBrushCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    mNewBrush = model->GetBrush();
    mShape->SetBrush(mNewBrush);
}

void SetBrushCommand::Undo(std::shared_ptr<PaintModel> model)
{
    mShape->SetBrush(mOldBrush);
    model->SetBrushColor(mOldBrush.GetColour());
}

void SetBrushCommand::Redo(std::shared_ptr<PaintModel> model)
{
    mShape->SetBrush(mNewBrush);
    model->SetBrushColor(mNewBrush.GetColour());
}
