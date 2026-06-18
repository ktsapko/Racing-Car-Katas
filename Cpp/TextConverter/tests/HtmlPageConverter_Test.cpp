#include <gtest/gtest.h>
#include "HtmlPagesConverter.h"
#include "FileReader.h"

TEST(HtmlPagesConverter, GetHtmlPage)
{
  FileReader source("../../../TextConverter/tests/test.txt");
  HtmlPagesConverter converter(source);
  ASSERT_EQ("Hello World<br />", converter.getHtmlPage(0));
}

TEST(HtmlPagesConverter, GetHtmlPageWithPageBreak)
{
  FileReader source("../../../TextConverter/tests/test_with_page_break.txt");
  HtmlPagesConverter converter(source);
  ASSERT_EQ("Hello<br />World<br />", converter.getHtmlPage(0));
  ASSERT_EQ("This is page 2<br />", converter.getHtmlPage(1));
}
