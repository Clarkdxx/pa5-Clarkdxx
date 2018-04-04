# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
   Command.h
   Cursors.h
   EventID.h
   PaintApp.h
   PaintDrawPanel.h
   PaintFrame.h
   PaintModel.h
   Shape.h
   DrawCommand.h
   RectShape.h
   PencilShape.h
   LineShape.h
   EllipseShape.h
   SetBrushCommand.h
   SetPenCommand.h
   DeleteCommand.h
   MoveCommand.h
)

set(SOURCE_FILES
   Command.cpp
   Cursors.cpp
   PaintApp.cpp
   PaintDrawPanel.cpp
   PaintFrame.cpp
   PaintModel.cpp
   Shape.cpp
   DrawCommand.cpp
   RectShape.cpp
   PencilShape.cpp
   LineShape.cpp
   EllipseShape.cpp
   SetBrushCommand.cpp
   SetPenCommand.cpp
   DeleteCommand.cpp
   MoveCommand.cpp
)

# Don't change this
add_library(src ${SOURCE_FILES} ${HEADER_FILES})
