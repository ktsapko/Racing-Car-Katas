#include <gtest/gtest.h>
#include "HtmlPagesConverter.h"


TEST (HtmlPagesConverter, GetFilename) {
    auto converter = new HtmlPagesConverter("test.txt");
    ASSERT_EQ("test.txt", converter->getFilename());
}

TEST(HtmlPagesConverter, GetHtmlPage) {
    auto converter = new HtmlPagesConverter("../../../TextConverter/tests/test.txt");
    ASSERT_EQ("Hello World<br />", converter->getHtmlPage(0));
}

TEST(HtmlPagesConverter, GetHtmlPageWithPageBreak) {
    auto converter = new HtmlPagesConverter("../../../TextConverter/tests/test_with_page_break.txt");    
    ASSERT_EQ("Hello<br />World<br />", converter->getHtmlPage(0));
    ASSERT_EQ("This is page 2<br />", converter->getHtmlPage(1));
}
