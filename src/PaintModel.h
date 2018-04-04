#pragma once
#include <memory>
#include <vector>
#include "Shape.h"
#include "Command.h"
#include <wx/bitmap.h>
#include <stack>

class PaintModel : public std::enable_shared_from_this<PaintModel>
{
public:
	// Draws any shapes in the model to the provided DC (draw context)
	void DrawShapes(wxDC& dc, bool showSelection = true);

	// Clear the current paint model and start fresh
	void New();

	// Add a shape to the paint model
	void AddShape(std::shared_ptr<Shape> shape);
	// Remove a shape from the paint model
	void RemoveShape(std::shared_ptr<Shape> shape);
    
    bool HasActiveCommand();
    
    void CreateCommand(CommandType command, const wxPoint& start);
    
    void UpdateCommand(const wxPoint& start);
    
    void FinalizeCommand();
    
    bool CanUndo();
    
    bool CanRedo();
    
    void Undo();
    
    void Redo();
    
    wxColour GetPenColor();
    
    void SetPenColor(const wxColour& color);
    
    int GetPenWidth() const;
    
    void SetPenWidth(int width);
    
    wxColour GetBrushColor() const;
    
    void SetBrushColor(const wxColour& color);
    
    wxPen GetPen();
    
    wxBrush GetBrush();
    
    void SelectShape(const wxPoint& start);
    
    std::shared_ptr<Shape> GetSelectShape();
    
    void SetSelectShape();
    
    bool MouseOnSelectShape(const wxPoint& start);
    
    void SaveBitMap(const std::string& fileName, const wxSize& bitMapSize, const wxBitmapType& bitMapType);
    
    void LoadBitMap(const std::string& fileName, const wxBitmapType& bitMapType);
    
    bool CheckNew();
    
    bool CheckAddShape();
    
    std::shared_ptr<Command> GetCommand();
    
    void SetTesting();
private:
	// Vector of all the shapes in the model
	std::vector<std::shared_ptr<Shape>> mShapes;
    std::shared_ptr<Command> mCommand;
    std::stack<std::shared_ptr<Command>> mUndoStack, mRedoStack;
    std::shared_ptr<Shape> mSelectShape;
    wxPen mPen = *wxBLACK_PEN;
    wxBrush mBrush = *wxWHITE_BRUSH;
    wxBitmap mBitMap;
    bool mIsExport = false, mTesting = false;
};
