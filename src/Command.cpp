#include "Command.h"
#include "Shape.h"
#include "PaintModel.h"
#include "DrawCommand.h"
#include "RectShape.h"
#include "EllipseShape.h"
#include "LineShape.h"
#include "PencilShape.h"
#include "SetPenCommand.h"
#include "SetBrushCommand.h"
#include "DeleteCommand.h"
#include "MoveCommand.h"

Command::Command(const wxPoint& start, std::shared_ptr<Shape> shape)
	:mStartPoint(start)
	,mEndPoint(start)
	,mShape(shape)
{

}

// Called when the command is still updating (such as in the process of drawing)
void Command::Update(const wxPoint& newPoint)
{
	mEndPoint = newPoint;
}

std::shared_ptr<Command> CommandFactory::Create(std::shared_ptr<PaintModel> model,
	CommandType type, const wxPoint& start)
{
	std::shared_ptr<Command> retVal;
	
	// TODO: Actually create a command based on the type passed in
    std::shared_ptr<Shape> newShape;
    if(type == CM_DrawRect)
    {
        newShape = std::make_shared<RectShape>(start);
    }
    else if(type == CM_DrawEllipse)
    {
        newShape = std::make_shared<EllipseShape>(start);
    }
    else if(type == CM_DrawLine)
    {
        newShape = std::make_shared<LineShape>(start);
    }
    else if(type == CM_DrawPencil)
    {
        newShape = std::make_shared<PencilShape>(start);
    }
    else if(type == CM_SetPen)
    {
        retVal = std::make_shared<SetPenCommand>(start, model->GetSelectShape());
        return retVal;
    }
    else if(type == CM_SetBrush)
    {
        retVal = std::make_shared<SetBrushCommand>(start, model->GetSelectShape());
        return retVal;
    }
    else if(type == CM_Delete)
    {
        retVal = std::make_shared<DeleteCommand>(start, model->GetSelectShape());
        return retVal;
    }
    else if(type == CM_Move)
    {
        retVal = std::make_shared<MoveCommand>(start, model->GetSelectShape());
        return retVal;
    }
    newShape->SetPen(model->GetPen());
    newShape->SetBrush(model->GetBrush());
    retVal = std::make_shared<DrawCommand>(start, newShape);
    model->AddShape(newShape);
	return retVal;
}
