/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#include "modules/planning/scenarios/side_pass/side_pass_scenario.h"

#include <memory>

#include "gtest/gtest.h"

#include "cybertron/common/log.h"
#include "modules/common/util/file.h"
#include "modules/planning/common/planning_gflags.h"

namespace apollo {
namespace planning {

class SidePassScenarioTest : public ::testing::Test {
 public:
  virtual void SetUp() {}

 protected:
  std::unique_ptr<SidePassScenario> scenario_;
};
TEST_F(SidePassScenarioTest, Simple) {
  FLAGS_scenario_side_pass_config_file =
      "modules/planning/conf/scenario_side_pass_config.pb.txt";

  scenario_.reset(new SidePassScenario());
  EXPECT_EQ(scenario_->scenario_type(), ScenarioConfig::SIDE_PASS);

  ScenarioConfig config;
  EXPECT_TRUE(apollo::common::util::GetProtoFromFile(
      FLAGS_scenario_side_pass_config_file, &config));
  EXPECT_TRUE(scenario_->Init());
}

}  // namespace planning
}  // namespace apollo
