#include <gmock/gmock.h>
#include "HtmlPagesConverter.h"

namespace {
  TEST(HtmlPagesConverter, Foo) {
        auto converter = new HtmlPagesConverter("foo");
        ASSERT_EQ("foo", converter->getFilename());
  }
}


