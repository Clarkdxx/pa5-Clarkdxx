//
//  MoveCommand.cpp
//  main
//
//  Created by Xiaoxi Dai on 27/10/2017.
//

#include "MoveCommand.h"
#include "Shape.h"
#include "PaintModel.h"

MoveCommand::MoveCommand(const wxPoint& start, std::shared_ptr<Shape> shape) : Command(start, shape)
{
    mOldOffest = mShape->GetOffset();
}

void MoveCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    mShape->Finalize();
}

void MoveCommand::Undo(std::shared_ptr<PaintModel> model)
{
    mShape->SetOffset(mOldOffest);
}

void MoveCommand::Redo(std::shared_ptr<PaintModel> model)
{
    mShape->SetOffset(mOldOffest + mNewPoint - mStartPoint);
}

void MoveCommand::Update(const wxPoint &newPoint)
{
    mNewPoint = newPoint;
    mShape->SetOffset(newPoint - mStartPoint + mOldOffest);
}
