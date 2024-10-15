// Copyright 2024, Fawad Siddiqui, Andreas Reichle (HOREICH GmbH)

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MODBUS_RTU_SLAVE_EXAMPLE_HPP
#define MODBUS_RTU_SLAVE_EXAMPLE_HPP

#include "rs485.hpp"
#include "modbusRTUSlave.hpp"
namespace mbed
{

class Modbus_RTUSlaveExample
{
public:
    int run();
};

} // namespace mbed

#endif // Modbus_RTU_SLAVE_EXAMPLE_HPP