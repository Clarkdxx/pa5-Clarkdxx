#include "catch.hpp"
#include <string>
#include <chrono>
#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif
#include "PaintModel.h"
#include "RectShape.h"

// Helper function declarations (don't change these)
extern bool CheckFileMD5(const std::string& fileName, const std::string& expected);
extern bool CheckTextFilesSame(const std::string& fileNameA, 
	const std::string& fileNameB);

// TODO:
// Add test cases for your functions here!!
// (You will want to make multiple test cases with different sections)
TEST_CASE("Function test cases", "[student]")
{
    PaintModel paintModel;
    paintModel.SetTesting();
    
    SECTION("New()")
    {
        paintModel.New();
        REQUIRE(paintModel.CheckNew());
    }
    
    SECTION("AddShape")
    {
        std::shared_ptr<RectShape> newShape = std::make_shared<RectShape>(wxPoint());
        paintModel.AddShape(newShape);
        REQUIRE(paintModel.CheckAddShape());
    }
    
    SECTION("CreateCommand")
    {
        paintModel.CreateCommand(CM_Move, wxPoint());
        REQUIRE(!paintModel.CanRedo());
    }
    
    SECTION("FinalizeCommand")
    {
        paintModel.FinalizeCommand();
        REQUIRE(paintModel.GetCommand() == nullptr);
    }
    
    SECTION("Undo, Redo")
    {
        paintModel.Undo();
        REQUIRE(paintModel.GetCommand() == nullptr);
        REQUIRE(paintModel.GetSelectShape() == nullptr);
        paintModel.Redo();
        REQUIRE(paintModel.GetCommand() == nullptr);
        REQUIRE(paintModel.GetSelectShape() == nullptr);
    }
}
