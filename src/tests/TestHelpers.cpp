#include "catch.hpp"
#include "../Config.h"
#include "../ProgramOptions.h"

TEST_CASE( "parseColor")
{
    REQUIRE((helpers::parseColor("0,0,0") == Config::Color{0, 0, 0}));
    REQUIRE((helpers::parseColor("255,255,255") == Config::Color{255, 255, 255}));
    REQUIRE((helpers::parseColor(" 255 , 255    ,  255  ") == Config::Color{255, 255, 255}));

    REQUIRE_THROWS_AS(helpers::parseColor(""), std::logic_error);
    REQUIRE_THROWS_AS(helpers::parseColor("foo"), std::logic_error);
    REQUIRE_THROWS_AS(helpers::parseColor("0,1"), std::logic_error);
    REQUIRE_THROWS_AS(helpers::parseColor("0,1,2,3"), std::logic_error);
    REQUIRE_THROWS_AS(helpers::parseColor("0,a,1"), std::logic_error);

    REQUIRE_THROWS_AS(helpers::parseColor("0,1,256"), std::logic_error);
    REQUIRE_THROWS_AS(helpers::parseColor("0,1,-1"), std::logic_error);
}

TEST_CASE("parseCharsString")
{
    REQUIRE((helpers::parseCharsString("") == std::set<uint32_t>{}));
    REQUIRE((helpers::parseCharsString("0") == std::set<uint32_t>{0}));
    REQUIRE((helpers::parseCharsString("42") == std::set<uint32_t>{42}));
    REQUIRE((helpers::parseCharsString("0-1") == std::set<uint32_t>{0,1}));
    REQUIRE((helpers::parseCharsString("1-3") == std::set<uint32_t>{1,2,3}));
    REQUIRE((helpers::parseCharsString(" 1 - 3 ") == std::set<uint32_t>{1,2,3}));

    REQUIRE_THROWS_AS(helpers::parseCharsString("foo"), std::logic_error);
    REQUIRE_THROWS_AS(helpers::parseCharsString("-1"), std::logic_error);
    REQUIRE_THROWS_AS(helpers::parseCharsString("-1-2"), std::logic_error);
    //REQUIRE_THROWS_AS(helpers::parseCharsString("1-2 3"), std::logic_error);
}
