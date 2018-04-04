//
//  SetBrushCommand.h
//  pa5
//
//  Created by Xiaoxi Dai on 26/10/2017.
//

#ifndef SetBrushCommand_h
#define SetBrushCommand_h
#include "Command.h"

class SetBrushCommand : public Command
{
public:
    SetBrushCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    //void Update(const wxPoint& newPoint) override;
    // Called when the command is completed
    void Finalize(std::shared_ptr<PaintModel> model) override;
    // Used to "undo" the command
    void Undo(std::shared_ptr<PaintModel> model) override;
    // Used to "redo" the command
    void Redo(std::shared_ptr<PaintModel> model) override;
private:
    wxBrush mOldBrush, mNewBrush;
};

#endif /* SetBrushCommand_h */
