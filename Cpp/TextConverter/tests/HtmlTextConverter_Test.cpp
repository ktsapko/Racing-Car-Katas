#include <gtest/gtest.h>
#include "HtmlTextConverter.h"

TEST(HtmlTextConverter, ReturnsFilenamePassedToConstructor)
{
    HtmlTextConverter converter("foo");

    EXPECT_EQ("foo", converter.getFilename());
}

TEST(HtmlTextConverter, ConvertsTextFileToHtml)
{
    HtmlTextConverter converter("../../../TextConverter/tests/test.txt");

    EXPECT_EQ(
        "Hello World<br />",
        converter.convertToHtml());
}

TEST(HtmlTextConverter, ConvertsTextFileWithMultipleLinesToHtml)
{
    HtmlTextConverter converter(
    "../../../TextConverter/tests/test_multiple_lines.txt");

    EXPECT_EQ(
        "First Line<br />Second Line<br />Third Line<br />",
        converter.convertToHtml());
}

TEST(HtmlTextConverter, ConvertsTextFileWithSpecialCharactersToHtml)
{
    HtmlTextConverter converter(
    "../../../TextConverter/tests/test_special_characters.txt");

    EXPECT_EQ(
        "&amp;<br />*<br />#<br />",
        converter.convertToHtml());
}

TEST(HtmlTextConverter, ThrowsExceptionWhenFileDoesNotExist)
{
    HtmlTextConverter converter("non_existent_file.txt");

    EXPECT_THROW(
        converter.convertToHtml(),
        std::runtime_error);
}
