//
//  Created by Bradley Austin Davis on 2016/03/19
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#pragma once

#include "common.hpp"

namespace vkx {

    // Version information for Vulkan is stored in a single 32 bit integer
    // with individual bits representing the major, minor and patch versions.
    // The maximum possible major and minor version is 512 (look out nVidia)
    // while the maximum possible patch version is 2048
    struct Version {
        Version() : major(0), minor(0), patch(0) {
        }
        Version(uint32_t version) : Version() {
            *this = version;
        }

        Version& operator =(uint32_t version) {
            memcpy(this, &version, sizeof(uint32_t));
            return *this;
        }

        operator uint32_t() const {
            uint32_t result;
            memcpy(&result, this, sizeof(uint32_t));
        }

        std::string toString() const {
            std::stringstream buffer;
            buffer << major << "." << minor << "." << patch;
            return buffer.str();
        }

        const uint32_t patch : 12;
        const uint32_t minor : 10;
        const uint32_t major : 10;

    };
}