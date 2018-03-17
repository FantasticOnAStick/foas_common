#include <iostream>
#include <memory>

#include <gtest/gtest.h>

#include <foas/common/parsers/JsonParser.h>


TEST(JsonParser, ParseString) {
  std::shared_ptr<foas::common::parsers::Parser> parser = std::make_shared<foas::common::parsers::JsonParser>();
  
  std::shared_ptr<foas::common::Property> content = parser->ParseString("{\"key0\": {\"key1\": [\"value0\", 1]}}");

  ASSERT_TRUE(content != nullptr);
  ASSERT_TRUE(content->Get("key0") != nullptr);
  ASSERT_TRUE(content->Get("key0")->Get("key1") != nullptr);
  
  EXPECT_EQ(2, content->Get("key0")->Get("key1")->Size());
  EXPECT_EQ("value0", content->Get("key0")->Get("key1")->Get(0)->Get<std::string>());
  EXPECT_EQ(1, content->Get("key0")->Get("key1")->Get(1)->Get<int>());
}
