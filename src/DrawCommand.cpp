//
//  DrawCommand.cpp
//  main
//
//  Created by Xiaoxi Dai on 24/10/2017.
//

#include "DrawCommand.h"
#include "Shape.h"
#include "PaintModel.h"

DrawCommand::DrawCommand(const wxPoint& start, std::shared_ptr<Shape> shape) : Command(start, shape)
{
    
}

void DrawCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    mShape->Finalize();
}

void DrawCommand::Undo(std::shared_ptr<PaintModel> model)
{
    model->RemoveShape(mShape);
}

void DrawCommand::Redo(std::shared_ptr<PaintModel> model)
{
    model->AddShape(mShape);
}

void DrawCommand::Update(const wxPoint &newPoint)
{
    Command::Update(newPoint);
    mShape->Update(newPoint);
}
