#include <gtest/gtest.h>
#include "HtmlTextConverter.h"

TEST(HtmlTextConverter, ReturnsFilenamePassedToConstructor)
{
    HtmlTextConverter converter("foo");

    EXPECT_EQ("foo", converter.getFilename());
}

TEST(HtmlTextConverter, ConvertsTextFileToHtml)
{
    std::ofstream out("test.txt");
    out << "Hello\nWorld";
    out.close();

    HtmlTextConverter converter("test.txt");

    EXPECT_EQ(
        "Hello<br />World<br />",
        converter.convertToHtml());
}