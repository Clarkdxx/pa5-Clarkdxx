//
//  DrawCommand.h
//  pa5
//
//  Created by Xiaoxi Dai on 24/10/2017.
//

#ifndef DrawCommand_h
#define DrawCommand_h
#include "Command.h"

class DrawCommand : public Command
{
public:
    DrawCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    void Update(const wxPoint& newPoint) override;
    // Called when the command is completed
    void Finalize(std::shared_ptr<PaintModel> model) override;
    // Used to "undo" the command
    void Undo(std::shared_ptr<PaintModel> model) override;
    // Used to "redo" the command
    void Redo(std::shared_ptr<PaintModel> model) override;
};

#endif /* DrawCommand_h */
