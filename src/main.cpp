#include <memory>
#include "Core/Initialize.h"

int main(int argc, char** argv)
{
    std::unique_ptr<ShatteredEngine_Core::Initialize> _initialize = std::make_unique<ShatteredEngine_Core::Initialize>();

    return 0;
}