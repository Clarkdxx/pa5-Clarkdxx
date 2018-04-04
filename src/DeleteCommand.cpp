//
//  DeleteCommand.cpp
//  main
//
//  Created by Xiaoxi Dai on 27/10/2017.
//

#include "DeleteCommand.h"
#include "Shape.h"
#include "PaintModel.h"

DeleteCommand::DeleteCommand(const wxPoint& start, std::shared_ptr<Shape> shape) : Command(start, shape)
{
    
}

void DeleteCommand::Finalize(std::shared_ptr<PaintModel> model)
{
    model->RemoveShape(mShape);
    model->SetSelectShape();
}

void DeleteCommand::Undo(std::shared_ptr<PaintModel> model)
{
    
}

void DeleteCommand::Redo(std::shared_ptr<PaintModel> model)
{
    
}
