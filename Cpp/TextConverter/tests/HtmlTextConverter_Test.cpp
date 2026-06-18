#include <gtest/gtest.h>
#include "HtmlTextConverter.h"
#include "FileReader.h"

TEST(HtmlTextConverter, ConvertsTextFileToHtml)
{
    FileReader source("../../../TextConverter/tests/test.txt");

    HtmlTextConverter converter(source);

    EXPECT_EQ(
        "Hello World<br />",
        converter.convertToHtml());
}

TEST(HtmlTextConverter, ConvertsTextFileWithMultipleLinesToHtml)
{
    FileReader source("../../../TextConverter/tests/test_multiple_lines.txt");

    HtmlTextConverter converter(source);

    EXPECT_EQ(
        "First Line<br />Second Line<br />Third Line<br />",
        converter.convertToHtml());
}

TEST(HtmlTextConverter, ConvertsTextFileWithSpecialCharactersToHtml)
{
    FileReader source("../../../TextConverter/tests/test_special_characters.txt");

    HtmlTextConverter converter(source);

    EXPECT_EQ(
        "&amp;<br />*<br />#<br />",
        converter.convertToHtml());
}

TEST(HtmlTextConverter, ThrowsExceptionWhenFileDoesNotExist)
{
    FileReader source("non_existent_file.txt");

    HtmlTextConverter converter(source);

    EXPECT_THROW(
        converter.convertToHtml(),
        std::runtime_error);
}
