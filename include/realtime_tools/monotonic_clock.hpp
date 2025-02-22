// Copyright 2025 PAL Robotics S.L.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/// \author Sai Kishor Kothakota

#ifndef REALTIME_TOOLS__MONOTONIC_CLOCK_HPP_
#define REALTIME_TOOLS__MONOTONIC_CLOCK_HPP_

#ifdef _WIN32
#error "The monotonic_clock.hpp header is not supported on Windows platforms"
#endif

#include <chrono>
#include <ctime>
#include <ratio>

namespace realtime_tools
{
class MonotonicClock
{
public:
  using rep = std::chrono::nanoseconds::rep;
  using period = std::chrono::nanoseconds::period;
  using duration = std::chrono::nanoseconds;
  using time_point = std::chrono::time_point<MonotonicClock>;

  static constexpr bool is_steady = true;

  static time_point now() noexcept
  {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
    return time_point(std::chrono::seconds(ts.tv_sec) + std::chrono::nanoseconds(ts.tv_nsec));
  }
};
}  // namespace realtime_tools

#endif  // REALTIME_TOOLS__MONOTONIC_CLOCK_HPP_
