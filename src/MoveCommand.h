//
//  MoveCommand.h
//  pa5
//
//  Created by Xiaoxi Dai on 27/10/2017.
//

#ifndef MoveCommand_h
#define MoveCommand_h
#include "Command.h"

class MoveCommand : public Command
{
public:
    MoveCommand(const wxPoint& start, std::shared_ptr<Shape> shape);
    //void Update(const wxPoint& newPoint) override;
    // Called when the command is completed
    void Finalize(std::shared_ptr<PaintModel> model) override;
    // Used to "undo" the command
    void Undo(std::shared_ptr<PaintModel> model) override;
    // Used to "redo" the command
    void Redo(std::shared_ptr<PaintModel> model) override;
    
    void Update(const wxPoint& newPoint) override;
    
private:
    wxPoint mNewPoint;
    wxPoint mOldOffest;
};


#endif /* MoveCommand_h */
