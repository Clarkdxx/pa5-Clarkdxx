//
//  SetPenCommand.h
//  pa5
//
//  Created by Xiaoxi Dai on 26/10/2017.
//

#ifndef SetPenCommand_h
#define SetPenCommand_h
#include "Command.h"

class SetPenCommand : public Command
{
public:
    SetPenCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    //void Update(const wxPoint& newPoint) override;
    // Called when the command is completed
    void Finalize(std::shared_ptr<PaintModel> model) override;
    // Used to "undo" the command
    void Undo(std::shared_ptr<PaintModel> model) override;
    // Used to "redo" the command
    void Redo(std::shared_ptr<PaintModel> model) override;
private:
    wxPen mOldPen, mNewPen;
};

#endif /* SetPenCommand_h */
