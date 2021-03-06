// Copyright Robert Dickerson 2014

#ifndef INCLUDE_COMMON_H_
#define INCLUDE_COMMON_H_

#include <string>
#include <memory>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

namespace Hodhr {

  struct HodhrVertex {
    float x, y, z;          // position
    float nx, ny, nz;       // normal direction
    unsigned short s, t;    // texture coordinates
  };
  
  int printOglError(std::string instruction);
  
}  // namespace Hodhr



#endif  // INCLUDE_COMMON_H_
