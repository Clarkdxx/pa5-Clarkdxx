#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif
#include "PaintModel.h"
#include <algorithm>
#include <iostream>
#include <wx/dcmemory.h>

// Draws any shapes in the model to the provided DC (draw context)
void PaintModel::DrawShapes(wxDC& dc, bool showSelection)
{
	// TODO
    if(mBitMap.IsOk())
    {
        dc.DrawBitmap(mBitMap, 0, 0);
    }
    for(auto shape : mShapes)
    {
        dc.SetPen(mPen);
        dc.SetBrush(mBrush);
        shape->Draw(dc);
    }
    if(mSelectShape != nullptr && !mIsExport)
    {
        mSelectShape->DrawSelection(dc);
    }
}

// Clear the current paint model and start fresh
void PaintModel::New()
{
	// TODO
    wxBitmap newBitMap;
    mBitMap = newBitMap;
    mCommand = nullptr;
    mSelectShape = nullptr;
    mShapes.clear();
    mRedoStack = std::stack<std::shared_ptr<Command>>();
    mUndoStack = std::stack<std::shared_ptr<Command>>();
    mPen = *wxBLACK_PEN;
    mBrush = *wxWHITE_BRUSH;
}

bool PaintModel::CheckNew()
{
    if(mCommand != nullptr || mSelectShape != nullptr)
    {
        return false;
    }
    if(!mRedoStack.empty() && !mUndoStack.empty())
    {
        return false;
    }
    return mPen == *wxBLACK_PEN && mBrush == *wxWHITE_BRUSH;
}

// Add a shape to the paint model
void PaintModel::AddShape(std::shared_ptr<Shape> shape)
{
    mSelectShape = nullptr;
	mShapes.emplace_back(shape);
}

bool PaintModel::CheckAddShape()
{
    return (mSelectShape == nullptr && !mShapes.empty());
}

// Remove a shape from the paint model
void PaintModel::RemoveShape(std::shared_ptr<Shape> shape)
{
	auto iter = std::find(mShapes.begin(), mShapes.end(), shape);
	if (iter != mShapes.end())
	{
		mShapes.erase(iter);
	}
}

bool PaintModel::HasActiveCommand()
{
    return (mCommand != nullptr);
}

void PaintModel::CreateCommand(CommandType command, const wxPoint& start)
{
    if(!mTesting)
    {
        mCommand = CommandFactory::Create(shared_from_this(), command, start);
    }
    mRedoStack = std::stack<std::shared_ptr<Command>>();
}

void PaintModel::UpdateCommand(const wxPoint& start)
{
    mCommand->Update(start);
}

void PaintModel::FinalizeCommand()
{
    if(!mTesting)
    {
        mCommand->Finalize(shared_from_this());
    }
    mUndoStack.push(mCommand);
    mCommand = nullptr;
}

bool PaintModel::CanUndo()
{
    return !mUndoStack.empty();
}

bool PaintModel::CanRedo()
{
    return !mRedoStack.empty();
}

void PaintModel::Undo()
{
    if(!mTesting)
    {
        mCommand = mUndoStack.top();
        mCommand->Undo(shared_from_this());
        mUndoStack.pop();
        mRedoStack.push(mCommand);
    }
    mSelectShape = nullptr;
    mCommand = nullptr;
}

void PaintModel::Redo()
{
    if(!mTesting)
    {
        mCommand = mRedoStack.top();
        mCommand->Redo(shared_from_this());
        mRedoStack.pop();
        mUndoStack.push(mCommand);
    }
    mSelectShape = nullptr;
    mCommand = nullptr;
}

wxColour PaintModel::GetPenColor()
{
    return mPen.GetColour();
}

void PaintModel::SetPenColor(const wxColour& color)
{
    mPen.SetColour(color);
}

int PaintModel::GetPenWidth() const
{
    return mPen.GetWidth();
}

void PaintModel::SetPenWidth(int width)
{
    mPen.SetWidth(width);
}

wxColour PaintModel::GetBrushColor() const
{
    return mBrush.GetColour();
}

void PaintModel::SetBrushColor(const wxColour& color)
{
    mBrush.SetColour(color);
}

wxPen PaintModel::GetPen()
{
    return mPen;
}

wxBrush PaintModel::GetBrush()
{
    return mBrush;
}

void PaintModel::SelectShape(const wxPoint& start)
{
    mSelectShape = nullptr;
    for(int i = mShapes.size() - 1; i >=0; i--)
    {
        if(mShapes[i]->Intersects(start))
        {
            mSelectShape = mShapes[i];
            break;
        }
    }
}

std::shared_ptr<Shape> PaintModel::GetSelectShape()
{
    return mSelectShape;
}

void PaintModel::SetSelectShape()
{
    mSelectShape = nullptr;
}

bool PaintModel::MouseOnSelectShape(const wxPoint& start)
{
    if(mSelectShape == nullptr)
    {
        return false;
    }
    return mSelectShape->Intersects(start);
}

void PaintModel::SaveBitMap(const std::string& fileName, const wxSize& bitMapSize, const wxBitmapType& bitMapType)
{
    wxBitmap bitmap;
    // Create the bitmap of the specified wxSize
    bitmap.Create(bitMapSize);
    // Create a memory DC to draw to the bitmap
    wxMemoryDC dc(bitmap);
    // Clear the background color
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    // Draw all the shapes (make sure not the selection!)
    mIsExport = true;
    DrawShapes(dc);
    mIsExport = false;
    // Write the bitmap with the specified file name and wxBitmapType
    bitmap.SaveFile(fileName, bitMapType);
}

void PaintModel::LoadBitMap(const std::string& fileName, const wxBitmapType& bitMapType)
{
    New();
    mBitMap.LoadFile(fileName, bitMapType);
}

std::shared_ptr<Command> PaintModel::GetCommand()
{
    return mCommand;
}

void PaintModel::SetTesting()
{
    mTesting = true;
}
