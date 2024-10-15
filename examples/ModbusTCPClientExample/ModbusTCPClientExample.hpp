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

#ifndef MODBUS_TCP_CLIENT_EXAMPLE_HPP
#define MODBUS_TCP_CLIENT_EXAMPLE_HPP

#include "W5500.hpp"
#include "W5500_TCPServer.h"
#include "W5500_TCPClient.h"
#include "W5500_EMAC.hpp"

namespace mbed
{

class Modbus_TCPClientExample
{
public:
    int run();
};

} // namespace mbed

#endif // Modbus_TCP_CLIENT_EXAMPLE_HPP