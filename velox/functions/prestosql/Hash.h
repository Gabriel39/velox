/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <functional>
#include <string>
#include "HashImpl.h"
#include "folly/CPortability.h"
#include "folly/String.h"
#include "folly/hash/Hash.h"
#include "velox/functions/Macros.h"

namespace facebook::velox::functions {

template <typename T>
struct HashFunction {
  VELOX_DEFINE_FUNCTION_TYPES(T);

  template <typename TFrom>
  FOLLY_ALWAYS_INLINE bool call(int64_t& result, const TFrom& a) {
    result = computeHash(a);
    return true;
  }
};

} // namespace facebook::velox::functions
