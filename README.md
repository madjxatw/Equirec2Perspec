# Equirec2Perspec

A library that converts equirectangular panorama image into normal perspective
view, based on the code from
[Wotipati/Equirectangular2Perspective](https://github.com/Wotipati/Equirectangular2Perspective)

## Requirements

- OpenCV 3.4 or newer

## Installation

```sh
git clone https://github.com/madjxatw/equirec2perspec
cd equire2perspec
mkdir build && cd build
cmake ..
make
sudo make install
```

This installs:

- `/usr/local/include/equirec2perspec/equirec2perspec.h`
- `/usr/local/lib/libequi2pers.so`
- `/usr/local/lib/cmake/equirec2perspec/Equirec2PerspecConfig.cmake`
- `/usr/local/lib/cmake/equirec2perspec/Equirec2PerspecConfigVersion.cmake`
- `/usr/local/lib/cmake/equirec2perspec/Equirec2PerspecConfigTargets.cmake`

Once installed, you can import the library as shown below in your CMake
listfile:

```sh
find_package(Equirec2Perspec REQUIRED)
target_link_libraries(${YOUR_TARGET_NAME} Equirec2Perspec)
```

## Usage

```c++
// Inclucde header files
#include <equirec2perspec/equirec2perspec.h>

// Output image resolution
const int height = 720;
const int width = 1080;

// z-axis angle (0: forward, 180: backword)
float theta = 180.0f;

// y-axis angle (>0: upper, <0: lower)
float phi = 0.0f;

// FOV of the output perspective image
float fov = 120.0f;

// instantiate a parser
Equirec2Perspec equi_parser;
// input_image and output_image are both of cv::Mat type
equi_parser.setParams(input_image, fov, height, width);
equi_parser.convert(input_image, output_image, theta, phi);
```

