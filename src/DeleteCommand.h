//
//  DeleteCommand.h
//  pa5
//
//  Created by Xiaoxi Dai on 27/10/2017.
//

#ifndef DeleteCommand_h
#define DeleteCommand_h
#include "Command.h"

class DeleteCommand : public Command
{
public:
    DeleteCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
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


#endif /* DeleteCommand_h */
